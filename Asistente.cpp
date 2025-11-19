//
// Created by Paolo on 17-11-2025.
//

#include "Asistente.h"

/**
 * @author Paolo Vera
 * Constructor clase asistente
 * @param id
 * @param nombre
 * @param entrada
 * @param asiento
 */
Asistente::Asistente(int id, string nombre, bool entrada, int asiento) {
    this->id = id;
    this->nombre = nombre;
    this->entrada = entrada;
    this->asiento = asiento;
}

/**
 * @author Paolo Vera
 * Getter ID
 * @return ID de la persona
 */
int Asistente::getId() {return this->id;}

/**
 * @author Paolo Vera
 * Getter Nombre
 * @return Nombre de la persona
 */
string Asistente::getNombre() {return this->nombre;}

/**
 * @author Paolo Vera
 * Getter Entrada
 * @return true si la persona tiene entrada, false si la persona no tiene entrada
 */
bool Asistente::getEntrada() {return this->entrada;}

/**
 * @author Paolo Vera
 * Getter Asiento
 * @return Numero de asiento del cliente
 */
int Asistente::getAsiento() {return this->asiento;}

/**
 * @author Paolo Vera
 * Getter VIP
 * @return true si la persona es VIP, false si no lo es
 */
bool Asistente::getVip() {return this->vip;}
