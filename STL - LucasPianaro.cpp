 #include <iostream>
 #include <stack>
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <set>

 using namespace std;

 int main(){
    stack <int> pilha;
    queue <int> fila;
    vector <int> lista;
    vector <int>::iterator it;
    set <int> arvore;
    set <int>::iterator itr;

    pilha.push(5);
    pilha.push(15);
    pilha.push(20);
    pilha.push(25);
    pilha.push(40);

    fila.push(5);
    fila.push(15);
    fila.push(20);
    fila.push(25);
    fila.push(40);

    lista.push_back(5);
    lista.push_back(15);
    lista.push_back(20);

    arvore.insert(5);
    arvore.insert(15);
    arvore.insert(20);
    arvore.insert(25);

    for (itr = arvore.begin(); itr != arvore.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    sort(lista.begin(), lista.end());
    for(it = lista.begin(); it != lista.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


    pilha.pop();
    pilha.pop();  

    fila.pop();
    fila.pop();
    

    
    cout << "Topo:" << pilha.top() << endl;
    cout << "Primeiro fila:" << fila.front() << endl;  

    cout << "Tamanho:" << pilha.size() << endl;
    cout << "Tamanho:" << fila.size() << endl;
    
 }
