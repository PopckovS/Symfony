##Урок №4. Автомонтирование и свои собстенные Сервисы.

Установка логгера Monolog через рецепты Flex.

    composer require logger

Чтобы сразу использовать ноовый подключенный класс, мы подключаем его:

    use Psr\Log\LoggerInterface;

И сразу указываем аргумент передаваемый в метод контроллера как переменную нужного класса,
Symfony сам создаст обьект этого класса, это называется `автомонтирование`:

    public function index($name, LoggerInterface $logger)
    {   
        $logger->info("Saying hello to $name!");

        // ...
    }

Далее мы можем использовать переменную $logger как обьект класса LoggerInterface.
Все подобные обьекты называются `Сервисами`.
Сообщения логгера хранятся в `var/log/dev.log` 

Таким образом различные Бандлы что мы устанавливаем в наше приложение, могут использоваться для
`Автомонтирования` в наши методы как Сервисы.

Для того чтобы посмотреть все доступные классы для использования их как Сервисов, выполним:

    php bin/console debug:autowiring

В результате получим списки пространст имен классов для подключения и использования:

        Provides basic utility to manipulate the file system.
        Предоставляет базовую утилиту для управления файловой системой.
    Symfony\Component\Filesystem\Filesystem (filesystem)

        Allows creating a form based on a name, a class or a property.
        Позволяет создать форму на основе имени, класса или свойства
    Symfony\Component\Form\FormFactoryInterface (form.factory)

        Validates PHP values against constraints.
        Проверяет значения PHP на соответствие ограничениям
    Symfony\Component\Validator\Validator\ValidatorInterface (debug.validator)

###Свои Сервисы.

По мимо использования сторонних сервисов при Автомонтировании в аргументы наших методов, мы
можем создавать свои собственные Сервисы, все сервисы должны быть определены в директории
`src/Service` к примеру создадим сервис с названием `GreetingGenerator.php`.

Определим ему пространство имен `namespace App\Service;` и создадим сам класс:

    namespace App\Service;

    class GreetingGenerator
    {

        public function getRandomGreeting()
        {
            $greetings = ['Hey', 'Yo', 'Aloha'];
            $greeting = $greetings[array_rand($greetings)];
    
            return $greeting;
        }
    }

Теперь мы создали свой собственный сервис, и можем использовать его при Автомонтировании в наши
контроллеры, подобно любым сторонним Сервисам что подключаем через composer.

Для этого импортируем класс Сервиса в наш контроллер `use App\Service\GreetingGenerator;` и
все егом можно автомонтировать в методы контроллеров.

Если в нутри нашего Сервиса мы хотим использовать сторонний сервис, его следует определить 
через автомонтирование в конструкторе Сервиса, и присвоить в свойство класса:

    class GreetingGenerator
    {
        private $logger;

        public function __construct(LoggerInterface $logger)
        {
            $this->logger = $logger;
        }

        public function getRandomGreeting()
        {
            $greetings = ['Hey', 'Yo', 'Aloha'];
            $greeting = $greetings[array_rand($greetings)];
    
            return $greeting;
        }
    }

###Свои Фильтры

Используя шаблонизатор `Twig` мы можем работать с фильтрами,оторые работают как функции обертки,
принимают значение обрабатываеют его и возвращают результат. К примеру так

    $name = "HelloWorld!"
    <h1>{{ name|length }}</h1>   

В результате выведет число: **11**

Мы можем создавать свои собственные фильтры для `twig`. Сделаем это, создадим директорию в `src`
под названием `Twig`. Создадим в ней файл `GreetExtension.php` и получим полный путь в виде
`src/Twig/GreetExtension.php`. Класс будет иметь следующие видимости:

    namespace App\Twig; // Простр имен самого класса.

    use App\GreetingGenerator; // Созданный нами ранее Сервис Генератор.

    use Twig\TwigFilter; // Класс фильтра
    use Twig\Extension\AbstractExtension; // Абстрактный класс для создания своего фильтра  

Создадим класс и унаследуем его от Абстрактного Расширения.
    
    class GreetExtension extends AbstractExtension

Мы можем использовать в своих фильтрах, созданныем намиже сервисы, для этого определим их
также как и до этого определяли сторонние сервисы в наших сервисах.

    private $greetingGenerator;

    public function __construct(GreetingGenerator $greetingGenerator)
    {
        $this->greetingGenerator = $greetingGenerator;
    }

Далее создадим 2 Функции. Первая из них и будет функцией фильтром, это сам обработчик,
функция что будет производить фильтрацию полученного аргумента и возвращать результат.

    public function greetUser($name)
    {
        $greeting = $this->greetingGenerator->getRandomGreeting();
        return "$greeting $name!";
    }

Получаемый аргумент и будет тем параметром что передается в фильтр, тут же мы используем 
созданный нами ранее Сервис, и возвращаем обработанный результат.

Вторая функция что мы определим, будет связующей, ее задача возвращать обьект базового фильтра
который использовать нашу функцию фильтр как колбэк.

    public function getFilters()
    {
        return [
            new TwigFilter('greet', [$this, 'greetUser']),
        ];
    }

Эта функциядолжна возвращать массив с фильтрами, в данном слуае обьект типа `new TwigFilter`
а уже потом этот обьект вызовет зарагестрированную функцию обработчик, которую мы создали ранее,
параметры при создании обьекта:

1) Название фильтра, по которому к нему будет обращение из `twig` шаблона, в данном случае это `'greet'`
2) Это массив где:
   1) Первый параметр это указание на обьект из которого будет взята функция для коллбэка.
   2) Название метода что будет вызван как колбэк для фильтра.