#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


struct Edge_info{
    int weight;
    int v1;
    int v2;
    struct Edge_info *next;
};


// void insertion_sort(Edge_info* head, Edge_info newElement){
//     Edge_info* current = head->next;
//     Edge_info* next = head->next->next;

//     /* first element of ordered list */
//     if(current == NULL){
//         current->next = &newElement;
//         return;
//     }

//     while(next != NULL){
//         current = current->next;
//         next = previous->next;
//         if(current->weight < newElement.weight){
//             newElement.next = current;
//             previous->next = &newElement;
//             return;
//         }
//     }

//     /* last element of ordered list */
//     current->next = &newElement;
//     newElement.next = NULL;
// }

void insertion_sort(struct Edge_info* head, Edge_info* newElement){
    if (list == NULL) {
        head->next = newElement;
    }
    
    else{
        Edge_info* current = head->next;
        printf("head weight: %d\n", head->next->weight);
        Edge_info* saveNext = NULL;
        printf("%d\n", current->weight);
        if(current->weight < newElement->weight){
            printf("if\n");
            newElement->next = current;
        }
        else{
            printf("else\n");
            while(current->next != NULL && current->next->weight > newElement->weight){
                current = current->next;
            }
            saveNext = current->next;
            newElement->next = saveNext;
            current->next = newElement;
        }
    }
}

int find_max_total_weight(struct Edge_info *list, long unsigned int num_vertices) {
    int max_total_weight = 0;
    vector<int> explored_vertices;
    struct Edge_info* current = list;
    printf("num_vertices: %ld\n", num_vertices);

    while(explored_vertices.size() < num_vertices) {
        printf("explored: %ld\n", explored_vertices.size());
        
        
        // printf("here\n");
        int i1 = current->v1;
        int i2 = current->v2;

        printf("i1: %d, i2: %d\n", i1, i2);

        if(find(explored_vertices.begin(), explored_vertices.end(), i1) == explored_vertices.end() &&
        find(explored_vertices.begin(), explored_vertices.end(), i2) == explored_vertices.end()) {
            printf("heheheha\n");
            explored_vertices.push_back(i1);
            explored_vertices.push_back(i2);
            max_total_weight += current->weight;
        }
        current = current->next;
    }

    return max_total_weight;
}


int main() {
    long unsigned int num_vertices;
    int num_edges;
    struct Edge_info* list = (Edge_info *)malloc(sizeof(struct Edge_info));
    struct Edge_info* new_edge;

    int v1, v2, weight;

    // input read
    cin >> num_vertices;
    cin >> num_edges;
    for(int i = 0; i < num_edges; i++) {
        new_edge = (Edge_info *)malloc(sizeof(struct Edge_info));
        cin >> v1 >> v2 >> weight;
        new_edge->v1 = v1;
        new_edge->v2 = v2;
        new_edge->weight = weight;
        
        insertion_sort(list, new_edge);
        printf("list weight: %d\n", list->weight);
        free(new_edge);
    }
    struct Edge_info* current = list;
    for(int i = 0; i < num_edges; i++) {
        printf("weights: %d\n", current->weight);
        current = current->next;
    }



    // cout << find_max_total_weight(list, num_vertices);
    free(emptyHead);
    return 0;
}