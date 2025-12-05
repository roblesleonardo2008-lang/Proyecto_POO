#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Fecha.h"
#include "Ubicacion.h"
#include "Bodega.h"
#include "Decoraciones.h"
#include "Herramientas.h"
#include "Almacenamiento.h"

Fecha::Fecha() : dia(0), mes(0) {}
Fecha::Fecha(int dia, int mes) : dia(dia), mes(mes) {}
int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
void Fecha::setDia(int dia) { this->dia = dia; }
void Fecha::setMes(int mes) { this->mes = mes; }

Ubicacion::Ubicacion() : altura(0), profundidad(0) {}
Ubicacion::Ubicacion(int altura, int profundidad)
        : altura(altura), profundidad(profundidad) {}
int Ubicacion::getAltura() const { return altura; }
int Ubicacion::getProfundidad() const { return profundidad; }
void Ubicacion::setAltura(int altura) { this->altura = altura; }
void Ubicacion::setProfundidad(int profundidad) { this->profundidad = profundidad; }

Bodega::Bodega()
        : ubicacion(), ultimoUso(), tamaño(""), dureza(""),
          descompuesto(false), cantidad(0),nombre("") {}
Bodega::Bodega(const Ubicacion& ubic, const Fecha& fecha,
               const string& tamaño, const string& dureza,
               bool descompuesto, int cantidad,string nombre)
        : ubicacion(ubic), ultimoUso(fecha), tamaño(tamaño), dureza(dureza),
          descompuesto(descompuesto), cantidad(cantidad),nombre(nombre) {}
Ubicacion Bodega::getUbicacion() const { return ubicacion; }
string Bodega::getNombre() const { return nombre; }
Fecha Bodega::getUltimoUso() const { return ultimoUso; }
string Bodega::getTamaño() const { return tamaño; }
string Bodega::getDureza() const { return dureza; }
bool Bodega::getDescompuesto() const { return descompuesto; }
int Bodega::getCantidad() const { return cantidad; }
void Bodega::setUbicacion(const Ubicacion& ubic) { ubicacion = ubic; }
void Bodega::setUltimoUso(const Fecha& fecha) { ultimoUso = fecha; }
void Bodega::setCantidad(int cantidad) { this->cantidad = cantidad; }

Decoraciones::Decoraciones()
        : Bodega(), tipo(""), externa(false), electrica(false) {}
Decoraciones::Decoraciones(const Ubicacion& ubic, const Fecha& fecha,
                           const string& tamaño, const string& dureza,
                           bool descompuesto, int cantidad,string nombre,
                           const string& tipo, bool externa, bool electrica)
        : Bodega(ubic, fecha, tamaño, dureza, descompuesto, cantidad,nombre),
          tipo(tipo), externa(externa), electrica(electrica) {}

