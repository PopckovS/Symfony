##Обработка форм отправки.
Учтановка:

     composer require symfony/form

Работа с формами состоит из 3-х шагов:

1) Создайте форму в контроллере.
2) Визуализировать форму в шаблоне twig.
3) Обработайте форму в контроллере.

###Делаем список задачь `Task`
Пользователь имеет возможность создавать и редактировать 
задачи с помощью форм Symfony. Каждая задача будет явл-ся 
экземпляром класса/сущьночти `Task`.

Создаем сущьность по стандартному для Symfony пути `src/Entity/`
Все сущьности получают пространство имен `App\Entity`.

Создаем класс что будет сущьностью описывающей таблицу в БД.
Где каждое поле таблицы представлено в сущьности в виде защищенного
свойства, и также определяем методы геттеры и сеттеры для каждого из
полей.

    // src/Entity/Task.php
    namespace App\Entity;
    
    class Task
    {
        protected $task;
        protected $dueDate;
    
        public function getTask()
        {
            return $this->task;
        }
    
        public function setTask($task)
        {
            $this->task = $task;
        }
    
        public function getDueDate()
        {
            return $this->dueDate;
        }
    
        public function setDueDate(\DateTime $dueDate = null)
        {
            $this->dueDate = $dueDate;
        }
    }  

###Создаем саму форму отправки.
В `Symfony` существует поняие `"типа-формы"` каждое отдельное поле
формы как и группа полей, так и сам тег `<form>` представлены как
экземпляр своего класса, и каждый из них условно называется `"типа-формы"`
Есть множество встроенных типов форм, также можно определять и свои
собственные.

###Создание форм в контроллерах при помощи `createFormBuilder`
Создаем контроллер `TaskController.php` иесли он наследуется от класса
`AbstractController` то у него будет метод помощник `createFormBuilder()`
унаследованный от родителя, этот метод помагает строить форму прямо в
контроллере на основании сущьности, и так что нам требуется:

1) App\Entity\Task - Сущьность на основании которой формируется форма
2) Symfony\Component\Form\Extension\Core\Type\TextType - Класс для
создания обьекта,оторый будет обрабатывать и отображать текстовое поле,
связанное с одним из свойств класса/сущьности.
3) Symfony\Component\Form\Extension\Core\Type\DateType - Класс для 
создания обьекта даты времени.
4) Symfony\Component\Form\Extension\Core\Type\SubmitType - Класс для 
отображения кнопки отправки.
5) Symfony\Component\HttpFoundation\Request - Обьект запроса для 
приема данных отправленых из формы.


    // src/Controller/TaskController.php
    namespace App\Controller;
    
    use App\Entity\Task;
    use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
    use Symfony\Component\Form\Extension\Core\Type\DateType;
    use Symfony\Component\Form\Extension\Core\Type\SubmitType;
    use Symfony\Component\Form\Extension\Core\Type\TextType;
    use Symfony\Component\HttpFoundation\Request;
    
    class TaskController extends AbstractController
    {
        public function new(Request $request)
        {
            // creates a task object and initializes some data for this example
            $task = new Task();
            $task->setTask('Write a blog post');
            $task->setDueDate(new \DateTime('tomorrow'));
    
            $form = $this->createFormBuilder($task)
                ->add('task', TextType::class)
                ->add('dueDate', DateType::class)
                ->add('save', SubmitType::class, ['label' => 'Create Task'])
                ->getForm();
    
            // ...
        }
    }

Создаем сущьность, и вносим начальные данне для примера: 

    $task = new Task();
    $task->setTask('Write a blog post');
    $task->setDueDate(new \DateTime('tomorrow'));

При помощи конструктора форм `createFormBuilder` создаем обьект формы и 
передаем в него обьект сущьности заранее заполненой данными,  

    $form = $this->createFormBuilder($task)

Далее при помощи метода `add` устанавливаем обьекты формы, 

1) Первый параметр название для поля, соответствует названию свойства сущьности.
2) TextType::class статич свойство типа обьекта отвеч-ющего за тип поля.
3) Есть и третий параметр, массив отвечающий за дополнительные параметры 
для поля формы, к примеру `['label' => 'Create Task']` тут к примеру мы 
устанавливаем надпись над полем формы.


    ->add('task', TextType::class)
    ->add('dueDate', DateType::class)
    ->add('save', SubmitType::class, ['label' => 'Create Task'])
    ->getForm();

Далее мы используем метод `->getForm();` билдера формы, который возвращает 
нам обьект формы со всеми вложенными обьектами/полями.























