# Global Mitigation Strategy

Hardware-based USB attacks (like those simulated in this project) require a multi-layered defense strategy. Relying on a single control is often insufficient.

---

## 🛑 1. Physical Layer Controls

The most effective defense is preventing unauthorized physical access.

- **Workstation Locking:** Automated logout/lock policies using GPO or MDM.
- **USB Port Blockers:** Physical inserts that prevent devices from being plugged into unused ports.
- **Hardware Enclosures:** For kiosks and public terminals, ensure all ports are behind locked panels.

## 🛡️ 2. Operating System Hardening

- **USB Device Whitelisting:** Use Windows GPO (Device Installation Restrictions) or platforms like Microsoft Intune to allow ONLY known VIDs/PIDs.
- **Constrained Execution:**
  - Implement **PowerShell Constrained Language Mode**.
  - Use **AppLocker** or **Windows Defender Application Control (WDAC)** to block unauthorized scripts and binaries.
- **Interactive Logon Limits:** Disable "Auto-Logon" and require MFA for physical terminal access.

## 🔍 3. Detection & Monitoring

- **Endpoint Detection & Response (EDR):** Configure EDR to alert on anomalous process trees (e.g., `cmd.exe` spawned by `explorer.exe` with no user interaction).
- **Audit PnP Activity:** Enable Windows audit policies for "Plug and Play" events to track device registration in the Security log.
- **Input Speed Analysis:** Advanced monitoring for "superhuman" typing speeds (typing hundreds of characters per second).

## 👥 4. Human Factors

- **Social Engineering Awareness:** Educate employees to never plug in "found" hardware or "tokens" from untrusted sources.
- **Incident Response:** Ensure the SOC team has a playbook for "Anomalous USB Interaction" that includes physical investigation.
