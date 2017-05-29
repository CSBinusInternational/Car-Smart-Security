# Car Smart Alarm Security Report

Welcome to our's open source Security system for your car.

![System Sketch](images/sketch.png)

## Getting Started

Arduino Smart Car System




Group 6
Project Report



By:
Andrianus Nadaek - 183443123
Ferick Andrew - 188763477
Mochammad Farhan Ghiffary - 1801434733


COMP6124 - Pervasive Computing
Class 2016/2017
Computer Science Program
BINUS International
Jakarta
 

PROJECT DESCRIPTIONS (MIN 3 PARAGRAPHS , 300 WORDS, INCLUDE SETTING AND PROBLEM HERE)
In this project, we are going to develop Mini tech-usable module which aims to alert the users or owner if there is suspicious movement inside the car. As human being we have been always carrying stuff that makes us fulfilled throughout the day of our life whether it is our phone, laptop , grocery stuff , camera and many else that leave behind in our car. yet, sometimes, we are reckless of thinking what we have brought and forgotten as if we don’t care about them. Speaking of which, as we go through what is yet to come, we found the modules that are suitable for us. 
We are using Arduino Uno R3 which is microcontroller board. It has 14 digital input/outputs, 6 analog inputs, reset button, power jack, ICSP header and USB connection to connect the microcontroller to Arduino software where all codes will be written and uploaded it to the board towards rest of module connected with the help of breadboard as well. Furthermore, PIR sensor is set to catch detection whether there is some movement and also the role of buzzer and LED is needed to make it complete of what our project is going to be. PIR sensor will get reaction from outsider action and will make the buzzer and LED to beep after motion is done. 
However, Our main goal is to dig the issue out to user in order to keep their possessions attended safely. Occasionally, whether we are being rush or do not care about them, those stuff are potential to be robbed by anonymous person while we are out of range from our car. Moreover, nowadays, robber becomes intelligent to steal without having known by surrounding, so they can sneakily take them and calmly run away as if they are innocent people. Therefore, we believe in this pivotal unforeseen circumstance, we could reduce threats that comprehend with our purposes and modules collected. 

COMPONENTS REQUIRED (INCLUDE THE QUANTITIY OF EACH COMPONENT)
The components required for this project are as follows
•	(1x) Arduino Uno R3
•	(1x) PIR Sensor HC-SR501
•	(1x) Buzzer Active Module KY-102
•	(1x) LCD 1602 Blue
•	() Jumper Male-male
•	() Jumper Male-Female
•	(1x) Red Light
•	(1x) Yellow Light
•	(5x) Resistor 100 Ohm 1/4W
•	(1x) Trimpot/Potentiometer 10K Ohm
•	(1x) Breadboard MB-102 830 Holes

HOW DOES IT WORK? (MIN 3 PARAGRAPHS , 300 WORD, INCLUDE YOUR DESIGN DESCRIPTIONS)
To overcome the issue, we are going to make smart car system to notify and monitor the car if there is suspicious action happened near them. Our system will be put as hidden as possible to minimize breaches and our system’s destruction by the robber.
HC-SR501 module will stay on input mode whilst it is not running in red mode (any motion detection). The LCD 16x2 will be used for a field monitoring, and should be hidden. Additionally we use one yellow LED and one red LED for a secondary monitoring. First the HC-SR501 or the PIR sensor module will keep tracks for any kind of movement, we also set the delay to be as minimum as possible and a medium for sensitivity. This sensor is the most important part in your system, since this will track any suspicious movement that is detecting. And to alert nearby, we are also using an active buzzer module KY-102, that supposed to beep with a short interlude. This module is not the loudest but at we don’t want to disturb peoples that is way too far from the car. All the alerts will stay on for around from at minimum 2 minutes and up to 5 minutes maximum, but for a display purpose, we will set it for only a couple of seconds. All of the components except for the sensor will be obscured.
Couple of drawbacks is probably from the sensor itself that is not a super sensitive and fast enough yet. And the other one is the power source, our kind of IoT or pervasive systems needs power all the time, but rather than having it to be powered from the car main, we might need a bigger and a longer-lasting battery for it to stay powered on. We can choose to use the car main, but that can be wasteful.


