/*
  SERVO MOTOR TEST SKETCH
  
  Tests MG90S servo motor for pen lift mechanism
  Moves servo through full range (up/down for pen control)
  
  Pin Configuration:
  - Servo signal: Arduino pin 9 (PWM-capable)
  - Servo power: 5V from Arduino
  - Servo ground: Arduino GND
  
  Wiring:
  - Servo Red (power) → Arduino 5V pin
  - Servo Black (ground) → Arduino GND pin
  - Servo Yellow (signal) → Arduino pin 9
  
  Expected Behavior:
  - Servo moves to 45° (pen DOWN)
  - Pauses 2 seconds
  - Servo moves to 135° (pen UP)
  - Pauses 2 seconds
  - Repeat
*/

#include <Servo.h>

// Servo object
Servo penServo;

// Pin definition (PWM-capable pin)
#define SERVO_PIN 9

// Servo angle definitions (adjust based on your setup)
#define PEN_DOWN 45    // Servo angle when pen touches paper
#define PEN_UP 135     // Servo angle when pen is lifted
#define PEN_CENTER 90  // Neutral position

// Timing
#define HOLD_TIME 2000 // Milliseconds to hold each position

void setup() {
  // Initialize serial for debugging
  Serial.begin(9600);
  
  // Attach servo to pin
  penServo.attach(SERVO_PIN);
  
  // Start at center position
  penServo.write(PEN_CENTER);
  
  Serial.println("=== SERVO MOTOR TEST ===");
  Serial.println("Servo attached to pin 9");
  Serial.print("Pen DOWN angle: ");
  Serial.println(PEN_DOWN);
  Serial.print("Pen UP angle: ");
  Serial.println(PEN_UP);
  Serial.println("Starting test sequence...\n");
  
  delay(1000);
}

void loop() {
  // Move pen DOWN
  Serial.println("-> Pen DOWN");
  penServo.write(PEN_DOWN);
  delay(HOLD_TIME);
  
  // Move pen UP
  Serial.println("-> Pen UP");
  penServo.write(PEN_UP);
  delay(HOLD_TIME);
  
  // Optional: return to center
  Serial.println("-> Center");
  penServo.write(PEN_CENTER);
  delay(500);
}

/*
  Alternate functions for more complex control
*/

// Move servo to specific angle
void moveServo(int angle) {
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;
  
  penServo.write(angle);
  
  Serial.print("Servo at ");
  Serial.print(angle);
  Serial.println("°");
}

// Sweep servo smoothly
void sweepServo(int start, int end, int step, int delayMs) {
  if (start < end) {
    for (int angle = start; angle <= end; angle += step) {
      penServo.write(angle);
      delay(delayMs);
    }
  } else {
    for (int angle = start; angle >= end; angle -= step) {
      penServo.write(angle);
      delay(delayMs);
    }
  }
}

// Detach servo (reduce power consumption)
void detachServo() {
  penServo.detach();
  Serial.println("Servo detached");
}

// Re-attach servo
void reattachServo() {
  penServo.attach(SERVO_PIN);
  Serial.println("Servo reattached");
}
