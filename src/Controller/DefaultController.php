<?php

namespace App\Controller;

use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;



class DefaultController
{

    /**
     * @Route("/")
     */
    public function index()
    {
        return new Response("Hello!");
    }

    /**
     * @Route("/hello/{name}")
     */
    public function hello($name)
    {
        return new Response("Hello! $name" );
    }


    /**
     * @Route("/lucky/number")
     */
    public function number()
    {
        $number = mt_rand(0, 100);

        return new Response(
            '<html><body>Lucky number: '.$number.'</body></html>'
        );
    }

}
