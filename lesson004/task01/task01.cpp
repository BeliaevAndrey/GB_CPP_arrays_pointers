/*
Задача 1
Что нужно сделать:
Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом
массиве, что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и
вывести их. a = {-2,1,-3,4,-1,2,1,-5,4} Тогда наибольшая сумма последовательных
элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6. Необходимо
вывести 3 и 6.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = 0;
    int lind, rind;

    for (int i = 0; i < a.size(); i++)
    {
        int locSum = 0;
        for (int j = i; j < a.size(); j++)
        {
            locSum += a[j];

            if (locSum > maxSum)
            {
                maxSum = locSum;
                lind = i;
                rind = j;
            }
        }
    }

    cout << lind << " " << rind << endl;

    return 0;
}
