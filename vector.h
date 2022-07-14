#pragma once

#include "rpgclass.h"

typdef struct vector_class {
    rpgclass* data;
    size_t limit; // Total size of the vector
    size_t current; //Number of vectors in it at present
};

typdef struct vector_location {
    location* data;
    size_t limit; // Total size of the vector
    size_t current; //Number of vectors in it at present
};

typedef struct vector_map {
    vector_location* data;
    size_t limit; // Total size of the vector
    size_t current; //Number of vectors in it at present
}

void vector_setlimit();
