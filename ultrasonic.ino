#define utrigger 23 
#define uecho 22
#define buzzer 24
#define threshold 10
long duration,dis, cm;
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
void setup()
{
  Serial.begin(9600);
  pinMode(utrigger, OUTPUT);
  pinMode(uecho, INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ledPin,OUTPUT);
}
void loop()
{
  digitalWrite(utrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(utrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(utrigger, LOW);
  duration = pulseIn(uecho, HIGH);
  cm = microsecondsToCentimeters(duration);
  if(cm>=200)
    {}
   else
   {
     dis=cm;
     Serial.println(dis);
     if(dis<=threshold)
     {
        digitalWrite(buzzer, HIGH);       
        delay(1000);
        digitalWrite(buzzer, LOW);       
        delay(1000);
     }
   }
}

