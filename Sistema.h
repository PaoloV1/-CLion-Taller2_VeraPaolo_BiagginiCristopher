#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>

#include "Asistente.h"
#include "ABB.h"
#include "ArbolEnhebrado.h"
#include "Cola.h"


class Sistema {
private:
    Cola<Asistente*> colaIngreso;
    ABB abbTickets;
    ArbolEnhebrado arbolAsientos;
    vector<Asistente*> ingresados;
    vector<Asistente*> rechazados;
    Cola<Asistente*> colaMerch;
    int comprasInPuerta = 0;
    int sinComprar = 0;
    int merch = 500;

public:
    Sistema();

    void cargarAsistentes(string nombreArchivo);
    void inicializarAsientos(int cantidad);

    void procesarIngreso();

    void mostrarAsientos();
    void mostrarResumen();

    void determinarMerch();

    void merchandising();
};



#endif //SISTEMA_H
