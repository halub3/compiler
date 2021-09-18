//
// FUNCTIONS TO READ AND FREEING DATA
//

#include "../headers/big_include.h"

/*
 * Print number in bits and move first zeros
 */
void print_number(struct str_number* number){

    uint64_t idx = (uint64_t)pow(2.0, (double)number->size - 1);
    uint64_t bit;
    bool was_one = false;

    for(size_t i = 0; i < number->size; i++){
        uint64_t number_for_calc = number->number;
        bit = (number_for_calc << i) & idx;
        bit = bit >> (number->size - 1);

        if ( bit == 0 & ! was_one) continue;
        printf("%" PRIu64, bit);
        was_one = true;
    }

    printf("\n");
}

/*
 * Freeing memory of numbers
 */
void free_numbers(struct str_number* first_number, struct str_number* second_number){
    free(first_number);
    free(second_number);
}

