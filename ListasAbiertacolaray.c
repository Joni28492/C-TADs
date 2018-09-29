#include <stdlib.h>
#include <stdio.h>
 
typedef struct _nodo {
  
   int valor;
   char time[8];
   struct _nodo *siguiente;
   struct _nodo *anterior;
} tipoNodo;
 

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

tipoNodo *primero=NULL;
tipoNodo *ultimo=NULL;
 
/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
 void recorreInverso(Lista l);



 

int ListaVacia(Lista l);
 
void MostrarLista(Lista l);
 
int main(){
   Lista lista = NULL;
   pNodo p;
   int n;

   Insertar(&lista, 20);
   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);


	

	 
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
 
   // Crear un nodo nuevo 
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   
   // Si la lista está vacía 
   if(ListaVacia(*lista)) {
      //al estar vacia igualamos el primer y ultimo elemento
      nuevo->siguiente = NULL; 
      nuevo->anterior=NULL;
      
      primero=nuevo;
      ultimo=nuevo;
      
     
   } 
   
   else {
      //al haber elementos en la lista lo colocamos a continuacion del ultimo
      ultimo->siguiente=nuevo;
      ultimo=nuevo;
      
      
   }
}

void Borrar(Lista *lista, int v) {
   pNodo anterior, nodo;
   
   nodo->valor=v;
   
   nodo = *lista;
   anterior = NULL;
   while(nodo) {
      anterior = nodo; 
      nodo = nodo->siguiente;
   }
   if(!nodo) return;
   
   else { /* Borrar el nodo */
     ultimo->siguiente->anterior=ultimo->anterior;
     ultimo->anterior=ultimo;
     
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















