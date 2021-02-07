//#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int sortirovka(int **mas1, int m, int n)
{
    int temp;
    // идем по столбцам - у нас их как раз столько, сколько элементов в строке
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if ((mas1[j][i] < mas1[k][i]) && (mas1[j][i] < 0) && (mas1[k][i] < 0))
                {
                    temp = mas1[k][i];
                    mas1[k][i] = mas1[j][i];
                    mas1[j][i] = temp;
                }
            }
        }
    }

    cout << "Sorted matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
//            cout << setw(3) << mas1[i][j] << setw(3);
            cout << setw(3) << mas1[i][j] << setw(3);
        }
        cout << endl;
    }

    return 0;
}





int main(void)
{
    int **mas; // указатель на указатель на массив
    int m, n; // количество строк и столбцов массива
    m = 3; n = 6;
    //cout << "Stroki i stolbci:" << endl;
    //cin >> m >> n; // ввод количества строк и столбцов
    mas = new int*[m]; // выделение памяти под массив указателей
    for (int i = 0; i < m; i++)
        mas[i] = new int[n];
    //cout << "Vvedite elementi v massiv:" << endl;

    mas[0][0] = -3; mas[0][1] =  6; mas[0][2] =  9; mas[0][3] = -11; mas[0][4] = -16; mas[0][5] = -19;
    mas[1][0] = -2; mas[1][1] = -5; mas[1][2] = -8; mas[1][3] = -12; mas[1][4] = -15; mas[1][5] = -18;
    mas[2][0] =  1; mas[2][1] = -4; mas[2][2] = -7; mas[2][3] = -13; mas[2][4] = -14; mas[2][5] = -17;

    //for (int i = 0; i < m; i++) {
    //  for (int j = 0; j < n; j++) {
    //      //mas[i][j] = rand() % 10;
    //      //cout <<  i <<  j ;
    //      while (!(cin >> mas[i][j]))
    //      {
    //          cin.clear();
    //          while (cin.get() != '\n');
    //          cout << "Nepravelna vvod. Povtoriti.\n";
    //          //  cout <<  i << j;
    //          //cout << "Введите количество строк: ";
    //      }
    //      //  cin >> mas[i][j];
    //  }
    //}

    /** Вывод первоначальной матрицы */
    cout << "Matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(3) << mas[i][j] << setw(4);
        cout << endl;
    }
    cout << endl;

    sortirovka(mas, m, n);

    delete[]mas;
    system("pause");
    return 0;
}