/*
TAD MyList2
- Representa uma lista implementada por encadeamento simples
- Criado por Salles Magalhaes em 19/02/2018

*/

#ifndef MyList2_H__
#define MyList2_H__

#include <iostream>
#include <string>
#include <ostream>

using namespace std;

//Excessao usada pela classe MyList2
class MyList2Exception {
private:
	std::string msg;
public:
	MyList2Exception (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};



template<class T>
class Node;

template<class T>
class Node { //a classe Node sera "escondida" quando trabalharmos com iteradores
	public:
		Node(const T&elem): data(elem), next(NULL), prev(NULL) {}
		T data;
		Node<T> *next;
		Node<T> *prev;
};

template<class T>
class MyList2 {
public:
	//decidimos utilizar o typedef com o objetivo de "abstrair" o conceito de iterador (a utilidade disso sera vista posteriormente)
	typedef Node<T> * iterator; //define um iterador, um tipo utilizado para percorrer uma estrutura de dados e "apontar" para os items armazenados nela

	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyList2<T2> &);

	//construtores/destrutures/etc
	MyList2();
	MyList2(int n, const T&init=T());

	//destrutor
	~MyList2() { destroy(); };

	//Construtor de copia
	MyList2(const MyList2 &);
	MyList2 & operator=(const MyList2 &);

	int eraseMatchingElements(const T&);
	void reverse();
	bool compare(const iterator, const iterator) const;

	//funcoes de acesso
	void push_back(const T&);
	void push_front(const T&);
	void insert(const T&,iterator where); //insere o primeiro argumento NA POSICAO apontada pelo segundo elemento
																					//os outros elementos sao deslocados
																				//diferentemente da lista simplesmente encadeada, aqui podemos inserir um elemento na posicao
																				// "where" de forma eficiente!
	iterator erase(iterator elem); //remove o elemento apontado por Elem
														//retorna o (apontador) para o elemento apos o removido

	iterator begin() {return dataFirst;} //Exercicio: e se tivermos uma lista constante, como itera-la para, por exemplo, imprimir os elementos?
	iterator end() {return NULL;} //retorna um apontador para um nodo que estaria APOS o final da lista
	iterator  next(iterator curr);
	iterator  prev(iterator curr);
	T& deref(iterator curr); //Retorna o elemento da lista apontado por curr (faz uma "derreferencia")
	

	//versoes constantes dos 4 metodos acima
	const iterator begin() const {return dataFirst;} //Exercicio: e se tivermos uma lista constante, como itera-la para, por exemplo, imprimir os elementos?
	const iterator end() const {return NULL;} //retorna um apontador para um nodo que estaria APOS o final da lista
	const iterator next(const iterator curr) const;
	const iterator prev(const iterator curr) const;
	const T& deref(const iterator curr) const; //Retorna o elemento da lista apontado por curr

	void clear();

	//Exercicio: implementar as duas funcoes abaixo supondo que nao ha um membro de dados dataSize (o calculo do tamanho da lista seria dinamico)
	void empty() const {return size() == 0;};
	int size() const; //{return dataSize;}; // na STL List, a funcao size() calcula o tamanho da lista dinamicamente (exercicio: qual a ordem de complexidade?)

private:
	Node<T> *dataFirst, * dataLast;
	int dataSize; //quantos elementos ha na lista?

	void create();
	void destroy();
	void destroy(iterator it);
	void rev(Node<T>*);
	void comp(const iterator, const iterator, bool & c) const;
	void size(const Node<T> *, int &) const;
};

template<class T>
int MyList2<T>::size() const {
	int cont = 0;

	size(dataLast, cont);

	return cont;
}

template<class T>
void MyList2<T>::size(const Node<T> *n, int &cont) const {
	if (!n) return;

	cont++;
	size(n->prev, cont);
}

template<class T>
void MyList2<T>::comp(const iterator it1, const iterator it2, bool & c) const {
	if (it2->prev) {
		if (it2->prev == it1) {
			c = true;
			return;
		}
		comp(it1, it2->prev, c);
	}
}

template<class T>
bool MyList2<T>::compare(const iterator it1, const iterator it2) const {
	bool c = false;
	comp(it1, it2, c);
	return c;
}

template<class T>
int MyList2<T>::eraseMatchingElements(const T & elem) {
	Node<T> * n = dataFirst;
	int cont = 0;
	while (n) {
		if (n->data == elem) {
			cont++;
			Node<T> *v = n->next;
			erase(n);
			n = v;
			continue;
			/*
			if (n == dataFirst) {
				dataFirst = n->next;
				dataFirst->prev = NULL;
				dataSize--;
				delete n;
				n = dataFirst;
			} else if (n == dataLast) {
				dataLast = n->prev;
				dataLast->next = NULL;
				dataSize--;
				delete n;
			} else {
				n->prev->next = n->next;
				n->next->prev = n->prev;
				dataSize--;
				Node<T> *v = n->next;
				delete n;
				n = v;
			}
			*/
		}
		n = n->next;
	}
	return cont;
}

template<class T>
void MyList2<T>::rev(Node<T>* n) {
	if (n->next) {
		rev(n->next);
	}
	swap(n->prev, n->next); 
}

template<class T>
void MyList2<T>::reverse() {
	if (size() <= 1) return;
	rev(dataFirst);
	Node<T>* n = dataFirst;
	dataFirst = dataLast;
	dataLast = n;
}