void Decoraciones::VisualizarInf() const {
    Ubicacion u=Bodega::getUbicacion();
    Fecha m=Bodega::getUltimoUso();
    cout <<"nombre : "<<getNombre()<<endl;
    cout<<"cantidad : "<<getCantidad()<<endl;
    cout<<"Ubicacion alto: " << u.getAltura()<<" profundo : "<<u.getProfundidad()<<endl;
    cout << "Ultima vez modificado día : "<<m.getDia()<<" mes : "<<m.getMes()<<endl;
    cout<<"Tamaño : "<<getTamaño()<<endl;
    cout<<"Dureza : "<<getDureza()<<endl;
    cout<<"Estado : "<<getDescompuesto()<<endl;
    cout << "Temporada: " << tipo << endl;
    cout << "Externa: " << (externa ? "Sí" : "No") << endl;
    cout << "Eléctrica: " << (electrica ? "Sí" : "No") << endl;
    cout << "Cantidad: " << cantidad << endl;
}
void Decoraciones::MenuSecundario() const{
    cout << "MENU DECORACIONES"<<endl;
    cout << "1 - Crear objeto"<<endl;
    cout << "2 - Buscar objeto"<<endl;
    cout << "3 - Ver lista"<<endl;
    cout << "4 - Modificar objeto(busca por nombre)"<<endl;
    cout << "5 - regresar"<<endl;
}
void Decoraciones::CrearObjetos() {
    int altura, profundidad;
    int dia, mes;
    string tamaño, dureza,nombre;
    bool descompuesto;
    int cantidad;
    cout << "Nombre del objeto: ";
    cin >> nombre;
    cout << "Altura de la ubicación: ";
    cin >> altura;
    cout << "Profundidad de la ubicación: ";
    cin >> profundidad;
    cout << "Día del último uso: ";
    cin >> dia;
    cout << "Mes del último uso: ";
    cin >> mes;
    cout << "Tamaño: ";
    cin >> tamaño;
    cout << "Dureza: ";
    cin >> dureza;
    cout << "¿Está descompuesta? (1 = sí, 0 = no): ";
    cin >> descompuesto;
    cout << "Cantidad: ";
    cin >> cantidad;
    cout << "Temporada de decoración: ";
    cin >> tipo;
    cout << "¿Es externa? (1 = sí, 0 = no): ";
    cin >> externa;
    cout << "¿Es eléctrica? (1 = sí, 0 = no): ";
    cin >> electrica;
    Ubicacion u(altura, profundidad);
    Fecha f(dia, mes);
    *this = Decoraciones(u, f, tamaño, dureza,
                         descompuesto, cantidad,nombre,
                         tipo, externa, electrica);
}
void Decoraciones::BuscarObjeto(const vector<Decoraciones>& lista) const {
    string buscado;
    cout << "Ingresa el nombre de la decoración: ";
    cin >> buscado;
    bool encontrado = false;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == buscado) {
            cout << "Decoración encontrada"<<endl;
            lista[i].VisualizarInf();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontró ninguna decoración con ese nombre"<<endl;
    }
}
void Decoraciones:: LeerLista(const vector<Decoraciones>& lista)const{
    cout << "LISTA DE DECORACIONES"<<endl;
    for (size_t i = 0; i < lista.size(); i++) {
        cout << "Objeto #" << (i + 1) << endl;
        cout << "Nombre: " << lista[i].getNombre() << endl;
        cout << "Cantidad: " << lista[i].getCantidad() << endl;
        Ubicacion u = lista[i].getUbicacion();
        cout << "Ubicación -> Altura: " << u.getAltura()<< ", Profundidad: " << u.getProfundidad() << endl;
        Fecha f = lista[i].getUltimoUso();
        cout << "Último uso -> " << f.getDia() << "/" << f.getMes() << endl;
    }
}
void Decoraciones::ModificarObjeto(vector<Decoraciones>& lista) {
    string buscado;
    int N_Cantidad = 1,N_Profundidad =1 ,N_Altura = 1,N_Dia,N_Mes,cambio;
    cout << "Ingresa el nombre de la decoración a modificar: ";
    cin >> buscado;
    int indice = -1;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == buscado) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        cout << "No se encontró la decoración"<<endl;
        return;
    }
    cout<<"Cambiar posición(1), cantidad(2) o ambos(3): ";
    cin>>cambio;
    if (cambio==1||cambio==3){
        cout<<"Inserta la nueva altura : ";
        cin>>N_Altura;
        cout<<"Inserta la nueva profundidad : ";
        cin>>N_Profundidad;
        Ubicacion m = lista[indice].getUbicacion();
        m.setAltura(N_Altura);
        m.setProfundidad(N_Profundidad);
        lista[indice].setUbicacion(m);
    }
    if (cambio==2||cambio==3){
        cout<<"inserta la nueva cantidad : ";
        cin>>N_Cantidad;
        lista[indice].setCantidad(N_Cantidad);
    }
    cout << "Ingresa el día : ";
    cin >> N_Dia;
    cout << "Ingresa el mes : ";
    cin >> N_Mes;
    Fecha m = lista[indice].getUltimoUso();
    m.setDia(N_Dia);
    m.setMes(N_Mes);
    lista[indice].setUltimoUso(m);
    if(N_Cantidad<=0){
        lista.erase(lista.begin() + indice);
    }
}

