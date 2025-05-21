// Sistema Gerenciador de Biblioteca

#include <stdio.h>
#include <string.h>

// Criando a estrutura Livros
typedef struct{
    char titulo[150];
    char autor[50];
    int anoDePublicacao;
    char codigoLivro[50];
    int disp;
} Livro ;


// Metodo para adicionar livros no acervo
void add (Livro *ptrLivro) {
    // Adicioando o título
    char inputTitulo[150] ;
    printf("\n\033[1mInforme o Titulo do livro: \033[0m") ;
    fgets(inputTitulo, sizeof(inputTitulo), stdin);
    strcpy(ptrLivro->titulo, inputTitulo) ;

    // Adicionando o autor
    char inputAutor[50] ;
    printf("\033[1mInforme o autor do livro: \033[0m") ;
    fgets(inputAutor, sizeof(inputAutor), stdin);
    strcpy(ptrLivro->autor, inputAutor) ;

    // Adicionando o ano de publicação
    int inputAdP;
    printf("\033[1mInforme o ano de publicacao: \033[0m") ;
    scanf("%d", &inputAdP) ;
    while(getchar() != '\n') ;
    ptrLivro->anoDePublicacao = inputAdP ;

    // Adicionando o código do livro
    char inputCL[50] ;
    printf("\033[1mInforme o codigo do livro: \033[0m") ;
    fgets(inputCL, sizeof(inputCL), stdin) ;
    strcpy(ptrLivro->codigoLivro, inputCL) ;

    // Adicionando a disponibilidade do livro
    int inputDisp ;
    printf("\033[1mInforme\033[0m \033[1;33m1\033[0m \033[1mpara livro Disponivel ou\033[0m \033[1;33m0\033[0m \033[1mpara livro indisponivel: \033[0m") ;
    scanf("%d", &inputDisp) ;
    while(getchar() != '\n') ;  // Tratamento para limpar o buffer
    ptrLivro->disp = inputDisp ;
}

//  Método para remover livros do acervo
void delete(Livro array[], char codigoLivro[], int *ptrContLivroAdd) {
    int indexDel = -1 ; //  Variável que armazenará o índice do livro a ser deletado
    //  Loop percorrendo o acervo de livros
    for (int i=0; i<*ptrContLivroAdd; i++) {
        if ((strcmp(array[i].codigoLivro, codigoLivro)) == 0) {
           indexDel = i ;   //  Índice do elemento a ser deletado
           break ;
        }
    }
    //  Condição para o caso o qual não existe o elemento no acervo
    if (indexDel == -1) {
        printf("\n\033[1;31mERRO. Codigo nao encontrado.\033[0m\n") ;
        return ; // Interromper a função
    }
    else {
        //  Loop para realizar o deslocamento dos elementos
        for (int i = indexDel; i < *ptrContLivroAdd - 1; i++) {
            array[i] = array[i + 1] ;
        }
    }
    (*ptrContLivroAdd)-- ;  // Redução de 1 elemento no acervo
    printf("\n\033[1;33mLivro removido com sucesso.\033[0m\n") ;


}


// Método para apresentar o menu de opções
void menuOpcoes() {
    printf("\n\033[1mMenu de opcoes\033[0m\n\n\
\033[0;33m1 - Adicionar Livros\033[0m\n\
\033[0;33m2 - Buscar livros\033[0m\n\
\033[0;33m3 - Listar livros\033[0m\n\
\033[0;33m4 - Deletar livros\033[0m\n\
\033[0;33m0 - Sair\033[0m\n\n") ;
}


