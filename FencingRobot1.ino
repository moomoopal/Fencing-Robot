void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);

  digitalWrite(2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:


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
  
  


  

}
