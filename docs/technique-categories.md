# Technique Categories

This document outlines the core technical domains where the Teensy development board excels in red team scenarios. Each category includes the objective, the Teensy enablement factor, and the defensive perspective.

---

## ⌨️ USB HID Emulation

**Objective:** Automate human-like interactions (keyboard, mouse) to perform tasks at high speed and precision.

* **Teensy Enablement:** High-speed USB 2.0/3.0 emulation allowing for millisecond-accurate keystrokes and mouse movements. It can bypass software-based focus or input validation that doesn't expect hardware-level speed.
* **Adversary Behavior:** Automated initial execution, rapid credential harvesting via UI interaction, or automated local discovery.
* **Defensive Perspective:** Defenders should monitor for "superhuman" typing speeds and unexpected HID device registration, especially outside of standard working hours.

## 🚪 Initial Access Simulation

**Objective:** Gaining a foothold through physical proximity or "dropping" hardware.

* **Teensy Enablement:** Emulating trusted hardware IDs (VID/PID) to bypass basic endpoint security policies that block "unknown" USB devices.
* **Adversary Behavior:** Simulating a "BadUSB" style attack where a device executes a stage-0 payload upon insertion.
* **Defensive Perspective:** Organizations must move beyond VID/PID blacklisting towards more robust device identity and behavioral monitoring.

## 🏃 Execution Simulation

**Objective:** Bypassing software execution policies (e.g., AppLocker, WDAC) through hardware-orchestrated workflows.

* **Teensy Enablement:** Combining HID input with other USB classes (like Mass Storage or Ethernet) to deliver and execute payloads through non-standard channels.
* **Adversary Behavior:** Using HID to open a terminal and pull a second-stage payload from the Teensy acting as a virtual network adapter (RNDIS/NCM).
* **Defensive Perspective:** Execution detection should focus on child-process spawning from common "living-off-the-land" binaries (PowerShell, CMD, Bash) regardless of the trigger.

## 🕵️ Defense Evasion Concepts

**Objective:** Remaining undetected by host-based security controls.

* **Teensy Enablement:** Using composite device profiles (multiple USB functions in one device) to blend in. A Teensy can appear as a standard keyboard AND a proprietary serial device simultaneously.
* **Adversary Behavior:** Fragmenting payloads or using jitter in HID delivery to evade pattern-based detection of automated input.
* **Defensive Perspective:** EDR solutions need to correlate device insertion events with immediate anomalous process behavior.

## 🔑 Credential Interaction Scenarios

**Objective:** Interacting with login screens or credential prompts.

* **Teensy Enablement:** Automated brute-forcing of local PINs/PSKs where rate-limiting is not enforced at the hardware level, or capturing credentials via "Fake Keyboard" social engineering.
* **Adversary Behavior:** Repeatedly attempting combinations on a locked kiosk or mobile device.
* **Defensive Perspective:** Implement account lockout policies and monitor for unusual failed login patterns at physical terminals.

## 🌐 Red Team Tradecraft Enhancements

**Objective:** Assisting the operator with physical tools.

* **Teensy Enablement:** Creating custom "button-box" controllers for rapid execution of complex operator tasks, or building signal-to-USB bridges.
* **Adversary Behavior:** Using a physical button on a Teensy to quickly "kill" a simulation or rotate C2 configurations.
* **Defensive Perspective:** Understanding that attackers may use specialized hardware to improve their own operational security and speed.
