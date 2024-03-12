/**
Задание 1. Многоквартирный дом
Что нужно сделать:
На вход программе поступают десять фамилий в формате строк. Это фамилии
жильцов квартир с первой по десятую. Необходимо прочитать эти фамилии и
записать в одномерный массив. Далее пользователь вводит три номера
квартир. Необходимо вывести в консоль фамилию жильца, проживающего в
этой квартире. Если пользователь введёт некорректный номер квартиры,
необходимо сообщить ему об этом.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numberOfCitizens = 10, numberOfApt = 3, aptNumber;
    string citizens[numberOfCitizens];

    for (int i = 0; i < numberOfCitizens; i++)
    {
        cout << "Input surname of citizen from apt #" << i + 1 << ": ";
        cin >> citizens[i];
    }

    for (int i = 0; i < numberOfApt; i++)
    {
        cout << "Input number of apartment: ";
        cin >> aptNumber;
        if (aptNumber < 1 || aptNumber > numberOfCitizens)
        {
            cout << "Incorrect apartment number" << endl;
        }
        else
        {
            cout << citizens[aptNumber - 1] << endl;
        }
    }

    return 0;
}