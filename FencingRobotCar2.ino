#include <IRremote.h>
int receiver_pin = 7;  
IRrecv receiver(receiver_pin); 
decode_results output;

#define LMOTORADJ 33
#define RMOTORADJ 36
#define ONE 41565
#define TWO 25245
#define THREE 57885
#define FOUR 8925
#define FIVE 765
#define SIX 49725
#define SEVEN 57375
#define EIGHT 43095
#define NINE 36975
#define ZERO 39015
#define STAR 26775
#define HASHTAG 45135
#define UP 6375
#define LEFT 4335
#define RIGHT 23205
#define DOWN 19125
#define OK 14535
#define HOLD 65535

int startButton = 2;
int positiveLeftMotor = 5;
int negativeLeftMotor = 10;
int positiveRightMotor = 6;
int negativeRightMotor = 9;
int echo = 12;
int trigger = 13;
int runKeepingDistance = 0;

// DC Motor Car Functions
void moveLeftForward(int);
void moveRightForward(int);
void moveBothForward(int, int);
void moveLeftBackward(int);
void moveRightBackward(int);
void moveBothBackward(int, int); 
void moveBothForwardContinuously(int);
void moveBothBackwardContinuously(int);
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
  receiver.enableIRIn();
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
  //0.5 Voltage difference between the two motors, multiply by 100 and add to right (weaker) pwr to make the robot go straight
  moveRightForward(pwr+RMOTORADJ);
  delay(ms);
  rStopBoth();
  return;
}
//caliberated using 5.8 volts on DC driver
void moveBothForwardCm(int cm, int pwr) {
  int ms;
  float spd;
  if (pwr == 100){
    spd = 0.02;
    ms = cm/spd;
    moveLeftForward(pwr);
    //0.5 Voltage difference between the two motors, multiply by 100 and add to right (weaker) pwr to make the robot go straight
    moveRightForward(pwr+RMOTORADJ);
    delay(ms);
    rStopBoth(); 
  }
  else if(pwr == 162){
    spd = 0.027;
    ms = cm/spd;
    moveLeftForward(pwr);
    //0.5 Voltage difference between the two motors, multiply by 100 and add to right (weaker) pwr to make the robot go straight
    moveRightForward(pwr+RMOTORADJ);
    delay(ms);
    rStopBoth(); 
  }
  else if(pwr == 200){
    spd = 0.036;
    ms = cm/spd;
    moveLeftForward(pwr);
    //0.5 Voltage difference between the two motors, multiply by 100 and add to right (weaker) pwr to make the robot go straight
    moveRightForward(pwr+RMOTORADJ);
    delay(ms);
    rStopBoth();
    
  }
  
 
  return;
}
void moveBothBackwardCm(int cm, int pwr) {
  int ms;
  float spd;
  if (pwr == 100){
    spd = 0.02;
    ms = cm/spd;
    moveLeftBackward(pwr+LMOTORADJ);
    moveRightBackward(pwr);
    delay(ms);
    rStopBoth(); 
     
  }
  else if(pwr == 162){
    spd = 0.027;
    ms = cm/spd;
    moveLeftBackward(pwr+LMOTORADJ);
    moveRightBackward(pwr);
    delay(ms);
    rStopBoth(); 
  }
  else if(pwr == 200){
    spd = 0.036;
    ms = cm/spd;
    moveLeftBackward(pwr+LMOTORADJ);
    moveRightBackward(pwr);
    delay(ms);
    rStopBoth(); 
  }
  
 
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
void moveBothBackwardContinuously(int pwr){
  moveLeftBackward(pwr+LMOTORADJ);
  moveRightBackward(pwr);
  return;
}
void moveBothBackward(int ms, int pwr){
  moveLeftBackward(pwr+LMOTORADJ);
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
void processKeepingDistance(int fencingDistance){
    long distance;
    int spd = 200;
    long tolerance = 3;
    long delta;
   
    distance = distanceMonitor();
    delay(100);
    Serial.println(distance);
    delta = abs(distance - fencingDistance);
    if (delta > tolerance){
      //if the distance is far
      if (distance > fencingDistance){
        moveBothForwardCm(delta, spd);
      }
      //1>= distance <=10
      //if distance is close
      if ((distance >=1)&&(distance <= fencingDistance)){
        moveBothBackwardCm(delta, spd);
      }
      else{
        //if we see a 0, it stops
        rStopBoth();
      }
      
    }
    else{
      rStopBoth();
    }
}
void keepingDistance(int fencingDistance){
  long distance;
  int spd = 200;
  long tolerance = 3;
  long delta;
  waitForButton();
  
  while (1){
    
    distance = distanceMonitor();
    delay(100);
    Serial.println(distance);
    delta = abs(distance - fencingDistance);
    if (delta > tolerance){
      //if the distance is far
      if (distance > fencingDistance){
        moveBothForwardCm(delta, spd);
      }
      //1>= distance <=10
      //if distance is close
      if ((distance >=1)&&(distance <= fencingDistance)){
        moveBothBackwardCm(delta, spd);
      }
      else{
        //if we see a 0, it stops
        rStopBoth();
      }
      
    }
    else{
      rStopBoth();
    }
    
  }
}

void loop() {
  //waitForButton();
  //delay(1000);
  
  if (receiver.decode(&output)){
    unsigned int value = output.value;
    Serial.println(value);
    if (value == UP){
      //moveBothForwardContinuously(162);
      moveBothForwardContinuously(162);
    }
    if (value == DOWN){
      moveBothBackwardContinuously(162);
    }
    if (value == OK){
      rStopBoth();
    }
    if (value == LEFT){
      moveLeftForward(162);
      moveRightBackward(162);
      delay(1000);
      rStopLeft();
    }
    if (value == RIGHT){
      moveRightForward(162);
      moveLeftBackward(162);
      delay(1000);
      rStopRight();
    }
    if (value != HOLD){
      
      if (value == STAR){
        runKeepingDistance = 1;
      }
      else {
        runKeepingDistance = 0;
      }
      
    }

    receiver.resume();
    
  }
  if (runKeepingDistance == 1) {
      processKeepingDistance(15);

    }
  //Serial.println(runKeepingDistance);
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
