#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///ESTRUCTURAS
typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;

typedef struct nodoArbol
{
    persona dato;
    struct nodoArbol* derec;
    struct nodoArbol* izq;
} nodoArbol;

typedef struct
{
    persona dato;
    struct nodoSimple* siguiente;
} nodoSimple;

/// PROTOTIPADO
/// Arboles
nodoArbol* iniclista();
nodoArbol* crearNodo(persona informacion);
nodoArbol* agregarAlArbolPorLegajo (nodoArbol* arbol, nodoArbol* nuevoNodo);
nodoArbol* cargarArbol (nodoArbol* arbol);
void mostrarArbolPersona(nodoArbol* arbol);
void mostrarUno(nodoArbol* arbol);
nodoArbol* buscarDatoArbol (nodoArbol* arbol,int legajo);
nodoArbol* buscarDatoArbolPorNombre (nodoArbol* arbol,char nombre[]);
int alturaArbol (nodoArbol* arbol);
int cantDeNodo (nodoArbol* arbol);
int cantHojas (nodoArbol* arbol);
nodoArbol* borrarHojas (nodoArbol* arbol, int legajoBorrar);
nodoArbol* nodoMasIzquierda(nodoArbol* arbol);
nodoArbol* borrarNodo(nodoArbol* arbol, int borrar);

///Lista Simple
nodoSimple* pasarDatos(nodoArbol* arbol,nodoSimple* lista);
void mostrarListaSimple(nodoSimple* lista);
void mostrarUnoSimple(nodoSimple* lista);



///             Árbol Binario de Búsqueda (ABB)
int main()
{
    nodoArbol* arbol = iniclista();;
    arbol=cargarArbol(arbol);

    mostrarArbolPersona(arbol);

//    printf("\nEJERCICIO PASAR DATOS:");
//    nodoSimple* lista = NULL;
//    lista=pasarDatos(arbol,lista);
//    printf("\nLISTA:");
//    mostrarListaSimple(lista);

//    int legajoBuscar;
//    printf("\nIngrese el legajo a buscar: ");
//    scanf("%i",&legajoBuscar);
//    nodoArbol* rta= buscarDatoArbol(arbol,legajoBuscar);
//    mostrarUno(rta);

//    char nombreBuscar[20];
//    printf("\nIngrese el nombre a buscar: ");
//    scanf("%s", nombreBuscar);
//    nodoArbol* rtaNombre = buscarDatoArbolPorNombre(arbol,nombreBuscar);
//    mostrarUno(rtaNombre);

//    int alturaDelArbol;
//    alturaDelArbol= alturaArbol(arbol);
//    printf("ALTURA: %i\n", alturaDelArbol);
//
//    int cantNodos;
//    cantNodos= cantDeNodo(arbol);
//    printf("CANTIDAD DE NODOS: %i\n", cantNodos);

//    int cantidadHojas;
//    cantidadHojas= cantHojas(arbol);
//    printf("CANTIDAD DE HOJAS: %i", cantidadHojas);

/// Borrar nodo
    int legajoBorrar = 43;
    arbol = borrarNodo(arbol, legajoBorrar);
    printf("\n\nNUEVO ARBOL: \n\n");
    mostrarArbolPersona(arbol);







    return 0;
}




///FUNCIONES

nodoArbol* iniclista()
{
    return NULL;
}

void mostrarMenorAMayor(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        mostrarMenorAMayor(arbol->izq);
        printf("%d - ", arbol->dato);
        mostrarMenorAMayor(arbol->derec);
    }
}

nodoArbol* crearNodo(persona informacion)
{

    nodoArbol* aux= (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->dato= informacion;
    aux->derec=NULL;
    aux->izq=NULL;

    return aux;
}

nodoArbol* agregarAlArbolPorLegajo (nodoArbol* arbol, nodoArbol* nuevoNodo)
{
    if(arbol==NULL)
    {
        arbol=nuevoNodo;

    }
    else if (nuevoNodo->dato.legajo <= arbol->dato.legajo)
    {
        arbol->izq= agregarAlArbolPorLegajo(arbol->izq, nuevoNodo);
    }
    else
    {
        arbol->derec= agregarAlArbolPorLegajo(arbol->derec, nuevoNodo);
    }
    return arbol;
}

nodoArbol* cargarArbol (nodoArbol* arbol)
{
    persona informacion;

    for (int i=0; i<6 ; i++)
    {
        printf("NOMBRE: ");
        fflush(stdin);
        gets(informacion.nombre);
        printf("EDAD:");
        scanf("%i", &informacion.edad);
        printf("LEGAJO:");
        scanf("%i", &informacion.legajo);

        nodoArbol* nuevo= crearNodo(informacion);
        arbol= agregarAlArbolPorLegajo(arbol, nuevo);


    }

    return arbol;
}

void mostrarArbolPersona(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        mostrarArbolPersona(arbol->izq);
        mostrarUno(arbol);
        mostrarArbolPersona(arbol->derec);
    }
}

void mostrarUno(nodoArbol* arbol)
{
    printf("NOMBRE: %s - ", arbol->dato.nombre);
    printf("\tEDAD:%i - ", arbol->dato.edad);
    printf("\tLEGAJO:%i - ", arbol->dato.legajo);
    printf("\n");
}

