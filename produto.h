#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
using namespace std;

class Produto {
public:
    int id;
    string tipo;
    int quantidade;
    double valor;

    Produto(int id, string tipo, int quantidade, double valor)
        : id(id), tipo(tipo), quantidade(quantidade), valor(valor) {}

    string toString() const {
        return to_string(id) + "," + tipo + "," + to_string(quantidade) + "," + to_string(valor);
    }
};

#endif // PRODUTO_H
