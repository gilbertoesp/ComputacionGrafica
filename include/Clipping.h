#ifndef CLIPPING_H_INCLUDED
#define CLIPPING_H_INCLUDED
#include "Punto.h"
#include "Linea.h"
/*
    Test
*/
void test_clipping();
//////////////////////////////////////////
/*
    ->Docs
    ->ToDo: Regresar los 4 puntos donde terminan
*/
void window(int _heigth, int _width, unsigned int _color);
//////////////////////////////////////////
/*
    Crea una window dado o 2 puntos, esquinas opuestas. que son los limites de la venana
*/
void window(Punto _min, Punto _max, unsigned int _color);
//////////////////////////////////////////
/** \brief Algoritmo Cohen Sutherland para Clipping de Lineas
 *  Cambia el inicio o final de la linea si esta se sale de la pantalla de corte.
 * \param linea que queremos pintar,
 * \param _min Punto minimo de la ventana de trazado
 * \param _max Punto maximo de la ventana de trazado
 * \return void
 *
 */
void clip_cohen_sutherland(Linea _linea, Punto _min, Punto _max);
//////////////////////////////////////////
/*
    Funcion Auxiliar
    Calcula el codigo bit para un punto, usando el rectangulo de recorte
    con esquinas _min y _max
*/
typedef int OutCode;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000
OutCode ComputeOutCode(Punto _punto, Punto _min, Punto _max);
//////////////////////////////////////////
#endif // CLIPPING_H_INCLUDED
