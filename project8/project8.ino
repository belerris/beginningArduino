float RGB1[3];
float RGB2[3];
float INC[2];

int red, green, blue;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup(){
  randomSeed(analogRead(0));
  
  RGB1[0] = 0;
  RGB1[1] = 0;
  RGB1[2] = 0;
  
  RGB2[0] = random(256);
  RGB2[1] = random(256);
  RGB2[2] = random(256);
}

void loop(){
  randomSeed(analogRead(0));
  
  for (int x=0; x<3; x++){
    INC[x] = (RGB1[x] - RGB2[x]) /256;
  }
  
  for (int x=0; x<256; x++){
    red = int(RGB1[0]);
    blue = int(RGB1[2]);
    green = int(RGB1[1]);
    
    
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
    delay(10);
    
    RGB1[0] -= INC[0];
    RGB1[1] -= INC[1];
    RGB1[2] -= INC[2];
  }
  
  for (int x=0; x<3; x++){
    RGB2[x] = random(556) - 300;
    RGB2[x] = constrain(RGB2[x], 0, 255);
    delay(10);
  }
}

