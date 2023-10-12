#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "Dispositivo.h"

class Notebook : public Dispositivo
{
private:
    string placaDeVideo;
    string teclado;
public:
    Notebook(string, string, string,string, int, int, string, string);
    string getPlacaDeVideo() const;
    string getTeclado() const;
    void setPlacaDeVideo(string);
    void setTeclado(string);
    virtual int getTipo() const;
    virtual void imprime() const;
};

#endif