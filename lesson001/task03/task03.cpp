/*
Задание 3. Использование assert
Что нужно сделать:
Создайте в своей программе функцию
float travelTime(float distance, float speed). Она будет находить время
в пути и при этом использовать assert, чтобы отбросить нулевую и
отрицательную скорость. Вызовите эту функцию в main. Убедитесь, что
падение происходит за счёт assert.

Не забудьте подключить заголовочный файл cassert.
*/

#include <iostream>
#include <cassert>

using namespace std;

int main()
{

    float travelTime(float distance, float speed);
    float sqrtVal, distance, speed;
    cout << "1 Input value for distance: ";
    cin >> distance;
    cout << "2 Input value for speed: ";
    cin >> speed;
    cout << travelTime(distance, speed) << endl;

    return 0;
}

float travelTime(float distance, float speed)
{
    assert(speed > 0);
    return distance / speed;
}
