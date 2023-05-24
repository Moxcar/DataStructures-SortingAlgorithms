#include "LibreriaED.h"

using namespace std;

int main()
{
	int a,b;
	do {
		system("cls");
		cout << "Selecciona una opcion" << endl;
		cout << "1 Para entrar a estructuras de datos" << endl;
		cout << "2 Para entrar a metodos de ordenacion" << endl;
		cout << "3 Para entrar a metodos de busqueda" << endl;
		cout << "4 Para entrar a programas de recursividad y punteros" << endl;
		cout << "5 Para entrar al arbol de busqueda binaria" << endl;
		cout << "6 Para entrar al grafo" << endl;
		cout << "s Para salir" << endl;
		a = _getch();
		system("cls");
		switch (a)
		{
		case '1':
			do {
				cout << "Menu estructuras de datos" << endl;
				cout << "Selecciona una opcion" << endl;
				cout << "1 Para lista simple" << endl;
				cout << "2 Para tabla hash" << endl;
				cout << "3 Para cola" << endl;
				cout << "4 Para lista circular" << endl;
				cout << "5 Para lista circular doble" << endl;
				cout << "6 Para lista doble" << endl;
				cout << "7 Para pila" << endl;
				cout << "s para salir" << endl;
				b = _getch();
				switch (b)
				{
				case '1':
					estructurasDeDatos::listaSimple::mainLista();
					break;
				case '2':
					estructurasDeDatos::tablaHash::mainTH();
					break;
				case '3':
					estructurasDeDatos::cola::mainCola();
					break;
				case '4':
					estructurasDeDatos::listaCircular::mainListaCircular();
					break;
				case '5':
					estructurasDeDatos::listaCircularDoble::mainListaCircularDoble();
					break;
				case '6':
					estructurasDeDatos::listaDoble::mainListaDoble();
					break;
				case '7':
					estructurasDeDatos::pila::mainPila();
					break;
				}
			} while (b != 's');
			break;
		case '2':
			do {
				cout << "Metodos de ordenacion" << endl;
				cout << "1 Para entrar a merge" << endl;
				cout << "2 Para entrar a radix" << endl;
				cout << "3 Para entrar a seleccion" << endl;
				cout << "4 Para entrar a shell" << endl;
				cout << "5 Para entrar a quicksort" << endl;
				cout << "6 Para entrar a insercion" << endl;
				cout << "7 Para entrar a burbuja" << endl;
				cout << "s para salir" << endl;
				b = _getch();
				switch (b)
				{
				case '1':
					metodosOrdenacion::merge::mainMerge();
					break;
				case '2':
					metodosOrdenacion::radix::mainRadix();
					break;
				case '3':
					metodosOrdenacion::seleccion::mainSeleccion();
					break;
				case '4':
					metodosOrdenacion::shell::mainShell();
					break;
				case '5':
					metodosOrdenacion::quickSort::mainQuickSort();
					break;
				case '6':
					metodosOrdenacion::insercion::mainInsercion();
					break;
				case '7':
					metodosOrdenacion::burbuja::mainBurbuja();
					break;
				}
			} while (b != 's');
			break;
		case '3':
			do {
				cout << "Metodos de busqueda" << endl;
				cout << "1 Para entrar a busqueda secuencial" << endl;
				cout << "2 Para entrar a busqueda binaria" << endl;
				cout << "s para salir" << endl;
				b = _getch();
				switch (b)
				{
				case '1':
					metodosBusqueda::secuencial::mainSecuencial();
					break;
				case '2':
					metodosBusqueda::binaria::mainBinaria();
					break;
				}
			} while (b != 's');
			break;
		case '4':
			do {
				cout << "Recursividad y punteros" << endl;
				cout << "1 Para entrar a multiplicacion y division" << endl;
				cout << "2 Para entrar a matrices" << endl;
				cout << "3 Para entrar a funcion de busqueda para estructura" << endl;
				b = _getch();
				switch (b)
				{
				case '1':
					programasRecursividadYPunteros::multiplicacionDivision::mainMultiDivi();
					break;
				case '2':
					programasRecursividadYPunteros::matrices::mainMatrices();
					break;
				case '3':
					programasRecursividadYPunteros::funcionDeBusquedaParaEstructura::mainFuncion();
					break;
				}
			} while (b != 's');
			break;
		case '5':
			arbolDeBusquedaBinaria::mainArbolBB();
			break;
		case '6':
			grafo::mainGrafo();
			break;
		}
	} while (a != 's');

}
