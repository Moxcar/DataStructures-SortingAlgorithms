#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

namespace estructurasDeDatos {
    namespace listaSimple {
        class Nodo
        {
        public:
            int dato;
            Nodo* enlace;
            Nodo() :enlace(nullptr) {};
        };

        class Coleccion
        {
            Nodo* inicio;
        public:
            Coleccion() : inicio(nullptr) {};
            ~Coleccion();
            void agregarDato(int dato);
            void borrarTodo();
            Nodo* borrarDato(int dato);
            void contar();
            void modificar(int dato, int mod);
        };

        void imprimirColeccion(Nodo* x);

        int mainLista()
        {
            int n, x, a, y;
            bool c = 1;
            Coleccion myColeccion;
            Nodo* inicio;
            cout << "Ingresa la cantidad de datos que va a tener tu coleccion: " << endl;
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor numero " << i + 1 << " de la coleccion: ";
                cin >> x;
                myColeccion.agregarDato(x);
            }
            do
            {
                cout << "1 para borrar un dato\n2 borrar todo\n3 agregar dato\n4 para contar\n5 para modificar\n6 para salir" << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Ingresa el dato a borrar: ";
                    cin >> x;
                    system("cls");
                    imprimirColeccion(myColeccion.borrarDato(x));
                    break;
                case 2:
                    system("cls");
                    cout << "Borrando todo" << endl;
                    myColeccion.borrarTodo();
                    break;
                case 3:
                    system("cls");
                    cout << "Ingresa el dato para agregarlo: ";
                    cin >> x;
                    myColeccion.agregarDato(x);
                    break;
                case 4:
                    system("cls");
                    cout << "contar" << endl;
                    myColeccion.contar();
                    break;
                case 5:
                    system("cls");
                    cout << "Modificar" << endl;
                    cout << "Ingresa el valor que quieres modificar: ";
                    cin >> x;
                    cout << "Ingresa el nuevo valor: ";
                    cin >> y;
                    myColeccion.modificar(x, y);
                    break;
                }
            } while (a != 6);
            return 0;
        }

        void Coleccion::modificar(int dato, int mod)
        {
            Nodo* modificar;
            if (inicio->dato == dato)
                inicio->dato = mod;
            else
            {
                modificar = inicio;
                while (modificar->dato != dato)
                    modificar = modificar->enlace;
                modificar->dato = mod;
            }
            cout << "Se ha modificado el valor exitosamente" << endl;
        }

        void Coleccion::contar()
        {
            Nodo* x = inicio;
            int n = 0;
            do
            {
                n++;
                x = x->enlace;
            } while (x != nullptr);
            cout << "Numeros de elementos en la coleccion: " << n << endl;
        }

        Coleccion::~Coleccion()
        {
            borrarTodo();
        }

        void imprimirColeccion(Nodo* inicio)
        {
            Nodo* x = inicio;
            do
            {
                cout << x->dato << "\t";
                x = x->enlace;
            } while (x != nullptr);
            cout << endl;
        }

        void Coleccion::agregarDato(int dato)
        {
            Nodo* cursor;
            Nodo* nuevo = new Nodo();
            nuevo->dato = dato;
            if (inicio == nullptr)
                inicio = nuevo;
            else
            {
                cursor = inicio;

                while (cursor->enlace != nullptr)
                    cursor = cursor->enlace;

                cursor->enlace = nuevo;
            }
        }

        void Coleccion::borrarTodo()
        {
            Nodo* borrar, * anterior;
            do
            {
                if (inicio->enlace != nullptr)
                {
                    borrar = inicio;
                    while (borrar->enlace != nullptr)
                        borrar = borrar->enlace;
                    anterior = inicio;
                    while (anterior->enlace != borrar)
                        anterior = anterior->enlace;
                    delete borrar;
                    anterior->enlace = nullptr;
                }
                else
                {
                    delete inicio;
                    inicio = nullptr;
                    break;
                }
            } while (1);
        }

        Nodo* Coleccion::borrarDato(int dato)
        {
            Nodo* borrar, * anterior;
            if (inicio->dato == dato)
            {
                borrar = inicio;
                inicio = inicio->enlace;
                delete borrar;
            }
            else
            {
                borrar = inicio;
                anterior = inicio;
                while (borrar->dato != dato)
                {
                    anterior = borrar;
                    borrar = borrar->enlace;
                }
                if (borrar->enlace == nullptr)
                {
                    delete borrar;
                    anterior->enlace = nullptr;
                }
                else
                {
                    anterior->enlace = borrar->enlace;
                    delete borrar;
                }
            }
            return inicio;
        }
    }
    namespace tablaHash {
        class Nodo
        {
        public:
            string dato;
            Nodo* enlace;
            Nodo* indice;
            Nodo()
                :enlace(nullptr), indice(nullptr), dato("")
            {}
        };

        class Coleccion
        {
            Nodo* inicio;
        public:
            Coleccion();
            ~Coleccion();
            void ingresarDato(string nombre);
            int contar();
            int buscar(string nombre);
            bool eliminar(string nombre);
            void borrarTodo();
        };

        int codificar(string n);

        int mainTH()
        {
            Coleccion myColeccion;
            int a;
            string nombre;
            char n[30];
            do
            {
                system("cls");
                cout << "Menu\n1. Ingresar un valor a la coleccion\n2. Eliminar un valor en la coleccion\n3. Contar los valores de la coleccion\n4. Buscar un nombre en la coleccion\n5. Para Borrar todo\n6. Para salir" << endl;
                cin >> a;
                cin.ignore();
                switch (a)
                {
                case 1:
                    cout << "\nIngresa el nombre que vas a agregar a la coleccion: ";
                    cin.getline(n, 30);
                    nombre = n;
                    myColeccion.ingresarDato(nombre);
                    break;
                case 2:
                    cout << "\nIngresa el nombre que vas a borrar de la coleccion: ";
                    cin.getline(n, 30);
                    nombre = n;
                    if (myColeccion.eliminar(nombre))
                        cout << "El nombre: " << nombre << " se ha eliminado exitosamente" << endl;
                    else
                        cout << "Error al encontrar el nombre " << nombre << " para eliminarlo" << endl;
                    _getch();
                    break;
                case 3:
                    cout << "\nLos elementos en la coleccion son: " << myColeccion.contar() << endl;
                    _getch();
                    break;
                case 4:
                    cout << "\nIngresa el nombre que quieras buscar en la coleccion" << endl;
                    cin.getline(n, 30);
                    nombre = n;
                    if (myColeccion.buscar(nombre) != 0)
                        cout << "Se encontro el nombre " << nombre << " un total de " << myColeccion.buscar(nombre) << " veces en la coleccion" << endl;
                    else
                        cout << "No se encontro el nombre " << nombre << " en la coleccion" << endl;
                    _getch();
                    break;
                case 5:
                    myColeccion.borrarTodo();
                    break;
                }
            } while (a != 6);
            return 0;

        }

        Coleccion::~Coleccion()
        {
            borrarTodo();//Borramos los datos dentro de los indices
            //borramos los indices
            Nodo* cursor = inicio;
            for (int i = 0;i < 1;i++)
            {
                inicio = inicio->enlace;
                delete cursor;
                cursor = inicio;
            }
            delete inicio;
        }

        Coleccion::Coleccion()
        {
            Nodo* anterior, * primero = new Nodo();
            inicio = primero;
            inicio->dato = "0";
            anterior = inicio;
            for (int i = 1;i < 11;i++)
            {
                Nodo* nuevo = new Nodo();
                anterior->indice = nuevo;
                nuevo->dato = to_string(i);
                anterior = nuevo;
            }
        }

        void Coleccion::ingresarDato(string nombre)
        {
            Nodo* cursor = inicio, * nuevo = new Nodo();
            int n = codificar(nombre);
            nuevo->dato = nombre;

            for (int i = 0;i < n;i++)//Este for pone a cursor en el indice donde va nombre
                cursor = cursor->indice;

            while (cursor->enlace != nullptr)//Este ciclo lleva a cursor al final del indice que se encuentra
                cursor = cursor->enlace;

            cursor->enlace = nuevo;//Aqui se agrega el nuevo nodo al encadenamiento
        }

        int Coleccion::contar()
        {
            Nodo* cursor = inicio, * subcursor;
            int contador = 0;
            for (int i = 0;i < 11;i++)
            {
                subcursor = cursor;
                while (subcursor->enlace != nullptr)
                {
                    contador++;
                    subcursor = subcursor->enlace;
                }
                cursor = cursor->indice;
            }
            return contador;
        }

        int Coleccion::buscar(string nombre)
        {
            Nodo* cursor = inicio;
            int buscar = 0;
            int n = codificar(nombre);
            for (int i = 0;i < n;i++)
                cursor = cursor->indice;
            while (cursor != nullptr)
            {
                if (cursor->dato == nombre)
                {
                    buscar++;
                }
                cursor = cursor->enlace;
            }
            return buscar;
        }

        bool Coleccion::eliminar(string nombre)
        {
            Nodo* cursor = inicio, * anterior;
            bool eliminar = 0;
            int n = codificar(nombre);
            for (int i = 0;i < n;i++)
                cursor = cursor->indice;
            if (cursor->enlace == nullptr)
                eliminar = 0;
            else
            {
                anterior = cursor;
                cursor = cursor->enlace;
                while (cursor != nullptr)
                {
                    if (cursor->dato == nombre)
                    {
                        eliminar = 1;
                        anterior->enlace = cursor->enlace;
                        delete cursor;
                        break;
                    }
                    cursor = cursor->enlace;
                }
            }
            return eliminar;
        }

        int codificar(string n)
        {
            int x = 0;
            for (auto i = 0;i < n.size();i++)
                x += int(n[i]);
            return (x % 11);
        }

        void Coleccion::borrarTodo()
        {
            Nodo* cursor = inicio, * subcursor;
            for (int i = 0;i < 11;i++)
            {
                while (cursor->enlace != nullptr)
                {
                    subcursor = cursor->enlace;
                    cursor->enlace = subcursor->enlace;
                    delete subcursor;
                }
                cursor = cursor->indice;
            }
        }
    }
    namespace cola {
        class Nodo
        {
        public:
            int dato;
            Nodo* enlace;
            Nodo() :enlace(nullptr) {};
        };

        class Coleccion
        {
            Nodo* inicio;
        public:
            Coleccion() : inicio(nullptr) {};
            ~Coleccion();
            void agregarDato(int dato);
            void borrarTodo();
            void contar();
            bool eliminar();
        };

        int mainCola()
        {
            int x, a;
            Coleccion myColeccion;
            Nodo* inicio;
            do
            {
                system("cls");
                cout << "1 para borrar el primer dato\n2 borrar todo\n3 agregar dato\n4 para contar\n5 para salir" << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    myColeccion.eliminar();
                    cout << "Se borro el primer elemento de la cola" << endl;
                    break;
                case 2:
                    cout << "Borrando todo" << endl;
                    myColeccion.borrarTodo();
                    break;
                case 3:
                    cout << "Ingresa el dato para agregarlo: ";
                    cin >> x;
                    myColeccion.agregarDato(x);
                    break;
                case 4:
                    cout << "contar" << endl;
                    myColeccion.contar();
                    break;
                }
                system("pause");
            } while (a != 5);
            return 0;
        }

        bool Coleccion::eliminar()
        {
            if (inicio == nullptr)
                return 0;
            Nodo* borrar = inicio;
            inicio = inicio->enlace;
            return 1;
        }

        void Coleccion::agregarDato(int dato)
        {
            Nodo* cursor;
            Nodo* nuevo = new Nodo();
            nuevo->dato = dato;
            if (inicio == nullptr)
                inicio = nuevo;
            else
            {
                cursor = inicio;

                while (cursor->enlace != nullptr)
                    cursor = cursor->enlace;

                cursor->enlace = nuevo;
            }
        }

        Coleccion::~Coleccion()
        {
            borrarTodo();
        }

        void Coleccion::borrarTodo()
        {
            Nodo* borrar, * anterior;
            do
            {
                if (inicio->enlace != nullptr)
                {
                    borrar = inicio;
                    while (borrar->enlace != nullptr)
                        borrar = borrar->enlace;
                    anterior = inicio;
                    while (anterior->enlace != borrar)
                        anterior = anterior->enlace;
                    delete borrar;
                    anterior->enlace = nullptr;
                }
                else
                {
                    delete inicio;
                    inicio = nullptr;
                    break;
                }
            } while (1);
        }

        void Coleccion::contar()
        {
            Nodo* x = inicio;
            int n = 0;
            if (x == nullptr)
            {
                cout << "0 elementos en la coleccion" << endl;
                return;
            }
            do
            {
                n++;
                x = x->enlace;
            } while (x != nullptr);
            cout << "Numeros de elementos en la coleccion: " << n << endl;
        }
    }
    namespace listaCircular {
        class Nodo
        {
        public:
            int dato;
            Nodo* enlace;
            Nodo() :enlace(nullptr) {};
        };

        Nodo* fin;

        class Coleccion
        {
            Nodo* inicio;
        public:
            Coleccion() : inicio(nullptr) {};
            ~Coleccion();
            void agregarDato(int dato);
            void borrarTodo();
            void borrarDato(int dato);
            void contar();
            void modificar(int dato, int mod);
        };

        int mainListaCircular()
        {
            int n, x, a, y;
            bool c = 1;
            Coleccion myColeccion;
            Nodo* inicio;
            cout << "Ingresa la cantidad de datos que va a tener tu coleccion: " << endl;
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor numero " << i + 1 << " de la coleccion: ";
                cin >> x;
                myColeccion.agregarDato(x);
            }
            do
            {
                cout << "1 para borrar un dato\n2 borrar todo\n3 agregar dato\n4 para contar\n5 para modificar\n6 para salir" << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Ingresa el dato a borrar: ";
                    cin >> x;
                    system("cls");
                    myColeccion.borrarDato(x);
                    break;
                case 2:
                    system("cls");
                    cout << "Borrando todo" << endl;
                    myColeccion.borrarTodo();
                    break;
                case 3:
                    system("cls");
                    cout << "Ingresa el dato para agregarlo: ";
                    cin >> x;
                    myColeccion.agregarDato(x);
                    break;
                case 4:
                    system("cls");
                    cout << "contar" << endl;
                    myColeccion.contar();
                    break;
                case 5:
                    system("cls");
                    cout << "Modificar" << endl;
                    cout << "Ingresa el valor que quieres modificar: ";
                    cin >> x;
                    cout << "Ingresa el nuevo valor: ";
                    cin >> y;
                    myColeccion.modificar(x, y);
                    break;
                }
            } while (a != 6);
            return 0;
        }

        void Coleccion::modificar(int dato, int mod)
        {
            Nodo* modificar;
            if (inicio->dato == dato)
                inicio->dato = mod;
            else
            {
                modificar = inicio;
                while (modificar->dato != dato)
                    modificar = modificar->enlace;
                modificar->dato = mod;
            }
            cout << "Se ha modificado el valor exitosamente" << endl;
        }

        void Coleccion::borrarTodo()
        {
            Nodo* borrar, * anterior;
            do
            {
                if (inicio->enlace != fin)
                {
                    borrar = inicio;
                    while (borrar->enlace != fin)
                        borrar = borrar->enlace;
                    anterior = inicio;
                    while (anterior->enlace != borrar)
                        anterior = anterior->enlace;
                    delete borrar;
                    anterior->enlace = fin;
                }
                else
                {
                    delete inicio;
                    inicio = nullptr;
                    break;
                }
            } while (1);
        }

        void Coleccion::contar()
        {
            if (inicio == nullptr)
                cout << "Hay 0 elementos en la coleccion" << endl;
            Nodo* x = inicio->enlace;
            int n = 01;
            do
            {
                n++;
                x = x->enlace;
            } while (x != inicio);
            cout << "Numeros de elementos en la coleccion: " << n << endl;
        }

        Coleccion::~Coleccion()
        {
            borrarTodo();
        }

        void Coleccion::agregarDato(int dato)
        {
            Nodo* nuevo;
            nuevo = new Nodo;
            nuevo->dato = dato;
            nuevo->enlace = NULL;

            if (inicio == NULL)
            {
                inicio = nuevo;
                inicio->enlace = inicio;
                fin = nuevo;
            }
            else
            {
                nuevo->enlace = inicio;
                inicio = nuevo;
                fin->enlace = inicio;
            }
        }

        void Coleccion::borrarDato(int dato)
        {
            Nodo* borrar, * anterior;
            if (inicio->dato == dato)
            {
                borrar = inicio;
                inicio = inicio->enlace;
                delete borrar;
            }
            else
            {
                borrar = inicio;
                anterior = inicio;
                while (borrar->dato != dato)
                {
                    anterior = borrar;
                    borrar = borrar->enlace;
                }
                if (borrar->enlace == fin)
                {
                    delete borrar;
                    anterior->enlace = fin;
                }
                else
                {
                    anterior->enlace = borrar->enlace;
                    delete borrar;
                }
            }
        }
    }
    namespace listaCircularDoble {
        class Nodo
        {
        public:
            int dato;
            Nodo* enlace, * anterior;
            Nodo() :enlace(nullptr), anterior(nullptr) {};
        };

        Nodo* fin;

        class Coleccion
        {
            Nodo* inicio;
        public:
            Coleccion() : inicio(nullptr) {};
            ~Coleccion();
            void agregarDato(int dato);
            void borrarTodo();
            void borrarDato(int dato);
            void contar();
            void modificar(int dato, int mod);
        };

        int mainListaCircularDoble()
        {
            int n, x, a, y;
            bool c = 1;
            Coleccion myColeccion;
            Nodo* inicio;
            cout << "Ingresa la cantidad de datos que va a tener tu coleccion: " << endl;
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor numero " << i + 1 << " de la coleccion: ";
                cin >> x;
                myColeccion.agregarDato(x);
            }
            do
            {
                cout << "1 para borrar un dato\n2 borrar todo\n3 agregar dato\n4 para contar\n5 para modificar\n6 para salir" << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Ingresa el dato a borrar: ";
                    cin >> x;
                    system("cls");
                    myColeccion.borrarDato(x);
                    break;
                case 2:
                    system("cls");
                    cout << "Borrando todo" << endl;
                    myColeccion.borrarTodo();
                    break;
                case 3:
                    system("cls");
                    cout << "Ingresa el dato para agregarlo: ";
                    cin >> x;
                    myColeccion.agregarDato(x);
                    break;
                case 4:
                    system("cls");
                    cout << "contar" << endl;
                    myColeccion.contar();
                    break;
                case 5:
                    system("cls");
                    cout << "Modificar" << endl;
                    cout << "Ingresa el valor que quieres modificar: ";
                    cin >> x;
                    cout << "Ingresa el nuevo valor: ";
                    cin >> y;
                    myColeccion.modificar(x, y);
                    break;
                }
            } while (a != 6);
            return 0;
        }

        void Coleccion::modificar(int dato, int mod)
        {
            Nodo* modificar;
            if (inicio->dato == dato)
                inicio->dato = mod;
            else
            {
                modificar = inicio;
                while (modificar->dato != dato)
                    modificar = modificar->enlace;
                modificar->dato = mod;
            }
            cout << "Se ha modificado el valor exitosamente" << endl;
        }

        void Coleccion::borrarTodo()
        {
            Nodo* borrar, * anterior;
            do
            {
                if (inicio->enlace != fin)
                {
                    borrar = inicio;
                    while (borrar->enlace != fin)
                        borrar = borrar->enlace;
                    anterior = inicio;
                    while (anterior->enlace != borrar)
                        anterior = anterior->enlace;
                    delete borrar;
                    anterior->enlace = fin;
                }
                else
                {
                    delete inicio;
                    inicio = nullptr;
                    break;
                }
            } while (1);
        }

        void Coleccion::contar()
        {
            if (inicio == nullptr)
                cout << "Hay 0 elementos en la coleccion" << endl;
            Nodo* x = inicio->enlace;
            int n = 01;
            do
            {
                n++;
                x = x->enlace;
            } while (x != inicio);
            cout << "Numeros de elementos en la coleccion: " << n << endl;
        }

        Coleccion::~Coleccion()
        {
            borrarTodo();
        }

        void Coleccion::agregarDato(int dato)
        {
            Nodo* nuevo;
            nuevo = new Nodo;
            nuevo->dato = dato;

            if (inicio == nullptr)
            {
                inicio = nuevo;
                inicio->enlace = inicio;
                inicio->anterior = inicio;
                fin = nuevo;
            }
            else
            {
                nuevo->enlace = inicio;
                inicio = nuevo;
                inicio->anterior = nuevo;
                fin->enlace = inicio;
            }
        }

        void Coleccion::borrarDato(int dato)
        {
            Nodo* borrar, * anterior;
            if (inicio->dato == dato)
            {
                borrar = inicio;
                inicio = inicio->enlace;
                delete borrar;
            }
            else
            {
                borrar = inicio;
                anterior = inicio;
                while (borrar->dato != dato)
                {
                    anterior = borrar;
                    borrar = borrar->enlace;
                }
                if (borrar->enlace == fin)
                {
                    delete borrar;
                    anterior->enlace = fin;
                }
                else
                {
                    anterior->enlace = borrar->enlace;
                    delete borrar;
                }
            }
        }
    }
    namespace listaDoble {
        class Nodo
        {
        public:
            int dato;
            Nodo* enlace, * atras;
            Nodo() :enlace(nullptr), atras(nullptr) {};
        };

        class Coleccion
        {
            Nodo* inicio;
        public:
            Coleccion() : inicio(nullptr) {};
            ~Coleccion();
            void agregarDato(int dato);
            void borrarTodo();
            Nodo* borrarDato(int dato);
            void contar();
            void modificar(int dato, int mod);
        };

        void imprimirColeccion(Nodo* x);

        int mainListaDoble()
        {
            int n, x, a, y;
            bool c = 1;
            Coleccion myColeccion;
            Nodo* inicio;
            cout << "Ingresa la cantidad de datos que va a tener tu coleccion: " << endl;
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor numero " << i + 1 << " de la coleccion: ";
                cin >> x;
                myColeccion.agregarDato(x);
            }
            do
            {
                cout << "1 para borrar un dato\n2 borrar todo\n3 agregar dato\n4 para contar\n5 para modificar\n6 para salir" << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Ingresa el dato a borrar: ";
                    cin >> x;
                    system("cls");
                    imprimirColeccion(myColeccion.borrarDato(x));
                    break;
                case 2:
                    system("cls");
                    cout << "Borrando todo" << endl;
                    myColeccion.borrarTodo();
                    break;
                case 3:
                    system("cls");
                    cout << "Ingresa el dato para agregarlo: ";
                    cin >> x;
                    myColeccion.agregarDato(x);
                    break;
                case 4:
                    system("cls");
                    cout << "contar" << endl;
                    myColeccion.contar();
                    break;
                case 5:
                    system("cls");
                    cout << "Modificar" << endl;
                    cout << "Ingresa el valor que quieres modificar: ";
                    cin >> x;
                    cout << "Ingresa el nuevo valor: ";
                    cin >> y;
                    myColeccion.modificar(x, y);
                    break;
                }
            } while (a != 6);
            return 0;
        }

        void Coleccion::modificar(int dato, int mod)
        {
            Nodo* modificar;
            if (inicio->dato == dato)
                inicio->dato = mod;
            else
            {
                modificar = inicio;
                while (modificar->dato != dato)
                    modificar = modificar->enlace;
                modificar->dato = mod;
            }
            cout << "Se ha modificado el valor exitosamente" << endl;
        }

        void Coleccion::contar()
        {
            Nodo* x = inicio;
            int n = 0;
            do
            {
                n++;
                x = x->enlace;
            } while (x != nullptr);
            cout << "Numeros de elementos en la coleccion: " << n << endl;
        }

        Coleccion::~Coleccion()
        {
            borrarTodo();
        }

        void imprimirColeccion(Nodo* inicio)
        {
            Nodo* x = inicio;
            do
            {
                cout << x->dato << "\t";
                x = x->enlace;
            } while (x != nullptr);
            cout << endl;
        }

        void Coleccion::agregarDato(int dato)
        {
            Nodo* cursor;
            Nodo* nuevo = new Nodo();
            nuevo->dato = dato;
            nuevo->atras = nullptr;
            if (inicio == nullptr)
                inicio = nuevo;
            else
            {
                cursor = inicio;

                while (cursor->enlace != nullptr)
                    cursor = cursor->enlace;
                nuevo->atras = cursor;
                cursor->enlace = nuevo;
            }
        }

        void Coleccion::borrarTodo()
        {
            Nodo* borrar, * anterior;
            do
            {
                if (inicio->enlace != nullptr)
                {
                    borrar = inicio;
                    while (borrar->enlace != nullptr)
                        borrar = borrar->enlace;
                    anterior = inicio;
                    while (anterior->enlace != borrar)
                        anterior = anterior->enlace;
                    delete borrar;
                    anterior->enlace = nullptr;
                }
                else
                {
                    delete inicio;
                    inicio = nullptr;
                    break;
                }
            } while (1);
        }

        Nodo* Coleccion::borrarDato(int dato)
        {
            Nodo* borrar, * anterior;
            if (inicio->dato == dato)
            {
                borrar = inicio;
                inicio = inicio->enlace;
                delete borrar;
            }
            else
            {
                borrar = inicio;
                anterior = inicio;
                while (borrar->dato != dato)
                {
                    anterior = borrar;
                    borrar = borrar->enlace;
                }
                if (borrar->enlace == nullptr)
                {
                    delete borrar;
                    anterior->enlace = nullptr;
                }
                else
                {
                    anterior->enlace = borrar->enlace;
                    delete borrar;
                }
            }
            return inicio;
        }
    }
    namespace pila {
        class Nodo
        {
        public:
            int dato;
            Nodo* enlace;
            Nodo() :enlace(nullptr) {};
        };

        class Coleccion
        {
            Nodo* inicio;
        public:
            Coleccion() : inicio(nullptr) {};
            ~Coleccion();
            void agregarDato(int dato);
            void borrarTodo();
            void contar();
            bool eliminar();
        };

        int mainPila()
        {
            int x, a;
            Coleccion myColeccion;
            Nodo* inicio;
            do
            {
                system("cls");
                cout << "1 para borrar el ultimo dato\n2 borrar todo\n3 agregar dato\n4 para contar\n5 para salir" << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    if (myColeccion.eliminar())
                        cout << "Se pudo eliminar el valor" << endl;
                    else
                        cout << "No se pudo eliminar el valor" << endl;
                    break;
                case 2:
                    cout << "Borrando todo" << endl;
                    myColeccion.borrarTodo();
                    break;
                case 3:
                    cout << "Ingresa el dato para agregarlo: ";
                    cin >> x;
                    myColeccion.agregarDato(x);
                    break;
                case 4:
                    cout << "contar" << endl;
                    myColeccion.contar();
                    break;
                }
                system("pause");
            } while (a != 5);
            return 0;
        }

        bool Coleccion::eliminar()
        {
            Nodo* borrar, * anterior;
            borrar = inicio;
            anterior = inicio;
            if (inicio == nullptr)
            {
                return 0;
            }
            if (inicio->enlace == nullptr)
            {
                delete borrar;
                inicio = nullptr;
                return 0;
            }
            while (borrar->enlace != nullptr)
            {
                anterior = borrar;
                borrar = borrar->enlace;
            }
            anterior->enlace = nullptr;
            delete borrar;
            return 1;
        }

        void Coleccion::agregarDato(int dato)
        {
            Nodo* cursor;
            Nodo* nuevo = new Nodo();
            nuevo->dato = dato;
            if (inicio == nullptr)
                inicio = nuevo;
            else
            {
                cursor = inicio;

                while (cursor->enlace != nullptr)
                    cursor = cursor->enlace;

                cursor->enlace = nuevo;
            }
        }

        Coleccion::~Coleccion()
        {
            borrarTodo();
        }

        void Coleccion::borrarTodo()
        {
            Nodo* borrar, * anterior;
            do
            {
                if (inicio->enlace != nullptr)
                {
                    borrar = inicio;
                    while (borrar->enlace != nullptr)
                        borrar = borrar->enlace;
                    anterior = inicio;
                    while (anterior->enlace != borrar)
                        anterior = anterior->enlace;
                    delete borrar;
                    anterior->enlace = nullptr;
                }
                else
                {
                    delete inicio;
                    inicio = nullptr;
                    break;
                }
            } while (1);
        }

        void Coleccion::contar()
        {
            Nodo* x = inicio;
            int n = 0;
            if (x == nullptr)
            {
                cout << "0 elementos en la coleccion" << endl;
                return;
            }
            do
            {
                n++;
                x = x->enlace;
            } while (x != nullptr);
            cout << "Numeros de elementos en la coleccion: " << n << endl;
        }
    }
}

