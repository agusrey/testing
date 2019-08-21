# testing
TP3 Testing de Software CESE2019 8Co
El trabajo consiste en desarrollar un driver simple de comunicaciones por consola
que será invocado por una tarea bajo freertos. Dicha tarea quedará bloqueada
en una función tipo "gets", y una vez obtenido el string por consola llamará
a funciones del driver.

Se reciben comandos para arrancar y detener el motor como asi también
valores de velocidad y rampas de aceleración y desaceleración.
También verifica que los valores ingresados estén dentro del rango permitido
