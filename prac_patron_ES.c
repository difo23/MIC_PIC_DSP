
#include "xc.h"

/* Configuration bits */
/* XT crystal, clock switching and fail safe clock monitor off */
/* Crystal of 7.3728 MHz */
_FOSC(CSW_FSCM_OFF & XT_PLL8);
/* XT_PLL4 or XT_PLL8 for 20I (20 MIPS) devices */
/* XT_PLL16 for 30I (30 MIPS) devices */

_FWDT(WDT_OFF); /* Watchdog timer off */
/* Pin function is MCLR, PWM pins are io pins on reset */
/* PWM high-side pins are activa high */
/* PWM low-side pins are activa high */
/* Brown out reset active, BOR active when Vdd goes below 2.7v */
/* Power up time out of 64 ms */
_FBORPOR(MCLR_EN & RST_IOPIN & PWMxH_ACT_HI & PWMxL_ACT_HI
         & PBOR_ON & BORV27 & PWRT_64);
/* No protect code memory */
_FGS(CODE_PROT_OFF);

void init_TMR1(void){

    TMR1=0;
    
    PR1=57600;

    T1CONbits.TSIDL=1;
    T1CONbits.TGATE=0;
    T1CONbits.TCS=0;

    T1CONbits.TCKPS=3;
    T1CONbits.TSYNC=0;

    IPC0bits.T1IP = 7;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;

    T1CONbits.TON = 1;

   
}


void init_portb(void)
{
    TRISB= 0x0000;
    ADPCFG = 0xFFFF;
    PORTB=0;
}

int main(void)
{

    init_portb();
    init_tmr1();
    
    SRbits.IPL = 6;

    while(1);

}

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void){

    PORTB +=1;

    IFS0bits.T1IF=0;
    return;


}
