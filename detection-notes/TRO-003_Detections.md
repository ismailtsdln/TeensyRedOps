# Detection Notes: TRO-003 (Credential Hunter)

UI-based capture is subtle but has characteristic fingerprints.

## 🕵️ Behavioral Indicators

### 1. PowerShell GUI Interactions

Standard scripts rarely use `Get-Credential` in non-interactive background tasks.

* **Query (Splunk):**

    ```text
    index=logs sourcetype=WinEventLog:Microsoft-Windows-PowerShell/Operational EventCode=4104
    Message="*Get-Credential*"
    ```

### 2. Sudden Launch of User Input Forms

Monitor for processes that create windows with title text related to "Credentials", "Login", or "Verification" from non-parent processes like PowerShell or CMD.

## 🛡️ Best Practices

1. **Windows Defender Credential Guard:** Use virtualization-based security to isolate secrets so even if the UI is spoofed, system secrets remain protected.
2. **MFA Everywhere:** Even if a password is captured, MFA blocks the secondary use of the credential.
3. **Process Tree Analysis:** Detect if `powershell.exe` is a child of an unexpected process or has no logical reason to be popping a UI.
