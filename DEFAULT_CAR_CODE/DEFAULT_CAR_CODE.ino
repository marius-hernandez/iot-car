/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

//Right motor
int enableRightMotor=22; 
int motor1_dir1=18;
int motor1_dir2=19;
//Left motor
int enableLeftMotor=23;
int motor2_dir1=16;
int motor2_dir2=17;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("MyEsp32");       //set bluetooth name of your device
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");

 // put your main code here, to run repeatedly:
  Dabble.processInput();
  if (GamePad.isUpPressed())
    {
      Serial.print("UP");
      forward();
    }

  else if (GamePad.isDownPressed())
    {
      Serial.print("DOWN");
      backward();
    }

  else  if (GamePad.isLeftPressed())
    {
      Serial.print("Left");
      left();
    }

  else  if (GamePad.isRightPressed())
    {
      Serial.print("Right");
      right();
    }

  else 
    {
    Serial.println("strop");
    Stop();
    }
}

void forward()
     {
        // analogWrite(motor1_en,255);
        // analogWrite(motor2_en,255);
        digitalWrite(motor1_dir1,HIGH);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,HIGH);
        digitalWrite(motor2_dir2,LOW);
      
     }
     void backward()
     {
        // analogWrite(motor1_en,255);
        // analogWrite(motor2_en,255);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,HIGH);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,HIGH);
      
     }
     void left()
     {
        // analogWrite(motor1_en,255);
        // analogWrite(motor2_en,255);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,HIGH);
        digitalWrite(motor2_dir1,HIGH);
        digitalWrite(motor2_dir2,LOW);
      
     }
     void right()
     {
        // analogWrite(motor1_en,255);
        // analogWrite(motor2_en,255);
        digitalWrite(motor1_dir1,HIGH);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,HIGH);
      
     }
     void Stop()
     {
        // analogWrite(motor1_en,0);
        // analogWrite(motor2_en,0);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,LOW);
     }