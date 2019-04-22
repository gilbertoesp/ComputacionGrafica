#ifndef LINEA_H
#define LINEA_H

#include "Punto.h"
/*
    Linea, Primitiva Grafica
*/
class Linea
{
    private:
        Punto m_inicio;
        Punto m_final;

    public:
        Linea() : m_inicio(0,0), m_final(0,0) {} // Punto en centro
        Linea(Punto _inicio, Punto _final);
        ~Linea() {};
        // Set & Get - Inicio
        Punto Inicio() { return m_inicio; }
        void setInicio(Punto _punto) {
            m_inicio.setx(_punto.x());
            m_inicio.sety(_punto.y());
        }
        void setInicio(int _x, int _y) {
            m_inicio.setx(_x);
            m_inicio.sety(_y);
        }
        // Set & Get - Inicio
        Punto Final() { return m_final; }
        void setFinal(Punto _punto) {
            m_final.setx(_punto.x());
            m_final.sety(_punto.y());
        }
        void setFinal(int _x, int _y) {
            m_final.setx(_x);
            m_final.sety(_y);
        }

        static void drawAxis(unsigned int _color = BLUE); // Dibuja los ejes de plano cartesiano en el display

        /* Funcion de la clase para dibujar una linea entre dos puntos dados, sin tener que crear un nuevo objeto Linea */
        static void draw(Punto _inicio, Punto _final, unsigned int _color);

        void draw(unsigned int _color = RED); // Algoritmo de Bresenham
        void drawDDA(unsigned int _color = GREEN); //Algoritmo Diferencal
        void drawGeneral(unsigned int _color = CYAN); // Algoritmo General

        static void test(); // Testeamos las funciones y diversos punto

};

#endif // LINEA_H
