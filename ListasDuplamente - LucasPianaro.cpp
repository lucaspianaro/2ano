#include <iostream>

using namespace std;

struct no {
    int dado;
    struct no *prox;
    struct no *ant;
};

struct no *lista=NULL;

void insereLista(int valor) {
	struct no *atual;
	struct no *anterior=NULL;
	struct no *novo;
	
	novo=new(struct no);
	novo->dado = valor;
	atual = lista;
	while (atual != NULL && atual->dado<valor) {
		anterior = atual;
		atual = atual->prox;
	}
	novo->prox=atual;
	novo->ant=anterior;
	if (atual!=NULL) {
		atual->ant=novo;
	} 
	if (anterior!=NULL) {
		
		anterior->prox=novo;
	}
	else lista=novo;
}

void imprime() {
    struct no *aux = lista;
    while(aux!=NULL) {
        cout<< aux->dado << " ";
        aux = aux->prox;
    }
    cout << endl;
}

void contaLista(int valor) {
	struct no *atual;
	int cont=0;
	
	atual=lista;
	while (atual!=NULL && atual->dado<-valor) {
		if (atual->dado == valor) {
			cont++;
		}
		atual=atual->prox;
	}
	if (cont==0)
	cout << "Elemento nao encontrado" << endl;
	else cout << "Elemento encontrado" << cout << " vezes" << endl;
	}

int main() {
    insereLista(2);
    insereLista(5);
    insereLista(1);
    insereLista(3);
    insereLista(5);
    imprime();
    contaLista(9);
    contaLista(5);
}
