#include "Asistente.h"

/**
 * Constructor clase asistente
 * @param id
 * @param nombre
 * @param entrada
 * @param asiento
 */
Asistente::Asistente(int id, string nombre, bool entrada, int asiento, bool vip) {
    this->id = id;
    this->nombre = nombre;
    this->entrada = entrada;
    this->asiento = asiento;
    this->vip = vip;
}

/**
 * Getter ID
 * @return ID de la persona
 */
int Asistente::getId() {return this->id;}

/**
 * Getter Nombre
 * @return Nombre de la persona
 */
string Asistente::getNombre() {return this->nombre;}

/**
 * Getter Entrada
 * @return true si la persona tiene entrada, false si la persona no tiene entrada
 */
bool Asistente::getEntrada() {return this->entrada;}

/**
 * Getter Asiento
 * @return Numero de asiento del cliente
 */
int Asistente::getAsiento() {return this->asiento;}

/**
 * Getter VIP
 * @return true si la persona es VIP, false si no lo es
 */
bool Asistente::getVip() {return this->vip;}

/**
 * Setter VIP
 */
void Asistente::setVip(bool vip) {
    this->vip = vip;
}

