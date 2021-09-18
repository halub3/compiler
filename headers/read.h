// FUNCTIONS TO READ DATA AND CHECK IT

#ifndef READ_H
#define READ_H

// Alloc memory for number
struct str_number* create_number();

// Read all data and check it
bool read_data(struct str_number* first_number, struct str_number* second_number, size_t* start, size_t* stop);

#endif //UNTITLED1_READ_H
