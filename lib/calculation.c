//
// FUNCTIONS TO CALCULATE THE ANSWER
//
#include "../headers/big_include.h"

/*
 * Move number's bits:
 *  all bits with number >= stop become 0
 *  shift new value by <start> bits to the left
 *      In the end: All bits = 0 except first (stop - start + 1) bits,
 *      which shift to the left on (start) bits
 */
uint64_t bit_shifts (uint64_t number, size_t start, size_t stop){
    uint64_t new_number = number;
    new_number = new_number << (MAX_SIZE - stop + start - 1);
    new_number = new_number >> (MAX_SIZE - stop + start - 1);
    new_number = new_number << start;

    return new_number;

}

/*
 * Multiply ( & ) the first number by value from bit_shifts (but All bits = 1 (not 0) except first (stop - start + 1) )
 * and then add ( | ) normal value of bit_shift (All bits = 0 except first (stop - start + 1) )
 *
 * At the end we get the desired number
 */
void insert(struct str_number* first_number, struct str_number* second_number,
        size_t const* start, size_t const* stop){

    first_number->number = ( first_number->number & ~bit_shifts( ~second_number->number, *start, *stop) )
                           | bit_shifts( second_number->number, *start, *stop );
}