namespace metodosOrdenacion {
    namespace merge{
        void imprimirLista(int lista[], int N);
        void merge(int arr[], int l, int m, int r);
        void ordenarPorMerge(int arr[], int l, int r);

        int mainMerge()
        {
            int n;
            cout << "Ingresa el numero de elementos a ordenar: ";
            cin >> n;
            int* list = new int[n];
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor " << i << ": ";
                cin >> list[i];
            }
            ordenarPorMerge(list, 0, n - 1);
            imprimirLista(list, n);
            return 0;
        }

        void imprimirLista(int lista[], int N)
        {
            for (int i = 0;i < N;i++)
            {
                std::cout << lista[i] << " ";
            }
        }

        void merge(int arr[], int l, int m, int r)
        {
            int i, j, k;
            int n1 = m - l + 1;
            int n2 = r - m;

            int* L = new int[n1], * R = new int[n2];

            for (i = 0; i < n1; i++)
                L[i] = arr[l + i];

            for (j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];

            i = 0;
            j = 0;
            k = l;

            while (i < n1 && j < n2)
            {
                if (L[i] <= R[j])
                {
                    arr[k] = L[i];
                    i++;
                }
                else
                {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < n1)
            {
                arr[k] = L[i];
                i++;
                k++;
            }
            while (j < n2)
            {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        void ordenarPorMerge(int arr[], int l, int r)
        {
            if (l < r)
            {
                int m = l + (r - l) / 2;
                ordenarPorMerge(arr, l, m);
                ordenarPorMerge(arr, m + 1, r);
                merge(arr, l, m, r);
            }
        }
    }
    namespace radix{
        /*
        Este metodo que es el de radix queria retarme a no hacerlo con el operador modulo (%), queria hacerlo con strings y pues por eso es más complejo pero funciona :D
        */

        void imprimirVecP(vector<string> x);//funcion para imprimir la lista positiva
        void imprimirVecN(vector<string> x);//funcion para imprimir la lista negativa
        vector<string> ordenarPorRadix(vector<string> x);//Funcion para ordenar por radix

        int mainRadix()
        {
            vector <string> listap, listan;
            int n, temp;
            cout << "Ingresa el numero de datos: " << endl;
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el dato " << i << ": ";
                cin >> temp;
                if (temp < 0)
                    listan.push_back(to_string((-1) * temp));//Aqui a las string le meto los valores negativos pero convertidos a positivos para que mi funcion radix funcione con ellos
                else
                    listap.push_back(to_string(temp));
            }
            cout << "Resultado :" << endl;
            imprimirVecN(ordenarPorRadix(listan));
            imprimirVecP(ordenarPorRadix(listap));
            return 0;
        }

        void imprimirVecP(vector<string> x)
        {
            for (auto i = 0;i < x.size();i++)
            {
                cout << stoi(x[i]) << "   ";
            }
            cout << endl;
        }
        void imprimirVecN(vector<string> x)//Este imprimir imprime la lista negativa al reves y le pone el signo de menos
        {
            for (int i = int(x.size() - 1);i >= 0; i--)
            {
                cout << (-1) * stoi(x[i]) << "   ";
            }
        }

        vector<string> ordenarPorRadix(vector<string> x)
        {
            int longitudMax = 0;
            for (auto i = 0;i < x.size();i++)//Este for me ayuda a saber cual es la longitud maxima que tiene una strin, para asi saber cuantos digitos tengo que ordenar
            {
                if (int(x[i].length()) > longitudMax)
                {
                    longitudMax = int(x[i].length());
                }
            }
            for (auto i = 0;i < x.size();i++)//En este for lleno los strings que no sean del tamaño de longitud maxima agregandoles 0´s al principio, por ejemplo si la longitud es 3 y tengo un 1 se convierte a 001
            {
                ;
                if (int(x[i].length()) < longitudMax)
                {
                    for (int j = int(x[i].length()); j < longitudMax;j++)
                    {
                        x[i].insert(0, "0");
                    }
                }
            }
            for (int i = 0;i < longitudMax;i++)//Esta función ordena los string por radix
            {
                for (auto k = 0;k < x.size() - 1;k++)
                {
                    for (auto j = 0;j < x.size() - 1;j++)
                    {
                        if (x[j][longitudMax - i - 1] > x[j + 1][longitudMax - i - 1])
                        {
                            swap(x[j], x[j + 1]);
                        }
                    }
                }
            }
            return x;
        }
    }
    namespace seleccion{
        void ordenarPorSeleccion(int lista[]);
        void imprimirLista(int lista[]);

        int n;

        int mainSeleccion()
        {
            int list[100];
            cout << "Ingresa el numero de datos maximo" << endl;
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor " << i+1 << ": ";
                cin >> list[i];
            }
            ordenarPorSeleccion(list);
            imprimirLista(list);
            return 0;
        }

        void ordenarPorSeleccion(int lista[])
        {
            for (int i = 0;i < n - 1;++i)
            {
                int seleccion = i;
                for (int j = i + 1; j < n; ++j) {
                    if (lista[seleccion] > lista[j])
                        seleccion = j;
                }
                int temp = lista[i];
                lista[i] = lista[seleccion];
                lista[seleccion] = temp;
            }
        }

        void imprimirLista(int lista[])
        {
            static int N = n;
            for (int i = 0;i < N;i++)
            {
                cout << lista[i] << " ";
            }
            cout << endl;
        }
    }
    namespace shell{
        void imprimirLista(int lista[], int n);
        void ordenarPorShell(int lista[], int n);