Herramientas::Herramientas()
        : Bodega(), electricas(false), funcion(""), especificaciones("") {}
Herramientas::Herramientas(const Ubicacion& ubic, const Fecha& fecha,
                           const string& tamaño, const string& dureza,
                           bool descompuesto, int cantidad,string nombre,
                           bool electricas, const string& funcion,
                           const string& especificaciones)
        : Bodega(ubic, fecha, tamaño, dureza, descompuesto, cantidad,nombre),
          electricas(electricas), funcion(funcion), especificaciones(especificaciones) {}
void Herramientas::VisualizarInf() const {
    Ubicacion u=Bodega::getUbicacion();
    Fecha m=Bodega::getUltimoUso();
    cout <<"nombre : "<<getNombre()<<endl;
    cout<<"cantidad : "<<getCantidad()<<endl;
    cout<<"Ubicacion alto: " << u.getAltura()<<" profundo : "<<u.getProfundidad()<<endl;
    cout << "Ultima vez modificado día : "<<m.getDia()<<" mes : "<<m.getMes()<<endl;
    cout<<"Tamaño : "<<getTamaño()<<endl;
    cout<<"Dureza : "<<getDureza()<<endl;
    cout<<"Estado : "<<getDescompuesto()<<endl;
    cout << "Eléctrica: " << (electricas? "Sí" : "No")<< endl;
    cout << "Externa: " << funcion << endl;
    cout << "Cantidad: " << especificaciones << endl;
    cout << "Cantidad: " << cantidad << endl;
}
void Herramientas::MenuSecundario() const{
    cout << "MENU HERRAMIENTAS"<<endl;
    cout << "1 - Crear objeto"<<endl;
    cout << "2 - Buscar objeto"<<endl;
    cout << "3 - Ver lista"<<endl;
    cout << "4 - Modificar objeto(busca por nombre)"<<endl;
    cout << "5 - regresar"<<endl;
}
void Herramientas::CrearObjetos() {
    int altura, profundidad;
    int dia, mes;
    string tamaño, dureza,nombre;
    bool descompuesto;
    int cantidad;
    cout << "Nombre del objeto: ";
    cin >> nombre;
    cout << "Altura de la ubicación: ";
    cin >> altura;
    cout << "Profundidad de la ubicación: ";
    cin >> profundidad;
    cout << "Día del último uso: ";
    cin >> dia;
    cout << "Mes del último uso: ";
    cin >> mes;
    cout << "Tamaño: ";
    cin >> tamaño;
    cout << "Dureza: ";
    cin >> dureza;
    cout << "¿Está descompuesta? (1 = sí, 0 = no): ";
    cin >> descompuesto;
    cout << "Cantidad: ";
    cin >> cantidad;
    cout << "¿Es Eléctrica? (1 = sí, 0 = no): ";
    cin >> electricas;
    cout << "Función:";
    cin >> funcion;
    cout << "Especificaciones: ";
    cin >> especificaciones;
    Ubicacion u(altura, profundidad);
    Fecha f(dia, mes);
    *this = Herramientas(u, f, tamaño, dureza,
                         descompuesto, cantidad,nombre,
                         electricas, funcion, especificaciones);
}
void Herramientas::BuscarObjeto(const vector<Herramientas>& lista) const {
    string buscado;
    cout << "Ingresa el nombre de la Herramienta: ";
    cin >> buscado;
    bool encontrado = false;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == buscado) {
            cout << "Herramienta encontrada"<<endl;
            lista[i].VisualizarInf();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontró ninguna herramienta con ese nombre"<<endl;
    }
}
void Herramientas:: LeerLista(const vector<Herramientas>& lista)const{
    cout << "LISTA DE HERRAMIENTAS"<<endl;
    for (size_t i = 0; i < lista.size(); i++) {
        cout << "Objeto #" << (i + 1) << endl;
        cout << "Nombre: " << lista[i].getNombre() << endl;
        cout << "Cantidad: " << lista[i].getCantidad() << endl;
        Ubicacion u = lista[i].getUbicacion();
        cout << "Ubicación -> Altura: " << u.getAltura()<< ", Profundidad: " << u.getProfundidad() << endl;
        Fecha f = lista[i].getUltimoUso();
        cout << "Último uso -> " << f.getDia() << "/" << f.getMes() << endl;
    }
}
void Herramientas::ModificarObjeto(vector<Herramientas>& lista) {
    string buscado;
    int N_Cantidad = 1,N_Profundidad =1 ,N_Altura = 1,N_Dia,N_Mes,cambio;
    cout << "Ingresa el nombre de la herramienta a modificar: ";
    cin >> buscado;
    int indice = -1;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == buscado) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        cout << "No se encontró la herramienta"<<endl;
        return;
    }
    cout<<"Cambiar posición(1), cantidad(2) o ambos(3): ";
    cin>>cambio;
    if (cambio==1||cambio==3){
        cout<<"Inserta la nueva altura : ";
        cin>>N_Altura;
        cout<<"Inserta la nueva profundidad : ";
        cin>>N_Profundidad;
        Ubicacion m = lista[indice].getUbicacion();
        m.setAltura(N_Altura);
        m.setProfundidad(N_Profundidad);
        lista[indice].setUbicacion(m);
    }
    if (cambio==2||cambio==3){
        cout<<"inserta la nueva cantidad : ";
        cin>>N_Cantidad;
        lista[indice].setCantidad(N_Cantidad);
    }
    cout << "Ingresa el día : ";
    cin >> N_Dia;
    cout << "Ingresa el mes : ";
    cin >> N_Mes;
    Fecha m = lista[indice].getUltimoUso();
    m.setDia(N_Dia);
    m.setMes(N_Mes);
    lista[indice].setUltimoUso(m);
    if(N_Cantidad<=0){
        lista.erase(lista.begin() + indice);
    }
}

