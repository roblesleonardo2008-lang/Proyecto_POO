#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H
#include <iostream>
using namespace std;
#include "Bodega.h"
class Herramientas : public Bodega {
private:
    bool electricas;
    string funcion;
    string especificaciones;
public:
    Herramientas();
    Herramientas(const Ubicacion& ubic, const Fecha& fecha,
                 const string& tamaño, const string& dureza,
                 bool descompuesto, int cantidad,string nombre,
                 bool electricas, const string& funcion,
                 const string& especificaciones);
void VisualizarInf() const;
    void MenuSecundario()const;
    void CrearObjetos();
    void BuscarObjeto(const vector<Herramientas>& lista) const;
    void LeerLista(const vector<Herramientas>& lista)const;
    void ModificarObjeto(vector<Herramientas>&lista);
};
#endif
