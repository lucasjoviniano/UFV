#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include "Data.h"
#include "Horario.h"
using namespace std;

class ItemAgenda {
    private:
      string descricao;
      Data d;
      Horario h;
    public:
        ItemAgenda();
        ItemAgenda(const string &, const Data &, const Horario &);
        ItemAgenda(const ItemAgenda &);
        void setDesc(const string &);
        void setData(const Data &);
        void setHorario(const Horario &);
        const string & getDesc() const;
        const Data & getData() const;
        const Horario & getHorario() const;
};

class Agenda {
  private:
    ItemAgenda eventos[1000];
    int cont = 0;
  public:
    void inserirItem(const ItemAgenda &);
    void compromissosData(const Data &) const;
};

#endif