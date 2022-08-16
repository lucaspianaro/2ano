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


void selectionSort() {
    int i, current, k, temp;
    for (i=0; i <=TAM-2; i++){
        current = i;
        for(k=i+1; k<=TAM-1; k++){
            if(vetor[current] > vetor [k])
                current = k;
        }
        temp = vetor[i];
        vetor[i] = vetor[current];
        vetor[current] = temp;
    }
}

void mergeSort (int lo, int hi) {
	int mid, L, H, k;
	
	if (lo < hi) {
		mid = (lo + hi) / 2;
		mergeSort(lo, mid);
		mergeSort(mid+1, hi);
		L = lo;
		H = mid + 1;
		for (k = lo; k <= hi; k++) {
			if (L <= mid && (H > hi || vetor[L] < vetor[H])) {
				scratch[k] = vetor[L];
				L = L + 1;
			} else {
				scratch[k] = vetor[H];
				H = H + 1;
			}
		}
		for (k = lo; k <= hi; k++) {
			vetor[k] = scratch[k];
		}
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
	
	cout << "mergeSort: " << endl;
	tempo1 = clock();
	mergeSort(0, TAM-1);
	imprime();
	tempo2 = clock() - tempo1;
	cout << "Tempo mergeSort: " << (float) tempo2/CLOCKS_PER_SEC << " s\n" << endl;
	tempo1 = 0; tempo2 = 0;
	
	cout << "selectionSort: " << endl;
	gera();
	tempo1 = clock();
	selectionSort();
	imprime();
	tempo2 = clock() - tempo1;
	cout << "Tempo selectionSort: " << (float) tempo2/CLOCKS_PER_SEC << " s\n" << endl;
	tempo1 = 0; tempo2 = 0;
}
