##API Platform урок Первый.

https://habr.com/ru/sandbox/78803/

Это Бандл, что представляет из себя API для CRUD операций по отношению 
к Сущьностям,озволяя тем самым автоматизировать процесс CRUD операций.

Установка:

    symfony composer req api

Файл настроек создан в:
    
    config/packages/api_platform.yaml

В нем будут указаны базовые настройи, прмерно следующего формата:

    api_platform:
        mapping:
            paths: ['%kernel.project_dir%/src/Entity']
        patch_formats:
            json: ['application/merge-patch+json']
        swagger:
            versions: [3]

Api platform работает со swagger, также тут надо указывать путь к директории
в которой хранятся наши сущьности `paths: ['%kernel.project_dir%/src/Entity']`

Поддерживается веб-стандарты JSON для связанных данных (JSON-LD).

###JSON-LD (Linked Data) - Это расширение для формата JSON внедренное от W3C.

Linked Data это коллекция взаимосвязанных наборов данных. 4 Базовых принцыпа:

1) Использование URL для именования сущьностей.
2) Использовать HTTP URI чтобы эти сущьности могли находить.
3) Когда кто-то ищет этот URI. предоставлять полезную информацию надо  
   используя стандарты `RDF*` и `SPARQL`
4) Включать ссылки надругие URI чтобы включать больше сущьностей.

###Api platform работате с сущьностью через аннотации.
С начала создадим эту сущьность, назовем ее Task и опишим ей ряд полей,
импортируем классы для работы с api platform:

1) Класс `ApiResource` для указания что эта суьность будет использована как
поставщик данных для работы API системы:


    use ApiPlatform\Core\Annotation\ApiResource;

2) Класс `ApiFilter` для использования ыильтров в api platform


    use ApiPlatform\Core\Annotation\ApiFilter;  

3) Для каждого вида фильтров используется свой класс,аждый из которых
следует импортировать отдельно:


    use ApiPlatform\Core\Bridge\Doctrine\Orm\Filter\SearchFilter;
    use ApiPlatform\Core\Bridge\Doctrine\Orm\Filter\DateFilter;


По мимо все этого у Symfony есть свой сериалайзер, который может создавать 
группы и назначать эти группы для полей сущьности, он может работать самос-но
но api platform использует его для указания какие из полей сущьности 
будут выбраны для конкретно группы, импортирем его:

    use Symfony\Component\Serializer\Annotation\Groups;

###Пропишим аннотации для класса.

1) Класс репозиторий, это сервис предоставляющий обертку над сущьностью, он
не свзяан с api platform.


    @ORM\Entity(repositoryClass=TaskRepository::class)

2) При помощи `normalizationContext` указываем группу, в данном случае это
`task` также указываем атрибуты, где атрибут `order` устанавливает по какому
полю и в каком порядке сортировать выборку данных, в данном случае сортировка 
происходит по полю `planned_finished_at` сортировкой вобратном порядке `DESC`.
Параметр `pagination_enabled` указывает пагинацию если она нужна.


    @ApiResource(
         normalizationContext={
                      "groups"={"task"}},
                      attributes={"order"={"planned_finished_at": "DESC"},
         "pagination_enabled"=false}
         )

3) Установка Фильтра для выборки по полю имеющему тип `datetime`


    @ApiFilter(DateFilter::class, properties={"planned_finished_at"})

4) Фильтр для выборки данных по различным полям. `properties` указывает
по каким полям как надо искать данные в сущьности, есть несколько параметров
`exact` это параметр указывающий что искать следует в полном строгом 
соответствии с переданным параметром.

    @ApiFilter(
              SearchFilter::class,
              properties={
                    "id":"exact", 
                    "title":"exact", 
                    "content":"exact"
                    }
          )

5) Фильтр по Дате


    @ApiFilter(DateFilter::class, properties={"planned_finished_at"})

###Теперь посмотрим на поля сущьности.
Мы импортировали класс `use Doctrine\ORM\Mapping as ORM` для того чтобы
доктрина определяла для себя чем являеются поля сущьности,и и как с ними 
надо работать.

Уникальный ID для таблицы

    @ORM\Id

Поле автоинкрементированное

    @ORM\GeneratedValue

Поле имеет тип данных `integer`

    @ORM\Column(type="integer")

Группа для сериалайзера, api platform тоже использует эту группу,
для понимания какий из полей выбирать при поиске.

    @Groups({"task"})
    
Тип данных строка, 255 символом максимум, может быть `NULL`

    @ORM\Column(type="string", length=255, nullable=true)    
    
Тип данных поля Дата и время:
    
    @ORM\Column(type="datetime", nullable=true)    

Поле $id


        /**
         * @ORM\Id  
         * @ORM\GeneratedValue
         * @ORM\Column(type="integer")
         * @Groups({"task"})
         */
        private $id;

Поле $title


       /**
         * @ORM\Column(type="string", length=255, nullable=true)
         * @Groups({"task"})
         */
        private $title;


Поле $content

    
     /**
         * @ORM\Column(type="text", nullable=true)
         * @Groups({"task"})
         */
        private $content;
        
Поле $planned_finished_at


        /**
         * @ORM\Column(type="datetime", nullable=true)
         * @Groups({"task"})
         */
        private $planned_finished_at;









