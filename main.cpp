#include "mbed.h"
#include "datos.h"
#include "math.h"
 
#define longitudTrama 500
 
Timer timer;
float resultado;
int tiempo;
 
struct estructuraMedidas 
{ 
   float vrms; 
   float irms;  
   float potenciaActiva; 
   float potenciaReactiva;  
   float potenciaAparente;  
   float energiaConsumida;
   float factorDePotencia;
};
 
float calcularRMS(int16_t *datos, int longitud);
 
void calcularDatos(int16_t *datosV, int16_t *datosI, int longitud, estructuraMedidas *medidas);
 
 
int main()
{
 
    timer.reset();
    timer.start();
    resultado=calcularRMS(datos, longitudTrama);
    timer.stop();
    printf("\n****El valor Vrms es %f calculado en %lld us ****\n\n",resultado,timer.elapsed_time().count());
    
    estructuraMedidas medidas;
    medidas.energiaConsumida=0;
    
    timer.reset();
    timer.start();
    calcularDatos(datosV,datosI,longitudTrama,&medidas);
    timer.stop();
    printf("**** Datos calculados en %lld us ****\n",timer.elapsed_time().count());
    printf("**** El valor Vrms es %f ****\n",medidas.vrms);
    printf("**** El valor Irms es %f ****\n",medidas.irms);
    printf("**** La potencia activa es %f ****\n",medidas.potenciaActiva);
    printf("**** La potencia reactiva es %f ****\n",medidas.potenciaReactiva);
    printf("**** La potencia aparente es %f ****\n",medidas.potenciaAparente);
    printf("**** La energia consumida es %f ****\n",medidas.energiaConsumida);
    printf("**** El factor de potencia es es %f ****\n",medidas.factorDePotencia);

    while(true){}
}
 

 //Esta función calcula el valor RMS
float calcularRMS(int16_t *datos, int longitud)
{
    float rms=0;
    float datoV;
    for (int i=0;i<longitud;i++){
        datoV=datos[i];
        rms+=datoV*datoV;
    }
    rms=sqrt(rms/longitud/32768.0*3.3/32768.0*3.3);
    return rms;
}
 
void calcularDatos(int16_t *datosV, int16_t *datosI, int longitud, estructuraMedidas *medidas)
{
    
}  

