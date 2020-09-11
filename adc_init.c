//Converting 1 Channel, Manual Sample Start,
//Manual Conversion Start Code



ADPCFG = 0xFFFB;	//All PORTB = Digital; RB2 = analog.
ADCON1 = 0x0000;	//SAMP bit = 0 ends sampling ...
					//and starts converting
ADCHS= 0x0002;		//Connect RB2/AN2 as CH0 input ..
					//in this example RB2/AN2 is the input
ADCSSL = 0;
ADCON3 = 0x0002;	// Manual Sample, Tad = internal 2 Tcy
ADCON2 = 0;


ADCON1bits.ADON = 1;	// turn ADC ON
while (1)				// repeat continuously
{
ADCON1bits.SAMP = 1;	//start sampling ...
DelayNmSec(100);		//for 100 mS
ADCON1bits.SAMP = 0;	//start Converting
while (!ADCON1bits.DONE); //conversion done?
ADCValue = ADCBUF0; //yes then get ADC value
}//repeat















