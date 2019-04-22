#include "Punto.h"
void Punto::print()// Imprime en consola el punto, estilo  (x,y)
{
    std::cout << "(" << m_x << ", " << m_y << ")";
}
void Punto::drawPunto(unsigned int _color)
{
    //Dibujando un pixel con respecto a las coordenadas de la ventana
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();
    putpixel(m_x + w/2, (h/2) - m_y, _color);
}

void Punto::drawPunto(int _x, int _y, unsigned int _color) // Dibuja un punto con las coordenas dadas.
{
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();
    putpixel(_x + w/2, (h/2) - _y, _color);
}

float Punto::dist(Punto _other)// La distancia entre dos puntos
{
    float xd = m_x - _other.x();
    float yd = m_x - _other.y();
    return sqrt(xd*xd + yd*yd);
}

void Punto::test() // Testeamos los puntos y las funciones
{
    std::cout << "\nTest Punto Iniciando." << std::endl;
    //Algunos puntos
    Punto a(-5, -5);
    Punto b(5, 5);
    Punto c(100,100);
    std::cout << "test print. Punto C. "; c.print(); //Imprimiendo punto c
    a.drawPunto(RED);
    b.drawPunto(CYAN);
    c.drawPunto(YELLOW);
    Punto::drawPunto(50,-50, MAGENTA);
    std::cout << "Test Punto Terminado." << std::endl;
}
