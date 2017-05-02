  // définition des broches utilisées 
  int trig = 12; 
  int echo = 11; 
  long lecture_echo; 
  long cm;
  int ledVert = 2;
  int ledJaune = 3;
  int i = 0;
  int photocellPin1 = 0;
  int photocellPin2 = 1;
  int photocellReading1;
  int photocellReading2;

void setup() {
  pinMode(trig, OUTPUT); 
  digitalWrite(trig, LOW); 
  pinMode(echo, INPUT); 
  Serial.begin(9600); 
  pinMode(ledVert, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  blink();
}

void blink ()
{
  for (i; i<10; i++)
  {
    digitalWrite(ledVert, HIGH);
    digitalWrite(ledJaune, LOW);
    delay(100);
    digitalWrite(ledVert, LOW);
    digitalWrite(ledJaune, HIGH);
    delay(100);
  }
}

void loop() 
{
  photocellReading1 = analogRead(photocellPin1);
  photocellReading2 = analogRead(photocellPin2);
  Serial.print("PhotoCell_1 = ");
  Serial.println(photocellReading1);
  Serial.print("PhotoCell_2 = ");
  Serial.println(photocellReading2); 
  digitalWrite(ledVert, HIGH);
  digitalWrite(ledJaune, LOW);
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  lecture_echo = pulseIn(echo, HIGH); 
  cm = lecture_echo / 58; 
  Serial.print("Distancem : "); 
  Serial.println(cm);
  digitalWrite(ledVert, LOW); 
  if (cm<20 && cm>15 && photocellReading1>1000 && photocellReading2<100)
  {
    if (i>=4)
    {
      blink();
      digitalWrite(ledVert, HIGH);
      digitalWrite(ledJaune, HIGH);
      Serial.println("OK");
      delay(6000);
    }
    i++;
    digitalWrite(ledJaune, HIGH);
  }
  else
  {
    i=0;
  }
  delay(1000);
}
