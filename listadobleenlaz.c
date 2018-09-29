#include <stdlib.h>
#include <stdio.h>
 
typedef struct _nodo {
  
   int valor;
   struct _nodo *siguiente;
   struct _nodo *anterior;
} tipoNodo;
 

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
 
/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);

void insertaCien(Lista *l, int v);
 void recorreInverso(Lista l);
 void desencolar(Lista *l);

 void borrarprimero(Lista *l);
 

int ListaVacia(Lista l);
 
void MostrarLista(Lista l);
 
int main(){
   Lista lista = NULL;
   pNodo p;
   int n;
 
  // insertaCien(&lista,n);
   Insertar(&lista, 20);
   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);

	//recorreInverso(lista);
	

	 
	printf("\n\n");
   MostrarLista(lista);
   
   

      MostrarLista(lista);
 

  /* Borrar(&lista, 10);
   Borrar(&lista, 15);
   Borrar(&lista, 45);
   Borrar(&lista, 30);
   Borrar(&lista, 40);

   MostrarLista(lista);*/
   
   getchar();
   return 0;
}




int ListaVacia(Lista lista) {
   return (lista == NULL);
}


void MostrarLista(Lista lista) {
   pNodo nodo = lista;

   if(ListaVacia(lista)) printf("Lista vacia\n");
   else {
      while(nodo) {
         printf("%d -> ", nodo->valor);
         nodo = nodo->siguiente;
     }
     printf("\n");
   }
}



//en funciones no usar los &
//inserta en una lista 100 numeros aleatorios del 1 a 100
void insertaCien(Lista *lista, int v){
	
int i=0;
pNodo nuevo;

   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;


	while(i<=100){
	
	v=rand()%100+1;
	
    Insertar(lista, v);
	i++;
	}

	
}



void recorreInverso(Lista lista){

pNodo nodo=lista;

	if(nodo){
		recorreInverso(lista->siguiente);
		printf("%d ->", lista->valor);	
	}
	
}


void Insertar(Lista *lista, int v) {
pNodo nuevo, actual;


/* Crear un nodo nuevo */
nuevo = (pNodo)malloc(sizeof(tipoNodo));
nuevo->valor = v;


/* Colocamos actual en la primera posición de la lista */
actual = *lista;
if(actual)
while(actual->anterior)
actual = actual->anterior;


/* Si la lista está vacía o el primer miembro es mayor que el nuevo */
if(!actual) {
/* Añadimos la lista a continuación del nuevo nodo */
nuevo->siguiente = actual;
nuevo->anterior = NULL;

if(actual) actual->anterior = nuevo;
if(!*lista) *lista = nuevo;
}


else {
/* Avanzamos hasta el último elemento*/
while(actual->siguiente)
actual = actual->siguiente;


/* Insertamos el nuevo nodo después del nodo anterior */
nuevo->siguiente = actual->siguiente;
actual->siguiente = nuevo;
nuevo->anterior = actual;
if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;

}


}


void Borrar(Lista *lista, int v) {
// LISTA ORDENADA
pNodo nodo; /* Buscar el nodo de valor v */
nodo = *lista;


while(nodo)
nodo = nodo->siguiente;


while(nodo)
nodo = nodo->anterior;

if(!nodo) return;

/* Borrar el nodo */
/* Si lista apunta al nodo que queremos borrar, apuntar a otro */
if(nodo == *lista)
if(nodo->anterior)
*lista = nodo->anterior;
else
*lista = nodo->siguiente;
if(nodo->anterior) /* no es el primer elemento */
nodo->anterior->siguiente = nodo->siguiente;
if(nodo->siguiente) /* no es el último nodo */
nodo->siguiente->anterior = nodo->anterior;
free(nodo);
}



