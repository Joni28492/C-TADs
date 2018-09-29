#include<stdio.h>
#define MAX_NODOS 10
#define INFINITO 32000

int numNodos;  //Nº nodos del grafo



struct info {
	
	float distancia;
	int intensidad_trafico; //vehiculos minuto
	int calidad_via; //1..5 valores del 1 al 5, 1 malo, 5 muy bueno
	float coste; //coste economico de transitar la via 
	
};






void iniNodos(char n[MAX_NODOS]){
// Inicializa o vacía la matriz de nodos con espacios
  int i;
  for(i=0; i<MAX_NODOS; i++)
     n[i]=' ';
  numNodos=0;        
}






void iniAdyacencia( struct info a[MAX_NODOS][MAX_NODOS]){
// Inicializa la matriz de adyacencia (pesos)
  int i,j;
  for(i=0; i<MAX_NODOS; i++)     
    for(j=0; j<MAX_NODOS; j++){
    
        a[i][j].distancia=INFINITO;  
        a[i][j].intensidad_trafico=0; 
        a[i][j].calidad_via=0; 
        a[i][j].coste=INFINITO; 
	
	}
}






int posNodo(char n[MAX_NODOS], char nodo){
/* Busca nodo en la matriz de nodos y retorna su
   posición. Caso de no existir, devuelve -1
*/
   int i;
   
   for(i=0; i<MAX_NODOS; i++)
     if(n[i]==nodo)
        return i;
   
   return -1;        
}







void addNodo(char n[MAX_NODOS],struct info A[MAX_NODOS][MAX_NODOS]){
   int pos;
   char nuevoNodo;
   
   if(numNodos!=MAX_NODOS){  //Hay espacio
      printf("Introduce el nuevo nodo: ");
      fflush(stdin);
      scanf("%c",&nuevoNodo);                          
      pos=posNodo(n, nuevoNodo); //¿Existe ya?
      
      if(pos>=0){
         printf("El nodo ya existe\n");
      }  
      else
      {
        n[numNodos]=nuevoNodo; //Lo almacenamos
        A[numNodos][numNodos].distancia=0;
        A[numNodos][numNodos].coste=0;
         numNodos++;    
      }                       
   }                                              
   else  //No hay espacio
   {
     printf("No hay espacio disponible\n");
   }
}











void addArista(char n[MAX_NODOS],  struct info a[MAX_NODOS][MAX_NODOS]){

   int posOrigen, posDestino;
   char origen, destino;
   float distancia, coste;
   int calidad, intensidad;
   
   //Leemos los nodos origen y destino
   printf("Nodo origen: ");
   fflush(stdin);
   scanf("%c",&origen);
   printf("Nodo destino: ");
   fflush(stdin);
   scanf("%c",&destino);
   
   //Miramos si existen en la matriz de nodos
   posOrigen=posNodo(n,origen);
   posDestino=posNodo(n,destino);   
   
   if(posOrigen<0 || posDestino<0){
      printf("Al menos uno de los nodos no existe\n");
   }
   else
   {
      printf("distancia: ");
      fflush(stdin);
      scanf("%f", &distancia);
      printf("intensida de trafico: ");
      fflush(stdin);
      scanf("%i", &intensidad);
      printf("calidad de la via: ");
      fflush(stdin);
      scanf("%i", &calidad);
      printf("coste: ");
      fflush(stdin);
      scanf("%f", &coste);
      
      a[posOrigen][posDestino].distancia=distancia;
      a[posOrigen][posDestino].intensidad_trafico=intensidad;
      a[posOrigen][posDestino].calidad_via=calidad;
      a[posOrigen][posDestino].coste=coste;
   }
                
}








void verNodos(char n[MAX_NODOS]){
  int i;
  for(i=0; i<MAX_NODOS; i++)
     printf("%c\t", n[i]); 
  printf("\n");   
}












void verGrafo(char nodos[MAX_NODOS],struct info A[MAX_NODOS][MAX_NODOS],int tipo){
   int i,j;
   
   /*
   tipo=1 muestra distancias
   tipo=2 muestra intensidad de trafico 
   tipo=3 muestra calida de la via 
   tipo=4 muestra el coste (€)
   */
   
   
   
   printf("\t");
   verNodos(nodos);
   
   switch(tipo){
   
   
   		case 1:
   		
   		for(i=0; i<numNodos; i++){
    	 	 printf("%c\t", nodos[i]);
      		for(j=0; j<numNodos; j++){
      		
      	  				if(A[i][j].distancia ==INFINITO){
							printf("INF.\t");
         				}
         	
			 			else{
         					printf("%f\t",A[i][j].distancia);
        	 			}
      			
      					break;
         
     			}
      		}
    	  	printf("\n");
   		
   			break;
   		
   		
   		
   		
   		case 2:
   		
   		for(i=0; i<numNodos; i++){
    	 	 printf("%c\t", nodos[i]);
      		for(j=0; j<numNodos; j++){
      		
      	  				if(A[i][j].intensidad_trafico==INFINITO){
							printf("INF.\t");
         				}
         	
			 			else{
         					printf("%i\t",A[i][j].intensidad_trafico);
        	 			}
      			
      					break;
         
     			}
      		}
    	  	printf("\n");
   		
   			break;
   		
   		
   		
   		case 3:
   		
   		for(i=0; i<numNodos; i++){
    	 	 printf("%c\t", nodos[i]);
      		for(j=0; j<numNodos; j++){
      		
      	  				if(A[i][j].calidad_via ==INFINITO){
							printf("INF.\t");
         				}
         	
			 			else{
         					printf("%i\t",A[i][j].calidad_via);
        	 			}
      			
      					break;
         
     			}
      		}
    	  	printf("\n");
   		
   			break;
   		
   		case 4:
   		
   		for(i=0; i<numNodos; i++){
    	 	 printf("%c\t", nodos[i]);
      		for(j=0; j<numNodos; j++){
      		
      	  				if(A[i][j].coste==INFINITO){
							printf("INF.\t");
         				}
         	
			 			else{
         					printf("%f\t",A[i][j].coste);
        	 			}
      			
      					break;
         
     			}
      		}
    	  	printf("\n");
   		
   			break;
   		
	}
}










