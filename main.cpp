#include <iostream>
#include "memoria.h"

using namespace std;

int main() {
    vector<int> memoria = {10, 20, 5, 15, 30};
    int ultimaPos = 0; // Para Siguiente Ajuste
    int opcion, proceso;

    while (true) {
        cout << "\nMenu de Algoritmos de Asignacion de Memoria:\n";
        cout << "1. Siguiente Ajuste\n";
        cout << "2. Mejor Ajuste\n";
        cout << "3. Peor Ajuste\n";
        cout << "4. Ajuste Rapido\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 5) {
            cout << "Saliendo del programa...\n";
            break;
        }

        cout << "Ingrese el tamaño del proceso: ";
        cin >> proceso;

        // Copia de la memoria original para cada prueba
        vector<int> memoriaActual = memoria;

        switch (opcion) {
            case 1:
                siguienteAjuste(memoriaActual, proceso, ultimaPos);
                break;
            case 2:
                mejorAjuste(memoriaActual, proceso);
                break;
            case 3:
                peorAjuste(memoriaActual, proceso);
                break;
            case 4:
                ajusteRapido(memoriaActual, proceso);
                break;
            default:

                cout << "Opción no valida. Intente nuevamente.\n";

        }
    }

    return 0;
}
