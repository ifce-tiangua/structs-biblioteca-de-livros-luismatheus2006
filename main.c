#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct{
    char Title[255];
    char Isbn[255];
    float Preco;
    int Score;
    char Editora[255];
}Livro;

typedef Livro* pLivro;

pLivro livro_aloc(int qtde);

void livro_ler(pLivro livros, int qtde);

void livro_exibe(pLivro livros, int qtde);

void livro_desaloca(pLivro livros);

int main()
{
    int qntde;
    scanf("%d", &qntde);
    pLivro livros = livro_aloc(qntde);
    livro_ler(livros, qntde);
    livro_exibe(livros,qntde);
    livro_desaloca(livros);
    
}

pLivro livro_aloc(int qtde){
    pLivro livros = (pLivro)malloc(qtde*sizeof(Livro));
    
    if(qtde == 0){
          exit(1);
    }
return livros;
}
void livro_ler(pLivro livros, int qtde){
    int i;
    for(i = 0; i < qtde; i++){
        getchar();
        fgets(livros[i].Title, sizeof(livros[i].Title),stdin);
        
        getchar();
        fgets(livros[i].Isbn, sizeof(livros[i].Isbn),stdin);
        
        scanf("%f",&livros[i].Preco );
        scanf("%d", &livros[i].Score);
        
        getchar();
        fgets(livros[i].Editora, sizeof(livros[i].Editora),stdin);
    }
    
}
void livro_exibe(pLivro livros, int qtde){
    int i;
    for(i = 0; i < qtde; i++){
        int j = i;
        if(i + 1 == i <qtde){
        printf("Livro: %d\nNome: %sISBN: %sPreço: R$ %.2f\nScore: %d\nEditora: %s\n",++j, 
        livros[i].Title,livros[i].Isbn,livros[i].Preco,livros[i].Score,livros[i].Editora);
        }
        else{
            printf("Livro: %d\nNome: %sISBN: %sPreço: R$ %.2f\nScore: %d\nEditora: %s",++j, 
        livros[i].Title,livros[i].Isbn,livros[i].Preco,livros[i].Score,livros[i].Editora);
        }
        j = 0;
    }
}
void livro_desaloca(pLivro livros){
    free(livros);
}

