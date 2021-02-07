#include "stdio.h"
#include "locale.h"
#include <iostream>

#include <cstring>
#include <typeinfo>

using namespace std;


/**Структура для формирования списка*/
struct Ticket
{
    char ticket_date[20];   //Дата концерта
    char ticket_name[20];   //Название исполнителя
    int  ticket_number; //Количество проданных билетов
    Ticket *prev;     //Указатель на предыдущий элемент
    Ticket *next;     //Указатель на последующий элемент
};

/** Указатели на начало и конец списка */
Ticket *ticket_first;
Ticket *ticket_end;


/** Обьявление прототипов используемых функций для интерфейса */
void menu();
void vvod();
void vivod();
void search();
void del();

/** Прототипы функций для работы со списками */
Ticket* list_first(char* ticket_date, char* ticket_name, int ticket_number);


/** Главная функция программы */
//int main(int argc, char* argv[])
int main()
{
    setlocale(LC_ALL,"");

    // Инициализация указателя на последний элемент списка
    ticket_first = 0;
    ticket_end = 0;

    // Выбранный пункт меню
    int num=0;

    //Цикл обработки действий пользователя
    while (num!=5)
    {
        menu();
        cin>>num;
        switch(num){
            case 1: vvod(); break;
            case 2: vivod(); break;
            case 3: search(); break;
            case 4: del(); break;
            case 5: break;
            default: cout<<"Неверный вариант выбора";
        }
    }
    return 0;
}


/** Функция прорисовки меню */
void menu()
{
    cout<<"\n МЕНЮ \n";
    cout<<"1. Ввод данных\n";
    cout<<"2. Вывод данных\n";
    cout<<"3. Поиск\n";
    cout<<"4. Удаление\n";
    cout<<"5. Выход\n";
    cout<<"\nВведите номер пункта меню для дальнейшей работы\n";
}


/** Ввод данных пользователем */
void vvod()
{
    int number;
    char ticket_date[20];
    char ticket_name[20];
    int  ticket_number;

    cout<<"Введите кол-во добавляемых записей в список =";
    cin>>number;

    for (int i=0; i<number; i++)
    {
        cout<<"\nВведите дату концерта\n";
        cin>>ticket_date;

        cout<<"Введите название концерта\n";
//        cin.getline(ticket_name,20);
        cin>> ticket_name;
//        cout<< ticket_name;
//        cout<< typeid(ticket_name).name();

        cout<<"Введите количество билетов\n";
        cin>> ticket_number;

        if (ticket_first) {
//            add_sort(&pbeg, &pend, t_num, p_nazn, v_otpr);
        }else{//Если список пуст - формируется первый элемент списка
            ticket_first = list_first(ticket_date, ticket_name, ticket_number);
            ticket_end = ticket_first;
        }
    }
}

/** Вывод данных пользователю */
void vivod()
{
    if (ticket_first)
    {
        cout<<"=======* Список концертов *=======";
        cout<<"\n==================================\n";
        cout<<"Дата концерта(Ключ) | Название концерта  | Количество билетов\n";

        Ticket *pv = ticket_first;
        while (pv)
        {
//            printf("| %5s | %20s | %10d |\n", pv->ticket_date, pv->ticket_name, pv->ticket_number);
            printf(" %5s  %20s  %20d \n", pv->ticket_date, pv->ticket_name, pv->ticket_number);
            pv = pv->next;
        }
        cout<<"\n==================================\n";

//        Train *pv = ticket_first;
    }else { //Если список пуст - вывод сообщения
        cout << "\nСписок пуст!\n";
    }
}

/** Поиск записи в списке */
void search()
{
    cout<<"\n Поиск \n";
}


/** Удаляем элемент из списка */
void del()
{
    cout<<"\n Удаление \n";
}


/** ================ Далее функции для работы со списками ================== */

/** Функция формирования первого элемента списка */
Ticket* list_first(char* ticket_date, char* ticket_name, int ticket_number)
{
    Ticket *pv = new Ticket; //Создание нового элемента

    //Заполнение полей данных
    strcpy(pv->ticket_date, ticket_date);
    strcpy(pv->ticket_name, ticket_name);
//    strcpy(pv->ticket_number, ticket_number);
    pv->ticket_number = ticket_number;

    //Инициализация указателей на соседние элементы списка
    pv->prev = 0;
    pv->next = 0;
    return pv;
}






