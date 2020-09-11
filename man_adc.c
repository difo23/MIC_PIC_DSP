/* device = dsPIC30F6014A
   Clock=10MHz */

void main(){
  TRISB  = 0xFFFF;          //Port B is input
  TRISD  = 0;               //Port D is output (for ADC results)
  ADPCFG = 0xFBFF;          //10th channel is sampled and coverted
  ADCON1 = 0;               //ADC off, output_format=INTEGER
                            //Manual start of convesion
                            //Manual start of sampling
  ADCHS  = 0x000A;          //Connect RB10 on AN10 as CH0 input
  ADCSSL = 0;               //No scan
  ADCON3 = 0x1003;          //ADCS=3 (min TAD for 10MHz is 3*TCY=300ns)
  ADCON2 = 0;               //Interrupt upon completion of one sample/convert
  ADCON1.F15 = 1;           //ADC on
  while (1) {
      ADCON1.F1 = 1;        //Start sampling (SAMP=1)
      Delay_ms(100);        //Wait for 100ms (sampling ...)
      ADCON1.F1 = 0;        //Clear SAMP bit (trigger conversion)
      while (ADCON1.F0 == 0)
         asm nop;           //Wait for DONE bit in ADCON1
      LATD = ADCBUF0;       //Output result on port D
  }
}