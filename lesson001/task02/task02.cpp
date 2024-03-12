/*
Задание 2. Сортировка

Что нужно сделать:
Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и
вывести в консоль в порядке от большего к меньшему. По возможности используйте
минимум дополнительной памяти и проходов по массиву.
*/

#include <iostream>

using namespace std;

int main()
{
    void printArray(float[], int);
    void heapSort(float[], int);

    int arraySize = 15;

    // float array[] = {        /* sample data */
    //     1.2, 2.3, 1.11, 3.4, 5.5,
    //     5.4, 5.3, 5.1, 1.5, 1.25,
    //     5.41, 5.31, 5.11, 1.51, 1.251};

    float array[arraySize];
    cout << "Input array elements:" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << "element #" << i << ": ";
        cin >> array[i];
    }

    cout << "Source array: " << endl;
    printArray(array, arraySize);

    heapSort(array, arraySize);
    cout << "Sorted array: " << endl;
    printArray(array, arraySize);
}

void heapify(float array[], int arraySize, int n)
{
    int large = n;
    int left = 2 * n + 1;
    int right = 2 * n + 2;

    if (left < arraySize && array[left] < array[large])
        large = left;

    if (right < arraySize && array[right] < array[large])
        large = right;

    if (large != n)
    {
        swap(array[n], array[large]);
        heapify(array, arraySize, large);
    }
}

void heapSort(float array[], int arraySize)
{
    void heapify(float[], int, int);

    for (int i = arraySize / 2 - 1; i >= 0; i--)
        heapify(array, arraySize, i);

    for (int i = arraySize - 1; i > 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void printArray(float array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        cout << array[i] << " ";

    cout << endl;
}