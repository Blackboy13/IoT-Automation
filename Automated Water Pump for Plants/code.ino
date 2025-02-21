int WATERPUMP = 13; 
int sensor = 8;
int val; 

void setup() {
  pinMode(13,OUTPUT); 
  pinMode(8,INPUT); 
  Serial.begin(9600); 
  while (! Serial)
  Serial.println("Speed 0 to 255");
}

void loop()
  { 
  if (Serial.available()) {
    int speed = Serial.parseInt(); 
    if (speed >= 0 && speed <= 255){
      analogWrite(WATERPUMP, speed 
    }
  }
  val = digitalRead(8);   
  if(val == LOW) {
  digitalWrite(13,LOW); 
  }
  else{
  digitalWrite(13,HIGH);
  }
  delay(400); 
}
