#include <iostream>
using namespace std;
struct no {
	int dado;
	struct no *prox;
};
struct no *lista=NULL;

void insereLista (int valor) {
	struct no *atual;
	struct no *anterior;
	struct no *novo;
	novo = new (struct no);
	novo->dado = valor;
	atual = lista;
	
	if (valor>=0) {
		while (atual!=NULL && atual->dado<valor) {
		anterior = atual;
		atual = atual->prox;
	}
	
	if (atual==lista) {
		novo->prox = atual;
		lista = novo;
	} else {
		novo->prox = atual;
		anterior->prox = novo;
	}
	cout << "Elemento inserido com sucesso!" << endl;
	} else {
		cout << "Não é possível inserir valores negativos." << endl;
	}
}

void buscaLista (int valor) {
	struct no *atual;
	int posicao=0;
	int x=0;
	atual = lista;
	while (atual!=NULL) {
		if (atual->dado == valor) {
			cout << "Valor " << valor << " foi encontrado na posicao " << posicao << "."<< endl;
			x++;
			atual = atual->prox;
		} else {
			atual = atual->prox;
		}
	posicao++;
}	
	if (x==0) {
		cout << "Valor " << valor << " nao foi encontrado.\n";
	} else {
		cout << endl;
		cout << "Valor " << valor << " foi encontrado " << x << " vez na lista." << endl;	
	}
}

void imprime () {
	struct no *aux = lista;
	while (aux!=NULL) {
		cout << aux->dado << " ";
		aux = aux->prox;
	}
	cout << endl;
}

int main () {
	insereLista(2);
	insereLista(5);
	insereLista(8);
	insereLista(5);
	insereLista(9);
	insereLista(5);
	insereLista(12);
	insereLista(15);
	imprime();
	buscaLista (5);
	buscaLista(3);
}
