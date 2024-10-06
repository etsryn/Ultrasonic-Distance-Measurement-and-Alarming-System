// Physical Setups
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
// Forth Used Variable Declrartion
long duration;
int distance;
int safetyDistance;
 
// Setting up the Physical Setups to the Code
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}
 
// To Execute the objective of this system
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 20) { // Distance regarded as non alarming is > 20 cm
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}