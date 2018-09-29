#include<stdio.h>
#define TAM 20




int tA=0, tC=0, tO=0;

void burbuja(int lista[TAM]){
int i,j;
int temp;

				tA++; tC++;
for (i=1; i<TAM; i++)
				tA++; tC++; tO++;
				
				tA++; tC++;
for (j=0 ; j<TAM - 1; j++)
tA++; tC++; tO++;

tC++;
if (lista[j] > lista[j+1]){
temp = lista[j];
tO++;
lista[j] = lista[j+1];
tO++;
lista[j+1] = temp;
tO++;
}
}

int main(){
int vector[20]={87,921,45,56,30,34,20,23,15,17,10,11,8,9,5,6,3,4,0,2};
tA+=20;
burbuja(vector);
printf("Ordenado!\n");

 printf("\nAsignaciones: %i, Comparaciones: %i, Ops. aritmeticas: %i\n",tA,tC,tO); 
 printf("\nTiempo de ejecucion: %i ciclos\n",tA+tC*2+tO*3);  


getchar();
}
