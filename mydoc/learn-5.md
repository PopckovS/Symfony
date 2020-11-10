##Урок №5 Переадресация, ошибки и 404 страница 

###`Controller` и `AbstractController`

Есть 2 способа как можно расширить контроллер, от Controller или AbstractController:

    use Symfony\Bundle\FrameworkBundle\Controller\Controller;

    class LuckyController extends Controller
    {
        ...
    }

Разница между `Controller` и `AbstractController` небольшая 
`AbstractController` более ограниченный - он не позволяет вам получить 
доступ к сервисам напрямую через `$this->get()` или `$this->container->get()` 

###Название для маршрутов

При создании маршрута для контроллера мы можем создать Алиас, тоесть название
для жтого маршруту, вот такой строчкой `name="app_lucky_number"`

     /**
     * @Route("/lucky/number/{max}", name="app_lucky_number")
     */
     public function number($max)
     {
        ...
     }

Когда мы унаследовались свои контроллером от базового,ы унаследовали ряд методов
помошников, в том числе и метод `$this->generateUrl` этот метод генерирует
`URL` с заданными параметрами, для перенаправления на нужный контроллер.

    $url = $this->generateUrl('app_lucky_number', array('max' => 10));

У нас уже есть метод контроллера с названием `number` к которому привязан роутинг
`@Route("/lucky/number/{max}"` и у этого роутинга есть название по которому к нему
можно обратиться `name="app_lucky_number"` и теперь используя это имя мы можем
сделать на него перенаправление.

####Перенаправление
Перенаправление можно сделать при помощи 2-х методов,ба они являются методами
родительского контроллера.

    1) redirectToRoute() 
    2) redirect()

1) `redirect()` Полноценное перенаправление, где мы указываем адрес для адресации полностью.
    
    // перенаправляет внутренне
    return $this->redirect('http://symfony.com/doc');

2) `redirectToRoute()` Перенаправление на маршрут по его названию:


    // пенеправить по маршруту "homepage"
    return $this->redirectToRoute('homepage');

    // Или так где app_lucky_number название маршрута, а массив это его параметры
    return $this->redirectToRoute('app_lucky_number', array('max' => 10));


###Управление ошибками и 404 страницами
Если нам нужно отдать пользователю страницу 404 то мы можем кинуть исключение
с сообщением об ошибке, при помощи встроенного метода уносаледованного от 
родительского контроллера `$this->createNotFoundException`.

    throw $this->createNotFoundException('The product does not exist');

У Symfony есть 3 режима работы, которые можно переключать в главном 
конфигурационном файле **`.env`** вот они:
    
    1) APP_ENV=dev
    2) APP_ENV=prod
    3) APP_ENV=test

Если мы находимся в режиме `dev` режим разработчика, то при выдаче исключения
методом `createNotFoundException` мы получим страницу ошибки со всеми параметрами,
и отладочной информацией. 

Если мы находимся в режиме `prod` то мы увидим стандартную страницу 
ошибки `404` подобно этой:

    Oops! An Error Occurred
    The server returned a "404 Not Found".
    
    Something is broken. Please let us know what you were doing when this error occurred. 
    
    We will fix it as soon as possible. Sorry for any inconvenience caused.
















