#ifndef UBICACION_H
#define UBICACION_H
#include <iostream>
using namespace std;
class Ubicacion {
private:
    int altura;
    int profundidad;
public:
    Ubicacion();
    Ubicacion(int altura, int profundidad);
    int getAltura() const;
    int getProfundidad() const;
    void setAltura(int altura);
    void setProfundidad(int profundidad);
};
#endif
