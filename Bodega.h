#ifndef BODEGA_H
#define BODEGA_H
#include <iostream>
using namespace std;
#include "Fecha.h"
#include "Ubicacion.h"
class Bodega {
protected:
    Ubicacion ubicacion;
    Fecha ultimoUso;
    string tamaño;
    string dureza;
    string nombre;
    bool descompuesto;
    int cantidad;
public:
    Bodega();
    Bodega(const Ubicacion& ubic, const Fecha& fecha,
           const string& tamaño, const string& dureza,
           bool descompuesto, int cantidad,string nombre);
    Ubicacion getUbicacion() const;
    Fecha getUltimoUso() const;
    string getNombre() const;
    string getTamaño() const;
    string getDureza() const;
    bool getDescompuesto() const;
    int getCantidad() const;
    void setUbicacion(const Ubicacion& ubic);
    void setUltimoUso(const Fecha& fecha);
    void setCantidad(int cantidad);
    virtual void VisualizarInf() const = 0;
    virtual void MenuSecundario()const = 0;
    virtual void CrearObjetos() = 0;
};
#endif
