# Setup & Hardware Guide

This guide details the requirements and steps to set up your environment for Teensy-based security research.

## 🛠️ Hardware Requirements

While many microcontrollers have USB capabilities, this project specifically focuses on the **Teensy** family due to its superior USB stack and performance.

| Model | Recommendation | Key Features |
| :--- | :--- | :--- |
| **Teensy 4.1** | **Highly Recommended** | 600 MHz, massive memory, support for all USB types. |
| **Teensy 4.0** | **Great Value** | Same speed as 4.1 in a smaller form factor. |
| **Teensy LC** | **Budget Choice** | Sufficient for simple HID tasks, lacks high-speed features. |

## 💻 Software Configuration

### 1. Arduino IDE

Download and install the latest **Arduino IDE** (v2.x recommended) from [arduino.cc](https://www.arduino.cc/en/software).

### 2. Teensyduino

Teensyduino is the software add-on that allows you to use the Arduino IDE with Teensy boards.

- Download from [pjrc.com/teensy/td_download.html](https://www.pjrc.com/teensy/td_download.html).
- Follow the installation instructions for your OS.

### 3. Board Configuration

In the Arduino IDE:

1. Go to `Tools > Board > Teensy` and select your model.
2. Go to `Tools > USB Type`. This is CRITICAL for our research.
    - For simple HID: Select `Keyboard`.
    - For advanced research (TRO-004): Select `Serial + Keyboard + Mouse + Joystick`.

## 🧪 Safety First

- **Isolated Lab:** Always test your payloads against isolated virtual machines or dedicated lab hardware.
- **Physical Lockdown:** Never use these techniques on systems you do not have explicit authorization to test.
- **Backup:** Keep a "Dead Man's Switch" (e.g., a physical button check) in your code to stop long-running HID loops.
