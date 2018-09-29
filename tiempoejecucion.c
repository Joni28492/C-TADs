#include<stdio.h>
/*Suponemos los siguientes tiempos: 
     Asignaciones 1 ciclo de reloj
     Comparaciones 2 ciclos
     Ops. 3 ciclos
*/

int nA=0; //Asignaciones
int nC=0; //Comparaciones
int nO=0; //Ops. Aritméticas

int main()
{
 long int n=2371;    nA++;
 int i;
 int res=1;     nA++;
 
 nA++; nO++;
 for(i=2;i<=n-1;i++)
 {
  nC++;nA++;nO++;
  
  nC++; nO++;                 
  if(n % i == 0) {
   res=0;   nA++;
   break;
  }
 }
 
 nC++;
 if(res==1)
    printf("Es primo");
 else
    printf("No es primo");
 
 printf("\nAsignaciones: %i, Comparaciones: %i, Ops. aritméticas: %i\n",nA,nC,nO); 
 printf("\nTiempo de ejecución: %i ciclos\n",nA+nC*2+nO*3);  
 getchar();               
}






