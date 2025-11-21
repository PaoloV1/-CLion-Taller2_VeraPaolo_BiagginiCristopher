//
// Created by Paolo on 21-11-2025.
//

#include "Sistema.h"

#include <fstream>
#include <iostream>
#include <sstream>

Sistema::Sistema() {}

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

        colaIngreso.encolar(a);

        Ticket* t = new Ticket(id, asiento, vip);
        abbTickets.insertar(t);
    }
    archivo.close();
}
void Sistema::inicializarAsientos(int cantidad) {
    arbolAsientos.construirAsientos(1,cantidad);
}


bool Sistema::validarEntrada(Asistente *a) {
    if (a == nullptr) {
        cout << "Asistente invalido"<<endl;
        return false;
    }

    int id= a->getId();
    Ticket* t = abbTickets.buscar(id);

    if (t == nullptr) {
        cout << "El ticket no existe en el sistema"<<endl;
        return false;
    }
    if (t->isUsado()) {
        cout << "Este ticket ya fue utilizado"<<endl;
        return false;
    }

    t->marcarUsado();
    cout <<"Entrada Valida"<<endl;
    return true;
}

void Sistema::procesarIngreso() {
    cout << "PROCESANDO INGRESO..."<<endl;
    cout << "..............."<<endl;
    cout << "..............."<<endl;

    while (!colaIngreso.estaVacia()) {
        Asistente* a = colaIngreso.desencolar();
        cout << "Procesando: "<<a->getNombre()<<" |Ticket: "<<a->getId()<<endl;

        Ticket* t = abbTickets.buscar(a->getId());

        if (t == nullptr) {
            cout << "Ticket invalido"<<endl;
            rechazados.push_back(a);
            continue;
        }
        if (t->isUsado()) {
            cout << "Este ticket ya fue utilizado"<<endl;
            rechazados.push_back(a);
            continue;
        }

        t->marcarUsado();
        ingresados.push_back(a);

        int asiento = t->getAsiento();

        cout << "Asignando asiento: "<<asiento<<endl;

        if (arbolAsientos.asignarAsiento(asiento, a)) {
            cout << "Asiento asignado correctamente"<<endl;
        } else {
            cout << "Este asiento ya esta ocupado. Ingreso denegado"<<endl;
        }
    }
    cout << "Todos los asistentes han sido procesados"<<endl;
}

void Sistema::mostrarAsientos() {
    arbolAsientos.mostrarInOrden();
}
void Sistema::mostrarResumen() {
    cout << "RESUMEN DEL CONCIERTO"<<endl;

    cout <<"GRAFICO DE ASIENTOS:"<<endl;
    mostrarAsientos();

    cout <<"LISTA DE ASISTENTES INGRESADOS:"<<endl;
    for (auto a :ingresados) {
        cout << a->getId()<< " - " << a->getNombre() << endl;
    }

    cout <<"LISTA DE ASISTENTES RECHAZADOS:"<<endl;
        for (auto a :rechazados) {
            cout << a->getId()<< " - " << a->getNombre() << endl;
        }
    cout <<"COMPRAS EN PUERTA: "<<comprasInPuerta<<endl;
}

void Sistema::determinarMerch() {
    for (auto a :ingresados) {
        if ((rand() % 100)< 60) {
            colaMerch.encolar(a);
        }
    }
}

void Sistema::merchandising() {
    cout << "MERCHANDISING"<<endl;

    while (!colaMerch.estaVacia()) {
        colaMerch.desencolar();
        if (merch > 0) {
            merch--;
            comprasInPuerta++;
        } else {
            sinComprar++;
        }
    }
}






