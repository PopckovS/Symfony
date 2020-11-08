<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Routing\Annotation\Route;
use Psr\Log\LoggerInterface;

use App\Service\GreetingGenerator;


class LessonFirstController extends AbstractController
{

    /**
     * @Route("/index/{name}")
     */
    public function index($name, LoggerInterface $logger)
    {
        $logger->info("Saying hello to $name!");

        return $this->render('default/index.html.twig', [
            'name' => $name,
        ]);
    }


    /**
     * @Route("/greeting/{name}")
     */
    public function greeting($name, LoggerInterface $logger, GreetingGenerator $generator)
    {
        $randomGreeting = $generator->getRandomGreeting();
        $logger->info("Был использовансозданный в ручную и  Автомонтированный сервис, $name, $randomGreeting");
        return $this->render('default/greeting.html.twig', [
            'router' => "/greeting/$name",
            'service' => "Автомонтированный сервис созданный нами.",
            'greeting' => $randomGreeting,
            'name' => $name,
        ]);
    }


}


