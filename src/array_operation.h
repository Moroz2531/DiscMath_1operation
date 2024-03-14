#ifndef STRUCT_ARRAY
#define STRUCT_ARRAY

typedef struct
{
    char *array;
    int size;
    int capacity;
} Array;

#endif

#ifndef ARRAY_OPERATION
#define ARRAY_OPERATION

#define COUNT_OPERATION 4

void select_operation(short *select);
void union_arrays(Array *a1, Array *a2, Array *res_ar);
void intersection_arrays(Array *a1, Array *a2, Array *res_ar);
void different_arrays(Array *a1, Array *a2, Array *res_ar);
Array *implement_operation(Array *arr1, Array *arr2);
int entry_arrays(Array *a1, Array *a2);

#endif
