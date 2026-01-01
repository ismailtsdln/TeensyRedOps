# Detection Notes: TRO-004 (The Composite Ghost)

Composite devices present a unique challenge for correlation. Many systems log individual interface registrations but fail to link them to the same physical device.

## 🕵️ Behavioral Indicators

### 1. Multi-Interface Registration (Registry/Logs)

Look for a single USB hub port that suddenly registers multiple distinct classes.

* **Registry Analysis (Windows):**
    Check `HKLM\SYSTEM\CurrentControlSet\Enum\USB`. A composite device will have a parent entry with multiple child `DeviceInstanceID`s.

* **Audit Query (PowerShell):**

    ```powershell
    Get-PnpDevice | Where-Object { $_.InstanceId -like "*PID_0482*" } | Select-Object FriendlyName, InstanceId, Status
    ```

    (Note: Replace PID with the Teensy composite ID if customized).

### 2. Time-Synchronized Device Bursts

When a composite device is plugged in, the OS triggers a burst of PnP (Plug and Play) events for each interface.

* **Detection Strategy:** Alert on more than 3 `DeviceEvents` where `ActionType == "UsbDeviceAttached"` occurring within 500ms on the same machine.

### 3. Cross-Class Triggers

Correlation between a Serial port receiving data and a Keyboard subsequently sending input.

## 🛡️ Best Practices

1. **Block Non-Essential Classes:** If a workstation only needs a mouse and keyboard, block the "Ports (COM & LPT)" class via GPO.
2. **Parent Device Monitoring:** Monitor `Event ID 20001` in the `Microsoft-Windows-PnPCustomizationsNonInteractive/Operational` log to see parent device metadata.
3. **Physical Port Hardening:** Use tools like `USBview` or specialized hardware to audit the physical topology of connected devices.