CIRCUIT DIAGRAM
Connect the LCD (16x2) module to the Arduino as follows:
•	Pin 1 VSS (GND) on the LCD to Ground on the Arduino
•	Pin 2 VDD on the LCD to the 5V on the Arduino.
•	Pin 3 VE (Contrast) on the LCD to the middle pin on the 10K potentiometer.
•	Pin 4 RE on the LCD to digital pin 12 on the Arduino.
•	Pin 5 R/W on the LCD to the ground of Arduino. This will put the LCD in read mode.
•	Pin 6 Enable on the LCD to the pin 11 of Arduino.
•	Connect the data pins (D4-D7) on the LCD to the pins 5, 4, 3, 2 on the Arduino.
•	Pin 15 (Anode) on the LCD to the 5V pin on the Arduino through 220-ohm resistor. This is the positive pin of the backlight.
•	Pin 16 (Cathode) on the LCD to the ground on the Arduino. This is the negative pin of the backlight.
Then we connect the 10K-ohm Potentiometer module to the Arduino as follows:
•	Left Pin (3.3V) on the Potentiometer to the 5V on the Arduino. You can also use 3V3 pin on the Arduino.
•	Middle Pin (A2) on the Potentiometer to the Pin 3 VE (Contrast) on the LCD.
•	Right Pin (AGND) on the Potentiometer to the Ground on the Arduino.
Afterwards we connect the HC-SR501 PIR Sensor module to the Arduino as follows:
•	Pin GND on the PIR sensor to the Ground on the Arduino
•	Pin OUT on the PIR sensor to the pin 7 on the Arduino through 200-ohm resistor.
•	Pin VCC on the PIR sensor to the 5V pin on the Arduino.
Next we connect the Red and Yellow LED modules to the Arduino as follows:
•	Long leg on the Red LED to the pin 13 on the Arduino through 220-ohm resistor.
•	Long leg on the Yellow LED to the pin 9 on the Arduino through 220-ohm resistor.
•	Short leg on both Red and Yellow LED to the Ground on the Arduino.
Finally, connect the KY-102 Active Buzzer module to the Arduino as follows:
•	Pin S (Positive) on the Buzzer to the Ground on the Arduino through 220-ohm resistor.
•	Pin – (Negative) on the Buzzer to the pin 10 on the Arduino.

Here are the complete fritz schematics for a complete reference:
 




PROJECT CODING:
{PUT YOUR GITHUB LINK HERE}

#include <LiquidCrystal.h>

int redLedPin = 13;        // choose the pin for the LED
int yellowLedPin = 9;
int inputPin = 7;       // choose the input pin (for PIR sensor)
int pirState = LOW;     // we start, assuming no motion detected
int val = 0;            // variable for reading the pin status
int pinSpeaker = 10;    // Set up a speaker on a PWM pin (digital 9, 10, or 11)
int counter = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(redLedPin, OUTPUT);      // declare LED as output
  pinMode(yellowLedPin, OUTPUT);
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(pinSpeaker, OUTPUT);

  digitalWrite(redLedPin, HIGH);
  digitalWrite(yellowLedPin, HIGH);
  
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.setCursor(3, 0);                      // Set LCD cursor position (column, row)
  lcd.print("Car Alarm");                   // Print text to LCD
  lcd.setCursor(3, 1);                      // Set LCD cursor position (column,row)
  lcd.print("Security");                    // Print text to LCD
  delay(4000);      // wait 5s              // Delay to read text

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motion Detection");
  lcd.setCursor(0, 1);
  lcd.print("With PIR Sensor");
  delay(3000);

  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Calibrating");
  lcd.setCursor(3, 1);
  lcd.print("Sensor ...");
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Waiting for");
  lcd.setCursor(2, 1);
  lcd.print("Motion....");
}

void loop()
{
  val = digitalRead(inputPin);        // read input value
  
  if (val == HIGH)                    // check if the input is HIGH
  {
      playTone(300, 300);
      delay(150);
      
      if (pirState == LOW)
      {
        digitalWrite(yellowLedPin, LOW);
        Serial.println("Motion detected!");
        lcd.clear() ;
        lcd.setCursor(0, 0);                     // Set LCD cursor position (column 0, row 0)
        lcd.print("Motion Detected!");
        
        // We only want to print on the output change, not state
        pirState = HIGH;
      }
  }
  else
  {
      digitalWrite(yellowLedPin, HIGH);
      digitalWrite(redLedPin, LOW);
      
      playTone(0, 0);
      delay(300);
      if (pirState == HIGH)
      {
        // we have just turned of
        Serial.println("Motion ended!");
        delay(1000);
        lcd.clear() ;
        lcd.setCursor(3, 0); 
        lcd.print("Waiting For");
        lcd.setCursor(3, 1);
        lcd.print("Motion....");      // We only want to print on the output change, not state
        pirState = LOW;
      }
   }
}

// duration in mSecs, frequency in hertz
void playTone(long duration, int freq)
{
    duration *= 1000;
    int period = (1.0 / freq) * 100000;
    long elapsed_time = 0;
    while (elapsed_time < duration)
    {
        digitalWrite(redLedPin, HIGH);
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);

        digitalWrite(redLedPin, LOW);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        
        elapsed_time += (period);
    }
}

