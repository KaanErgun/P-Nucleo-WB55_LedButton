#include <Arduino.h>

// Pin definitions
const int buttonPins[3] = {PC4, PD0, PD1};  // Button/SW pins
const int ledPins[3] = {PB5, PB0, PB1};     // LED pins

// Button states
int buttonStates[3] = {0, 0, 0};
int lastButtonStates[3] = {0, 0, 0};

// Timer variables
unsigned long lastDebounceTimes[3] = {0, 0, 0};
unsigned long debounceDelay = 50;

void setup() {
  // Set pin modes
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }

  // Start serial communication
  Serial.begin(9600);
}

void handleButton(int index) {
  int reading = digitalRead(buttonPins[index]);

  // Debounce button
  if (reading != lastButtonStates[index]) {
    lastDebounceTimes[index] = millis();
  }
  if ((millis() - lastDebounceTimes[index]) > debounceDelay && reading != buttonStates[index]) {
    buttonStates[index] = reading;

    // Handle LED state based on button state
    switch (buttonStates[index]) {
      case LOW:
        Serial.print("Button ");
        Serial.print(index + 1);
        Serial.println(" pressed!");
        digitalWrite(ledPins[index], HIGH);
        break;

      case HIGH:
        digitalWrite(ledPins[index], LOW);
        break;
    }
  }
  lastButtonStates[index] = reading;
}

void loop() {
  for (int i = 0; i < 3; i++) {
    handleButton(i);
  }
}
