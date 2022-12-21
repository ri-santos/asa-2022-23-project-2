#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

struct Edge_info{
    int weight;
    int v1;
    int v2;
    struct Edge_info *next;
};

void insertion_sort(struct Edge_info* list, Edge_info newElement){
    if (list == NULL) {list = &newElement;}
    
    else{
        struct Edge_info* saveNext = NULL;
        while(list->weight > newElement.weight){
            list = list->next;
        }
        saveNext = list->next;
        newElement.next = saveNext;
        list->next = &newElement;
    }
}

int find_max_total_weight(struct Edge_info *list, long unsigned int num_vertices) {
    int max_total_weight = 0;
    vector<int> explored_vertices;
    struct Edge_info* current = list;

    while(explored_vertices.size() < num_vertices) {
        if(explored_vertices[current->v1] != current->v1 ||
        explored_vertices[current->v2] != current->v2) {
            explored_vertices[current->v1] = current->v1;
            explored_vertices[current->v2] = current->v2;
            max_total_weight += current->weight;
        }
        current = current->next;
    }

    return max_total_weight;
}


int main() {
    long unsigned int num_vertices;
    int num_edges;
    struct Edge_info* list = NULL;
    struct Edge_info new_edge;

    int v1, v2, weight;

    // input read
    cin >> num_vertices;
    cin >> num_edges;
    for(int i = 0; i < num_edges; i++) {
        cin >> v1 >> v2 >> weight;
        new_edge.v1 = v1;
        new_edge.v2 = v2;
        new_edge.weight = weight;
        new_edge.next = NULL;
    
        insertion_sort(list, new_edge);
    }

    cout << find_max_total_weight(list, num_vertices);

    return 0;
}