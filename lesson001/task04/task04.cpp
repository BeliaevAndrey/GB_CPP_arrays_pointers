/*
Задание 4. Ряд чисел* (дополнительное задание)

Что нужно сделать:
В программе инициализирован массив из 15 целых положительных чисел. Эти числа
являются множеством из 14 последовательных чисел, начиная с Х (Х может быть
любым), а одно число из ряда повторяется. Необходимо найти повторяющееся число
и вывести его в консоль. По возможности используйте минимум дополнительной
памяти и проходов по массиву.
*/

#include <iostream>

using namespace std;

int main()
{
    int findDouble(int[], int);

    int array[] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int arraySize = sizeof(array) / sizeof(array[0]);

    int doubleElement = findDouble(array, arraySize);
    if (doubleElement != 0)
        cout << "Double element: " << doubleElement << endl;
    else
        cout << "No double elements" << endl;
    return 0;
}

int findDouble(int array[], int arraySize)
{
    int unique = arraySize - 1;
    int minNum = array[0];
    int arraySum = 0, uniqueSum, step = 1;

    for (int i = 0; i < arraySize; i++)
    {
        if (minNum > array[i])
            minNum = array[i];
        arraySum += array[i];
    }
    uniqueSum = (2 * minNum + step * (unique - 1)) * unique / 2;

    return arraySum - uniqueSum;
}