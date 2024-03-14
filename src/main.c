#include <stdio.h>
#include <stdlib.h>

#include "array_operation.h"
#include "in_out_array.h"

#define COUNT_ARRAY 2

int main()
{
    Array *arr[COUNT_ARRAY];

    printf("Введите элементы сначала для первого, потом для второго множества: \n");
    for (int i = 0; i < COUNT_ARRAY; i++)
    {
        arr[i] = malloc(sizeof(Array));
        if (arr[i] == NULL)
            return 1;
        input_array(arr[i]);
    }

    Array *res_array = NULL;

    do
    {
        res_array = implement_operation(arr[0], arr[1]);
        if (res_array->size != 0)
            output_array(res_array, arr[0], arr[1]);

        free(res_array->array);
        free(res_array);
    } while (1);

    return 0;
}
