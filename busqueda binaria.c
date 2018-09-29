#include<stdio.h>

int tA=0, tC=0, tO=0;

int busqueda_binaria(int vector[20],int llave)
{
int encontrado = 0; tA+=3;
int izquierda = 0;
int derecha = 19;
int centro;

tC+=3;
while (! encontrado && izquierda <= derecha){
    tC+=3;
centro = (izquierda + derecha) / 2; tA++; tO++;

tC++; tA++;
if (llave < vector[centro])
derecha = centro - 1;



else if (llave > vector[centro])
izquierda = centro + 1;

else
encontrado = 1;
}

tC++;
if(encontrado==1)
return centro;
else
return -1;
}



int main()
{
int vector[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
tA+=20;

int pos;
pos=busqueda_binaria(vector,18); tA++;

printf("El elemento está en la posición: %i",pos);
printf("\ntiempo de asignacion: %i\n tiempo comparacion: %i\n tiempo op aritmetica: %i\n", tA, tC, tO);
printf("ciclos: %i\n", tA+tC*2+tO*3);
getchar();
}
