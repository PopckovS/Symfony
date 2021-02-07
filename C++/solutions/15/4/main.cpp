#include "locale.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
using namespace std;

/** Лабораторная работа № 4
 *
 * Двумерные динамические массивы.
 *
 * Составить программу для работы с матрицей. Размер
 * матрицы задается пользователем. Заполнение матрицы
 * осуществляется с помощью генератора случайных чисел.
 *
 * Задача:
 * В целочисленной квадратной матрице найти, где
 * больше нечетных элементов – над или под главной диагональю.
 * */


int n,m;
int **array = new int *[n];

/** Создание массива */
void vvod()
{
    cout << "Введите количество строк матрицы\n";
    cin >> n;
    cout << "Введите количество столбцов матрицы\n";
    cin >> m;

    /** Выделение памяти под матрицу */
    for (int i=0; i<n; i++)
    {
        array[i] = new int[m];
    }
}


/** Вывод матрицы */
void out(int n, int m, int **array)
{
    for (int i(0); i<n; i++)
    {
        for (int j(0); j<m; j++)
        {
            if(array[i][j]>=0)cout << " " << array[i][j]<< "  ";
            else cout << array[i][j] << "  ";
        }
        cout << endl;
    }
}


/** Заполнение матрицы случайными числами */
void random(int n, int m, int **array)
{
    /** Инициализация генератора случайных чисел */
    srand(time(NULL));

    /** Задание диапазона генератора случайных числе */
    int dmin, dmax;
    cout<<"Введите нижний предел ГСЧ"<<"\n";
    cin>>dmin;
    cout<<"Введите верхний предел ГСЧ"<<"\n";
    cin>>dmax;

    /** Генерация */
    for (int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            array[i][j] = rand() % (dmax - dmin + 1) + dmin;
        }
    }
}


/** Вывод результата*/
void vivod(int n, int m, int **array)
{
    int over = 0;
    int under = 0;

    cout << "Вывод Результата" << endl;
    for (int i(0); i<n; i++)
    {
        for (int j(0); j<m; j++)
        {
            /** Вывод над диагонали */
            if(j > i)
            {
                if (array[i][j] % 2 != 0){
                    over++;
                }
            }

            /** Вывод под диагонали */
            if(j < i){
                if (array[i][j] % 2 != 0){
                    under++;
                }
            }
        }
    }

    cout << "Количество нечетных над диагональю = " << over << endl;
    cout << "Количество нечетных под диагональю = " << under << endl;
}


/** Запуск программы */
int main()
{
    setlocale(LC_CTYPE,"");

    /** Создание массива */
    vvod();

    /** Заполнение матрицы случайными числами */
    random(n, m, array);

    /** Вывод матрицы */
    out(n, m, array);

    /** Вывод результата*/
    vivod(n, m, array);

    return 0;
}








