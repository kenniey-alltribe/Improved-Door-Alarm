const int buzzer=8, echo=9, trig=10, red=5, blue=6, fan=11;
long duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //clear the trigpin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  //settrippin high for 10ms
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  //Distance Calculations
  duration = pulseIn(echo, HIGH);
  distance = duration*0.34/2;

  if (distance < 100){
    digitalWrite(blue, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(fan, LOW);
    delay(10);
  }else if(distance > 100) {
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(fan, HIGH);
    tone(buzzer, 10000, 100);
    delay(10);
   }
   Serial.print("Distance :");
   Serial.println(distance);
}
