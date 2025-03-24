#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <libgen.h>

// Função para substituir uma substring em uma string
void replace(char *src, char *dest, const char *old, const char *new) {
    char *pos = strstr(src, old);
    if (pos == NULL) {
        strcpy(dest, src);
        return;
    }

    strncpy(dest, src, pos - src);
    dest[pos - src] = '\0';
    strcat(dest, new);
    strcat(dest, pos + strlen(old));
}

// Função para processar uma linha do Cangaceiro++ e convertê-la para C
void process_line(char *line, FILE *output) {
    char temp[1024];

    // Substituições básicas
    replace(line, temp, "oxente mainha()", "int main()");
    strcpy(line, temp);

    replace(line, temp, "inteiroxi", "int");
    strcpy(line, temp);

    replace(line, temp, "quaseinteiro", "float");
    strcpy(line, temp);

    replace(line, temp, "letrinha", "char");
    strcpy(line, temp);

    replace(line, temp, "visse(", "printf(");
    strcpy(line, temp);

    replace(line, temp, "ifoxente", "if");
    strcpy(line, temp);

    replace(line, temp, "senãohomi", "else");
    strcpy(line, temp);

    replace(line, temp, "arretado", "for");
    strcpy(line, temp);

    replace(line, temp, "mire", "*");
    strcpy(line, temp);

    replace(line, temp, "aperte", "&");
    strcpy(line, temp);

    replace(line, temp, "volte", "return");
    strcpy(line, temp);

    // Adicionar substituição para vish (while)
    replace(line, temp, "vish", "while");
    strcpy(line, temp);

    // Correção específica para ponteiros: "int ponteiro = &x" vira "int* ponteiro = &x"
    char temp2[1024];
    if (strstr(line, "int ponteiro = &")) {
        replace(line, temp2, "int ponteiro = &", "int* ponteiro = &");
        strcpy(line, temp2);
    }

    // Escreve a linha processada no arquivo de saída
    fprintf(output, "%s", line);
}

// Função para criar o diretório build se não existir
void ensure_build_dir(const char *input_path) {
    char dir_path[1024] = {0};
    char temp_path[1024] = {0};
    
    // Copia o caminho para não modificar o original
    strcpy(temp_path, input_path);
    char *base_dir = dirname(temp_path);
    
    sprintf(dir_path, "%s/build", base_dir);
    
    // Verifica se o diretório já existe
    struct stat st = {0};
    if (stat(dir_path, &st) == -1) {
        // Cria o diretório
        mkdir(dir_path, 0700);
    }
}

// Função para obter o nome do arquivo sem o caminho e a extensão
void get_filename_without_ext(const char *input_path, char *output_name) {
    char temp_path[1024] = {0};
    
    // Copia o caminho para não modificar o original
    strcpy(temp_path, input_path);
    char *filename = basename(temp_path);
    
    // Copia para evitar problemas com a string possivelmente estática
    strcpy(output_name, filename);
    
    // Remove a extensão .cangaceiro
    char *dot = strrchr(output_name, '.');
    if (dot) {
        *dot = '\0';
    }
}

int main(int argc, char *argv[]) {
    // Verifica os argumentos
    if (argc < 2) {
        printf("Uso: %s <arquivo.cangaceiro>\n", argv[0]);
        return 1;
    }
    
    // Pega o caminho do arquivo de entrada
    char *input_path = argv[1];
    
    // Verifica se é um arquivo .cangaceiro
    if (strstr(input_path, ".cangaceiro") == NULL) {
        printf("Erro: O arquivo deve ter a extensão .cangaceiro\n");
        return 1;
    }
    
    // Cria o diretório build se não existir
    ensure_build_dir(input_path);
    
    // Obtém o nome base do arquivo
    char filename[256] = {0};
    get_filename_without_ext(input_path, filename);
    
    // Cria os caminhos completos para os arquivos de saída
    char c_file_path[1024] = {0};
    char exe_file_path[1024] = {0};
    char temp_path[1024] = {0};
    
    // Copia o caminho para não modificar o original
    strcpy(temp_path, input_path);
    char *base_dir = dirname(temp_path);
    
    sprintf(c_file_path, "%s/build/%s.c", base_dir, filename);
    sprintf(exe_file_path, "%s/build/%s", base_dir, filename);
    
    // Abre os arquivos
    FILE *input = fopen(input_path, "r");
    FILE *output = fopen(c_file_path, "w");
    
    if (input == NULL || output == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return 1;
    }
    
    // Adiciona cabeçalho necessário para printf
    fprintf(output, "#include <stdio.h>\n\n");
    
    char line[1024];
    while (fgets(line, sizeof(line), input) != NULL) {
        process_line(line, output);
    }
    
    fclose(input);
    fclose(output);
    
    // Compila o código gerado com gcc
    char compile_cmd[1024] = {0};
    sprintf(compile_cmd, "gcc %s -o %s", c_file_path, exe_file_path);
    
    int result = system(compile_cmd);
    if (result == 0) {
        printf("Código compilado com sucesso! Execute com '%s'\n", exe_file_path);
        
        // Remover o arquivo .c intermediário
        unlink(c_file_path);
    } else {
        printf("Erro ao compilar o código gerado!\n");
    }
    
    return 0;
}