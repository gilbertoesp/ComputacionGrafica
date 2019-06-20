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
    Punto origen(-200,200);
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

void cuadrado_3(unsigned int color)
{
    int grado;
    Punto origen(-400,400);
    L_system cuadra("F-F-F-F");
    Tortuga tortuga(origen);
    tortuga.Setstep_size(10); // Paso pequeno

    cuadra.agregar_regla("F", "FF-F--F-F");
    grado = 4;

    cuadra.aplicar_reglas(grado);
    std::cout << "Iteracion: " << grado << "\t Cadena: " << cuadra.Get_cadena() << std::endl;

    tortuga.dibujar(cuadra.Get_cadena(), color);
}

void spin(unsigned int color)
{
    int grado;
    Punto origen(0,200);
    L_system spin("F-F-F-F");
    Tortuga tortuga(origen);
    tortuga.Setstep_size(10); // Paso pequeno

    spin.agregar_regla("F", "FF-F-F-F-F-F+F");
    grado = 3;

    spin.aplicar_reglas(grado);
    std::cout << "Iteracion: " << grado << "\t Cadena: " << spin.Get_cadena() << std::endl;

    tortuga.dibujar(spin.Get_cadena(), color);
}

void dragon_curva(unsigned int color)
{
    int grado;
    Punto origen(0,0);
    Tortuga tortuga(origen);
    tortuga.Setstep_size(10); // Paso pequeno
    L_system curva("L");
    // L y R es avanzar, se hace, en la lectura de tortuga, la interpreta como F
    curva.agregar_regla("L", "L+R+");
    curva.agregar_regla("R", "-L-R");
    grado = 8;

    curva.aplicar_reglas(grado);
    std::cout << "Iteracion: " << grado << "\t Cadena: " << curva.Get_cadena() << std::endl;
    tortuga.dibujar(curva.Get_cadena(), color);
}

void sierpinski_triangle(unsigned int color)
{
    int grado;
    Punto origen(-400,300);

    L_system triangulo("L");
    // Tanto L como R,
    triangulo.agregar_regla("L", "R+L+R");
    triangulo.agregar_regla("R", "L-R-L");

    Tortuga tortuga(origen);
    tortuga.Setangle_inc(60); // Angulo de 60
    tortuga.Setstep_size(3);
    grado = 8;
    triangulo.aplicar_reglas(grado);
    std::cout << "Iteracion: " << grado << "\t Cadena: " << triangulo.Get_cadena() << std::endl;
    tortuga.dibujar(triangulo.Get_cadena(), color);
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
    initwindow(800, 800);

    //Punto::test(); Dibuja 3 puntos
    //Linea::test();
    //Circulo::test();
    //test_clipping();
    //L_system::test();
    //Tortuga::test();
    ///Fractales
    //koch_island(CYAN);
    //cuadrado_3(CYAN);
    //spin(CYAN);
    //dragon_curva(CYAN);
    sierpinski_triangle(CYAN);
    // End DRAWING
    getch();
    // Cierra el grafico generado y limpia la memoria.
    closegraph();
    return 0;
}
