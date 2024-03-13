# Массивы и Указатели в C++
## Урок 2. Знакомство с std::vector v2

## Практическая работа

Цель практической работы:
* Научиться работать с типом std::vector.
* Попробовать на практике использовать функции для работы с vector.

## Задача 1

### Что нужно сделать
Необходимо из заданного пользователем вектора удалить число X.

Как работает программа
1. Пользователь вводит с клавиатуры число n — размер вектора, который надо заполнять.
2. Пользователь вводит n целых чисел, которые заполняют вектор.
3. Пользователь вводит значение — X. X — удаляемое из вектора значение. Необходимо удалить из вектора все элементы, которые равны заданному значению.
4. В конце программы необходимо вывести итоговое состояние вектора.

Пример выполнения
```
Input vector size: 5
Input numbers: 1 3 3 5 1
Input number to delete: 3
Result: 1 5 1
```

### Пояснение
Пользователь ввёл 5, потом числа 1, 3, 3, 5, 1 и потом число 3. В векторе должны остаться числа 1, 5, 1, которые надо вывести на экран.

Что оценивается
* Не удалено лишних элементов.
* Все элементы, которые необходимо удалить, удалены.
* Для удаления элементов из вектора использована функция pop_back()
* Удаления из вектора совершены in-place, т.е. при удалении из вектора не используются дополнительные структуры данных или переменные.
* Решение использует только один вектор.

## Задача 2

### Что нужно сделать
С помощью списка инициализации задаётся вектор цен на продукты (дробными
числами). Таким же образом с помощью списка инициализации задаётся вектор покупок (в виде
индексов), которые совершает человек. Необходимо вывести на экран итоговую стоимость 
покупок. Вектор цен и вектор покупок можно задать напрямую в коде.

Пример выполнения

```
// Вектор цен выглядит так: {2.5, 4.25, 3.0, 10.0}.
std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
// Вектор покупок: {1, 1, 0, 3}, то есть два товара по индексу 1 и по одному — индексов 0 и 3.
std::vector<int> items {1, 1, 0, 3};

Суммарная стоимость будет равна 21.0.
```

### Советы и рекомендации
При получении итоговой стоимости покупок не нужно делать циклы по обоим векторам, достаточно одного цикла.

Что оценивается
Программа не допускает выхода за границы вектора цен.

## Задача 3

### Что нужно сделать
Вам дали задание разработать хранилище для целочисленных значений во встраиваемой операционной системе. Такие системы работают в большей части техники, которая нас окружает: автомобилях, стиральных машинах, микроволновках, холодильниках. Только вот незадача: объём памяти этой системы очень небольшой, поэтому в хранилище не может находиться более 20 элементов.
В хранилище, являющееся вектором, с клавиатуры приходят целочисленные значения и помещаются один за другим.
При вводе «−1» с клавиатуры необходимо вывести всё содержимое хранилища (20 или менее элементов). При выводе элементы должны быть в том порядке, в котором они добавлялись.
Попробуйте написать максимально оптимизированное решение этой задачи, чтобы совершалось как можно меньше расширений и перемещений элементов внутри вектора.
Чтобы задать размера вектора равным 20, используйте:

```c++
std::vector<int> db(20);
// ^ Задаём размер вектора при создании
```

Пример выполнения:
```
input number: 1
input number: 2
input number: 3
…
input number: 19
input number: 20
input number: -1
output: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
input number: 21
input number: 22
input number: 23
input number: -1
output: 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
```

### Рекомендации по выполнению
Посмотрите, как работает кольцевой буфер. Этот алгоритм поможет быстрее найти решение.

### Что оценивается
* Размер вектора не превышает 20 элементов.
* Нет изменений в размере вектора (это выполняется, если вы выбрали верный алгоритм решения).

### Критерии оценки
* Выполнены все три задания.
* Программы запускаются и корректно работают, нет синтаксических ошибок.
* Имена переменных корректные, отражают суть хранимых данных.
* Создан текстовый интерфейс для всех программ.
* Для всех задач обеспечен контроль ввода.
* В циклах нет выхода за границы векторов.