        int mainShell()
        {
            int n;
            cout << "Ingresa el tamano de la lista: ";
            cin >> n;
            int* list = new int[n];
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor " << i << ": ";
                cin >> list[i];
            }
            ordenarPorShell(list, n);
            imprimirLista(list, n);
            return 0;
        }

        void imprimirLista(int lista[], int n)
        {
            for (int i = 0;i < n;i++)
            {
                std::cout << lista[i] << " ";
            }
        }

        void ordenarPorShell(int lista[], int n)
        {
            for (int i = n / 2;i > 0;i /= 2)
            {
                for (int j = i; j < n; j += 1)
                {
                    int temp = lista[j];
                    int k;
                    for (k = j; k >= i && lista[k - i] > temp; k -= i)
                        lista[k] = lista[k - i];
                    lista[k] = temp;
                }
            }
        }
    }
    namespace quickSort{
        void imprimirLista(int lista[], int N);
        void ordenarPorQuickSort(int lista[], int inicio, int fin);
        int selPivote(int lista[], int inicio, int fin);

        int mainQuickSort()
        {
            int n;
            cout << "Ingresa el numero de elementos a ordenar: ";
            cin >> n;
            int* list = new int[n];
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor " << i << ": ";
                cin >> list[i];
            }
            ordenarPorQuickSort(list, 0, n - 1);
            cout << "Ordenado" << endl;
            imprimirLista(list, n);
            return 0;
        }

        void imprimirLista(int lista[], int N)
        {
            for (int i = 0;i < N;i++)
            {
                std::cout << lista[i] << " ";
            }
        }

        int selPivote(int lista[], int inicio, int fin)
        {
            int pivote = lista[fin];
            int i = (inicio - 1);

            for (int j = inicio; j <= fin - 1; j++)
            {
                if (lista[j] < pivote)
                {
                    i++;
                    int temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
            }
            int temp = lista[i + 1];
            lista[i + 1] = lista[fin];
            lista[fin] = temp;
            return (i + 1);
        }

        void ordenarPorQuickSort(int lista[], int inicio, int fin)
        {
            if (inicio < fin)
            {
                int pi = selPivote(lista, inicio, fin);
                ordenarPorQuickSort(lista, inicio, pi - 1);
                ordenarPorQuickSort(lista, pi + 1, fin);
            }
        }
    }
    namespace insercion{
        void ordenarPorInsercion(int numero, int lista[], int n);
        void imprimirLista(int lista[]);

        int n;

        int mainInsercion()
        {
            cout << "Ingresa el numero de elementos de la lista: " << endl;
            cin >> n;
            int* p = new int[n];
            int x;
            for (int i = 0;i < n;i++)
            {
                cin >> x;
                ordenarPorInsercion(x, p, i);
            }
            imprimirLista(p);
            return 0;
        }

        void ordenarPorInsercion(int numero, int lista[], int n)
        {
            if (n == 0)
                lista[0] = numero;
            else
            {
                n--;
                while ((lista[n] > numero) && (n >= 0))
                {
                    lista[n + 1] = lista[n];
                    n--;
                }
                lista[n + 1] = numero;
            }
        }
        void imprimirLista(int lista[])
        {
            static int N = n;
            for (int i = 0;i < N;i++)
            {
                std::cout << lista[i] << " ";
            }
        }
    }
    namespace burbuja{
        void ordenarPorBurbuja(int lista[]);
        void imprimirLista(int lista[]);

        int n;

        int mainBurbuja()
        {
            int list[100];
            cout << "Ingresa el numero de elementos a ordenar: ";
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el valor " << i << ": ";
                cin >> list[i];
            }
            ordenarPorBurbuja(list);
            imprimirLista(list);
            return 0;
        }

        void ordenarPorBurbuja(int lista[])
        {
            for (int i = 0;i < n;i++)
            {
                for (int j = 0;j < n - 1;j++)
                {
                    if (lista[j] > lista[j + 1])
                    {
                        int temp = lista[j];
                        lista[j] = lista[j + 1];
                        lista[j + 1] = temp;
                    }
                }
            }
        }

        void imprimirLista(int lista[])
        {
            static int N = n;
            for (int i = 0;i < N;i++)
            {
                std::cout << lista[i] << " ";
            }
        }
    }
}

