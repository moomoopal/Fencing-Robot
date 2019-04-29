int startButton = 2;
int positiveLeftMotor = 3;
int negativeLeftMotor = 5;
int positiveRightMotor = 6;
int negativeRightMotor = 9;
int echo = 12;
int trigger = 13;

// DC Motor Car Functions
void moveLeftForward(int);
void moveRightForward(int);
void moveBothForward(int, int);
void moveLeftBackward(int);
void moveRightBackward(int);
void moveBothBackward(int, int); 
void moveBothForwardContinuously(int);
void rStopLeft();
void rStopRight();
void rStopBoth();
void moveHalfLeftForward();
void waitForButton();
int distanceMonitor();
void wallDetector();
void keepingDistance(int);

void setup() {
  // put your setup code here, to run once:
  pinMode (startButton, INPUT);
  pinMode (positiveLeftMotor,OUTPUT);
  pinMode (negativeLeftMotor,OUTPUT);
  pinMode (positiveRightMotor,OUTPUT);
  pinMode (negativeRightMotor,OUTPUT);
  pinMode (echo, INPUT);
  pinMode (trigger, OUTPUT);
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
void moveBothForwardContinuously(int pwr){
  moveLeftForward(pwr);
  //0.5 Voltage difference between the two motors, multiply by 100 and add to right (weaker) pwr to make the robot go straight
  moveRightForward(pwr+50);
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
void wallDetector(){
  long distance;
  waitForButton();

  while (1){
    
    distance = distanceMonitor();
    if (distance != 0) {
      Serial.println(distance);
    }
    else{
      //do nothing 
    }
    
    //1>= distance <=10
    if ((distance >=1)&&(distance <=35)){
      rStopBoth();
    }
    else{
      moveBothForwardContinuously(150);
    }
    
  }
}

void keepingDistance(int fencingDistance){
  long distance;
  waitForButton();

  while (1){
    
    distance = distanceMonitor();
    if (distance != 0) {
      Serial.println(distance);
    }
    else{
      //do nothing 
    }
    
    //1>= distance <=10
    if ((distance >=1)&&(distance <=35)){
      rStopBoth();
    }
    else{
      moveBothForwardContinuously(150);
    }
    
  }
}
void loop() {
  wallDetector();  
}

int distanceMonitor(){
  

  long distance;
  //send pulse
  digitalWrite (trigger, LOW);
  delayMicroseconds (2);
  digitalWrite (trigger, HIGH);
  delayMicroseconds (20);
  digitalWrite (trigger, LOW);

  //wait for pulse to come back
  distance = pulseIn(echo, HIGH);
  distance /= 59;
  return distance;
  
  
}
