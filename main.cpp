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
    float rms;
    float num = 32768.0*3.3;
    float mile = 0.00000001;
    int i=0;
    int a=100;
    int b=200;
    int c=300;
    int d=400;
    
    //float datoV;
    for (i && a && b && c && d;i<100 && a<200 && b<300 && c<400 && d<longitud;i++,a++,b++,c++,d++){
        //datoV=datos[i];
        rms+=((datos[i]*datos[i])+(datos[a]*datos[a])+(datos[b]*datos[b])+(datos[c]*datos[c])+(datos[d]*datos[d]));
    }
    rms=sqrt(rms*mile/longitud*num/num);
    return rms;
}
 
void calcularDatos(int16_t *datosV, int16_t *datosI, int longitud, estructuraMedidas *medidas)
{
    int16_t voltajes;
    int32_t product_volt;
    int64_t sumatorio_volt=0;
    float resultado_v;
    int16_t intens;
    int32_t product_i;
    int64_t sumatorio_i=0;
    float resultado_i;
    int32_t pot;
    int64_t sumatorio_pot=0;
    float resultado_pot;
    float cte=6.6/65536.0*6.6/65536.0;
 
    for (int n=0;n<longitud;n++){
            
            voltajes=datosV[n];
            product_volt=voltajes*voltajes;
            sumatorio_volt+=product_volt;
            
            intens=datosI[n];
            product_i=intens*intens;
            sumatorio_i+=product_i;
            
            pot=voltajes*intens;
            sumatorio_pot+=pot;
            
        }
        resultado_v=sumatorio_volt*cte/longitud;
        resultado_i=sumatorio_i*cte/longitud;
        resultado_pot=sumatorio_pot*cte/longitud;
    
    (*medidas).vrms=sqrt(resultado_v);    
    (*medidas).irms=sqrt(resultado_i);
    (*medidas).potenciaActiva=resultado_pot;
    (*medidas).potenciaAparente=(*medidas).vrms*(*medidas).irms;
    (*medidas).potenciaReactiva=sqrt(-((*medidas).potenciaActiva*(*medidas).potenciaActiva)+((*medidas).potenciaAparente*(*medidas).potenciaAparente));
    (*medidas).factorDePotencia=(*medidas).potenciaActiva/(*medidas).potenciaAparente;
 
}
 

