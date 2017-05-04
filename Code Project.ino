//This Type Of Sensor Detects Motion
//And lows L.E.D And Start Buzzing
//It Also Displays The That The "Motion is Detected" On 
//An Lcd Screen
//For Any Help,Please Contact Zishan on +917277989686,India

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

