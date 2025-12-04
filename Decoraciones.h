#ifndef DECORACIONES_H
#define DECORACIONES_H
#include <iostream>
using namespace std;
#include "Bodega.h"
class Decoraciones : public Bodega {
private:
    string tipo;
    bool externa;
    bool electrica;
public:
    Decoraciones();
    Decoraciones(const Ubicacion& ubic, const Fecha& fecha,
                 const string& tamaño, const string& dureza,
                 bool descompuesto, int cantidad,string nombre,
                 const string& tipo, bool externa, bool electrica);
    void VisualizarInf() const;
    void MenuSecundario()const;
    void CrearObjetos();
    void BuscarObjeto(const vector<Decoraciones>& lista) const;
    void LeerLista(const vector<Decoraciones>& lista)const;
    void ModificarObjeto(vector<Decoraciones>&lista);
};
#endif
