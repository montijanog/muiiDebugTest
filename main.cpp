/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define nDatos 5
#define WAIT_TIME_MS 1000

float multiplicaDatos(float a, float b);

int main()
{
    printf("Inicia el programa\n");

volatile    float vectorA[nDatos]={1.2, 3.3, 4.5, 8.4, 5.4};
volatile    float vectorB[nDatos]={5.2, 6.3, 7.5, 5.4, 6.4};
    float resultado=0;

    for (int i=0;i<nDatos;i++){
        float datoA=vectorA[i];
        float datoB=vectorB[i];
        resultado+=multiplicaDatos(datoA,datoB);
        
    }
    
    printf("El resultado es %f\n",resultado);
    printf("Programa finalizado\n");
    while (true)
    {
        thread_sleep_for(WAIT_TIME_MS);
    }
}

float multiplicaDatos(float a, float b){
    return a*b;
    
}