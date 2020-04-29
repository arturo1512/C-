#include <iostream>
int bandera = 0;
using namespace std;

struct s_caja {
	int elemento;
	s_caja *hijo_izq;
	s_caja *hijo_der;
};

bool hay_hijo(int n)
{
	char *lado[2] = {"IZQ", "DER"};

	cout << "HAY HIJO" << "," << lado[n] << "?";
	cout << "\nOPRIME 'S' SI AHI HIJO OPRIME CUALQUIER TECLA PARA INDICAR QUE NO Y CONTINUA" << endl;
	char c;
	cin>>c;

	return c == 's' || c == 'S';

}

s_caja * ConstruyeArbol()
{
	s_caja * raiz;
	raiz = new s_caja;
	cout << " DATO: ";
	cin >> raiz->elemento;
	raiz->hijo_izq = NULL;
	raiz->hijo_der = NULL;
	if (hay_hijo(0))
		raiz->hijo_izq = ConstruyeArbol();
	if (hay_hijo(1))
		raiz->hijo_der = ConstruyeArbol();
	return raiz;
}

void DestruyeArbol(s_caja *p)
{
	if (p == NULL) return;
	DestruyeArbol(p->hijo_izq);
	DestruyeArbol(p->hijo_der);
	delete p;
}

void imprimeArbol_preOrden(s_caja * p)
{
	if (bandera == 0) {
		cout << "\t\t\t";
		bandera = bandera + 1;
	}

	if (p == NULL) return;
	cout << "\t " << p->elemento << ", ";
	cout << "\n";
	imprimeArbol_preOrden(p->hijo_izq);
	imprimeArbol_preOrden(p->hijo_der);
}

void imprimeArbol_postOrden(s_caja * p)
{
	if (p == NULL) return;
	imprimeArbol_postOrden(p->hijo_izq);
	imprimeArbol_postOrden(p->hijo_der);
	cout << " " << p->elemento << ", ";
}

void imprimeArbol_entreOrden(s_caja * p)
{
	if (p == NULL) return;
	imprimeArbol_entreOrden(p->hijo_izq);
	cout << " " << p->elemento << ", ";
	imprimeArbol_entreOrden(p->hijo_der);
}


int main()
{
	int *raiz, buscado, i, linf, lsup, mitad, Tamanio;
	s_caja *inicio;
	int opcion;
	cout << "\t\t ARBOL BINIARIO " << endl;
	cout << "Ingresa los nodos del arbol en pre-orden \n" << endl;
	cout << "Para cada nodo indicar si tiene un subarbol izq. y der" << endl;
	cout << " ""S"" para indicar que si, cualquier otra tecla para  indicar que no \n" << endl;
	cout << "DAME NODO RAIZ" << endl;
	inicio = ConstruyeArbol();
	while (true) {
		do {
			cout << " \n Para imprimir el arbol, indica el recorrido: \n" << endl;
			cout << " 1.- pre-orden: raíz-izq-der \n" << endl;
			cout << " 2.- post-orden: izq-der-raíz \n" << endl;
			cout << " 3.- entre-orden: izq-raíz-der \n" << endl;
			cout << " 4.- salir \n" << endl;
			cout << "5.-buscar en el arbol"<<endl;
			cin >> opcion;
		} while (opcion < 1 || opcion > 4);
		switch (opcion) {
		case 1: cout << " El arbol en pre-orden es: \n";
			imprimeArbol_preOrden(inicio);
			break;
		case 2: cout << " El árbol en post-orden es: \n";
			imprimeArbol_postOrden(inicio);
			break;
		case 3: cout << " El arbol en entre-orden es: \n";
			imprimeArbol_entreOrden(inicio);
			break;
		case 4:
		    DestruyeArbol(inicio);
			break;
		case 5: 
		int Buscar(s_caja p, int dat) {
   raiz = a;

   while(!NULL(raiz)) {
      if(elemento == p->elemento) 
	  return TRUE;
      else if(elemento < p->elemento) raiz = p->hijo_izq;  
      else if(elemento > p->elemento) raiz = p->hijo_der; 
   }
   return FALSE; 
}
			return 0;
		};
	};
}
