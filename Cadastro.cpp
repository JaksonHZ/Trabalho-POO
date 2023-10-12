#include "Cadastro.h"
#include "Celular.h"
#include "Notebook.h"
#include <algorithm>
#include <fstream>
using namespace std;

Cadastro::Cadastro(string fileName) : fileName(fileName) {
    recupera();
}

Cadastro::~Cadastro() {}

void Cadastro::grava() {

    int tipo, tam, armazenamento, numeroSerie;
    string nome,processador, marca, SO, chip, camera, placaDeVideo, teclado;
    bool flash;
    Celular *c1;
    Notebook *n1;

    ofstream saida(fileName, ios::binary);

    for (long unsigned int i = 0; i < dispositivos.size(); i++)  {

        // Escrevendo o tipo do dispositivo (Celular ou Notebook)

        tipo = dispositivos[i]->getTipo();
        saida.write(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        // Escrevendo o nome

        nome = dispositivos[i]->getNome();
        tam = nome.size();

        // Escrevendo o tamanho da string (nome)
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));

        // Escrevendo os caracteres da string (nome)
        saida.write(reinterpret_cast<char *>(&nome[0]), tam);

        // Escrevendo o processador
        processador = dispositivos[i]->getProcessador();
        tam = processador.size();
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&processador[0]), tam);

        // Escrevendo a marca
        marca = dispositivos[i]->getMarca();
        tam = marca.size();
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&marca[0]), tam);

        // Escrevendo o SO
        SO = dispositivos[i]->getSO();
        tam = SO.size();
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&SO[0]), tam);

        // Escrevendo o Armazenamento
        armazenamento = dispositivos[i]->getArmazenamento();
        saida.write(reinterpret_cast<char *>(&armazenamento), sizeof(armazenamento));

        // Escrevendo o Armazenamento
        numeroSerie = dispositivos[i]->getNumeroSerie();
        saida.write(reinterpret_cast<char *>(&numeroSerie), sizeof(numeroSerie));

        // Escreve as caracteristicas especificas do Dispositivo

        switch (tipo) {
            case 1: {
                // Escrevendo os atributos do Celular

                // Escrevendo o Chip
                c1 = dynamic_cast<Celular *>(dispositivos[i]);
                chip = c1->getChip();
                tam = chip.size();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&chip[0]), tam);

                // Escrevendo a camera

                camera = c1->getCamera();
                tam = camera.size();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&camera[0]), tam);

                // Escrevendo o Flash

                flash = c1->getFlash();
                saida.write(reinterpret_cast<char *>(&flash), sizeof(flash));


                break;
            }
            case 2: {

                n1 = dynamic_cast<Notebook *>(dispositivos[i]);

                placaDeVideo = n1->getPlacaDeVideo();
                tam = placaDeVideo.size();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&placaDeVideo[0]), tam);

                teclado = n1->getTeclado();
                tam = teclado.size();
                saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                saida.write(reinterpret_cast<char *>(&teclado[0]), tam);

             break;
            }
        }
    }

    saida.close();
}

void Cadastro::recupera() {

    int tipo, tam, armazenamento, numeroSerie;
    string nome,processador, marca, SO, chip, camera, placaDeVideo, teclado;
    bool flash;

    ifstream entrada(fileName, ios::binary);
    
    if (entrada.is_open()) {

        dispositivos.clear();

        // Lendo o tipo

        entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        while (entrada.good()) {

            // Lendo o nome
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            nome.resize(tam);
            entrada.read(reinterpret_cast<char *>(&nome[0]), tam);

            // Lendo o processador
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            processador.resize(tam);
            entrada.read(reinterpret_cast<char *>(&processador[0]), tam);

            // Lendo a marca
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            marca.resize(tam);
            entrada.read(reinterpret_cast<char *>(&marca[0]), tam);

            // Lendo o SO
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            SO.resize(tam);
            entrada.read(reinterpret_cast<char *>(&SO[0]), tam);

            // Lendo o Armazenamento
            entrada.read(reinterpret_cast<char *>(&armazenamento), sizeof(armazenamento));

            // Lendo a o numero de serie
            entrada.read(reinterpret_cast<char *>(&numeroSerie), sizeof(numeroSerie));

            // Lendo as caracteristicas especificas do Dispositivo
            // (atributos da classe Celular ou Notebook)

            switch (tipo) {
                case 1: {

                    // Lendo o Chip
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    chip.resize(tam);
                    entrada.read(reinterpret_cast<char *>(&chip[0]), tam);

                    // Lendo a camera
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    camera.resize(tam);
                    entrada.read(reinterpret_cast<char *>(&camera[0]), tam);

                    // Lendo Flash
                    entrada.read(reinterpret_cast<char *>(&flash), sizeof(flash));

                    dispositivos.push_back(new Celular(processador, marca, SO, nome, armazenamento, numeroSerie, chip, camera, flash));
                    break;
                }
                case 2: {

                    // Lendo a Placa de Video
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    placaDeVideo.resize(tam);
                    entrada.read(reinterpret_cast<char *>(&placaDeVideo[0]), tam);

                    // Lendo o Teclado
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    teclado.resize(tam);
                    entrada.read(reinterpret_cast<char *>(&teclado[0]), tam);

                    dispositivos.push_back(new Notebook(processador, marca, SO, nome, armazenamento, numeroSerie, placaDeVideo, teclado));
                    break;
                }
            }

            // Lendo o tipo

            entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
        }
    }
    entrada.close();
}

