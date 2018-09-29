#include<stdio.h>
#include<limits.h>

#define MAX_NODOS 10

// Number of nodes currently active in the graph
int num_nodos;

void iniNodos(char nod[MAX_NODOS])
{
    int i;
    for(i = 0; i < MAX_NODOS; ++i)
        nod[i] = ' ';
          
    num_nodos = 0; 
}
 
void iniAdyacencia(int A[MAX_NODOS][MAX_NODOS])
{
    int i, j;
    
    for(i = 0; i < MAX_NODOS; ++i)
        for(j = 0; j < MAX_NODOS; ++j)
            if(i == j)
                A[i][j] = 0;
            else
                A[i][j] = INT_MAX;
}

int posNodo(char nod[MAX_NODOS], char nodo)
{
    int i;
    
    for(i = 0; i < num_nodos; ++i)
    {
        if(nod[i] == nodo)
            return i;
        }
     
    return -1;      
}

void addNodo(char nod[MAX_NODOS], char nodo)
{
    if(num_nodos < MAX_NODOS)
    {
        if(posNodo(nod, nodo) != -1)
        {
            printf("Character already in.\n");
            return;
        }
                      
        nod[num_nodos] = nodo;
        ++num_nodos;
        
        return;
    }
    
    printf("Out of space.\n");
}

void addArista(char nod[MAX_NODOS],
                int A[MAX_NODOS][MAX_NODOS],
                char nodo_o,char nodo_d, int peso)
{
    int pos_o = posNodo(nod, nodo_o);
    int pos_d = posNodo(nod, nodo_d);
    
    if(pos_o != -1 && pos_d != -1)
        A[pos_o][pos_d] = peso;
}

void verGrafo(char nod[MAX_NODOS],
                int A[MAX_NODOS][MAX_NODOS])
{
    if(num_nodos)
    {
        int i, j;
        
        printf(" ");
        
        for(i = 0; i < num_nodos; ++i)
            printf("|%c", nod[i]);
        
        printf("|\n");
        
        for(i = 0; i < num_nodos; ++i)
        {
            printf("%c", nod[i]);
            for(j = 0; j < num_nodos; ++j)
            {
                if(A[i][j] == INT_MAX)
                    printf("| ");
                else
                    printf("|%i", A[i][j]);
            }   
            printf("|\n");
        }

    }
}

int gradoSalida(char nod[MAX_NODOS],
                 int A[MAX_NODOS][MAX_NODOS], char nodo)
{
    int out_counter = 0, i;
    
    int pos = posNodo(nod, nodo);
    
    if(pos != -1)
    {
        for(i = 0; i < num_nodos; ++i)
            if(A[pos][i] != INT_MAX && A[pos][i] != 0)
                ++out_counter;
    }
    else
        return -1;
    
    return out_counter;
}

int gradoEntrada(char nod[MAX_NODOS],
                 int A[MAX_NODOS][MAX_NODOS], char nodo)
{
    int in_counter = 0, i;
    
    int pos = posNodo(nod, nodo);
    
    if(pos != -1)
    {
        for(i = 0; i < num_nodos; ++i)
            if(A[i][pos] != INT_MAX && A[i][pos] != 0)
                ++in_counter;
    }
    else
        return -1;
            
    return in_counter;
}

int camino(char nod[MAX_NODOS],
                int A[MAX_NODOS][MAX_NODOS],
                char nodo_o, char nodo_d)
{
    int pos_o = posNodo(nod, nodo_o);
    int pos_d = posNodo(nod, nodo_d);
    
    if(pos_o != -1 && pos_d != -1)
        if(A[pos_o][pos_d] != INT_MAX 
            && A[pos_o][pos_d] != 0)
                return 1;

    return 0;                
}

