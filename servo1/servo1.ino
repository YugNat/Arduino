#include <Servo.h>
 
Servo monServo;  
 
const char AN_POTENTIOMETRE = 0;  
const char PWM_SERVO = 9;   

int positionDuServo = 45;
 
void setup()
{
  monServo.attach(9);
  monServo.write(positionDuServo);
}
 
void loop()
{
  for(positionDuServo = 45; positionDuServo <= 145; positionDuServo++)
  {
    monServo.write(positionDuServo);
    delay(15);                        
  }
  for(positionDuServo = 145; positionDuServo>=45; positionDuServo--)
  {
    monServo.write(positionDuServo);
    delay(15);
  }
}
