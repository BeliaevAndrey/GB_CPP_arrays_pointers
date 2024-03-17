/*
Задача 1
Что нужно сделать:
Напишите функцию swapvec, принимающую std::vector и указатель на массив переменных типа int (одного размера) и обменивающую значения этих массивов.
*/

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> swapvec(std::vector<int>, int *);

    void printVec(std::vector<int>);
    void printArr(int[], int);

    std::vector<int> a = {1, 2, 3, 4};
    int b[] = {2, 4, 6, 8};

    int sizeB = sizeof(b) / sizeof(b[0]);
    printVec(a);
    printArr(b, sizeB);

    std::cout << "after swap: " << std::endl;
    a = swapvec(a, b);

    std::cout << "vec: ";
    printVec(a);
    std::cout << "arr: ";
    printArr(b, sizeB);

    return 0;
}

std::vector<int> swapvec(std::vector<int> vec, int *arr)
{
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        int tmp = *(arr + i);
        std::cout << "swapping: " << tmp;
        *(arr + i) = vec[i];
        vec.pop_back();
        vec.push_back(tmp);
        std::cout << " <-> " << vec[i] << std::endl;
    }
    return vec;
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
