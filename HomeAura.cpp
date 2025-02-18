#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define IR_SENSOR_PIN 7  // Pin for the IR sensor
#define LDR_PIN A0       // Pin for the LDR sensor
#define FAN_PIN 8
#define LIGHT_PIN 9

#define TEMP_THRESHOLD 30  // Temperature threshold to control the fan
#define LIGHT_THRESHOLD 200  // Light threshold to control the light (darker room)

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD display setup (I2C address 0x27)

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(IR_SENSOR_PIN, INPUT);  // Set IR sensor pin as input
  pinMode(LIGHT_PIN, OUTPUT);     // Set light pin as output
  pinMode(FAN_PIN, OUTPUT);       // Set fan pin as output
  
  digitalWrite(LIGHT_PIN, LOW);   // Ensure light is off initially
  digitalWrite(FAN_PIN, LOW);     // Ensure fan is off initially

  lcd.begin(16, 2);  // Initialize the LCD
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);  // Read the light level from LDR
  int irDetected = digitalRead(IR_SENSOR_PIN);  // Read the IR sensor output
  float temperature = dht.readTemperature();  // Read the temperature

  // Light control logic using LDR
  if (lightLevel < LIGHT_THRESHOLD) {  // If it's dark enough
    digitalWrite(LIGHT_PIN, HIGH);  // Turn on the light
  } else {
    digitalWrite(LIGHT_PIN, LOW);   // Turn off the light
  }

  // Fan control logic based on temperature
  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(FAN_PIN, HIGH);    // Turn on the fan if temperature exceeds the threshold
  } else {
    digitalWrite(FAN_PIN, LOW);     // Turn off the fan otherwise
  }

  // Display message and temperature if IR sensor detects something
  if (irDetected == HIGH) {
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
  Serial.print(lightLevel);  // Print the current light level
  Serial.print("  Temperature: ");
  Serial.print(temperature);  // Print the current temperature
  Serial.print(" °C  IR Sensor: ");
  Serial.println(irDetected == HIGH ? "Detected" : "Not Detected");
  
  delay(1000);  // Wait for a second before the next loop
}
