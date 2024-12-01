#include "memoria.h"

void imprimirMemoria(const vector<int>& memoria) {
    cout << "Estado actual de la memoria: ";
    for (int bloque : memoria) {
        cout << bloque << " ";
    }
    cout << endl;
}

void siguienteAjuste(vector<int>& memoria, int proceso, int& ultimaPos) {
    int n = memoria.size();
    for (int i = 0; i < n; ++i) {
        int idx = (ultimaPos + i) % n;
        if (memoria[idx] >= proceso) {
            memoria[idx] -= proceso;
            ultimaPos = idx;
            cout << "Proceso asignado al bloque de tamaño " << proceso << " en la posición " << idx << endl;
            imprimirMemoria(memoria);
            return;
        }
    }
    cout << "No se encontró un bloque adecuado para el proceso de tamaño " << proceso << endl;
}

void mejorAjuste(vector<int>& memoria, int proceso) {
    int mejorIdx = -1;
    int menorDesperdicio = INT_MAX;
    for (size_t i = 0; i < memoria.size(); ++i) {
        if (memoria[i] >= proceso && (memoria[i] - proceso) < menorDesperdicio) {
            mejorIdx = i;
            menorDesperdicio = memoria[i] - proceso;
        }
    }
    if (mejorIdx != -1) {
        memoria[mejorIdx] -= proceso;
        cout << "Proceso asignado al bloque de tamaño " << proceso << " en la posición " << mejorIdx << endl;
        imprimirMemoria(memoria);
    } else {
        cout << "No se encontró un bloque adecuado para el proceso de tamaño " << proceso << endl;
    }
}

void peorAjuste(vector<int>& memoria, int proceso) {
    int peorIdx = -1;
    int mayorDesperdicio = -1;
    for (size_t i = 0; i < memoria.size(); ++i) {
        if (memoria[i] >= proceso && (memoria[i] - proceso) > mayorDesperdicio) {
            peorIdx = i;
            mayorDesperdicio = memoria[i] - proceso;
        }
    }
    if (peorIdx != -1) {
        memoria[peorIdx] -= proceso;
        cout << "Proceso asignado al bloque de tamaño " << proceso << " en la posición " << peorIdx << endl;
        imprimirMemoria(memoria);
    } else {
        cout << "No se encontró un bloque adecuado para el proceso de tamaño " << proceso << endl;
    }
}

void ajusteRapido(vector<int>& memoria, int proceso) {
    for (size_t i = 0; i < memoria.size(); ++i) {
        if (memoria[i] >= proceso) {
            memoria[i] -= proceso;
            cout << "Proceso asignado al bloque de tamaño " << proceso << " en la posición " << i << endl;
            imprimirMemoria(memoria);
            return;
        }
    }
    cout << "No se encontró un bloque adecuado para el proceso de tamaño " << proceso << endl;
}
