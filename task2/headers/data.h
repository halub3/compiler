/* FUNCTIONS WITH INPUT DATA - NODES, EDGES AND MATRIX*/

#ifndef NODES_H
#define NODES_H

void free_nodes(struct node* nodes, int16_t* total_nodes);
void free_matrix(int16_t** matrix, int16_t* total_nodes);
void print_matrix(int16_t** matrix, int16_t* total_nodes);
bool read_edges(struct node* nodes, int16_t* total_nodes, int16_t* total_edges);
struct node* create_nodes(int16_t* total_nodes, int16_t* total_edges);
int16_t** create_matrix(int16_t* matrix_size);

#endif //NODES_H
