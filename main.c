#include "headers/big_include.h"

int main(){
    size_t start = 0;
    size_t stop = 0;
    struct str_number* first_number = create_number();
    struct str_number* second_number = create_number();

    if ( !read_data(first_number, second_number, &start, &stop) ) return 1;

    insert( first_number, second_number, &start, &stop );
    print_number( first_number );
    free_numbers( first_number, second_number );

}