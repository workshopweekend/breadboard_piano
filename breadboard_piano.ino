/**   
 *  Create a very simple "breadboard" piano using a jumper wire to simulate pressing each "piano" key.
 *  This one has 5 notes, but you can expand it using more digital IO pins.
 *   
 *  author:
 *   Rolf Widenfelt - Feb 2014 - Workshop Weekend
**/

#include "pitches.h"

int tonepin = 9;  // PWM0 output = 9, PWM1 output = 10

// these are the "piano keys" - they are just input pins
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6    

void setup() {          
  // setup internal pullups on "piano keys" (pins D2 through D6)
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
}    

void loop() {
  while (1) {    
    // scan "piano keys" for one that is "pressed"
    if (digitalRead(D6) == LOW) {
      tone(tonepin, NOTE_C4);
    } else if (digitalRead(D5) == LOW) {
      tone(tonepin, NOTE_D4);
    } else if (digitalRead(D4) == LOW) {
      tone(tonepin, NOTE_E4);
    } else if (digitalRead(D3) == LOW) {
      tone(tonepin, NOTE_F4);
    } else if (digitalRead(D2) == LOW) {
      tone(tonepin, NOTE_G4);
    } else {
      noTone(tonepin);
    }
    delay(100);    // probably not needed.. you can experiment!
  }
}