int nodoConexo(char nod[MAX_NODOS],
                 int A[MAX_NODOS][MAX_NODOS], char nodo)
{
    if(gradoSalida(nod, A, nodo) == num_nodos - 1)
        return 1;
    else
        return 0;
}
int nodoSumidero(char nod[MAX_NODOS],
                 int A[MAX_NODOS][MAX_NODOS], char nodo)
{
    if(gradoEntrada(nod, A, nodo)
         && !gradoSalida(nod, A, nodo))
        return 1;
    else
        return 0;
}

int nodoFuente(char nod[MAX_NODOS],
                 int A[MAX_NODOS][MAX_NODOS], char nodo)
{
    if(gradoSalida(nod, A, nodo)
        && !gradoEntrada(nod, A, nodo))
        return 1;
    else
        return 0;
}

int grafoFuertementeConexo(char nodo[MAX_NODOS],
                            int A[MAX_NODOS][MAX_NODOS])
{
    int i;
    
    for(i = 0; i < num_nodos; ++i)
        if(nodoConexo(nodo, A, nodo[i]) == 0)
            return 0;
    
    return 1;
}

int main(void)
{
    char nodos[MAX_NODOS];
    int A[MAX_NODOS][MAX_NODOS];
    char c;
    int i;
    
    //Initialize matrices
    iniNodos(nodos);
    iniAdyacencia(A);
    
    for(i = 0; i < 3; ++i)
    {
        printf("Insert node : ");
        fflush(stdin);
        scanf("%c", &c);
        addNodo(nodos, c);
    }
    
    
    addArista(nodos, A, 'A', 'B', 10);
    addArista(nodos, A, 'A', 'C', 5);
    addArista(nodos, A, 'B', 'A', 20);
    addArista(nodos, A, 'B', 'C', 12);
    addArista(nodos, A, 'C', 'A', 7);
    //addArista(nodos, A, 'C', 'B', 7);

    
    verGrafo(nodos, A);
    
    printf("Is 'A' strongly connected? :");
    if(nodoConexo(nodos, A, 'A'))
        printf("Yes\n");
    else
        printf("No\n");
        
    printf("Is 'C' strongly connected? :");
    if(nodoConexo(nodos, A, 'C'))
        printf("Yes\n");
    else
        printf("No\n");
        
    printf("Is the graph strongly connected? :");
    if(grafoFuertementeConexo(nodos, A))
        printf("Yes\n");
    else
        printf("No\n");
    
    //printf("Out grade of A : %i\n", 
//    gradoSalida(nodos, A, 'A'));
//    printf("Out grade of B : %i\n", 
//    gradoSalida(nodos, A, 'B'));
//    printf("Out grade of C : %i\n", 
//    gradoSalida(nodos, A, 'C'));
//    printf("Out grade of C : %i\n", 
//    gradoSalida(nodos, A, 'D'));
//    printf("Out grade of C : %i\n", 
//    gradoSalida(nodos, A, 'E'));
//    
//    printf("In grade of A : %i\n", 
//    gradoEntrada(nodos, A, 'A'));
//    printf("In grade of B : %i\n", 
//    gradoEntrada(nodos, A, 'B'));
//    printf("In grade of C : %i\n", 
//    gradoEntrada(nodos, A, 'C'));
//    printf("In grade of C : %i\n", 
//    gradoEntrada(nodos, A, 'D'));
//    printf("In grade of C : %i\n", 
//    gradoEntrada(nodos, A, 'E'));
//    
//    printf("Is there conection from 'A' to 'C' :");
//    if(camino(nodos, A, 'A', 'C'))
//        printf(" Yes\n");
//    else
//        printf(" No\n");
//        
//    printf("Is there conection from 'C' to 'A' :");
//    if(camino(nodos, A, 'C', 'A'))
//        printf(" Yes\n");
//    else
//        printf(" No\n");
//        
//    printf("End node is 'E' : ");
//    if(nodoSumidero(nodos, A, 'E'))
//        printf(" Yes\n");
//    else
//        printf(" No\n");
//        
//    printf("Start node is 'A' : ");
//    if(nodoSumidero(nodos, A, 'A'))
//        printf(" Yes\n");
//    else
//        printf(" No\n");
    
    
    system("PAUSE");    
};