namespace metodosBusqueda {
    namespace secuencial{
        void busquedaSecuencial(int n, int num, int list[]);

        int mainSecuencial()
        {
            int n, num, * p;
            cout << "Ingrese el numero de elementos que vas a ingresar: ";
            cin >> n;
            p = new int[n];
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el elemento " << i + 1 << ": ";
                cin >> p[i];
            }
            cout << "Ingresa el numero a buscar: " << endl;
            cin >> num;
            busquedaSecuencial(n, num, p);
            return 0;
        }

        void busquedaSecuencial(int n, int num, int list[])
        {
            int contador = 0;
            vector <int> resultado;
            for (int i = 0;i < n;i++)
            {
                if (list[i] == num)
                {
                    contador++;
                    resultado.push_back(i);
                }
            }
            cout << "El numero " << num << " se encontro un total de " << contador << " vez/veces en la lista en las posiciones:" << endl;
            for (auto i = 0;i < resultado.size();i++)
            {
                cout << resultado[i] << endl;
            }
        }
    }
    namespace binaria{
        void busquedaBinaria(int lista[], int x, int y, int num);
        void ordenarPorBurbuja(int lista[], int n);
        void imprimirLista(int lista[], int N);

        int mainBinaria()
        {
            int n, num, * p;
            cout << "Ingrese el numero de elementos que vas a ingresar: ";
            cin >> n;
            p = new int[n];
            for (int i = 0;i < n;i++)
            {
                cout << "Ingresa el elemento " << i + 1 << ": ";
                cin >> p[i];
            }
            cout << "Ingresa el numero a buscar: " << endl;
            cin >> num;
            ordenarPorBurbuja(p, n);
            imprimirLista(p, n);
            busquedaBinaria(p, 0, n - 1, num);
            return 0;
        }

        void busquedaBinaria(int lista[], int x, int y, int num)
        {
            while (x <= y) {
                int m = x + (y - x) / 2;
                if (lista[m] == num)
                {
                    cout << "Se encontro el numero " << num << " en el lugar " << x << " de la lista" << endl;
                    return;
                }
                if (lista[m] < num)
                    x = m + 1;
                else
                    y = m - 1;
            }
            cout << "No se encontro el numero " << num << " en la lista" << endl;
            return;
        }

        void ordenarPorBurbuja(int lista[], int n)
        {
            for (int i = 0;i < n;i++)
            {
                for (int j = 0;j < n - 1;j++)
                {
                    if (lista[j] > lista[j + 1])
                    {
                        int temp = lista[j];
                        lista[j] = lista[j + 1];
                        lista[j + 1] = temp;
                    }
                }
            }
        }

        void imprimirLista(int lista[], int N)
        {
            for (int i = 0;i < N;i++)
            {
                std::cout << lista[i] << " ";
            }
            cout << endl;
        }
    }
}

