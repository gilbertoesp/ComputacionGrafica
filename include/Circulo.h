#ifndef CIRCULO_H
#define CIRCULO_H


class Circulo
{
    private:
        unsigned int m_radio;
        Punto m_centro;

    public:
        Circulo();
        virtual ~Circulo();

        unsigned int Getradio() { return m_radio; }
        void Setradio(unsigned int val) { m_radio = val; }
        Punto Getcentro() { return m_centro; }
        void Setcentro(Punto val) { m_centro = val; }

        static void test();
};

#endif // CIRCULO_H
