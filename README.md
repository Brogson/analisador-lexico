# 🔍 Analisador Léxico — Máquina de Moore
 
> **Trabalho 1** · Teoria da Computação  
> Autores: **Leandro Grazziolin** e **Victor Toniato**
 
---

## Comandos para rodar o código (Makefile)

make -> compila o código
make run -> executa o código
make valgrind -> executa e verifica erros no código
make clean -> limpa os arquivos objeto e executáveis
make full -> compila, executa e limpa arquivos objeto e executáveis
make valgrind-full -> compila, executa, limpa e verifica erros

---
 
## 📖 Sobre o Projeto
 
Implementação de um **Analisador Léxico** baseado em uma **Máquina de Moore**, desenvolvida em Java.
 
A Máquina de Moore é um autômato finito determinístico (AFD) com saídas associadas aos estados. Neste projeto, ela recebe uma sequência de caracteres de entrada e classifica cada lexema reconhecido em um **token**, simulando a etapa de análise léxica de um compilador.
 
---
 
## 🪙 Tokens Reconhecidos
 
| Token | Expressão Regular | Exemplos de Lexemas |
|---|---|---|
| `<ABRE_PAR>` | `(` | `(` |
| `<ABRE_COL>` | `[` | `[` |
| `<ABRE_CHV>` | `{` | `{` |
| `<FECHA_PAR>` | `)` | `)` |
| `<FECHA_COL>` | `]` | `]` |
| `<FECHA_CHV>` | `}` | `}` |
| `<NUM>` | `(1\|2\|...\|9)+` | `1`, `32`, `999` |
| `<VAR>` | `(a\|...\|z\|A\|...\|Z)(-\|a\|...\|z\|0\|...\|9\|A\|...\|Z)*` | `A`, `a_12`, `b8` |
| `<OP>` | `+\|-\|/\|*` | `+`, `-`, `/`, `*` |
| `<EOF>` | Caractere de fim de arquivo | — |
 
> Espaços, tabulações (`\t`) e quebras de linha (`\n`, `\r`) são tratados como separadores e ignorados na saída.
 
---
 
## ⚙️ Como Funciona
 
A máquina possui **11 estados** (S0 a S10), onde cada estado final tem uma saída associada ao token reconhecido.
 
```
Entrada (stream de caracteres)
        ↓
   [Estado S0] ──── transição por caractere ────▶ [Estado Sn]
                                                       ↓
                                               Token emitido
```
 
| Estado | Token de Saída |
|---|---|
| S1 | `<ABRE_PAR>` |
| S2 | `<ABRE_COL>` |
| S3 | `<ABRE_CHV>` |
| S4 | `<FECHA_PAR>` |
| S5 | `<FECHA_COL>` |
| S6 | `<FECHA_CHV>` |
| S7 | `<NUM>` |
| S8 | `<VAR>` |
| S9 | `<OP>` |
| S10 | `<EOF>` |
 
---
 
## 🚀 Como Executar
 
### Pré-requisitos
- Java 8 ou superior instalado
### Compilar e rodar
 
```bash
# Clonar o repositório
git clone https://github.com/seu-usuario/analisador-lexico-moore.git
cd analisador-lexico-moore
 
# Compilar
javac Main.java
 
# Executar
java Main
```
 
---
 
## 🗂️ Estrutura do Projeto
 
```
analisador-lexico-moore/
├── src/
│   ├── Main.java          # Ponto de entrada
│   ├── MaquinaMoore.java  # Implementação da máquina
│   ├── Estado.java        # Representação dos estados
│   └── Token.java         # Enum de tokens
├── README.md
└── exemplos/
    └── entrada.txt        # Exemplo de entrada
```
 
---
 
## 📚 Conceitos Envolvidos
 
- **Máquina de Moore**: AFD com saídas associadas aos estados, definida pela 7-upla M = (Σ, Q, δ, q0, F, Δ, G)
- **Análise Léxica**: primeira fase de um compilador, responsável por agrupar caracteres em tokens
- **Expressões Regulares**: usadas para definir o padrão de cada token reconhecido
---
