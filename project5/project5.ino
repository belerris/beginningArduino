byte led[] = {13,12,11,10,9,8,7,6};
byte ledDelay = 100;

void setup(){
  for (int x =0; x<10; x++){
    pinMode(led[x], OUTPUT);
  }
}

void loop(){
  digitalWrite(led[7],LOW);
  digitalWrite(led[0], HIGH);
  for (int x=1; x<7; x++){
    delay(ledDelay);
    digitalWrite(led[x-1], LOW);
    digitalWrite(led[x], HIGH);
    delay(ledDelay);
  }

  for (int x=7; x>=0; x--){
    delay(ledDelay);
    digitalWrite(led[x+1], LOW);
    digitalWrite(led[x], HIGH);
    delay(ledDelay);
  }
  
  
}
