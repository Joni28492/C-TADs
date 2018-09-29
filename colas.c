#include<stdio.h>
#include<stdlib.h>


typedef elemento;

struct nodo{
	
	elemento id;
	
	struct nodo *siguiente;
		
}tipoNodo;

typedef struct tipoNodo pNodo;

typedef struct tipoNodo *posicion;


typedef struct{
	
	int longitud;
	
	posicion pri, ult;
	
}cola;

//funciones

int vacia(cola);

int encolar(cola*, elemento);

int desencolar(cola*, elemento);

int mostrarCola(cola);

void inicializarCola(cola*);

int tamano(cola);






int main(){
	
	
	
	
	
	
	
	
	
}




void inicializarCola(cola *c){
	
	(*c).pri=NULL;
	(*c).ult=NULL;
	(*c).longitud=0;	
	
	
	printf("\n\n");
}



//funcion para saber si la cola esta vacia

int vacia (cola c){
	
	if(c.longitud<0)
		return -1;
	
	else{
		
		if(c.longitud==0)
			return 1;
			
		else
			return 0;
		
		
	}
	
}


//devolvemos el tamño de la cola

int tamano(cola c){
	
	return c.longitud;
	
}



//añadir elementos a la cola

int encolar(cola *c, elemento v){
	
	
	tipoNodo pNodo;
	
	if(vacia(*c)<0){
		
		
		printf("no existe cola");
		
		return 0;
	
	}
	
	
	else{
		
		
		(*nodo).id=v;
		(*nodo).siguente=NULL;
		
		
		
			if(vacia(*c)==1)
				(*c).ult->siguiente=nodo; //al ser el ultimo elemento igualamos el siguiente a null
				
				
				
			else if(vacia(*c)==0)
				(*c).ult->siguiente=nodo; //se inserta a continuacion del ultimo nodo
		
		
			(*c).ult=nodo; //ultimo elemento añadido a la cola 
			
			(*c).longitud+=1;
			return 1;
		
		
		
		
	}
	
	
	
	
	
	
	
	
}
















