//Converting 1 Channel, Automatic Sample Start,
//Manual Conversion Start Code



ADPCFG = 0xFF7F;	//1111 1111 0111 1111 All PORTB = Digital; RB7 = analog.
ADCON1 = 0x0004;	//0000 0000 0000 0100 SAMP bit = 1 implies sampling ...
					//and starts immediately after last

ADCHS= 0x0007;		//Connect RB7/AN7 as CH0 input ..
					//in this example RB7/AN7 is the input
ADCSSL = 0;
ADCON3 = 0x0002;	// Manual Sample, Tad = internal 2 Tcy
ADCON2 = 0;


ADCON1bits.ADON = 1;	// turn ADC ON
while (1)				// repeat continuously
{
//ADCON1bits.SAMP = 1;	//start sampling ...
DelayNmSec(100);		//for 100 mS
ADCON1bits.SAMP = 0;	//start Converting
while (!ADCON1bits.DONE); //conversion done?
ADCValue = ADCBUF0; //yes then get ADC value
}//repeat
