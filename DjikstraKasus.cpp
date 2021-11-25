#include <iostream>
#include <limits.h>

using namespace std; 
#define node 12

char Alphabet[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

int shortPath (int distance[], bool shortestPath[]);
void path(int start[], int j);
void dijkstra(int graph[node][node], int src);

int main(){
    int graph[node][node] = {
     {0, 17, 19, 15, 20, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 22, 23, 21, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 28, 27, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 26, 25, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 13, 17, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 12, 16, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 27, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    cout<< "Shortest Path:\n";

    dijkstra(graph, 0);
    cout << endl;
    return 0;
}

int shortPath (int distance[], bool shortestPath[]){
    int min = INT_MAX, minIndex;
    for (int v = 0; v < node; v++)
        if (shortestPath[v] == false && distance[v] <= min){
         min = distance[v], minIndex = v;
  }
    return minIndex;
}
   
void path(int start[], int j){
    if (start[j] == - 1){
     return;
 }
    path(start, start[j]);
    cout << "->" << Alphabet[j];
}

void dijkstra(int graph[node][node], int src){
    int distance[node]; 
    bool shortestPath[node];
    int start[node];
    for (int i = 0; i < node; i++){
        start[0] = -1;
        distance[i] = INT_MAX;
        shortestPath[i] = false;
    }
    distance[src] = 0;

    for (int count = 0; count < node - 1; count++){
        int u = shortPath(distance, shortestPath);   
        shortestPath[u] = true;
        for (int v = 0; v < node; v++)
            if (!shortestPath[v] && graph[u][v] &&
                distance[u] + graph[u][v] < distance[v]){
                start[v] = u;
                distance[v] = distance[u] + graph[u][v];
            } 
    }
    printf("Vertex\t\t Jarak \t  Path");
    for (int i = 1; i < node; i++){
        cout << "\n" << Alphabet[src] << " ke " << Alphabet[i] << " \t\t " << distance[i] << "\t  A"; 
        path(start, i);
    }
}
