void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);  
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(7,INPUT);
}

void processButton(){
  
  if (digitalRead(2)==HIGH) {
    // light is on
    if(digitalRead(3)==LOW){
      tone(5,440);
      delay(1000);
      digitalWrite(2,LOW);
      noTone(5);
    }
    else{
      noTone(5);
    }
  }
  else {
    // light is off
  }

  if (digitalRead(4)==HIGH) {
    // light is on
    if(digitalRead(7)==LOW){
      tone(5,440);
      delay(1000);
      digitalWrite(4,LOW);
      noTone(5);
    }
    else{
      noTone(5);
    }
  }
  else {
    // light is off
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //light combination

  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
  for(int i=0; i<15151; i++){
    processButton(); 
  }
  digitalWrite(2,LOW);
  for(int i=0; i<15151; i++){
    processButton(); 
  }
  
  
  
  }
  

  //code below this line = buzzing
  
  
  

