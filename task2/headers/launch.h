//
// Created by Александр Сущенко on 17/09/2021.
//

#ifndef UNTITLED_LAUNCH_H
#define UNTITLED_LAUNCH_H

bool read_data(int16_t* total_nodes, int16_t* total_edges);
int16_t** make_final_matrix(struct node* nodes, int16_t* total_nodes);
void print_matrix_and_free_data(int16_t** matrix, struct node* nodes, int16_t* total_nodes);

#endif //UNTITLED_LAUNCH_H
