#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;
class Fecha {
private:
    int dia;
    int mes;
public:
    Fecha();
    Fecha(int dia, int mes);
    int getDia() const;
    int getMes() const;
    void setDia(int dia);
    void setMes(int mes);
};
#endif
