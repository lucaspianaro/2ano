#include <iostream>
using namespace std;

struct no  {
    int dado;
    struct no *prox;
};
struct no *topo = NULL;

void push(int valor) {
    struct no *novo;
    
    novo = new (struct no);
    novo->dado = valor;
    novo->prox = topo;
    topo = novo;
}

void pop() {
    struct no *apaga;
    
    if(topo == NULL)cout <<"Pilha vazia."<< endl;
    else
    {
        apaga = topo;
        topo = topo->prox;
        delete(apaga);
    }
}

void imprime() {
    struct no *aux = topo;
    if(aux == NULL)
    {
        cout <<"Pilha vazia."<< endl;
        return;
    }
    while(aux!=NULL)
    {
        cout<< aux->dado << " ";
        aux = aux->prox;
    }
}


void topoPilha() {
    struct no *aux = topo;
    
    if(aux != NULL)
    {
        cout << aux->dado << endl;
        return;
    }else
    {
        cout <<"Pilha vazia."<< endl;
    }

}
int main() {
    push(30);
    push(10);
    push(15);
    pop();
    push(5);
    topoPilha();
    imprime();
}
