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

void Circulo::drawDDA(unsigned int _color)
{
    int tx, ty;
    double dt, cc, ss, x,y, aux;
    dt = (double)1/m_radio;
    cc = cos(dt);
    ss = sin(dt);
    x = 0; y = m_radio;

    while (y >= abs(x)){
        tx = round(x);
        ty = round(y);
        this->draw8Punto(tx, ty, _color);

        aux = x;
        x = x *cc - y*ss;
        y = y*cc+aux*ss;
    }
    return;
}

void Circulo::drawGeneral(unsigned int _color) // Algoritmo General
{
    float y1, y2;
    int x;
    for (x = m_centro.x()- m_radio ; x <= m_centro.x() + m_radio ; x = x + 2){
        y1 = m_centro.y() + sqrt( pow(m_radio, 2) - pow(x - m_centro.x(), 2) );
        y2 = m_centro.y() - sqrt( pow(m_radio, 2) - pow(x - m_centro.x(), 2) );
        Punto::drawPunto(x, y1, _color);
        Punto::drawPunto(x, y2, _color);
    }


    return;
}
void Circulo::test()
{
    Linea::drawAxis(); // Ejes de referencia
    Circulo circulo1(0,0,100); // Circulo con centro (0,0) y radio de 100
    circulo1.draw(RED); // Dibujando con Bresenham

    circulo1.setCentro(100,100);
    circulo1.drawDDA(CYAN); // Dibujamos un circulo con el algoritmo DDA

    circulo1.setCentro(-100,100);
    circulo1.setRadio(75);
    circulo1.drawGeneral(YELLOW); // Dibujamos con el algoritmo general
    return;
}
