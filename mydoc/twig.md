##Twig описание и примеры


    post.published_at = 2020.10.11
    
    {{ post.published_at|date_modify("+1 day")|date("m/d/Y") }}

    // Будет выведено 2020.10.11

