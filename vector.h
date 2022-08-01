#pragma once

#include "rpgclass.h"

typdef struct vector {
    union* data {
        rpgclass class;
        location location;
    } data;
    //rpgclass* data;
    int mode;//What type of data?
    size_t limit; // Total size of the vector
    size_t current; //Number of vectors in it at present
};

/*
typdef struct vector_location {
    vector* data;
    size_t limit; // Total size of the vector
    size_t current; //Number of vectors in it at present
};

*/
typedef struct vector_map {
    vector* data;
    size_t limit; // Total size of the vector
    size_t current; //Number of vectors in it at present
} 

//void vector_setlimit();

void vector_push_rpgclass(vector v, rpgclass class); 

void vector_push_map(vector_map m, vector_map map);

struct rpgclass vector_pop_rpgclass();

struct location vector_pop_location();

struct map vector_pop_map();
