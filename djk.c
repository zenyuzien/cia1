#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define I INT_MAX
struct graph
{
  int **arr;
  int v;
  int *varr;
};




void create (struct graph *g)
{
  g->v = 6;
  g->varr = (int *) malloc (sizeof (int) * g->v);
  g->arr = (int **) malloc (sizeof (int) * g->v * g->v);

    for (int i = 0; i < g->v; i++)
    g->arr[i] = (int *) malloc (sizeof (int) * g->v);


  for (int i = 0; i < g->v; i++)
  {

      g->varr[i] = i;
    }

    for (int i = 0; i < g->v; i++)
    for (int j = 0; j < g->v; j++)
    g->arr[i][j] = I;

  g->arr[1][3] = 2;		//
  g->arr[2][1] = 1;		//
  g->arr[3][2] = -2;		//
  g->arr[4][1] = -4;		//
  g->arr[4][3] = -1;		//
  g->arr[5][4] = 1;		//
  g->arr[0][1] = 10;		//
  g->arr[0][5] = 8;		//
 
}


void display (struct graph *g)
{

  printf ("\n\nno. of vertices = %d \n", g->v);
  printf ("g->arr representation: \n");
  printf ("  ");
  for (int i = 0; i < g->v; i++)
  printf ("%d ", g->varr[i]);
  printf ("\n");
  
    for (int i = 0; i < g->v; i++)
    {
      printf ("%d ", g->varr[i]);
      for (int j = 0; j < g->v; j++)
	  {
	    if (g->arr[i][j] == I)
	    printf ("- ");
	    else
	    printf ("%d ", g->arr[i][j]);
	  }
      printf ("\n");
    }
  printf ("\n");

}


void djk(struct graph* g)
{
    
    int isVisit[g->v], path[g->v];
    int a = 0, b = 0;
    

    for(int i=0; i<g->v; i++)
    {
        isVisit[i] = 0;
		path[i]=g->arr[0][i];
		isVisit[i]=0;
	}

    isVisit[0] = 1; // the source index is 0 


    for(int count=1; count<g->v; count++)
    {

        int weight = I;
        
        for(int i = 0; i<g->v; i++)
        if(path[i]<weight && !isVisit[i])
        {
			weight = path[i];
			a = i;
		}      

        isVisit[a] = 1;
		for(int i = 0; i < g->v; i++)
		if(!isVisit[i])
		if(weight+g->arr[a][i] < path[i])
		path[i] = weight + g->arr[a][i];
			
    }

    for(int i = 1; i<g->v; i++)
	printf("\nnet weight from source S to the node %d is %d \n",i,path[i]);

}

int main()
{
    struct graph g;
    create (&g);
  display(&g);
  djk(&g);

    return 0;
}