bool Cadastro::adiciona(int tipo) {
    int tam, armazenamento, numeroSerie;
    string nome,processador, marca, SO, chip, camera, placaDeVideo, teclado;
    bool flash;

    Dispositivo *d;

    cin.ignore();
    cout << "Nome: ";
    getline(cin, nome);
    //cin.ignore();
    cout << "Processador: ";
    getline(cin,processador);
    cout << "Marca: ";
    cin >> marca;
    cout << "SO: ";
    cin >> SO;
    cout << "Armazenamento(GB): ";
    cin >> armazenamento;
    cout << "Numero de Serie: ";
    cin >> numeroSerie;

    switch(tipo) {
        case 1: {
            cin.ignore();
            cout << "CHIP: ";
            getline(cin,chip);
            //cin.ignore();
            cout << "Camera: ";
            getline(cin,camera);
            cout << "Flash(1 para possui, 0 para não possui): ";
            cin >> flash;
            d = new Celular(processador, marca, SO, nome, armazenamento, numeroSerie, chip, camera, flash);
            break;
        }
        case 2: {
            cin.ignore();
            cout << "Placa De Video: ";
            getline(cin, placaDeVideo);
            //cin.ignore();
            cout << "Teclado: ";
            getline(cin, placaDeVideo);;
            d = new Notebook(processador, marca, SO, nome, armazenamento, numeroSerie, placaDeVideo, teclado);
            break;
        }
    }

    dispositivos.push_back(d);
    grava();
    return true;
}

bool Cadastro::atualiza(int numeroSerie) {
    string processador;
    bool ok = false;
    int pos = indice(numeroSerie);

    if (pos != -1) {
        
        cout << "Processador: ";
        cin >> processador;
        dispositivos[pos]->setProcessador(processador);
        grava();
        ok = true;
    }

    return ok;
}

bool Cadastro::remove(int numeroSerie) {
    bool ok = false;
    int pos = indice(numeroSerie);

    if (pos != -1) {
        dispositivos.erase(dispositivos.begin() + pos);
        grava();
        ok = true;
    }

    return ok;
}

int Cadastro::indice(int numeroSerie) {
    long unsigned int tam = dispositivos.size();
    long unsigned int pos = 0;

    while (pos < tam && dispositivos[pos]->getNumeroSerie() != numeroSerie) {
        pos++;
    }

    if (pos < tam) {
        return pos;
    } else {
        return -1;
    }
}

void Cadastro::imprime(int numeroSerie) {
    int pos = indice(numeroSerie);

    if (pos != -1) {
        dispositivos[pos]->imprime();
    } else {
        cout << "Numero de Serie não encontrado";
    }
}

void Cadastro::imprimePorTipo(int tipo) {
    vector<Dispositivo*> copia = dispositivos;

    for (long unsigned int i = 0; i < copia.size(); i++) {
        if (copia[i]->getTipo() == tipo){
            copia[i]->imprime();
        }
    }
}

void Cadastro::imprime() {
    vector<Dispositivo*> copia = dispositivos;

    for (long unsigned int i = 0; i < copia.size(); i++) {
        copia[i]->imprime();
        cout << endl;
    }
}

char Cadastro::opcao() {
    char c;
    cout << "[I] Imprime todos" << endl;
    cout << "[C] Imprime por Número de Série" << endl;
    cout << "[O] Imprime Notebooks" << endl;
    cout << "[K] Imprime Celulares" << endl;
    cout << "[E] Adiciona Celular" << endl;
    cout << "[M] Adiciona Notebook" << endl;
    cout << "[S] Atualiza processador (por Número de Série)" << endl;
    cout << "[R] Remove (por Número de Série)" << endl;
    cout << "[F] Fim" << endl;
    cout << "> ";
    cin >> c;
    return (toupper(c));
}