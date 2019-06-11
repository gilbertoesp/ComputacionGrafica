#include <iostream>
#include "Clipping.h"
using namespace std;
/*
    Main para probar el clipping
*/
void test_clipping()
{
    cout << "Algoritmos de Clipping" << endl;
    //Linea::drawAxis();
    // Puntos minimos y maximos de la ventana de dibujo
    Punto min, max;
    min.set(-160,-100);
    max.set(160,100);
    window(min, max, WHITE);

    Linea linea1;
    linea1.setInicio(-50,-180);
    linea1.setFinal(50,25);
    //    linea.draw();
    linea1.draw(RED);
    clip_cohen_sutherland(linea1,min,max);

    Linea linea2;
    linea2.setInicio(30,180);
    linea2.setFinal(200,0);
    //    linea.draw();
    linea2.draw(RED);
    clip_cohen_sutherland(linea2,min,max);

    Linea linea3;
    linea3.setInicio(-170,-50);
    linea3.setFinal(-190,100);
    //    linea.draw();
    linea3.draw(RED);
    clip_cohen_sutherland(linea3,min,max);

    Linea linea4;
    linea4.setInicio(-25,25);
    linea4.setFinal(75,50);
    //    linea.draw();
    linea4.draw(RED);
    clip_cohen_sutherland(linea4,min,max);


    // Lineas prueba
    // Caso dentro del area de graficacion
    return;
}
/*
    Dibuja un rectangulo que simula ser nuestra ventana de dibujar para el clipping
    Con centro en el origen.

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
/*
    Punto x,y min
    Punto x y max

    Dibuja un rectangulo entre ambos
*/
void window(Punto _min, Punto _max, unsigned int _color)
{
    Linea up, down, left, right;

    up.setInicio(_min.x(), _max.y());
    up.setFinal(_max.x(), _max.y());

    right.setInicio(_max.x(), _max.y());
    right.setFinal(_max.x(), _min.y());

    down.setInicio(_min.x(), _min.y());
    down.setFinal(_max.x(), _min.y());

    left.setInicio(_min.x(), _min.y());
    left.setFinal(_min.x(), _max.y());

    up.draw(_color);
    right.draw(_color);
    down.draw(_color);
    left.draw(_color);

    return;
}
//=================================================================
/////// COHEN SHUTERLAND //////////////////////////////////////////
OutCode ComputeOutCode(Punto _punto, Punto _min, Punto _max)
{
	OutCode code;
	code = INSIDE;          // initialised as being inside of [[clip window]]

	if (_punto.x() < _min.x())           // to the left of clip window
		code |= LEFT;
	else if (_punto.x() > _max.x())      // to the right of clip window
		code |= RIGHT;
	if (_punto.y() < _min.y())           // below the clip window
		code |= BOTTOM;
	else if (_punto.y() > _max.y())      // above the clip window
		code |= TOP;

	return code;
}

// Cohen–Sutherland clipping algorithm clips a line from
// P0 = (x0, y0) to P1 = (x1, y1) against a rectangle with
// diagonal from (xmin, ymin) to (xmax, ymax).
void clip_cohen_sutherland(Linea _linea, Punto _min, Punto _max)
{
    int x0,y0,x1,y1;
    x0 = _linea.Inicio().x(); y0 = _linea.Inicio().y();
    x1 = _linea.Final().x(); y1= _linea.Final().y();
	// compute outcodes for P0, P1, and whatever point lies outside the clip rectangle
	OutCode outcode0 = ComputeOutCode(_linea.Inicio(), _min, _max);
	OutCode outcode1 = ComputeOutCode(_linea.Final() , _min, _max);
	bool accept = false;

	while (true) {
		if (!(outcode0 | outcode1)) {
			// bitwise OR is 0: both points inside window; trivially accept and exit loop
			accept = true;
			break;
		} else if (outcode0 & outcode1) {
			// bitwise AND is not 0: both points share an outside zone (LEFT, RIGHT, TOP,
			// or BOTTOM), so both must be outside window; exit loop (accept is false)
			break;
		} else {
			// failed both tests, so calculate the line segment to clip
			// from an outside point to an intersection with clip edge
			double x, y;

			// At least one endpoint is outside the clip rectangle; pick it.
			OutCode outcodeOut = outcode0 ? outcode0 : outcode1;

			// Now find the intersection point;
			// use formulas: y4 e
			//   slope = (y1 - y0) / (x1 - x0)
			//   x = x0 + (1 / slope) * (ym - y0), where ym is ymin or ymax
			//   y = y0 + slope * (xm - x0), where xm is xmin or xmax
			// No need to worry about divide-by-zero because, in each case, the
			// outcode bit being tested guarantees the denominator is non-zero
			if (outcodeOut & TOP) {           // point is above the clip window
				x = x0 + (x1 - x0) * (_max.y() - y0) / (y1 - y0);
				y = _max.y();
			} else if (outcodeOut & BOTTOM) { // point is below the clip window
				x = x0 + (x1 - x0) * (_min.y() - y0) / (y1 - y0);
				y = _min.y();
			} else if (outcodeOut & RIGHT) {  // point is to the right of clip window
				y = y0 + (y1 - y0) * (_max.x() - x0) / (x1 - x0);
				x = _max.x();
			} else if (outcodeOut & LEFT) {   // point is to the left of clip window
				y = y0 + (y1 - y0) * (_min.x() - x0) / (x1 - x0);
				x = _min.x();
			}

			// Now we move outside point to intersection point to clip
			// and get ready for next pass.
			if (outcodeOut == outcode0) {
				x0 = x;
				y0 = y;
                _linea.setInicio(x,y);
				outcode0 = ComputeOutCode(_linea.Inicio(), _min,_max);
			} else {
				x1 = x;
				y1 = y;
				_linea.setFinal(x,y);
				outcode1 = ComputeOutCode(_linea.Final(), _min,_max);
			}
		}
	}
	if (accept) {
		// Following functions are left for implementation by user based on
		// their platform (OpenGL/graphics.h etc.)
		//DrawRectangle(xmin, ymin, xmax, ymax);
		//LineSegment(x0, y0, x1, y1);
		_linea.draw(GREEN);
		cout << "accepted";
	}
}
