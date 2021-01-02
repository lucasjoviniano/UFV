#include "Agenda.h"
#include "Horario.h"
#include "Data.h"
#include <string>
#include <iostream>

using namespace std;

ItemAgenda::ItemAgenda() {
    setDesc("");
    setData(Data());
    setHorario(Horario());
}

ItemAgenda::ItemAgenda(const string & desc, const Data & dt, const Horario & hms) {
    setDesc(desc);
    setData(dt);
    setHorario(hms);
}

ItemAgenda::ItemAgenda(const ItemAgenda &obj) {
    *this = obj;
}

void ItemAgenda::setDesc(const string & desc) {
    this->descricao = desc;
}

void ItemAgenda::setData(const Data & data) {
    this->d = data;
}

void ItemAgenda::setHorario(const Horario &hms) {
    this->h = hms;
}

const string & ItemAgenda::getDesc() const {
    return this->descricao;
}

const Data & ItemAgenda::getData() const {
    return this->d;
}

const Horario & ItemAgenda::getHorario() const {
    return this->h;
}

void Agenda::inserirItem(const ItemAgenda & it) {
    this->eventos[cont] = it;
    cont++;
}

void Agenda::compromissosData(const Data & dt) const {
    for (int i = 0;  i < cont; i++) {
        if (this->eventos[i].getData().compData(dt) == 0) {
            cout << eventos[i].getHorario() << ' ' << eventos[i].getDesc() << endl;
        } 
    }
}