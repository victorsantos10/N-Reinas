/* Titulo: N Reinas 
Equipo      :
Participantes:
Adrian Bastardo        ID : 1105264
Alexa  Guzmán          ID : 1101488
José L.Cruz            ID : 1106529
Eros Bencosme          ID : 1104510
Manuel Mancebo         ID : 1105615
Victo Santos           ID : 1105977
Fecha : 12 / 01 / 2023
Materia :  Estructura de Datos y Algoritmos II
Profesor : Casimiro Gilberto Cordero Ramirez*/


#include <iostream>
#include <math.h>

using namespace std;

int contador = 0; // cuenta la cantidad de soluciones 

bool Comprobacion(int reinas[], int n, int k) {
	int i;
	for (i = 0; i < k; i++) {
		if ((reinas[i] == reinas[k]) or (abs(k-i) == abs(reinas[k]- reinas[i]))) {
			return false;
		}
	}
	return true;
}

void Nreinas(int reinas[], int n, int k) {

	if (k == n) {
		contador++;
		cout << "Solucion Numero " << contador << " : ";
		for (int i = 0; i < n; i++) {
			cout << reinas[i] << " , ";
		}
		cout << endl;
	}
	else {
		for (reinas[k] = 0; reinas[k] < n; reinas[k]++) {
			if (Comprobacion(reinas, n, k)) {
				Nreinas(reinas, n, k + 1);
			}
		}
	}

}

int main()
{
	int k = 0; // nivel del arbol
	int cantidad; // cantidad de Reinas
	cout << "Ingresa la cantidad de Reinas: ";
	cin >> cantidad;

	int* reinas = new int[cantidad];

	for (int i = 0; i < cantidad; i++) {
		reinas[i] = -1;
	}
	Nreinas(reinas, cantidad, k);
}	
