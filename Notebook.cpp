#include "Notebook.h"

Notebook::Notebook(string processador, string marca, string SO, string nome, int armazenamento, int numeroSerie, string placaDeVideo, string teclado) :
Dispositivo(processador, marca, SO, nome, armazenamento, numeroSerie), placaDeVideo(placaDeVideo), teclado(teclado){}

string Notebook::getPlacaDeVideo() const{
    return placaDeVideo;
}

string Notebook::getTeclado() const{
    return teclado;
}

void Notebook::setPlacaDeVideo(string placaDeVideo_){
    placaDeVideo = placaDeVideo_;
}

void Notebook::setTeclado(string teclado_){
    teclado = teclado_;
}
int Notebook::getTipo() const{
    return 2;
}

void Notebook::imprime() const{
    Dispositivo::imprime();
    cout << "Placa de Video: " << placaDeVideo << endl;
    cout << "Teclado: " << teclado << endl;
    cout << "-------------------------" << endl;
}
