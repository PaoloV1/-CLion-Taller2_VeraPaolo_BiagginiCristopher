//
// Created by Paolo on 17-11-2025.
//

#ifndef ABB_H
#define ABB_H

#include  "Asistente.h"
using namespace std;

class NodoABB {
public:
    Asistente* dato;
    NodoABB* hijoIzq;
    NodoABB* hijoDer;

    NodoABB(Asistente* asistente) : dato(asistente), hijoIzq(nullptr), hijoDer(nullptr){}

};

class ABB {
private:
    NodoABB* raiz;

    NodoABB* insertarRec(NodoABB* nodo, Asistente* asistente);
    Asistente* buscarRec(NodoABB* nodo, int id);
    void inOrdenRec(NodoABB* nodo);
    void liberarRec(NodoABB* nodo);

public:
    ABB();
    ~ABB();

    void insertar(Asistente* asistente);

    Asistente *buscar(int id);
    void inOrden();
};



#endif //ABB_H
