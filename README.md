# Ejemplo para la depuración de un programa

Utilizando esta plantilla se experimentará con la depuración en circuito de un programa y se buscará reducir lo máximo posible el tiempo de ejecución

El programa consta de dos apartados, en cada uno de ellos habrá que introducir código en una función

# Ejercicio 1

En este ejercicio hay que modificar el código que se encuentra en la función calcularRMS, la función tiene este definición:

'''
    float calcularRMS(int16_t *datos, int longitud);
'''

La función recibe un puntero a un array de datos en formato enteros con signo de 16 bits de anchura de palabra.
Los datos que contiene el array provienen de un ADC de 16bits que muestrea una señal comprendida entre -3.3V3 y 3.3V
Como segundo parámetro recibe la cantidad de elementos que contiene el array.
Lo que la función tiene que devolver es el valor Vrms de la señal en Voltios.

La ecuación para calcular la tensión eficaz es la siguiente:

![](https://latex.codecogs.com/svg.image?V_{rms}=\sqrt{\frac{1}{N}\sum_{0}^{N-1}\left|&space;v\left&space;(&space;n&space;\right&space;)\right|^{2}})
