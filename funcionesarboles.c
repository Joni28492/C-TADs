int Altura(Arbol a, int dat) {
pNodo actual = a;

int h=0;

while(actual != NULL) {

if(dat = = actual->dato)
return h; /* dato encontrado (2) */



else if(dat < actual->dato)
actual = actual->izquierdo;/* (3) */


else if(dat > actual->dato)
actual = actual->derecho; /* (4) */

h++;
}


return -1; /* No está en árbol (1) */
}



int Menor(arbol a){
	
	pNodo actual = a;
	
	if(actual!=NULL){
	
	
		while(actual->izquierdo!=NULL){
		actual=actual-izquierdo;
		}
		
		
	return actual->dat;
	}
	
	
	else 
	return -1;
}



