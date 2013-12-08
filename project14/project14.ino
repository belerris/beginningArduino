int piezoPin = 8;
int ldrPin = 0;
int ldrValue = 0;

void setup(){
  //nothing here
}

void loop(){
  ldrValue = analogRead(ldrPin);
  tone(piezoPin, 200);
  delay(25);
  noTone(piezoPin);
  delay(ldrValue);
}

