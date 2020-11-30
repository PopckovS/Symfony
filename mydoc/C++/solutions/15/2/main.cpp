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

/** Задача №1
 * Дана целочисленная прямоугольная матрица. Определить номер первого из
 * столбцов, содержащих хотя бы один нулевой элемент.
 */

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


///** Сортируем матрицу по убыванию эллементов столбцов */
//void BubbleSort(int mas[N][M])
//{
//    int temp;
//    int i,j;
//
//    for(int k = 0; k<N; k++)
//    {
//        for(i=0;i<M;i++)
//        {
//            for(j=0; j<(M-1); j++)
//            {
//                if(mas[k][j]<mas[k][j+1]){
//                    temp = mas[k][j];
//                    mas[k][j] = mas[k][j+1];
//                    mas[k][j+1] = temp;
//                };
//
////                if(mas[j][k]<mas[j][k+1]){
////                    temp = mas[j][k];
////                    mas[j][k] = mas[j][k+1];
////                    mas[j][k+1] = temp;
////                };
//            };
//        };
//    };
//
//    cout << "Выводим отсортированную матрицу" << endl;
//    out(mas);
//}




/** Сортируем матрицу по убыванию эллементов столбцов */
void BubbleSort(int mas[N][M])
{
    int temp;
    int i,j;

    for(int k = 0; k<N; k++)
    {
        for(i=0;i<M;i++)
        {
            for(j=0; j<(M-1); j++)
            {
                if(mas[j][k] < mas[j+1][k])
                {
                    temp = mas[j+1][k];
                    mas[j][k] = mas[j+1][k];
                    mas[j+1][k] = temp;
                };
//                if(mas[k][j]<mas[k][j+1])
//                {
//                    temp = mas[k][j];
//                    mas[k][j] = mas[k][j+1];
//                    mas[k][j+1] = temp;
//                };
            };
        };
    };

    cout << "Выводим отсортированную матрицу" << endl;
    out(mas);
}



/** Главная функция для запуска программы */
int main()
{
//    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int mas[N][M];
    random(mas);
    out(mas);
//    one(mas);
//    BubbleSort(mas);
    BubbleSort(mas);
//    system("pause>NUL");
    return 0;
}