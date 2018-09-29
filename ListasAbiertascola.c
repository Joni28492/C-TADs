#include <stdlib.h>
#include <stdio.h>
 
typedef struct _nodo {
   int valor;
 
   struct _nodo *siguiente;
  
} tipoNodo;
 

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
 
 typedef struct _nodo *posicion; /* La cola es un puntero a nodo */
 
 typedef struct {

	int longitud;

	posicion prim, ult;

}LISTA;


void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
 
int ListaVacia(Lista l);
void desencolar(Lista *l);
 
void MostrarLista(Lista l);

void inicializarLista(LISTA *L);
 
int main() {
   Lista lista = NULL;
   pNodo p;
   
   
    inicializarLista(LISTA *L);
 
   Insertar(&lista, 20);
   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);

  
   MostrarLista(lista);
 
   
   
  /* Borrar(&lista, 10);
   Borrar(&lista, 15);
   Borrar(&lista, 45);
   Borrar(&lista, 30);
   Borrar(&lista, 40);*/

   MostrarLista(lista);
   
   getchar();
   return 0;
}





void inicializarLista(LISTA *L){

	(*L).prim=NULL;

	(*L).ult=NULL;

	(*L).longitud=0;

}

//insertar funciona
void Insertar(Lista *lista, int v) {
   pNodo nuevo, anterior;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   
   /* Si la lista está vacía */
   if(ListaVacia(*lista) || (*lista)) {
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

void RecorreLista(Lista lista){

pNodo nodo = lista;

 if(ListaVacia(lista)) printf("Lista vacia\n");
 
 	while(nodo){
 
  	 nodo = nodo-> siguiente;	
 	
	 }




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




/*Implementarunprogramaquehagalosiguiente:
1. Debe generar 100 números al azar. A medida que los crea los debe insertar en una listasimplementeenlazadaordenada.
2. Acontinuaciónrecorrerlalistamostrandosuselementos*/


/*void cienNumeros(Lista lista, int v){

int i, n;

	for(i=0; i<=100; i++){
	n=rand()%100+1;
	insertar(&lista, n);
	}

}*/





