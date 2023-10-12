#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <iostream>
#include <string>

using namespace std;

class Dispositivo {
private:
    string nome;
    string processador;
    string marca;
    string SO;
    int armazenamento;
    int numeroSerie;
public:
    Dispositivo(string, string, string,string, int, int);
    ~Dispositivo();
    string getNome() const;
    string getProcessador() const;
    string getMarca() const;
    string getSO() const;
    int getArmazenamento() const;
    int getNumeroSerie() const;
    void setNome(string);
    void setProcessador(string);
    void setMarca(string);
    void setSO(string);
    void setArmazenamento(int);
    void setNumeroSerie(int);
    virtual int getTipo() const = 0;
    virtual void imprime() const;
    //static bool comparaNome(Dispositivo* a1, Dispositivo* a2);
};

#endif