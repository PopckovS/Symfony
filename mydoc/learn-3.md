##Основы  

Все контроллеры, сущьности, и прочее определены в директории src.

Контроллеры находятся в src/Controller и должны иметь Название + Controller.
К примеру DefaultController, к примеру так:

    namespace App\Controller;
    
    use Symfony\Component\HttpFoundation\Response;
    
    class DefaultController
    {
        public function index()
        {
            return new Response('Hello!');
        }
    }
    
Контроллер - это обычная функция с одним правилом: она должна возвращать 
объект Symfony Response. Сам ответ уже может быть любым текст, JSON или Вид.

###Существует 2 способа создания роутов к контроллерам приложения.

#### 1 - Первый способ это прописывать роуты в файле конфигов по пути 
config/routes.yaml

#### 2 - Второй способ, установка бандлов 
Установка Аннотаций, для создания маршрутизации прямо в контроллере. 

     composer require annotations
    
Установив аннотации мы получили возможность прописывать маршруты прямо в 
аннотациях к методам контроллеров.

Этой строчкой подключаем пространство имен для использования класса Аннотаций. 

    use Symfony\Component\Routing\Annotation\Route;

Добавляем в метод контроллера аннотацию для роута, где /hello указывает первую
статичную часть URl. Второй параметр может бытьт чем угодно, и будет передан
в метод класса как аргумент с названием {name} с которым мы в контроллере можем
делать уже что угодно.

       /**
        * @Route("/hello/{name}")
        */
        public function index($name)
        {
            return new Response("Hello! $name" );
        }

Symfony Flex - это новый способ установки и управления приложениями Symfony. 
Данный пакет заменяет Symfony Installer и Symfony Standard Edition. 
Flex автоматизирует самые общие задачи - установку и удаление бандлов, 
а также других зависимостей Composer.

В файле `config/bundles.php` описаны ввсе подключаемые при помощи Flex бандлы.

Подключаем Шаблонизатор twig

    composer require twig

При его подключении к проекту, в файле `config/packages/twig.yaml` будут указаны настройки 
для Бандла управляющего твигом.

###config/packages/ - Директория для файлов с настройками Бандлов.

Также в проекте появится директория `templates/` в которой по умолчанию будут храниться шаблоны 
twig для работы  проекта, имеющие след названия `base.html.twig`

До этого мы создавали контроллер, и давали ему возможность формировать HTTP ответы  
при помощи используемого класса:

    use Symfony\Component\HttpFoundation\Response;

Класс Response мог формировать и возвращать на свой вызов HTTP ответы

    return new Response("Hello!");

Теперьже нам надо создать контроллер для управления страницей сайта, для этого 
расширим наш контроллер, абстрактным контроллером фреймворка Symfony след образом

    use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

    class LessonFirstController extends AbstractController

В результате получим контроллер следующего вида:

    namespace App\Controller;

    use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
    use Symfony\Component\Routing\Annotation\Route;

    class LessonFirstController extends AbstractController
    {

            /**
             * @Route("/index/{name}")
             */
            public function index($name)
            {
                return $this->render('default/index.html.twig', [
                            'name' => $name,
                        ]);
             }

    }

Видим что у данного контроллера от родительского унаследовался некий метод `$this->render()`
который первым параметров указывает путь к стандартной директории twig в результатет у нас
получается след путь к файлу вида `templates + default/index.html.twig`

Путь к файлу вида == `templates/default/index.html.twig`

Еслибы мы строили API систему то у нас в распоряжении от родительского контроллера есть
еще один метод, для формирования ответа в виде JSON:

    /**
    * @Route("/api/hello/{name}")
    */
    public function apiExample($name)
    {
        return $this->json([
            'name' => $name,
            'symfony' => 'rocks',
        ]);
    }





























