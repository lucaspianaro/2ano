#include <iostream>

using namespace std;

struct no {
    int dado;
    struct no *prox;
};

struct no *lista=NULL;

void insereLista(int valor) {
	struct no *atual;
	struct no *anterior;
	struct no *novo;
	
	novo=new(struct no);
	novo->dado = valor;
	atual = lista;
	while (atual != NULL && atual->dado<valor) {
		anterior = atual;
		atual = atual->prox;
	}
	if (atual==lista) {
		novo->prox = atual;
		lista = novo;
	} else {
		novo->prox = atual;
		anterior->prox=novo;
	}
	cout << "Elemento inserido!" << endl;
}

void recuperaLista(int pos) {
	struct no *atual;
	int cont=0;
	atual = lista;
	while (atual != NULL && cont!=pos) {
		atual = atual->prox;
		cont++;
	}
	if (atual!=NULL) {
		cout << "Elemento " << atual->dado << " na posicao " << pos << endl;
	} else {
		cout << "Posicao invalida!" << endl;
	}
}

void buscaLista(int valor) {
	struct no *atual;
	int pos=0, parada=0;
	
	atual = lista;
	while (atual != NULL && atual->dado<= valor) {
		if(atual->dado == valor) {
    		cout << "O valor " << valor << " esta na posicao " << pos << endl;
    		parada = 1;
		}
		atual = atual->prox;
		pos++;
    }
    	if (parada != 1) {
    		cout << "Numero nao encontrado" << endl;
	}
	
	cout << "Numero nao encontrado\n";
}

void imprime() {
    struct no *aux = lista;
    while(aux!=NULL) {
        cout<< aux->dado << " ";
        aux = aux->prox;
    }
    cout << endl;
}


int main() {
    insereLista(20);
    insereLista(30);
    insereLista(15);
    imprime();
    recuperaLista(0);
    recuperaLista(3);
    buscaLista(30);
}
