#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Prototipos de las funciones
void imprimirMemoria(const vector<int>& memoria);
void siguienteAjuste(vector<int>& memoria, int proceso, int& ultimaPos);
void mejorAjuste(vector<int>& memoria, int proceso);
void peorAjuste(vector<int>& memoria, int proceso);
void ajusteRapido(vector<int>& memoria, int proceso);



#endif // MEMORIA_H_INCLUDED
