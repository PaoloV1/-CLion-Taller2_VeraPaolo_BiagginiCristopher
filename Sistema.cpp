//
// Created by Paolo on 21-11-2025.
//

#include "Sistema.h"

#include <fstream>
#include <sstream>

Sistema::Sistema() {

}

void Sistema::cargarAsistentes(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return;

    string linea;

    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string sId, nombre, sEntrada, sAsiento, sVip;

        getline(ss, sId,',');
        getline(ss, nombre, ',');
        getline(ss,sEntrada, ',');
        getline(ss, sAsiento, ',');
        getline(ss, sVip);

        int id = stoi(sId);
        int asiento = stoi(sAsiento);
        bool vip = (sVip == "si");
        bool tieneEntrada = (sEntrada == "si");

        Asistente* a = new Asistente(id, nombre, tieneEntrada, asiento, vip);
        a->setVip(vip);

        colaIngreso.push(a);

        Ticket* t = new Ticket(id, asiento, vip);
        abbTickets.insertar(t);
    }
}

