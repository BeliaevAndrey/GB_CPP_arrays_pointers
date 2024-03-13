/*
Задача 2
Что нужно сделать
С помощью списка инициализации задаётся вектор цен на продукты (дробными
числами). Таким же образом с помощью списка инициализации задаётся вектор
покупок (в виде индексов), которые совершает человек. Необходимо вывести на
экран итоговую стоимость покупок. Вектор цен и вектор покупок можно задать
напрямую в коде.
*/

#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

int main()
{
    vector<float> prices{2.5, 4.25, 3.0, 10.0};
    vector<int> items{1, 1, 0, 3};
    float total = 0;

    for (int i = 0; i < items.size(); i++)
        total += prices[items[i]];

        printf("Total cost is: %.2f.\n", total);
}