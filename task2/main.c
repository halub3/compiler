#include "headers/big_include.h"


int main(){
    int16_t total_nodes = 0;
    int16_t total_edges = 0;

    if ( !read_data(&total_nodes, &total_edges) )  return 1;

    struct node* nodes = create_nodes(&total_nodes, &total_edges);
    if ( !read_edges(nodes, &total_nodes, &total_edges) ) return 2;

    int16_t** reachability_matrix = make_final_matrix(nodes, &total_nodes);
    print_matrix_and_free_data(reachability_matrix, nodes, &total_nodes);

    return 0;
}