#include "Celular.h"

Celular::Celular(string processador, string marca, string SO, string nome, int armazenamento, int numeroSerie, string chip, string camera, bool flash) :
Dispositivo(processador, marca, SO, nome, armazenamento, numeroSerie), chip(chip), camera(camera), flash(flash){}

string Celular::getChip() const{
    return chip;
}

string Celular::getCamera() const{
    return camera;
}

bool Celular::getFlash() const{
    return flash;
}

void Celular::setChip(string chip_){
    chip = chip_;
}

void Celular::setCamera(string camera_){
    camera = camera_;
}

void Celular::setFlash(bool flash_){
    flash = flash_;
}

int Celular::getTipo() const{
    return 1;
}

void Celular::imprime() const{
    Dispositivo::imprime();
    cout << "Chip: " << chip << endl;
    cout << "Camera: " << camera << endl;
    cout << "Flash: " << (flash ? "Possui" : "Não Possui") << endl;
    cout << "-------------------------" << endl;
}