CODE EXPLANATION
First of all, we included the Arduino’s LCD Library before we can use the LCD.
#include <LiquidCrystal.h>
 After that, we initialized the variables that we are going to use in this code.
int redLedPin = 13;     // choose the pin for the LED
int yellowLedPin = 9;
int inputPin = 7;       // choose the input pin (for PIR sensor)
int pirState = LOW;     // we start, assuming no motion detected
int val = 0;            // variable for reading the pin status
int pinSpeaker = 10;    // Set up a speaker on a PWM pin (digital 9, 10, or 11)
int counter = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
In the setup function,  we declare all the input modes (LEDs, PIR sensor, and the Buzzer), afterwards we set a write to our LEDs to HIGH for a startup, these are optional since we’re still on initialization.
Others that are optional are from line 11 to 41, these shows a print text with delays are on set.
1 void setup()
2 {
3   pinMode(redLedPin, OUTPUT);      // declare LED as output
4   pinMode(yellowLedPin, OUTPUT);
5   pinMode(inputPin, INPUT);     // declare sensor as input
6   pinMode(pinSpeaker, OUTPUT);
7
8   digitalWrite(redLedPin, HIGH);
9   digitalWrite(yellowLedPin, HIGH);
10
11   Serial.begin(9600);
12   lcd.begin(16, 2); 
13   lcd.setCursor(3, 0);                      // Set LCD cursor position (column, row)
14   lcd.print("Car Alarm");                   // Print text to LCD
15   lcd.setCursor(3, 1);                      // Set LCD cursor position (column,row)
16   lcd.print("Security");                    // Print text to LCD
17   delay(4000);      // wait 5s              // Delay to read text
18
19   lcd.clear();
20   lcd.setCursor(0, 0);
21   lcd.print("Motion Detection");
22   lcd.setCursor(0, 1);
23   lcd.print("With PIR Sensor");
24   delay(3000);
25
26   digitalWrite(redLedPin, LOW);
27   digitalWrite(yellowLedPin, LOW);
28
29   lcd.clear();
30   lcd.setCursor(2, 0);
31   lcd.print("Calibrating");
32   lcd.setCursor(3, 1);
33   lcd.print("Sensor ...");
34   delay(3000);
35
36   lcd.clear();
37   lcd.setCursor(2, 0);
38   lcd.print("Waiting for");
39   lcd.setCursor(2, 1);
40   lcd.print("Motion....");
41 }
 In the loop function, we check if the input from the PIR sensor, any motion detection from the sensor will trigger the Buzzer blinking at a rate of 300 milliseconds and delayed 150 milliseconds, in the same time LCD will print a text “Motion Detected!” without any intervals, since it is a printout, later it’ll be printing “Waiting for motion..”, if sensor finishes the detection. Red LED will blink in exchange of the Yellow LED that will be turned off beforehand.
void loop()
{
  val = digitalRead(inputPin);        // read input value
  
  if (val == HIGH)                    // check if the input is HIGH
  {
      playTone(300, 300);
      delay(150);
      
      if (pirState == LOW)
      {
        digitalWrite(yellowLedPin, LOW);
        Serial.println("Motion detected!");
        lcd.clear() ;
        lcd.setCursor(0, 0);                     // Set LCD cursor position (column 0, row 0)
        lcd.print("Motion Detected!");
        
        // We only want to print on the output change, not state
        pirState = HIGH;
      }
  }
  else
  {
      digitalWrite(yellowLedPin, HIGH);
      digitalWrite(redLedPin, LOW);
      
      playTone(0, 0);
      delay(300);
      if (pirState == HIGH)
      {
        // we have just turned of
        Serial.println("Motion ended!");
        delay(1000);
        lcd.clear() ;
        lcd.setCursor(3, 0); 
        lcd.print("Waiting For");
        lcd.setCursor(3, 1);
        lcd.print("Motion....");      // We only want to print on the output change, not state
        pirState = LOW;
      }
   }
}
Additionally we create a playTone function for buzzer’s continuous blinking beeps.
// duration in mSecs, frequency in hertz
void playTone(long duration, int freq)
{
    duration *= 1000;
    int period = (1.0 / freq) * 100000;
    long elapsed_time = 0;
    while (elapsed_time < duration)
    {
        digitalWrite(redLedPin, HIGH);
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);

        digitalWrite(redLedPin, LOW);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        
        elapsed_time += (period);
    }
}
 
