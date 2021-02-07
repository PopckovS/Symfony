
# Вопросы для обсуждения:
1) Как в Postgres делается DCL доступ прав к сущьн в БД ?
2) Как посмотреть описание Таблицы в Бд ?


# Cisco AnyConnect Secure Mobility Client
Это компания которая предоставляет в пользование VPN сервера,то шифруют настоящий IP.
Есть сайт https://2ip.ru/ На нем можно посмотреть данные о компьютере.
Если адрес типа: 185.144.62.20 Значит нету VPN.
Если адрес типа: 95-28-277-27.broadbands.corbina.ru значит VPN скорее всего есть.
При соединении надо указыавть к какому Серверу подключчаемся, также группу, логин и пароль.



# Postgres
####Посмотреть текущую установленную версию postgres
    psql --version



# Устанавливаем DBeaver и Postgres(Есть 10.14 и 12.14 Версии)
При помощи DBeaver можно создавать подключения к Бд как на своем пк так и к удаленным серверам.
Для работы с проектом выкачаем его Бд к себе на локальную машину, это можно сдделать через DBeaver.
####Создаем новое подключение к Postgres в DBeaver указываем:
1) хост   = 10.48.16.170
2) порт   = 5432
3) логин  = portal
4) пароль = portalpwd

Соединяемся и выкачиваем их БД, выбираем БД tools -> backup при этом можно увидеть ошибку
Native client ... выбираем client... получаем окно "Configure local client for postgres"
и указываем его Native client который ведет к исполняемому файлу postgres "/usr/bin" в котором
и лежат бинарные файлы.

Выбираем табл которые будут экспортированы, выбираем формат для экспорта Custom/Plain/tar/Directory
и скачиваем о туда все таблицы.

При этом если версия pg_dump на нашем пк и на сервере не соответствуют друг другу, то можно словить
ошибку экспорта БД, к примеру 12.14 == 10.14 версии не совместимы.




# Напоминание GIT
####Скачать проект с ветки dev на свой локальный ПК:
    git clone link -b dev
####Посмотреть на какой веткке находится проект сейчас
    git branch
####Все ветки посмотреть
    git branch -a



# Запускаем Symfony
И так, мы закачали себе проект на Symfony.
В папке .env находится список параметров для работы приложения.
Тут описаны конфигурационные параметры для работы некотрых Бандлов.

###Bandle / Бандл 
    Это php класс + настройка, что делает этот класс Сервисом в фреймворке Symfony. 

### Так выглядит подключение через Bandle Doctrine:
    DATABASE_URL=pgsql://user:password@host(IP):port/BD_name
   
Соединение может быть с какой угодно СУБД в данном случае с Postgres, 
это указывается в первом параметре, в даном случае pgsql:// - Соединение с Postgres.
Указываем параметры и соединяемся, что с локальным ПК, что с удаленным сервером.

### Кэширование и Логи
Кэш и логи находятся в директории var, которая содержит в себе:
1) #####cache/dev 
    Кэш для режима работы разработчика.
2) #####log/dev.deprecations.log 
    Лог файлов в которых содерж информ об устаревании текущ кода в будущихверсиях. 
3) #####dev.log 
    Лог файлов, как для информации так и для критич ошибок, для всего вобщем.


###Сборка NPM
Начинаем работу, у нас есть множество файлов css и js, то для их оптимизиции(сборки)
потребуется использовать Node.JS сервер, у которого есть такие инструменты как:
1) npm
2) yarn
####Узнать версию npm:
    npm -v
###Запускам установку npm в проект
    npm install
####Запустить сборку JS и CSS проекта:
    npm run build
В результате у нас будут сгенерированы файлы js и css и мы получи уведомление такого типа:

<nav style="background: #002c56">
<spanv>
    <span style="font-size: large">
        <span style="color: #935b38">1263</span>
        <span style="color: white">files written to </span>
        <span style="color: #935b38">public/build/basic</span>
    </span>
</spanv>

<p style="font-size: large; color: white"> 
    Child basic:
</p>

<p style="font-size: large">
    <span style="color: white">Entrypoint basic-js</span>
    <span style="color: #d5c315">[big]</span>
    <span>=</span>
    <span style="color: green">runtime.c2f0415a.js basic-js.a2d7db8c.js</span>
</p>

<p style="font-size: large">
<span style="color: white">Entrypoint basic-style</span>
<span style="color: #d5c315">[big]</span>
<span>=</span>
<span style="color: green">runtime.c2f0415a.js basic-style.9ffc8109.css basic-style.66c9b389.js</span>
</p>

<p style="font-size: large">
<span style="color: white">Entrypoint _tmp_copy =</span>
<span style="color: green">runtime.c2f0415a.js</span>
</p>
</nav>

Это означает что npm собрал для нас 4 документа и один манифест:
1) JS файл для Скриптов  - <span style="color: green">basic-js.a2d7db8c.js</span>
2) JS файл для Стилей    - <span style="color: green">basic-style.66c9b389.js</span>
3) CSS файл для Стилей   - <span style="color: green">basic-style.9ffc8109.css</span>
4) И один временный файл - <span style="color: green">runtime.c2f0415a.js</span>

Все эти документы автоматически сохраняются в директории 
<span style="font-size: large; color:yellow">public/build/basic</span>

В папке <span style="font-size: large; color:yellow">public/build/basic</span> хранятся:
1) <span style="font-size: large; color:yellow">fonts/</span> - Шрифты.
2) <span style="font-size: large; color:yellow">images/</span> - Картинки.
3) <span style="font-size: large; color:yellow">Остальные файлы</span>:
    1) Временные JS и CSS файлы сгенерированные при помощи npm.
    3) <span style="font-size: large; color:yellow">manifest.json</span> - временные пути картинок и их реалный пути.
    2) <span style="font-size: large; color:yellow">entrypoints.json</span> - 
    JSON массив с путями к сгенерированым JS и CSS файлам.
       
Все после этого проект собран и его можно запускать.

###Запуск Сервера:
Можно запускать проект как Apache2 или Nginx. А можно использовать сервер самого 
Symfony.

Установка через Composer сервера для Symfony:

    composer require server --dev
Запуск сервера: 

    php bin/console server:start

В папке <span style="color:yellow">bin</span> находится 2 php файла:
1) console - Точка входа для терминальных команд.
2) phpunit - Для запуска тестов.







