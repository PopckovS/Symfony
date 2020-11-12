<?php

namespace App\Controller;

use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Routing\Annotation\Route;
use Psr\Log\LoggerInterface;

use App\Service\GreetingGenerator;


class TestController extends AbstractController
{
    /**
     * @Route("/test")
     */
    public function test()
    {

        $result = 'Тест';

        return $this->render('default/index.html.twig', [
            'name' => $result,
        ]);
    }

}


