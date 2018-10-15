int startButton = 2;
int positiveLeftMotor = 3;
int negativeLeftMotor = 5;
int positiveRightMotor = 6;
int negativeRightMotor = 9;

// DC Motor Car Functions
void moveLeftForward(int);
void moveRightForward(int);
void moveBothForward(int, int);
void moveLeftBackward(int);
void moveRightBackward(int);
void moveBothBackward(int, int); 
void rStopLeft();
void rStopRight();
void rStopBoth();
void moveHalfLeftForward();
void waitForButton();

void setup() {
  // put your setup code here, to run once:
  pinMode (startButton, INPUT);
  pinMode (positiveLeftMotor,OUTPUT);
  pinMode (negativeLeftMotor,OUTPUT);
  pinMode (positiveRightMotor,OUTPUT);
  pinMode (negativeRightMotor,OUTPUT);
  Serial.begin(9600);
}

void moveLeftForward(int pwr) {
  analogWrite (positiveLeftMotor,pwr);
  analogWrite (negativeLeftMotor, 0);
  return;
}

void moveRightForward(int pwr) {
  analogWrite (positiveRightMotor,pwr);
  analogWrite (negativeRightMotor,0);
  return;
}

void moveBothForward(int ms, int pwr) {
  moveLeftForward(pwr);
  moveRightForward(pwr);
  delay(ms);
  rStopBoth();
  return;
}

void moveLeftBackward(int pwr){
  analogWrite (positiveLeftMotor,0);
  analogWrite (negativeLeftMotor,pwr); 
  return;
}

void moveRightBackward(int pwr){
  analogWrite (positiveRightMotor,0);
  analogWrite (negativeRightMotor,pwr);
  return;
}

void moveBothBackward(int ms, int pwr){
  moveLeftBackward(pwr);
  moveRightBackward(pwr);
  delay(ms);
  rStopBoth();
  return;
}

void rStopLeft(){
  digitalWrite (positiveLeftMotor,LOW);
  digitalWrite (negativeLeftMotor,LOW);
  return;
}

void rStopRight(){
  digitalWrite (positiveRightMotor,LOW);
  digitalWrite (negativeRightMotor,LOW);
  return;
}

void rStopBoth(){
  rStopLeft();
  rStopRight();
  return;
}

void moveHalfLeftForward(){
  analogWrite (positiveLeftMotor, 80);
  analogWrite (negativeLeftMotor, 0);
}
void waitForButton(){
  int buttonPress;
  buttonPress = digitalRead(startButton);
  while (buttonPress == HIGH){
    //Serial.println(buttonPress); 
    buttonPress = digitalRead(startButton);
  }
  return;
}
void loop() {
  // put your main code here, to run repeatedly:
  waitForButton();
  moveBothForward(1000, 250);
  delay(1000);
  moveBothBackward(1000, 170);
  delay(1000);
  
  /*digitalWrite (positiveLeftMotor,HIGH);
  digitalWrite (negativeLeftMotor,LOW);
  delay(1000);
  digitalWrite (positiveLeftMotor,LOW);
  digitalWrite (negativeLeftMotor,LOW);
  delay(500);
  digitalWrite (positiveLeftMotor,LOW);
  digitalWrite (negativeLeftMotor,HIGH);
  delay(1000);
  digitalWrite (positiveLeftMotor,LOW);
  digitalWrite (negativeLeftMotor,LOW);
  delay(500);
  
  digitalWrite (positiveRightMotor,HIGH);
  digitalWrite (negativeRightMotor,LOW);
  delay(1000);
  digitalWrite (positiveRightMotor,HIGH);
  digitalWrite (negativeRightMotor,HIGH);
  delay(500);
  digitalWrite (positiveRightMotor,LOW);
  digitalWrite (negativeRightMotor,HIGH);
  delay(1000);
  digitalWrite (positiveRightMotor,HIGH);
  digitalWrite (negativeRightMotor,HIGH);
  delay(500);
  */

  
}
