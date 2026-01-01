# Lab & Education Ideas

The goal of these labs is to provide a safe, structured environment for understanding and detecting hardware-based offensive techniques.

## 🧪 Lab 1: The Visibility Challenge

* **Concept:** Deploy a Teensy with a basic HID payload against a "Detection-Ready" VM (Sysmon, Windows Event Logs forwarded to an ELK stack).
* **Learning Objective:** Identify exactly which log entries are generated upon insertion and execution.
* **Outcome:** Students create a Snort or Sigma rule based on their findings.

## 🧪 Lab 2: VID/PID Spoofing & Whitelisting

* **Concept:** Attempt to gain access to a system that has USB whitelisting enabled by spoofing the ID of a "Pre-Approved" hardware device (e.g., a specific Logitech mouse).
* **Learning Objective:** Understand the limitations of ID-based filtering.
* **Outcome:** Implementation of behavioral-based blocking policies.

## 🧪 Lab 3: The Composite Correlation

* **Concept:** Use a Teensy as a composite device. Analyze how the OS treats the "split" identity and whether security software correlates the events correctly.
* **Learning Objective:** Researching data correlation in EDR/SIEM.

## 🧪 Lab 4: Social Engineering via Hardware

* **Concept:** Build a "Physical Hardware Token" (Teensy in a 3D-printed case) and design a scenario where a user is tricked into using it.
* **Learning Objective:** Highlighting the human element in hardware security.
