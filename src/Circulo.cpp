#include "Circulo.h"

Circulo::Circulo(Punto _punto, unsigned int _radio)
{
    //ctor
    m_centro.set(_punto.x(), _punto.y());
    m_radio = _radio;
}

Circulo::Circulo(int _x, int _y, unsigned int _radio)
{
    //ctor
    m_centro.set(_x, _y);
    m_radio = _radio;
}
// Funcion auxiliar que dibuja 8 puntos en pantalla, por los cuadrantes en los que dividimos el circulo
void Circulo::draw8Punto(int _x, int _y, unsigned int _color)
{
    Punto::drawPunto(m_centro.x() + _x, m_centro.y() + _y, _color);
    Punto::drawPunto(m_centro.x() - _x, m_centro.y() + _y, _color);
    Punto::drawPunto(m_centro.x() + _x, m_centro.y() - _y, _color);
    Punto::drawPunto(m_centro.x() - _x, m_centro.y() - _y, _color);

    Punto::drawPunto(m_centro.x() + _y, m_centro.y() + _x, _color);
    Punto::drawPunto(m_centro.x() - _y, m_centro.y() + _x, _color);
    Punto::drawPunto(m_centro.x() + _y, m_centro.y() - _x, _color);
    Punto::drawPunto(m_centro.x() - _y, m_centro.y() - _x, _color);

}

void Circulo::draw(unsigned int _color)
{
    int x = 0, y = m_radio;

    // Factor de Decision d
    int d = 3 - 2 * m_radio;

    // Loop hasta y >= x
    while (y >= x)
    {
        // por cada pixel pintaremos 8 aprovechando la simetria
        this->draw8Punto(x, y, _color);
        x++;

        // revisa el parametro d
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;

        this->draw8Punto(x, y, _color);
    }
    return;
}

void Circulo::test()
{
    Linea::drawAxis(); // Ejes de referencia
    Circulo circulo1(0,0,100); // Circulo con centro (0,0) y radio de 100
    circulo1.draw(RED); // Dibujando con Bresenham

    circulo1.setCentro(50,50);
    circulo1.draw(CYAN); // Dibujamos un circulo con el algoritmo DDA

    circulo1.setCentro(-50,50);
    circulo1.setRadio(50);
    circulo1.draw(YELLOW); // Dibujamos con el algoritmo general
    return;
}