namespace programasRecursividadYPunteros{
    namespace multiplicacionDivision{
        int multiplicacion(int x, int y)
        {
            if (y == 0 || x == 0)
                return 0;
            if (y == 1)
                return x;
            else
            {
                y--;
                return x + multiplicacion(x, y);
            }
        }

        int dividir(int x, int y)
        {
            if (x == 0)
                return 0;
            if (y == 0)
                return -1;
            if (x == y)
                return 1;
            else if (x < y)
                return 0;
            else
                return 1 + dividir(x - y, y);
        }

        int mainMultiDivi()
        {
            char a;
            int x, y;
            srand(time(NULL));
            do {
                x = rand() % 101;//Genera un numero random entre 0 a 100 y se lo asigna a x
                y = rand() % 101;//Genera un numero random entre 0 a 100 y se lo asigna a y
                cout << x << " * " << y << " = " << multiplicacion(x, y) << endl;
                cout << x << " / " << y << " = " << dividir(x, y) << endl;
                cout << "Si quieres generar otra prueba aleatoria pulsa espacio\n" << endl;
                a = _getch();
            } while (a == ' ');
            return 0;
        }
    }
    namespace matrices{
        int cofactor(int matriz[][7], int n, int fila, int columna);
        int determinante(int matriz[][7], int n)
        {
            int det = 0;

            if (n == 1)
            {
                det = matriz[0][0];
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    det = det + matriz[0][j] * cofactor(matriz, n, 0, j);
                }
            }

