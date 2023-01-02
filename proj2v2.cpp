#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct {
    int weight;
    int v1;
    int v2;
} Edge;


bool comparator(Edge e1, Edge e2){
    return e2.weight < e1.weight;
}

// gets the parent node of a given node v
int findSet(int p[], int v){
    if (v != p[v]){                        // if the parent is not the node itself, get the parent node's parent
        p[v] = findSet(p, p[v]);
        
    }
    return p[v];
}

// links 2 nodes, changing their parents and ranks
void link(int v1, int v2, int p[], int r[]){
    if (r[v1] < r[v2]){
        p[v1] = v2;
    }
    else{
        p[v2] = v1;
        if (r[v1] == r[v2]){
            r[v1]++;
        }
    }
}


int findMaxWeight(vector<Edge> edges, int num_vertices, int num_edges){
    int maxWeight = 0;
    int *parent = (int*)malloc(sizeof(int) * num_vertices);
    int *rank = (int*)malloc(sizeof(int) * num_vertices);

    int i;
    for (i = 0; i < num_vertices; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    
    for (i = 0; i < num_edges; i++){
        int find1 = findSet(parent, edges.at(i).v1 - 1);
        int find2 = findSet(parent, edges.at(i).v2 - 1);
        if (find1 != find2){
            maxWeight += edges.at(i).weight;
            link(find1, find2, parent, rank);
        }
    }
    
    free(parent);
    free(rank);
    return maxWeight;
}


int main(){
    int num_vertices;
    int num_edges;
    int v1, v2, weight;
    // vector of all edges
    vector<Edge> edges;
    
    //input read
    if(scanf("%d", &num_vertices) != 1)
        exit(1);
    if(scanf("%d", &num_edges) != 1)
        exit(1);
        
    for(int i = 0; i < num_edges; i++) {
        if(scanf("%d %d %d", &v1, &v2, &weight) != 3)
            exit(1);
        Edge newEdge;
        newEdge.weight = weight;
        newEdge.v1 = v1;
        newEdge.v2 = v2;
        edges.push_back(newEdge);
    }

    sort(edges.begin(), edges.end(), comparator);

    printf("%d\n", findMaxWeight(edges, num_vertices, num_edges));

    return 0;
}