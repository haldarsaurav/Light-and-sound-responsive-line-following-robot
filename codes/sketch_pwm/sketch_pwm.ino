//***************************************************************************************
//  Description;  Switch P2.1 and P1.6 of MSP430 between 3.3V and 0V to create
//                a PWM signal for motor control
//***************************************************************************************

int LMOTOR = P2_1;     // set LMOTOR as P2.1 alias
int RMOTOR = P1_6;     // set RMOTOR as P1.6 alias

void setup()
{ 
  pinMode(LMOTOR, OUTPUT);   // set P2.1 as output (LMOTOR)
  pinMode(RMOTOR, OUTPUT);   // set P1.6 as output (RMOTOR)
}

void loop()
{            
   analogWrite(RMOTOR,128);  // PWM both motors at 50%
   analogWrite(LMOTOR,128);
   delay(1000);              // let motors run one second
   analogWrite(RMOTOR,0);    // turn both motors off
   analogWrite(LMOTOR,0);
   delay(1000);              // let motors rest one second
}
