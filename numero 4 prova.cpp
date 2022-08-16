#include <iostream>

using namespace std;

const int TAM = 15;  	

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


int espalha (int chave) {
	return chave%TAM;
}

void insere (int chave) {
	int pos;
	struct no *atual, *anterior, *novo;
	
	pos=espalha(chave);
	atual = vetor[pos];
	while (atual!=NULL) {
		if(atual->chave == chave) {
			cout << "Chave repetida!" << endl;
			return;
		}
		anterior=atual;
		atual=atual->prox;
	}
	novo = new (struct no);
	novo->chave = chave;
	novo->prox = NULL;
	if(vetor[pos]==NULL) {
		vetor[pos] = novo;
	} else {
		anterior->prox = novo;
	}
}

void busca (int chave) {
	int pos;
	struct no *atual;
	int colisoes = 0;
	
	pos=espalha(chave);
	atual = vetor[pos];
	while (atual!=NULL) {
		if(atual->chave == chave) {
			cout << "Chave encontrada!" << endl;
			cout << "Numero de colisoes: " << colisoes << endl;
			return;
		}
		atual=atual->prox;
		colisoes++;
	}
	cout << "Chave nao encontrada!" << endl;
	cout << "Numero de colisoes: " << colisoes << endl;
}

int main() {

    inicia();
    
    insere(17);
    insere(47);
    insere(77);
    insere(87);
    insere(27);
    insere(37);
    insere(57);
    insere(67);
    insere(97);
    
    busca(17);
    busca(47);
    busca(77);
    busca(87);
    busca(27);
    busca(37);
    busca(57);
    busca(67);
    busca(97);
    
    imprime();
}