int main() {
    Livro acervo[10] ;
    int opcao = 9, contLivroAdd = 0, tamanhoMax = sizeof(acervo)/sizeof(acervo[0]) ;
    
    while(1) {
        menuOpcoes() ;
        do {
            printf("\033[1mInforme a opcao desejada (numero): \033[0m") ;
            scanf("%d", &opcao) ;
            while(getchar() != '\n') ; // Tratamento para lipeza do buffer

            if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 0 && opcao != 4) printf("\033[1;31mOpcao invalida. Tente novamente\033[0m\n");

        } while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 0 && opcao != 4) ;

        if (opcao == 0) {
            printf("\n\033[1;33mPrograma finalizado.\033[0m\n") ;
            break ;
        }

        //  Adicionando Livros
        if (opcao == 1) {
            if (contLivroAdd >= tamanhoMax) {
                printf("\n\033[1;31mLimite maximo de livros cadastrados.\033[0m\n\n") ;
                continue ;
            }
            Livro *ptrLivro = &acervo[contLivroAdd] ;
            add(ptrLivro);
            contLivroAdd ++ ;   // Variável que armazena o número de livros adicionados
            printf("\n\033[1;33mLivro adicionado com sucesso.\033[0m\n") ;
            opcao = 9; // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
        }   //  Fim da opcao 1

        //  Pesquisar livros ;
        if (opcao == 2) {
            int flagBusca = 0;
            //  Tratando o caso para zero livros adicionados
            if (contLivroAdd == 0) {
                printf("\n\033[1;31mPesquisa invalida. Nao ha livros adicionados.\033[0m\n") ;
                continue ;
            }
            int anoPublicacaoBusca, opcaoBusca = 9, comparacao ;
            char codigoLivroBusca[50], tituloBusca[150], autorBusca[50] ;
            printf("\033[1m\nMenu de opcoes de busca\033[0m\n\n") ;
            printf("\033[1;33m1 - Titulo\n2 - Autor\n3 - Ano de publicacao\n4 - Codigo do livro\033[0m\n\n") ;
            
            //  Tratando a entrada recebida
            do {
                printf("\033[1mInforme a opcao de busca desejada: \033[0m") ;
                scanf("%d", &opcaoBusca) ;
                while(getchar() != '\n') ; //   Tratamento para limpar o buffer
                //  Mensgem de erro
                if (opcaoBusca != 1 && opcaoBusca != 2 && opcaoBusca != 3 && opcaoBusca != 4) printf("\033[1;31mOpcao invalida. Tente novamente\033[0m\n\n") ;
            } while(opcaoBusca != 1 && opcaoBusca != 2 && opcaoBusca != 3 && opcaoBusca != 4) ;
            
            //  Filtrando pelo título
            if (opcaoBusca == 1) {
                printf("\n\033[1mInforme o titulo: \033[0m") ;
                fgets(tituloBusca, sizeof(tituloBusca), stdin) ;
                //  Loop que percorre o array acervo buscando o livro através do fitro informado
                for (int i=0; i<contLivroAdd; i++) {
                    comparacao = strcmp(acervo[i].titulo, tituloBusca) ;
                    if (comparacao == 0) {
                        flagBusca = 1;  //  Livro encontrado => flagBusca = true
                        printf("\n\033[1;33mLivro encontrado.\033[0m\n\n") ;
                        printf("\033[1;33mInformacoes sobre o livro:\033[0m\n") ;
                        printf("Titulo: %s", acervo[i].titulo) ;    //  Não precisa do \n porque por algum motivo o acevo[i].atributo pula uma linha quando exibido (isso se dá por conta que o fgets armazena também o \n do buffer)
                        printf("Autor: %s", acervo[i].autor) ;  //  Não precisa do \n porque por algum motivo o acevo[i].atributo pula uma linha quando exibido 
                        printf("Ano de publicacao: %d\n", acervo[i].anoDePublicacao) ;
                        printf("Codigo do livro: %s", acervo[i].codigoLivro) ;    //  Não precisa do \n porque por algum motivo o acevo[i].atributo pula uma linha quando exibido
                        printf("Disponibilidade do livro: ") ;
                        if (acervo[i].disp == 1) printf("\033[1;32mDisponivel\033[0m\n\n") ;
                        else printf("\033[1;31mIndisponivel\033[0m\n\n") ;
                    }
                }
                if (!flagBusca) {
                    printf("\033[1;31mLivro nao encontrado\033[0m\n\n") ;
                }
                opcaoBusca = 9 ; // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
            }
            //  Filtrando por autor
            else if (opcaoBusca == 2) {
                printf("Informe o autor: ") ;
                fgets(autorBusca, sizeof(autorBusca), stdin) ;
                //  Loop que percorre o array acervo buscando o livro através do fitro informado
                for (int i=0; i<contLivroAdd; i++) {
                    comparacao = strcmp(acervo[i].autor, autorBusca) ;
                    if (comparacao == 0) {
                        flagBusca = 1;  //  Livro encontrado => flagBusca = true
                        printf("\n\033[1;33mLivro encontrado.\033[0m\n\n") ;
                        printf("\033[1;33mInformacoes sobre o livro\033[0m\n") ;
                        printf("Titulo: %s", acervo[i].titulo) ;
                        printf("Autor: %s", acervo[i].autor) ;
                        printf("Ano de publicacao: %d\n", acervo[i].anoDePublicacao) ;
                        printf("Codigo do livro: %s", acervo[i].codigoLivro) ;
                        printf("Disponibilidade do livro: ") ;
                        if (acervo[i].disp == 1) printf("\033[1;32mDisponivel\033[0m\n\n") ;
                        else printf("\033[1;31mIndisponivel\033[0m\n\n") ;
                    }
                }
                if (!flagBusca) {
                    printf("\033[1;31mLivro nao encontrado\033[0m\n\n") ;
                }
                opcaoBusca = 9 ; // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
            }
            // Filtrando por Ano de publcação
            else if (opcaoBusca == 3) {
                printf("Informe o ano de publlicacao [yyyy]: ") ;
                scanf("%d", &anoPublicacaoBusca) ; //   Não há tratamento para caso o usuário informar um ano inválido
                //  Loop que percorre o array acervo buscando o livro através do fitro informado
                for (int i=0; i<contLivroAdd; i++) {
                    if (acervo[i].anoDePublicacao == anoPublicacaoBusca) {
                        flagBusca = 1;  //  Livro encontrado => flagBusca = true
                        printf("\n\033[1;33mLivro encontrado.\033[0m\n\n") ;
                        printf("\033[1;33mInformacoes sobre o livro\033[0m\n") ;
                        printf("Titulo: %s", acervo[i].titulo) ;
                        printf("Autor: %s", acervo[i].autor) ;
                        printf("Ano de publicacao: %d\n", acervo[i].anoDePublicacao) ;
                        printf("Codigo do livro: %s", acervo[i].codigoLivro) ;
                        printf("Disponibilidade do livro: ") ;
                        if (acervo[i].disp == 1) printf("\033[1;32mDisponivel\033[0m\n\n") ;
                        else printf("\033[1;31mIndisponivel\033[0m\n\n") ;
                    }
                }
                if (!flagBusca) {
                    printf("\033[1;31mLivro nao encontrado\033[0m\n\n") ;
                }
                opcaoBusca = 9 ; // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
            }
            // Filtrando por Código do livro
            else if (opcaoBusca == 4) {
                printf("Informe o codigo do livro: ") ;
                fgets(codigoLivroBusca, sizeof(codigoLivroBusca), stdin) ;
                //  Loop que percorre o array acervo buscando o livro através do fitro informado
                for (int i=0; i<contLivroAdd; i++) {
                    comparacao = strcmp(acervo[i].codigoLivro, codigoLivroBusca) ;
                    if (comparacao == 0) {
                        flagBusca = 1;  //  Livro encontrado => flagBusca = true
                        printf("\n\033[1;33mLivro encontrado.\033[0m\n\n") ;
                        printf("\033[1;33mInformacoes sobre o livro\033[0m\n") ;
                        printf("Titulo: %s", acervo[i].titulo) ;
                        printf("Autor: %s", acervo[i].autor) ;
                        printf("Ano de publicacao: %d\n", acervo[i].anoDePublicacao) ;
                        printf("Codigo do livro: %s", acervo[i].codigoLivro) ;
                        printf("Disponibilidade do livro: ") ;
                        if (acervo[i].disp == 1) printf("\033[1;32mDisponivel\033[0m\n\n") ;
                        else printf("\033[1;31mIndisponivel\033[0m\n\n") ;
                    }
                }
                if (!flagBusca) {
                    printf("\033[1;31mLivro nao encontrado\033[0m\n\n") ;
                }
                opcaoBusca = 9 ; // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
            }
            opcao = 9 ;    // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
        } // Fim da opcao 2

        //  Listar Livros
        else if (opcao == 3) {
            int opcaoListar = 9;
            //  Tratando o caso para zero livros adicionados
            if (contLivroAdd == 0) {
                printf("\n\033[1;31mListagem invalida. Nao ha livros adicionados.\033[0m\n") ;
                continue ;
            }
            printf("\n\033[1mMenu de opcoes de listagem\033[0m\n\n") ;
            printf("\033[1;33m1 - Apenas livros disponiveis\n2 - Todos o livros\033[0m\n\n") ;
            
            do{
                printf("Informe a opcao desejada: ") ;
                scanf("%d", &opcaoListar) ;
                while(getchar() != '\n') ;  //  Tratamento para limpar o buffer
                if (opcaoListar != 1 && opcaoListar != 2) printf("\033[1;31mOpcao invalida. Tente novamente\033[0m\n") ;
            } while(opcaoListar != 1 && opcaoListar != 2) ;

            if (opcaoListar == 1) {
                printf("\n\033[1;33mLivros disponiveis:\033[0m\n") ;
                for(int i=0; i<contLivroAdd ; i++) {
                    if (acervo[i].disp == 1) {
                        printf("\033[1;32m%s\033[0m", acervo[i].titulo) ;
                    }
                }
            }
            else {
                printf("\n\033[1;33mTodos os livros:\033[0m\n") ; // array de valores 1 para livros disponiveis (verdes) e 0 para livros nao disponiveis (vermelos)
                for (int i=0; i<contLivroAdd; i++) {
                    if (acervo[i].disp == 1) printf("\033[1;32m%s\033[0m", acervo[i].titulo) ;
                    else printf("\033[1;31m%s\033[0m", acervo[i].titulo) ;
                }
                opcaoListar = 9 ;   // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
            }
            opcao = 9 ; // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
        }   //  Listar livros fim

        //  Deletar livros
        else if (opcao == 4) {
            char codLivroDel[50] ;
            if (contLivroAdd == 0) {
                printf("\n\033[1;31mERRO. Nao ha livros adicionados.\033[0m\n") ;
                continue ;
            }
            printf("Informe o codigo do livro a ser deletado: ") ;
            fgets(codLivroDel, sizeof(codLivroDel), stdin) ;
            delete(acervo, codLivroDel, &contLivroAdd) ;
            opcao = 9 ; // Redefinindo a opcao inicial. Necessário pois caso o usuário informe um valor inadequado como uma string, o programa desconsiderará essa leitura e considerará a última leitura válida
        }
    }

    return 0;
}   //  Chave da função main()