Almacenamiento::Almacenamiento()
        : Bodega(), tipo(""), digital(false), contenido("") {}
Almacenamiento::Almacenamiento(const Ubicacion& ubic, const Fecha& fecha,
                               const string& tamaño, const string& dureza,
                               bool descompuesto, int cantidad,string nombre,
                               const string& tipo, bool digital,
                               const string& contenido)
        : Bodega(ubic, fecha, tamaño, dureza, descompuesto, cantidad,nombre),
          tipo(tipo), digital(digital), contenido(contenido) {}
void Almacenamiento::VisualizarInf() const {
    Ubicacion u=Bodega::getUbicacion();
    Fecha m=Bodega::getUltimoUso();
    cout <<"nombre : "<<getNombre()<<endl;
    cout<<"cantidad : "<<getCantidad()<<endl;
    cout<<"Ubicacion alto: " << u.getAltura()<<" profundo : "<<u.getProfundidad()<<endl;
    cout << "Ultima vez modificado día : "<<m.getDia()<<" mes : "<<m.getMes()<<endl;
    cout<<"Tamaño : "<<getTamaño()<<endl;
    cout<<"Dureza : "<<getDureza()<<endl;
    cout<<"Estado : "<<getDescompuesto()<<endl;
    cout << "Digital: " << (digital? "Sí" : "No")<< endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Contenido " << contenido << endl;
    cout << "Cantidad: " << cantidad << endl;
}
void Almacenamiento::MenuSecundario() const{
    cout << "MENU ALMACENAMINETO"<<endl;
    cout << "1 - Crear objeto"<<endl;
    cout << "2 - Buscar objeto"<<endl;
    cout << "3 - Ver lista"<<endl;
    cout << "4 - Modificar objeto(busca por nombre)"<<endl;
    cout << "5 - regresar"<<endl;
}
void Almacenamiento::CrearObjetos() {
    int altura, profundidad;
    int dia, mes;
    string tamaño, dureza,nombre;
    bool descompuesto;
    int cantidad;
    cout << "Nombre del objeto: ";
    cin >> nombre;
    cout << "Altura de la ubicación: ";
    cin >> altura;
    cout << "Profundidad de la ubicación: ";
    cin >> profundidad;
    cout << "Día del último uso: ";
    cin >> dia;
    cout << "Mes del último uso: ";
    cin >> mes;
    cout << "Tamaño: ";
    cin >> tamaño;
    cout << "Dureza: ";
    cin >> dureza;
    cout << "¿Está descompuesto? (1 = sí, 0 = no): ";
    cin >> descompuesto;
    cout << "Cantidad: ";
    cin >> cantidad;
    cout << "¿Es digital? (1 = sí, 0 = no): ";
    cin >> digital;
    cout << "Tipo de almacenamiento:";
    cin >> tipo;
    cout << "Contenido: ";
    cin >> contenido;
    Ubicacion u(altura, profundidad);
    Fecha f(dia, mes);
    *this = Almacenamiento(u, f, tamaño, dureza,
                           descompuesto, cantidad,nombre,
                           tipo,digital,contenido);
}
void Almacenamiento::BuscarObjeto(const vector<Almacenamiento>& lista) const {
    string buscado;
    cout << "Ingresa el nombre del Almacenamiento: ";
    cin >> buscado;
    bool encontrado = false;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == buscado) {
            cout << "Almacenamiento encontrada"<<endl;
            lista[i].VisualizarInf();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontró ningun Almacenamiento con ese nombre"<<endl;
    }
}
void Almacenamiento:: LeerLista(const vector<Almacenamiento>& lista)const{
    cout << "LISTA DE ALMACENAMIENTOS"<<endl;
    for (size_t i = 0; i < lista.size(); i++) {
        cout << "Objeto #" << (i + 1) << endl;
        cout << "Nombre: " << lista[i].getNombre() << endl;
        cout << "Cantidad: " << lista[i].getCantidad() << endl;
        Ubicacion u = lista[i].getUbicacion();
        cout << "Ubicación -> Altura: " << u.getAltura()<< ", Profundidad: " << u.getProfundidad() << endl;
        Fecha f = lista[i].getUltimoUso();
        cout << "Último uso -> " << f.getDia() << "/" << f.getMes() << endl;
    }
}
void Almacenamiento::ModificarObjeto(vector<Almacenamiento>& lista) {
    string buscado;
    int N_Cantidad = 1,N_Profundidad =1 ,N_Altura = 1,N_Dia,N_Mes,cambio;
    cout << "Ingresa el nombre del almacenamiento a modificar: ";
    cin >> buscado;
    int indice = -1;
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == buscado) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        cout << "No se encontró el almacenamiento"<<endl;
        return;
    }
    cout<<"Cambiar posición(1), cantidad(2) o ambos(3): ";
    cin>>cambio;
    if (cambio==1||cambio==3){
        cout<<"Inserta la nueva altura : ";
        cin>>N_Altura;
        cout<<"Inserta la nueva profundidad : ";
        cin>>N_Profundidad;
        Ubicacion m = lista[indice].getUbicacion();
        m.setAltura(N_Altura);
        m.setProfundidad(N_Profundidad);
        lista[indice].setUbicacion(m);
    }
    if (cambio==2||cambio==3){
        cout<<"inserta la nueva cantidad : ";
        cin>>N_Cantidad;
        lista[indice].setCantidad(N_Cantidad);
    }
    cout << "Ingresa el día : ";
    cin >> N_Dia;
    cout << "Ingresa el mes : ";
    cin >> N_Mes;
    Fecha m = lista[indice].getUltimoUso();
    m.setDia(N_Dia);
    m.setMes(N_Mes);
    lista[indice].setUltimoUso(m);
    if(N_Cantidad<=0){
        lista.erase(lista.begin() + indice);
    }
}


