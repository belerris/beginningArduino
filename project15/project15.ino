int potPin = 0;
int transistorPin = 9;
int potValue = 0;

void setup(){
  pinMode(transistorPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  potValue = analogRead(potPin) / 4;
  analogWrite(transistorPin, potValue);
  Serial.println(potValue);
}

