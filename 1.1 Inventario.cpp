#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Arbol {
    string especie;
    double altura;
};

class InventarioForestal {
private:
    vector<Arbol> arboles;

public:
    void agregarArbol(const Arbol& arbol) {
        arboles.push_back(arbol);
    }


    void mostrarInventario() {
        cout << "Inventario Forestal:\n";
        for (const auto& arbol : arboles) {
            cout << "Especie: " << arbol.especie << ", Altura: " << arbol.altura << "\n";
        }
    }

    void guardarEnArchivo(const string& nombreArchivo) {
        ofstream archivo(nombreArchivo);

        for (const auto& arbol : arboles) {
            archivo << arbol.especie << " " << arbol.altura << "\n";
        }
    }

    void cargarDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo " << nombreArchivo << "\n";
            return;
        }

        Arbol arbol;
        while (archivo >> arbol.especie >> arbol.altura) {
            arboles.push_back(arbol);
        }
    }
};

int main() {
    InventarioForestal inventario;

    inventario.cargarDesdeArchivo("inventario.txt");

    char opcion;
    do {
        cout << "\nMenú:\n";
        cout << "1. Agregar árbol\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Salir\n";
        cout << "Ingrese la opción deseada (1-3): ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                string especie;
                double altura;

                cout << "Ingrese la especie del arbol: ";
                cin >> especie;

                cout << "Ingrese la altura del arbol: ";
                cin >> altura;

                inventario.agregarArbol({especie, altura});
                break;
            }
            case '2':
                inventario.mostrarInventario();
                break;
            case '3':
                inventario.guardarEnArchivo("inventario.txt");
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo.\n";
        }

    } while (opcion != '3');

    return 0;
}