int main() {
    vector<Decoraciones> listaDecoraciones;
    vector<Herramientas> listaHerramientas;
    vector<Almacenamiento> listaAlmacenamiento;
    Decoraciones arbolNavidad(
            Ubicacion(0,10), Fecha(1,12), "Grande", "rígido", false, 1, "Arbol de Navidad",
            "Navidad", true, false
    );
    Decoraciones arañaHalloween(
            Ubicacion(2,2), Fecha(31,10), "Mediana", "Media", false, 4, "Araña Halloween",
            "Halloween", false, false
    );
    Herramientas martillo(
            Ubicacion(3,1), Fecha(10,5), "Pequeño", "Duro", false, 1, "Martillo",
            false, "Golpear", "Uso general"
    );
    Herramientas bombaAire(
            Ubicacion(0,4), Fecha(15,7), "Mediana", "Media", true, 1, "Bomba de Aire",
            false, "Inflar", "Para neumáticos"
    );
    Almacenamiento libro(
            Ubicacion(3,1), Fecha(22,10), "Pequeño", "suave", false, 15, "Libro",
            "Datos", false, "Varios poemas de Pablo Neruda"
    );
    Almacenamiento maleta(
            Ubicacion(2,3), Fecha(5,6), "Grande", "Media", true, 1, "Maleta",
            "Fisico", false, "Ropa de viaje"
    );
    listaDecoraciones.push_back(arbolNavidad);
    listaDecoraciones.push_back(arañaHalloween);
    listaHerramientas.push_back(martillo);
    listaHerramientas.push_back(bombaAire);
    listaAlmacenamiento.push_back(libro);
    listaAlmacenamiento.push_back(maleta);
    int option;
    do {
        cout << "Bienvenido a tu Bodega doméstica" << endl;
        cout << "Elige a que sección queres acceder" << endl;
        cout << "1 - Decoraciones" << endl;
        cout << "2 - Herramientas" << endl;
        cout << "3 - Almacenamiento" << endl;
        cout << "4 - Salir" << endl;
        cin >> option;
        switch (option) {
            case 1: {
                int opcionD = 0;
                Decoraciones temp;
                do {
                    temp.MenuSecundario();
                    cin >> opcionD;
                    switch (opcionD) {
                        case 1: {
                            Decoraciones nuevo;
                            nuevo.CrearObjetos();
                            listaDecoraciones.push_back(nuevo);
                            break;
                        }
                        case 2:
                            temp.BuscarObjeto(listaDecoraciones);
                            break;
                        case 3:
                            temp.LeerLista(listaDecoraciones);
                            break;
                        case 4:
                            temp.ModificarObjeto(listaDecoraciones);
                            break;
                        case 5:
                            cout << "Regresando al menú principal" << endl;
                            break;
                        default:
                            cout << "Opción inválida" << endl;
                    }
                } while (opcionD != 5);
                break;
            }

            case 2: {
                int opcionH = 0;
                Herramientas temp;
                do {
                    temp.MenuSecundario();
                    cin >> opcionH;
                    switch (opcionH) {
                        case 1: {
                            Herramientas nuevo;
                            nuevo.CrearObjetos();
                            listaHerramientas.push_back(nuevo);
                            break;
                        }
                        case 2:
                            temp.BuscarObjeto(listaHerramientas);
                            break;
                        case 3:
                            temp.LeerLista(listaHerramientas);
                            break;
                        case 4:
                            temp.ModificarObjeto(listaHerramientas);
                            break;
                        case 5:
                            cout << "Regresando al menú principal" << endl;
                            break;
                        default:
                            cout << "Opción inválida" << endl;
                    }
                } while (opcionH != 5);
                break;
            }
            case 3:{
                int opcionA = 0;
                Almacenamiento temp;
                do {
                    temp.MenuSecundario();
                    cin >> opcionA;
                    switch (opcionA) {
                        case 1: {
                            Almacenamiento nuevo;
                            nuevo.CrearObjetos();
                            listaAlmacenamiento.push_back(nuevo);
                            break;
                        }
                        case 2:
                            temp.BuscarObjeto(listaAlmacenamiento);
                            break;
                        case 3:
                            temp.LeerLista(listaAlmacenamiento);
                            break;
                        case 4:
                            temp.ModificarObjeto(listaAlmacenamiento);
                            break;
                        case 5:
                            cout << "Regresando al menú principal" << endl;
                            break;
                        default:
                            cout << "Opción inválida" << endl;
                    }
                } while (opcionA != 5);
                break;
            }
            case 4:
                cout << "Saliendo" << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (option != 4);
}



