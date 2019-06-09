#include <Servo.h>
#define LEVEL 4
#define BICEPUP 180
#define BICEPDOWN 30
#define BICEPMIDDLE 90

#define FOREARMEXTEND 0
#define FOREARMWITHDRAW 90
#define FOREARMENGARDE 70

#define SWORDCCW 180
#define SWORDHALFCCW 135
#define SWORDSLOWCCW 110
#define SWORDSTOP 90
#define SWORDHALFCW 45
#define SWORDSLOWCW 70
#define SWORDCW 0

Servo bicep;
Servo forearm;
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
}
void extend(){
  bicep.write(BICEPMIDDLE);
  forearm.write(FOREARMEXTEND);
}
void highline(){
  
}

void defenseCircle6(int duration){
  bicep.write(BICEPDOWN);
  forearm.write(120);
  sword.write(SWORDCCW);
  delay(duration);
  sword.write(SWORDSTOP);
}

void defenseCircle4(int duration){
  bicep.write(BICEPDOWN);
  forearm.write(120);
  sword.write(SWORDCW);
  delay(duration);
  sword.write(SWORDSTOP);
}

void defenseCircle8(int duration){
  bicep.write(BICEPDOWN);
  forearm.write(30);
  sword.write(SWORDCW);
  delay(duration);
  sword.write(SWORDSTOP);
}

void defenseCircle7(int duration){
  bicep.write(BICEPDOWN);
  forearm.write(30);
  sword.write(SWORDCCW);
  delay(duration);
  sword.write(SWORDSTOP);
}

void loop() {
  // put your main code here, to run repeatedly:
  defenseCircle8(2000);
  defenseCircle6(2000);
  defenseCircle7(2000);
  defenseCircle4(2000);

  
  
  //random(2) returns either 0(true) or 1(false)
  footOn = random(2);
  kneeOn = random(2);
  chestOn = random(2);
  //bicep.write(random(0,91));
  //forearm.write(random(0,181));
  
  
  counterMax = random(15000/gameLevel,100000/gameLevel);
  
  digitalWrite(footLightPin,footOn);
  digitalWrite(kneeLightPin,kneeOn);
  digitalWrite(chestLightPin,chestOn);
  
  for(counter=0; counter<counterMax; counter++){
    processButton(); 
  }
  
}
  

  //code below this line = buzzing
  
  
  
