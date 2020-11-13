##API Platform урок Второй.
Теперь когда api platform установлен и сущьность для него создана, когда
через аннотациии установлены все правила, теперь мы можем делать запросы
к нашей API Platform.

По стандарту API идет на путь `/api` по этому URL описана его документация
через swagger, и по этому пути будет идти обращение к нему.

Есть полный набор CRUD операций которые мы можем делать к API.
Все операции делятся на 2 группы:

1) collection operations — операции с коллекцией элементов;
2) item operations — операции с одним элементом данных.

`Collection operations` - Операции с коллекцией эллементов поддерживает 2
различных типа операций:

1) GET - получить список элементов;
2) POST - добавить элемент в коллекцию.

`Item operations` - Операции с конкретным эллементом поддерживает 4
типа операций:

1) GET - получить элемент по ID;
2) PUT - изменить элемент;
3) DELETE - удалить элемент из коллекции;
4) PATCH - частичное изменение элемента.

При необходимости можно ограничивать набор допустимых операций для Сущьности,
для этого опишим их в аннотации к сущьности:

    @ApiResource(
            collectionOperations={"get","post"},
            itemOperations={"get","delete"}
        )

`collectionOperations` - Указывает какие операции будут поддеражаны для
коллекции.

`itemOperations` - Указывает каки операции будут поддержаны для одного эллемента

После запуска сайта зайдем на страницу `http://127.0.0.1:8000/api` где путь `/api`
это стандартный путь, где видим как swagger описывает нам какие сущьности находятся
под контролем API.

Сущьность и доступные с ней действия.

Действия доступные для коллекции:

    GET  /api/tasks - Retrieves the collection of Task resources.
    POST /api/tasks - Creates a Task resource.

Здесь метод GET получает коллекцию сущьностей из БД по переданному запросу на 
путь `/api/tasks` И по этомуже путь можно сделать запрос типа POST для создания
ряда записей в БД.

Действия доступные для конкретной сущьности, по всему CRED:

    GET    /api/tasks/{id} - Retrieves a Task resource.
    DELETE /api/tasks/{id} - Removes the Task resource.
    PUT    /api/tasks/{id} - Replaces the Task resource.
    PATCH  /api/tasks/{id} - Updates the Task resource.

Сдесь же при помощи `Swagger UI` доступен просмотр и работа с запросами к API.

К примеру для поля `planned_finished_at` как для поля типа DateTime доступны 
4 вида запросов:
    
    planned_finished_at[before]           - Раньше
    planned_finished_at[strictly_before]  - Строго раньше
    planned_finished_at[after]            - Позже
    planned_finished_at[strictly_after]   - Строго позже

Примеры запросов:

1) GET запрос на получение всех записей из таблицы
   

    http://127.0.0.1:8000/api/tasks

2) POST запрос на создание записи в таблице, по переданным параметрам.


    http://127.0.0.1:8000/api/tasks

    {
        "title": "string",
        "content": "string",
        "plannedFinishedAt": "2020-11-13T12:34:15.396Z"
    }
В ответ получаем тело ответа:

    {
        "@context": "/api/contexts/Task",
        "@id": "/api/tasks/4",
        "@type": "Task",
        "id": 4,
        "title": "string",
        "content": "string",
        "planned_finished_at": "2020-11-13T12:34:15+03:00"
    }

3)GET запрсо получить запись по полю `planned_finished_at` выбрать все записи 
у которых срок раньше чем дата `2020-11-30`

    http://127.0.0.1:8000/api/tasks?planned_finished_at[before]=2020-11-30


4)GET запрос на получение конкретного дня, сожалению нет возможности сдеалть
это специальным конкретным методом, так что сделаем это зажав нужную дату
между двумя другими:

    
    http://127.0.0.1:8000/api/tasks?
        planned_finished_at[strictly_before]=2020-11-13&
        planned_finished_at[strictly_after]=2020-11-11

В результате получим дату `2020-11-12`
