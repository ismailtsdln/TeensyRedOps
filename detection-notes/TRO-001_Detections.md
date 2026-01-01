# Detection Notes: TRO-001 (The Rapid Foothold)

This document provides specific guidance on how to detect the behaviors associated with the TRO-001 scenario.

## 🕵️ Behavioral Indicators

### 1. Rapid Command-Line Execution

Attackers using HID devices often bypass manual typing. A process like `powershell.exe` or `cmd.exe` appearing with long, complex command strings within seconds of a device insertion is a major red flag.

* **Query (Splunk/KQL):**

    ```kusto
    DeviceEvents
    | where ActionType == "UsbDeviceAttached"
    | join kind=inner (
        ProcessCreationEvents
        | where ProcessCommandLine contains "powershell"
    ) on DeviceId, $left.Timestamp <= $right.Timestamp and datetime_diff('second', $right.Timestamp, $left.Timestamp) < 10
    ```

### 2. Standard Teensy Hardware IDs

By default, Teensy devices use specific Vendor and Product IDs. While these can be changed in the firmware, many researchers use the defaults.

* **VID:** `16C0` (PJRC.COM)
* **PID:** `0482` (Teensy Keyboard/Mouse/Joystick)

* **Detection Strategy:** Create an alert for any new device registration where `VID == 16C0`.

### 3. PowerShell Script Block Logging (Event ID 4104)

Search for keywords commonly used in automated footholds even if they are non-destructive:
* `whoami`
* `hostname`
* `ipconfig`
* Redirects to `$env:TEMP` or `C:\Users\Public`

### 4. Anomalous Keyboard Speed

Advanced EDR tokens may capture the timestamp of individual keystrokes. If 100+ characters are entered in less than 200ms, it is a machine-driven interaction.

## 🛡️ Best Practices for Defenders

1. **Sysmon Configuration:** Ensure `ProcessCommandline` capture is enabled.
2. **Audit USB Insertion:** Enable Windows Event Log Category: *Object Access -> Audit External Storage*. (Note: This is usually for Mass Storage, use *Audit PnP Activity* for HID).
3. **Physical Locking:** Use Group Policy to enforce short inactivity timeouts for screen locking.
