#include <iostream>
using namespace std;

/** Задача №1
 * Дана целочисленная прямоугольная матрица.
 * Расположить по убыванию элементы столбцов.
 */

#include <iostream>
#include <time.h> // Для srand

using namespace std;
const int N = 4, M = 4;

/** Вывод на экран массива */
void out(int mas[N][M])
{
    for (int i(0); i<N; i++)
    {
        for (int j(0); j<M; j++)
        {
            if(mas[i][j]>=0)cout << " " << mas[i][j]<< "  ";
            else cout << mas[i][j] << "  ";
        }
        cout << endl;
    }
}


/** Заполнение массива ранд числами в диапазоне -5 до 5 */
void random(int mas[N][M])
{
    for (int i(0); i<N; i++)
        for (int j(0); j<M; j++)
            mas[i][j] = rand()%10+(-5);
}


/** Сортируем матрицу по убыванию эллементов столбцов */
void BubbleSort(int mas[N][M])
{
    int temp;
//    int i,j;
    int r=0, s=0;

    cout << "==============================" << endl;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int m=0; m<(M-1); m++)
            {
                if(mas[m][i] < mas[m+1][i])
                {
                    temp = mas[m][i];
                    mas[m][i] = mas[m+1][i];
                    mas[m+1][i] = temp;
                }
            }
        }
        cout << "======" << endl;
    }


    cout << "Выводим отсортированную матрицу" << endl;
    out(mas);
}



/** Главная функция для запуска программы */
int main()
{
    srand(time(NULL));

    int mas[N][M];
    random(mas);
    out(mas);

    BubbleSort(mas);

    return 0;
}