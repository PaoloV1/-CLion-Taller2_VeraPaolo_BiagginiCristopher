#ifndef ASISTENTE_H
#define ASISTENTE_H

#include <string>

using namespace std;
class Asistente {
private:
    int id;
    string nombre;
    bool entrada;
    int asiento;
    bool vip;
public:
    Asistente(int id, string nombre, bool entrada, int asiento, bool vip);
    int getId();
    string getNombre();
    bool getEntrada();
    int getAsiento();
    bool getVip();
    void setVip(bool vip);
};



#endif //ASISTENTE_H
