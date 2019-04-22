#include <iostream>
#include <graphics.h>

//#include "Punto.h"
#include "Linea.h"
int main(){
    std::cout << "Computacion Grafica." << std::endl;

    /// DRAWING
    // gm is el modo Grafico del display de la computadora
    // mode genera imagenes usando pixels
    // DETECT es un macro definido en "graphics.h" header
    int gd = DETECT, gm;

    // initgraph inicializa el grafico del sistema
    // cargando los graficos del disco
    initgraph(&gd, &gm, "");

    //Punto::test(); Dibuja 3 puntos
    //Linea::test();
    Circulo::test();
    // End DRAWING
    getch();
    // Cierra el grafico generado y limpia la memoria.
    closegraph();
    return 0;
}
