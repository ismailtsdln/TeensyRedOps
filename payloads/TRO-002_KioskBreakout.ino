/*
 * TeensyRedOps - Educational Scenario TRO-002
 * Scenario: Kiosk Breakout Simulation (Windows Focus)
 *
 * Objective:
 *   Automated "hotkey spray" to test kiosk lockdown boundaries.
 *
 * [!] FOR EDUCATIONAL RESEARCH ONLY.
 */

void setup() {
  delay(3000); // 3 sec breathing room

  // 1. Try to minimize everything (Win+D)
  Keyboard.set_modifier(MODIFIERKEY_LEFT_GUI);
  Keyboard.set_key1(KEY_D);
  Keyboard.send_now();
  delay(100);
  clearKeys();
  delay(1000);

  // 2. Try to close active window (Alt+F4)
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_F4);
  Keyboard.send_now();
  delay(100);
  clearKeys();
  delay(1000);

  // 3. Try to open Task Manager (Ctrl+Shift+Esc)
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
  Keyboard.set_key1(KEY_ESC);
  Keyboard.send_now();
  delay(100);
  clearKeys();
  delay(2000);

  // 4. Try the "Advanced User" menu (Win+X)
  Keyboard.set_modifier(MODIFIERKEY_LEFT_GUI);
  Keyboard.set_key1(KEY_X);
  Keyboard.send_now();
  delay(100);
  clearKeys();

  // NOTE: This payload does not execute commands.
  // It only tests if UI elements respond to these inputs.
}

void clearKeys() {
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void loop() {}
