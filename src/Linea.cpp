
#include "Linea.h"

// Constructor dado dos objetos tipo Punto
Linea::Linea(Punto _inicio, Punto _final)
{
    //Punto incial
    m_inicio.setx(_inicio.x());
    m_inicio.sety(_inicio.y());
    //Punto final
    m_final.setx(_final.x());
    m_final.sety(_final.y());
}
/*
    Dibuja los ejes del plano en el color dado
*/
void Linea::drawAxis(unsigned int _color/*= BLUE*/)
{
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();
    std::cout << "Window Height: " << h << std::endl;
    std::cout << "Window Width: " << w << std::endl;
    // Axis
    Linea l_vertical, l_horizontal; // linea_
    //Mitades del planoo
    l_vertical.setInicio((int)-w/2,0);
    l_vertical.setFinal(w/2,0);
    l_horizontal.setInicio(0,h/2);
    l_horizontal.setFinal(0,-h/2);

    l_vertical.draw(_color);
    l_horizontal.draw(_color);
    return;
}

void Linea::draw(Punto _inicio, Punto _final, unsigned int _color)
{
    // Utilizamos el algoritmo de BResenham por ser el mas eficaz de los tres mostrados
        // Definiendo las deltas
    int dx = _final.x() - _inicio.x();
    int dy = _final.y() - _inicio.y();

    // Signos de las deltas
    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);

    // Punto iniciales para dibujar
    int x = _inicio.x();
    int y = _inicio.y();

    // Bandera para saber si se intercambian o no
    bool isSwaped = false;

    // Des ser necesario, Intercambia los deltas para avanzar en la direccion del otro punto
    if(abs(dy) > abs(dx))
    {
        // intercambio de dx y dy
        int tdx = dx;
        dx = dy;
        dy = tdx;

        isSwaped = true;
    }

    // Parametro de Desicion
    int p = 2*(abs(dy)) - abs(dx);

    //Dibuja punto inicial
    Punto::drawPunto(x,y,_color);

    // Ciclo por la cantidad de espacio entre las x, dx
    for(int i = 0; i<= abs(dx);i++)
    {
        // Depending on decision parameter
        if(p < 0)
        {
            if(isSwaped == 0){
                x = x + sx;
                Punto::drawPunto(x,y,_color);
            }
            else{
                y = y+sy;
                Punto::drawPunto(x,y,_color);
            }
            p = p + 2*abs(dy);
        }
        else
        {
            x = x+sx;
            y = y+sy;
            Punto::drawPunto(x,y,_color);
            p = p + 2*abs(dy) - 2*abs(dx);
        }
    }
}

void Linea::draw(unsigned int _color/* = RED */)
{
    /*
        m_inicio.x() = x1
        m_inicio.y() = m_inicio.y()
        m_final.x() = x2
        m_final.y() = y2
    */
    // Definiendo las deltas
    int dx = m_final.x() - m_inicio.x();
    int dy = m_final.y() - m_inicio.y();

    // Signos de las deltas
    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);

    // Punto iniciales para dibujar
    int x = m_inicio.x();
    int y = m_inicio.y();

    // Bandera para saber si se intercambian o no
    bool isSwaped = false;

    // Des ser necesario, Intercambia los deltas para avanzar en la direccion del otro punto
    if(abs(dy) > abs(dx))
    {
        // intercambio de dx y dy
        int tdx = dx;
        dx = dy;
        dy = tdx;

        isSwaped = true;
    }

    // Parametro de Desicion
    int p = 2*(abs(dy)) - abs(dx);

    //Dibuja punto inicial
    Punto::drawPunto(x,y,_color);

    // Ciclo por la cantidad de espacio entre las x, dx
    for(int i = 0; i<= abs(dx);i++)
    {
        // Depending on decision parameter
        if(p < 0)
        {
            if(isSwaped == 0){
                x = x + sx;
                Punto::drawPunto(x,y,_color);
            }
            else{
                y = y+sy;
                Punto::drawPunto(x,y,_color);
            }
            p = p + 2*abs(dy);
        }
        else
        {
            x = x+sx;
            y = y+sy;
            Punto::drawPunto(x,y,_color);
            p = p + 2*abs(dy) - 2*abs(dx);
        }
    }
}
void Linea::drawDDA(unsigned int _color)
{
    // calculate dx & dy
    float dx = m_final.x() - m_inicio.x();
    float dy = m_final.y() - m_inicio.y();

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    int x_inc = dx / steps;
    int y_inc = dy / steps;

    // Put pixel for each step
    float x = m_inicio.x();
    float y = m_inicio.y();
    for (int i = 0; i <= steps; i++)
    {
        Punto::drawPunto(x,y,_color);  // put pixel at (X,Y)
        x += x_inc;                          // increment in x at each step
        y += y_inc;                          // increment in y at each step

    }

    return;
}

void Linea::drawGeneral(unsigned int _color /* = CYAN*/)
{

    float m = (m_final.y()-m_inicio.y()) / (m_final.x()-m_inicio.x());
    float b = m_inicio.y() - m * m_inicio.x();
    float y;
    int x;
    Punto::drawPunto(m_inicio.x(),m_inicio.y(),_color);
    for(x = m_inicio.x() + 1 ; x <= m_final.x() ; x++){
        y = m*x + b;
        Punto::drawPunto(x,round(y),_color);
    }

    return;
}

void Linea::test()
{
    std::cout << "Test Linea Iniciando." << std::endl; // Empezamos a dibujar varias lineas
    // Este test dibuja lineas paralelas con m = 1/2
    Punto a(50,50);
    Punto a2(-50,-50);
    Linea linea1(a,a2);
    linea1.draw(RED);
    // Este dibuja una linea con pendiente -1/2
    Punto b(-100,100);
    Punto b2; // Punto en (0,0)
    linea1.setInicio(b2); //test set
    linea1.setFinal(b);
    linea1.draw(CYAN);
    // Dibujando Ejes
    Linea::drawAxis(BLUE);
    // Dibujando on los otros algoritmos
    linea1.setInicio(-100,-50);
    linea1.setFinal(100,50);
    linea1.drawDDA(LIGHTGREEN);

    linea1.setInicio(-50,-100);
    linea1.setFinal(50,100);
    linea1.drawGeneral(LIGHTMAGENTA);
    a.set(-150,50);
    a2.set(50,-150);
    Linea::draw(a,a2, LIGHTGRAY);
    std::cout << "Test Linea Terminado" << std::endl;

}
