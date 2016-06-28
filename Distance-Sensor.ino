/*  This project uses the built in example "Ping" that is distributed with the Arduino IDE.
    The Ping example sketch was created on Nov 3 2008 by David A Mellis. A further modification of the sketch was made Aug 30 2011 by Tom Igoe.
    The original code can be found at http://www.arduino.cc/en/Tutorial/Ping

    This project featured in Linux Voice magazine

    This example code is in the public domain.
*/

const int pingPin = 12;
const int time = 10;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);  
  pinMode(11, OUTPUT);  
}

void loop() {
  long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm < 5){
    Serial.print("Less than 5CM");
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    delay(time);
  }
  else if (cm < 10 && cm > 5){
    Serial.print("Less than 10CM");
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    delay(time);
  }
  else if (cm < 15 && cm > 10){
    Serial.print("Less than 15CM");
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(time);
 }
  else if (cm < 20 && cm > 15){
    Serial.print("Less than 20CM");
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    delay(time);
  }
  else if (cm < 30 && cm > 20){
    Serial.print("Less than 30CM");
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    delay(time);               
  } else {
    Serial.print("Greater than 20CM");
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    delay(time);
  }
  //}
  

  delay(100);
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
