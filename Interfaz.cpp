//
// Created by Paolo on 21-11-2025.
//

#include "Interfaz.h"
#include <cstdlib>
#include <ctime>

/**
 * Metodo constructor clase Interfaz
 */
Interfaz::Interfaz() {
    srand(time(nullptr));

    iniciarConcierto();
}

/**
 * Metodo para inicar el concierto
 */
void Interfaz::iniciarConcierto() {
    cout << "Bienvenido al Movistar Arena"<<endl;
    cout << "El concierto de ADO esta por empezar"<<endl;

    sistema.cargarAsistentes("asistentes.txt");

    sistema.inicializarAsientos(2000);

    sistema.procesarIngreso();

    sistema.determinarMerch();

    sistema.merchandising();
    sistema.mostrarResumen();

}
