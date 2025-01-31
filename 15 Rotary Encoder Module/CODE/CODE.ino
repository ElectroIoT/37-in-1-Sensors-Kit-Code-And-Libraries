#define CLK 2  // Rotary Encoder Clock pin
#define DT 3   // Rotary Encoder Data pin
#define SW 4   // Rotary Encoder Switch pin

int lastStateCLK;
int currentStateCLK;

void setup() {
    pinMode(CLK, INPUT);
    pinMode(DT, INPUT);
    pinMode(SW, INPUT_PULLUP);  // Internal pull-up resistor enabled for button

    Serial.begin(9600);
    lastStateCLK = digitalRead(CLK); // Read initial state of CLK
}

void loop() {
    currentStateCLK = digitalRead(CLK);

    // If the state of CLK has changed, determine rotation direction
    if (currentStateCLK != lastStateCLK) {
        if (digitalRead(DT) != currentStateCLK) {
            Serial.println("Rotated: Clockwise");
        } else {
            Serial.println("Rotated: Counterclockwise");
        }
    }
    lastStateCLK = currentStateCLK;

    // Check if the button is pressed
    if (digitalRead(SW) == LOW) {
        Serial.println("Button Pressed");
        delay(200); // Debounce delay
    }
}
