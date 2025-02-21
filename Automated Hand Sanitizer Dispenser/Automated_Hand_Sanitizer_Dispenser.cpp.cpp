
#include<LiquidCrystal.h>
#include<Servo.h>
#define pinServo 10
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo S1;
int degree = 0;
long cm=0;
unsigned char count = 0;
long sensordistance2 (int triggerMotion2, int echoMotion2)
{
  
  pinMode(triggerMotion2, OUTPUT);   
  digitalWrite(triggerMotion2, LOW); 
  delayMicroseconds(2);
  digitalWrite(triggerMotion2, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerMotion2, LOW);
  pinMode(echoMotion2, INPUT);        
  return (pulseIn(echoMotion2, HIGH)*0.01723);
}

long sensordistance (int triggerMotion, int echoMotion)
{
 
  pinMode(triggerMotion, OUTPUT);       
  digitalWrite(triggerMotion, LOW);      
  delayMicroseconds(2);
  digitalWrite(triggerMotion, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerMotion, LOW);
  pinMode(echoMotion, INPUT);            
  return (pulseIn(echoMotion, HIGH)*0.01723);
}


void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Beware of");
  delay(500);
  lcd.setCursor(5,1);
  lcd.print("CORONA!");
  delay(1500);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Stay Safe");
  delay(2500);
  lcd.clear();
  lcd.print("Wash Hands Regularly");
  pinMode(13,OUTPUT);
  S1.attach(pinServo);
  Serial.begin(9600);
  S1.write(0);
  delay(1000);
  pinMode(10,OUTPUT);
}

void loop()
{
  for (int i = 0; i < 13; i++) {
   lcd.scrollDisplayLeft();
    delay(500);
  }
  lcd.clear();
  cm = sensordistance (9,8);  
  if (cm > 20)
  {
    cm = sensordistance(5,4);
    Serial.print(cm);
    Serial.println("cm");
    if(cm > 180)
    {
      digitalWrite(10,LOW);     
      S1.write(0);
    }
    if(cm < 180)
    {
  
      lcd.begin(16,2);
      digitalWrite(10, HIGH);    
      S1.write(60);
      lcd.setCursor(4,0);
      lcd.print("Welcome!!");
      digitalWrite(13,HIGH);
      delay(1000);
      digitalWrite(13,LOW);
      lcd.clear();
      delay(500);
      S1.write(0);
      delay(500); 
    }
     delay(100);
  }
  else;              
  {
    digitalWrite(10, LOW);
    S1.write(0);
  }
}
 
