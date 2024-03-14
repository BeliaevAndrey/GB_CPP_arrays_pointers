/*
Задание 5. Пупырка
После посылки из Китая осталась спецплёнка для бережной перевозки груза
— пупырка. Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого
пузырька: он либо целый, либо нет, то есть true или false (тип массива —
bool). Для начала требуется реализовать отдельную функцию инициализации
пупырки начальным состоянием: полностью целая пупырка, все элементы
true. Программа заключается в последовательном лопании целых регионов
пузырьков. Перед каждым таким лопанием надо показывать пользователю
полностью всю плёнку: o — это целый пузырёк, x — лопнутый. Это тоже надо
выделить в отдельную функцию. Итак, как выглядит само лопание.
Пользователь вводит две координаты: начала региона и конца региона.
Процедура лопания пузырей должна быть реализована с помощью отдельной
функции, все аргументы должны проверяться на валидность, что они в в
рамках диапазона возможных значений, иначе должна быть выведена ошибка.
После лопания каждого пузыря, который не был ещё лопнут до того, в
консоль должно выводиться сообщение “Pop!”. Лопание должно продолжаться
до последнего пузырька. Как только вся пупырка потрачена, программа
заканчивает выполнение. Вы можете подсчитать окончание в самой функции
по отображению пузырьков плёнки, так как функция выполняется после
каждого лопания.
*/

#include <iostream>

using namespace std;

int main()
{
    void popRegion(bool[][12]);
    bool printWrapper(bool[][12]);
    void initWrapper(bool[][12]);

    bool wrapper[12][12];

    initWrapper(wrapper);
    printWrapper(wrapper);
    while (printWrapper(wrapper))
        popRegion(wrapper);

    cout << "Game over. All popped" << endl;
    return 0;
}

void initWrapper(bool wrapper[][12])
{
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            wrapper[i][j] = true;
}

void popRegion(bool wrapper[][12])
{
    int ulRow, ulCol, lrRow, lrCol;
    bool flag = false;

    while (!flag)
    {
        cout << "Input region coordinates\n"
             << "upper-left row: ";
        cin >> ulRow;
        cout << "upper-left col: ";
        cin >> ulCol;
        cout << "lower-right row: ";
        cin >> lrRow;
        cout << "lower-right col: ";
        cin >> lrCol;
        if (ulRow < lrRow && ulCol < lrCol)
            flag = true;
        else
            cout << "Invalid values, try again please" << endl
                 << endl;
    }

    ulRow = ulRow < 0 ? 0 : ulRow;
    ulCol = ulCol < 0 ? 0 : ulCol;
    lrRow = lrRow > 12 ? 12 : lrRow;
    lrCol = lrCol > 12 ? 12 : lrCol;

    for (int i = ulRow; i < lrRow; i++)
        for (int j = ulCol; j < lrCol; j++)
        {
            if (wrapper[i][j])
            {
                cout << "POP!" << endl;
                wrapper[i][j] = false;
            }
        }
}

bool printWrapper(bool wrapper[][12])
{
    int count = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (wrapper[i][j])
            {
                cout << 'o' << " ";
                count++;
            }
            else
                cout << 'x' << " ";
        }
        cout << endl;
    }
    return count > 0;
}
