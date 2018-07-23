#define LEVEL 4

long counter;
long counterMax;

bool footOn;
bool kneeOn;
bool chestOn;

int footLightPin = 2;
int footButtonPin = 3;
int kneeLightPin = 4;
int buzzerPin = 5;
int kneeButtonPin = 7;
int chestLightPin = 8;
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
        slows down the processing time 
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

void loop() {
  // put your main code here, to run repeatedly:
  
  
  //random(2) returns either 0(true) or 1(false)
  footOn = random(2);
  kneeOn = random(2);
  chestOn = random(2);

  counterMax = random(15000/gameLevel,100000/gameLevel);
  
  digitalWrite(footLightPin,footOn);
  digitalWrite(kneeLightPin,kneeOn);
  digitalWrite(chestLightPin,chestOn);
  
  for(counter=0; counter<counterMax; counter++){
    processButton(); 
  }
  
}
  

  //code below this line = buzzing
  
  
  

