#include <stdlib.h>
#include <stdio.h>

#include "in_out_array.h"
#include "unique_array.h"

void input_array(Array *arr)
{
    arr->size = 0;
    arr->capacity = 5;
    arr->array = malloc(arr->capacity * sizeof(char));
    if (arr->array == NULL)
        exit(1);

    char ch;
    while ((ch = getchar()) != '\n')
    {
        if ('a' <= ch && ch <= 'z')
        {
            if (arr->size >= arr->capacity)
            {
                char *t = realloc(arr->array, 2 * arr->capacity * sizeof(char));
                if (t == NULL)
                    exit(1);

                arr->capacity *= 2;
                arr->array = t;
            }
            arr->array[arr->size] = ch;
            arr->size++;
        }
    }
    uniq_arr(arr);
};

void output_array(Array *arr, Array *a1, Array *a2)
{
    printf("\nПервое множество:\n");

    for (int i = 0; i < a1->size; i++)
        printf("%c ", a1->array[i]);

    printf("\nВторое множество:\n");

    for (int i = 0; i < a2->size; i++)
        printf("%c ", a2->array[i]);

    printf("\nРезультат: \n");

    for (int i = 0; i < arr->size; i++)
        printf("%c ", arr->array[i]);
    printf("\n\n");
}
