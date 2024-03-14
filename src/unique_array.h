#ifndef STRUCT_ARRAY
#define STRUCT_ARRAY

typedef struct
{
    char *array;
    int size;
    int capacity;
} Array;

#endif

#ifndef UNIQUE_ARRAY
#define UNIQUE_ARRAY

void *uniq_arr(Array *arr);

#endif
