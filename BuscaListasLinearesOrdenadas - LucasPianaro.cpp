#include <iostream>
#include <cstdlib>

using namespace std;

const int TAM=20000;

int vetor[TAM+1];
float comparaS, comparaB;

int particao(int p, int r) {

   int pivo, temp, i, j;

   pivo = vetor[p];
   i=p-1;
   j=r+1;
   while (1) {
   	do {
      	j=j-1;
         } while (vetor[j]>pivo);
      do {
      	i=i+1;
         } while (vetor[i]<pivo);
      if (i<j)
      	{
         temp = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = temp;
         }
         else return j;
   }
}

void quick(int p, int r) {

   int q;

	if (p < r) {
   	  q = particao(p,r);
      quick(p,q);
      quick(q+1,r);
   }
}

void sequencial(int chave) {
	int i;
	i=0;
	
	while( i<TAM && vetor[i]<chave) {
		i++;
		comparaS++;
	}
//	if (i!=TAM && vetor[i]==chave)
//	cout << "Achei na posicao" << i << endl;
//	else 
//		cout << "Nao achei" << endl;
}

void sequencialSentinela (int chave) {
	int i;
	i=0;
	
	vetor[TAM]=chave;
	while (vetor[i]<chave) {
		i++;
	}
	if (i!=TAM && vetor[i] == chave)
		cout << "Achei na posicao" << i << endl;
	else 
		cout << "Nao encontrei" << endl;
}

void geraVetor() {

   int i;
   cout <<  "Gerando vetor randomico...." << endl;
   for (i=0;i<TAM;i++) {
       vetor[i]=rand();
   }
}

void imprime() {
	int i;

    for (i=0; i<TAM; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void binaria (int chave) {
	int primeiro = 0, ultimo = TAM - 1, meio;
	
	while (primeiro < ultimo) {
		comparaB++;
		meio = (primeiro + ultimo) / 2;
		
		if (vetor[meio] == chave) {
			//cout << "Achei na posicao "<<meio << endl;
			return;
		}		
		if ( chave < vetor[meio]) {
			ultimo = meio;
		} else {
			primeiro = meio + 1;
		}
	}
	return;
}


int main()

{
 	int i, chavebusca;

	setlocale(LC_ALL,"");

    geraVetor();
    cout << "Classificando vetor... " << endl;
    quick(0,TAM-1);
    cout << "Fazendo buscas" << endl;


    comparaS=0;
    comparaB=0;
    for (i=0;i<1000;i++) {
   	  chavebusca=rand();
   	  sequencial(chavebusca);
      binaria(chavebusca);
    }

    cout << "Sequencial: Numero medio de operacoes de comparacao " << comparaS/1000 << endl;
    cout << "Binaria: Numero medio de operacoes de comparacao " << comparaB/1000 << endl;

}
