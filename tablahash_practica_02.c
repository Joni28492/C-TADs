/*
/*
autor:Jonathan Fernández López
fuente: hashing(practica 02)
fecha:06/02/2015
ultima revision:16/06/2015
	
*/










#include<stdio.h>
#include<string.h>
#define TAM_TABLA 127

typedef struct termino{
	
char castellano[20];
char ingles[20];
char frances[20];
char aleman[20];
	
}tablahash[TAM_TABLA];

//busquedas por el castellano 





void inicializa(tablahash t){
	
	int i;
	
		for(i=0; i<TAM_TABLA; i++){
			
			strcpy(t[i].castellano,"");
		
		}
	
		for(i=0; i<TAM_TABLA; i++){
		strcpy(t[i].ingles,"");
		
		}
	
		for(i=0; i<TAM_TABLA; i++){
		strcpy(t[i].frances,"");
		
		}
	
		for(i=0; i<TAM_TABLA; i++){
		strcpy(t[i].aleman,"");
		
		}
}


void mostrar(tablahash t){
	int i; 
	
	for(i=0; i<TAM_TABLA; i++){
		
		 printf("%i - %s\t %s\t %s\t %s\n",i,t[i].castellano,t[i].ingles,t[i].frances,t[i].aleman);
	}
}


int convierte(char clave[30]){
	int num=0;
	int i;
	
	for(i=0; i<strlen(clave); i++){
		
		num+=(int)clave[i];
	}
	
	return num;
	
}

int hash(char clave[30]){
	int res;
	
	res=convierte(clave)%(TAM_TABLA);
	return res;
	//tambien vale 
	//return convierte(clave)%TAM_TABLA
}





void insertarCuad(tablahash t, char clave[30], char clave2[30], char clave3[30], char clave4[30]){
	
	int pos=hash(clave);
	int i=0, intento=0, posOriginal;
	
	posOriginal=pos;
	
	while(pos<TAM_TABLA){
	
	
		//posicion vacia
		if(strcmp(t[pos].castellano,"")==0){
			strcpy(t[pos].castellano, clave);
			strcpy(t[pos].ingles, clave2);
			strcpy(t[pos].frances, clave3);
			strcpy(t[pos].aleman, clave4);
			break;
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].castellano,clave)==0){
			printf("la clave ya esta en la tabla");
			break;
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].castellano,clave)!=0){
			intento++;
				pos=posOriginal+ (intento*intento);
			
			if(pos>=TAM_TABLA){
				pos=pos-TAM_TABLA-1;
			}
				
		}
		
	}
}





void eliminarCuad(tablahash t, char clave[30]){
	
	int pos=hash(clave);
	int i=0, intento=0, posOriginal;
	
	posOriginal=pos;
	
	while(pos<TAM_TABLA){
	
	
		//posicion vacia
		if(strcmp(t[pos].castellano,"")==0){
			printf("la clave no existe");
			
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].castellano,clave)==0){
			strcpy(t[pos].castellano,"");
			strcpy(t[pos].ingles,"");
			strcpy(t[pos].frances,"");
			strcpy(t[pos].aleman,"");
			break;
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].castellano,clave)!=0){
			intento++;
				pos=posOriginal+ (intento*intento);
			
			if(pos>=TAM_TABLA){
				pos=pos-TAM_TABLA-1;
			}
				
		}
		
	}
}





//busqueda cuadratica
int busquedaCuad(tablahash t, char clave[30]){
	
	int pos=hash(clave);
	int i=0, intento=0, posOriginal;
	
	posOriginal=pos;
	
	while(pos<TAM_TABLA){
	
	
		//posicion vacia
		if(strcmp(t[pos].castellano,"")==0){
			return -1;
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].castellano,clave)==0){
			return pos;
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].castellano,clave)!=0){
			intento++;
				pos=posOriginal+ (intento*intento);
			
			if(pos>=TAM_TABLA){
				pos=pos-TAM_TABLA-1;
			}
				
		}
		
	}
}






//hacer funcion que devuelva el factor de carga
float factorCarga(tablahash t){
	int i, j=0;

	
	for(i=0; i<TAM_TABLA; i++){
		if(strcmp(t[i].castellano,"")!=0){
			j++;
		}
		
		
	}
	
	return (float)j/TAM_TABLA;
	
}


int agrupamientoMaximo(tablahash t){
	

	int i;
	int m, n=0;

		
	
	
	for(i=0; i<TAM_TABLA; i++){
		
		//si la posicion no esta vacia
		if(strcmp(t[i].castellano,"")==0){
			n++;
		}
		
		else{
			if(n>m){
			 m=n;
			 n=0;
			}
		
		}
		
		
	}
	
	return m;
	
}






int main(){
	
	tablahash tabla;
	
	inicializa(tabla);

	
	
	int n;
	
	
	
	



	while(1){
		
		
		printf("\n\n");
		
		printf("1. Reiniciar Tabla\n"
		   "2. Insertar Clave\n"
		   "3. Buscar Clave\n"
		   "4. Ver Tabla\n"
		   "5. Factor de Carga\n"
		   "6. Agrupamiento Maximo\n");
	
		scanf("%i", &n);
		
		
		while(n<1 || n>6){
		
		printf("vuelve a introduccir opcion: ");
		scanf("%i", &n);
		
		}
	
		//reiniciar tabla
		if(n==1){
			inicializa(tabla);
			continue;	
		}
		
		
		//insertar clave
		else if(n==2){
			char palabrai[30],palabrai2[30],palabrai3[30],palabrai4[30];
			
			printf("insertar palabra en castellano: ");
			scanf("%s", &palabrai);
			
			printf("insertar palabra en ingles: ");
			scanf("%s", &palabrai2);
			
			printf("insertar palabra en frances: ");
			scanf("%s", &palabrai3);
			
			printf("insertar palabra en aleman: ");
			scanf("%s", &palabrai4);
			
			insertarCuad(tabla, palabrai, palabrai2,palabrai3,palabrai4);
			continue;
		}
		
		
		
		//buscar clave
		else if(n==3){
			
			
			char palabrab[30];
			
			printf("buscar palabra en castellano: ");
			scanf("%s", &palabrab);
			
			printf("\n\n%i\n\n",busquedaCuad(tabla, palabrab));
			continue;
		}
		
		
		
		
		//ver tabla
		else if(n==4){
			mostrar(tabla);
			continue;
		}
		
		
		
		//factor de carga
		else if(n==5){
			//factorCarga(tabla);	
			
			printf("\n\nel factor de carga es de %f\n\n", factorCarga(tabla));
			continue;
			
		}
		
		
		
		
		//agrupamiento maximo
		else if(n==6){
			//agrupamientoMaximo(tabla);
			printf("\n\nel agrupamiento maximo es de %i", agrupamientoMaximo(tabla));
			continue;
			
		}
		
	
	}
	
	
	
	system("PAUSE");
}

