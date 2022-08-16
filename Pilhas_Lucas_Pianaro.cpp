#include <iostream>

using namespace std;

const int TAM=6;
int pilha[TAM];
int topo=-1;


void push(int valor){
	if(topo == TAM -1){
		cout <<"Pilha cheia!"<< endl;
		return;
	}
	topo = topo + 1;
	pilha[topo] = valor;
	cout <<"Valor inserido com sucesso!"<< endl;
}

void imprime(){
	int i;
	for(i = 0; i<= topo; i++){
		cout << pilha[i]<<" "<< endl;
	}
}
void pop(){
	if(topo ==  -1){
		cout <<"Pilha vazia!"<< endl;
		return;
	}
	topo = topo - 1;
}
void topoPilha(){
	if(topo ==  -1){
		cout <<"Pilha vazia!"<< endl;
		return;
	}
	
	cout<<pilha[topo]<< endl;
}
int main(){
	push(10);
	push(15);
	pop();
	topoPilha();
	imprime();
}
