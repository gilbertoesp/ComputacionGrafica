#ifndef TORTUGA_H
#define TORTUGA_H

#include "Punto.h"

#include <cstring>

class Tortuga
{
    public:
        Tortuga(Punto posicion_inicial);
        virtual ~Tortuga();

        Punto Getposicion() { return m_posicion; }
        void Setposicion(Punto val) {
            m_posicion.setx(val.x());
            m_posicion.sety(val.y());
        }
        int Getheading_angle() { return m_heading_angle; }
        void Setheading_angle(int val) { m_heading_angle = val; }
        int Getangle_int() { return m_angle_inc; }
        void Setangle_inc(int val) { m_angle_inc = val; }
        int Getstep_size() { return m_step_size; }
        void Setstep_size(int val) { m_step_size = val; }

        static void test();
        /// Dibujando con nuestra tortuga
        void dibujar(std::string cadena, unsigned int _color);
        /// Avanza la tortuga dibujando una linea
        void avanza(unsigned int _color);
    protected:

    private:
        Punto m_posicion;
        int m_heading_angle;
        int m_step_size;
        int m_angle_inc;
};

#endif // TORTUGA_H
