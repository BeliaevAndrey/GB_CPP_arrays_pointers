/*
Задание 4. Умножение матрицы на вектор
Реализуйте частный случай умножения матрицы на матрицу, а именно
умножение вектора на матрицу. Эта операция распространена в
компьютерной индустрии в целом и в компьютерной графике в частности,
поэтому это будет хорошим упражнением. Итак, у нас есть
четырёхкомпонентный вектор b, представленный с помощью массива, и
матрица a размером 4 × 4, представленная в виде двумерного массива. Их
произведением будет новый четырёхэлементный вектор c. Его компоненты
будут суммой произведений элемента вектора b на строку матрицы a. Индекс
столбца при этом равен индексу соответствующей компоненты вектора b,
который мы и рассчитываем. Все входные данные, матрица a и вектор b
вносятся из пользовательского ввода. Итоговый вектор c надо вывести в
консоль (std::cout). Тип данных элементов — всегда float. Желательно
реализовать этот алгоритм с помощью вложенного цикла на умножение
колонки.
*/

#include <iostream>

using namespace std;

int main()
{
    void printVector(float[]);
    void multiplyMatrix(float[][4], float[], float[]);
    void initMatrix(float matrix[][4]);
    void initVector(float[]);

    // float A[4][4] = { /* test data */
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {8, 7, 6, 5},
    //     {4, 3, 2, 1}};

    float A[4][4];
    // float vector[4] = {2, 2, 2, 2};  /* test multiplier */
    float vector[4];                 // multiplier
    float vectorC[4] = {0, 0, 0, 0}; // result

    initMatrix(A);
    initVector(vector);

    multiplyMatrix(A, vector, vectorC);
    printVector(vectorC);

    return 0;
}

void multiplyMatrix(float matrix[][4], float vector[4], float vectorC[4])
{
    void printVector(float[]);

    printVector(vectorC);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            vectorC[i] += matrix[i][j] * vector[j];
}

void initMatrix(float matrix[][4])
{
    cout << "Enter matrix: " << endl;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> matrix[i][j];
}

void initVector(float vector[4])
{
    cout << "Enter vector: " << endl;

    for (int i = 0; i < 4; i++)
        cin >> vector[i];
}

void printVector(float vector[4])
{
    for (int i = 0; i < 4; i++)
        cout << vector[i] << " ";
    cout << endl;
}