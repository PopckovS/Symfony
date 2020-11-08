<?php

namespace App\Twig;

use Twig\Extension\AbstractExtension;
use Twig\TwigFilter;
use App\Service\GreetingGenerator;


class GreetExtension extends AbstractExtension
{
    private $greetingGenerator;


    /** Создаем все Сервисы с которыми будем работать. */
    public function __construct(GreetingGenerator $greetingGenerator)
    {
        $this->greetingGenerator = $greetingGenerator;
    }


    /** Возвращаем фильтр связанный с методом данного класса. */
    public function getFilters()
    {
        return [
            new TwigFilter('greet', [$this, 'greetUser']),
        ];
    }


    /** Метод что будет использован как фильтр */
    public function greetUser($name)
    {
        $greeting = $this->greetingGenerator->getRandomGreeting();
        return "<p style='color: #B0413E'>Сообщение полученное с использованием своего фильтра: $greeting $name</p>";
    }
}