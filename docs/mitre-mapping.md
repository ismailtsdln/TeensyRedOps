# MITRE ATT&CK® Mapping

This document provides a centralized view of how TeensyRedOps scenarios align with the MITRE ATT&CK framework.

| Scenario ID | Name | Tactics | Techniques |
| :--- | :--- | :--- | :--- |
| **TRO-001** | **The Rapid Foothold** | Initial Access, Execution | [T1059.001 (PowerShell)](https://attack.mitre.org/techniques/T1059/001/) |
| **TRO-002** | **Kiosk Breakout** | Execution, Discovery | [T1201 (Password Policy Discovery)](https://attack.mitre.org/techniques/T1201/), [T1566 (Phishing)](https://attack.mitre.org/techniques/T1566/) |
| **TRO-003** | **Credential Hunter** | Credential Access | [T1056.002 (GUI Input Capture)](https://attack.mitre.org/techniques/T1056/002/) |
| **TRO-004** | **The Composite Ghost** | Defense Evasion | [T1036 (Masquerading)](https://attack.mitre.org/techniques/T1036/), [T1200 (Hardware Additions)](https://attack.mitre.org/techniques/T1200/) |

---

## 🛡️ Tactic Breakdown

### Initial Access

Adversaries use the Teensy to gain a foothold via physical USB proximity, bypassing software-only network defenses.

### Execution

Automated HID inputs trigger the execution of local scripts or binaries, often leveraging "Living off the Land" techniques.

### Defense Evasion

Composite device profiles and masquerading techniques are used to blend in with authorized hardware and stay below the radar of EDR solutions.

### Credential Access

UI-based spoofing and automated input capture are used to harvest credentials directly from the user.
