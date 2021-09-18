//
// FUNCTIONS TO READ DATA AND CHECK IT
//
#include "../headers/big_include.h"

/*
 * Check that the numbers contain only 0 and 1
 */
bool check_number(char const* data, size_t const* size){
    for (size_t i = 0; i < *size; i++){
        if ( data[i] != '0' && data[i] != '1' ) return false;
    }

    return true;
}

/*
 * Check start and stop value on correct size
 */
bool check_data(struct str_number* first_number, struct str_number* second_number, size_t const* start, size_t const* stop){

    // Stop must be >= start
    if ( *start > *stop ) {
        printf("\nYour i1 > i2\n");
        return false;
    }

    // Size of insert range must be less than the size of the first number
    if ( *stop - *start + 1 > second_number->size ) {
        printf("\nYour Size > Size of second number\n");
        return false;
    }

    // values must be > 0 and i2 must be less than size of first number
    if ( *start < 0 || *stop < 0 || *stop >= first_number->size ) {
        printf("\nError with i1 or i2\n");
        return false;
    }

    return true;
}

/*
 * Read one value (for start and stop)
 */
void read_one_value(size_t* value){
    scanf("%zu", value);
}

/*
 * Read number in bytes and convert it
 */
bool read_number_in_bytes(struct str_number* number){

    char input[MAX_SIZE];
    scanf("%s", input);
    size_t size = strlen(input);

    if (size > MAX_SIZE || !check_number(input, &size) ) {
        printf("Wrong number\n");
        return false;
    }

    char *end_pointer = input + size;
    number->number = (uint64_t) strtol(input, &end_pointer, 2);
    number->size = size;

    return true;
}

/*
 * Read all data and check it
 */
bool read_data(struct str_number* first_number, struct str_number* second_number, size_t* start, size_t* stop){
    if ( !read_number_in_bytes(first_number) || !read_number_in_bytes(second_number) ) return false;

    read_one_value(start);
    read_one_value(stop);

    if ( !check_data(first_number, second_number, start, stop) ) return false;
    else return true;
}

/*
 * Alloc memory for number
 */
struct str_number* create_number(){
    return (struct str_number*)malloc( sizeof(struct str_number) );
}

