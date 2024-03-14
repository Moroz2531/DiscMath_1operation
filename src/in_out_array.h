#ifndef STRUCT_ARRAY
#define STRUCT_ARRAY

typedef struct
{
    char *array;
    int size;
    int capacity;
} Array;

#endif

#ifndef IN_OUT_ARRAY
#define IN_OUT_ARRAY

void input_array(Array *arr);
void output_array(Array *arr, Array *a1, Array *a2);

#endif
