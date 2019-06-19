#include "L_system.h"
#include <iostream>

#define EQUAL 0 // Utilizado para comparar cadenas

void L_system::test()
{
    std::cout << "L-system" << std::endl;

    L_system l_sist("F");
    if (l_sist.Get_axioma() != "F")
        std::cout << "Error 101" << std::endl;

    l_sist.agregar_regla("F", "F+F");
    if(l_sist.regla("+") != "+")
        std::cout << "Error 102" << std::endl;
    if(l_sist.regla("F") != "F+F")
        std::cout << "Error 103" << std::endl;

    l_sist.aplicar_reglas(2);
    if(l_sist.Get_cadena() != "F+F+F+F")
        std::cout << "Error 104" << std::endl;

    std::cout << "\nTest Passed" << std::endl;
}
/**
    Constructor por defecto, inicializa con strings vacias ("") y NULL
*/
L_system::L_system()
{
    m_axioma = "";
    m_cadena = "";
    m_reglas = NULL;
}
/**
    Constructor con axioma, lo asigna a axioma y a cadena,
*/
L_system::L_system(std::string _axioma)
{
    m_axioma = _axioma;
    m_cadena = _axioma;
    m_reglas = NULL;
}
L_system::~L_system()
{
    // Borrando relgas creadas dinamicamente
    Regla* tmp;
    if( m_reglas != NULL )
        tmp = m_reglas; // guardamos el inicio de la lista de reglas
        m_reglas = m_reglas->siguiente; // avanzamos en la lista, el ultimo elemento le pasara NULL
        delete tmp; // borramos la regla sacada
}
/**
    Agregando una nueva regla a la lista linkeada de reglas
*/
void L_system::agregar_regla(std::string _simbolo, std::string _produccion)
{
    //struct Regla* nueva = (struct Regla*) malloc(sizeof(struct Regla));
    Regla* nueva;
    nueva = new Regla;
    nueva->simbolo = _simbolo;
    nueva->produccion = _produccion;
    nueva->siguiente = m_reglas;
    m_reglas = nueva;
}
/**
    Regresa la regla para el simbolo dado
*/
std::string L_system::regla(std::string _simbolo)
{
    Regla* tmp;
    tmp = m_reglas;
    while(tmp != NULL){
        if(tmp->simbolo == _simbolo) return tmp->produccion;
        else tmp = tmp->siguiente;
    }
    return _simbolo; // Si no se encuentra el simbolo, regla de identidad
}
/**
    Aplica las reglas del sistema L una cantidad n de veces, siempre empieza del axioma
*/
void L_system::aplicar_reglas(int n)
{
    std::string tmp = "";
    std::string sim;
    m_cadena = m_axioma;

    for(int j = 0 ; j < n ; j++){
        tmp = "";
        for(unsigned int i = 0 ; i < m_cadena.length() ; i++){
            sim = m_cadena[i];
            tmp = tmp + this->regla(sim);
        }
        m_cadena = tmp;
    }
}
/*
L_system::L_system(const L_system& other)
{
    //copy ctor
}

L_system& L_system::operator=(const L_system& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
*/
