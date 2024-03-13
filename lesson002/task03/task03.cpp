/*
Задача 3
Что нужно сделать
Вам дали задание разработать хранилище для целочисленных значений во
встраиваемой операционной системе. Такие системы работают в большей части
техники, которая нас окружает: автомобилях, стиральных машинах, микроволновках,
холодильниках. Только вот незадача: объём памяти этой системы очень небольшой,
поэтому в хранилище не может находиться более 20 элементов. В хранилище,
являющееся вектором, с клавиатуры приходят целочисленные значения и помещаются
один за другим. При вводе «−1» с клавиатуры необходимо вывести всё содержимое
хранилища (20 или менее элементов). При выводе элементы должны быть в том
порядке, в котором они добавлялись. Попробуйте написать максимально
оптимизированное решение этой задачи, чтобы совершалось как можно меньше
расширений и перемещений элементов внутри вектора.
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec, int start, int occupied)
{
    if (occupied >= vec.size())
        for (int i = start; i < vec.size(); i++)
            cout << vec[i] << " ";

    for (int i = 0; i < start; i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    const int bufSize = 20;
    vector<int> storage(bufSize);

    int value;
    int index = 0;
    int occupied = 0;

    while (value != -100)
    {
        cout << "Input number: ";
        cin >> value;
        if (value == -1)
        {
            printVector(storage, index, occupied);
            cout << "capacity: " << storage.capacity()
                 << " size: " << storage.size() << endl;
        }
        else
        {
            if (index < bufSize)
            {
                storage[index] = value;
                index++;
                occupied++;
            }
            else
            {
                storage[0] = value;
                index = 1;
                occupied = bufSize;
            }
        }
    }

    return 0;
}