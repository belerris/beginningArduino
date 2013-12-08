#define switchPin 2 //switch input
#define motorPin1 3 // L293D Input 1
#define motorPin2 4 //L293D Input 2
#define speedPin 9 //L293D enable Pin 1
#define potPin 0 // Potentiometer on Analog Pin 0

int Mspeed = 0; //variable to hold the current speed value

void setup(){
  //set switch pin as INPUT
  pinMode(switchPin, INPUT);
  // set remaining pins as OUTPUTs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(speedPin, OUTPUT);
}

void loop(){
  Mspeed = analogRead(potPin)/4; // read the speed value from the potentiometer
  analogWrite(speedPin, Mspeed); // write speed to enable 1 pin
  if (digitalRead(switchPin)){ // if switch is high rotate motor clockwise
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }
  else{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
}

