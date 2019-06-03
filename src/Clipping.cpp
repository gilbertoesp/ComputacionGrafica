#include <iostream>
#include "Linea.h"
#include "Clipping.h"
using namespace std;
/*
    Main para probar el clipping
*/
void test_clipping()
{
    cout << "Algoritmos de Clipping" << endl;
    int win_heigth, win_width;
    win_heigth = 300; win_width = 200;

    Linea::drawAxis();
    window(win_heigth,win_width,WHITE);
    return;
}
/*
    Dibuja un rectangulo que simula ser nuestra ventana de dibujar para el clipping
    Con centro en el origen
*/
void window(int _heigth, int _width, unsigned int _color)
{
    Linea up, down, left, right;

    up.setInicio(-_heigth/2, _width/2);
    up.setFinal(_heigth/2, _width/2);

    right.setInicio(_heigth/2, _width/2);
    right.setFinal(_heigth/2, -_width/2);

    down.setInicio(-_heigth/2, -_width/2);
    down.setFinal(_heigth/2, -_width/2);

    left.setInicio(-_heigth/2, _width/2);
    left.setFinal(-_heigth/2, -_width/2);

    up.draw(_color);
    right.draw(_color);
    down.draw(_color);
    left.draw(_color);

    return;
}
