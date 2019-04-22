#ifndef PUNTO_H
#define PUNTO_H

// Librearias necesarias para el proyecto.
#include <graphics.h>
#include <iostream>
#include <math.h>

class Punto
{
    public:
        Punto() : m_x(0) , m_y(0) {}
        Punto( int _x,  int _y) : m_x(_x), m_y(_y) {}
        virtual ~Punto() {}; // El destructor

         int x() { return m_x; }
        void setx( int val) { m_x = val; }
         int y() { return m_y; }
        void sety( int val) { m_y = val; }
        void set( int _x, int _y ) { m_x = _x; m_y = _y; }

        void drawPunto( unsigned int color); //Dibujando un pixel con respecto a las coordenadas de la ventana
         // #TODO Es la mejor forma de dibujar un punto?
        static void drawPunto(int _x, int _y, unsigned int _color); // Dibuja un punto con las coordenas dadas.
        // void input(); // Captura un punto. #TODO
        void print(); // Imprime en consola el punto, estilo  (x,y)
        float dist(Punto _other); // La distancia entre dos puntos

        static void test(); // Testeamos las funciones y diversos punto

    private:
         int m_x; // member_x
         int m_y; // member_y
};

#endif // PUNTO_H
