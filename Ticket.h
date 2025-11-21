#ifndef TICKET_H
#define TICKET_H
#include <string>
using namespace std;


class Ticket {
private:
    int idTicket;
    int asiento;
    bool usado;
    bool vip;
public:
    Ticket(int idTicket, int asiento, bool vip);
    int getIdTicket();
    int getAsiento();
    bool isUsado();
    bool isVip();

    void marcarUsado();
};



#endif //TICKET_H
