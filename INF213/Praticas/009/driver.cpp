#include <iostream>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"

#include "MyStack.h"
#include "MyQueue.h"

void etapa1() {
	int v;
	MyStack<int> s;
	MyQueue<int> q;

	for (int i = 0; i < 6; i++) {
		cin >> v;
		s.push(v);
		q.push(v);
	}

	while (s.size() > 1) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << s.top() << endl;

	while (q.size() > 1) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << q.front() << endl;

	// Os números são impressos da forma inversa uma da outra
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

#include <string>

void etapa2() {
	MyStack<char> p;
	char c;
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			p.push(s[i]);
			continue;
		}

		if (p.empty()) {
			cout << "Inconsistente" << endl;
			return;
		}

		if (s[i] == ')') {
			c = p.top();
			p.pop();
			if (c != '(') {
				cout << "Inconsistente" << endl;
				return;
			}
		} else if (s[i] == ']') {
			c = p.top();
			p.pop();
			if (c != '[') {
				cout << "Inconsistente" << endl;
				return;
			}
		} else if (s[i] == '}') {
			c = p.top();
			p.pop();
			if (c != '{') {
				cout << "Inconsistente" << endl;
				return;
			}
		}
	}

	if (p.empty()) cout << "Consistente" << endl;
	else cout << "Inconsistente" << endl;
}

//---------------------------------------

// Na etapa 3 voce deve implementar MyQueue2.h e descomentar os codigos de teste abaixo...

#include "MyQueue2.h"

void etapa3() {
	char operacao;
	MyQueue2<string> q;

	//le um arquivo contendo "comandos" para a fila e aplica-os a fila criada com sua classe...
	while(cin>> operacao) {
		if(operacao=='p') {
			string st;
			cin >> st;
			q.push(st); //insere um novo elemento na sua fila...
		} else if(operacao=='f') {
			cout << q.front() << "\n";
		} else if(operacao=='P') {
			q.pop();
		} else if(operacao=='e') {
			cout << ((q.empty())?"vazia":"cheia") << "\n";
		} else cout << q.size() << "\n";
	}	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 4....


void etapa4() {
	int n;
	cin >> n;
	int v[n + 1];
	v[0] = n;
	
	for(int i = 1; i <= n; i ++){
		cin >> v[i];
	}

	int cont = v[1] + 1;
	bool flag = true;
	MyStack<int> s;

	for(int i = 1; i <= cont - 1; i++) s.push(i);

	for(int i = 2; i <= n; i ++){
		if( cont <= v[i]){
			while(cont <= v[i]){
				s.push(cont);
				cont ++;
			}
		}
		if(s.empty()!=true && s.top() >= v[i]){
			while(s.empty()!=true && s.top() >= v[i]) s.pop();
		}
		else{
			flag = false;
		}
	}

	if(flag) cout << "SIM" << endl;
	else cout << "NAO" << endl;
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
		case 4:
			cout << "Etapa 4" << endl;
			etapa4();
			break;
	}
}