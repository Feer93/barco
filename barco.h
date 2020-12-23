//
// Created by ferna on 23/12/2020.
//

#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

const int NORTE = 1, SUR = 3, ESTE = 0, OESTE = 2;


class Direccion{

private:
    int CurrentDir;
public:
    Direccion(int Dir){
        this->CurrentDir = Dir;
    }

    int getCurrentDir(){
        return this->CurrentDir;
    }
    //Izquierda : false , Derecha : True
    void rotate(int nRotation,bool sentido){
        CurrentDir= (sentido) ? (((CurrentDir - nRotation) % 4+4)%4) : ((CurrentDir + nRotation) % 4);

    }

};


class Barco{

private:
    int x,y;
    Direccion d;
public:

    Barco(Direccion d) : d(d) {
        this->x = 0, this->y = 0;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void resolverProblema(string v, int valor){

        //Caso de ir hacia al norte
            if (v == "N"){
                y+=valor;
            }//Caso de ir al sur
            else if (v == "S"){
                y-=valor;
            }//Caso de ir hacia el este
            else if (v == "E"){
                x+=valor;
            }//Caso de ir hacia el oeste
            else if (v == "W"){
                x-=valor;
            }else if(v == "F"){
                int direccion = d.getCurrentDir();
                switch (direccion) {
                    case NORTE:
                        y+=valor;
                        break;
                    case SUR:
                        y-=valor;
                        break;
                    case ESTE:
                        x+=valor;
                        break;
                    case OESTE:
                        x-=valor;
                        break;
                }

            }//Rotamos hacia la izquierda
            else if(v == "L"){
                int valorR =  (valor > 360) ? (valor% 360)/90 : valor/90;
                d.rotate(valorR, false) ;
            }//Rotamos hacia la derecha
            else if (v == "R"){
                int valorR =  (valor > 360) ? (valor% 360)/90 : valor/90;
                d.rotate(valorR, true);
            }

    }



};
