//archivos de cabecera
#include "p30f3014.h"
#include "libpic30.h"
#include "common.h"


//macros o configuracion de parametros
_FOSC(CSW_ON_FSCM_OFF & XT);
_FWDT(WDT_OFF);
_FBORPOR(PBOR_OFF & PWRT_16 & MCLR_EN);
_FGS(CODE_PROT_OFF);

//rutina de retardos
#ifndef __DELAY_H
#define delay_us(x) __delay32(((x*FCY)/1000000L))//delay x us
#define delay_ms(x) __delay32(((x*FCY)/1000L)) //delay x us
#define delay_s(x) __delay32(((x*FYC)/1L))
#define __DELAY_H 1
#endif

//MAIN

int main()
{
	TRISB= 0XFFFF; //defino la entrada
	TRISF=0; //DESTINO SALIDA

	//definir entradas analogicas o digitales

	ADPCFG = 0xFFFC; //RB1 y RB2 analogo; todo lo demas digtial

	// configuracion general del ADC
	ADCON1=0;//adon=0 adc off
	//form=0 formato salida=entero
	//ssrc=0 inicio de conversion: manual (a traves de samp)
	//simsam=0 muestras secuenciales (una por una)
	//asam=0 muestreo empiza con samp=1
	//samp=0 muestreo deshabilitado (inician cuando samp=1)
	//done=0 convesrio no terminada	

	//Cofigurar canales A/D de entrada
	ADCHS=0; //ch0na=0 channel 0 negative input is vref
	//ch0sa=0000 rb0/an0 = ch0 configuro rb/an0 como mi canal

	//SCAN
	ADCSSL=0; //skip scan de todos los canales

	//tiempos
	ADCON3=0x0101; //1 TAD y reloj derivado del sistema

	//BUffers
	ADCON2=0; // VCFG=0 referencias avss= negativa avdd= positiva
	// CSCNA=0 no scan
	//CHPS=0 convertir ch0
	//BUFS=0 No aplica pues no dividiremos el resultado
	// SMPI=0 interrumpir cuando se complete una conversion
	//ALTS=0 usar unicamente mux a (MUestreo SIMPLE)

ADCON1bits.ADON=1; //ADC ON
while(1)
{
	ADCON1bits.SAMP=1; //iniciar muestreo ...
	delay_us(100); // esperando 100us
	ADCON1bits.SAMP=0;// detener muestreo; iniciar conversion
	while(!ADCON1bits.DONE); //conversion lista?
	int VADC=ADCBUF); // SI, CAPTURAR EL VALOR EN LA VARIABLE VADC

	PORTF= 0b0101010101010101;
	delay_ms(VADC);
	PORTF= 0b1010101010101010;
	delay_ms(VADC);
		
}
	return 0; //REPETIR

}