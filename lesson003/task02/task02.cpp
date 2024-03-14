/*
Задание 2. Крестики-нолики
Что нужно сделать
Старая добрая игра на страницах всех школьных тетрадей. Поле размером 3
× 3 представлено в виде двумерного массива с типом элементов char.
Участвуют два игрока, они ходят по очереди и ставят в указанные ими в
стандартном вводе координаты свой символ — X или O (буквы латинского
алфавита). Как только у одного из игроков будет установлено подряд три
крестика или три нолика, он побеждает. Если свободных клеток не
осталось, а трёх совпадающих элементов не найдено, то объявляется ничья.
Для простоты не будем рассматривать диагональные совпадения — только
строго вертикальные и строго горизонтальные. Изначально всё поле
инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки
одинарные и в одну сторону). Это можно сделать сразу при объявлении либо
с помощью вложенного цикла. На каждом ходе при занятой клетке или при
неверных координатах этой клетки должно быть выведено сообщение, и игрок
должен указать координаты клетки повторно. После каждого хода надо
выводить в консоль текущее состояние всего игрового поля для наглядности.
*/

#include <iostream>

using namespace std;

int main()
{
    bool winner = false;
    void printBoard(char[][3]);
    bool checkWin(char[][3], char);
    void move(char[][3], char);
    char mark = '0';
    int countMoves = 0;

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    printBoard(board);

    do
    {
        mark = mark == 'X' ? '0' : 'X';
        move(board, mark);
        countMoves++;
        printBoard(board);
        winner = checkWin(board, mark);

    } while (!winner && countMoves < 9);

    if (winner)
        cout << mark << " WINS!" << endl;
    else
        cout << "Draw!" << endl;

    return 0;
}

void move(char board[][3], char mark)
{
    bool flag = false;
    do
    {
        int row = 0, col = 0;
        cout << "Enter the coordinates (row col; 1 - 3): ";
        while (row > 3 || row < 1)
        {
            cin >> row;
            if (row > 3 || row < 1)
                cout << "invalid value, try again, please" << endl;
        }

        while (col > 3 || col < 1)
        {
            cin >> col;
            if (col > 3 || col < 1)
                cout << "invalid value, try again, please" << endl;
        }
        if (board[row - 1][col - 1] == ' ')
        {
            board[row - 1][col - 1] = mark;
            flag = true;
        }
        else
            cout << "Position occupied, once again, please" << endl;
    } while (!flag);
}

bool checkWin(char board[][3], char mark)
{
    int count = 0;
    // rows
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (board[i][j] == mark)
            {
                count++;
                if (count == 3)
                    return true;
            }
        count = 0;
    }

    // cols
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
            if (board[i][j] == mark)
            {
                count++;
                if (count == 3)
                    return true;
            }
        count = 0;
    }

    return false;
}

void printBoard(char board[][3])
{
    cout << endl
         << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "|";
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " |";
        }
        cout << endl
             << "-------------" << endl;
    }
}