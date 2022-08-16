#include <iostream>

using namespace std;

const int TAM = 5;
int fila[TAM];
int inicio = 0;
int fim = 0;
int contador = 0;


void insereFila(int valor){
	if(contador == TAM){
		cout<<"Fila cheia. \n";
		return;
	}
	contador++;
	fila[fim]=valor;
	if(fim == TAM-1){
		fim = 0;
	}else{
		fim++;
		cout<<"Elemento "<<valor<<" inserido. \n";
	}
}
void removeFila(){
	if(contador == 0){
		cout<<"Fila vazia. \n";
		return;
	}
	contador--;
	
	if(inicio == TAM-1){
		inicio = 0;
	}else{
		inicio++;
		cout<<"Elemento removido. \n";
	}
}

void inicioFila(){
	if(contador == 0){
		cout<<"Fila vazia. \n";
		return;
	}	
	cout<< fila[inicio]<<endl;
}
int main(){
	insereFila(10);
	insereFila(20);
	insereFila(15);
	inicioFila();
	removeFila();
	removeFila();
	inicioFila();
}


