# Detection Notes: TRO-002 (Kiosk Breakout)

Detecting a kiosk breakout requires correlation between hardware events and UI-level behaviors.

## 🕵️ Behavioral Indicators

### 1. Hotkey "Spamming"

Unlike a human who might try one combination and wait, a programmed device will cycle through many escapes in rapid succession.

* **EDR Detection:** Monitor for multiple "privileged" shortcut executions (Win+X, Ctrl+Shift+Esc) within a 5-second window.

### 2. Forbidden Process Launch

In a locked-down environment, `taskmgr.exe`, `mmc.exe`, or `cmd.exe` should never be seen.

* **Query (Sysmon):**

    ```text
    EventID: 1 (Process Create)
    Image: *taskmgr.exe OR *cmd.exe
    User: [KioskUserAccount]
    ```

### 3. Registry Monitoring

Some advanced breakouts involve using "Sticky Keys" or other accessibility features.

* **Monitor:** `HKCU\Control Panel\Accessibility` for unexpected changes.

## 🛡️ Best Practices for Kiosks

1. **Assigned Access:** Use Windows 10/11 "Assigned Access" (Single App Mode) which natively blocks most hotkeys at the kernel level.
2. **NoWinKeys:** Set `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoWinKeys` to `1`.
3. **Bios/Port Security:** Password protect BIOS and physically seal internal USB ports.
