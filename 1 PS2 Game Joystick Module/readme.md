# 🎮 PS2 Game Joystick Module Test with Arduino Uno  

This project tests the **PS2 Joystick Module (KY-023)** with an **Arduino Uno**. The joystick provides **X and Y axis values** and detects button presses. The output is displayed in the **Serial Monitor**.  

---

## 📌 What is a PS2 Joystick Module?  

The **PS2 Game Joystick Module (KY-023)** is an **analog joystick** similar to the one used in PlayStation controllers. It has:  

- **VRX (X-axis)** – Analog output for left-right movement.  
- **VRY (Y-axis)** – Analog output for up-down movement.  
- **SW (Switch)** – Detects when the joystick is pressed.  
- **VCC & GND** – Power supply connections.  

---

## 🛠 Components Required  

| Component                 | Quantity |
|---------------------------|----------|
| **Arduino Uno**           | 1 |
| **PS2 Joystick Module**   | 1 |
| **Jumper Wires**          | 5 |

---

## 📡 Connection Details  

| Joystick Module Pin | Arduino Uno Pin |
|----------------------|----------------|
| **VRX (X-axis)**    | **A0**         |
| **VRY (Y-axis)**    | **A1**         |
| **SW (Button)**     | **D2**         |
| **VCC**             | **5V**         |
| **GND**             | **GND**        |

### 🖼 Schematic Diagram  

![PS2 Joystick Schematic](https://user-images.githubusercontent.com/your-image-url.png) *(Replace with your image link)*  

---

## 💻 Code  

```cpp
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
