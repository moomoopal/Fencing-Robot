int testi;
long counter;
long timeWaster;
long counterMax;

bool footOn;
bool kneeOn;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);  //Light - foot
  pinMode(3,INPUT);   //Button - foot
  pinMode(4,OUTPUT);  //Light - knee
  pinMode(7,INPUT);   //Button - knee

  footOn = false;
  kneeOn = false;
  counterMax = 0;

  Serial.begin(9600);
  testi = 0;
}

void processButton(){
  
  if (footOn==true) {
    // light is on
    if(digitalRead(3)==LOW){
      tone(5,440);
      delay(1000);
      noTone(5);
    }
    else{
      noTone(5);
    }
  }
  else {
    // light is off
    //for(timeWaster = 0; timeWaster<5; timeWaster++){
      noTone(5);
 //   }
    
  }

  if (kneeOn==true) {
    // light is on
    if(digitalRead(7)==LOW){
      tone(5,440);
      delay(1000);
      noTone(5);
    }
    else{
      noTone(5);
    }
  }
  else {
    // light is off
    //for(timeWaster = 0; timeWaster<2; timeWaster++){
      noTone(5);
 //   }
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //random(2) returns either 0(true) or 1(false)
  footOn = random(2);
  kneeOn = random(2);
  counterMax = random(15000,100000);
  
  digitalWrite(2,footOn);
  digitalWrite(4,kneeOn);
  
  for(counter=0; counter<counterMax; counter++){
    processButton(); 
  }
  
  
}
  

  //code below this line = buzzing
  
  
  

