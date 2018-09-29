#include<stdio.h>
#define MAX_NODOS 10
#define INFINITO 32000

int numNodos;  //Nº nodos del grafo


void iniNodos(char n[MAX_NODOS]){
// Inicializa o vacía la matriz de nodos con espacios
  int i;
  for(i=0; i<MAX_NODOS; i++)
     n[i]=' ';
  numNodos=0;        
}

void iniAdyacencia(int a[MAX_NODOS][MAX_NODOS]){
// Inicializa la matriz de adyacencia (pesos)
  int i,j;
  for(i=0; i<MAX_NODOS; i++)     
    for(j=0; j<MAX_NODOS; j++)
        a[i][j]=INFINITO;  
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

void addNodo(char n[MAX_NODOS], int A[MAX_NODOS][MAX_NODOS]){
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
         A[numNodos][numNodos]=0;
         numNodos++;    
      }                       
   }                                              
   else  //No hay espacio
   {
     printf("No hay espacio disponible\n");
   }
}

void addArista(char n[MAX_NODOS],int a[MAX_NODOS][MAX_NODOS]){

   int posOrigen, posDestino, peso;
   char origen, destino;
   
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
      printf("Peso de la arista: ");
      fflush(stdin);
      scanf("%i", &peso);
      a[posOrigen][posDestino]=peso;
   }
                
}

void verNodos(char n[MAX_NODOS]){
  int i;
  for(i=0; i<MAX_NODOS; i++)
     printf("%c\t", n[i]); 
  printf("\n");   
}

void verGrafo(char nodos[MAX_NODOS], int A[MAX_NODOS][MAX_NODOS]){
   int i,j;
   
   printf("\t");
   verNodos(nodos);
   
   for(i=0; i<numNodos; i++){
      printf("%c\t", nodos[i]);
      for(j=0; j<numNodos; j++){
         if(A[i][j]==INFINITO){
            printf("INF.\t");
         }
         else
         {
            printf("%i\t",A[i][j]);
         }
      }
      printf("\n");
   }
}



//mirar desde aqui
int gradoSalida(int A[MAX_NODOS][MAX_NODOS], char nodos[MAX_NODOS], char nodo){

    int pos=posNodo(nodos, nodo);
    int j;
    int grado=0;
    
    if(pos<0){
       printf("El nodo indicado NO existe\n");
    }
    else
    {
       for(j=0; j<numNodos; j++){
          if(A[pos][j]>0 && A[pos][j]!=INFINITO)
             grado++;
       }
    }
    return grado;
}

int gradoEntrada(int A[MAX_NODOS][MAX_NODOS],char nodos[MAX_NODOS], char nodo){

    int pos=posNodo(nodos, nodo);
    int j;
    int grado=0;
    
    if(pos<0){
       printf("El nodo indicado NO existe\n");
    }
    else
    {
       for(j=0; j<numNodos; j++){
          if(A[j][pos]>0 && A[j][pos]!=INFINITO)
             grado++;
       }
    }
    return grado;
}

int camino(int A[MAX_NODOS][MAX_NODOS], char nodos[MAX_NODOS], char nodo1, char nodo2){
    int posNodo1=posNodo(nodos,nodo1);
    int posNodo2=posNodo(nodos, nodo2);
    
    if(posNodo1>=0 && posNodo2>=0){
       if(A[posNodo1][posNodo2]>0 && 
          A[posNodo1][posNodo2]!=INFINITO)
         return 1;
       else
         return 0;  
    }
    else
    {
       printf("Nodo origen y/o destino no existen\n");
    }    
}



int nodoSumidero(int A[MAX_NODOS][MAX_NODOS],char nodos[MAX_NODOS],char nodo){
    //cuando todas las aristas son entrada es un nodo sumidero
    if(gradoEntrada(A,nodos,nodo)>0 &&
       gradoSalida(A,nodos,nodo)==0)
      return 1;
    else 
      return 0;   
}




int nodoFuente(int A[MAX_NODOS][MAX_NODOS],char nodos[MAX_NODOS],char nodo){
 
    if(gradoEntrada(A,nodos,nodo)==0 &&
       gradoSalida(A,nodos,nodo)>0)
      return 1;
    else 
      return 0;   
}


int nodoConexo(int a[MAX_NODOS][MAX_NODOS],char nodos[MAX_NODOS], char nodo){
	
	int pos=posNodo(nodos, nodo);
	int j;
	
	for(j=0; j<numNodos; j++){
		
		if(j!=pos){
		
			if(!(a[pos][j]>0 && a[pos][j]!=INFINITO)){
				return 0;
			}
		}	
	}
	return 1;
}


int grafoFuertementeConexo(int a[MAX_NODOS][MAX_NODOS],char nodos[MAX_NODOS], char nodo){
	//arreglar para que compile 
	int i;
	
	for(i=0; i<numNodos; i++){
		
		if(nodoConexo(nodo, a, nodo[i])==0)
			return 0;
			
		return 1;
	}
}
//copiar codigo gonzalo de carpeta compartida 


//definir un struc para dar mas informacion, distancia trafico calidad de la via coste etc...
//redefinir la mat de adyacencia, si es conexo 




int main(){
   char nodos[MAX_NODOS]; //matriz de nodos
   char nodo;
   int A[MAX_NODOS][MAX_NODOS];  //Mat. adyacencia
   
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
   
   verGrafo(nodos, A);  
   
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
