#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct {
    char Title[255];
    char Isbn[255];
    float Preco;
    int Score;
    char Editora[255];
} Livro;

typedef Livro* pLivro;

pLivro livro_aloc(int qtde);

void livro_ler(pLivro livros, int qtde);

void livro_exibe(pLivro livros, int qtde);

void livro_desaloca(pLivro livros);

int main() {
    int qntde;
    scanf("%d", &qntde);
    pLivro livros = livro_aloc(qntde);
    livro_ler(livros, qntde);
    livro_exibe(livros, qntde);
    livro_desaloca(livros);
}

pLivro livro_aloc(int qtde) {
    pLivro livros = (pLivro)malloc(qtde * sizeof(Livro));
    
    if (qtde == 0) {
        exit(1);
    }
    return livros;
}

void livro_ler(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        getchar();
        fgets(livros[i].Title, sizeof(livros[i].Title), stdin);
        livros[i].Title[strcspn(livros[i].Title, "\n")] = '\0';
        
        fgets(livros[i].Isbn, sizeof(livros[i].Isbn), stdin);
        livros[i].Isbn[strcspn(livros[i].Isbn, "\n")] = '\0';
        
        scanf("%f", &livros[i].Preco);
        scanf("%d", &livros[i].Score);
        
        getchar();
        fgets(livros[i].Editora, sizeof(livros[i].Editora), stdin);
        livros[i].Editora[strcspn(livros[i].Editora, "\n")] = '\0';
    }
}

void livro_exibe(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Nome: %s\n", livros[i].Title);
        printf("ISBN: %s\n", livros[i].Isbn);
        printf("Preço: R$ %.2f\n", livros[i].Preco);
        printf("Score: %d\n", livros[i].Score);
        printf("Editora: %s\n", livros[i].Editora);
    }
}

void livro_desaloca(pLivro livros) {
    free(livros);
}
