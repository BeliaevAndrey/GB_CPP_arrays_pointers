/*
Задача 1
Что нужно сделать:
Напишите функцию swapvec, принимающую std::vector и указатель на массив переменных типа int (одного размера) и обменивающую значения этих массивов.
*/

#include <iostream>
#include <vector>

int main()
{
    void swapvec(std::vector<int> &, int *);

    void printVec(std::vector<int>);
    void printArr(int[], int);

    std::vector<int> a = {1, 2, 3, 4};
    int b[] = {2, 4, 6, 8};

    int sizeB = sizeof(b) / sizeof(b[0]);
    std::cout << "vec: ";
    printVec(a);
    std::cout << "arr: ";
    printArr(b, sizeB);

    std::vector<int> &refA = a;

    std::cout << "after swap: " << std::endl;
    swapvec(refA, b);

    std::cout << "vec: ";
    printVec(a);
    std::cout << "arr: ";
    printArr(b, sizeB);

    return 0;
}

void swapvec(std::vector<int> &vec, int *arr)
{

    for (int i = 3; i >= 0; i--)
    {
        int tmp = arr[i];
        arr[i] = vec[i];
        vec[i] = tmp;
    }
}

void printVec(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
