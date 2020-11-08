#define trig 12
#define echo 11
#define PWM 6

 
void setup() {
  Serial.begin (9600);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(PWM, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8,OUTPUT);
}
 
void loop() {
  long distance, pulseTime;
  float Kp = 2;
  float valueSet = 100;
  float error;
  int valuePWM;
 
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  pulseTime = pulseIn(echoPin, HIGH);
  distance = pulseTime / 58;
  
 error = valueSet - distance;
 valuePWM = Kp * error;


 if(valuePWM >255)
    valuePWM = 255;
 else if(valuePWM < -255)
    valuePWM = -255;


if(valuePWM > 0) {
    analogWrite(PWM,valuePWM);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
}

else if(valuePWM<0){
    analogWrite(PWM, abs(valuePWM);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
}

else{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
 
  delay(50);
}
