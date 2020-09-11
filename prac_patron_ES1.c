
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



void init_portb(void)
{
    // Configure RB as digital
    TRISB = 0x0000;
    ADPCFG = 0xFFFF;

    PORTB = 0;
}

 
int main(void)
{
    init_portb();


    SRbits.IPL = 6; /* Enable only CPU priority 7 */
    
    
    while(1)
    {
      PORTB += 1;
    }

    return 0;
}



