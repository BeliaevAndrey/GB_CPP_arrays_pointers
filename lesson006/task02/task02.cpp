/*
Задача 2

Что нужно сделать:
Написать функцию, которая принимает указатель на тип int, по которому размещены 10 переменных типа int. Функция ничего не возвращает, но по тому же указателю элементы должны лежать в обратном порядке.
*/

#include <iostream>

int main()
{
    void backSort(int *, int size);
    void printArr(int *, int size);

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int array[] = {11, 2, 3, 1, 7, 5, 6, 7, 8, 10, 9};
    int size = sizeof(array) / sizeof(*(array));

    printArr(array, size);
    backSort(array, size);
    printArr(array, size);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backSort(int *array, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        ::swap(array + i, array + size - 1 - i);
    }
}

void printArr(int *array, int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
