#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


typedef struct {
    int weight;
    int v1;
    int v2;
} Edge;


void merge(Edge edges[], int l, int m, int r, int num_edges) {
    
    printf("yau\n");
    int i, j, k;
    Edge aux[num_edges];

    for (i = m+1; i > l; i--){
        aux[i-1] = edges[i-1];
    }
    for (j = m; j < r; j++){
        aux[r+m-j] = edges[j+1];
    }
    for (k = l; k <= r; k++){
        if (aux[l].weight <= aux[i].weight){ 
            edges[k] = aux[j--]; 
        }
        else{ 
            edges[k] = aux[i++]; 
        }
    }
}

void mergeSort(Edge edges[], int l, int r, int num_edges) {
    int m = (r + l) / 2;

    printf("sort\n");
    if(r <= l){ return; }
    mergeSort(edges, l, m, num_edges);
    mergeSort(edges, m + 1, r, num_edges);
    merge(edges, l, m, r, num_edges);
}



int findMaxWeight(Edge edges[], int num_vertices, int num_edges){
    int maxWeight = 0;
    int explored_vertices[num_vertices];
    int vertices_counter = 0;

    int i = 0;
    while(vertices_counter < num_vertices){
        int v1 = edges[i].v1;
        int v2 = edges[i].v2;
        if(explored_vertices[v1] == 0 || explored_vertices[v2] == 0) {
            if(explored_vertices[v1] == 0) {
                explored_vertices[v1] = 1;
                vertices_counter++;
            }
            if(explored_vertices[v2] == 0) {
                explored_vertices[v2] = 1;
                vertices_counter++;
            }
            maxWeight += edges[i].weight;
        }
        i++;
    }

    return maxWeight;
}


int main(){
    int num_vertices;
    int num_edges;
    int v1, v2, weight;
    
    //input read
    cin >> num_vertices;
    cin >> num_edges;
    printf("hi1\n");
    
    // array of all edges
    Edge edges[num_edges];
    for(int i = 0; i < num_edges; i++) {
        cin >> v1 >> v2 >> weight;
        edges[i].weight = weight;
        edges[i].v1 = v1;
        edges[i].v2 = v2;
    }

    mergeSort(edges, 0, num_edges, num_edges);

    printf("hi2\n");
    //cout << findMaxWeight(edges, num_vertices, num_edges);

    for(int i = 0; i < num_edges; i++) {
        printf("%d\n", edges[i].weight);
    }

    return 0;
}