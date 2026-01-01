# Example Scenarios

This directory contains initial research stubs for Teensy-based red team simulations.

## 📋 Planned Scenarios

| ID | Name | Category | Status |
| :--- | :--- | :--- | :--- |
| **TRO-001** | **The Rapid Foothold** | Initial Access | Stub |
| **TRO-002** | **Kiosk Breakout Simulation** | Execution | Stub |
| **TRO-003** | **Credential Hunter (UI-Based)** | Credentials | Stub |
| **TRO-004** | **The Composite Ghost** | Defense Evasion | Stub |

---

### [NEW] [TRO-001: The Rapid Foothold](docs/scenarios/TRO-001.md)

* **Focus:** Simulating a fast-acting HID payload that opens a terminal and executes a non-destructive verification command (e.g., `whoami /all > %TEMP%\research.txt`).
* **Goal:** Demonstrate the speed of hardware-orchestrated initial execution.

### [NEW] [TRO-002: Kiosk Breakout Simulation](docs/scenarios/TRO-002.md)

* **Focus:** Using specific keyboard shortcuts (Alt+Tab, Win+R, Ctrl+Shift+Esc) to simulate escaping a restricted UI environment.
* **Goal:** Test the robustness of locked-down terminals.

### [NEW] [TRO-003: Credential Hunter (UI-Based)](docs/scenarios/TRO-003.md)

* **Focus:** Simulating a social engineering scenario where a prompt is generated to trick a user into entering credentials, which are then transmitted via HID-based typing.
* **Goal:** Educate on UI-level spoofing and interaction.

### [NEW] [TRO-004: The Composite Ghost](docs/scenarios/TRO-004.md)

* **Focus:** Configuring the Teensy as a Composite Device (Keyboard + Serial) to research how EDR logs multiple device types from a single port.
* **Goal:** Visibility and detection correlation research.
