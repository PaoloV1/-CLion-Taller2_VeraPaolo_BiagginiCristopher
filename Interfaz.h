#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Sistema.h"
#include <iostream>
using namespace std;


class Interfaz {
private:
    Sistema sistema;
    public:
    Interfaz();
    void iniciarConcierto();
};



#endif //INTERFAZ_H
