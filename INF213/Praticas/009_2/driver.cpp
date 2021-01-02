#include <iostream>

using namespace std;




//Codigo da etapa 1 (na pronto...)
#include "MyPriorityQueue2.h"
#include "MyPriorityQueue.h"

//Faz testes com uma fila de prioridades de inteiro...
//Nao altere nada aqui na parte da etapa 1 do driver (apenas implemente MyPriorityQueue2)
template<class PQ>
void testaMyPriorityQueue() {
	PQ filaPrioridades;
	char opcao;
	int maxSize = 0;
	int numPush = 0;
	int numPop = 0;
	while(cin >> opcao) {
		maxSize = max(maxSize, filaPrioridades.size());
		switch(opcao) {
			case 'S':
				cout << filaPrioridades.size() << "\n";
				break;
			case 'P': //teste com push... 
				numPush++;
				int x;
				cin >> x;
				filaPrioridades.push(x);
				break;
			case 'p': //testes com pop
				numPop++;
				filaPrioridades.pop();
				break;
			case 'T': //testes com top
				cout << filaPrioridades.top() << "\n";
				break;
		}
	}
	cout << "Tamanho maximo da fila: " << maxSize << "\n";
	cout << "Numero de push(): " << numPush << "\n";
	cout << "Numero de pop(): " << numPop << "\n";
}
void etapa1() {
	int opcao;
	cin >> opcao;
	if(opcao==1) { //se o arquivo de entrada comecar com 1 testaremos a fila de prioridades original
 		cout << "Fila original\n" ;
 		testaMyPriorityQueue< MyPriorityQueue<int> > ();
	} else { //testaremos sua fila de prioridades..
		assert(opcao==2);
		cout << "Fila nova\n" ;
		testaMyPriorityQueue< MyPriorityQueue2<int> > ();
	}
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	int n, j, aux;
	int i = 0;
	cin >> n >> j;            
	MyPriorityQueue<int> v;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push(aux);
	}
	
	if (j == 0) {
		cout << 0 << endl;
		return;
	}
	
	if (v.size() == 0) {
		cout << -1 << endl;
		return;
	}

	while (j > 0 && v.top() > 0) {
		i++;
		j -= v.top();
		aux = v.top() / 2;
		v.pop();
		v.push(aux);
	}

	if (j <= 0) {
		cout << i << endl;
	} else {
		cout << -1 << endl;
	}
}

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
	Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;
}

//---------------------------------------




int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}