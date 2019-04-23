#ifndef CIRCULO_H
#define CIRCULO_H

#include "Linea.h"

class Circulo
{
    private:
        Punto m_centro;
        unsigned int m_radio;


    public:
        Circulo() : m_centro(0,0), m_radio(5) {};
        Circulo(int _x, int _y, unsigned int _radio);
        Circulo(Punto _punto, unsigned int _radio);
        ~Circulo() {};
        // Set & Get - Radio
        unsigned int getRadio() { return m_radio; }
        void setRadio(unsigned int _radio) { m_radio = _radio; }
        // Set & Get - Centro
        Punto getCentro() { return m_centro; }
        void setCentro(Punto _punto) {
            // Al objeto Punto que es nuestro ccentro lo seteamos con las coordenadas del muevo punto
            m_centro.set(_punto.x(), _punto.y());
        }
        void setCentro(int _x, int _y) {
            m_centro.set(_x, _y);
        }
        // Dibuja 8 puntos. Funcion auxiliar para trazado de circulos
        void draw8Punto(int _x, int _y, unsigned int _color);
        // Dibujando circulos
        void draw(unsigned int _color);

        static void test();
};

#endif // CIRCULO_H
