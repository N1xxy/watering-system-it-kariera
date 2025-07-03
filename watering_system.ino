#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int moisturePin = A0;
const int maxSensor = 1023; // dry
const int minSensor = 200;   // wet

void setup() {
  lcd.begin(16, 2); // 16x2 display
}

void loop() {
  int moistureRaw = analogRead(moisturePin);

  // Convert raw to percentage: 100% = wet, 0% = dry
  int moisturePercent = map(moistureRaw, minSensor, maxSensor, 100, 0);
  moisturePercent = constrain(moisturePercent, 0, 100); // keep within bounds

  String status;
  if (moisturePercent > 70) {
    status = "Wet";
  } else if (moisturePercent > 40) {
    status = "Okay";
  } else {
    status = "Dry";
  }

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  lcd.print(status);

  delay(200);
}
