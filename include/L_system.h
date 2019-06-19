#ifndef L_SYSTEM_H
#define L_SYSTEM_H

#include <cstring>
#include <graphics.h>
#include <math.h>
/**
    Estructura que guarda el simbolo y la produccion de una regla del sistema L
    Estilo lista linkeada, guarda un puntero a la siguiente regla
*/
struct Regla{
    std::string simbolo;
    std::string produccion;
    Regla* siguiente;
};

class L_system
{
    public:
        L_system();
        L_system(std::string _axioma);
        virtual ~L_system();
        L_system(const L_system& other);
        L_system& operator=(const L_system& other);

        std::string Get_axioma() { return m_axioma; }
        void Set_axioma(std::string val) { m_axioma = val; }
        std::string Get_cadena() { return m_cadena; }
        void Set_cadena(std::string val) { m_cadena = val; }
        Regla* Get_reglas() { return m_reglas; }
        void Set_reglas(Regla* val) { m_reglas = val; }

        static void test(); // Testing
        /// Agrega regla a la lista linkeada de reglas
        void agregar_regla(std::string _simbolo, std::string _produccion);
        /// Regresa la produccion para el simbolo
        std::string regla(std::string _simbolo);
        /// Aplica las producciones una cantidad n de veces.
        void aplicar_reglas(int n);

    private:
        std::string m_axioma; // axioma inicial del sistema
        std::string m_cadena; // cadena generada por el sistema
        Regla* m_reglas; // reglas para los cimbolos de las producciones
};

#endif // L_SYSTEM_H
