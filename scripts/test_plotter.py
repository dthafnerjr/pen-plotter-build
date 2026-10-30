#!/usr/bin/env python3
"""
PEN PLOTTER TEST SCRIPT

Tests Arduino plotter controller via USB serial connection
Sends G-code commands and verifies responses

Usage:
    python3 test_plotter.py

Requirements:
    pip install pyserial
"""

import serial
import time
import sys

class PlotterController:
    def __init__(self, port='/dev/ttyACM0', baudrate=9600, timeout=1):
        """Initialize serial connection to Arduino"""
        try:
            self.ser = serial.Serial(port, baudrate, timeout=timeout)
            time.sleep(2)  # Wait for Arduino to initialize
            print(f"✅ Connected to {port} at {baudrate} baud")
        except serial.SerialException as e:
            print(f"❌ Failed to connect to {port}: {e}")
            sys.exit(1)
    
    def send_command(self, cmd):
        """Send G-code command and wait for response"""
        # Send command with newline
        self.ser.write((cmd + '\n').encode())
        
        print(f"→ {cmd}")
        
        # Wait for "OK" response
        response = self.ser.readline().decode().strip()
        
        if response:
            print(f"← {response}")
        
        time.sleep(0.1)
        return response
    
    def home(self):
        """Return to home position"""
        print("\n=== HOME ===")
        self.send_command("G28")
    
    def move_to(self, x, y, draw=False):
        """Move to position (with or without drawing)"""
        cmd = f"G{'1' if draw else '0'} X{x} Y{y}"
        self.send_command(cmd)
    
    def pen_down(self):
        """Lower pen"""
        print("↓ PEN DOWN")
        self.send_command("M3")
    
    def pen_up(self):
        """Raise pen"""
        print("↑ PEN UP")
        self.send_command("M5")
    
    def status(self):
        """Report current position"""
        print("\n=== STATUS ===")
        self.send_command("STATUS")
    
    def close(self):
        """Close serial connection"""
        self.ser.close()
        print("\n✅ Connection closed")


def test_sequence():
    """Run a complete test sequence"""
    
    plotter = PlotterController()
    
    try:
        print("\n" + "="*50)
        print("PEN PLOTTER TEST SEQUENCE")
        print("="*50)
        
        # Test 1: Home
        plotter.home()
        time.sleep(1)
        
        # Test 2: Move to start position
        print("\n=== MOVE TO START ===")
        plotter.move_to(50, 50)
        time.sleep(1)
        
        # Test 3: Pen down
        plotter.pen_down()
        time.sleep(0.5)
        
        # Test 4: Draw a line (X-axis)
        print("\n=== DRAW LINE (X-AXIS) ===")
        plotter.move_to(150, 50, draw=True)
        time.sleep(1)
        
        # Test 5: Pen up
        plotter.pen_up()
        time.sleep(0.5)
        
        # Test 6: Move to next position
        print("\n=== MOVE TO NEXT POSITION ===")
        plotter.move_to(50, 100)
        time.sleep(1)
        
        # Test 7: Pen down
        plotter.pen_down()
        time.sleep(0.5)
        
        # Test 8: Draw a line (Y-axis)
        print("\n=== DRAW LINE (Y-AXIS) ===")
        plotter.move_to(50, 150, draw=True)
        time.sleep(1)
        
        # Test 9: Pen up
        plotter.pen_up()
        time.sleep(0.5)
        
        # Test 10: Return home
        print("\n=== RETURN HOME ===")
        plotter.home()
        time.sleep(1)
        
        # Test 11: Status
        plotter.status()
        
        print("\n" + "="*50)
        print("✅ TEST SEQUENCE COMPLETE")
        print("="*50)
        
    except KeyboardInterrupt:
        print("\n\n⚠️ Test interrupted by user")
    except Exception as e:
        print(f"\n❌ Error during test: {e}")
    finally:
        plotter.close()


def interactive_mode():
    """Interactive command mode"""
    
    plotter = PlotterController()
    
    print("\n" + "="*50)
    print("PEN PLOTTER INTERACTIVE MODE")
    print("="*50)
    print("\nCommands:")
    print("  home                - Return to home (0, 0)")
    print("  status              - Show current position")
    print("  move X Y            - Move to position (no drawing)")
    print("  draw X Y            - Move to position (drawing)")
    print("  pen_down            - Lower pen")
    print("  pen_up              - Raise pen")
    print("  help                - Show this help")
    print("  exit                - Exit interactive mode")
    print()
    
    try:
        while True:
            cmd_input = input("plotter> ").strip()
            
            if not cmd_input:
                continue
            
            parts = cmd_input.split()
            cmd = parts[0].lower()
            
            if cmd == "exit":
                break
            elif cmd == "help":
                print("\nCommands:")
                print("  home, status, pen_down, pen_up")
                print("  move X Y - Move to (X, Y)")
                print("  draw X Y - Draw to (X, Y)")
                print()
            elif cmd == "home":
                plotter.home()
            elif cmd == "status":
                plotter.status()
            elif cmd == "pen_down":
                plotter.pen_down()
            elif cmd == "pen_up":
                plotter.pen_up()
            elif cmd == "move" and len(parts) == 3:
                try:
                    x = float(parts[1])
                    y = float(parts[2])
                    plotter.move_to(x, y, draw=False)
                except ValueError:
                    print("❌ Invalid coordinates")
            elif cmd == "draw" and len(parts) == 3:
                try:
                    x = float(parts[1])
                    y = float(parts[2])
                    plotter.move_to(x, y, draw=True)
                except ValueError:
                    print("❌ Invalid coordinates")
            else:
                print(f"❌ Unknown command: {cmd_input}")
                print("Type 'help' for available commands")
    
    except KeyboardInterrupt:
        print("\n\n✅ Goodbye!")
    except Exception as e:
        print(f"\n❌ Error: {e}")
    finally:
        plotter.close()


if __name__ == "__main__":
    if len(sys.argv) > 1:
        if sys.argv[1] == "--interactive":
            interactive_mode()
        else:
            print(f"Usage: {sys.argv[0]} [--interactive]")
            print()
            print("Run automatic test sequence (default)")
            print("Or use --interactive for manual control")
    else:
        test_sequence()
