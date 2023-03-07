#include <Servo.h>
Servo s = Servo();
#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(4,3);

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT); 
  analogWrite(11, 200);
  analogWrite(5, 200);
  s.attach(8);
  Serial.begin(9600);


}

void loop() {

  int x = Serial.read();

  if (x == '1') {
    s.write(90);
    delay(300);
    int d = u.distanceRead();


    if (d > 10) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);

      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);

      delay(2000);

      digitalWrite(13, LOW);
      digitalWrite(12, LOW);

      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
    }

  }
  if (x == '2') {
    s.write(30);
    delay(300);
    int d = u.distanceRead();

    if (d > 10) {
      digitalWrite(10,HIGH);
      digitalWrite(9,LOW);
     
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);

      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);

      delay(2000);

      digitalWrite(13, LOW);
      digitalWrite(12, LOW);

      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
    }
    s.write(90);
  }
  if (x == '3') {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(2000);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  if (x == '4') {
    s.write(150);
    delay(300);
    int d = u.distanceRead();

    if (d > 10) {
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      delay(2000);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
    s.write(90);
  }

}
