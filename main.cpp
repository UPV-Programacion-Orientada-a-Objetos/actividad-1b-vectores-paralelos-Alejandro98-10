#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS = 100;
int totalProductos = 5; 

int codigos[MAX_PRODUCTOS];
string nombres[MAX_PRODUCTOS];
int stock[MAX_PRODUCTOS];
float precios[MAX_PRODUCTOS];

void cargarDatosIniciales() {
    codigos[0] = 101; nombres[0] = "Martillo"; stock[0] = 15; precios[0] = 120.50;
    codigos[1] = 102; nombres[1] = "Destornillador"; stock[1] = 30; precios[1] = 45.75;
    codigos[2] = 103; nombres[2] = "Taladro"; stock[2] = 10; precios[2] = 950.00;
    codigos[3] = 104; nombres[3] = "Sierra"; stock[3] = 8; precios[3] = 350.90;
    codigos[4] = 105; nombres[4] = "Llave Inglesa"; stock[4] = 20; precios[4] = 80.00;
}

int buscarProducto(int codigo) {
    for (int i = 0; i < totalProductos; i++) {
        if (codigos[i] == codigo) {
            return i;
        }
    }
    return -1; 
}

void consultarProducto() {
    int codigo;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;

    int pos = buscarProducto(codigo);
    if (pos == -1) {
        cout << "❌ Error: Producto no encontrado.\n";
    } else {
        cout << "✅ Producto encontrado:\n";
        cout << "Codigo: " << codigos[pos] << endl;
        cout << "Nombre: " << nombres[pos] << endl;
        cout << "Stock: " << stock[pos] << endl;
        cout << "Precio: $" << precios[pos] << endl;
    }
}

void actualizarInventario() {
    int codigo, cantidad;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;

    int pos = buscarProducto(codigo);
    if (pos == -1) {
        cout << "❌ Error: Producto no encontrado.\n";
    } else {
        cout << "Ingrese la cantidad a modificar (positiva o negativa): ";
        cin >> cantidad;

        if (stock[pos] + cantidad < 0) {
            cout << "❌ Error: No puede haber stock negativo.\n";
        } else {
            stock[pos] += cantidad;
            cout << "✅ Stock actualizado. Nuevo stock: " << stock[pos] << endl;
        }
    }
}

void generarReporte() {
    cout << "\n📋 Reporte de Inventario:\n";
    cout << "---------------------------------------------\n";
    cout << "Codigo\tNombre\t\tStock\tPrecio\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << codigos[i] << "\t" 
             << nombres[i] << "\t\t" 
             << stock[i] << "\t" 
             << "$" << precios[i] << endl;
    }
    cout << "---------------------------------------------\n";
}

void productoMasCaro() {
    int posMax = 0;
    for (int i = 1; i < totalProductos; i++) {
        if (precios[i] > precios[posMax]) {
            posMax = i;
        }
    }
    cout << "\n💰 Producto más caro:\n";
    cout << "Nombre: " << nombres[posMax] << endl;
    cout << "Precio: $" << precios[posMax] << endl;
}

void mostrarMenu() {
    int opcion;
    do {
        cout << "\n=== Sistema de Inventario - Ferreteria 'El Martillo' ===\n";
        cout << "1. Consultar producto\n";
        cout << "2. Actualizar inventario\n";
        cout << "3. Generar reporte\n";
        cout << "4. Buscar producto mas caro\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: consultarProducto(); break;
            case 2: actualizarInventario(); break;
            case 3: generarReporte(); break;
            case 4: productoMasCaro(); break;
            case 0: cout << "Saliendo del sistema...\n"; break;
            default: cout << "❌ Opcion invalida.\n";
        }
    } while (opcion != 0);
}

int main() {
    cargarDatosIniciales();
    mostrarMenu();
    return 0;
}

