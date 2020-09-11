/*device = dsPIC30F6014A
  Clock=10MHz*/

void main(){
  TRISB  = 0xFFFF;        //Port B is input
  TRISD  = 0;             //Port D is output (for ADC results)
  ADPCFG = 0xFBFF;        //10th channel is sampled and coverted
  ADCON1 = 0x0040;        //ADC off, output_format=INTEGER
                          //Timer 3 starts convesion
  ADCHS  = 0x000A;        //Connect RB10 on AN10 as CH0 input
  ADCSSL = 0;             //No scan
  ADCON3 = 0x0F00;        //TAD = internalTCY
                          //Sample time ends with timer 3 clock
  /*TIMER3 init*/
  TMR3   = 0;             //Reset TIMER3 counter
  PR3    = 0x3FFF;        //PR3, number of TIMER3 clocks between two conversions start
  T3CON  = 0x8010;        //TIMER3 ON, prescale 1:1

  ADCON1.F15 = 1;         //ADC on
  ADCON1.F2  = 1;         //ASAM=1, start sampling after conversion ends
  while(1){
     ADCON1.F1 = 1;       //SAMP=1, start sampling
     while(ADCON1.F0 == 0)
       asm nop;           //Wait for DONE bit in ADCON1
     LATD = ADCBUF0;      //Output result on port D
  }
}