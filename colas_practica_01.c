/*
autor:Jonathan Fernández López
fuente: colas(practica 01)
fecha:06/02/2015
ultima revision:22/06/2015
	
*/





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>





typedef struct _nodo {

 int id; 
 char time[8];
 struct _nodo *siguiente; 

} tipoNodo; 
 
typedef tipoNodo *pNodo;
typedef tipoNodo *Cola;


/* Funciones con colas: */ 
void Anadir(pNodo *primero, pNodo *ultimo, int v); 
int Leer(pNodo *primero, pNodo *ultimo);
void MostrarCola(pNodo *primero);



horaEntrada(){
		
	time_t current_time;
struct tm * time_info;
char timeString[9];  //  "HH:MM:SS\0" se utilizan nueve porque con [8] da problemas

time(&current_time);
time_info = localtime(&current_time);

strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
puts(timeString);

}


int main() {
  pNodo primero = NULL;
  pNodo ultimo = NULL;
int n, v=0;
char time[8];
Cola cola;

	while(1){
		printf("\n\n1. acceder a la cola\n"
				"2. finalizar compra\n"
				"3. ver cola\n"
				"4. salir\n");

		printf("\nintroduce opcion: ");
		scanf("%i", &n);


		while(n<1 || n>4){
	
		printf("vuelve a introducir opcion: ");
		scanf("%i", &n);

		}

		
		if(n==1){
			
			v++;
		
			Anadir(&primero, &ultimo, v);
			printf("\nencolamos(%i)\n", v);
			horaEntrada();
		
			continue;
		
		
		
		}
		
		
		
		if(n==2){
			
			printf("\ndesencolamos: %d\n", Leer(&primero, &ultimo));
			horaEntrada();
			continue;
		}
		
		
		if(n==3){
			printf("\n\n");
			MostrarCola(&primero);
			continue;
		
		}
		
		
		
		if(n==4){
			break;
		}



	}


getchar();

return 0;
}





//funcion encolar
void Anadir(pNodo *primero, pNodo *ultimo, int v) {
pNodo nuevo;


 // Crear un nodo nuevo 
nuevo = (pNodo)malloc(sizeof(tipoNodo));



 nuevo->id = v; /* Este será el último nodo, no debe tener siguiente */
 nuevo->siguiente = NULL; /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
 
  if(*ultimo)
   (*ultimo)->siguiente = nuevo; /* Ahora, el último elemento de la cola es el nuevo nodo */ 
   *ultimo = nuevo;
   
    /* si primero es NULL */
    if(!*primero)
	 *primero = nuevo;
}




	

//funcion desencolar
int Leer(pNodo *primero, pNodo *ultimo) {
 pNodo nodo; /* variable auxiliar para manipular nodo */ 
 int v; /* variable auxiliar para retorno */


/* Nodo apunta al primer elemento de la cola*/
 nodo = *primero; 
 	if(!nodo) 
	 return 0;
  /* Si no hay nodos en la cola retornamos 0 */ 


  /* Asignamos a primero la dirección del segundo nodo */
   *primero = nodo->siguiente;
    /* Guardamos el valor de retorno */ 
	v = nodo->id;
	
	 /* Borrar el nodo */ 
	 free(nodo); /* Si la cola quedó vacía, ultimo debe ser NULL también*/
	 
	  if(!*primero)
	   *ultimo = NULL;
	
	
	return v;
}


void MostrarCola(pNodo *primero) {
pNodo nodo = *primero;


	while(nodo!= NULL){
	
	printf("%d ->", nodo->id);
	nodo=nodo->siguiente;
	}

	printf("NULL");
}

