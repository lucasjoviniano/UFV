#ifndef PREDICTOR_H
#define PREDICTOR_H
#include "MyMap.h"
#include "MyVecNewIterator.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <time.h>

using namespace std;

class Predictor {
    public:
        Predictor(string = "");
        void consultar(const int, const string &);
        void gerar(int, const string &);
    private:
        void generate(int, MyVec<string> & , bool = false);
        void processText(istream & = cin);
        void createMaps();

        MyVec<string> sentences;
        MyMap<string, int> m1;
        MyMap<string, MyMap<string, int>> m2;
        MyMap<string, MyMap<string, MyMap<string, int>>> m3;
};

// Recebe uma string que é o nome do arquivo. Se nada for passado lê do cin
Predictor::Predictor(string s) {
    srand(time(NULL));
    if (s.empty()) {
        processText();
    } else {
        ifstream file(s);
        processText(file);
        file.close();
    }
    createMaps();
}

// -------- Pré - Processamento -------- //

// Converte uma string para caracteres minúsculos
void toLower(string & s) {
    string::iterator i = s.begin();
    while (i != s.end()) {
        *i = tolower(*i);
        i++;
    }
}

// Confere se o caractere é um espaço em branco
bool isWhiteSpace(const char c) {
    string s = "\'\n\" ";
    return (s.find(c) != string::npos);
}

// Confere se o caractere é um delimitador de sentença
bool isDelimiter(const char c) {
    if (isalpha(c) || c == '-') return false;
    if (isWhiteSpace(c)) return false;
    return true; 
}

void Predictor::processText(istream & file) {
    string s;
    string aux;

    // Se for do cin, ignora a linha COMECO_TREINO
    if (&file == &cin) {
        getline(file, aux);
    }

    while (file.good()) {
        getline(file, aux);
        if (aux == "FINAL_TREINO") break;
        toLower(aux);
        s.append(aux);
        s.append(" ");
    }

    for (int i = 0; i < s.size(); i++) {
        if (isWhiteSpace(s[i])) {
            // Transforma os caracteres equivalentes a espaço em branco no mesmo
            s[i] = ' ';
        } else if (isDelimiter(s[i])) {
            // Transforma os caracteres delimitadores em quebras de linha
            s[i] = '\n';
        }
    }

    stringstream ss(s);

    // Separa as sentenças
    while (ss.good()) {
        getline(ss, aux);
        if (!aux.empty()) sentences.push_back(aux);
    }
}

void Predictor::createMaps() {

     // Strings auxiliares
     string w1, w2, w3;

     for (int i = 0; i < sentences.size(); i++) {
         stringstream ss(sentences[i]);
         // Enquanto houver palavras na stream
         while (ss >> w1) {
             m1[w1]++;
             if (!w2.empty()) m2[w2][w1]++;
             if (!w3.empty()) m3[w3][w2][w1]++;

             // Troca os conteúdos das strings, de modo que o último seja substituído na próxima leitura
             swap(w2, w3);
             swap(w1, w2);
         }
         // Limpa as strings auxiliares para a próxima sentença
         w1.clear();
         w2.clear();
         w3.clear();
     }
}

// -------- Pesquisar e Gerar -------- //

bool compare(const pair<string, int> & p1, const pair<string, int> & p2) {
    // Se a frequencia for igual compara lexicograficamente
    if (p1.second == p2.second) {
        return (p1.first <= p2.first);
    }
    return (p1.second > p2.second);
}

MyVec<pair<string, int>> sortPairs(MyMapIterator<std::string, int> it) {
    MyVec<pair<string, int>> v;

    while (it != NULL) {
        v.push_back(*it);
        it++;
    }

    sort(v.begin(), v.end(), compare);

    return v;
}

void getPairs(const int k, const MyVec<string> & v, MyMap<string, int> & m) {
    MyVec<pair<string, int>> pairs;

    pairs = sortPairs(m.begin());

    for (int i = 0; i < min(k, m.size()); i++) {
        for (int j = 0; j < v.size(); j++) cout << v[j] << " ";
        cout << pairs[i].first << " (" << pairs[i].second << ")\n";
    }
}

void Predictor::consultar(const int k, const string & p) {
    stringstream ss(p);
    MyVec<string> v;

    string s;

    while (ss >> s) v.push_back(s);

    if (v.size() == 1) {
        cout << v[0] << " (" << m1[v[0]] << ")\n";
        getPairs(k, v, m2[v[0]]);
    } else if (v.size() == 2) {
        cout << v[0] << " " << v[1] << " (" << m2[v[0]][v[1]] << ")\n";
        getPairs(k, v, m3[v[0]][v[1]]);
    } else {
        cout << v[0] << " " << v[1] << " " << v[2] << " (" << m3[v[0]][v[1]][v[2]] << ")\n";
    }
}

MyVec<double> calcCDFs(const MyVec<pair<string, int>> & pairs) {
    MyVec<double> v;

    double aux = 0;
    int sum = 0;

    // Calcula a soma das frequências
    for (int i = 0; i < pairs.size(); i++) sum += pairs[i].second;

    for (int i = 0; i < pairs.size(); i++) {
        // Calcula a Função de Distribuição Acumulada, normalizando os valores
        aux += (double)pairs[i].second / (double)sum;
        v.push_back(aux);
    }

    return v;
}

string getRand(const MyVec<pair<string, int>> & pairs) {
    MyVec<double> v = calcCDFs(pairs);

    // Gera um número aleatório entre 0 e 1
    double num = (double)rand() / RAND_MAX;

    // Seleciona a primeira palavra que foi >= que o número sorteado
    // Como prioriza os valores maiores, os que tiverem maior frequência têm mais chances
    for (int i = 0; i < pairs.size(); i++) {
        if (v[i] >= num) return pairs[i].first;
    }

    return pairs[0].first;
}

void Predictor::generate(int k, MyVec<string> & v, bool isRand) {
    MyVec<pair<string, int>> pairs;

    for (; k > 0; k--) {
            if (v.size() >= 2 && m3.count(v[v.size() - 2]) && m3[v[v.size() - 2]].count(v[v.size() - 1])) {
                pairs = sortPairs(m3[v[v.size() - 2]][v[v.size() - 1]].begin());
            } else if (v.size() >= 1 && m2.count(v[v.size() - 1])) {
                pairs = sortPairs(m2[v[v.size() - 1]].begin());
            } else {
                pairs = sortPairs(m1.begin());
            }

            if (isRand) v.push_back(getRand(pairs));
            else v.push_back(pairs[0].first);
        }

        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

        cout << endl;
}

void Predictor::gerar(int k, const string & p) {

    stringstream ss(p);
    string modo;
    ss >> modo;

    MyVec<string> v;
    string s;

    while (ss >> s) v.push_back(s);

    if (modo == "padrao") {
        generate(k, v);
    } else {
        generate(k, v, true);
    }
}

#endif