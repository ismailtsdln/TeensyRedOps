/*
 * TeensyRedOps - Educational Scenario TRO-004
 * Scenario: The Composite Ghost (Serial + HID)
 *
 * Objective:
 *   Demonstrate a composite device profile and basic cross-interface triggers.
 *   Note: In Teensyduino, select "Serial + Keyboard + Mouse" from the Tools >
 * USB Type menu.
 *
 * [!] FOR EDUCATIONAL RESEARCH ONLY.
 */

void setup() {
  Serial.begin(9600);
  delay(3000);

  Serial.println("[RESEARCH] Composite Device Active.");
  Serial.println("[RESEARCH] Waiting for trigger command over Serial...");
}

void loop() {
  // Wait for a command over the Serial interface to trigger a Keyboard action
  if (Serial.available() > 0) {
    char incoming = Serial.read();

    if (incoming == 'T') { // 'T' for Trigger
      Serial.println("[!] TRIGGER RECEIVED. Initiating HID Sequence...");
      executeHidSequence();
    }
  }
}

void executeHidSequence() {
  // Simple non-destructive verification
  Keyboard.set_modifier(MODIFIERKEY_LEFT_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  delay(500);
  clearKeys();

  Keyboard.print("cmd /c echo Composite Ghost Research Active & pause");
  Keyboard.press(KEY_ENTER);
  Keyboard.release(KEY_ENTER);
}

void clearKeys() {
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}
