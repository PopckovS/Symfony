/** Вариант №1
* Дана целочисленная прямоугольная матрица. Определить:
* 1) количество строк, не содержащих ни одного нулевого элемента;
* 2) максимальное из чисел, встречающихся в заданной матрице более одного раза.
*/

#include <iostream>
#include <time.h>

using namespace std;

/** !!! Повторить способы обьявления !!! */
/** Обьявляем прототипы для функций */
//void createRandomMatrix(int mass[N][M]);
//void finedNotZeroElement(int mass[N][M]);

const int N=5, M=5;


/** Генерирует рандомные значения и заполняет ими матрицу */
void createRandomMatrix(int mass[N][M])
{
    for (int i = 0; i <N ; ++i)
    {
        for (int j = 0; j <M ; ++j)
        {
            mass[i][j] = rand()%10+(-4);
        }
    }
}


/** Выводит матрицу на экран */
void showMatrix(int mass[N][M])
{
    for (int i = 0; i <N ; ++i)
    {
        for (int j = 0; j <M ; ++j)
        {
            cout << " " << mass[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


/** Ищет количество строк, не содержащих ни одного нулевого элемента; */
void finedNotZeroElement(int mass[N][M])
{
    int resultZero=0;

    for (int i = 0; i <N ; ++i)
    {
        for (int j = 0; j <M ; ++j)
        {
            if(mass[i][j] == 0)
            {
                resultZero++;
                cout << "Строка содержащая 0 число имеет индекс = " << i << endl;
                break;
            }
        }
    }

    if(resultZero == 0){
        cout << "Все строки матрицы содержат нулевые элементы" << endl;
    }else{
        cout << "Количество элементов содержащих 0 равно = " << resultZero << endl;
    }
}


/** Ищет максимальное из чисел, встречающихся в
 * заданной матрице более одного раза */
void finedMaxCounter(int mass[N][M])
{
    int max = mass[0][0];
    int maxTwice = 0;
    int counter = 0;

    for (int i = 0; i < N ; ++i)
    {
        for (int j = 0; j < M ; ++j)
        {
//            if(max <= mass[i][j]){
                if(max < mass[i][j]){
                    max = mass[i][j];
                    counter = 1;
                }else if(max == mass[i][j]){
                    counter = 2;
                    maxTwice = max;
                }
//            }
//            if (max == mass[i][j]){
//                counter++;
//                if(counter > 1){
//                    maxTwice = max;
//                }
//            if(max < mass[i][j]){
//                maxTwice = mass[i][j];
//            }
        }
    }

    cout << "Cамое большое число встречающееся более 1 раза = " << maxTwice << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int mass[N][M];

    createRandomMatrix(mass);
    showMatrix(mass);
    finedNotZeroElement(mass);
    finedMaxCounter(mass);

    return 0;
}





