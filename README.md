# 🌵 Cangaceiro++ - A Linguagem de Programação do Nordeste

## 📖 Sobre
Cangaceiro++ é uma linguagem de programação inspirada em C, na relidade um Transpilador, que traz um toque regional nordestino para o mundo da programação. Mantendo a lógica do C, adaptamos a sintaxe para refletir o jeito único que o nordestino fala e suas expressões típicas.

Foi inspirada pelo desafio do Criascript: [Desafiei um inscrito a criar uma linguagem de programação](https://www.youtube.com/watch?v=5TzJmj7W2nY)

Até pensei em utilizar o LLVM, mas a cachaça tá muito cara!

Para falar que eu não tentei, eu tentei mais depois de classes e mais classes com lexer, parser e compiler e mais de 1000 linhas, é loucura aprender o LLVM em 1 hora, por isso um transpilador!

## 🔍 Características Principais

### 1. Estrutura Base
| C Tradicional | Cangaceiro++ | Significado |
|---------------|--------------|-------------|
| `main()`      | `oxente mainha()` | "Oxente" é uma expressão de surpresa/ênfase, perfeita para a função principal! |

### 2. Tipos de Dados
| C Tradicional | Cangaceiro++ | Significado |
|---------------|--------------|-------------|
| `int`         | `inteiroxi`  | Número inteiro com sotaque regional (-xi) |
| `float`       | `quaseinteiro` | Número decimal (quase inteiro, mas tem vírgula!) |
| `char`        | `letrinha`   | Um caractere sozinho |

### 3. Entrada e Saída
| C Tradicional | Cangaceiro++ | Significado |
|---------------|--------------|-------------|
| `printf()`    | `visse()`    | "Visse?" para mostrar algo na tela |
| `scanf()`     | `ôxe()`      | "Ôxe!" para receber dados do usuário |

### 4. Estruturas Condicionais
| C Tradicional | Cangaceiro++ | Significado |
|---------------|--------------|-------------|
| `if`          | `ifoxente`   | Para testar condições |
| `else`        | `senãohomi`  | Para alternativas |

### 5. Laços de Repetição
| C Tradicional | Cangaceiro++ | Significado |
|---------------|--------------|-------------|
| `for`         | `arretado()` | Repetição rápida e forte |
| `while`       | `vish()`     | Repetição que pode demorar |

### 6. Ponteiros e Referências
| C Tradicional | Cangaceiro++ | Significado |
|---------------|--------------|-------------|
| `*`           | `mire`       | Ponteiro que mira um endereço |
| `&`           | `aperte`     | Referência que agarra o valor |

### 7. Retorno
| C Tradicional | Cangaceiro++ | Significado |
|---------------|--------------|-------------|
| `return`      | `volte`      | Retorna um valor e "volta" |

## 📝 Exemplo de Código

```c
oxente mainha() {
    inteiroxi x = 8;
    quaseinteiro y = 3.5;
    letrinha letra = 'A';

    mire inteiroxi ponteiro = aperte x;
    aperte inteiroxi referencia = x;

    visse("Valor de x: %d\n", x);
    visse("Valor de y: %.2f\n", y);
    visse("Letra: %c\n", letra);
    visse("Ponteiro aponta pra: %d\n", mire ponteiro);
    visse("Referência tem: %d\n", referencia);

    ifoxente (x > 5) {
        visse("Eita, x é maior que 5!\n");
    } senãohomi {
        visse("Oxente, x é menor ou igual a 5!\n");
    }

    arretado (inteiroxi i = 0; i < 5; i++) {
        visse("Rodando o for arretado: %d\n", i);
    }

    inteiroxi capa_while = 0;
    vish (i < 5) {
        visse("Rodando o while vish: %d\n", capa_while);
        capa_while++;
    }

    inteiroxi capa_while = 0;
    vish (i < 5) {
        visse("Rodando o while vish: %d\n", capa_while);
        capa_while++;
    }

    volte 0;
}
```

## 🚀 Como Usar

Para compilar e executar um programa em Cangaceiro++:

```bash
gcc transpilador.c -o transpilador
./transpilador programa.cangaceiro
```

---
*Feito com 💚 e muito forró!*