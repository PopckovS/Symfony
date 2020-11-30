##Фиксированные и Динамические массивы в C++ 

Допустим нам надо создать 30 записей о студентах, это можно сделать 
создав 30 переенных типа.

    int testResultStudent1;
    int testResultStudent2;
    int testResultStudent3;
    // ...
    int testResultStudent30;
    
Создание массива с 30-ю записями типа int
    
    int testResult[30];

Квадратные скобки как указание что это массви, и число как указание 
его размерности. Указав размер массива мы создали `массив фиксированной длины`.
У фиксированного массива рего длинна известна во время компиляции, при
создании массива, компилятор выделит 30 целочисленных переменных.

Каждая из переменных называется элементом массвиа, доступ к ним 
осуществляется через нумерованные индексы.

      int array[5]; // массив из пяти чисел
      
      array[0] = 3; // индекс первого элемента - 0 (нулевой элемент)
      array[1] = 2;
      array[2] = 4;
      array[3] = 8;
      array[4] = 12; // индекс последнего элемента - 4 

Можно обьявлять массивы типа `double`

    double array[3]; // выделяем 3 переменные типа double
    
    array[0] = 3.5;
    array[1] = 2.4;
    array[2] = 3.4;


###Динамические Массивы
Длинну такого массива можно устанавливать в процессе выполнения программы.

Для работы с Динамическим массивом используется специальные формы операторов
`new[]` и `delete[]`.






