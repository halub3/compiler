//
// Created by Александр Сущенко on 18/09/2021.
//

#ifndef BIG_INCLUDE_H
#define BIG_INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

#include "read.h"
#include "print.h"
#include "calculation.h"

#define MAX_SIZE 64

struct str_number{
    uint64_t number;
    size_t size;
};

#endif //BIG_INCLUDE_H
