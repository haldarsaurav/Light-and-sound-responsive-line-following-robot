//***************************************************************************************
//  Description; Power-block a 3.3V rail at P1.1 and subsequently read inputs from
//     Wheatstone bridges, connected to P1.2 and P1.7
//***************************************************************************************

int PBRAIL = P1_1;   // set PBRAIL as P1.1 alias
int LPHOTO = P1_2;   // set LPHOTO as P1.2 alias
int RPHOTO = P1_7;   // set RPHOTO as P1.7 alias

int REDLED = P1_0;   // set REDLED as P1_0 alias
int GRNLED = P1_6;   // set GRNLED as P1_6 alias

void setup()
{ 
  
  // set power block pin and led pins as outputs
  pinMode(PBRAIL, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(GRNLED, OUTPUT);
  
  // set photocell input pins
  pinMode(LPHOTO, INPUT);
  pinMode(RPHOTO, INPUT);

}

void loop()
{
  digitalWrite(PBRAIL, HIGH);        // supply 3.3V to the power rail
  delayMicroseconds(1000);           // delay briefly to allow comparator outputs to settle

  if (digitalRead(LPHOTO) == HIGH)  // if LPHOTO is on, turn REDLED on
  {
     digitalWrite(REDLED, HIGH);     // otherwise, turn REDLED off
  }
  else
  {
     digitalWrite(REDLED, LOW);  
  }   
  if (digitalRead(RPHOTO) == HIGH)   // if RPHOTO is on, turn GRNLED on
  {
     digitalWrite(GRNLED, HIGH);     // otherwise, turn GRNLED off
  }
  else
  {
     digitalWrite(GRNLED, LOW);  
  }
  
  digitalWrite(PBRAIL, LOW);          // turn the power rail off again
  sleep(19);                          // wait 19 ms (can do other tasks in this time,
                                      // but we are simply demonstrating that you can cut power
                                      // to the circuits for 95% of the time and not notice!

}
