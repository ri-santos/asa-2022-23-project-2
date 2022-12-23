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


// void merge(Edge edges[], int l, int m, int r) {
    
//     printf("yau\n");
//     int i, j, k;
//     Edge aux[r];

//     for (i = m+1; i > l; i--){
//         aux[i-1] = edges[i-1];
//     }
//     for (j = m; j < r; j++){
//         aux[r+m-j] = edges[j+1];
//     }
//     for (k = l; k <= r; k++){
//         if (aux[l].weight <= aux[i].weight){ 
//             edges[k] = aux[j--]; 
//         }
//         else{ 
//             edges[k] = aux[i++]; 
//         }
//     }
// }

// void mergeSort(Edge edges[], int l, int r) {
//     int m = (r + l) / 2;

//     printf("sort\n");
//     if(r <= l){ return; }
//     mergeSort(edges, l, m);
//     mergeSort(edges, m + 1, r);
//     merge(edges, l, m, r);
// }


void bubbleSort(Edge edge[], int n){
    int i, j;
    bool swapped = false;

    for (i = 0; i < n - 1; i++){
 
        for (j = 0; j < n - i - 1; j++){
            if (edge[j].weight < edge[j + 1].weight){
                swap(edge[j], edge[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false){ break; }
    }
}


int findMaxWeight(Edge edges[], int num_vertices, int num_edges){
    int maxWeight = 0;
    int explored_vertices[num_vertices] = {0};
    int vertices_counter = 0;

    int i = 0;
    while(vertices_counter < num_vertices && i < num_edges){
        int v1 = edges[i].v1;
        int v2 = edges[i].v2;
        if(explored_vertices[v1-1] == 0 || explored_vertices[v2-1] == 0) {
            if(explored_vertices[v1-1] == 0) {
                explored_vertices[v1-1] = 1;
                vertices_counter++;
            }
            if(explored_vertices[v2-1] == 0) {
                explored_vertices[v2-1] = 1;
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
    
    // array of all edges
    Edge edges[num_edges];
    for(int i = 0; i < num_edges; i++) {
        cin >> v1 >> v2 >> weight;
        edges[i].weight = weight;
        edges[i].v1 = v1;
        edges[i].v2 = v2;
    }

    bubbleSort(edges, num_edges);

    cout << findMaxWeight(edges, num_vertices, num_edges) << endl;

    return 0;
}