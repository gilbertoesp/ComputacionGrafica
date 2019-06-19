#include "Fractal.h"
#include <iostream>
//#define PI 3.1416
/** Definiciones para comparar cadenas */
#define EQUAL 0
#define LARGER 1
#define SHORTER -1
void L_system::test()
{
    //L_sist;
    try
    {
        std::string axioma;

        axioma = "F";
        /// Axioma
        L_system l_sist(axioma);// Creando un L-system
        if( l_sist.axioma().compare(axioma) != EQUAL ) //TEST
            throw 101; // El axioma del objeto debe ser el declarado";
        if( l_sist.cadena().compare(axioma) != EQUAL ) //TEST
            throw 102; // La cadena al inicio es el axioma del objeto debe ser el declarado";
        std::cout << "Axioma test clear." << std::endl;
    /// Reglas
        l_sist.agregar_regla("F", "F+F"); // Agrega una nueva regla al conjunto de reglas
        l_sist.agregar_regla("G", "FF");
        std::cout << l_sist.regla()->produccion;
        if( l_sist.regla()->simbolo.compare("F") == EQUAL ) //TEST
            throw 201; //
        if( l_sist.regla()->produccion.compare("F+F") == EQUAL ) //TEST
            throw 202;
        if( l_sist.regla("+").compare("+") == EQUAL )
            throw 203;
        if( l_sist.regla("G").compare("FF") == EQUAL )
            throw 204;

        std::cout << "Reglas test clear." << std::endl;
    /// Cadena Final
        if( l_sist.cadena().compare(axioma) != EQUAL )
            throw 3; // cadena no es el axioma
        std::cout << "Cadena final test clear." << std::endl;

        std::cout << "All test clear." << std::endl;
        //l_sist.apply_rules(grado); // Aplica las reglas a la cadena de l_system


    }
    catch (int err)
    {
        std::cout << "An exception occurred. " << "Error: " << err << '\n';
    }
}
/**

*/
L_system::L_system()
{
    m_axioma = "";
    m_reglas = NULL;
    m_cadena = "";
}
/**

*/
L_system::L_system(std::string _axioma)
{
    m_axioma = _axioma;
    m_reglas = NULL;
    m_cadena = _axioma; // La cadena final empieza con el axioma
}
/** \brief Destructor, itera la lista de reglas creada dinamicamente y las borra
 *
 * \param
 * \param
 * \return
 *
 */

L_system::~L_system()
{
    Regla* regla; // REgla auxiliar para iterar
    while(m_reglas != NULL){
        regla = m_reglas;
        m_reglas = m_reglas->siguiente;
        delete regla;
    }
}
/** \brief Nueva Regla
 *
 * \param
 * \param
 * \return
 *
 */
void L_system::agregar_regla(std::string _simbolo, std::string _produccion)
{
    return;
    /*
    Regla nueva;
    Regla *ultima = NULL;
    nueva.produccion = _produccion;
    nueva.simbolo = _simbolo;
    nueva.siguiente = NULL;
    if(m_reglas == NULL) m_reglas = &nueva; //Agregamos la regla a m_reglas
    else{
        ultima = m_reglas;
        while(ultima->siguiente != NULL) ultima = ultima->siguiente;
        ultima->siguiente = &nueva;
    }
    */
    // std::cout << "Regla " << nueva.simbolo << " -> " << nueva.produccion << " guardada.\n";
}
/** \brief Busca la regla para el simbolo dado y regresa la produccion
 *
 * \param simbolo a buscar en la lista de reglas
 * \param
 * \return produccion para el simbolo dado
 *
 */
std::string L_system::regla(std::string _simbolo)
{
    Regla* regla;
    regla = m_reglas; //Empezamos en el principio

    while(regla != NULL){// Mientras existan reglas
        if(regla->simbolo.compare(_simbolo) == EQUAL) return regla->produccion;
        else regla = regla->siguiente;
    }
    return _simbolo; // Si la regla no se encontro se utiliza la propiedad que todo simbolo puede ser sustituido por si mismo
}
/** \brief Aplica la regla al simbolo dado
 *
 * \param
 * \param
 * \return
 *
 */
std::string L_system::aplicar_reglas(unsigned int _n)
{
    for(unsigned int k = 0 ; k < _n ; ++k){
        std::string nueva_cadena ("");
        for(unsigned int i = 0 ; i < m_cadena.length() ; ++i){
            i++;
            //nueva_cadena = nueva_cadena + regla(m_cadena[i]);
        }
        m_cadena = nueva_cadena;
    }
    return m_cadena;
}
/*
void FRACTAL::test()
{
    int x,y,length,angle;
    x=getmaxx()/2;
	y=getmaxy();


	//setcolor(GREEN);


        Call drawTree with
            1. x position
            2. y position
            3. length of bark
            4. Angle of deviation
            5. angle of tree
            6. level of recursion

    drawTree(x,y,length,angle,0,13);
}
*/
void drawTree(int x,int y,int length, int angle, int arg,int n)
{
    int x1,y1;

    if(n>0)
    {
        // change the x1 and x2 as
        // x1 = x - length * sin(angle of tree)
        // y1 = y -  length * cos(angle pf tree)
        x1=(int)(x-length*sin(arg*M_PI/180));
        y1=(int)(y-length*cos(arg*M_PI/180));

        // Draw the line
        line(x,y,x1,y1);

        // Recursive function calls
        /*
            call with
            1. new x value. i.e. x1
            2. new y value. i.e. y1
            3. reduced length of bark
            4. angle of barks
            5. new angle of tree
            6. reduced recursion level
        */

        // RHS call
        drawTree(x1,y1,(int)(0.8*length),angle,arg+angle,n-1);

        // LHS call
        drawTree(x1,y1,(int)(0.8*length),angle,arg-angle,n-1);
    }
}
