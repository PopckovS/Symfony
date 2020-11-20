##Подготовка к запуску нового проекта.

Установим специальный установщик(installer) проектов для Symfony 

     wget https://get.symfony.com/cli/installer -O - | bash
     
Эта команда при помощи утилиты wget сделает HTTP запрос к сайту 
https://get.symfony.com/cli/installer и при получении ответа 200 OK начнет 
закачку в расширении [binary/octet-stream] что означает обычный бинарный файл.

В результате будет скачен и разархивирован архив с бинар файлом с сайта
https://github.com/symfony/cli/releases/download/v4.20.1/symfony_linux_amd64.gz 

И помещен в домашнию директорию пользователя по пути .symfony/bin/symfony.
Сообщение выглядит след образом:
    
    Uncompress binary...
    Making the binary executable...
    Installing the binary into your home directory...
    The binary was saved to: /home/serg/.symfony/bin/symfony
    
    The Symfony CLI v4.20.1 was installed successfully!
 
Таким образом мы получаем бинарный файл для установки приложений на Symfony.
Теперь нужно прописать пути к бинарному файлу, чтобы использовать его, есть 3 варианта:

    Use it as a local file:
    /home/serg/.symfony/bin/symfony

    Or add the following line to your shell configuration file:
    export PATH="$HOME/.symfony/bin:$PATH"

    Or install it globally on your system:
    mv /home/serg/.symfony/bin/symfony /usr/local/bin/symfony
      
Используем 2-й вариант, введем след команду

    export PATH="$HOME/.symfony/bin:$PATH"
    
Введем команду symfony в терминал и получим описание возможностей данной утилиты.  
Введем команду:

    symfony check:requirements
    
Эта команда покажет, соответствует ли компьютер техническим требованиям.     
Эта команда покажет нам используемый нами php.ini файл
    
    > PHP is using the following php.ini file:
    /etc/php/7.4/cli/php.ini
    
И сообщение о готовности утилиты symffony для работы с проектами.
    
    [OK]                                         
    Your system is ready to run Symfony projects
     
Также получимм и предупреждение, о том что php может использоваться от разных 
php.ini в терминале и на веб сайте, и предостережение о соблюдении использования 
одной версии php везде.

    Note  The command console can use a different php.ini file
    ~~~~  than the one used by your web server.
          Please check that both the console and the web server
          are using the same PHP version and configuration.    
    
Теперь все установлено, и мы можем использовать утилиту symfony для создания 
проектов.

###Создание приложения при помощи илиты symfony

    Создать традиционного веб-приложения с названием SymfonyApplication
    symfony new --full SymfonyApplication    
    
    Создать проект для консольного приложения, microservice или API
    symfony new my_project_name    
    
    
###Создание приложения при помощи Composer    
    
    запустите для создания традиционного веб-приложения
    composer create-project symfony/website-skeleton my_project_name

    запустите, если разрабатываете консольное приложение, microservice или API
    composer create-project symfony/skeleton my_project_name    
    
При первом создании запус будет долгим, все послед создания будут быстрее, 
за счет кэша скачиваемых библиотек.     

Установка API

    composer require api

Удаление API

    composer remove api