            return det;
        }


        int cofactor(int matriz[][7], int n, int fila, int columna)
        {
            int Minimo[7][7];
            n--;

            int x = 0;
            int y = 0;

            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    if (i != fila && j != columna)
                    {
                        Minimo[x][y] = matriz[i][j];
                        y++;

                        if (y >= n)
                        {
                            x++;
                            y = 0;
                        }
                    }
                }
            }

            return pow(-1, fila + columna) * determinante(Minimo, n);
        }

        int mainMatrices()
        {
            int n, matriz[7][7];
            cout << "Ingresa el tamaño de la matriz: " << endl;
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                for (int j = 0;j < n;j++)
                {
                    cout << "Ingresa el valor [" << j + 1 << "][" << i + 1 << "]";
                    cin >> matriz[j][i];
                }
            }
            cout << determinante(matriz, n);
            return 0;
        }
    }
    namespace funcionDeBusquedaParaEstructura{
        class Coordenada
        {
        public:
            int x, y;
            Coordenada()
            {
                x = 0;
                y = 0;
            }
            Coordenada(int x, int y)
            {
                this->x = x;
                this->y = y;
            }
        };

        class Nodo
        {
        public:
            void* dato;
            Nodo* sig;
            Nodo() :sig(nullptr) {};
        };

        class Lista
        {
            Nodo* inicio;
        public:
            Lista();

            void add(void* data);
            void* find(void* value, int (*criterio)(void* value1, void* value2));
        };

        Lista::Lista()
        {
            inicio = nullptr;
        }


        void Lista::add(void* data)
        {
            Nodo* cursor;
            Nodo* nuevo = new Nodo();
            nuevo->dato = data;

            if (inicio == nullptr)
                inicio = nuevo;
            else
            {
                cursor = inicio;
                while (cursor->sig != nullptr)
                    cursor = cursor->sig;
                cursor->sig = nuevo;
            }
        }

        void* Lista::find(void* value, int (*criterio)(void* value1, void* value2))
        {
            Nodo* cursor = inicio;
            while (cursor)
            {
                if (criterio(value, cursor->dato))
                {
                    return cursor->dato;
                }
                cursor = cursor->sig;
            }
            return nullptr;
        }

        int criterioCoordenada(void* value1, void* value2)
        {
            if ((*((Coordenada*)value1)).x == (*((Coordenada*)value2)).x)
                return 1;
            return 0;
        }

        int criterioEntero(void* value1, void* value2)
        {
            int d1, d2;
            int* dir1, * dir2;

            dir1 = (int*)value1;
            d1 = *dir1;

            // dir2 = (int*)value2;
            // d2 = *dir2;
            // d2 = *(dir2)

            d2 = *((int*)value2);

            if (d1 == d2) // if( d1 == *((int*)value2)) // if (*((int*)value1) == *((int*)value2))
                return 1;
            return 0;
        }

        void imprimirCoord(void* x)
        {
            cout << "La coordenada en y es: " << (*(Coordenada*)x).y << " cuando x es: " << (*(Coordenada*)x).x << endl;
        }

        int mainFuncion()
        {
            Lista lista1;
            lista1.add(new Coordenada(2, 5));
            lista1.add(new Coordenada(3, 6));
            lista1.add(new Coordenada(4, 50));
            int b = 3;
            void* r;
            r = lista1.find(&b, criterioCoordenada);
            if (r != nullptr)
            {
                imprimirCoord(r);
            }
            return 0;
        }
    }
}

namespace arbolDeBusquedaBinaria{

    class nodo {
    public:
        int dato;
        nodo* izq, * der;
        nodo(int x) : izq(nullptr), der(nullptr), dato(x) {}
        nodo() : izq(nullptr), der(nullptr) {}
    };

    class arbolBB {
    public:
        nodo* inicio;
        arbolBB() : inicio(nullptr) {}
        ~arbolBB();
        void insertarDato(int dato);
        void eliminarDato(int dato);
        void eliminarArbol();
        void recorridoPreorden(nodo* x);
        void recorridoOrden(nodo* x);
        void recorridoPostorden(nodo* x);
        int calculoProfundidad(nodo* x);
    };

    int mainArbolBB()
    {
        arbolBB x;
        int dato;
        do {
            system("cls");
            cout << "a) Ingreso de datos." << endl;
            cout << "b) Eliminación de un dato." << endl;
            cout << "c) Eliminación de todo el árbol." << endl;
            cout << "d) Mostrar el recorrido en : orden, pre - orden y post - orden." << endl;
            cout << "e) Calculo de la profundidad." << endl;
            cout << "s) Salir del programa." << endl;
            switch (_getch())
            {
            case 'a':
                cout << "Ingresa el dato de tipo entero que deseas agregar" << endl;
                cin >> dato;
                x.insertarDato(dato);
                break;
            case 'b':
                cout << "Ingresa el dato que vas a eliminar" << endl;
                cin >> dato;
                x.eliminarDato(dato);
                break;
            case 'c':
                cout << "Eliminar todo el arbol" << endl;

                x.eliminarArbol();
                break;
            case 'd':
                cout << "Recorrido en orden: ";
                x.recorridoOrden(x.inicio);
                cout << endl << "Recorrido preorden: ";
                x.recorridoPreorden(x.inicio);
                cout << endl << "Recorrido postorden: ";
                x.recorridoPostorden(x.inicio);
                break;
            case 'e':
                cout << "La profundidad es: ";
                cout << x.calculoProfundidad(x.inicio) << endl;
                break;
            case 's':
                return 1;
            default:
                break;
            }
            _getch();
        } while (1);
        return 0;
    }

