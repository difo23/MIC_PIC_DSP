unsigned rx1;

void main() {

  Uart1_Init(9600);                 // initialize USART module


  //--- un-comment the following lines to have Rx and Tx pins on their alternate
  //    locations. This is used to free the pins for other module, namely the SPI.
    U1MODEbits.ALTIO = 1;
    Delay_ms(10);                     // pause for usart lines stabilization
    rx1 = Uart1_Read_Char();          // perform dummy read to clear the register

  Uart1_Write_Char('s');            // signal start

  while(1) {
    if (Uart1_Data_Ready())  {     // check if there is data in the buffer
     rx1 = Uart1_Read_Char();      // receive data
     Uart1_Write_Char(rx1);        // send data back
    }
  }
}//~!