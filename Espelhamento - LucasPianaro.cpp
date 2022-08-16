#include <iostream>

using namespace std;

const int TAM = 10;  	
int vetor[TAM];

void inicia()
{
	int i;

	for (i=0;i<TAM;i++) {
   	    vetor[i]=-1;
    }
}

void imprime()
{
	int i;

	for (i=0;i<TAM;i++) {
   	    cout << i << "-> " << vetor[i] << endl;;
    }
}

int espalha (int chave) {
	return chave%TAM;
}

int reespalha (int pos) {
	return (pos+1)%TAM;
}

void insere (int chave) {
	int cont=0;
	int pos;
	
	pos = espalha(chave);
	while (vetor[pos]!=-1 && cont!=TAM) {
		pos = reespalha(pos);
		cont++;
	}
	if(cont==TAM) {
		cout << "Tabela cheia\n" << endl;
	} else vetor[pos] = chave;
}

void busca (int chave) {
	int cont=0;
	int pos;
	
	pos = espalha(chave);
	while (vetor[pos]!=chave && vetor[pos]!=-1 && cont!=TAM) {
		pos = reespalha(pos);
		cont++;
	}
	if(vetor[pos]==chave) {
		cout << "Chave encontrada na posicao: " << pos << endl;
	} else cout << "Chave nao encontrada" << endl;
}

int main()
{
    inicia();

    insere(15);
    insere(55);
    insere(22);
    insere(2);
    insere(111);
    insere(26);
    imprime();
    
    busca(47);
    busca(222);
    busca(69);
    busca(26);
    busca(33);
}
