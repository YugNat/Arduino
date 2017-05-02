
/* Utilisation du capteur Ultrason HC-SR04 */

// définition des broches utilisées 
int trig = 12; 
int echo = 11; 
long lecture_echo; 
long cm;
int ledVert = 2;
int ledJaune = 3;
int i = 0;

void setup() 
{ 
  pinMode(trig, OUTPUT); 
  digitalWrite(trig, LOW); 
  pinMode(echo, INPUT); 
  Serial.begin(9600); 
  pinMode(ledVert, OUTPUT);
  pinMode(ledJaune, OUTPUT);
}

void loop() 
{ 
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
  if (cm<30 && cm>25)
  {
    if (i>=4)
    {
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
