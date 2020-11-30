#include <iostream>
#include <time.h> // Для srand

using namespace std;
const int N = 5,M = 5; // Размер матрицы
//const int N, M; // Размер матрицы


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


/** Вычисляем порядковый номер первого столбца соделжащего нулевой элемент */
void one(int mas[N][M])
{
    int result(M+1);
    for (int i(0); i < N; i++)
    {
        for (int j(0); j < M; j++)
        {
            if (mas[i][j] == 0){
                if(j<result){
                    result=j;
                }
            }
        }
    }
    if(result<M+1)
    {
        cout << "Номер первого столбца содержащего нулевой элемент: " << result+1 << endl;
    }else {
        cout << "Нулевой элемент в массиве не найден\n";
    }
}


/** Главная функция для запуска программы */
int main()
{
//    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int mas[N][M];
    random(mas);
    out(mas);
    one(mas);

//    system("pause>NUL");
    return 0;
}