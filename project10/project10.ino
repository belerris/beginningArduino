char buffer[18];
int red, green, blue;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup(){
  Serial.begin(9600);
  Serial.flush();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  if (Serial.available() > 0){
    int index = 0;
    delay(100); //let the buffer fill up
    int numChar = Serial.available();
    if (numChar > 15){
      numChar = 15;
    }
    while (numChar--){
      buffer[index++] = Serial.read();
    }
    splitString(buffer);
  }
}

void splitString(char* data){
  Serial.print("Data Entered: ");
  Serial.println(data);
  char* parameter;
  parameter = strtok (data, " ,");
  while(parameter != NULL){
    setLED(parameter);
    parameter = strtok (NULL, " ,");
  }
  //Clear the text and serial buffers
  for (int x=0; x<16; x++){
    buffer[x] = '\0';
  }
  Serial.flush();
  
}

void setLED(char* data){
  if ((data[0] == 'r') || (data[0] == 'R')){
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(redPin, Ans);
    Serial.print("Red is set to: ");
    Serial.println(Ans);
  }
  if ((data[0] == 'g') || (data[0] == 'G')){
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(greenPin, Ans);
    Serial.print("Green is set to: ");
    Serial.println(Ans);
  }
  if ((data[0] == 'b') || (data[0] == 'B')){
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(bluePin, Ans);
    Serial.print("Blue is set to: ");
    Serial.println(Ans);
  }
}

  
