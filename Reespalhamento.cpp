#include <iostream>

using namespace std;

const int TAM = 10;  	/* Tamanho máximo do vetor */

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
