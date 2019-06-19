#ifndef FRACTAL_H
#define FRACTAL_H

#include <cstring>
#include <graphics.h>
#include <math.h>
/*
    Fractales generados a partir de L-system
    Implementacion en C++
    Para la creacion de Fractales, se utilizara L-system, que son un modelo de reescritura paralelo
    y un tipo de gramatica formal.
*/

struct Regla{
    /**
        Regla de produccion
    */
    std::string simbolo, produccion;
    Regla* siguiente; // Simulamos una lista de reglas
};

class L_system // Basados en L-system
{
    /**
        Docs
    */
    public:
        /*
            Todos los fractales tienen un grado y una axioma base para ser generados
        */
        L_system();
        L_system(std::string _axioma);

        virtual ~L_system();
        // Axioma
        std::string axioma() { return m_axioma; }
        void set_axioma(std::string _val) { m_axioma = _val; }
        std::string cadena() { return m_cadena; }
        // Agrega una nueva regla en el conjunto de reglas
        void agregar_regla(std::string _simbolo, std::string _produccion);
        // Regresa la regla para el simbolo dado
        std::string regla(std::string _simbolo);
        Regla* regla() { return m_reglas; }
        // Aplica las reglas una cantidad n veces
        std::string aplicar_reglas(unsigned int _n);

        static void test(); // testing a L-system

    protected: // Vamos a heredar
        std::string m_axioma; // Axioma inicial
        // std::string m_alfabeto; // Lista de simbolos utilizados en la cadena
        Regla* m_reglas; // Producciones para crear el sistema L-system
        std::string m_cadena; // Resultado final
    private:


};
/** \brief Fractal Tree,
 *
 * \param
 * \param
 * \return
 *
 */
void drawTree(int x,int y,int length, int angle, int arg,int n);
#endif // FRACTAL_H
