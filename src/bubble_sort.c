#include "bubble_sort.h"

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
};

void bubble_sort(char *array, int size)
{
    int flag_bubble_sort = 1;

    for (int i = 0; i < size; i++)
    {
        if (flag_bubble_sort)
        {
            flag_bubble_sort = 0;
            for (int j = 0; j < size - i - 1; j++)
            {
                if ((int)array[j] > (int)array[j + 1])
                {
                    swap(&array[j], &array[j + 1]);
                    flag_bubble_sort = 1;
                }
            }
        }
    }
};
