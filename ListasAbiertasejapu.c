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

void Insertar(Lista *lista, int v) {
   pNodo nuevo, anterior;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   
   /* Si la lista está vacía */
   if(ListaVacia(*lista) || (*lista)->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *lista; 
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *lista = nuevo;
   } else {
      /* Buscar el nodo de valor menor a v */
      anterior = *lista;
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v */
      while(anterior->siguiente && anterior->siguiente->valor <= v) 
         anterior = anterior->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
   }
}

void Borrar(Lista *lista, int v) {
   pNodo anterior, nodo;
   
   nodo = *lista;
   anterior = NULL;
   while(nodo && nodo->valor < v) {
      anterior = nodo; 
      nodo = nodo->siguiente;
   }
   if(!nodo || nodo->valor != v) return;
   else { /* Borrar el nodo */
      if(!anterior) /* Primer elemento */
         *lista = nodo->siguiente;
      else  /* un elemento cualquiera */
         anterior->siguiente = nodo->siguiente;
      free(nodo);
   }   
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


//funcion de desencole
/*void desencolar(Lista *lista){
	
	pNodo nodo, primero, ultimo;
	 
	primero= NULL;
	ultimo=NULL;
	nodo=*lista;
	
	while(nodo!=NULL){
		primero=nodo;
		nodo=nodo->siguiente;
	}
	
	
	if(!nodo) return;
	
	else{
		if(!primero){
			*lista=nodo->siguiente;
		}
		free(nodo);
	}
	
}*/


void borrarprimero(Lista *lista){
	
	pNodo anterior, nodo;
	anterior = NULL;
	
	while(nodo){
		anterior=nodo;
		nodo=nodo->siguiente;
	}
	
	if(!nodo) return;
	
	else{
		if(!anterior){
			*lista = nodo->siguiente;
		}
		free(nodo);
	}
}





