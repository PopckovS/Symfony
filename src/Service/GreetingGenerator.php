<?php

namespace App\Service;

use Psr\Log\LoggerInterface;


/** В место использования стороннего сервиса, мы создаем свой собственный
 * Обьявив этот класс с методами мы создали свой собственный сервис,
 * который мы можем использовать для Автомонтирования.
 */
class GreetingGenerator
{
    private $logger;


    /**
     * Если мы хотим использовать в нутри нашего собственного Сервиса, сторонний сервис то
     * нам нужно определить их инициализацию в методе конструкторе, и сохранить во внутреннем
     * свойстве класса, чтобы взаимодействовать с ним во всех методах класса.
     */
    public function __construct(LoggerInterface $logger)
    {
        $this->logger = $logger;
    }


    /**
     * Этот метод можно использовать в методах класса
     * где происходит автомонтирование этого Сервиса.
     */
    public function getRandomGreeting()
    {
        $greetings = ['Hey', 'Yo', 'Aloha'];
        $greeting = $greetings[array_rand($greetings)];

        return $greeting;
    }
}