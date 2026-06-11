# 🧬 Jogo da Vida

Implementação do clássico **Jogo da Vida de Conway** em linguagem C. O projeto simula a evolução de uma população de células em uma grade bidimensional, aplicando regras simples de vizinhança para gerar padrões dinâmicos e comportamentos emergentes.

## 📖 Sobre o Projeto

O Jogo da Vida é um autômato celular criado pelo matemático John Conway em 1970. Apesar de suas regras simples, o sistema é capaz de produzir padrões complexos e interessantes ao longo das gerações.

Neste projeto, a evolução das células é calculada iterativamente a partir do estado atual do tabuleiro.

## ⚙️ Regras

A cada geração:

- Uma célula viva com menos de dois vizinhos vivos morre por solidão;
- Uma célula viva com dois ou três vizinhos vivos sobrevive;
- Uma célula viva com mais de três vizinhos vivos morre por superpopulação;
- Uma célula morta com exatamente três vizinhos vivos torna-se viva.

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Compilador GCC
- Terminal/Console

## 🚀 Compilação

Compile o projeto utilizando:

```bash
gcc main.c -o jogo_da_vida
```

## ▶️ Execução
Após a compilação:

```bash
./jogo_da_vida
```

## 📚 Conceitos Aplicados
- Matrizes bidimensionais
- Estruturas de repetição
- Estruturas condicionais
- Manipulação de memória
- Autômatos celulares
- Simulação computacional

## 👨‍💻 Autores
- Eduardo Domingues Blanco
- Ives Passini Ferreira

## 🎓 Contexto Acadêmico
Projeto desenvolvido como atividade da disciplina de Programação da PUC-Campinas.
