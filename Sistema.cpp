#include "Sistema.h"

#include <fstream>
#include <iostream>
#include <sstream>
/**
 * Metodo constructor clase Sistema
 */
Sistema::Sistema() {}

/**
 * Metodo para cargar los Asistentes del archivo a la Cola de ingreso y al ABB
 * @param nombreArchivo
 */
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
        int asiento = -1;
        if (!sAsiento.empty()) asiento = stoi(sAsiento);
        bool vip = (sVip == "si");
        bool tieneEntrada = (sEntrada == "si");

        Asistente* a = new Asistente(id, nombre, false, asiento, vip);
        a->setVip(vip);

        colaIngreso.encolar(a);
        if (tieneEntrada) {
            Ticket* t = new Ticket(id, asiento, vip);
            abbTickets.insertar(t);
        }

    }
    archivo.close();
}

/**
 * Metodo para inicializar los asientos del concierto
 * @param cantidad
 */
void Sistema::inicializarAsientos(int cantidad) {
    arbolAsientos.construirAsientos(1,cantidad);
}


/**
 * Metodo para procesar el ingreso de las personas que estan en la cola de ingreso
 */
void Sistema::procesarIngreso() {
    cout << "PROCESANDO INGRESO..."<<endl;
    cout << "..............."<<endl;
    cout << "..............."<<endl;

    while (!colaIngreso.estaVacia()) {
        Asistente* a = colaIngreso.desencolar();
        cout << "Procesando: "<<a->getNombre()<<" |Ticket: "<<a->getId()<<endl;

        Ticket* t = abbTickets.buscar(a->getId());

        if (t == nullptr) {
            rechazados.push_back(a);
            continue;
        }
        if (t->isUsado()) {
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

/**
 * Metodo para mostrar los asientos del concierto
 */
void Sistema::mostrarAsientos() {
    arbolAsientos.mostrarInOrden();
}

/**
 * Metodo para mostrar el Resumen al final del concierto
 */
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

    cout << "CANTIDAD DE PERSONAS QUE NO PUDIERON COMPRAR: "<<sinComprar<<endl;
}

/**
 * Metodo para determinar que asistentes del concierto quieren comprar merch y quienes no
 */
void Sistema::determinarMerch() {
    for (auto a :ingresados) {
        if ((rand() % 100)< 60) {
            colaMerch.encolar(a);
        }
    }
}

/**
 * Metodo para que cada persona que esta en la cola de merchandising compre un producto
 */
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






