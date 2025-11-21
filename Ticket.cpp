#include "Ticket.h"

/**
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
 * Getter Id del ticket
 * @return Id del ticket
 */
int Ticket::getIdTicket() {
    return this->idTicket;
}

/**
 * Getter Id del ticket
 * @return Numero de asiento
 */
int Ticket::getAsiento() {
    return this->asiento;
}

/**
 * Getter VIP
 * @return true si es VIP, false si no lo es
 */
bool Ticket::isVip() {
    return this->vip;
}

/**
 * Getter Usado
 * @return true si el asiento esta usado, false si no lo esta
 */
bool Ticket::isUsado() {
    return this->usado;
}

/**
 * Metodo para cambiar el estado de la variable usado
 */
void Ticket::marcarUsado() {
    usado = true;
}

