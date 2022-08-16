#include <iostream>

using namespace std;

struct no {
	int dado;
	struct no *esq;
	struct no *dir;
};

struct no* raiz=NULL;

void insereArvore(int valor) {
	struct no *atual, *anterior, *novo;
	
	novo = new(struct no);
	novo->dado = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if (raiz == NULL) {
		raiz = novo;
		return;
	}
	
	atual = raiz;
	
	while (atual != NULL) {
		anterior = atual;
		if (valor < atual->dado) {
			atual = atual->esq;
		} else {
			atual = atual->dir;
		}
	}
	
	if (valor < anterior->dado) {
		anterior->esq = novo;
	} else {
		anterior->dir = novo;
	}
	cout << "Elemento inserido" << endl;
}

void insereArvoreSemRepetidos(int valor) {
	struct no *atual, *anterior, *novo;
	
	novo = new(struct no);
	novo->dado = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if (raiz == NULL) {
		raiz = novo;
		return;
	}
	
	atual = raiz;
	
	while(atual!=NULL){
		anterior=atual;
		
		if (valor == atual->dado){
			cout << "[" << atual->dado << "] inserido agora eh um numero repetido" << endl;
			return;
		}	
		else {
			if(valor < atual->dado)
				atual=atual->esq;
			else atual=atual->dir;		
		}	
	}
	
	while (atual != NULL) {
		anterior = atual;
		if (valor < atual->dado) {
			atual = atual->esq;
		} else {
			atual = atual->dir;
		}
	}
	
	if (valor < anterior->dado) {
		anterior->esq = novo;
	} else {
		anterior->dir = novo;
	}
}

void buscaArvore (int valor) {
	struct no *atual;
	
	atual = raiz;
	while (atual != NULL) {
		if (valor == atual->dado) {
			cout << "Elemento encontrado" << endl;
			return;
		}
		if (valor < atual->dado) {
			atual = atual->esq;
		} else {
			atual = atual->dir;
		}
	}
	cout << "Elemento nao encontrado" << endl;
}

void emOrdem(struct no *atual) {
	if (atual != NULL) {
		emOrdem(atual->esq);
		cout << atual->dado << " ";
		emOrdem(atual->dir);
	}
}

int main() {
	
	//insereArvore(5);
	//insereArvore(20);
	//insereArvore(4);
	//insereArvore(7);
	
	insereArvoreSemRepetidos(4);
	insereArvoreSemRepetidos(2);
	insereArvoreSemRepetidos(3);
	insereArvoreSemRepetidos(4);
	insereArvoreSemRepetidos(4);
	
	buscaArvore(3);
	buscaArvore(43);
	
	emOrdem(raiz);
}
