/*
Задача 4
Что нужно сделать:
Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел.

Пример:

Массив {-100,-50, -5, 1, 10, 15}
Вывод: 1, -5, 10, 15, -50, -100
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    void sortAndPrint(vector<int>);

    vector<int> vec = {-100, -50, -5, 1, 10, 15};
    vector<int> vec1 = {-14, 10, 11, 12, 15, 25};
    vector<int> vec2 = {-14, -10, -9, -3, 1, 25};
    
    sortAndPrint(vec);
    sortAndPrint(vec1);
    sortAndPrint(vec2);

    return 0;
}

void sortAndPrint(vector<int> vec)
{

    vector<int> result(vec.size(), 0);
    int minVal = abs(vec[0]);

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < minVal)
            minVal = abs(vec[i]);
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        int maxInd = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            if (abs(vec[j]) > abs(vec[maxInd]))
                maxInd = j;
        }
        result[i] = vec[maxInd];
        vec[maxInd] = minVal;
    }

    cout << "Sorted by absolute value: ";
    
    for (int i = 0; i < vec.size(); i++)
    {
        cout << result[i] << " ";
    }
    
    cout << endl;
}
