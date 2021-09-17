//
// Created by Александр Сущенко on 17/09/2021.
//

#ifndef STRUCTS_H
#define STRUCTS_H

/*
 * One edge with the first and second value
 */
struct edge{
    struct node* first;
    struct node* second;
};

/*
 * Node with params:
 *   number - node number (from 0 to N-1)
 *   edges - array of edges with first value = number
 *   size - size of array of edges
 *   visited - visited or not in BFS algorithm
 */
struct node{
    int16_t number;
    struct edge* edges;
    size_t size;
    bool visited;
};

/*
 * Queue in BFS algorithm
 *  array - array of numbers in queue
 *  size - array's size
 */
struct queue{
    int16_t* array;
    size_t size;
};

#endif //STRUCTS_H
