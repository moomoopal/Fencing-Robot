int positiveLeftMotor = 3;
int negativeLeftMotor = 5;
int positiveRightMotor = 6;
int negativeRightMotor = 9;

void setup() {
  // put your setup code here, to run once:
  
  pinMode (positiveLeftMotor,OUTPUT);
  pinMode (negativeLeftMotor,OUTPUT);
  pinMode (positiveRightMotor,OUTPUT);
  pinMode (negativeRightMotor,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (positiveLeftMotor,HIGH);
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
}
