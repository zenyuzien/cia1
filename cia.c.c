#include <stdio.h>
#include <stdlib.h>
#define I 19999
struct graph
{
    int* *arr ;
    int v ;
    int* varr;
};



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
    
    g->arr[0][2] = 2 ; 
    g->arr[1][0] = 1 ;
    g->arr[2][1] = -2 ;
    g->arr[3][0] = -4 ; 
    g->arr[3][2] = -1 ;
    g->arr[4][3] = 1 ;
    g->arr[5][0] = 10; 
    g->arr[5][4] = 8 ;
    
}

void display(struct graph* g)
{
    
    printf("\n\nno. of vertices = %d \n",g->v);
    printf("g.arr representation: \n");
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


int shortest_path(int dist[], int tmp[], int x) {
   int min = I, min_index;
   for (int v = 0; v < x; v++)
   if ( !tmp[v]  && dist[v] <= min)
      min = dist[v], min_index = v;
   return min_index;
}
int printSolution(int dist[], int x, int src) {
   printf("\nvertex / Source %d \n",src);
   for (int i = 0; i < x; i++)
   {
       if(dist[i]==0 || dist[i]>19000)
       printf("%d <--> -", i);
       else
       printf("%d <--> %d", i, dist[i]);
       if(i%2==0)printf("\t");
       else
       printf("\n");
   }
}
void djk(struct graph* g ,int src) {
   int dist[g->v], tmp[g->v];
   for (int i = 0; i < g->v ; i++)
      dist[i] = I, tmp[i] = 0;
      dist[src] = 0;
   for (int count = 0; count < g->v - 1; count++) {
      int u = shortest_path(dist, tmp,g->v);
      tmp[u] = 1;
      for (int v = 0; v < g->v; v++)
         if (!tmp[v] && g->arr[u][v] && dist[u] != I && dist[u] + g->arr[u][v] < dist[v])
         dist[v] = dist[u] + g->arr[u][v];
   }
   printSolution(dist, g->v, src);
}

void djk_utility(struct graph* g)
{
    printf("\ndijkistras method : \n");
    for(int i = 0 ; i < g->v; i++)
    djk(g,i);
}

int main(){

    struct graph g; 
    create(&g);
    display(&g);

    int visit[g.v];
    for(int i =0 ;i < g.v ;i++)
    visit[i]=0;


    int distance[g.v];
    
    int choice = 0, count = 0, cost = 0, a = 0, b = 0;



    for(int i=0; i<g.v; i++){
		distance[i]=g.arr[0][i];
		visit[i]=0;
	}

    visit[0] = 1;

    while(count<g.v){

        cost = I;
        for(int i = 0; i<g.v; i++)
        if(distance[i]<cost && !visit[i])
        {
            cost = distance[i];
		    a = i;
        }
        visit[a] = 1;
		for(int i = 0; i < g.v; i++)
		if(!visit[i])
		if(cost+g.arr[a][i] < distance[i])
		distance[i] = cost+g.arr[a][i];
		count++;

    }

    for(int i = 0; i<g.v; i++)
		if(i!=0)
		{
			printf("\nCOST FROM SOURCE TO %d IS %d",i,distance[i]);
			
	}
	
	djk_utility(&g);
	

    return 0;
}