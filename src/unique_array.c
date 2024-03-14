#include <stdlib.h>

#include "unique_array.h"
#include "bubble_sort.h"

void *uniq_arr(Array *arr)
{
    int res_arr_size = 0;
    char *res_arr = malloc(arr->capacity * sizeof(char));
    if (res_arr == NULL)
        exit(1);

    char temp_arr[arr->capacity];

    for (int i = 0; i < arr->size; i++)
        temp_arr[i] = '0';

    for (int i = 0; i < arr->size; i++)
    {
        int flag_uniq = 1, flag_repeat = 1;

        for (int j = (i + 1); j < arr->size; j++)
        {
            if (arr->array[i] == arr->array[j])
            {
                flag_uniq = 0;
                temp_arr[i] = arr->array[i];
                break;
            }
        }
        for (int j = 0; j < arr->size; j++)
        {
            if (arr->array[i] == temp_arr[j])
            {
                flag_repeat = 0;
                break;
            }
        }
        if (flag_uniq)
        {
            res_arr[res_arr_size] = arr->array[i];
            res_arr_size++;
        }
        else if (flag_repeat)
        {
            res_arr[res_arr_size] = arr->array[i];
            res_arr_size++;
        }
    }
    bubble_sort(res_arr, res_arr_size);
    free(arr->array);
    arr->size = res_arr_size;
    arr->array = res_arr;
}
