/*
  PEN PLOTTER CONTROLLER
  
  Complete G-code interpreter for pen plotter control
  Receives G-code commands via USB serial and executes plotter motion
  
  G-code Commands:
  - G0 X100 Y50       → Move to position (no drawing)
  - G1 X100 Y50       → Move to position (drawing)
  - M3 S100           → Pen down (servo to down angle)
  - M5                → Pen up (servo to up angle)
  - G28               → Home (return to 0,0)
  - G92 X0 Y0         → Set current position as origin
  
  Pin Configuration:
  - X-axis: DIR pin 2, STEP pin 3
  - Y-axis: DIR pin 4, STEP pin 5
  - Servo: PWM pin 9
  
  Serial Protocol:
  - Baud rate: 9600
  - Terminator: \n (newline)
  - Response: "OK" when complete
*/

#include <Servo.h>
#include <String.h>

// ============ PIN DEFINITIONS ============

#define DIR_X 2
#define STEP_X 3
#define DIR_Y 4
#define STEP_Y 5
#define SERVO_PIN 9

// ============ CONSTANTS ============

#define STEPS_PER_MM 50           // Calibration: steps per mm (adjust based on your setup)
#define STEP_DELAY_MICROS 500     // Microseconds between steps
#define MAX_SPEED 200             // mm/sec max speed
#define PEN_DOWN 45               // Servo angle when pen touches paper
#define PEN_UP 135                // Servo angle when pen is lifted

// ============ GLOBAL VARIABLES ============

Servo penServo;

// Current position tracking (in mm)
float currentX = 0.0;
float currentY = 0.0;
boolean penIsDown = false;

// ============ SETUP & INITIALIZATION ============

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set motor pins as outputs
  pinMode(DIR_X, OUTPUT);
  pinMode(STEP_X, OUTPUT);
  pinMode(DIR_Y, OUTPUT);
  pinMode(STEP_Y, OUTPUT);
  
  // Initialize servo
  penServo.attach(SERVO_PIN);
  penServo.write(PEN_UP);
  penIsDown = false;
  
  // Home position
  currentX = 0.0;
  currentY = 0.0;
  
  Serial.println("PEN PLOTTER READY");
  Serial.print("Position: X");
  Serial.print(currentX);
  Serial.print(" Y");
  Serial.println(currentY);
}

// ============ MAIN LOOP ============

void loop() {
  // Check for incoming serial data
  if (Serial.available() > 0) {
    // Read command string (until newline)
    String command = Serial.readStringUntil('\n');
    
    // Trim whitespace
    command.trim();
    
    if (command.length() > 0) {
      // Parse and execute command
      executeCommand(command);
    }
  }
}

// ============ COMMAND EXECUTION ============

void executeCommand(String cmd) {
  cmd.toUpperCase();
  
  if (cmd.startsWith("G0")) {
    // G0 - Rapid move (no drawing)
    handleMove(cmd, false);
  }
  else if (cmd.startsWith("G1")) {
    // G1 - Linear move (drawing)
    handleMove(cmd, true);
  }
  else if (cmd.startsWith("G28")) {
    // G28 - Home
    handleHome();
  }
  else if (cmd.startsWith("G92")) {
    // G92 - Set position
    handleSetPosition(cmd);
  }
  else if (cmd.startsWith("M3")) {
    // M3 - Pen down
    handlePenDown(cmd);
  }
  else if (cmd.startsWith("M5")) {
    // M5 - Pen up
    handlePenUp();
  }
  else if (cmd.startsWith("STATUS")) {
    // STATUS - Report current position
    handleStatus();
  }
  else {
    Serial.println("ERROR: Unknown command");
    return;
  }
  
  Serial.println("OK");
}

// ============ G-CODE HANDLERS ============

