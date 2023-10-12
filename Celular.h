#ifndef CELULAR_H
#define CELULAR_H

#include "Dispositivo.h"

class Celular : public Dispositivo
{
private:
    string chip;
    string camera;
    bool flash;
public:
    Celular(string, string, string,string, int, int, string, string, bool);
    string getChip() const;
    string getCamera() const;
    bool getFlash() const;
    void setChip(string);
    void setCamera(string);
    void setFlash(bool);
    virtual int getTipo() const;
    virtual void imprime() const;
};

#endif