/*
Задача 1

Что нужно сделать:
Написать функцию, принимающую два указателя на int и меняет местами содержимое данных указателей.

*/

#include <iostream>

void swap(int *a, int *b)
{
    std::cout << "Swapping..." << std::endl;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    std::cout << "a: " << a << " "
              << "b: " << b << std::endl;

    swap(&a, &b);

    std::cout << "a: " << a << " "
              << "b: " << b << std::endl;

    return 0;
}