void handleMove(String cmd, boolean draw) {
  // Parse: G0 X100 Y50
  float targetX = currentX;
  float targetY = currentY;
  
  // Extract X value
  int xIndex = cmd.indexOf('X');
  if (xIndex != -1) {
    targetX = cmd.substring(xIndex + 1).toFloat();
  }
  
  // Extract Y value
  int yIndex = cmd.indexOf('Y');
  if (yIndex != -1) {
    targetY = cmd.substring(yIndex + 1).toFloat();
  }
  
  // Calculate distance
  float deltaX = targetX - currentX;
  float deltaY = targetY - currentY;
  float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
  
  // If drawing, ensure pen is down
  if (draw && !penIsDown) {
    penServo.write(PEN_DOWN);
    penIsDown = true;
    delay(200);  // Wait for servo to move
  }
  
  // Move motors
  moveToPosition(targetX, targetY);
  
  // Update current position
  currentX = targetX;
  currentY = targetY;
}

void handleHome() {
  // Move to 0,0
  moveToPosition(0.0, 0.0);
  currentX = 0.0;
  currentY = 0.0;
  penServo.write(PEN_UP);
  penIsDown = false;
}

void handleSetPosition(String cmd) {
  // G92 X0 Y0 - Set current position
  float newX = currentX;
  float newY = currentY;
  
  int xIndex = cmd.indexOf('X');
  if (xIndex != -1) {
    newX = cmd.substring(xIndex + 1).toFloat();
  }
  
  int yIndex = cmd.indexOf('Y');
  if (yIndex != -1) {
    newY = cmd.substring(yIndex + 1).toFloat();
  }
  
  currentX = newX;
  currentY = newY;
}

void handlePenDown(String cmd) {
  // M3 S100 - Pen down with optional angle parameter
  int angle = PEN_DOWN;
  
  int sIndex = cmd.indexOf('S');
  if (sIndex != -1) {
    angle = cmd.substring(sIndex + 1).toInt();
  }
  
  penServo.write(angle);
  penIsDown = true;
  delay(200);  // Wait for servo
}

void handlePenUp() {
  // M5 - Pen up
  penServo.write(PEN_UP);
  penIsDown = false;
  delay(200);  // Wait for servo
}

void handleStatus() {
  // Report current position and pen status
  Serial.print("X");
  Serial.print(currentX);
  Serial.print(" Y");
  Serial.print(currentY);
  Serial.print(" PEN:");
  Serial.println(penIsDown ? "DOWN" : "UP");
}

// ============ MOTOR CONTROL ============

void moveToPosition(float targetX, float targetY) {
  // Calculate steps needed
  int stepsX = (int)((targetX - currentX) * STEPS_PER_MM);
  int stepsY = (int)((targetY - currentY) * STEPS_PER_MM);
  
  // Determine directions
  int dirX = (stepsX >= 0) ? HIGH : LOW;
  int dirY = (stepsY >= 0) ? HIGH : LOW;
  
  // Take absolute values
  stepsX = abs(stepsX);
  stepsY = abs(stepsY);
  
  // Set directions
  digitalWrite(DIR_X, dirX);
  digitalWrite(DIR_Y, dirY);
  
  // Move motors (simplified: no acceleration/deceleration yet)
  int maxSteps = max(stepsX, stepsY);
  
  for (int i = 0; i < maxSteps; i++) {
    // X-axis step
    if (i < stepsX) {
      digitalWrite(STEP_X, HIGH);
      delayMicroseconds(STEP_DELAY_MICROS);
      digitalWrite(STEP_X, LOW);
      delayMicroseconds(STEP_DELAY_MICROS);
    }
    
    // Y-axis step
    if (i < stepsY) {
      digitalWrite(STEP_Y, HIGH);
      delayMicroseconds(STEP_DELAY_MICROS);
      digitalWrite(STEP_Y, LOW);
      delayMicroseconds(STEP_DELAY_MICROS);
    }
  }
}

// ============ UTILITY FUNCTIONS ============

float distance(float x1, float y1, float x2, float y2) {
  float dx = x2 - x1;
  float dy = y2 - y1;
  return sqrt(dx * dx + dy * dy);
}
