#include <iostream> // Для работы с терминалом
#include <time.h>   // Для функции srand

/** Пространства имен */
using namespace std;

/** Начальная размерность массива */
const int N = 10,M = 10; // Размер матрицы


/** Вывод на экран массива */
void out(int mas[N][M])
{
    for (int i(0); i<N; i++)
    {
        for (int j(0); j<M; j++)
        {
            if(mas[i][j]>=0){
                cout << " " << mas[i][j]<< "  ";
            }else{
                cout << mas[i][j] << "  ";
            }
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
    if(result<(M+1))
    {
        cout << "Номер первого столбца содержащего нулевой элемент: " << result+1 << endl;
    }else {
        cout << "Нулевой элемент в массиве не найден\n";
    }
}


/** Сортируем матрицу по убыванию эллементов столбцов */
void BubbleSort(int mas[N][M])
{
    int temp;

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
    }
}

void testingMatrix()
{
    const int N =10, M=10;
    int mas[N][M];
    bool verdict = true;
    int testMax = 10;
    int test;

    int cicle = 0;

    for (int m = 0; m < testMax; ++m)
    {
        random(mas);
        BubbleSort(mas);
        out(mas);
        verdict = true;

        for (int i = 0; i < M; ++i)
        {
            test = mas[0][i];
            for (int j = 0; j < N; ++j)
            {
                cicle++;
                if (test < mas[i][j]) {
                    verdict = false;
//                    break;
                }else{
                    verdict = true;
                }
            }
        }

        if (verdict){
            cout << "Успех в попытке №" << m << endl;
        }else{
            cout << "Провал в попытке №" << m << endl;
        }
        cout << "cicle = " << cicle << endl;
    }
}


/** Главная функция для запуска программы */
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int mas[N][M];
    random(mas);
    cout << "Выводим матрицу" << endl;
    out(mas);
    one(mas);
    BubbleSort(mas);
    cout << "Выводим отсортированную по столбцам матрицу" << endl;
    out(mas);

    testingMatrix();


    return 0;
}