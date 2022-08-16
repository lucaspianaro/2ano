#include <iostream>

using namespace std;

const int TAM = 6;
int lista[TAM];
int tamanho = 0;

void insereLista(int valor)
{
	int i;
	if(tamanho == TAM)
	{
		cout <<"Lista Cheia!\n";
		return;
	}
	for(i = tamanho; i > 0 && valor<lista[i-1] ; i--)
	{
		lista[i] = lista[i-1];
	}
	lista[i] = valor;
	tamanho++;
	cout <<"Elemento inserido\n";
}

void removeLista(int valor)
 {
    int i, j;
    for (i=0; i<tamanho && valor>=lista[i]; i++)
	{
        if (lista[i]==valor) 
		{
            for (j=i; j<tamanho-1; j++)
			{
                lista[j]=lista[j+1];
            }
            tamanho--;
            cout << "Elemento removido \n";
            return;
        }
    }
    cout << "Elemento nao foi encontrado \n";

}

void imprime()
{
	int i;
	for(i = 0; i < tamanho ; i++)
	{
		cout << lista[i] << " ";
	}
	cout << endl;
}

void buscaLista(int valor) 
{
    int i;
    for(i=0; i<tamanho && valor>=lista[i]; i++) 
	{
        if (lista[i]==valor) 
		{
            cout << "Valor encontrado na posicao: " << i << endl;
            return;
        } 
    }
    cout << "Elemento nao encontrado" << endl;
    return;
}

int main()
{
	insereLista(9);
	insereLista(16);
	insereLista(5);
	insereLista(11);
	imprime();
	removeLista(16);
	removeLista(8);
	buscaLista(11);
	imprime();
}
