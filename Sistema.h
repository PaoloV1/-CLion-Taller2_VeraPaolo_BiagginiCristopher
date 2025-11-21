//
// Created by Paolo on 21-11-2025.
//

#ifndef SISTEMA_H
#define SISTEMA_H
#include "Asistente.h"
#include "ABB.h"
#include "ArbolEnhebrado.h"
#include <queue>


class Sistema {
private:
    queue<Asistente*> colaIngreso;
    ABB abbTickets;
    ArbolEnhebrado arbolAsientos;

public:
    Sistema();

    void cargarAsistentes(string nombreArchivo);
    void inicializarAsientos(int cantidad);

    void procesarIngreso();
    void validarEntrada(Asistente* a);

    void mostrarAsientos();

};



#endif //SISTEMA_H