int gradoSalida(   struct info A[MAX_NODOS][MAX_NODOS], char nodos[MAX_NODOS], char nodo){

    int pos=posNodo(nodos, nodo);
    int j;
    int grado=0;
    
    if(pos<0){
       printf("El nodo indicado NO existe\n");
    }
    else
    {
       for(j=0; j<numNodos; j++){
          if(A[pos][j].distancia>0 && 
		  	 A[pos][j].distancia!=INFINITO)
             grado++;
       }
    }
    return grado;
}











int gradoEntrada( struct info A[MAX_NODOS][MAX_NODOS], char nodos[MAX_NODOS], char nodo){

    int pos=posNodo(nodos, nodo);
    int j;
    int grado=0;
    
    if(pos<0){
       printf("El nodo indicado NO existe\n");
    }
    else
    {
       for(j=0; j<numNodos; j++){
          if(A[j][pos].distancia>0 && 
		  	 A[j][pos].distancia!=INFINITO)
             
			 grado++;
       }
    }
    return grado;
}





int camino(   struct info A[MAX_NODOS][MAX_NODOS], char nodos[MAX_NODOS], char nodo1, char nodo2){
    int posNodo1=posNodo(nodos,nodo1);
    int posNodo2=posNodo(nodos, nodo2);
    
    if(posNodo1>=0 && posNodo2>=0){
       if(A[posNodo1][posNodo2].distancia>0 && 
          A[posNodo1][posNodo2].distancia!=INFINITO)
         return 1;
       else
         return 0;  
    }
    else
    {
       printf("Nodo origen y/o destino no existen\n");
    }    
}






int nodoSumidero(   struct info A[MAX_NODOS][MAX_NODOS], char nodos[MAX_NODOS],char nodo){
    
    if(gradoEntrada(A,nodos,nodo)>0 &&
       gradoSalida(A,nodos,nodo)==0)
      return 1;
    else 
      return 0;   
}




int nodoFuente(   struct info A[MAX_NODOS][MAX_NODOS], char nodos[MAX_NODOS], char nodo){
    
    if(gradoEntrada(A,nodos,nodo)==0 &&
       gradoSalida(A,nodos,nodo)>0)
      return 1;
    else 
      return 0;   
}


/*
int grafoFuertementeConexo(struct info a[MAX_NODOS][MAX_NODOS],char nodos[MAX_NODOS], char nodo){
	//arreglar para que compile 
	int i;
	
	for(i=0; i<numNodos; i++){
		
		if(nodoConexo(nodo, a, nodo[i])==0)
			return 0;
			
		return 1;
	}
}

*/



/*inicializar grafo
add nodo arist
vergrafo
nodo y garfo si son conexo 
camino entre los nodos*/






void menu(char nodo,struct info A[MAX_NODOS][MAX_NODOS], int n[MAX_NODOS]){
	
	int k;
	
	printf("\t1\tInicializar Grafo\n\t2\tAgregar Nodo\n\t3\tAgregar Arista\n\t4\tVerGrafo\n\t5\tComprobar si el nodo es conexo\n\t6\tComprobar si la arista es conexa\n\t7\tCamino entre los nodos\n");
	printf("escoger opcion: ");
	scanf("%i", &k);
	
	
	
	
	
	switch(k){
		
		case 1:
		  	iniNodos(n);
  			iniAdyacencia(A);	
		break;
		
		
		case 2:
			addNodo(n,A);
			break;
		
		case 3:	
			addArista(n, A);	
			break;
		
		case 4:
			int t;
			
			printf("\t1\tDistancia\n\t2\tIntensidad del trafico\n\t3\tCalidad de la via\n\t4\tCoste\n");
			printf("escoge informacion a mostrar: ")
			scanf("%i", &t)
			
			 verGrafo(nodos, A,t);
			break;
			
			//mirar el int y la funcion ver grafo
		
		
		
		
		
	}
	
	
	
	
	
	
	
}




int main(){
   char nodos[MAX_NODOS]; //matriz de nodos
   char nodo;
   struct info A[MAX_NODOS][MAX_NODOS];  //Mat. adyacencia
   int tipo;
   
   
   
   
   
   
   
   
   //Inicializamos las estructuras
   iniNodos(nodos);
   iniAdyacencia(A);
   
   addNodo(nodos,A);
   addNodo(nodos,A);
   addNodo(nodos,A);
   addNodo(nodos,A);
   addNodo(nodos,A);
   
   addArista(nodos, A);
   addArista(nodos, A);
   addArista(nodos, A);      
   addArista(nodos, A);   
   addArista(nodos, A);   
   
   verGrafo(nodos, A,tipo);  
   
   printf("Nodo: ");
   fflush(stdin);
   scanf("%c",&nodo);
   printf("Grado S.: %i\n",
             gradoSalida(A,nodos,nodo));       
   printf("Grado E.: %i\n",
             gradoEntrada(A,nodos,nodo)); 
   printf("Sumidero: %i\n", nodoSumidero(A,nodos,nodo));
      
       
   
   system("PAUSE"); 

}
