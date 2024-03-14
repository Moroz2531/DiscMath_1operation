#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "array_operation.h"
#include "unique_array.h"

void select_operation(short *select)
{
    printf("Выберите необходимую операцию (порядок A ... B):\n\
        1. Операция объединения.\n\
        2. Операция пересечения.\n\
        3. Операция вхождения.\n\
        4. Разность.\n\
        5. Выход из программы.\n");
    printf("Введите номер операции: ");
    scanf("%hd", select);
};

void union_arrays(Array *a1, Array *a2, Array *res_ar)
{
    for (int i = 0; i < a1->size; i++)
    {
        res_ar->array[res_ar->size] = a1->array[i];
        res_ar->size++;
    }

    for (int i = 0; i < a2->size; i++)
    {
        res_ar->array[res_ar->size] = a2->array[i];
        res_ar->size++;
    }
    uniq_arr(res_ar);
};

void intersection_arrays(Array *a1, Array *a2, Array *res_ar)
{
    for (int i = 0; i < a1->size; i++)
    {
        for (int j = 0; j < a2->size; j++)
        {
            if (a1->array[i] == a2->array[j])
            {
                res_ar->array[res_ar->size] = a1->array[i];
                res_ar->size++;
                break;
            }
        }
    }
};

int entry_arrays(Array *a1, Array *a2)
{
    int count_elem_arr1 = 0;

    for (int i = 0; i < a1->size; i++)
    {
        for (int j = 0; j < a2->size; j++)
        {
            if (a1->array[i] == a2->array[j])
            {
                count_elem_arr1++;
                break;
            }
        }
    }
    if (count_elem_arr1 == a1->size)
        return 1;
    return 0;
};

void different_arrays(Array *a1, Array *a2, Array *res_ar)
{
    for (int i = 0; i < a1->size; i++)
    {
        int flag_diff = 1;
        for (int j = 0; j < a2->size; j++)
        {
            if (a1->array[i] == a2->array[j])
            {
                flag_diff = 0;
                break;
            }
        }
        if (flag_diff)
        {
            res_ar->array[res_ar->size] = a1->array[i];
            res_ar->size++;
        }
    }
};

Array *implement_operation(Array *arr1, Array *arr2)
{
    short select;
    Array *result_array = malloc(sizeof(Array));
    if (result_array == NULL)
        exit(1);

    result_array->capacity = arr1->size + arr2->size;
    result_array->size = 0;
    result_array->array = malloc(result_array->capacity * sizeof(char));
    if (result_array->array == NULL)
        exit(1);

    select_operation(&select);

    switch (select)
    {
    case 1:
        union_arrays(arr1, arr2, result_array);
        break;
    case 2:
        intersection_arrays(arr1, arr2, result_array);
        break;
    case 3:
        if (entry_arrays(arr1, arr2))
            printf("Множество A является подмножеством B\n\n");
        else
            printf("Множество A не является подмножеством B\n\n");
        break;
    case 4:
        different_arrays(arr1, arr2, result_array);
        break;
    case 5:
        free(arr1->array);
        free(arr2->array);
        free(result_array->array);
        free(arr1);
        free(arr2);
        free(result_array);
        exit(0);
    default:
        printf("Номера с такой операцией отсутствует!\n");
    };

    return result_array;
};
