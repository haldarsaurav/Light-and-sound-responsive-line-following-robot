//***************************************************************************************
//  Description;  Switch P1.1 of MSP430 between output 3.3V and input mode (high-Z) to
// 	demonstrate tri-stating and bypass capacitor filtering. If the LaunchPad button
//	at P1.3 is pressed, the output switches at a higher frequency.
//      Use the green LED as an indicator of output state.
//***************************************************************************************

int VOUT   = P1_1;  // set VOUT   as P1.1 alias
int BUTTON = P1_3;  // set BUTTON as P1.3 alias
int GRNLED = P1_6;  // set GRNLED as P1.6 alias

void setup()
{ 
  pinMode(BUTTON, INPUT_PULLUP);   // set P1.3 as input (pushbutton) with pullup R
  pinMode(GRNLED, OUTPUT);         // set P1.6 as output (Green LED)
}

void loop()
{
  pinMode(VOUT, OUTPUT);           // set VOUT as output
  digitalWrite(VOUT, HIGH);        // set VOUT and GRNLED to 3.3V
  digitalWrite(GRNLED, HIGH);
  
  delay(50);                       // wait, tri-state VOUT, and turn off GRNLED
  pinMode(VOUT, INPUT);
  digitalWrite(GRNLED, LOW);
  if (digitalRead(BUTTON) == LOW)   // check pushbutton state
  {   
	delayMicroseconds(1000);        // if button is pressed, discharge cycle lasts 1 ms
  }
  else
  {
    delay(100);                     // if button is unpressed, discharge cycle lasts 100 ms
  }    
}
