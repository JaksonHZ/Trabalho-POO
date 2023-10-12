#include "Dispositivo.h"

Dispositivo::Dispositivo(string processador, string marca, string SO, string nome, int armazenamento, int numeroSerie) :
                        processador(processador), marca(marca), SO(SO), nome(nome), armazenamento(armazenamento), numeroSerie(numeroSerie){
}

Dispositivo::~Dispositivo(){}

string Dispositivo::getProcessador() const{
    return processador;
}

string Dispositivo::getMarca() const{
    return marca;
}

string Dispositivo::getSO() const{
    return SO;
}

string Dispositivo::getNome() const{
    return nome;
}

int Dispositivo::getArmazenamento() const{
    return armazenamento;
}

int Dispositivo::getNumeroSerie() const{
    return numeroSerie;
}

void Dispositivo::setProcessador(string processador_){
    processador = processador_;
}

void Dispositivo::setMarca(string marca_){
    marca = marca_;
}

void Dispositivo::setSO(string SO_){
    SO = SO_;
}

void Dispositivo::setNome(string nome_){
    nome = nome_;
}

void Dispositivo::setArmazenamento(int armazenamento_){
    armazenamento = armazenamento_;
}

void Dispositivo::setNumeroSerie(int numeroSerie_){
    numeroSerie = numeroSerie_;
}

void Dispositivo::imprime() const{
    string aparelho;

    switch (getTipo()) {
        case 1: {
            aparelho = "Celular";
            break;
        }
        case 2: {
            aparelho = "Notebook";
            break;
        }
    }
    cout << "Dispostivo: " << aparelho << endl;
    cout << "Processador: " << processador << endl;
    cout << "Marca: " << marca << endl;
    cout << "SO: " << SO << endl;
    cout << "Armazenamento(GB): " << armazenamento << endl;
    cout << "Número de Série: " << numeroSerie << endl;
}

