//***************************************************************************************
//  Description; the MSP430 reads the output of the microphone circuit at P1.5 and
//	decides whether or not to flash on an LED based on the sound level
//***************************************************************************************

int MICINP = A5;   // set MICINP as P1.5 alias
int GRNLED = P1_6; // set GRNLED as P1.6 alias

void setup()
{
  // start the serial monitor
  Serial.begin(9600);
  
  // set GRNLED as output pin
  pinMode(GRNLED, OUTPUT);
  
  Serial.println("Setup complete!");
}

void loop()
{
  int value;				   // declare variable value to store result of analogRead
  value = analogRead(MICINP);  // get the voltage from the microphone
  Serial.println(value);       // write digitized value to serial monitor

  if (value >= 560)            // if digitized value is above 560,
  {
    digitalWrite(GRNLED, HIGH);// turn on the LED...
  }
  else
  {
	digitalWrite(GRNLED, LOW); // ...else turn off the LED
  }
  
  delay(1);                    // delay in between reads for stability
    
}
