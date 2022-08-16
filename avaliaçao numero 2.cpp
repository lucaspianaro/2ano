#include <iostream>

using namespace std;

struct no {
    int dado;
    struct no *prox;
};

struct no *lista = NULL;

int insereLista(int valor) {
    struct no *atual;
    struct no *anterior;
    struct no *novo;

    novo = new(struct no);
    if (valor >= 0) {
        novo->dado = valor;
        atual = lista;
    } else {
        cout << "Insira somente valores positivos" << endl;
        return 0;
    }
    while(atual != NULL && atual->dado < valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == lista) {
        novo->prox = atual;
        lista = novo;
    } else {
        novo->prox = atual;
        anterior->prox = novo;
    }
    cout <<"Elemento inserido.\n";
}

void maiorQueDez() {
    struct no *aux = lista;
    int maior = 0;
    if(aux == NULL) {
        cout<<"A lista esta vazia."<< endl;
    } else {
        while(aux != NULL) {
            if(aux->dado > 10) {
                maior++;
                aux = aux->prox;
            } else {
                aux = aux->prox;
            }
        }
        cout<< "A lista tem "<<maior<<" numeros maiores que dez."<< endl;
    }
}


void imprime() {
    struct no *aux = lista;
    while(aux != NULL) {
        cout << aux->dado <<" " << endl;
        aux = aux->prox;
    }
}


int main() {
    insereLista(-4);
    insereLista(20);
    insereLista(25);
    imprime();
    maiorQueDez();
}
