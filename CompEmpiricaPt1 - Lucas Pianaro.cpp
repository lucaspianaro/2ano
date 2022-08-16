#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 10;

clock_t tempo1;
clock_t tempo2;

int vetor[TAM];
int scratch[TAM];
int tamheap;

void gera() {
	int i; 
	for (i = 0; i < TAM; i++)
		vetor[i]=rand();
}

void imprime() {
	int i;
	for (i = 0; i < TAM; i++)
		cout << vetor[i] << " ";
	cout << endl;
}

void bubbleSort() {
	int pass, sorted, i, temp;
	pass= 1;
	sorted= 0;
	while (!sorted && pass < TAM) {
		sorted = 1;
		for (i = 0; i <= TAM-pass-1; i++) {
			if (vetor[i] > vetor[i+1]) {
				temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				sorted = 0;
			}
		}
		pass = pass + 1;
	}
}

int partition(int p, int r) {
	int piv, i, j, k;
	piv = vetor[p];
	i = p - 1;
	j = r + 1;
	
	while (true) {
		do {
			j--;
		} while (vetor[j] > piv);
		do {
			i++;
		} while (vetor[i] < piv);
		if (i < j) {
			k = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = k;
		}else return j;
	}
}

int quickSort(int p, int r) {
	int q;
	if (p < r) {
		q = partition(p, r);
		quickSort(p, q);
		quickSort(q+1, r);
	}
}


int main() {
	gera();
	cout << "Vetor original: " << endl;
	imprime();
	cout << endl;
	
	cout << "bubbleSort: " << endl;
	gera();
	tempo1 = clock();
	bubbleSort();
	imprime();
	tempo2 = clock() - tempo1;
	cout << "Tempo bubbleSort: " << (float) tempo2/CLOCKS_PER_SEC << " s\n" << endl;
	tempo1 = 0; tempo2 = 0;
	
	cout << "quickSort: " << endl;
	gera();
	tempo1 = clock();
	quickSort(0, TAM-1);
	imprime();
	tempo2 = clock() - tempo1;
	cout << "Tempo quickSort: " << (float) tempo2/CLOCKS_PER_SEC << " s\n" << endl;
	tempo1 = 0; tempo2 = 0;
}
