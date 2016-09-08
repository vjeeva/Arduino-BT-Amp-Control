#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;
int bluetoothTx = 10;
int bluetoothRx = 11;
bool ampOn = true;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo.attach(9);
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(2, OUTPUT);
}

void loop()
{
  if(bluetooth.available()> 0 )
  {
    byte servopos = bluetooth.read();
    Serial.write((int)servopos);
    if (((int) servopos) == 255){
      ampOn = !ampOn;
      if (ampOn){
        digitalWrite(2,1);
      } else {
        digitalWrite(2,0);
      }
    } else {
      myservo.write((int)servopos);
      Serial.write(" ");
    }
    delay(10);
  }
}
