/*
* Fórmula para um array circular Decrescente
* Com esta fórmula podemos saber em que indice pararemos depois de pularmos no "sentido horário" - aumentando o array:

    i+=pulo;
    while(i > tam)
    {
    i -= tam;
    }

*Com esta fórmula podemos saber em que indice no pararemos depois de pularmos no "sentido anti-horário" - diminuindo o array:

    i -= pulo;
    while(i < 0)
    {
    i += tam;
    }

*/