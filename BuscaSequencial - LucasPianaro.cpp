#include <iostream>

using namespace std;

const int TAM = 10;

int vetor[TAM+1] = {25,5,23,10,9,7,4,18,12,34};

//feito em aula
void sequencial(int chave) {
	int i = 0;
	
	while (i < TAM && chave != vetor[i]) {
		i++;
	}
	if (i != TAM) {
		cout << "Encontrei na posicao " << i << endl;
	} else  {
		cout << "Nao encontrei!" << endl;
	}
}

void sequencialSentinela(int chave) {
	int i = 0;
	vetor[TAM] = chave;
	
	while(chave != vetor[i]) {
		i++;
	}
	if (i != TAM) {
		cout << "Encontrei na posicao " << i << endl;
	} else  {
		cout << "Nao encontrei!" << endl;
	}
}

void sequencialTransposicao(int chave) {
	int i = 0;
	int j;
	
	while (i < TAM && chave != vetor[i]) {
		i++;
	}
	if (i != TAM) {
		if (i-1 >= 0) {
			j = vetor[i]; vetor[i] = vetor[i-1]; vetor[i-1] = j;
			cout << "Encontrado e transposto!" << endl;
		} else {
			cout << "Ja esta no topo!" << endl;
		}
	} else  {
		cout << "Nao encontrei!" << endl;
	}
	
}

void sequencialMoverPraFrente(int chave) {
	int i = 0;
	int j;
	
	while (i < TAM && chave != vetor[i]) {
		i++;
	}
	if (i != TAM) {
		cout << "Encontrei e movi pra frente " << endl;
		for(j=i; j>0; j--) {
			vetor[j] = vetor[j-1];
		}
		vetor[0] = chave;
	} else  {
		cout << "Nao encontrei!" << endl;
	}
}

void imprime() {
	int i;
	for (i = 0; i < TAM; i++) {
		cout << vetor[i] << " ";
	}
	cout << endl;
}

int main () {
	int num = 5;
	int j = 9;
	sequencial(num);
	sequencialSentinela(num);
	sequencialMoverPraFrente(num);
	sequencialTransposicao(j);
	imprime();
}
