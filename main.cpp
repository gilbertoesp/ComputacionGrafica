#include <iostream>
#include <graphics.h>

#include "Punto.h"
//#include "Circulo.h"
//#include "Clipping.h"
#include "Tortuga.h"
#include "L_system.h"

void koch_island(unsigned int color)
{
    int grado;
    Punto origen(-150,150);
    L_system koch("F-F-F-F");
    Tortuga tortuga(origen);
    tortuga.Setstep_size(5); // Paso pequeno

    koch.agregar_regla("F", "F-F+F+FF-F-F+F");
    grado = 3;
    for(int i = 0 ; i <= grado ; i++){
        koch.aplicar_reglas(i);
        std::cout << "Iteracion: " << i << "\t Cadena: " << koch.Get_cadena() << std::endl;
    }
    tortuga.dibujar(koch.Get_cadena(), color);
}

int main(){
    std::cout << "Computacion Grafica." << std::endl;

    /// DRAWING
    // gm is el modo Grafico del display de la computadora
    // mode genera imagenes usando pixels
    // DETECT es un macro definido en "graphics.h" header
    //int gd = DETECT, gm;

    // initgraph inicializa el grafico del sistema
    // cargando los graficos del disco
    //initgraph(&gd, &gm, "");
    initwindow(800, 600);

    //Punto::test(); Dibuja 3 puntos
    //Linea::test();
    //Circulo::test();
    //test_clipping();
    //L_system::test();
    //Tortuga::test();
    ///Fractales
    koch_island(CYAN);
    // End DRAWING
    getch();
    // Cierra el grafico generado y limpia la memoria.
    closegraph();
    return 0;
}
