#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H
#include <iostream>
using namespace std;

#include "Bodega.h"
class Almacenamiento : public Bodega {
private:
    string tipo;
    bool digital;
    string contenido;
public:
    Almacenamiento();
    Almacenamiento(const Ubicacion& ubic, const Fecha& fecha,
                   const string& tamaño, const string& dureza,
                   bool descompuesto, int cantidad,string nombre,
                   const string& tipo, bool digital,
                   const string& contenido);
    void VisualizarInf() const;
    void MenuSecundario()const;
    void CrearObjetos();
    void BuscarObjeto(const vector<Almacenamiento>& lista) const;
    void LeerLista(const vector<Almacenamiento>& lista)const;
    void ModificarObjeto(vector<Almacenamiento>&lista);
};
#endif
