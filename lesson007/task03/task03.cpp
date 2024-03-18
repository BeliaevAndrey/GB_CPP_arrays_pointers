/*
Задача 3
Что нужно сделать:
Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную ans, а возвращает void. После завершения работы функции в переменной ans должно оказаться количество чётных цифр в записи числа n.
*/

#include <iostream>

int main()
{
    void countEvens(long long, int &);
    int ans = 0;
    countEvens(9223372036854775806, ans),
        std::cout << "ans: " << ans << std::endl;
}

void countEvens(long long number, int &ans)
{
    if (number == 0)
        return;
    if (!((number % 10) % 2))
    {
        ans++;
        countEvens(number / 10, ans);
    }
    else
        countEvens(number / 10, ans);
}