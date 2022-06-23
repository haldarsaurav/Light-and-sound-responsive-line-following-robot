//***************************************************************************************
//  Description; P1.3 outputs 800 Hz square wave in random burst patterns
//***************************************************************************************

int BUZZER = P1_3; // set BUZZER as P1.3 alias

void setup()
{
  // set BUZZER as output pin
  pinMode(BUZZER, OUTPUT);
  
  // random analog voltage noise at analog pin 0 will seed
  // the random number generator differently every time it runs
  // otherwise, we will hear the same pseudo-random sequence
  // every time we run the program (which is at times useful)
  randomSeed(analogRead(0));
}

void loop()
{
  int val;					// declare variable val to store result of Random Number Generator (RNG)
  val = random(1,100);      // create a random number from 1 to 100 using the Energia RNG
  if (val > 50)             // if val is greater than 50, output an 800 Hz wave
  {
    tone(BUZZER, 800, 50);  // otherwise, do nothing for the same period
  }
  else
  {
    delay(50);
  }
}
