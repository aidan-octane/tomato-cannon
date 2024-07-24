#include <Arduino.h>
#include <OneButton.h>


const int BUTTON_PIN = 5;
const int TRIGGER_PIN = 7;
const int LED = 9;
OneButton btn = OneButton(
      BUTTON_PIN,  // Input pin for the button
      true,        // Button is active LOW
      true         // Enable internal pull-up resistor
);

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT); 
  pinMode(LED, OUTPUT);
  btn.attachClick(trigger);
  digitalWrite(LED, HIGH);
}

void loop() {
  btn.tick();
  delay(1);
}

static void trigger() {
  digitalWrite(LED, LOW);
  digitalWrite(TRIGGER_PIN, HIGH);
  delay(500);
  digitalWrite(TRIGGER_PIN, LOW);
  digitalWrite(LED, HIGH);
}
