#include <Arduino.h>

// Pin definitions
const int buttonPin1 = PC4;  // Button/SW 1 pin
const int buttonPin2 = PD0;  // Button/SW 2 pin
const int buttonPin3 = PD1;  // Button/SW 3 pin

const int ledPin1 = PB5;     // LED 1 pin
const int ledPin2 = PB0;     // LED 2 pin
const int ledPin3 = PB1;     // LED 3 pin

// Button states
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int lastButtonState1 = 0;
int lastButtonState2 = 0;
int lastButtonState3 = 0;

// Timer variables
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;

unsigned long debounceDelay = 50;

void setup() {
  // Set pin modes
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read button states
  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
  int reading3 = digitalRead(buttonPin3);

  // Debounce button 1
  if (reading1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }
  if ((millis() - lastDebounceTime1) > debounceDelay && reading1 != buttonState1) {
    buttonState1 = reading1;
    if (buttonState1 == LOW) {
      Serial.println("Button 1 pressed!");
      digitalWrite(ledPin1, HIGH); // Turn on LED 1
    } else {
      digitalWrite(ledPin1, LOW);  // Turn off LED 1
    }
  }
  lastButtonState1 = reading1;

  // Debounce button 2
  if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }
  if ((millis() - lastDebounceTime2) > debounceDelay && reading2 != buttonState2) {
    buttonState2 = reading2;
    if (buttonState2 == LOW) {
      Serial.println("Button 2 pressed!");
      digitalWrite(ledPin2, HIGH); // Turn on LED 2
    } else {
      digitalWrite(ledPin2, LOW);  // Turn off LED 2
    }
  }
  lastButtonState2 = reading2;

  // Debounce button 3
  if (reading3 != lastButtonState3) {
    lastDebounceTime3 = millis();
  }
  if ((millis() - lastDebounceTime3) > debounceDelay && reading3 != buttonState3) {
    buttonState3 = reading3;
    if (buttonState3 == LOW) {
      Serial.println("Button 3 pressed!");
      digitalWrite(ledPin3, HIGH); // Turn on LED 3
    } else {
      digitalWrite(ledPin3, LOW);  // Turn off LED 3
    }
  }
  lastButtonState3 = reading3;
}
