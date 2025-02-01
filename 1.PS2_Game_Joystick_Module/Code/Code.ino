// Define joystick pins
#define VRX A0  // X-axis pin
#define VRY A1  // Y-axis pin
#define SW  2   // Switch (button) pin

void setup() {
    pinMode(VRX, INPUT);
    pinMode(VRY, INPUT);
    pinMode(SW, INPUT_PULLUP); // Enable internal pull-up resistor for button
    Serial.begin(9600);
}

void loop() {
    // Read X and Y axis values (0 to 1023)
    int xValue = analogRead(VRX);
    int yValue = analogRead(VRY);

    // Read switch state (LOW when pressed)
    int buttonState = digitalRead(SW);

    // Print values to Serial Monitor
    Serial.print("X: ");
    Serial.print(xValue);
    Serial.print(" | Y: ");
    Serial.print(yValue);
    Serial.print(" | Button: ");
    Serial.println(buttonState == LOW ? "Pressed" : "Not Pressed");

    delay(200); // Delay for stability
}