//funcao auxiliar (nao membro)
//Dado um apontador first para o primeiro nodo de uma lista encadeada, deleta todos os nodos apos 
//first (incluindo first)
template<class T>
void MyList2<T>::destroy(MyList2<T>::iterator first) {
	if(first==NULL) return;
	destroy(first->next);
	delete first;
}

template<class T>
void MyList2<T>::destroy() { // Lab...
	dataSize = 0;
	destroy(dataFirst);
}

template<class T>
void MyList2<T>::create() {
	dataFirst = dataLast  = NULL;
	dataSize = 0;
}

template<class T>
MyList2<T>::MyList2() {
	create();
}

template<class T>
MyList2<T>::MyList2(int n, const T&init) {
	create();
	for(int i=0;i<n;i++) push_back(init); //implementacao pode ser mais eficiente se evitar atualizar o apontador "dataLast" em cada iteracao
}


//Construtor de copia
template<class T>
MyList2<T>::MyList2(const MyList2 &other) {
	create(); //Crie um vetor vazio
	*this = other; 
}

template<class T>
MyList2<T> & MyList2<T>::operator=(const MyList2 &other) {
	if(this==&other) return *this; 
	clear(); //Exercicio: por que precisamos disso?

	if(other.dataFirst == NULL) {
		dataFirst = dataLast = NULL;
	} else {
		Node<T> *curr = other.dataFirst;
		while(curr!=NULL) { //equivalente a "while(curr)"
			push_back(curr->data);
			curr = curr->next; //avance para o proximo nodo
		}
	}
	return *this;
}


//---------------------------------------------------------------------------------------
//Funcoes de acesso

template<class T>
void MyList2<T>::push_back(const T&elem) {
	if(dataFirst==NULL) { //caso especial: lista inicialmente vazia
		dataFirst = dataLast = new Node<T>(elem);
	} else {
		dataLast->next = new Node<T>(elem);
		dataLast->next->prev = dataLast;
		dataLast = dataLast->next;
	}
	dataSize++;
}

template<class T>
void MyList2<T>::push_front(const T&elem) {
	if (!dataFirst) {
		push_back(elem);
		return;
	}
	Node<T> * n = new Node<T>(elem);
	n->next = dataFirst;
	dataFirst->prev = n;
	dataFirst = n;
	dataSize++;
}


//insere o elemento na posicao NA posicao nodeBefore
//diferentemente da lista simplesmente encadeada, isso pode ser feito de forma 
//eficiente na lista duplamente encadeada
template<class T>
void MyList2<T>::insert(const T&elem, iterator where) {
	if (!dataFirst || !where) {
		push_back(elem);
		return;
	} else if (where == dataFirst) {
		push_front(elem);
		return;
	}

	Node<T> * n = new Node<T>(elem);
	n->prev = where->prev;
	n->next = where;
	where->prev->next = n;
	where->prev = n;
	dataSize++;
}



template<class T>
void MyList2<T>::clear() {
	destroy();
	create();
}

//assumimos que elem seja um ponteiro valido para um nodo da lista
template<class T>
typename MyList2<T>::iterator MyList2<T>::erase(iterator elem) { //remove o elemento apontado por Elem
													       //retorna o (apontador) para o elemento apos o removido
	
	dataSize--;
	if(elem==dataFirst && elem==dataLast) { //exercicio: por que precisamos desse caso especial?
		//so ha um elemento na lista
		delete elem;
		dataFirst = dataLast = NULL;		
		return NULL;
	} else if(elem==dataFirst) {		
		dataFirst = dataFirst->next;
		dataFirst->prev = NULL;
		delete elem;
		return dataFirst;
	} else {
		//o elemento a ser removido nao e' o primeiro.
		Node<T> *beforeElem = elem->prev;

		beforeElem->next = elem->next;
		if(elem==dataLast) { //caso especial... eh o ultimo elemento
			dataLast = beforeElem;
		} else
			elem->next->prev = beforeElem;

		delete elem;

		return beforeElem->next;
	}
}

template<class T>
typename MyList2<T>::iterator MyList2<T>::next(iterator curr) {
	return curr->next;
}

template<class T>
typename MyList2<T>::iterator MyList2<T>::prev(iterator curr) {
	return curr->prev;
}

template<class T>
T& MyList2<T>::deref(iterator curr) { //Retorna o elemento da lista apontado por curr (faz uma "derreferencia")
	return curr->data;
}

template<class T>
const typename MyList2<T>::iterator MyList2<T>::next(const iterator curr) const {
	return curr->next;
}

template<class T>
const typename MyList2<T>::iterator MyList2<T>::prev(const iterator curr) const {
	return curr->prev;
}

template<class T>
const T& MyList2<T>::deref(const iterator curr) const { //Retorna o elemento da lista apontado por curr (faz uma "derreferencia")
	return curr->data;
}


template<class T2>
std::ostream& operator<<(std::ostream &out, const MyList2<T2> &v) {
	out << "Size: " << v.size() << "\n";
	/* //usando iteradores para abstrairem a iteracao
	MyList2<T2>::iterator it = v.begin();
	while(it!=v.end()) {
		 out << v.deref(it) << " ";
		 it = v.next(it);
	}
	*/
	Node<T2> *curr = v.dataFirst;
	while(curr!=NULL) { // equivalente a while(curr)
		 out << curr->data << " ";
		 curr = curr->next;
	}

	out << "\n";

	out << "Ordem reversa (testando ponteiros prev...)" << "\n";
	curr = v.dataLast;
	while(curr!=NULL) { // equivalente a while(curr)
		 out << curr->data << " ";
		 curr = curr->prev;
	}

	out << "\n";

	return out;
}


#endif