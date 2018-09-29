/*

Jonathan Fernandez López
1º videojuegos
06/02/2015



practica 01 
programacion 2


*/

#include<stdio.h>
#include<time.h>
#include<string.h>


horaEntrada(){
		
	time_t current_time;
struct tm * time_info;
char timeString[9];  //  "HH:MM:SS\0"

time(&current_time);
time_info = localtime(&current_time);

strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
puts(timeString);

}

	
	
/*struct cola{
	int id;
	char time[8]// hh:mm:ss
	
};*/



/*struct nodo {
int dato;
struct nodo *siguiente;
};
*/


//definimos un tipo nodo
typedef struct  {
struct cola *siguiente;
int id;
char* time[8];


}cola;
//hacemos que el primer y ultimo elemento apunten a null
cola *primero=NULL;
cola *ultimo=NULL;


/*void encolar(){


	// Crear un nodo nuevo 
pNodo nodo;
nodo = (pNodo) malloc(sizeof(tipoNodo));

int prioridad;
printf("insertar prioridad: ");
scanf("%i", &prioridad);




nodo->id =prioridad//damos valor de prioridad
nodo->time=//hora del sistema 
nodo->siguiente = *lista;
// Ahora, el comienzo de nuestra lista
//es el nuevo nodo 
*lista = nodo;
	
}*/


void encolar(pNodo *primero, pNodo *ultimo, int v) {
	
pNodo nuevo; /* Crear un nodo nuevo */
nuevo = (pNodo)malloc(sizeof(tipoNodo));
nuevo->valor = v;

/* Este será el último nodo, no debe tener siguiente */
nuevo->siguiente = NULL;


/* Si la cola no estaba vacía, añadimos el nuevo a
continuación de ultimo */
if(*ultimo)
(*ultimo)->siguiente = nuevo;

/* Ahora, el último elemento de la cola es el
nuevo nodo */
*ultimo = nuevo;

/* si primero es NULL */
if(!*primero)
*primero = nuevo;
}


int desencolar(){
	
	while(lista!=NULL)
		lista=lista->siguiente;

	
	
}


void verCola(){
	
	
	
	
	
	
	
}


int main(){
	
	int n;
	
	
	printf("1 usuario accede a la compra\n"
			"2 usuario finaliza compra\n"
			"3 ver cola\n"
			"4 salir\n");
	scanf("%i", &n);

	while(n<1 || n>4){
		printf("cuelve a introducir opcion: ");
		scanf("%i", &n);
	}
	
	if(n==1){
		
	}
	
	if(n==2){
		
	}
	
	if(n==3){
		
	}
	
	else


	
	
system("PAUSE");
}
