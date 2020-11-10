##Урок №6 Request, Flash-сообщения, Объекты Request и Response¶

Что вы будете делать, если вам понадобится узнать параметры запроса,
заголовок запроса или получить доступ к загруженному файлу?
Вся эта информация в Symfony содержится в объекте Request.

Чтобы получить доступ к обьекту `Request` используем его как сервис:


    use Symfony\Component\HttpFoundation\Request;
    
    public function index(Request $request, $firstName, $lastName)
    {
        $page = $request->query->get('page', 1);
    
        // ...
    }


###Flash-сообщения

Можно сохранять в пользовательской сессии специальные flash сообщения
предполагается использовать их один раз, полсе чего они автоматически 
исчезают из сессии как только мы их возвращаем. Их можно использовать как
пользовательчкие оповещания.

Это очень хорошо работает вместе с формами отправки, 
 
Отправка формы, с отправкой flash сообщения об удачном обновлении в случае
если форма была отправлена `$form->isSubmitted()` и была пройдена валидация
значений пришедших из формы `$form->isValid()`.

    public function update(Request $request)
    {
        // ...
    
        if ($form->isSubmitted() && $form->isValid()) {
            // выполните какую-то обработку
    
            $this->addFlash(
                'notice',
                'Изменения сохранены!'
            );
            
            // Эти записи эквивалентны 
            // $this->addFlash() 
            // $request->getSession()->getFlashBag()->add()
    
            return $this->redirectToRoute(...);
        }
    
        return $this->render(...);
    }

Ключ к сообщению `notice` может быть любым, он используется для доступа 
к самому сообщению, по этому ключу можно получить доступ к сообщению:
    
    {# вы можете прочитать и отобразить только один тип флеш-сообщений... #}
    {% for message in app.flashes('notice') %}
        <div class="flash-notice">
            {{ message }}
        </div>
    {% endfor %}

Или можно отобразить все сообщения что етсь:

    {# ...или вы можете прочитатьи отобразить все доступные флеш-сообщения #}
    {% for label, messages in app.flashes %}
        {% for message in messages %}
            <div class="flash-{{ label }}">
                {{ message }}
            </div>
        {% endfor %}
    {% endfor %}

Стандартно принято использовать ключи `notice, warning ` и ` error` для
разных типов сообщений.

###Объекты Request и Response

###Request
Мы можем получать обьект запроса как аргумент а функцию:

    public function index(Request $request)

У класса `Request` есть ряд методов и свойств которые предостаавляют 
информацию о запросе:
    
    // Это запрос Ajax? что использовал API браузера для получения информации
    // с сервера true/false
    $request->isXmlHttpRequest(); 

    // Язык что используется
    $request->getPreferredLanguage(array('en', 'fr'));

    // извлекает переменные GET и POST соответственно
    $request->query->get('page');
    $request->request->get('page');

    // извлекает переменные SERVER’а
    $request->server->get('HTTP_HOST');

    // извлекает объект UploadedFile по ключу foo
    $request->files->get('foo');

    // извлекает значение COOKIE
    $request->cookies->get('PHPSESSID');

    // извлекает заголовок запроса HTTP с нормализированными ключами строчными буквами
    $request->headers->get('host');
    $request->headers->get('content_type');

###Response

У обьекта `Response` тоже есть методы для чтения и изменения 
заголовков ответов.

    use Symfony\Component\HttpFoundation\Response;
    
    // создаёт простой Response со статус-кодом 200 (по умолчанию)
    $response = new Response('Hello '.$name, Response::HTTP_OK);
    
    // создаёт CSS-ответ со статус-кодом 200
    $response = new Response('<style> ... </style>');
    $response->headers->set('Content-Type', 'text/css');

##Возвращение JSON-ответов
Можно возвращать JSON из контроллера.

    public function index()
    {
        // возвращает '{"username":"jane.doe"}' 
        // и устанавливает правильный заголовок Content-Type
        return $this->json(array('username' => 'jane.doe'));
    
        // сокращеиие определяет три необязательных аргумента
        // вернуть $this->json(
                        $data, 
                        $status = 200, 
                        $headers = array(), 
                        $context = array()
                    );
    }

##Отдаем на скачивание файл. 

Отдаем на скачивание файл при помощи метода `$this->file`

    public function fileAction()
    {
        // отправить содержание файла и заставить браузер скачать его
        return $this->file('/path/to/some_file.pdf');
    }

Класс `File` предоставляет дополнительные методы для работы с файлами.

    
    use Symfony\Component\HttpFoundation\File\File;
    use Symfony\Component\HttpFoundation\ResponseHeaderBag;
    
    public function fileAction()
    {
        // загрузить файл из файловой системы
        $file = new File('/path/to/some_file.pdf');
    
        return $this->file($file);
    
        // переименовать скачанный файл
        return $this->file($file, 'custom_name.pdf');
    
        // отобразить содержание файла в браузере вместо скачивания
        return $this->file(
                    'invoice_3241.pdf', 
                    'my_invoice.pdf', 
                    ResponseHeaderBag::DISPOSITION_INLINE
               );
    }





