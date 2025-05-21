# Documentação do Sistema de Gerenciamento de Livros

## Descrição do Sistema

Este projeto foi desenvolvido em C com o objetivo de exercitar os conhecimentos sobre os conceitos de vetores `array`, funções, estruturas `struct` e ponteiros. O presente sistema, por meio de uma interface de terminal, permite ao usuário cadastrar, listar, buscar e remover livros. O sistema armazena os livros em um array de estrutura (`struct`), mantendo informações como código, título e autor.

## Funcionalidades

1.  **Adicionar Livro**: Permite cadastrar um novo livro informando código, título e autor.
    
2.  **Listar Livros**: Exibe todos os cadastrados no sistema.
    
3.  **Buscar Livro**: Permite pesquisar um livro por seus campos como: título, autor, código do livro e ano de publicação.
    
4.  **Remover Livro**: Exclui um livro do acervo com base no seu código.
    

## Estrutura do Código

O sistema é baseado em:

-   Uma estrutura `struct Livro` que define os atributos de um livro.
    
-   Um array `acervo[]` para armazenar os livros.
    
-   Métodos para manipulação dos livros no array:
    
    -   `add()` - Adiciona um novo livro ao acervo.
    
    -   `delete()` - Remove um livro e reorganiza o array.
    

## Instruções de Compilação e Execução

### Requisitos

-   Compilador C (GCC, MinGW ou outro compatível)
    
-   Terminal (Windows: CMD/Powershell, Linux/macOS: Shell)
    

### Compilação

No terminal do Windows, execute o seguinte comando para compilar o programa:

```
cd "caminho do diretório que contém o código fonte do sistema"
gcc nomeDoArquivo.c -o nomeDoArquivoCompilado
```

### Execução

Para executar o programa no Windows certifique-se de estar no diretório correto, caso precise mudar de diretório, execute, no terminal:

```
cd "caminho do diretório que contém o arquivo compilado"
.\"nome do arquivo compilado"
```
    

## Conclusão

O sistema de gerenciamento de livros permite operações básicas de registros de livros em uma biblioteca, além disso, o código tem tratamento de erros para evitar alguns erros de entrada inválida. Assim, atendendo ao propósito de ser um software simples com interface no terminal.
