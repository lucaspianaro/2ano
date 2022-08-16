#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct no {
    int dado;
    struct no *prox;
};

struct no *lista=NULL;

void geraLista(int tam) {
    struct no *novo;

    while (tam>0) {
        novo = new (struct no);
        novo->dado=rand()%(tam*2);  // gera números aleatórios entre 0 e tam*2;
        novo->prox=lista;
        lista=novo;
        tam--;
    }
}

void sequencial (int chave) {
	int i = 0;
	struct no *atual=lista;
	
	while (atual!= NULL && atual->dado!=chave) {
		atual = atual->prox;
		i++;
	}
	if (atual!=NULL) {
		cout << "Encontrei na posicao " << i << endl;				
	} else cout << "Nao encontrei." << endl;
}

void sequencialMoverFrente (int chave) {
	int i = 0;
	struct no *atual=lista;
	struct no *anterior;
	
	while (atual!= NULL && atual->dado!=chave) {
		anterior = atual;
		atual = atual->prox;
		i++;
	}
	if (atual!=NULL) {
		cout << "Encontrei na posicao " << i << endl;
		if (atual!=lista) {
			anterior-> prox = atual->prox;
			atual->prox = lista;
			lista = atual;
		}
	}
	else cout << "Nao encontrei." << endl;
}

void sequencialTransposicao (int chave) {
	int i = 0;
	struct no *atual=lista;
	struct no *anterior;
	
	while (atual!= NULL && atual->dado!=chave) {
		anterior = atual;
		atual = atual->prox;
		i++;
	}
	if (atual!=NULL) {
		cout << "Encontrei na posicao " << i << endl;
		if (atual!=lista) {
//			atual-> prox = anterior->atual;
//			atual->anterior = lista;
//			lista = atual;
		}
	}
	else cout << "Nao encontrei." << endl;
}

void imprimeLista() {
    struct no *atual=lista;

    cout << "Lista: ";
    while (atual!=NULL) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}

int main()

{
    geraLista(10);
    sequencial(14);
    sequencial(13);
    sequencialMoverFrente(14);
    sequencialMoverFrente(13);
    sequencialTransposicao(13);
    imprimeLista();
}
