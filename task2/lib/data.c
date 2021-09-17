/* FUNCTIONS WITH INPUT DATA - NODES, EDGES AND MATRIX*/

#include "../headers/big_include.h"

/* ********** NODES ********** */

/*
 * Create one node, allocate memory for one node, set start params
 */
void create_node(struct node* nodes, int16_t number, int16_t* total_edges){
    struct node* node = &nodes[number];
    node->number = number;
    node->visited = false;
    node->size = 0;
    node->edges = calloc( *total_edges, sizeof(struct edge) );
}

/*
 * Create array of nodes with start params, allocate memory for array of nodes
 */
struct node* create_nodes(int16_t* total_nodes, int16_t* total_edges){
    struct node* nodes = calloc( *total_nodes, sizeof(struct node) );

    for (int16_t i = 0; i < *total_nodes; i++){
        create_node(nodes, i, total_edges);
    }

    return nodes;
}

/* ********** EDGES ********** */

/*
 * Create one edge and add it to node = first value, return current status
 */
bool read_edge(struct node* nodes, const int16_t* total_edges){

    int16_t first_number;
    int16_t second_number;

    scanf("%" SCNd16, &first_number);
    scanf("%" SCNd16, &second_number);

    if ( first_number >= *total_edges || second_number >= *total_edges ||
            first_number < 0 || second_number < 0) {
        return false;
    }

    struct node* node = &nodes[first_number];
    (node->edges[node->size]).first = node;
    (node->edges[node->size]).second = &nodes[second_number];
    node->size += 1;

    return true;

}

/*
 * Read all edges, check their value and add them to their nodes
 */
bool read_edges(struct node* nodes, int16_t* total_nodes, int16_t* total_edges){
    for (int16_t i = 0; i < *total_edges; i++){
        if ( !read_edge(nodes, total_nodes) ) {
            printf("Error in edges\n");
            return false;
        }
    }
    return true;
}

/* ********** MATRIX ********** */

/*
 * Take the memory for matrix with shape (matrix_size)x(matrix_size)
 */
int16_t** create_matrix(int16_t* matrix_size){
    int16_t** array = calloc( *matrix_size, sizeof(int16_t*) );

    for (int16_t i = 0; i < *matrix_size; i++){
        array[i] = calloc( *matrix_size, sizeof(int16_t) );
    }

    return array;
}

/*
 * Freeing up memory of array of nodes
 */
void free_nodes(struct node* nodes, int16_t* total_nodes){
    for (int16_t i = 0; i < *total_nodes; i++){
        free(nodes[i].edges);
    }
    free(nodes);
}

/*
 * Freeing up memory of array of edges
 */
void free_matrix(int16_t** matrix, int16_t* total_nodes){
    for (int16_t i = 0; i < *total_nodes; i++) {
        free(matrix[i]);
    }

    free(matrix);
}

/*
 * Print matrix with shape (matrix_size)x(matrix_size)
 */
void print_matrix(int16_t** matrix, int16_t* matrix_size){
    for (int16_t i = 0; i < *matrix_size; i++){
        for (int16_t j = 0; j < *matrix_size; j++){
            printf("%" PRId16, matrix[i][j]);
        }
        printf("\n");
    }
}


