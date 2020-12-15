#include <iostream>

using namespace std;

/**
 * Лесенкой называется набор кубиков, в котором каждый более верхний
 * слой содержит кубиков меньше, чем предыдущий. Требуется написать программу,
 * вычисляющую число лесенок, которое можно построить из N кубиков.
 * */

int inputInt()
{
    int input = 10;

    cout << "Введит количество кубиков = ";
    cin >> input;

    return input;
}


int cicle(int input)
{
    int counter=1, result=0;
    int min=1, max=1;

    while (counter <= input)
    {
        cout << " " << counter << " ";
        counter++;

        if(min == max)
        {
            result++;
            min=0;
            max++;
            cout << "" << endl;
        }
        min++;
    }

    return result;
}

int main()
{
    int input, result;
    input = inputInt();
    result = cicle(input);

    cout << endl << "Ответ: "<< result << endl;

    return 0;
}



