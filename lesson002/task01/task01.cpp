/*
Задача 1

Что нужно сделать
Необходимо из заданного пользователем вектора удалить число X.

Как работает программа

1. Пользователь вводит с клавиатуры число n — размер вектора, который
    надо заполнять.
2. Пользователь вводит n целых чисел, которые заполняют вектор.
3. Пользователь вводит значение — X. X — удаляемое из вектора значение. Необходимо удалить из вектора все элементы, которые равны заданному значению.
4. В конце программы необходимо вывести итоговое состояние вектора.
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    int vectorSize;
    int numToDel;

    cout << "Input vector size: ";
    cin >> vectorSize;

    vector<int> numbers(vectorSize);

    cout << "Input numbers: ";
    for (int i = 0; i < vectorSize; i++)
    {
        cin >> numbers[i];
    }

    cout << "Input number to delete: ";
    cin >> numToDel;

    for (int i = vectorSize; i >= 0; i--)
    {
        if (numbers[i] == numToDel)
        {
            for (int j = i; j < vectorSize - 1; j++)
                numbers[j] = numbers[j + 1];
            numbers.pop_back();
        }
    }
    cout << "Result: ";
    printVector(numbers);

    return 0;
}
