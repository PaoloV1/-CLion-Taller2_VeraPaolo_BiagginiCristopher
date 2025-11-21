//
// Created by Paolo on 21-11-2025.
//

#include "Ticket.h"

/**
 * @author Paolo Vera
 * Constructor Ticket
 * @param idTicket
 * @param asiento
 * @param vip
 */
Ticket::Ticket(int idTicket, int asiento, bool vip) {
    this->idTicket = idTicket;
    this->asiento = asiento;
    this->vip = vip;
    this->usado = false;
}

/**
 * @author Paolo Vera
 * Getter Id del ticket
 * @return Id del ticket
 */
int Ticket::getIdTicket() {
    return this->idTicket;
}

/**
 * @author Paolo Vera
 * Getter Id del ticket
 * @return Numero de asiento
 */
int Ticket::getAsiento() {
    return this->asiento;
}

/**
 * @author Paolo Vera
 * Getter VIP
 * @return true si es VIP, false si no lo es
 */
bool Ticket::isVip() {
    return this->vip;
}

/**
 * @author Paolo Vera
 * Getter Usado
 * @return true si el asiento esta usado, false si no lo esta
 */
bool Ticket::isUsado() {
    return this->usado;
}

/**
 * @author Paolo Vera
 * Metodo para cambiar el estado de la variable usado
 */
void Ticket::marcarUsado() {
    usado = true;
}

