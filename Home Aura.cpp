
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define PROXIMITY_PIN 7
#define LDR_PIN A0
#define FAN_PIN 8
#define LIGHT_PIN 9

#define TEMP_THRESHOLD 30
#define LIGHT_THRESHOLD 200
#define PROXIMITY_THRESHOLD 10

// LCD display setup (address 0x27 for most I2C LCDs, 16 columns and 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(PROXIMITY_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  
  digitalWrite(LIGHT_PIN, LOW);
  digitalWrite(FAN_PIN, LOW);

  // Initialize the LCD
  lcd.begin(16,2);
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);
  int proximityDetected = digitalRead(PROXIMITY_PIN);
  float temperature = dht.readTemperature();
  
  // Light control logic
  if (proximityDetected == HIGH && lightLevel < LIGHT_THRESHOLD) {
    digitalWrite(LIGHT_PIN, HIGH);
  } else {
    digitalWrite(LIGHT_PIN, LOW);
  }
  
  // Fan control logic
  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }

  // Display "Welcome Back" and temperature if proximity is detected
  if (proximityDetected == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);  // Set cursor to the first row, first column
    lcd.print("Welcome Back");
    
    // Print temperature on the second row
    lcd.setCursor(0, 1);  // Set cursor to the second row, first column
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");
  }

  // Print data to the serial monitor for debugging
  Serial.print("Light Level: ");
  Serial.print(lightLevel);
  Serial.print("  Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  Proximity: ");
  Serial.println(proximityDetected == HIGH ? "Detected" : "Not Detected");
  
  delay(1000);
}
