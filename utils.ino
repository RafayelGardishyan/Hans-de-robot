void CustomDelay(unsigned int milis)
{
  unsigned long currentMillis = 1;
  unsigned long previousMillis = millis();

  while(millis() - previousMillis < milis)
  {
    currentMillis++; 
  }
  return;    
}

void CustomMicroDelay(unsigned int microS)
{
  unsigned long currentMicros = 1;
  unsigned long previousMillis = micros();

  while(micros() - previousMillis < microS)
  {
    currentMicros++; 
  }
  return;    
}

void refreshMotors()
{
  int s1 = ls.GetValue(Mode::analog);
  int s2 = ls2.GetValue(Mode::analog); 
  int sf1 = lsf.GetValue(Mode::analog);
  int sf2 = lsf2.GetValue(Mode::analog); 
  
  if (s2 > 300){
    speed1 = 75 ;
    speed2 = 25;
  }

  if (s1 > 300){
    speed2 = 75;
    speed1 = 25;
  }

  if (s1 < 300 && s2 < 300){
    speed2 = 50;
    speed1 = 50;
  }

  if (sf2 > 275){
    speed1 = 125 ;
    speed2 = 25;
  }

  if (sf1 > 275){
    speed2 = 125;
    speed1 = 25;
  }
// Maybe stop if no options more left
//  if (sf1 > 300 && sf2 > 300){
//    speed2 = 0;
//    speed1 = 0;
//  }

  motors.setM1Speed(speed1);
  motors.setM2Speed(speed2);

}
