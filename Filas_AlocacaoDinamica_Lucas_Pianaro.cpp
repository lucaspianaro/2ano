#include <iostream>

using namespace std;

struct no 
{
    int dado;
    struct no *prox;
};

struct no *inicio;
struct no *fim;

void insereF(int valor) {
    struct no *novo;
    novo = new (struct no);
    novo->dado = valor;
    novo->prox = NULL;
    if(fim == NULL) {
        fim = novo;
        inicio = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
}

void imprime() {
    struct no *aux = inicio;
    while(aux!=NULL) {
        cout<< aux->dado << " ";
        aux = aux->prox;
    }
}

void removeF() {
    struct no *apaga;
    if(inicio == NULL)cout <<"Pilha vazia."<< endl;
    else {
        apaga = inicio;
        inicio= inicio->prox;
        delete(apaga);
    }
}

void inicioF() {
    struct no *aux = inicio;
    if(aux == NULL) {
        cout <<"Pilha vazia."<< endl;
        return;
    } else {
        cout << aux->dado << endl;
    }
}

int main() {
    insereF(10);
    insereF(20);
    insereF(30);
    removeF();
    insereF(6);
    inicioF();
    imprime();
}
