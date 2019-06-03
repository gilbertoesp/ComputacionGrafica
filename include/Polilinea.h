#ifndef POLILINEA_H
#define POLILINEA_H

#include "Punto.h"
class Polilinea
{
    public:
        Polilinea();
        ~Polilinea();
        Polilinea(const Polilinea& other);
        Polilinea& operator=(const Polilinea& other);

        Punto* Getpuntos() { return m_puntos; }
        void Setpuntos(Punto* val) { m_puntos = val; }

    protected:

    private:
        Punto* m_puntos;
};

#endif // POLILINEA_H
