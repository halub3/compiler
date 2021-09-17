/* FUNCTIONS FOR BFS ALGORITHM */

#include "../headers/big_include.h"

/*
 * Create empty queue and alloc memory with input size of nodes
 */
struct queue* create_queue(int16_t* total_nodes){
    struct queue* queue = malloc( sizeof(struct queue) );
    queue->size = 0;
    queue->array = calloc( *total_nodes, sizeof(int16_t) );

    return queue;
}

/*
 * Get first in queue number of node
 */
int16_t get_from_queue(struct queue* queue){
    if (queue->size == 0)
        return -1;

    int16_t answer = *(queue->array);
    for (size_t i = 0; i < queue->size - 1; i++){
        (queue->array)[i] = (queue->array)[i+1];
    }

    (queue->array)[queue->size - 1] = -1;
    queue->size -= 1;

    return answer;
}

/*
 * Put number of node in the end of queue
 */
void put_to_queue(struct queue* queue, int16_t value){
    (queue->array)[queue->size] = value;
    queue->size += 1;
}

/*
 * Check is number of node in queue now, return true if yes
 */
bool is_number_in_queue(struct queue* queue, int16_t number){
    for (size_t i = 0; i < queue->size; i++){
        if ( (queue->array)[i] == number ){
            return true;
        }
    }
    return false;
}

/*
 * Set param visited = false for all nodes
 * Necessary for starting next iteration in BFS
 */
void set_false_all_nodes(struct node* nodes, int16_t* total_nodes){
    for (int16_t i = 0; i < *total_nodes; i++){
        nodes[i].visited = false;
    }
}

/*
 * Fill reachability matrix 1 or 0 after one pass of the algorithm
 * One pass of the algorithm - full run of the algorithm with a starting number of node = node_number
 */
void fill_matrix(int16_t** matrix, struct node* nodes, int16_t node_number, int16_t* total_nodes){
    for (int16_t i = 0; i < *total_nodes; i++){
        if (nodes[i].visited) matrix[i][node_number] = 1;
        else matrix[i][node_number] = 0;
    }
}

/*
 * One iteration of BFS
 * We visit one node in queue and add new nodes in queu
 */
bool bfs_iteration(struct queue* queue, struct node* node_itr){
    node_itr->visited = true;

    // Go through all the nodes where the edges lead
    for (int16_t i = 0; i < node_itr->size; i++){
        struct node* second_node = (node_itr->edges)[i].second;

        //Check to remove re-add the same number of node in queue
        if ( is_number_in_queue(queue, second_node->number ) || second_node->visited ) continue;

        put_to_queue(queue, second_node->number);
    }

    if (queue->size == 0) return false;
    else return true;
}

/*
 * All algorithm of BFS with one start node = *start_number
 */
void bfs_main(struct node* nodes, int16_t* start_number, int16_t* total_nodes){
    struct queue* queue = create_queue(total_nodes);

    while ( bfs_iteration(queue, &nodes[*start_number]) ){
        *start_number =  get_from_queue(queue);
    }
}

/*
 * Run BFS algorithm
 * Run bfs_main with each start node
 */
void run_bfs(int16_t** matrix, struct node* nodes, int16_t* total_nodes){
    for (int16_t node_number = 0; node_number < *total_nodes; node_number++){
        int16_t start_number = node_number;
        bfs_main(nodes, &start_number, total_nodes);
        fill_matrix(matrix, nodes, node_number, total_nodes);
        set_false_all_nodes(nodes, total_nodes);
    }
}
