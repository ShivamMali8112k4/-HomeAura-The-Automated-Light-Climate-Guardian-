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

#define TEMP_THRESHOLD_LOW 25  // Lower temperature threshold for fan speed control
#define TEMP_THRESHOLD_HIGH 30  // Upper temperature threshold for fan speed control
#define LIGHT_THRESHOLD 200  // Light threshold to control the light (darker room)
#define IR_SENSOR_DETECTION_DELAY 2000  // Delay for IR sensor detection (in milliseconds)

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD display setup (I2C address 0x27)

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(IR_SENSOR_PIN, INPUT);  // IR sensor pin
  pinMode(LIGHT_PIN, OUTPUT);     // Light pin
  pinMode(FAN_PIN, OUTPUT);       // Fan pin
  
  digitalWrite(LIGHT_PIN, LOW);   // Ensure light is off initially
  digitalWrite(FAN_PIN, LOW);     // Ensure fan is off initially

  lcd.begin(16, 2);  // Initialize LCD
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);  // Read the light level from LDR
  int irDetected = digitalRead(IR_SENSOR_PIN);  // Read the IR sensor output
  float temperature = dht.readTemperature();  // Read the temperature

  // Light control logic using LDR (PWM for dimming control)
  if (lightLevel < LIGHT_THRESHOLD) {  // If it's dark enough
    analogWrite(LIGHT_PIN, 255);  // Turn on the light at full brightness
  } else {
    int dimmingValue = map(lightLevel, 0, 1023, 0, 255);  // Map the light level to PWM range
    analogWrite(LIGHT_PIN, dimmingValue);  // Adjust light intensity based on ambient light
  }

  // Fan control logic based on temperature
  if (temperature > TEMP_THRESHOLD_HIGH) {
    analogWrite(FAN_PIN, 255);  // Turn on the fan at full speed
  } else if (temperature > TEMP_THRESHOLD_LOW) {
    analogWrite(FAN_PIN, 128);  // Turn on the fan at medium speed
  } else {
    digitalWrite(FAN_PIN, LOW); // Turn off the fan
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

    delay(IR_SENSOR_DETECTION_DELAY);  // Wait for 2 seconds to prevent flickering
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
