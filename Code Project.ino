//This Type Of Sensor Detects Motion
//And lows L.E.D And Start Buzzing
//It Also Displays The That The "Motion is Detected" On 
//An Lcd Screen

#include <LiquidCrystal.h>

int redLedPin = 13;     // Pin for the red LED
int yellowLedPin = 9;   // Pin for the yellow LED
int inputPin = 7;       // Pin for PIR sensor
int pirState = LOW;     // Initialization state, assuming for no motion
int val = 0;            // Variable of sensor status
int pinSpeaker = 10;    // Set up a speaker on a PWM pin (digital 9, 10, or 11)

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // declare LEDs and Buzzer as output
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(pinSpeaker, OUTPUT);

  // declare sensor as input
  pinMode(inputPin, INPUT);

  // Rest of these codes on "setup()" These are for initialization only
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
  
  // If motion is detected, set LED to red and turn on the buzzer
  if (val == HIGH)
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
  // Otherwise make the state back to normal, turn the yellow LED back on
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
