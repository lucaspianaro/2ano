#include <iostream>

using namespace std;

const int TAM=10;

struct no {
    int destino;
    struct no *prox;
};

int vertice[TAM];
struct no *arestas[TAM];

int n_vertices=0;

void inicia_grafo() {
    int i;

    for (i=0; i<TAM; i++)
        arestas[i]=NULL;
}

void insereVertice(int valor){
	if (n_vertices<TAM){
		for (int i=0; i<n_vertices; i++){
			if (vertice[i]==valor){
				cout << "Repetido!\n" << endl;
				return;
			}
		}
		vertice[n_vertices] = valor;
		n_vertices++;
	}else{
		cout << "Vetor Cheio!\n" << endl;
	}
	
}

void insereAresta(int orig, int dest) {
    int i=0, j=0;
    struct no *atual, *novo, *anterior;

    while (i<n_vertices && vertice[i]!=orig)
        i++;
    if (i==n_vertices) {
        cout << "Nao existe vertice de origem" << endl;
        return;
    }
    while (j<n_vertices && vertice[j]!=dest)
        j++;
    if (j==n_vertices) {
        cout << "Nao existe vertice de destino" << endl;
        return;
    }
    
    atual=arestas[i];
    while (atual!=NULL) {
    	if (atual->destino==dest) {
      		cout << "Repetida" << endl;
    		return;	
		}
		anterior=atual;
		atual=atual->prox;
	}
	
	novo=new(struct no);
	novo->destino=dest;
	novo->prox=NULL;
	if (arestas[i]==NULL)
		arestas[i]=novo;
	else anterior->prox=novo;
}

void removeAresta(int orig, int dest) {
    int i=0, j=0;
    struct no *atual, *novo, *anterior;

    while (i<n_vertices && vertice[i] != orig)
        i++;
    if (i==n_vertices) {
        cout << "Nao existe vertice de origem" << endl;
        return;
    }
    while (j<n_vertices && vertice[j]!=dest)
        j++;
    if (j==n_vertices) {
        cout << "Nao existe vertice de destino" << endl;
        return;
    }
    
    atual=arestas[i];
    while (atual != NULL) {
    	if (atual->destino==dest) {
    		if (arestas[i]==atual)
    			arestas[i]=arestas[i]->prox; 
			else anterior->prox=atual->prox; 
			delete(atual);
			return;
		}
		anterior=atual;
		atual=atual->prox;
	}
}

void haAresta(int orig, int dest) {
    int i=0, j=0;
    struct no *atual, *novo, *anterior;

    while (i<n_vertices && vertice[i]!=orig)
        i++;
    if (i==n_vertices) {
        cout << "Nao existe vertice de origem" << endl;
        return;
    }
    while (j<n_vertices && vertice[j]!=dest)
        j++;
    if (j==n_vertices) {
        cout << "Nao existe vertice de destino" << endl;
        return;
    }
	
    atual=arestas[i];
    while (atual!=NULL) {
    	if(atual->destino==dest) {
      		cout << "Existe aresta" << endl;
    		return;	
		}
		atual=atual->prox;
	}
	cout << "Valor Inexistente" << endl;
}

void imprimeGrafo() {

    struct no *atual;

	cout << endl;
    for (int i=0; i<n_vertices; i++) {
        cout << vertice[i] << " -> " ;
        for (atual=arestas[i]; atual!=NULL; atual=atual->prox)
            cout << "<" << vertice[i] << "," << atual->destino << "> ";
        cout << endl;
    }
    cout << endl;
}



int main() {

	inicia_grafo();

	insereVertice(10);
	insereVertice(20);
	insereVertice(30);
	insereVertice(40);
	insereVertice(50);
			
    insereAresta(10,40);
    insereAresta(20,30);
    insereAresta(20,50);
    insereAresta(30,40);
    insereAresta(50,40);
    insereAresta(60,10);
    insereAresta(10,60);
    imprimeGrafo();

    haAresta(10,40);
    haAresta(40,10);
    haAresta(60,40);
    haAresta(40,60);

    removeAresta(40,10);
    removeAresta(20,30);
    removeAresta(20,50);
    removeAresta(60,10);
    removeAresta(10,60);
    imprimeGrafo();

}
