#include <iostream>

using namespace std;

const int TAM = 10;

struct no {
    int chave;
    struct no *prox;
};

struct no *vetor[TAM];

void inicia() {
    for (int i=0; i<TAM; i++) {
        vetor[i] = NULL;
    }
}

int espalha(int chave) {
	return chave%TAM;
}

void insere(int chave) {
	int pos;
	struct no *atual, *anterior, *novo;
	
	pos=espalha(chave);
	atual = vetor[pos];
	while (atual!=NULL) {
		if (atual->chave == chave) {
			cout <<"Chave repetida!" << endl;
			return;
		}
		anterior = atual;
		atual = atual->prox;
	}
	novo = new (struct no);
	novo->chave = chave;
	novo->prox = NULL;
	if (vetor[pos]==NULL)
		vetor[pos] = novo;
	else anterior->prox = novo;
}

void busca(int chave) {
	int pos;
	struct no *atual;
	
	pos=espalha(chave);
	atual = vetor[pos];
	while (atual!=NULL) {
		if(atual->chave == chave) {
			cout << "Chave encontrada!" << endl;
			return;
		}
		atual = atual->prox;	
	}
	cout << "Chave nao encontrada!" << endl;
}

void imprime() {
    struct no *atual;
    int i;

    for (i=0; i<TAM; i++) {
        cout << i << " -> ";
        atual=vetor[i];
        while (atual!=NULL) {
            cout << atual->chave << " ";
            atual=atual->prox;
        }
        cout << endl;
    }
}

int main() {

    inicia();
    insere(31);
    insere(32);
    insere(42);
    insere(57);
    insere(59);
    insere(51);
    insere(44);
    insere(88);
    insere(39);
    
    busca(31);
    busca(32);
    busca(42);
    busca(57);
    busca(59);
    busca(51);
    busca(44);
    busca(88);
    busca(39);
    imprime();

}
