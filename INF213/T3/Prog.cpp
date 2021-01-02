#include "Predictor.h"
using namespace std;

int main(int argc, char** argv) {
   Predictor * p;
    if (argc > 1) {
        p = new Predictor(argv[1]);
    } else {
        p = new Predictor();
    }

    MyVec<string> args;
    string s, w;
    int k;

    while (cin.good()) {
        getline(cin, s);
        args.push_back(s);
    }
    
    for (int i = 0; i < args.size(); i++) {
        stringstream ss(args[i]);
        ss >> s >> k;
        getline(ss, w);
        if (s == "consultar") {
            p->consultar(k, w);
        } else {
            p->gerar(k, w);
        }
        cout << endl;
    }

    delete p;
}