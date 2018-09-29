#include <stdio.h>

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

// Funciones con listas:
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
void BorrarLista(Lista *);
void MostrarLista(Lista l);

int main() {
   Lista lista = NULL;
   pNodo p;

   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);
   Insertar(&lista, 20);
   Insertar(&lista, 50);

   MostrarLista(lista);

   Borrar(&lista, 30);
   Borrar(&lista, 50);

   MostrarLista(lista);

   BorrarLista(&lista);
   getchar();
   return 0;
}

void Insertar(Lista *lista, int v) {
   pNodo nodo;

   // Creamos un nodo para el nuvo valor a insertar
   nodo = (pNodo)malloc(sizeof(tipoNodo));
   nodo->valor = v;

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(*lista == NULL) *lista = nodo;
   else nodo->siguiente = (*lista)->siguiente;
   // En cualquier caso, cerramos la lista circular
   (*lista)->siguiente = nodo;
}

void Borrar(Lista *lista, int v) {
   pNodo nodo;

   nodo = *lista;

   // Hacer que lista apunte al nodo anterior al de valor v
   do {
      if((*lista)->siguiente->valor != v) *lista = (*lista)->siguiente;
   } while((*lista)->siguiente->valor != v && *lista != nodo);
   // Si existe un nodo con el valor v:
   if((*lista)->siguiente->valor == v) {
      // Y si la lista sólo tiene un nodo
      if(*lista == (*lista)->siguiente) {
         // Borrar toda la lista
         free(*lista);
         *lista = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo  de valor v
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
         free(nodo);
      }
   }
}

void BorrarLista(Lista *lista) {
   pNodo nodo;

   // Mientras la lista tenga más de un nodo
   while((*lista)->siguiente != *lista) {
      // Borrar el nodo siguiente al apuntado por lista
      nodo = (*lista)->siguiente;
      (*lista)->siguiente = nodo->siguiente;
      free(nodo);
   }
   // Y borrar el último nodo
   free(*lista);
   *lista = NULL;
}

void MostrarLista(Lista lista) {
   pNodo nodo = lista;

   do {
      printf("%d -> ", nodo->valor);
      nodo = nodo->siguiente;
   } while(nodo != lista);
   printf("\n");
}
