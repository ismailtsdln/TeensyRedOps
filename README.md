# TeensyRedOps 🛠️🔴

**Advanced Red Team & Adversary Simulation Research with Teensy Microcontrollers**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Security: Red Team](https://img.shields.io/badge/Security-Red%20Team-red.svg)](https://github.com/ismailtsdln/TeensyRedOps)
[![Research: Educational](https://img.shields.io/badge/Research-Educational-blue.svg)](https://github.com/ismailtsdln/TeensyRedOps)

## ⚖️ Ethical Disclaimer & Legal Notice

> [!CAUTION]
> **FOR EDUCATIONAL AND AUTHORIZED TESTING PURPOSES ONLY.**
>
> The contents of this repository are intended for security researchers, penetration testers, and red team operators performing authorized simulations. Unauthorized access to computer systems is illegal. The maintainer(s) of this project assume no liability for misuse or damage caused by the information or code provided herein.
>
> **Always ensure you have written authorization before testing any technique.**

---

## 🎯 Project Overview

**TeensyRedOps** is a specialized repository dedicated to documenting, researching, and simulating offensive security techniques utilizing the **Teensy** development board. As a powerful, USB-capable microcontroller, the Teensy allows for sophisticated hardware-based simulations that go beyond traditional software-only vectors.

Our mission is to bridge the gap between hardware hacking and red team tradecraft, providing a structured framework for:

- Adversary emulation focusing on physical/USB vectors.
- Educational labs for defenders to improve detection capabilities.
- Research into USB HID, Composite, and NCM/RNDIS behaviors.

---

## 🔍 Project Goals

1. **Comprehensive Reference:** A master repository for Teensy-based red team scenarios.
2. **Modular Structure:** Clean categorization of techniques mapped to adversary behaviors.
3. **Blue Team Empowerment:** Detailed detection notes and mitigation strategies for every technique.
4. **ATT&CK Integration:** Aligning hardware-based attacks with the MITRE ATT&CK® framework.

---

## 🏗️ Repository Structure

| Directory | Description |
| :--- | :--- |
| `docs/` | Comprehensive technical documentation and technique deep-dives. |
| `payloads/` | Educational (non-destructive) code examples for various scenarios. |
| `scenarios/` | Realistic simulation playbooks and high-level flow descriptions. |
| `labs/` | Guided environments for safe reproduction and detection training. |
| `firmware/` | Base configurations and hardware setup guides. |
| `detection-notes/` | Specialized guidance on how to identify these behaviors in logs/EDR. |
| `mitigations/` | Defensive controls for OS, Network, and Physical security layers. |
| `references/` | Curated list of external research, tools, and technical specifications. |

---

## 🏷️ Technique Categories

### ⌨️ USB HID Emulation

* **Objective:** Simulating rapid, automated keyboard/mouse input to bypass traditional software barriers.
- **Red Team Use:** Automated execution of commands, social engineering support, and rapid exfiltration.
- **Defensive Focus:** Monitoring for anomalous input speeds and device registration logs.

### 🚪 Initial Access Simulation

* **Objective:** Utilizing physical USB proximity to gain an initial foothold.
- **Enhancements:** Emulating trusted peripherals to bypass "Basic USB Blocking" policies.
- **Defensive Focus:** Hardware ID (VID/PID) whitelisting and physical access controls.

### 🛡️ Defense Evasion Concepts

* **Objective:** Researching how hardware-level interactions can stay below the radar of traditional EDR/AV.
- **Focus:** Composite device behaviors and timing-based execution patterns.

---

## 📝 Scenario Template

Every scenario in this project follows a standardized format to ensure professional documentation:

| Section | Description |
| :--- | :--- |
| **Scenario Name** | Clear, descriptive title. |
| **Threat Model** | Which adversary or behavior is being emulated? |
| **Attack Objective** | What is the end goal (e.g., Credential Access, Execution)? |
| **Hardware Required** | Teensy model and necessary peripherals. |
| **High-Level Flow** | Logical steps of the interaction (No destructive commands). |
| **Detection Surface** | Which logs (Event IDs, Sysmon) capture this activity? |
| **Mitigation** | How can an organization prevent or contain this vector? |

---

## 🧪 Education & Lab Focus

We focus on **Visibility** and **Response**.

- Our labs are designed to be run in isolated VMs or air-gapped hardware.
- We emphasize the use of tools like **Sysmon**, **USBLogView**, and specialized EDR hunting queries to find "The Ghost in the USB."

---

## 🤝 Contributing

Contributions are welcome! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on:

- Adding new technique research.
- Improving detection notes.
- Submitting lab ideas.

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Built with ❤️ for the Security Community by [Ismail Tasdelen](https://github.com/ismailtsdln)**
