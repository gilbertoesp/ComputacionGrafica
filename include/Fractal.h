#ifndef FRACTAL_H
#define FRACTAL_H


class Fractal
{
    public:
        Fractal();
        virtual ~Fractal();

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

        static void test(); // testing a fractal tree

    protected:

    private:
        unsigned int m_Counter;

};

void drawTree(int x,int y,int length, int angle, int arg,int n);

#endif // FRACTAL_H
