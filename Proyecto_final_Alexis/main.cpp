#include <iostream>

using namespace std;

typedef struct nodo  //definimos estructura (NODO)
{
    int dato; //Lista de enteros
    struct nodo *sig; //apuntador al elemento siguiente
    struct nodo *ant; //apuntador al elemento anterior

} NODO; //nombre de la estructura
NODO *CrearNodo(int dato); //prototipo , pasandole el dato que es int dato
int InsertarInicio(NODO **cabeza, int dato); //Prototipo para incertar inicio
int InsertarFinal(NODO **cabeza, int dato);

void ImprimirLista(NODO *cabeza);

int EliminarNodo(NODO **cabeza, int dato);

//implementar
void lista_doble_enlazada() {
    int variable;
    NODO *cabeza = NULL;

    printf("Dame un nodo al inicio ");
    scanf("%d", &variable);
    InsertarInicio(&cabeza, variable);
    printf(" \n Nodo Agregado \n\n ");
    printf("\n");

    printf("Dame un nodo al inicio ");
    scanf("%d", &variable);
    InsertarInicio(&cabeza, variable);
    printf(" \n Nodo Agregado \n\n ");
    printf("\n");

    printf("Dame un nodo al inicio ");
    scanf("%d", &variable);
    InsertarInicio(&cabeza, variable);
    printf(" \n Nodo Agregado \n\n ");
    printf("\n");

    printf("Dame nodo al final ");
    scanf("%d", &variable);
    InsertarFinal(&cabeza, variable);
    printf(" \n Nodo Agregado \n\n ");
    printf("\n");

    printf("Dame nodo al final ");
    scanf("%d", &variable);
    InsertarFinal(&cabeza, variable);
    printf(" \n Nodo Agregado \n\n ");
    printf("\n");

    printf("Dame nodo al final ");
    scanf("%d", &variable);
    InsertarFinal(&cabeza, variable);
    printf(" \n Nodo Agregado \n\n ");
    printf("\n");

    printf("Que nodo quiere borrar?:");
    scanf("%d", &variable);
    printf("Nodo borrado");
    printf("\n");

    EliminarNodo(&cabeza, variable);
    printf("\n");

    ImprimirLista(cabeza);
    printf("\n");

    system("pause>nul");

}

int EliminarNodo(NODO **cabeza, int dato) {
    NODO *actual = *cabeza, *ant = NULL, *sig = NULL;
    //apuntador al nodo y apuntamos a la cabeza
    //Apuntamos el anterior a NULL
    //Apuntamos siguiente a NULL
    while (actual != NULL) {
        if (actual->dato == dato)
            //preguntamos si el dato es el mismo de la funcion
        {
            if (actual == *cabeza) {
                //Delcarmos estas 3 OPCIONES
                //si el Nodo actual es la cabeza
                *cabeza = actual->sig;
                if (actual->sig != NULL)
                    actual->sig->ant = NULL;

            }
                //Si el nodo actual es el ultimo
            else if (actual->sig == NULL) {
                ant = actual->ant;
                actual->ant = NULL;
                ant->sig = NULL;
            }
                //si el nodo actual es intermedio
            else {
                ant = actual->ant;
                actual->ant = NULL;
                sig = actual->sig;
                actual->sig = NULL;
                ant->sig = sig;
                sig->ant = ant;

            }
            free(actual);
            return 1;
        }
        actual = actual->sig;
    }
    return 0;
}

int InsertarFinal(NODO **cabeza, int dato) {
    NODO *nuevo = NULL, *nAux = *cabeza;
    //definimos Nodo, el auxiliar recorrer el ultimo elemento de la lista hasta la cabeza
    nuevo = CrearNodo(dato);
    //creamos nodo poniendo los datos
    if (nuevo != NULL)
        //nuevo es diferente de nul
    {
        while (nAux->sig != NULL)
            //Recorre toda la lista hasta comprobara que es direfente de NULL
        { nAux = nAux->sig; }
        //se reccorre hasta llegar al ultimo de la lista
        nuevo->ant = nAux;
        //Apunta al ultimo de la lista porque lo recorrio al final de la lista
        nAux->sig = nuevo;
        //apunta al nuevo Nodo que creamos
        return 1;

    }

    return 0;

}

void ImprimirLista(NODO *cabeza)//implemetacion
{
    NODO *nAux = cabeza;//Auxilar para que revice la lista y no pierda la cabeza
    while (nAux != NULL)//validamos si existe el elemento
    {
        printf("%d", nAux->dato);//imprimir el datos
        nAux = nAux->sig;//para que imprima todo en la lista (nodos)
    }


}

int InsertarInicio(NODO **cabeza, int dato)//implementacion
{
    NODO *nuevo = NULL;
    nuevo = CrearNodo(dato);
    if (nuevo != NULL) {
        nuevo->sig = *cabeza;// apunta a la cabeza ya que el anteiror no lo hacia
        nuevo->ant = NULL;
        if (*cabeza != NULL) //validacion, si la lista ya tiene un nodo
            (*cabeza)->ant = nuevo; //unimos los datos al nuevo nodo que hacemos
        *cabeza = nuevo;//apunta el nuevo nodo que creamos
        return 1;

    }

    return 0;
}

NODO *CrearNodo(int dato)  //implemetacion
{
    NODO *nuevo = NULL; //inicializamos en NULO
    nuevo = (NODO *) malloc(sizeof(NODO)); //recervamos memoria
    if (nuevo != NULL)//comprobamos si se puede recerbar la memoria
    {
        nuevo->dato = dato;
        nuevo->sig = NULL;
        nuevo->ant = NULL;

    }
    return nuevo; //regresamos el nodo que creamos
}
//segundo programa

int arreglo_apuntadores() {
    int tamanio;
    int i;
    /*se pide al usuario el tamaño del arreglo
     * y se guarda en la variable tamanio
     * */
    printf("Dame el tamanio del arreglo: \n");
    scanf("%d", &tamanio);
    int *arreglo[tamanio];
    int dato[tamanio];
    /*
     * este for ingresa de manera dinamica los datos al arreglo
     * apoyandonos con la variable local i para recorrer cada una de
     * sus posiciones.
     * */
    for ( i = 0; i < tamanio; ++i) {
        /*se va pidiendo al usuario cada una de los valores
         * que se van a guardar en las respectivas posiciones del
         * arreglo
         * */
        printf("\n Dame dato de la poscion %d ", i);
        scanf("%d", &dato[i]);
        /*
         *guarda la direccion de la memoria de la variable*/
        arreglo[i] = &dato[i];
        /*se agrega el contenido del primer puntero
         * */
        *arreglo[i] = dato[i];
    }

    /*Se utiliza un segundo for para imprimir la varibles que hay en el arreglo
     * el cual nos muestar sus valores*/
    for (i = 0; i < tamanio; ++i) {
        /*
         * imprime el contenido del arreglo
         * */
        printf("\n Dato del arreglo %d", *arreglo[i]);

    }


    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    lista_doble_enlazada();
    arreglo_apuntadores();
    return 0;

}
