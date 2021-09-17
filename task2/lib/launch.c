/* FUNCTIONS TO RUN PROGRAM*/

#include "../headers/big_include.h"

/*
 * Read values of total_nodes (N) and total_edges (M) and check them
 */
bool read_data(int16_t* total_nodes, int16_t* total_edges){
    scanf("%" SCNd16, total_nodes);
    scanf("%" SCNd16, total_edges);

    if ( *total_nodes <= 0 || *total_edges < 0 || *total_nodes + *total_edges >= MAX_SUM){
        printf("Wrong data of N or M\n");
        return false;
    }
    if (*total_edges > *total_nodes * (*total_nodes-1)) {
        printf("Too much edges\n");
        return false;
    }

    return true;
}

/*
 * Create matrix and run BFS algorithm
 */
int16_t** make_final_matrix(struct node* nodes, int16_t* total_nodes){
    int16_t** matrix = create_matrix(total_nodes);
    run_bfs(matrix, nodes, total_nodes);

    return matrix;
}

/*
 * Print resultant matrix and free all alloc data
 */
void print_matrix_and_free_data(int16_t** matrix, struct node* nodes, int16_t* total_nodes){
    print_matrix(matrix, total_nodes);

    free_nodes(nodes, total_nodes);
    free_matrix(matrix, total_nodes);
}


