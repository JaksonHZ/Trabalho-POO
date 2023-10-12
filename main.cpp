#include "Cadastro.h"
#include "Celular.h"
#include "Notebook.h"
using namespace std;

int main() {

    char op;
    int numerodeSerie;
    
    Cadastro cadastro("info.dat");
    
    do {
        op = Cadastro::opcao();
        switch (op) {
            case 'I': { 
                cadastro.imprime();
                break;
            }
            case 'C': {
                cout << "Numero de Serie: ";
                cin >> numerodeSerie;
                cadastro.imprime(numerodeSerie);
                break;
            }
            case 'O': {
                cadastro.imprimePorTipo(2);
                break;
            }
            case 'K': {
                cadastro.imprimePorTipo(1);
                break;
            }
            case 'E': {
                cadastro.adiciona(1);
                break;
            }
            case 'M': {
                cadastro.adiciona(2);
                break;
            }
            case 'S': {
                cout << "Numero de Serie: ";
                cin >> numerodeSerie;
                bool ok = cadastro.atualiza(numerodeSerie);
                cout << "Atualização " << (ok ? "ok" : "não ok") << endl;
                break;
            }
            case 'R': {
                cout << "Numero de Serie: ";
                cin >> numerodeSerie;
                bool ok = cadastro.remove(numerodeSerie);
                cout << "Remoção " << (ok ? "ok" : "não ok") << endl;
                break;
            }
        }
        cout << endl;
    } while (op != 'F');

    return 0;
}