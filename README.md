# Pen Plotter — Complete Build Guide

**Version:** 1.0  
**Status:** Ready to Build  
**Estimated Build Time:** 4–6 hours  
**Difficulty Level:** Intermediate (mechanical assembly + basic electronics)

---

## 📋 Table of Contents

1. [Bill of Materials](#bill-of-materials)
2. [Tools Required](#tools-required)
3. [Safety Precautions](#safety-precautions)
4. [Phase 1: Frame Assembly](#phase-1-frame-assembly)
5. [Phase 2: Linear Motion System](#phase-2-linear-motion-system)
6. [Phase 3: Motor & Drive System](#phase-3-motor--drive-system)
7. [Phase 4: Timing Belt Installation](#phase-4-timing-belt-installation)
8. [Phase 5: Servo & Pen Lift](#phase-5-servo--pen-lift)
9. [Phase 6: Electronics & Wiring](#phase-6-electronics--wiring)
10. [Phase 7: Power & Testing](#phase-7-power--testing)
11. [Troubleshooting](#troubleshooting)

---

## Bill of Materials

See `BOM.md` for complete parts list with ASINs and prices.

**Summary:**
- Frame & Motion: 4 items
- Electronics: 5 items
- Servo & Control: 2 items
- **Total: 11 items, $216.28**

---

## Tools Required

### Essential
- ✅ M5 Hex Wrench (included in Taiss kit)
- ✅ Screwdriver set (Phillips + flat)
- ✅ Tweezers (small component handling)
- ✅ USB cable (Arduino programming)
- ✅ Wire stripper (included in Ginsco kit)
- ✅ Heat gun or lighter (heat shrink application)

### Optional but Helpful
- Calipers (measuring alignment)
- Small level (frame leveling)
- Needle-nose pliers (wire bending)
- Multimeter (continuity testing)

---

## Safety Precautions

⚠️ **Before You Start:**

1. **Electrical Safety**
   - Never power on while building
   - Disconnect power before modifying wiring
   - Use insulated tools around power supply
   - Test continuity before powering on

2. **Mechanical Safety**
   - Keep loose hardware in organized containers
   - Don't force any parts (misalignment = damage)
   - Secure frame before testing motion
   - Keep fingers away from moving parts during testing

3. **Heat Safety**
   - Use heat gun carefully (high temperature)
   - Never point at people or animals
   - Wear safety glasses when applying heat shrink
   - Keep heat shrink away from eyes

---

## Phase 1: Frame Assembly

**Time:** 30–45 minutes  
**Components:** SeekLiny extrusion, Taiss T-nuts & bolts

### Step 1.1: Inspect Frame Pieces

```
SeekLiny ships with:
- 4× 500mm aluminum 2020 extrusions (T-slot profile)
- Corner bracket kit (included)
- Protective film (remove this)
```

- [ ] Remove protective film from all 4 extrusion pieces
- [ ] Inspect for shipping damage
- [ ] Check that T-slots are clean (no debris)

### Step 1.2: Layout Frame Configuration

**Your plotter working area:**

```
        Y-axis (500mm)
        ↑
        |
        +-------+ ← Motor 2 (Y-axis)
        |       |
        |       |
        | 20cm  | Working
        |×28cm  | Area
        |       |
        +-------+ ← Motor 1 (X-axis)
        →
      X-axis (500mm)
```

**Frame layout:**
- **2 horizontal pieces (X-axis):** Side-by-side, parallel
- **2 vertical pieces (Y-axis):** Connect the horizontal pieces

### Step 1.3: Assemble Frame Corners

**Connect using corner brackets + M5 bolts from Taiss kit:**

For each of 4 corners:
1. Insert M5 T-nuts into T-slots (2 nuts per corner, 4 bolts total per side)
2. Align corner bracket
3. Insert M5 bolts through bracket holes
4. Tighten with M5 hex wrench (firm but not over-tight)

```
  T-slot
    ↓
  ▭▭▭▭▭
  ║▭▭▭║
  ║ ▭ ║  ← T-nut slides in groove
  ║▭▭▭║
  ▭▭▭▭▭
    ↓
  Bolt threads into T-nut
```

- [ ] Install 4 corner brackets (one per corner)
- [ ] Torque M5 bolts (finger-tight + ¼ turn, don't over-tighten)
- [ ] Check frame is square using calipers (measure diagonals — should be equal)
- [ ] Frame should be rigid with no flex

### Step 1.4: Final Frame Check

- [ ] Frame is square and level
- [ ] All T-slots are accessible (will need them for rod mounts)
- [ ] No gaps at corners
- [ ] Bolts are tight (tug on each corner)

---

## Phase 2: Linear Motion System

**Time:** 45–60 minutes  
**Components:** BUVVTPU (4 rods, 8 bearings, 8 rod supports)

### Step 2.1: Inspect Linear Motion Kit

BUVVTPU ships with:
- 4× 500mm smooth steel rods (8mm diameter)
- 8× SCS8UU linear slide blocks (bearing blocks)
- 8× SK8 rod rail supports (frame brackets)
- Hardware for support mounting

- [ ] Verify all 4 rods are straight (roll on flat surface)
- [ ] Check all 8 bearing blocks for free movement on a rod
- [ ] Inspect all 8 rod supports for damage

### Step 2.2: Mount Rod Supports to Frame

**Rod supports attach to T-slots using M5 bolts:**

For each of 4 rod supports:
1. Identify T-slot location on frame (2 per axis)
2. Prepare 2× M5 T-nuts + 2× M5 bolts from Taiss kit
3. Slide T-nuts into T-slot grooves
4. Position rod support over T-nuts
5. Insert bolts through support holes
6. Tighten (finger-tight + ¼ turn)

**Placement:**
- **X-axis rod supports (2):** Mount on inside edges of top/bottom horizontal pieces
- **Y-axis rod supports (2):** Mount on inside edges of left/right vertical pieces

- [ ] Install all 4 rod supports
- [ ] Verify supports are parallel (use level)
- [ ] Supports should not flex

### Step 2.3: Install Smooth Rods

**Insert rods through the rod supports:**

For X-axis (2 rods):
1. Slide 500mm rod into both X-axis rod supports
2. Rod should slide smoothly in SK8 bracket
3. Verify rod is centered in support (equal space on sides)

For Y-axis (2 rods):
1. Repeat for Y-axis

- [ ] Both X-axis rods installed and aligned
- [ ] Both Y-axis rods installed and aligned
- [ ] All rods can slide freely (no binding)
- [ ] Rods are parallel (check with level at multiple points)

### Step 2.4: Install Bearing Blocks

**Slide SCS8UU bearing blocks onto each rod:**

For X-axis:
1. Take one SCS8UU bearing block
2. Slide onto X-axis rod
3. It should move smoothly but with slight resistance
4. Install 2 bearing blocks per rod (one per motor side)

For Y-axis:
1. Repeat (2 bearing blocks per rod)

**Total: 8 bearing blocks (4 per axis)**

- [ ] All 8 bearing blocks installed and moving smoothly
- [ ] No grinding or rough spots
- [ ] Blocks move along full length of rods
- [ ] Linear motion system is complete and functional

---

## Phase 3: Motor & Drive System

**Time:** 45–60 minutes  
**Components:** STEPPERONLINE motors, Saiper couplers, Zeelo pulleys

### Step 3.1: Prepare Stepper Motors

**You have 2× NEMA 17 motors (1 per axis):**

Inspect each motor:
- [ ] Shaft is straight (no bend)
- [ ] Motor has 1.5A cable attached (from STEPPERONLINE kit)
- [ ] No damage to motor body

### Step 3.2: Mount Motors to Bearing Blocks

**Each motor drives one axis via timing belt:**

**X-axis Motor Mount:**
1. Secure NEMA 17 motor to one end of X-axis bearing block assembly
2. Motor shaft should point toward timing pulley
3. Use small brackets or 3D-printed mounts (secure with set screws)

**Y-axis Motor Mount:**
1. Repeat for Y-axis

**Note:** Motor mounts depend on your specific design. Options:
- 3D-printed mounts (if access to printer)
- Aluminum angle brackets ($5–10)
- Rigid mounting block design (custom)

- [ ] Both motors mounted securely
- [ ] Motor shafts align with pulley locations
- [ ] Motors don't obstruct bearing block movement

### Step 3.3: Install Flexible Couplers

**Connect motor shafts to timing pulleys:**

From Saiper 5-pack, use 2 couplers (1 per motor):

1. Slide flexible coupler onto motor shaft
2. Align with timing pulley bore
3. Tighten set screw on coupler (M4 hex wrench)

- [ ] Coupler on X-axis motor shaft, tightened
- [ ] Coupler on Y-axis motor shaft, tightened
- [ ] Shafts rotate freely (no binding)

### Step 3.4: Mount Timing Pulleys

**From Zeelo kit (6 pulleys total):**

Install 2 pulleys per motor:
1. Mount pulley 1 on motor shaft coupler (primary drive)
2. Mount pulley 2 on driven rod (timing belt wraps around both)

Set screw alignment:
- Motor-side pulley: set screw faces outward
- Driven-side pulley: set screw faces inward

- [ ] 4 total pulleys installed (2 per motor)
- [ ] All pulleys rotate freely
- [ ] Pulleys are coaxial (aligned, no wobble)

---

## Phase 4: Timing Belt Installation

**Time:** 30–45 minutes  
**Components:** Zeelo timing belt, idlers, tensioners

### Step 4.1: Prepare Timing Belt

From Zeelo 5M GT2 belt:
- Length available: 5 meters (plenty!)
- Cut to approximately:
  - **X-axis belt:** ~600mm (around both pulleys + slack)
  - **Y-axis belt:** ~600mm (around both pulleys + slack)

Suggested cut: 600mm per axis + spares

- [ ] Measure working distance around pulleys
- [ ] Cut belt to length (use sharp scissors or utility knife)
- [ ] Check cut edges are clean (no fraying)

### Step 4.2: Install X-Axis Timing Belt

1. Loop belt around X-axis motor pulley
2. Route belt to driven pulley on opposite end
3. Loop around driven pulley
4. Route back to motor

```
Motor    Driven
  O————→O
  ↑       ↓
  └───←───┘
  (belt path)
```

- [ ] Belt loops both pulleys
- [ ] Belt is smooth (no twists)
- [ ] Belt tension is slack (will adjust next)

### Step 4.3: Install Timing Tension & Idlers

From Zeelo kit:
- 4 idler pulleys (for belt tension)
- 4 tension springs (for spring-loaded idlers)

**Installation:**
1. Mount idler pulley on tension bracket
2. Position idler under belt at midpoint
3. Attach tension spring to pull idler upward
4. Spring should press belt firmly against motor pulley (but not too tight)

**Tension check:**
- Press belt midway between pulleys
- Should deflect ~5mm under moderate finger pressure
- Too tight = motor strain; too loose = skipping steps

- [ ] Both X and Y timing belts installed
- [ ] Idlers positioned and tensioned
- [ ] Belt tension is correct (5mm deflection)
- [ ] Manual rotation of motor = smooth belt movement

### Step 4.4: Test Timing System

Manually rotate motor shaft by hand:
- [ ] Belt moves smoothly without binding
- [ ] Driven pulley rotates with motor
- [ ] Bearing blocks move in sync with timing belt

---

## Phase 5: Servo & Pen Lift

**Time:** 20–30 minutes  
**Components:** Miuzei MG90S servo, servo horn, linkage

### Step 5.1: Prepare Servo Motor

From Miuzei 2-pack, use 1 servo (keep 1 spare):

- [ ] Servo is intact (no physical damage)
- [ ] Servo has control cable (3-wire: power, ground, signal)
- [ ] Servo rotates freely (manual test)

### Step 5.2: Design Pen Lift Mechanism

**Simple mechanism (examples):**

**Option A: Direct Lever**
```
Servo horn (90°)
    ↓
    +─── Arm (rigid)
    |     ↓
    |    Pen holder
    |     (moves up/down)
    └─── Pivot point
```

**Option B: Linkage**
```
Servo → Linkage arm → Pen holder
        (mechanical advantage)
```

**Recommended:** Option A (simpler, proven)

### Step 5.3: Mount Servo to Frame

1. Secure servo body to frame using M3 bolts/brackets
2. Servo horn (90°) should point toward pen holder
3. Servo cable runs to Arduino (see Phase 6)

- [ ] Servo is securely mounted
- [ ] Servo horn has full range of motion (0–180°)
- [ ] Pen holder can move 10–15mm up/down (sufficient for pen contact)

### Step 5.4: Attach Pen Holder

1. Design/print or fabricate pen holder that fits your pen diameter
2. Attach holder to servo linkage arm
3. Verify pen can make contact with paper when servo is in "down" position

- [ ] Pen holder is rigidly attached to servo arm
- [ ] Pen moves freely (no binding)
- [ ] Pen makes solid contact with paper at servo "down" position

---

## Phase 6: Electronics & Wiring

**Time:** 1–2 hours  
**Components:** Arduino Uno, DRV8825 drivers, breadboard, jumper wires, heat shrink

### Step 6.1: Arduino Uno Setup

1. Connect USB cable to Arduino (don't power yet)
2. Install Arduino IDE on your computer (https://www.arduino.cc/en/software)
3. Select Board: "Arduino Uno"
4. Select Port: (USB port where Arduino is connected)

- [ ] Arduino IDE installed
- [ ] Arduino board selected and recognized
- [ ] Test sketch compiles and uploads

### Step 6.2: DRV8825 Driver Setup

From DIYables 2-set combo:
- 2× DRV8825 stepper driver modules
- 2× Expansion boards

**On breadboard, layout:**
1. Driver #1 (X-axis motor control)
2. Driver #2 (Y-axis motor control)
3. Each driver on its own section of breadboard

**Wiring per driver:**
```
VCC (5V) ← from Arduino 5V pin
GND      ← Arduino GND
VMOT     ← 12V from power supply (motor power)
GND      ← common ground

Signal inputs:
DIR (direction pin) ← Arduino digital pin (e.g., pin 2 for motor 1)
STEP (step pin)     ← Arduino digital pin (e.g., pin 3 for motor 1)
```

- [ ] DRV8825 #1 wired on breadboard
- [ ] DRV8825 #2 wired on breadboard
- [ ] Power connections verified (5V + 12V + GND)

### Step 6.3: Motor Connections

**From each NEMA 17 stepper motor cable to DRV8825:**

Motor cable (4 wires):
- A+ (phase 1, positive)
- A- (phase 1, negative)
- B+ (phase 2, positive)
- B- (phase 2, negative)

Connect to DRV8825:
```
Motor A+ → DRV8825 OUT1
Motor A- → DRV8825 OUT2
Motor B+ → DRV8825 OUT3
Motor B- → DRV8825 OUT4
```

- [ ] X-axis motor wired to Driver #1
- [ ] Y-axis motor wired to Driver #2
- [ ] All motor connections secure (no loose wires)

### Step 6.4: Servo Connection

From MG90S servo 3-wire cable:
- Red (power) → Arduino 5V
- Black (ground) → Arduino GND
- Yellow (signal) → Arduino PWM pin (e.g., pin 9)

- [ ] Servo power connected
- [ ] Servo ground connected
- [ ] Servo signal connected to Arduino PWM pin

### Step 6.5: Heat Shrink & Insulation

Use Ginsco heat shrink kit to insulate all solder joints and connections:

1. Slide heat shrink tube over wire joint
2. Apply heat (heat gun or lighter) until shrink tubes tighten
3. Work safely — high temperature!

- [ ] All motor connections heat-shrinked
- [ ] All power connections heat-shrinked
- [ ] No exposed copper wire visible
- [ ] All joints are insulated

### Step 6.6: Cable Management

Organize wires with clips/ties:
- Motor cables bundled to motors
- Power cables routed away from signal cables
- Signal cables from Arduino to drivers clearly labeled

- [ ] Wiring is organized and labeled
- [ ] No cable strain on connectors
- [ ] Easy to trace signal flow

---

## Phase 7: Power & Testing

**Time:** 45–60 minutes  
**Components:** Gilivier 12V power supply

### Step 7.1: Power Supply Wiring

**Gilivier 12V 5A power supply:**

From power supply barrel jack or terminal block:
- Red (+12V) → Arduino Vin pin
- Black (GND) → Arduino GND (and all other GND points)

- [ ] 12V+ connected to Arduino Vin
- [ ] GND connected to Arduino GND
- [ ] Connections are secure (no loose wires)

### Step 7.2: Pre-Power Safety Check

**Before turning anything on:**

1. Visually inspect all wiring
2. Test continuity of power rail (multimeter: should read ~0.1Ω between + and -)
3. Verify no short circuits (multimeter: should read ∞ between + and any other point except -)
4. Confirm all motor cables are connected
5. Confirm servo cable is connected

- [ ] All visual inspections passed
- [ ] Continuity tests passed
- [ ] No loose wires or exposed connections

### Step 7.3: Initial Power-On (No Motors Yet)

1. Connect USB cable to Arduino (computer side)
2. Connect power supply 12V to Arduino Vin
3. Arduino should boot (LED on Arduino lights up)
4. Check Arduino IDE serial monitor (should show handshake)

- [ ] Arduino boots without errors
- [ ] No smoke or burnt smell
- [ ] Arduino LED lights up

### Step 7.4: Test Stepper Motors

Upload test sketch to Arduino (see `arduino/stepper-test.ino`):

```cpp
// Simple stepper motor test
#define DIR_X 2
#define STEP_X 3
#define DIR_Y 4
#define STEP_Y 5

void setup() {
  pinMode(DIR_X, OUTPUT);
  pinMode(STEP_X, OUTPUT);
  pinMode(DIR_Y, OUTPUT);
  pinMode(STEP_Y, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Test X-axis motor
  digitalWrite(DIR_X, HIGH);
  for (int i = 0; i < 200; i++) {  // 200 steps = 1 full rotation
    digitalWrite(STEP_X, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_X, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  
  // Reverse
  digitalWrite(DIR_X, LOW);
  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP_X, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_X, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
```

Expected behavior:
- X-axis motor should rotate in one direction
- Pause 1 second
- X-axis motor should rotate in reverse direction
- Bearing blocks on X-axis should move side-to-side

- [ ] X-axis motor rotates when powered
- [ ] X-axis bearing blocks move smoothly
- [ ] No grinding or skipping sounds
- [ ] Y-axis motor behaves similarly when tested

### Step 7.5: Test Servo

Upload servo test sketch (see `arduino/servo-test.ino`):

```cpp
#include <Servo.h>

Servo penServo;

void setup() {
  penServo.attach(9);  // Servo signal pin
  penServo.write(90);  // Center position
  Serial.begin(9600);
}

void loop() {
  penServo.write(45);   // Pen DOWN
  delay(2000);
  penServo.write(135);  // Pen UP
  delay(2000);
}
```

Expected behavior:
- Servo moves to 45° (pen down)
- Pause 2 seconds
- Servo moves to 135° (pen up)
- Pause 2 seconds
- Repeat

- [ ] Servo rotates smoothly
- [ ] Pen holder moves up and down
- [ ] No grinding or jittering
- [ ] Servo is controllable

### Step 7.6: Full Integration Test

Once individual components work:

1. Upload `plotter-controller.ino` (see `arduino/` directory)
2. Run Pi script: `python3 test_plotter.py` (see `scripts/`)
3. Pi sends commands to Arduino via serial
4. Arduino executes motion

Expected behavior:
- Motors move in coordinated fashion
- Pen lifts and lowers in sync with motion
- G-code commands execute smoothly

- [ ] G0 X100 Y50 moves plotter to position
- [ ] M3 lowers pen
- [ ] M5 raises pen
- [ ] G28 returns to home

---

## Troubleshooting

### Motor Doesn't Rotate

**Problem:** Motor shaft doesn't turn when powered

**Causes:**
- Coupler not tight (set screw loose)
- Wrong motor wiring (A+/A-/B+/B- reversed)
- Driver not powered (VMOT missing 12V)
- Arduino pin configuration wrong

**Fix:**
1. Check coupler set screw is tight
2. Test motor with multimeter (measure resistance between phases)
3. Verify 12V at VMOT pin on driver
4. Double-check Arduino code pin definitions

### Motor Skips Steps

**Problem:** Motor moves but not smoothly; stutters or skips

**Causes:**
- Timing belt too tight (binding)
- Bearing blocks too tight (friction)
- Stepper current too low (DRV8825 setting)
- Stepper pulse frequency too high

**Fix:**
1. Loosen timing belt tension (adjust idler springs)
2. Loosen bearing block set screws slightly
3. Increase DRV8825 current setting (potentiometer on driver)
4. Slow down step pulse frequency in Arduino code

### Servo Doesn't Move

**Problem:** Servo doesn't respond to commands

**Causes:**
- Signal pin not connected correctly
- Servo not receiving 5V power
- Servo control signal wrong frequency
- Arduino PWM pin misconfigured

**Fix:**
1. Verify servo signal cable to Arduino pin 9 (or configured pin)
2. Verify 5V + GND connected to servo
3. Use Arduino built-in Servo library (handles PWM correctly)
4. Test with simple servo sweep code first

### No Power at All

**Problem:** Nothing lights up; no Arduino LED

**Causes:**
- Power supply not connected
- Power supply is off/unplugged
- Wrong power cable polarity (12V+ and GND reversed)
- Arduino Vin pin damaged

**Fix:**
1. Verify power supply is plugged in and switched on
2. Check 12V output with multimeter (should read ~12V)
3. Verify polarity (red = +, black = -)
4. Try connecting power via USB (test if Arduino boots at all)

### Plotter Draws Crooked Lines

**Problem:** Lines are not straight; appear skewed or wavy

**Causes:**
- Frame not square (diagonal bracing needed)
- Bearing blocks misaligned
- Timing belts different tension
- Motor current settings unbalanced

**Fix:**
1. Measure frame diagonals (should be equal)
2. Inspect bearing blocks for binding (try manually moving axis)
3. Adjust idler tension springs to match both axes
4. Balance DRV8825 current settings (same for both drivers)

### Arduino Doesn't Upload Sketch

**Problem:** Upload fails with "Port not found" or "Device not recognized"

**Causes:**
- USB cable not connected
- USB driver not installed (Windows)
- Wrong board selected in Arduino IDE
- Arduino board damaged

**Fix:**
1. Verify USB cable is connected (both ends)
2. Install Arduino driver (Windows: https://www.arduino.cc/en/software)
3. Verify Board = "Arduino Uno" in Tools menu
4. Try different USB port (computer has multiple ports)
5. Test with bare Blink sketch first (verify basic upload works)

---

## Next Steps

Once build is complete and tested:

1. **Firmware Development**
   - Implement G-code parser on Arduino
   - Add acceleration/deceleration curves
   - Calibrate steps per mm

2. **Integration with FUCH_Visitors**
   - Write Pi-side G-code generator
   - Connect to Google Sheets API
   - Auto-print thank-you cards

3. **Calibration & Tuning**
   - Measure steps/mm for both axes
   - Test with various pen types
   - Optimize servo timing

4. **Documentation**
   - Record calibration values
   - Document firmware version
   - Create user manual for card printing

---

## Support & Resources

- **Arduino documentation:** https://www.arduino.cc/en/
- **DRV8825 datasheet:** TI DRV8825 stepper driver docs
- **G-code reference:** LinuxCNC G-code documentation
- **Community:** r/robotics, r/3Dprinting (CNC knowledge applies)

---

**Built:** Oct 30, 2026  
**Author:** David Hafner (Kavvika)  
**License:** MIT

<!-- project: path:/home/vautrin/.openclaw/workspace -->
