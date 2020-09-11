/*
Práctica-CAD

1. Configurar el procesador digital de señal dsPIC30F4012 para que arranque correctamente.
2. Configurar correctamente la UART para poder visualizar los resultados obtenidos.
3. Configurar correctamente el CAD para tomar muestras analógicas de un dispositivo externo.


Consideraciones añadidas:

1. Las muestras de tensión tendrán valores dentro del margen 5V..0V.
2. Debe utilizarse como pin de entrada analógico el pin B0.
3. En este primer ensayo se recomienda utilizar el canal 0.
4. Atendiendo a lo indicado en el punto 2, no deben muestrearse varias entradas.
5. El disparo de la conversión debe configurarse para realizarse de manera “manual” (poniendo
a cero el bit SAMP).
6. Debe configurarse una conversión por interrupción del ADC.
7. Como consecuencia de lo anterior, no tiene sentido dividir el conjunto de registros de
resultados en dos bloques independientes (BUFM = 0).
*/

#include "xc.h"