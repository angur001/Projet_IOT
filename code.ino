/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 https://docs.arduino.cc/learn/electronics/lcd-displays

*/

// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float start_lcd;
float start_servo;
float time;
unsigned long servoInterval = 15; // Intervalle entre les mouvements du servo en millisecondes
unsigned long previousServoMillis = 0;


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("light intensity:");
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  start_lcd = millis();
  start_servo = millis();
}

/*
void clearColumn(uint8_t col, uint8_t row) {
  // Move the cursor to the specified column and row
  lcd.setCursor(col, row);

  // Clear the column by printing empty spaces
  for (int i = 0; i < lcd.getNumberOfRows(); i++) {
    lcd.print(" ");
    lcd.setCursor(col, row + i);
  }
}
*/

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  time = millis();

  
  if (time - start_lcd > 200) {
    int val=analogRead(0);   //connect grayscale sensor to Analog 0
    lcd.clear();
    lcd.print(val,DEC);
    start_lcd = time;
  }


  //Serial.println(val,DEC);//print the value to serial
  
  
  //lcd.print(val,DEC);
  //delay(200);

  

  /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree

    myservo.write(pos);    
    delay(15);

  }
  
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    
    myservo.write(pos);    
    delay(15);

  }*/
  unsigned long currentMillis = millis();

  /*if (currentMillis - previousServoMillis >= servoInterval) {
    previousServoMillis = currentMillis;

    // Mouvement du servo de 0 à 180 degrés
    if (pos <= 180) {
      myservo.write(pos);
      pos++;
    }
    // Mouvement du servo de 180 à 0 degrés
    else if (pos > 180 && pos <= 360) {
      myservo.write(pos);
      pos--;
    }
    // Réinitialisation de la position du servo
    else {
      pos = 0;
    }
  }*/
  


    
  
}