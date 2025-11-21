//
// Created by Paolo on 21-11-2025.
//

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
    int merch = 100;

public:
    Sistema();

    void cargarAsistentes(string nombreArchivo);
    void inicializarAsientos(int cantidad);

    void procesarIngreso();
    bool validarEntrada(Asistente* a);

    void mostrarAsientos();
    void mostrarResumen();

    void determinarMerch();

    void merchandising();
};



#endif //SISTEMA_H
