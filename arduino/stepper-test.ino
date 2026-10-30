/*
  STEPPER MOTOR TEST SKETCH
  
  Tests both X-axis and Y-axis stepper motors
  Rotates each motor in both directions
  
  Pin Configuration:
  - X-axis: DIR pin 2, STEP pin 3
  - Y-axis: DIR pin 4, STEP pin 5
  
  Wiring:
  - DRV8825 #1 (X-axis):
    - DIR → Arduino pin 2
    - STEP → Arduino pin 3
    - GND → Arduino GND
    - VCC → Arduino 5V
    - VMOT → 12V power supply
    
  - DRV8825 #2 (Y-axis):
    - DIR → Arduino pin 4
    - STEP → Arduino pin 5
    - GND → Arduino GND
    - VCC → Arduino 5V
    - VMOT → 12V power supply
*/

// Pin definitions
#define DIR_X 2
#define STEP_X 3
#define DIR_Y 4
#define STEP_Y 5

// Constants
#define STEPS_PER_REV 200  // NEMA 17 default: 1.8° per step = 200 steps/rev
#define DELAY_MICROS 1000  // Microseconds between steps (lower = faster)

void setup() {
  // Initialize serial for debugging
  Serial.begin(9600);
  
  // Set motor control pins as outputs
  pinMode(DIR_X, OUTPUT);
  pinMode(STEP_X, OUTPUT);
  pinMode(DIR_Y, OUTPUT);
  pinMode(STEP_Y, OUTPUT);
  
  // Start with all pins LOW
  digitalWrite(DIR_X, LOW);
  digitalWrite(STEP_X, LOW);
  digitalWrite(DIR_Y, LOW);
  digitalWrite(STEP_Y, LOW);
  
  Serial.println("=== STEPPER MOTOR TEST ===");
  Serial.println("Testing X-axis motor...");
}

void loop() {
  // Test X-axis motor - forward
  Serial.println("X-axis: Rotating forward (1 rev)");
  rotateMotor(DIR_X, STEP_X, HIGH, STEPS_PER_REV);
  delay(1000);
  
  // Test X-axis motor - reverse
  Serial.println("X-axis: Rotating reverse (1 rev)");
  rotateMotor(DIR_X, STEP_X, LOW, STEPS_PER_REV);
  delay(1000);
  
  // Test Y-axis motor - forward
  Serial.println("Y-axis: Rotating forward (1 rev)");
  rotateMotor(DIR_Y, STEP_Y, HIGH, STEPS_PER_REV);
  delay(1000);
  
  // Test Y-axis motor - reverse
  Serial.println("Y-axis: Rotating reverse (1 rev)");
  rotateMotor(DIR_Y, STEP_Y, LOW, STEPS_PER_REV);
  delay(1000);
}

/*
  rotateMotor()
  
  Rotate a stepper motor by sending step pulses
  
  Parameters:
  - dirPin: Direction control pin
  - stepPin: Step pulse pin
  - direction: HIGH for forward, LOW for reverse
  - steps: Number of steps to execute
*/
void rotateMotor(int dirPin, int stepPin, int direction, int steps) {
  // Set direction
  digitalWrite(dirPin, direction);
  
  // Send step pulses
  for (int i = 0; i < steps; i++) {
    // Step pulse: HIGH then LOW
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(DELAY_MICROS);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(DELAY_MICROS);
  }
  
  Serial.print("  Completed ");
  Serial.print(steps);
  Serial.println(" steps");
}
