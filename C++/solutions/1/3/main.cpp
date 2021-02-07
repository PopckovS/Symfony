#include <iostream>

using namespace std;

struct Custom
{
    int id;
    bool flag;
    char name[10];
};


void example()
{
    int a = 5;
    int b = 7;

    cout << "Примеры простых ссылок и разименований" << endl;
    cout << a << endl;
    cout << &a << endl;
    cout << *&a << endl;

}

void showStructureCustom(Custom custom)
{
    cout << "id = " << custom.id << endl;
    cout << "flag = " << custom.flag << endl;
    cout << "name = " << custom.name << endl;
}

void showStructureCustom2(Custom *custom)
{
    cout << "id = " << (*custom).id << endl;
    cout << "flag = " << (*custom).flag << endl;
    cout << "name = " << (*custom).name << endl;
}

void showStructurePointerCustom(Custom *custom)
{
    cout << "id = " << custom->id << endl;
    cout << "flag = " << custom->flag << endl;
    cout << "name = " << custom->name << endl;
}

void structUse1()
{
    cout << "1)  Пример использования структур" << endl;
    Custom var1 = {1, true, "jo"};
    showStructureCustom(var1);
}

void structUse2()
{
    cout << "2)  Пример использования Указателей на структурах" << endl;
    Custom var2 = {2, false, "qwerty" };
    Custom *pointer;

    pointer = &var2;
    showStructureCustom2(pointer);
}

void structUse3()
{
    cout << "3)  Пример использования Указателей на структурах" << endl;
    Custom var3 = {3, true, "asd" };
    Custom *pointer;

    pointer = &var3;
    showStructurePointerCustom(pointer);
}

int main()
{
    example();
    structUse1();
    structUse2();
    structUse3();

    return 0;
}