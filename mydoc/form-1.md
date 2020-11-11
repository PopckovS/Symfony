##Создание классов форм.

Специальная утилить терминала для автоматизации создания форм.

    Установите MakerBundle в проекте для создания классов формы 
    с помощью make:formи make:registration-formкомандой.

Фреймворки стремятся использовать в контроллерах как можно меньше логики,
в преведущем уроке мы создавали форму в контроллере при помощи 
вспомагательного метода `createFormBuilder`, этот метод избыточен, 
и подходит только для легких простых форм.

Теперь используем другой метод, пределим форму в отдельном классе, что 
позволит уменьшить обьем кода и переиспользовать этот уже однажды 
определенный класс формы.

Класс формы это класс описывающий форму ее поля на основе специального 
интерфейса `Symfony\Component\Form\FormTypeInterface` но можно использовать
Абстрактный тип формы `Symfony\Component\Form\AbstractType` который уже
реализует/оборачивает в себе Интерфейс формы и потому предоставляет 
дополнительные возможности.

Классы-формы определяются в директории `src/Form/...` их принято называть
с префиксом `Type`, и так реализуем сущьность `Task` через наследование от
`AbstractType` который будет реализовывать в себе 
интерфейс `FormTypeInterface`.

    // src/Form/Type/TaskType.php
    namespace App\Form\Type;
    
    use Symfony\Component\Form\AbstractType;
    use Symfony\Component\Form\Extension\Core\Type\DateType;
    use Symfony\Component\Form\Extension\Core\Type\SubmitType;
    use Symfony\Component\Form\Extension\Core\Type\TextType;
    use Symfony\Component\Form\FormBuilderInterface;
    
    class TaskType extends AbstractType
    {
        public function buildForm(
                                FormBuilderInterface $builder, 
                                array $options
                            )
        {
            $builder
                ->add('task', TextType::class)
                ->add('dueDate', DateType::class)
                ->add('save', SubmitType::class)
            ;
        }
    }

