nodoSimple* crearNodoSimple(persona info)
{
    nodoSimple* aux = (nodoSimple*)malloc(sizeof(nodoSimple));
    aux->dato = info;
    aux->siguiente = NULL;
    return aux;
}

nodoSimple* agregarPpioSimple(nodoSimple* lista, nodoSimple* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

nodoSimple* pasarDatos(nodoArbol* arbol, nodoSimple* lista)
{
    if(arbol != NULL)
    {
        nodoSimple* nuevo = crearNodoSimple(arbol->dato);
        lista = agregarPpioSimple(lista, nuevo);

        lista = pasarDatos(arbol->izq,lista);
        lista = pasarDatos(arbol->derec,lista);
    }

    return lista;
}

void mostrarListaSimple(nodoSimple* lista)
{
    nodoSimple* aux = lista;
    while(aux)
    {
        mostrarUnoSimple(aux);
        aux = aux->siguiente;
    }
}

void mostrarUnoSimple(nodoSimple* lista)
{
//    printf("\nNOMBRE: %s", lista->dato.nombre);
//    printf("\tEDAD: %i", lista->dato.edad);
    printf("\tLEGAJO: %i", lista->dato.legajo);
}

nodoArbol* buscarDatoArbol (nodoArbol* arbol,int legajo)
{
    nodoArbol* rta;

    if(arbol !=NULL)
    {
        if(arbol->dato.legajo== legajo)
        {
            rta=arbol;
        }
        else
        {
            if(legajo >= arbol->dato.legajo)
                rta= buscarDatoArbol(arbol->derec, legajo);
            else
                rta= buscarDatoArbol(arbol->izq, legajo);
        }
    }

    return rta;
}

nodoArbol* buscarDatoArbolPorNombre (nodoArbol* arbol,char nombre[])
{
    nodoArbol* rta;

    if(arbol !=NULL)
    {
        if(strcmp(arbol->dato.nombre, nombre)==0)
        {
            rta=arbol;
        }
        else
        {
            if(strcmp(nombre,arbol->dato.nombre)<0)
                rta= buscarDatoArbolPorNombre(arbol->derec, nombre);
            else
                rta= buscarDatoArbolPorNombre(arbol->izq, nombre);
        }
    }

    return rta;
}

int alturaArbol (nodoArbol* arbol)
{
    int rta;
    int rta2;

    if(arbol!=NULL)
    {
        rta=1+alturaArbol(arbol->izq);
        rta2=1+alturaArbol(arbol->derec);

    }

    if(rta<rta2)
        rta=rta2;

    return rta;
}

int cantDeNodo (nodoArbol* arbol)
{
    int rta=1;

    if(arbol ==NULL)
    {
        rta=0;
    }
    else
    {
        rta= rta+cantDeNodo(arbol->derec)+ cantDeNodo(arbol->izq);
    }

    return rta;
}

int cantHojas (nodoArbol* arbol)
{
    int i=0;
    if(arbol!=NULL)
    {
        if(arbol->izq==NULL && arbol->derec==NULL)
        {
            i=1;
        }
        else
        {
            i=i+cantHojas(arbol->izq);
            i=i+cantHojas(arbol->derec);
        }
    }
    return i ;
}

nodoArbol* borrarHojas (nodoArbol* arbol,int nodoBorrar)
{
    if(arbol!=NULL)
    {
        nodoArbol* aux= arbol;
        if(arbol->dato.legajo == nodoBorrar && arbol->derec== NULL && arbol->izq==NULL)
        {
            free(aux);

        }
        if(arbol->dato.legajo < nodoBorrar)
            arbol->derec = borrarHojas(arbol->derec, nodoBorrar);
        else
            arbol->izq = borrarHojas(arbol->izq, nodoBorrar);
    }

    return arbol;
}

nodoArbol* borrarNodo(nodoArbol* arbol, int borrar)
{
    if (arbol)
    {
        if(arbol->dato.legajo == borrar)
        {
            if(arbol->izq != NULL && arbol->derec != NULL) //dos hijos
            {
                nodoArbol* masIzq = nodoMasIzquierda(arbol->derec); //busco al nodo mas izquierda DE LA DERECHA o el nodo mas derecha DE LA IZQUIERDA. Siempre el mas cercano al centro
                arbol->dato = masIzq->dato;
                arbol->derec = borrarNodo(arbol->derec, arbol->dato.legajo);
            }
            else
            {
                nodoArbol* aux = arbol;
                if(arbol->derec == NULL && arbol->izq == NULL) //nodo hoja (sin hijos)
                    arbol = NULL;
                else if (arbol->izq != NULL && arbol->derec == NULL) // solo un hijo
                    arbol = arbol->izq;
                else  // solo un hijo
                    arbol = arbol->derec;
                free(aux);
            }
        }
        else
        {
            if(arbol->dato.legajo > borrar)
                arbol->izq = borrarNodo(arbol->izq, borrar);
            else
                arbol->derec = borrarNodo(arbol->derec, borrar);
        }
    }
    return arbol;
}

nodoArbol* nodoMasIzquierda(nodoArbol* arbol)
{
    if(arbol->izq!=NULL)
    {
        arbol = nodoMasIzquierda(arbol->izq);
    }
    return arbol;
}
