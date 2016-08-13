#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;
int bluetoothTx = 10;
int bluetoothRx = 11;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo.attach(9);
  Serial.begin(115200);
  bluetooth.begin(9600);
}

void loop()
{
  Serial.println("Hi");
  if (Serial.available() > 0){
    //Serial.println("Hi");
    //myservo.write(Serial.read());
  }
  if(bluetooth.available()> 0 )
  {
    //int servopos = bluetooth.read();
    //Serial.println(servopos);
    //myservo.write(servopos);
  
  }
}
