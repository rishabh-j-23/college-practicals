#include <stdio.h>
#include <time.h>

double run_time(clock_t start, clock_t end){
    double ms = (double)(end - start);
    ms = ms / (double)CLK_TCK;
    return ms;
}

int tsp_g[4][4] = {
    {0, 1, 2, 6},
    {1, 0, 5, 3},
    {2, 5, 0, 4},
    {6, 3, 4, 0}
};
int visited[4], n, cost = 0;

void travellingsalesman(int c){
   int adj_vertex = 999;
   int min = 999;
   
   visited[c] = 1;
   
   printf("%d ", c + 1);
   
   /* checking the minimum cost edge in the graph */
   for(int k = 0; k < n; k++) {
      if((tsp_g[c][k] != 0) && (visited[k] == 0)) {
         if(tsp_g[c][k] < min) {
            min = tsp_g[c][k];
            adj_vertex = k;
         }
      }
   }
   if(min != 999) {
      cost = cost + min;
   }
   if(adj_vertex == 999) {
      adj_vertex = 0;
      printf("%d", adj_vertex + 1);
      cost = cost + tsp_g[c][adj_vertex];
      return;
   }
   travellingsalesman(adj_vertex);
}

int main(){
   int i, j;
   n = 4;
   for(i = 0; i < n; i++) {
      visited[i] = 0;
   }
   printf("\nShortest Path:\t");
   clock_t start, end;
   start = clock();
   travellingsalesman(0);
   end = clock();
   printf("\nMinimum Cost: \t");
   printf("%d\n", cost);
   printf("time : %f", run_time(start, end));
   return 0;
}