    void arbolBB::recorridoOrden(nodo* x)
    {
        if (x)
        {
            recorridoOrden(x->izq);
            cout << x->dato << "  ";
            recorridoOrden(x->der);
        }
    }

    void arbolBB::recorridoPreorden(nodo* x)
    {
        if (x)
        {
            cout << x->dato << "  ";
            recorridoPreorden(x->izq);
            recorridoPreorden(x->der);
        }
    }

    void arbolBB::recorridoPostorden(nodo* x)
    {
        if (x->izq)
            recorridoPostorden(x->izq);
        if (x->der)
            recorridoPostorden(x->der);
        cout << x->dato << "  ";
    }

    int arbolBB::calculoProfundidad(nodo* x)
    {
        int a = 0, b = 0;
        if (x == nullptr)
            return 0;
        if (x->izq)
            a = calculoProfundidad(x->izq);
        if (x->der)
            b = calculoProfundidad(x->der);
        if (a < b)
            return b + 1;
        return a + 1;
    }

    void arbolBB::insertarDato(int dato)
    {
        nodo* nuevo = new nodo(dato);
        if (inicio == nullptr)
        {
            inicio = nuevo;
            return;
        }
        nodo* cursor = inicio;
        do
        {
            if (dato < cursor->dato)
            {
                if (cursor->izq == nullptr)
                {
                    cursor->izq = nuevo;
                    break;
                }
                cursor = cursor->izq;
            }
            else
            {
                if (cursor->der == nullptr)
                {
                    cursor->der = nuevo;
                    break;
                }
                cursor = cursor->der;
            }
        } while (1);
    }

    void arbolBB::eliminarDato(int dato)
    {
        nodo* cursor = inicio, * anterior = nullptr;
        bool c = 0;
        if (inicio == nullptr)
        {
            cout << "No se encontro el dato" << endl;
            return;
        }
        do
        {
            if (cursor->dato == dato)
                break;
            if (dato < cursor->dato)
            {
                if (cursor->izq == nullptr)
                    return;
                anterior = cursor;
                cursor = cursor->izq;
                c = 1;
            }
            else
            {
                if (cursor->der == nullptr)
                    return;
                anterior = cursor;
                cursor = cursor->der;
                c = 0;
            }
        } while (1);
        //Si el dato a eliminar no tiene hijos
        if (cursor->izq == nullptr && cursor->der == nullptr)
        {
            if (anterior != nullptr)
            {
                if (c)
                    anterior->izq = nullptr;
                else
                    anterior->der = nullptr;
            }
            else
                inicio = nullptr;
            delete cursor;
            return;
        }
        //Si el dato a eliminar tiene hijos a la derecha
        if (cursor->der != nullptr)
        {
            //Buscar el dato que le sigue
            nodo* buscar = cursor->der;
            anterior = cursor;
            if (buscar != nullptr)
            {
                while (buscar->izq != nullptr)
                {
                    anterior = buscar;
                    buscar = buscar->izq;
                }
            }
            //Cambiar el dato del nodo que buscamos al del cursor
            cursor->dato = buscar->dato;
            //Eliminar el nodo que buscamos y poner su anterior puntero al que sigue
            if (anterior == inicio && cursor == inicio)
            {
                inicio->der = buscar->der;
            }
            else
            {
                if (anterior != nullptr)
                    anterior->izq = buscar->der;
            }
            delete buscar;
            return;
        }
        //Si el dato a eliminar no tiene hijos a la derecha
        if (cursor->der == nullptr)
        {
            //Buscar el dato que le sigue
            nodo* buscar = cursor->izq;
            anterior = cursor;
            while (buscar->der != nullptr)
            {
                anterior = buscar;
                buscar = buscar->der;
            }
            //Cambiar el dato del nodo que buscamos al del cursor
            cursor->dato = buscar->dato;
            //Eliminar el nodo que buscamos y poner su anterior puntero al que sigue
            if (anterior == inicio && cursor == inicio)
            {
                inicio->izq = buscar->izq;
            }
            else
            {
                if (anterior != nullptr)
                    anterior->der = buscar->izq;
            }
            delete buscar;
            return;
        }
    }

    void arbolBB::eliminarArbol()
    {
        do
        {
            if (inicio)
                eliminarDato(inicio->dato);
            else
                break;
        } while (1);
    }

    arbolBB::~arbolBB()
    {
        eliminarArbol();
    }
}

namespace grafo{

#pragma region decTH
    class nodoTH
    {
    public:
        int dato;
        nodoTH* enlace;
        nodoTH* indice;
        nodoTH() :enlace(nullptr), indice(nullptr) {}
    };

    class coleccionTH
    {
        nodoTH* inicio;
    public:
        coleccionTH();
        ~coleccionTH();
        void ingresarDato(int, int);
        void ingresarIndice(int);
        vector <int> hijos(int);
        void borrarTodoTH();
        bool buscarTH(int);
        int contarNodosIndice();
    };
#pragma endregion

#pragma region decFIFO
    class nodoFIFO
    {
    public:
        int dato;
        nodoFIFO* pos;
        nodoFIFO* enlace;
        nodoFIFO() :enlace(nullptr), pos(nullptr) {};
    };

    struct par
    {
        int dato;
        nodoFIFO* pos;
    };

    class coleccionFIFO
    {
        nodoFIFO* inicio;
    public:
        coleccionFIFO() : inicio(nullptr) {};
        ~coleccionFIFO();
        void agregarDato(int dato, nodoFIFO* pos);
        void borrarTodo();
        void contar();
        par eliminar();
    };
#pragma endregion

#pragma region declista

    class coleccionLst
    {
    protected:
        nodoFIFO* inicio;
    public:
        coleccionLst() : inicio(nullptr) {};
        ~coleccionLst();
        void agregarDato(int dato, nodoFIFO* pos);
        void borrarTodo();
        vector <int> recorreElCaminoHaciaAtras();
        nodoFIFO* lugarDe(int, nodoFIFO*);
    };
#pragma endregion

#pragma region decGrafo
    class coleccionGrafo : public coleccionFIFO, public coleccionTH, public coleccionLst
    {
    public:
        coleccionTH tabla;
        vector<vector<int>> rutaCorta(int, int, int);
    };
#pragma endregion

    void impR(vector <vector<int>> a);

    int mainGrafo()
    {
        coleccionGrafo grafo;
        int x, a, b, y;
        cout << "Ingresa el numero maximo de nodos que tendra tu grafo" << endl;
        cin >> x;
        for (int i = 0;i < x;i++)
        {
            cout << "Ingresa el valor del nodo numero " << i + 1 << endl;
            cin >> a;
            grafo.tabla.ingresarIndice(a);
            cout << "A cuantos nodos se conecta el nodo actual?" << endl;
            cin >> b;
            cout << "Ingresa a los nodos que se conecta" << endl;
            for (int j = 0;j < b;j++)
            {
                cout << j + 1 << ".- ";
                cin >> y;
                grafo.tabla.ingresarDato(y, a);
            }

        }
        vector <vector<int>> z;
        do
        {
            system("cls");
            cout << "Calcular Rutas" << endl;
            cout << "Cual es el origen de la ruta? ";
            cin >> a;
            cout << "Cual es el destino de la ruta? ";
            cin >> b;
            cout << "Cuantas maximas posibles rutas deseas calcular?";
            cin >> x;
            cout << "Las rutas son:" << endl;
            z = grafo.rutaCorta(a, b, x);
            impR(z);
        } while (1);
        return 0;
    }

