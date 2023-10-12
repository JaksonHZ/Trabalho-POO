#ifndef CADASTRO_H
#define CADASTRO_H

#include "Dispositivo.h"
#include <vector>
using namespace std;

class Cadastro {
public:
    Cadastro(string fileName);
    virtual ~Cadastro();
    bool adiciona(int tipo);
    void imprime();
    void imprime(int CPF);
    void imprimePorTipo(int tipo);
    bool remove(int CPF);
    bool atualiza(int CPF);
    static char opcao();
private:
    void grava();
    void recupera();
    int indice(int CPF);

    string fileName;
    vector<Dispositivo *> dispositivos;
};

#endif /* CADASTRO_H */