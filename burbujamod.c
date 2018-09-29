#include<stdio.h>
#define TAM 20


void burbuja(int lista[TAM]){
int i,j;
int temp;
for (i=1; i<TAM; i++)
for (j=0 ; j<TAM - 1; j++)
if (lista[j] > lista[j+1]){
temp = lista[j];
lista[j] = lista[j+1];
lista[j+1] = temp;

}


}

void burbujaA(int lista[TAM]){
int i,j;
int temp;
for (i=1; i<TAM; i++)
for (j=0 ; j<TAM - i; j++)
if (lista[j] > lista[j+1]){
temp = lista[j];
lista[j] = lista[j+1];
lista[j+1] = temp;

}


}



void mostrar(int m[TAM]){
	int i;
	
	for(i=0; i<TAM; i++){
		printf("\n %i|\t", m[i]);
	}
}




int main(){
int vector[20]={23,11,2,3,0,5,9,45,4,17,87,56,34,921,6,15,20,30,10,8};
burbujaA(vector);
mostrar(vector);
printf("Ordenado!\n");
getchar();
}
