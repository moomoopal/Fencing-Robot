#include <Servo.h>
#define LEVEL 4
#define BICEPUP 180
#define BICEPDOWN 40
#define BICEPMIDDLE 90

#define FOREARMEXTEND 20
#define FOREARMWITHDRAW 90
#define FOREARMENGARDE 70

#define ELBOWMAX 110
#define ELBOWEXTEND 40

#define SWORDCCW 180
#define SWORDHALFCCW 135
#define SWORDSLOWCCW 110
#define SWORDSTOP 90
#define SWORDHALFCW 45
#define SWORDSLOWCW 70
#define SWORDCW 0

Servo bicep;
Servo forearm;
Servo elbow;
Servo sword;

long counter;
long counterMax;

bool footOn;
bool kneeOn;
bool chestOn;

int footLightPin = 2;
int footButtonPin = 3;
int kneeLightPin = 4;
int buzzerPin = 5;
int bicepMotorPin = 6;
int kneeButtonPin = 7;
int chestLightPin = 8;
int forearmMotorPin = 9;
int swordMotorPin = 10;
int elbowMotorPin = 11;
int chestButtonPin = 12;
int gameLevel = LEVEL;

void setup() {
  // put your setup code here, to run once:
  pinMode(footLightPin,OUTPUT);  //Light - foot
  pinMode(footButtonPin,INPUT);   //Button - foot
  pinMode(kneeLightPin,OUTPUT);  //Light - knee
  pinMode(kneeButtonPin,INPUT);   //Button - knee
  pinMode(chestLightPin,OUTPUT);  //Light - chest
  pinMode(chestButtonPin,INPUT);  //Button - chest
  bicep.attach(bicepMotorPin);
  forearm.attach(forearmMotorPin);
  elbow.attach(elbowMotorPin);
  sword.attach(swordMotorPin);

  footOn = false;
  kneeOn = false;
  chestOn = false;
  counterMax = 0;

  Serial.begin(9600);
  
}

void processButton(){
  
  if (footOn) {
    // light is on
    if(digitalRead(footButtonPin)==LOW){
      tone(buzzerPin,440);
      delay(1000);
      noTone(buzzerPin);
    }
    else{
      noTone(buzzerPin);
    }
  }
  else {
     /* 
        this noTone command is neccessary to 
        slow down the processing time 
        when the light is off so that is matches 
        the processing time when light is on
      */
      noTone(buzzerPin);
  }

  if (kneeOn) {
    // light is on
    if(digitalRead(kneeButtonPin)==LOW){
      tone(buzzerPin,440);
      delay(1000);
      noTone(buzzerPin);
    }
    else{
      noTone(buzzerPin);
    }
  }
  else {
    /* 
        this noTone command is neccessary to 
        slows down the processing time 
        when the light is off so that is matches 
        the processing time when light is on
      */
    noTone(buzzerPin);

  }

  if (chestOn) {
    // light is on
    if(digitalRead(chestButtonPin)==LOW){
      tone(buzzerPin,440);
      delay(1000);
      noTone(buzzerPin);
    }
    else{
      noTone(buzzerPin);
    }
  }
  else {
    /* 
        this noTone command is neccessary to 
        slows down the processing time 
        when the light is off so that is matches 
        the processing time when light is on
      */
    noTone(buzzerPin);

  }

  
  
}
void enGarde(){
  bicep.write(BICEPDOWN);
  forearm.write(FOREARMENGARDE);
  elbow.write(ELBOWEXTEND);
  
}
void extend(){
  bicep.write(BICEPMIDDLE);
  forearm.write(FOREARMEXTEND);
  elbow.write(ELBOWEXTEND);
}
void highline(){
  
}
void defense6(){
  bicep.write(50);
  forearm.write(FOREARMENGARDE);
  elbow.write(50);
}

void defense4(){
  bicep.write(50);
  forearm.write(FOREARMENGARDE);
  elbow.write(60);
}

void defense8(){
  bicep.write(BICEPDOWN);
  forearm.write(20);
  elbow.write(60);
}

void defense7(){
  bicep.write(BICEPDOWN);
  forearm.write(20);
  elbow.write(70);
}
void defenseCircle6(int duration){
  defense6();
  sword.write(SWORDCCW);
  delay(duration);
  sword.write(SWORDSTOP);
}

void defenseCircle4(int duration){
  defense4();
  sword.write(SWORDCW);
  delay(duration);
  sword.write(SWORDSTOP);
}

void defenseCircle8(int duration){
  defense8();
  sword.write(SWORDCW);
  delay(duration);
  sword.write(SWORDSTOP);
}

void defenseCircle7(int duration){
  defense7();
  sword.write(SWORDCCW);
  delay(duration);
  sword.write(SWORDSTOP);
}

void testRoutine(){
  enGarde();
  delay(1000);
  extend();
  delay(1000);
  defenseCircle8(1000);
  defenseCircle7(1000);
  defense4();
  delay(1000);
  defenseCircle4(1000);
  defenseCircle6(1000);
  defense8();
  delay(1000);
  defense7();
  delay(1000);
  defense6();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
  
  //random(2) returns either 0(false) or 1(true)
  footOn = random(2);
  kneeOn = random(2);
  chestOn = random(2);
  
  if (footOn == true){
    kneeOn = false;
    chestOn = false;
    defense8();
  }
  if (kneeOn == true){
    chestOn = false;
    footOn = false;
    defense7();
  }
  if (chestOn ==true){
    footOn = false;
    kneeOn = false;
    defense6();
  }
  if ((footOn == false) && (kneeOn == false) && (chestOn == false)){
    extend();
  }
  counterMax = random(15000/gameLevel,100000/gameLevel);
  
  digitalWrite(footLightPin,footOn);
  digitalWrite(kneeLightPin,kneeOn);
  digitalWrite(chestLightPin,chestOn);
  
  for(counter=0; counter<counterMax; counter++){
    processButton(); 
  }
  
}
  

  //code below this line = buzzing
  
  
  
