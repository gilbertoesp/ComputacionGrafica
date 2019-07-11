#include "Tortuga.h"
#include "Linea.h"
#include <cmath> // sin cos
// Defaults
#define ANGLE_INCREMENT 90
#define STEP_SIZE 25
#define PI 3.14159265

Tortuga::Tortuga(Punto posicion_inicial)
{
    //ctor
    m_posicion.set(posicion_inicial.x(), posicion_inicial.y());
    m_heading_angle = 0;
    m_step_size = STEP_SIZE; // px
    m_angle_inc = ANGLE_INCREMENT; // grados
}
void Tortuga::set(Tortuga _other)
{
    this->Setposicion(_other.Getposicion());
    this->Setheading_angle(_other.Getheading_angle());
}
Tortuga::~Tortuga()
{
    //dtor
}
struct Estado{
    /**
        Simulacion de pila, para guardar los estados de las tortugas
    */
    Punto posicion;
    int angle;
    Estado* siguiente;

//    pila() {posicion(0,0), angle = 0, siguiente = NULL; }
};
void push(Punto _punto, int _angle)
{
    return;
}
void pop()
{
    return;
}
/**
    La tortuga podra leer simbolos dados en la cadena y dibujar a partir de ellos.
    F -> Dibuja una linea de tamano m_step_size
    + -> Aumenta m_heading_angle en m_angle_inc
    - -> Disminuye m_heading_angle en m_angle_inc
*/
void Tortuga::dibujar(std::string _cadena, unsigned int _color)
{
    std::string simbolo;
    for(unsigned int i = 0 ; i < _cadena.length() ; i++){
        simbolo = _cadena[i];
        //std::cout << "Simbolo: " << simbolo << std::endl;
        if(simbolo == "F"){ // F_l for edge rewriting
            this->avanza(_color);
        }
        if(simbolo == "R"){ // F_r for edge rewriting
            this->avanza(_color);
        }
        if(simbolo == "L"){ // F_r for edge rewriting
            this->avanza(_color);
        }
        /*
        if(simbolo == "["){
            pila.push(this);
        }
        if(simbolo == "]"){
            this.set(pila.top());
            pila.pop();
        }
        */
        if(simbolo == "+"){
            m_heading_angle = m_heading_angle + m_angle_inc;
        }
        if(simbolo == "-"){
            m_heading_angle = m_heading_angle - m_angle_inc;
        }
    }
}
/**
    Avanza la tortuga dibujando una linea de longitud STEP_SIZE en el angulo que ve la tortuga
*/
void Tortuga::avanza(unsigned int _color)
{
    Punto destino;
    // destino_x = posicion_x + step * cos (heading_angle)
    destino.setx(m_posicion.x() + (int)(m_step_size * std::cos( m_heading_angle * PI / 180.0 )));
    // destino_y = posicion_y + step * sin (heading_angle)
    destino.sety(m_posicion.y() + (int)(m_step_size * std::sin( m_heading_angle * PI / 180.0 )));
    /// La tortuga dibuja
    Linea::draw(m_posicion, destino, _color);
    // Cambiamos la posicion de la tortuga al destino
    this->Setposicion(destino);
    //std::cout << "Posicion: "; Getposicion().print(); std::cout << "\n";
}
/**
    TEST
*/
void Tortuga::test()
{
    Punto origen(0,0);
    //std::string cadena = "F+F+F+F"; // Un cuadrado
    //std::string cadena = "FFF-FF-F-F+F+FF-F-FFF"; // Un cuadrado
    std::string cadena = "F[F+F]F";
    Tortuga tortuga(origen);

    tortuga.dibujar(cadena, CYAN);

}
