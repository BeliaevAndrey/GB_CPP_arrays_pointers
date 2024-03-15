/**
Задача 3
Что нужно сделать:
С клавиатуры вводятся числа. Когда пользователь вводит «-1», необходимо выводить на экран пятое по возрастанию число среди введённых. Когда пользователь вводит «-2», программа завершает работу.

Пример:

ввод: 7 5 3 1 2 4 6 -1
вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
ввод: 1 1 1 -1
вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
ввод -2
завершение программы
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> sortAndPrint(vector<int>);

    vector<int> vec;
    int value = -3;

    while (value != -2)
    {
        cout << "Input number: ";
        cin >> value;
        if (value == -2)
        {
            cout << "Finishing..." << endl;
            return 0;
        }
        else if (value == -1)
        {
            if (vec.size() < 5)
                cout << "Amount of numbers is less then 5." << endl;
            else
            {
                // Неочевидно из задания -- нужно ли
                // перезаписывать вектор
                // vec = sortAndPrint(vec);

                sortAndPrint(vec);
            }
        }
        else
            vec.push_back(value);
    }

    return 0;
}

vector<int> sortAndPrint(vector<int> vec)
{

    vector<int> result(vec.size(), 0);
    int minVal = vec[0];

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < minVal)
            minVal = vec[i];
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        int maxInd = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j] > vec[maxInd])
                maxInd = j;
        }
        result[i] = vec[maxInd];
        vec[maxInd] = minVal;
    }

    cout << "Fifth by increase: " << result[4] << endl;
    return result;
}
