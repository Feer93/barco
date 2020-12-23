#include <iostream>
#include <fstream>
#include <stdlib.h>     /* atoi */
#include <sstream>
#include "barco.h"

using namespace std;

int main() {

    ifstream  f("fichero.txt");
    string movimiento;
    Direccion d(ESTE);
    Barco boat(d);
    int valor;

    while (getline(f,movimiento)) {
        string value = movimiento.substr(1,movimiento.size());
        stringstream sst(value);
        sst >> valor;
        boat.resolverProblema(movimiento.substr(0,1), valor);
    }

    cout <<  "Coordenada x: " << boat.getX() << endl;
    cout <<  "Coordenada y: " << boat.getY() << endl;
    int DistanciaManhattan = abs(boat.getX()) + abs(boat.getY());
    cout <<  "Distancia de Manhattan: " << DistanciaManhattan << endl;
    return 0;
}
