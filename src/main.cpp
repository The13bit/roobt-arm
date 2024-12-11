#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

#define VRX_PIN A1
#define VRY_PIN A0
#define Hand_pivot A2
Servo s1;
Servo s2;
Servo s3;
Servo s4;
int xValue = 0;
int yValue = 0;
int pivVal = 0;
int switchBtn = 6;
bool isPress = false;

int base = 2;
int pivot = 3;
int lift = 4;
int grab = 5;
void setup()
{
  Serial.begin(9600);
  pinMode(switchBtn, INPUT_PULLUP);
  s1.attach(base);
  s2.attach(pivot);
  s3.attach(lift);
  s4.attach(grab);
}

void loop()
{
  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  pivVal = analogRead(Hand_pivot);

  isPress = digitalRead(switchBtn);

  xValue = map(xValue, 0, 1023, 0, 179);
  yValue = map(yValue, 0, 1023, 0, 179);
  pivVal = map(pivVal, 0, 1023, 0, 90);
  // Serial.println(angleToPulse(xValue));
  Serial.println(xValue);
  Serial.println(yValue); 
  Serial.println(pivVal);
  Serial.println(isPress);

  s1.write(xValue);
  delay(500);
  s2.write(pivVal);
  delay(500);
  s3.write(yValue);
  delay(500);
  //
  if (isPress)
  {
    s4.write(0);
  }
  else
  {
    s4.write(0);
  }
}
