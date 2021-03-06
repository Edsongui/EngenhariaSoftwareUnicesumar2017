#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Pilha* criarPilha(){
	Pilha *pilha;
	
	pilha = (Pilha*)malloc(sizeof(Pilha));
	if (pilha){
		pilha->topo = 0;
	}
	return pilha;
}

int liberarPilha(Pilha *pilha){
	free(pilha);
	if (pilha == NULL){
		return 1;
	} else {
		return 0;
	}
}

int empilhar(Pilha *pilha){
	
	Livro livro;
	
	if (pilha == NULL){
		printf("Pilha n�o foi criada!");
		return 0;
	}
	if (pilha->topo == tamanho){
		printf("Pilha est�  cheia!");
		return 0;
	}
	fflush(stdin);
	printf("\nInforme o c�digo do livro: ");
	scanf("%d", &livro.codigo);
	fflush(stdin);
	printf("Informe o t�tulo do livro: ");
	fgets(livro.titulo,max,stdin);
	fflush(stdin);
	printf("Informe o autor do livro: ");
	fgets(livro.autor,max,stdin);
	
	pilha->livros[pilha->topo] = livro;
	pilha->topo++;
	return 1;
}

void desempilhar(Pilha *pilha){
	int i;
	Livro livro;
	
	if (pilha == NULL){
		printf("Pilha n�o foi criada!");
		return;
	}
	if (pilha->topo == 0){
		printf("Pilha est� vazia!");
		return;
	}
	livro = pilha->livros[pilha->topo-1];
	printf("Desempilhando livro: ");
	printf("\nC�digo: %d T�tulo: %s Autor: %s", livro.codigo, livro.titulo, livro.autor);
	pilha->topo--;
}

void imprimir(Pilha *pilha){
	int i;
	Livro livro;
	printf("\nLivros: %d", pilha->topo);
	printf("\n");
	for (i = 0; i < pilha->topo; i++){
		livro = pilha->livros[i];
		printf("C�digo: %i , T�tulo: %s, Autor: %s", livro.codigo, livro.titulo, livro.autor);
	}
}
