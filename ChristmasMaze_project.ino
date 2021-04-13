#include <Servo.h>

int  servo_Pin_x = 3;
int  servo_Pin_y = 6;

int  joy_x_pin = A0;
int  joy_y_pin = A7;

float  x_Servo_Movement;
float  y_Servo_Movement;

Servo Servo_1;
Servo Servo_2;

int x_Val;
int y_Val;

void setup()
{

  Serial.begin(9600);

  Servo_1.attach(servo_Pin_x);      
  Servo_2.attach(servo_Pin_y);

  pinMode(A0, INPUT);
  pinMode(A7, INPUT);
}
void loop()
{
  x_Val = analogRead(joy_x_pin);
  Serial.println(x_Val);

  y_Val = analogRead(joy_y_pin);
  Serial.println(y_Val);

  x_Servo_Movement = 75 + 0.0391 * x_Val;
  Serial.println(x_Servo_Movement);
  Servo_1.write(x_Servo_Movement);

  y_Servo_Movement = 75 + 0.0391 * y_Val;
  Serial.println(y_Servo_Movement);
  Servo_2.write(y_Servo_Movement);
  Serial.println("###########################################");
  //Servo_1.write(0);
  delay(100);
  //Servo_2.write(0);
}
