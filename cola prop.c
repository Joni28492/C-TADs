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

}COLA;




void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
 
int ListaVacia(Lista l);
void desencolar(Lista *l);
 
void MostrarLista(Lista l);


 
int main() {
   Lista lista = NULL;
   pNodo p;
 
   Insertar(&lista, 20);
   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);

  
   MostrarLista(lista);
   desencolar(&lista);
   
   
  /* Borrar(&lista, 10);
   Borrar(&lista, 15);
   Borrar(&lista, 45);
   Borrar(&lista, 30);
   Borrar(&lista, 40);*/

   MostrarLista(lista);
   
   getchar();
   return 0;
}


void crear_cola(COLA *C){

	(*C).prim=NULL;

	(*C).ult=NULL;

	(*C).longitud=0;

	printf("\nSe ha creado una cola vacia\n");

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


int tamano(COLA C){

	return C.longitud;

}



void desencolar(Lista *lista){

pNodo nodo;

nodo=*lista;

  if(ListaVacia(*lista)) printf("Lista vacia\n");
  return;

	if(listaVacia==1 && tamano==1){
		void crear_cola(*lista);
		

	
	}

}