    void impR(vector <vector<int>> a)
    {
        for (auto i = 0; i < a.size();i++)
        {
            cout << i + 1 << "- ";
            for (auto j = 0;j < a[i].size();j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

#pragma region TH
    int coleccionTH::contarNodosIndice()
    {
        nodoTH* cursor = inicio;
        int n = 1;
        while (cursor->indice != nullptr)
        {
            cursor = cursor->indice;
            n++;
        }
        return n;
    }

    bool coleccionTH::buscarTH(int b)
    {
        nodoTH* cursor = inicio;
        while (cursor != nullptr)
        {
            if (cursor->dato == b)
                return 1;
            cursor = cursor->indice;
        }
        return 0;
    }

    void coleccionTH::ingresarIndice(int d)
    {
        nodoTH* nuevo = new nodoTH();
        nuevo->dato = d;
        if (inicio == nullptr)
            inicio = nuevo;
        else
        {
            nodoTH* cursor = inicio;
            while (cursor->indice != nullptr)
                cursor = cursor->indice;
            cursor->indice = nuevo;
        }
    }

    coleccionTH::~coleccionTH()
    {
        borrarTodoTH();//Borramos los datos dentro de los indices
        //borramos los indices
        nodoTH* cursor = inicio, * temp;
        do {
            if (cursor == nullptr)
                break;
            temp = cursor->indice;
            delete cursor;
            cursor = temp;
        } while (1);
        delete cursor;
    }

    coleccionTH::coleccionTH()
    {
        inicio = nullptr;
    }

    void coleccionTH::ingresarDato(int nombre, int n)
    {
        nodoTH* cursor = inicio, * nuevo = new nodoTH();
        nuevo->dato = nombre;
        while (cursor->dato != n)
            cursor = cursor->indice;

        while (cursor->enlace != nullptr)//Este ciclo lleva a cursor al final del indice que se encuentra
            cursor = cursor->enlace;

        cursor->enlace = nuevo;//Aqui se agrega el nuevo nodo al encadenamiento
    }

    vector <int> coleccionTH::hijos(int n)
    {
        nodoTH* cursor = inicio;
        int buscar = 0;
        vector <int> dev;
        do
        {
            if (cursor == nullptr)
                break;
            if (cursor->dato == n)
                break;
            cursor = cursor->indice;
        } while (cursor != nullptr);
        if (cursor == nullptr)
            return dev;
        while (cursor != nullptr)
        {
            dev.push_back(cursor->dato);
            cursor = cursor->enlace;
        }
        dev.erase(dev.begin());
        return dev;
    }

    void coleccionTH::borrarTodoTH()
    {
        nodoTH* cursor = inicio, * subcursor;
        while (cursor != nullptr)
        {
            while (cursor->enlace != nullptr)
            {
                subcursor = cursor->enlace;
                cursor->enlace = subcursor->enlace;
                delete subcursor;
            }
            cursor = cursor->indice;
        }
    }
#pragma endregion

#pragma region FIFO
    par coleccionFIFO::eliminar()
    {
        if (inicio == nullptr)
        {
            par r;
            r.dato = -999;
            r.pos = nullptr;
            return r;
        }
        nodoFIFO* borrar = inicio;
        par temp;
        temp.dato = inicio->dato;
        temp.pos = inicio->pos;
        inicio = inicio->enlace;
        delete borrar;
        return temp;
    }

    void coleccionFIFO::agregarDato(int dato, nodoFIFO* pos)
    {
        nodoFIFO* cursor;
        nodoFIFO* nuevo = new nodoFIFO();
        nuevo->dato = dato;
        nuevo->pos = pos;
        if (inicio == nullptr)
            inicio = nuevo;
        else
        {
            cursor = inicio;

            while (cursor->enlace != nullptr)
                cursor = cursor->enlace;

            cursor->enlace = nuevo;
        }
    }

    coleccionFIFO::~coleccionFIFO()
    {
        borrarTodo();
    }

    void coleccionFIFO::borrarTodo()
    {
        nodoFIFO* borrar, * anterior;
        do
        {
            if (inicio == nullptr)
                break;
            if (inicio->enlace != nullptr)
            {
                borrar = inicio;
                while (borrar->enlace != nullptr)
                    borrar = borrar->enlace;
                anterior = inicio;
                while (anterior->enlace != borrar)
                    anterior = anterior->enlace;
                delete borrar;
                anterior->enlace = nullptr;
            }
            else
            {
                delete inicio;
                inicio = nullptr;
                break;
            }
        } while (1);
    }

    void coleccionFIFO::contar()
    {
        nodoFIFO* x = inicio;
        int n = 0;
        if (x == nullptr)
        {
            cout << "0 elementos en la coleccion" << endl;
            return;
        }
        do
        {
            n++;
            x = x->enlace;
        } while (x != nullptr);
        cout << "Numeros de elementos en la coleccion: " << n << endl;
    }
#pragma endregion

#pragma region Lst

    nodoFIFO* coleccionLst::lugarDe(int num, nodoFIFO* pos)
    {
        nodoFIFO* cursor = inicio;
        while (cursor != nullptr)
        {
            if (cursor->dato == num && cursor->pos == pos)
                return cursor;
            cursor = cursor->enlace;
        }
        return nullptr;
    }

    coleccionLst::~coleccionLst()
    {
        borrarTodo();
    }

    void coleccionLst::agregarDato(int dato, nodoFIFO* pos)
    {
        nodoFIFO* cursor;
        nodoFIFO* nuevo = new nodoFIFO();
        nuevo->dato = dato;
        nuevo->pos = pos;
        if (inicio == nullptr)
            inicio = nuevo;
        else
        {
            cursor = inicio;

            while (cursor->enlace != nullptr)
                cursor = cursor->enlace;

            cursor->enlace = nuevo;
        }
    }

    void coleccionLst::borrarTodo()
    {
        nodoFIFO* borrar, * anterior;
        do
        {
            if (inicio == nullptr)
                break;
            if (inicio->enlace != nullptr)
            {
                borrar = inicio;
                while (borrar->enlace != nullptr)
                    borrar = borrar->enlace;
                anterior = inicio;
                while (anterior->enlace != borrar)
                    anterior = anterior->enlace;
                delete borrar;
                anterior->enlace = nullptr;
            }
            else
            {
                delete inicio;
                inicio = nullptr;
                break;
            }
        } while (1);
    }

    vector <int> coleccionLst::recorreElCaminoHaciaAtras()
    {
        vector <int> r;
        nodoFIFO* cursor = inicio;
        while (cursor->enlace != nullptr)
            cursor = cursor->enlace;
        do
        {
            r.insert(r.begin(), cursor->dato);
            cursor = cursor->pos;
        } while (cursor != nullptr);
        return r;
    }
#pragma endregion

#pragma region Grafo
    vector <vector<int>> coleccionGrafo::rutaCorta(int origen, int destino, int nRutas)
    {
        if (!tabla.buscarTH(origen) || !tabla.buscarTH(destino))
        {
            vector <vector<int>> x;
            return x;
        }
        coleccionFIFO cola;
        coleccionLst lista;
        vector <int> h;
        vector <vector <int>> ruta(nRutas, vector<int>(tabla.contarNodosIndice() + 1));
        bool ctrl = 0;
        int iDestino = 0;
        par temp, tempAnt;
        if (origen == destino)
        {
            ruta[0].push_back(origen);
            return ruta;
        }
        cola.agregarDato(origen, nullptr);
        lista.agregarDato(origen, nullptr);
        temp = cola.eliminar();
        h = tabla.hijos(origen);
        tempAnt.dato = origen;
        tempAnt.pos = nullptr;
        for (auto i = 0; i < h.size();i++)
        {
            cola.agregarDato(h[i], lista.lugarDe(tempAnt.dato, tempAnt.pos));
        }
        do
        {
            //sacar el de la cola
            temp = cola.eliminar();
            //se checa si la cola esta vacia
            if (temp.dato == -999 || nRutas == 0)
                break;
            //agregar temp a la lista
            lista.agregarDato(temp.dato, temp.pos);
            if (temp.dato == destino)
            {
                ruta[iDestino] = lista.recorreElCaminoHaciaAtras();//Se calcula la ruta
                iDestino++;
                nRutas--;
            }
            //calcular los hijos
            h = tabla.hijos(temp.dato);
            //agregar los hijos a la cola
            //se checa si un hijo es el destino
            for (auto i = 0; i < h.size();i++)
            {
                cola.agregarDato(h[i], lista.lugarDe(temp.dato, temp.pos));
            }
        } while (1);
        return ruta;
    }
#pragma endregion
}

/*
Los métodos de ordenación.
Los métodos de busqueda.
Programas de recursividad, punteros.
Tabla hash
Listas Enlazadas.
Los árboles avl, binario.
El grafo
*/