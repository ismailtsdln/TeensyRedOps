# Detection & Mitigation Template

- **Technique:** [Technique Name]
- **Category:** [Category Name]
- **Severity:** [Low / Medium / High / Critical]

---

## 🔍 Detection Strategy

### 💻 Endpoint Telemetry (EDR/Sysmon)

* **Process Creation:** [e.g., Monitor for powershell.exe with -EncodedCommand shortly after USB insertion]
- **Input Monitoring:** [e.g., EDR alerts for high-frequency keystroke events]
- **Registry Keys:** [e.g., Changes to HKLM\SYSTEM\CurrentControlSet\Enum\USB]

### 🪵 Log Analysis (Event Viewer / SIEM)

* **Windows Event ID 4104:** [Powershell Script Block Logging]
- **Windows Event ID 4624:** [Logon events triggered by HID]
- **Linux/udev Logs:** [Monitoring /var/log/syslog for device enumeration]

### 📡 Network Visibility

* **Anomalous Traffic:** [e.g., DNS exfiltration initiated via HID-driven terminal]
- **Interface Monitoring:** [e.g., New virtual network interfaces appearing suddenly]

---

## 🛡️ Mitigation Controls

### 🏗️ Architectural Controls

* **USB Port Lockdown:** [Physical or BIOS-level disabling of unused ports]
- **Device Whitelisting:** [Using GPO or MDM to only allow specific VIDs/PIDs]

### ⚙️ Operating System Hardening

* **Execution Policies:** [Implementing AppLocker, WDAC, or SELinux in enforcing mode]
- **Interactive Logon Limits:** [Disabling automatic logon and enforcing MFA]

### 👥 Human Factors

* **User Training:** [Recognizing "found" USB devices and reporting anomalous keyboard behavior]
- **Incident Response:** [Defining playbooks for "Hardware-based Intrusion" scenarios]

---

## 🧪 Validation Labs

[Link to relevant lab in /labs directory for testing these detections]
