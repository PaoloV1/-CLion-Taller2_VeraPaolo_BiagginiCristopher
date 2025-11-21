//
// Created by Paolo on 21-11-2025.
//

#ifndef COLA_H
#define COLA_H


template <typename T>
class NodoCola {
public:
    T dato;
    NodoCola<T>* siguiente;
    NodoCola(T dato): dato(dato), siguiente(nullptr) {}
};
template <typename T>
class Cola {
private:
    NodoCola<T>* frente;
    NodoCola<T>* fin;
public:
    Cola() : frente(nullptr), fin(nullptr) {}

    ~Cola() {
        while (!estaVacia()) desencolar();
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    void encolar(T dato) {
        NodoCola<T>* nuevo = new NodoCola<T>(dato);
        if (estaVacia()) {
            frente = fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }
    T desencolar() {
        if (estaVacia()) return nullptr

        NodoCola<T>* temp = frente;
        T dato = temp->dato;
        frente = frente->siguiente;

        if (frente == nullptr) fin = nullptr;

        delete temp;
        return dato;
    }

    T peek() {
        if (estaVacia()) return nullptr;
        return frente->dato;
    }

};



#endif //COLA_H
