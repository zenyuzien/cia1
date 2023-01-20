#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define I INT_MAX

struct graph
{
    int* *arr ;
    int v ;
    int* varr;
};

void display(struct graph*);
void create(struct graph*);

void prims(struct graph* g)
{

    int isVisit[g->v];
    int weight = 0;
    int u = 0, v = 0;

    for(int i = 0; i<g->v; i++)
    isVisit[i] = 0;
    isVisit[0] = 1;

    for(int count = 0 ; count < g->v; count++){

        weight = I;
        
        for(int i = 0; i<g->v; i++)
        for(int j = 0; j<g->v; j++)
                if(g->arr[i][j] 
                < weight && 
                isVisit[i] ){ 
                    weight = g->arr[i][j];
                    u = i; v = j;
                }

        if( !isVisit[u] || !isVisit[v] )
        {
            printf("\n %d <--> %d,  weight = %d",u,v,weight);
			isVisit[v]=1;
        }

        g->arr[u][v] = g->arr[v][u] = I;
    }

}

int main(){

    struct graph g ;
    create(&g);
    display(&g);
    prims(&g);

    return 0;
}

void create(struct graph* g)
{
    g->v = 6 ;
    
    g->varr = (int* )malloc(sizeof(int)*g->v );
    
    
    g->arr = (int**)malloc(sizeof(int)*g->v*g->v) ;
    
    for(int i = 0 ; i < g->v ; i++)
    g->arr[i] =  (int* )malloc(sizeof(int)*g->v ) ;
    
    
    for(int i=0; i<g->v ;i++)
    {
        
        g->varr[i] = i ;
    }
    
    for(int i = 0 ; i < g->v ; i++)
    for(int j = 0 ; j < g->v ; j++)
    g->arr[i][j] = I ;
    
    
    g->arr[1][3] = 2 ; //
    g->arr[2][1] = 1 ;//
    g->arr[3][2] = -2 ;//
    g->arr[4][1] = -4 ; //
    g->arr[4][3] = -1 ;//
    g->arr[5][4] = 1 ;//
    g->arr[0][1] = 10; //
    g->arr[0][5] = 8 ; //

}


void display(struct graph* g)
{
    
    printf("\n\nno. of vertices = %d \n",g->v);
    printf("g->arr representation: \n");
    printf("  ");
    for(int i = 0; i < g->v ; i++)
    printf("%d ",g->varr[i]);
    printf("\n");
    for(int i = 0 ; i < g->v ; i++)
    {
        printf("%d ",g->varr[i]);
        for(int j = 0 ; j < g->v ; j++){
        if(g->arr[i][j]==I)printf("- ");else
        printf("%d ",g->arr[i][j]);}
        printf("\n");
    }
    printf("\n");
    
}