INDIVIDUAL WEEKLY PROGRESS:
Farhan Ghiffary - 1801434733
Week 1: when the first week initiated, all student were given two individual assignment that have to be accomplished for specified amount of time. Afterwards, all groups including of mine was asked to find Topic or idea that eventually  will become final project of this course. Me, ferick and Nadaek had been trying to figure out what is the best possibility to solve the issue in our society, and finally we came up with solution in which the project what would be created is smart car alarm system. Occasionally, people have been always carrying stuff that makes us fulfilled throughout the day of our life whether it is valuable or invaluable. yet, in certain time, They are reckless of thinking what they have brought and forgot as if they don’t care about them. That idea, me and our team is to address how we can build mini technology to alert or notify if there is unforeseen motion inside the car. Thus, the car would be in control and safe even though the owner is away.
Week 2: in Second week, I made the scenario to explain the project is going to be. Moreover, I finally found and bought the suitable module to apply for. The modules consist of Arduino uno R3, PIR sensor, Active buzzer, Arduino LCD, Tactile Switch Micro Push Button, transistor and resistor. In this state, me and my team were configuring before it stepped to third progress.
Week 3: In Third week, some parts assembled properly and programmed to make Arduino blinks. Also, make sure its physical layer it run correctly and finally Motion Sensor detection to blinking buzzer and LED. However, there are further changes may apply, breadboard 830 holes ,breadboard 400 holes , LCD blue.
Week 4: In Fourth week, even though there are some changes applied to module, it was successfully set to display helloworld in LCD module. Its progress made me more ambitious to continue assembling all component based on our ideas, yet PIR sensor was having a problem, thus the LED would not light up and still having a trouble to configure it.
Week 5: In Fifth week, What I have done for this project was continuing the project based on the cases that we have addressed. Fortunately, the preceding installment for PIR sensor would not active due to unforeseen circumstance, yet now we can set up the PIR sensor properly to our system that detect the movement as well as alert with buzzer and LED. In addition show message on the LCD is working properly. furthermore, we have set PIR delay and distance measuring to make sure the sensor is not able to sense any motion in afar.
Week 6: In Sixth week, Almost all modules were combined perfectly, i made the report progress of what we have been doing, and we tested the modules in every condition, deep dark situation, distance between sensor and object, it is working precisely. 
Week 7: In seventh week, we were planning to use wifi to upgrade our project better as well as PIR Delay & Sensivity reduced, thus the sensor will not able to detect motion from afar.
Week 8: In eighth week, still on progress to make up our project
Week 9: In ninth week, we had a problem to configure the wifi module because it would not be able to connect to sensor that become trigger in which the data will be sent via wifi module.
Week 10: In tenth week, frankly, we decided to not using wifi due to incompatible component to ours. Thus, we believe with just our improvised parts have already given usable and useful technology.
Week 11: Final Week, All modules are complete assembled, then made video documentary which was ready to deliver to spectators.
Problem found and covered during project development: 
	The problem that I found was that i manage to construct and choose which one is better and suitable to our purposes since we have bought components however in the end they are useless. Also, because this is a first time I got technical stuff, it was kind overwhelmed to see various parts tingled and messy in any shape but it was challenged us a lot and gave us more knowledge about this such engineering stuff.
   
   
   
Ferick Andrew - 1801433296
Week 1: Making an essay for our pervasive computing idea and preparations with a tutorials on how to use and build an interactive electronic objects with Arduino.
Week 2: Looking up for a finished IoT Framework and writing a short description about the framework.
Week 3: We are writing about Metcalfe’s Law.
Week 4: We are looking up for the necessary components, and looking up for installation tutorials.
Week 5: Creating the scenario and bought the necessary components including the Arduino.
Week 6: Creating Hello World printout into LCD module and create the fritz schematics. Additional component are bought (10K-ohm Potentiometer)
Week 7:
•	Creating a detect motion using PIR sensor and alert with Buzzer & LED
•	Show a message on the LCD
•	PIR Timelapse/Delay & Sensivity reduced, so the sensor won't detect motion way too far.
•	Completing the schematics
•	Creating out design sketch
Week 8: 
Week 9: Overall almost completed based on our purposes, starting from completing PIR sensor to detect the movement. Afterwards, Buzzer to trigger alarm and LCD to giving more information regarding the intruder also LED to look informative. We tried to get Wifi Module to yield notification to the owner. we believe if we can use this module, it is easier to the user to regulate their possession whether it something happens or not.
Week 10: *Completed*. We decided that we are not using WiFi module, since we need another helping module or otherwise changing the Arduino to WeMos.
Week 11: *Completed*
Problem found and covered during project development: 


Week 1: 
Week 2: 
Week 3: 
Week 4: 
Week 5: 
Week 6:
Week 7: 
Week 8: 
Week 9: 
Week 10: 
Week 11: 

 Problem found and covered during project development: 


