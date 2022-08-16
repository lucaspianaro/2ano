#include <iostream>

using namespace std;

const int TAM=5;

int vetor[TAM];

int main(){
	setlocale(LC_ALL,"Portuguese");
    int i, maior, menor, soma;
    soma = 0;
    float media;
   
    cout << "Digite " << TAM << " números: ";
    for(i=0; i<TAM; i++){
        cin >> vetor[i];
    }
    for(i=0; i<TAM; i++){
       	soma = soma + vetor[i];
        cout << vetor[i] << " ";
    }
    cout << endl;
    for(i=TAM-1; i>=0; i--){
        cout << vetor[i] << " ";
    }
    cout << endl;
	
	cout << "Soma: "<< soma << endl;
	
	maior = vetor[0];
	for(i=1; i<TAM; i++){
       if(vetor[i] > maior){
       		maior = vetor[i];
	   }
    }
    cout << "Maior valor: "<< maior << endl;
    
    menor = vetor[0];
	for(i=1; i<TAM; i++){
       if(vetor[i] < menor){
       		menor = vetor[i];
	   }
    }
    cout << "Menor valor: "<< menor << endl;
    
    media = (float )soma/TAM;
    cout << "Média: "<< media << endl;
    
}
