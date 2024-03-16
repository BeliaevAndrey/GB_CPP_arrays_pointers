/*
Задача 3

Что нужно сделать:
Написать функцию, которая принимает указатель на char, по которому лежит строка. Функция должна возвращать true, если вторая строка является подстрокой первой.

Пример:

const char* a = "Hello world";
const char* b = "wor";
const char* c = "banana";
std::cout << substr(a,b) << " " << substr(a,c);
    // true false
*/

#include <iostream>

int main()
{
    bool issubstr(const char *, const char *);

    const char *a = "Hello world";
    const char *b = "wor";
    const char *c = "banana";

    const char *d = "Hello";
    const char *e = "Hello, ";

    std::cout << (issubstr(a, b) ? "true" : "false") << " " << std::endl;
    std::cout << (issubstr(a, c) ? "true" : "false") << " " << std::endl;

    std::cout << (issubstr(a, d) ? "true" : "false") << " " << std::endl;
    std::cout << (issubstr(a, e) ? "true" : "false") << " " << std::endl;
}

bool issubstr(const char *l, const char *r)
{
    int i = 0, j = 0;

    while (*(l + j) != '\0')
    {
        if (*(r + i) != *(l + j))
            j++;
        else
        {
            while (*(r + i) != '\0' && *(l + j) != '\0')
            {
                if (*(r + i) == *(l + j))
                {
                    i++;
                    j++;
                }
                else
                    return false;
            }
        }
    }
    return i > 1;
}
