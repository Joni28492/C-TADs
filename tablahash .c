/*
tablas hash 




*/




#include<stdio.h>
#include<string.h>
#define TAM_TABLA 127

typedef struct termino{
	
char palabra[25];	
	
}tablahash[TAM_TABLA];


void inicializa(tablahash t){
	
	int i;
	
	for(i=0; i<TAM_TABLA; i++){
		//si no funciona el punto usar ->
		strcpy(t[i].palabra,"");
		
	}
	
	
}



void mostrar(tablahash t){
	int i; 
	
	for(i=0; i<TAM_TABLA; i++){
		
		printf("%i\t", i);
		puts(t[i].palabra);
		
	}
	
}

//clave se refiere a la palabra
int convierte(char clave[30]){
	int num=0, res;
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


void insertar(tablahash t, char clave[30]){
	
	int pos=hash(clave);
	
	while(pos<TAM_TABLA){
	
	
		//posicion vacia
		if(strcmp(t[pos].palabra,"")==0){
			strcpy(t[pos].palabra, clave);
			break;
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].palabra,clave)==0){
			printf("la clave ya esta en la tabla");
			break;
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].palabra,clave)!=0){
			if(pos==(TAM_TABLA-1))
				pos=0;
			else
				pos++;
				
		}
		
	}
}



void insertarCuad(tablahash t, char clave[30]){
	
	int pos=hash(clave);
	int i=0, intento=0, posOriginal;
	
	posOriginal=pos;
	
	while(pos<TAM_TABLA){
	
	
		//posicion vacia
		if(strcmp(t[pos].palabra,"")==0){
			strcpy(t[pos].palabra, clave);
			break;
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].palabra,clave)==0){
			printf("la clave ya esta en la tabla");
			break;
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].palabra,clave)!=0){
			intento++;
				pos=posOriginal+ (intento*intento);
			
			if(pos>=TAM_TABLA){
				pos=pos-TAM_TABLA-1;
			}
				
		}
		
	}
}


//igual que insertar

void eliminar(tablahash t, char clave[30]){
	
	int pos=hash(clave);
	
	while(pos<TAM_TABLA){
	
	
		//posicion vacia
		if(strcmp(t[pos].palabra,"")==0){
			printf("la clave no existe");
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].palabra,clave)==0){
		 
		strcpy(t[pos].palabra,"");
		 
		 break;
		 
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].palabra,clave)!=0){
			if(pos==(TAM_TABLA-1))
				pos=0;
			else
				pos++;
				
		}
		
	}
}

void eliminarCuad(tablahash t, char clave[30]){
	
	int pos=hash(clave);
	int i=0, intento=0, posOriginal;
	
	posOriginal=pos;
	
	while(pos<TAM_TABLA){
	
	
		//posicion vacia
		if(strcmp(t[pos].palabra,"")==0){
			printf("la clave no existe");
			
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].palabra,clave)==0){
			strcpy(t[pos].palabra,"");
			break;
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].palabra,clave)!=0){
			intento++;
				pos=posOriginal+ (intento*intento);
			
			if(pos>=TAM_TABLA){
				pos=pos-TAM_TABLA-1;
			}
				
		}
		
	}
}



int busqueda(tablahash t, char clave[30]){
	
	int pos=hash(clave);
	
	while(pos<TAM_TABLA){
	
	
		//posicion vacia
		if(strcmp(t[pos].palabra,"")==0){
			return -1;
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].palabra,clave)==0){
			return pos;
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].palabra,clave)!=0){
			if(pos==(TAM_TABLA-1))
				pos=0;
			else
				pos++;
				
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
		if(strcmp(t[pos].palabra,"")==0){
			return -1;
		}
		
		
		//la clave ya existe
		else if(strcmp(t[pos].palabra,clave)==0){
			return pos;
		}
		
		
		//ya hay otra clave 
		else if(strcmp(t[pos].palabra,clave)!=0){
			intento++;
				pos=posOriginal+ (intento*intento);
			
			if(pos>=TAM_TABLA){
				pos=pos-TAM_TABLA-1;
			}
				
		}
		
	}
}






//hacer funcion que devuelva el factor de carga; esta sin acabar



int factorCarga(tablahash t, char calve[30]){
	int i, j=0;
	int pos=hash(clave);
	
	for(i=0; i<TAM_TABLA; i++){
		if(palabra!=""){
			j++;
		}
		
		
	}
	
	return j/TAM_TABLA;
	
}



int main(){
	
	tablahash tabla;
	
	inicializa(tabla);
	//se mete entre comillas la palabra 
	//convierte("camarero");
	//hash("camarero");
	
	
	
	/*insertar(tabla,"crata");
	insertar(tabla,"traca");
	insertar(tabla,"catar");
	insertar(tabla,"ratac");
	printf("la posicion es %i\n\n",busqueda(tabla,"crata"));
	mostrar(tabla);
	
	
	//prueba busqueda Cuad
	/*insertarCuad(tabla,"crata");
	insertarCuad(tabla,"traca");
	insertarCuad(tabla,"catar");
	insertarCuad(tabla,"ratac");
	printf("la posicion es %i\n\n",busquedaCuad(tabla,"crata"));
	mostrar(tabla);*/
	
	int n;
	
	
	
	
	
	
	
	
	
	
	
	
}

