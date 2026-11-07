// Smart switch flipper — ESP32 + two servos + pushbutton trigger
// https://wokwi.com/arduino/projects/323706614646309460 (original servo sweep example)

#include <ESP32Servo.h>

// --- Pin assignments ---
const int servoTopPin = 18;    // pushes switch UP (off)
const int servoBottomPin = 19; // pushes switch DOWN (on)
const int buttonPin = 4;       // pushbutton, wired to this pin and GND

// --- Servo objects ---
Servo servoTop;
Servo servoBottom;

// --- State tracking ---
bool isOn = false;             // our best guess at the switch's current state
bool lastButtonState = HIGH;   // HIGH = not pressed, since we're using INPUT_PULLUP

void setup() {
  // Attach each servo object to its physical pin.
  // 500 and 2400 are the pulse widths (in microseconds) for 0 and 180 degrees.
  servoTop.attach(servoTopPin, 500, 2400);
  servoBottom.attach(servoBottomPin, 500, 2400);

  // Start both arms in neutral position (not touching the switch).
  servoTop.write(90);
  servoBottom.write(90);

  // INPUT_PULLUP means the pin reads HIGH by default, and LOW when the
  // button is pressed and connects the pin to GND.
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  // Only react on the moment the button goes from not-pressed to pressed,
  // not for every loop cycle while it's held down.
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    if (isOn) {
      turnOff();
    } else {
      turnOn();
    }
  }

  // Remember this reading for next time through the loop.
  lastButtonState = currentButtonState;
}

void turnOn() {
  if (!isOn) {
    servoBottom.write(180); // push down
    delay(1000);            // give the arm time to travel
    servoBottom.write(90);  // return to neutral
    isOn = true;
  }
}

void turnOff() {
  if (isOn) {
    servoTop.write(180);    // push up
    delay(1000);            // give the arm time to travel
    servoTop.write(90);     // return to neutral
    isOn = false;
  }
}