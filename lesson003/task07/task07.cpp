/*
Задание 7. Почти «Майнкрафт» (дополнительное задание)
Нам предстоит сделать некое подобие «Майнкрафта». Миллионов не обещаю,
но это интересная задача на пространственное мышление. У нас есть
небольшой квадратный ландшафт, размером 5 × 5 секторов. В каждом
секторе располагается блок (столбик) ландшафта, максимальная высота
которого — 10 блоков. Текущая высота каждого такого блока задаётся
пользователем в начале программы. Итоговая задача: используя трёхмерный
массив, вывести в стандартный вывод горизонтальное сечение (или
горизонтальный срез) нашего небольшого мира. Сам мир как раз должен
быть представлен в виде трёхмерного массива. Его горизонтальный срез —
это двумерный массив, который надо отобразить в виде единиц и нулей. 0
— это отсутствие элемента на данном уровне в данной точке, 1 — элемент
есть. Уровень среза от 0 до 9 включительно также задаётся в стандартном
вводе.
*/

#include <iostream>

using namespace std;

int main()
{
    void initHeights(int[][5][10]);
    void printSlice(int[][5][10], int);
    int matrix[5][5][10];
    int level = -1;

    initHeights(matrix);
    do
    {
        cout << endl
             << "Input level (or '-1' to exit): ";
        cin >> level;
        if (level > 9)
        {
            cout << "Level is set to 9 (maximum)" << endl;
            level = 9;
        }
        if (level < -1)
        {
            cout << "Level is set to 0 (basement)"  << endl;
            level = 0;
        }
        printSlice(matrix, level);
    } while (level != -1);

    return 0;
}

void initHeights(int matrix[][5][10])
{
    int height;

    cout << "Input matrix of heights: " << endl;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            cin >> height;
            for (int k = 9; k >= 0; k--)
                matrix[i][j][k] = k < height ? 1 : 0;
        }
}

void printSlice(int matrix[][5][10], int level)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << matrix[i][j][level] << " ";
        cout << endl;
    }
}
