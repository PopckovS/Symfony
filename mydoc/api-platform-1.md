##API Platform. https://habr.com/ru/sandbox/78803/

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

###Визуальное представление Linked Data это граф.
<img src="https://habrastorage.org/files/ef7/a2e/3b8/ef7a2e3b8b09421ab0cdd4ab0302f703.png">









