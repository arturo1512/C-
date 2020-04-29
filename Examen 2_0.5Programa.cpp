#include <iostream>

using namespace std;
struct s_caja {
int elemento;
s_caja *hijo_izq;
s_caja *hijo_der;
};
int obtenerNivelUtil(struct s_caja *s_caja, int elemento, int nivel) {
    if (s_caja == NULL)
        return 0;

    if (s_caja->elemento == elemento)
        return nivel;

    int bajarnivel = obtenerNivelUtil(s_caja->hijo_izq, elemento, nivel + 1);
    if (bajarnivel != 0)
        return bajarnivel;

    bajarnivel = obtenerNivelUtil(s_caja->hijo_der, elemento, nivel + 1);
    return bajarnivel;
}
int obtenerNivel(struct s_caja *s_caja, int elemento) {
    return obtenerNivelUtil(s_caja, elemento, 1);
}



int calcularAltura(s_caja *news_caja) {
    int AltIzq, AltDer;

    if (news_caja == NULL)
        return 0;
    else {
        AltIzq = calcularAltura(news_caja->hijo_izq);
        AltDer = calcularAltura(news_caja->hijo_der);

        if (AltIzq > AltDer)
            return AltIzq + 1;
        else
            return AltDer + 1;
    }
}

bool Buscar(s_caja* raiz, int elemento) {
    if (raiz == NULL) return false;
    else if (raiz->elemento == elemento) return true;
    else if (elemento <= raiz->elemento) return Buscar(raiz->hijo_izq, elemento);
    else return Buscar(raiz->hijo_der, elemento);
}






	bool hay_hijo(int n){
    char *lado[2]={"izq","der"};
	cout<<"hay hijo"<<lado[n]<<"?";
	char c;
	cin>>c;
	return c=='s'||c=='S';

}
  s_caja * ConstruyeArbol() {
    s_caja * raiz;
    raiz = new s_caja;
    cout << " \tDato "<<endl;
    cin >> raiz->elemento;
    raiz->hijo_izq = NULL;
    raiz->hijo_der = NULL;
    if( hay_hijo(0) )
    raiz->hijo_izq = ConstruyeArbol();
    if( hay_hijo(1) )
    raiz->hijo_der = ConstruyeArbol();
    return raiz;
 }
 void DestruyeArbol( s_caja *p ) {
   if( p == NULL ) return;
   DestruyeArbol( p->hijo_izq );
   DestruyeArbol( p->hijo_der );
   delete p;
 }
 void imprimeArbol_preOrden( s_caja * p ) {
   if( p == NULL ) return;
   cout << " "<< p->elemento << ", ";
   imprimeArbol_preOrden( p->hijo_izq );
   imprimeArbol_preOrden( p->hijo_der );
   }
 void imprimeArbol_postOrden( s_caja * p ) {
   if( p == NULL ) return;
   imprimeArbol_postOrden( p->hijo_izq );
   imprimeArbol_postOrden( p->hijo_der );
   cout << " "<< p->elemento << ", ";
   }
 void imprimeArbol_entreOrden( s_caja * p ) {
   if( p == NULL ) return;
   imprimeArbol_entreOrden( p->hijo_izq );
   cout << " "<< p->elemento << ", ";
imprimeArbol_entreOrden( p->hijo_der );
}
main() {
s_caja *inicio;

int opcion;
cout<<"\tIngresa los nodos del arbol en pre-orden \n"<<endl;  
cout<< "|""S""""|"" para indicar que si, cualquier otra tecla para  indicar que no. \n"<<endl;
cout<<"Raiz"<<endl;
inicio = ConstruyeArbol();
while(true){
do{
cout << " \n Para imprimir el arbol, indica el recorrido: \n"<<endl;
cout<< " 1: pre-orden: raiz-izq-der \n"<<endl;
cout<< " 2: post-orden: izq-der-raiz \n"<<endl;
cout<< " 3: entre-orden: izq-raiz-der \n"<<endl;
cout<< " 3: entre-orden: izq-raiz-der \n"<<endl;
cout<< " 4: salir \n"<<endl;
cin >> opcion;
}while( opcion < 1 || opcion > 4);
switch(opcion){
case 1: cout << " El arbol en pre-orden es: \n";
imprimeArbol_preOrden(inicio);
break;
case 2: 
cout << "\t(2)MOSTRAR LA ALTURA DEL ARBOL"<<endl;
int altura;
                altura = calcularAltura(inicio);
                cout << "\n" "La altura del arbol es: " << altura;

                break;
//cout << " El árbol en post-orden es: \n";
//imprimeArbol_postOrden(inicio);*/
break;
case 3:
	 cout << "\t(3)BUSCAR UN NUMERO EN EL ARBOL"<< endl;
  int numero;
                cout << "Ingrese el numero que desea buscar:\n";
                cin >> numero;
                if (Buscar(inicio, numero) == true) cout << "Nodo encontrado\n";
                else cout << "Nodo no encontrado\n";


// cout << " El arbol en entre-orden es: \n";
//imprimeArbol_entreOrden(inicio);
break;
case 4:
	cout << "\t(7)Calcular el Nivel dado un nodo"<<endl;
	         int numeron;
     cout << "Ingrese el numero que desea buscar:\n";
     cin >> numeron;
                 int obNivel,nivel; 
     nivel = obtenerNivel(inicio,numero);
     obNivel = obtenerNivel (inicio,numero);
      if (nivel)
      cout << "\n" "El nivel del nodo " << numero << " es:" << obNivel;  
           else
      cout << "\n" "El elemento" << numero << " no está presente en el arbol";
     break;



// DestruyeArbol( inicio );
return 0;
};
};
}
