# 🌟 Smart Room Automation System 🏠

This project is a simple **Smart Room Automation System** that controls a light 💡 and a fan 🌬 based on various conditions like proximity, temperature 🌡, and ambient light 🌞. It uses a combination of sensors and an LCD display to give feedback on the status.

## 🛠 Components Used:
- **DHT11**: Temperature and humidity sensor 🌡💧
- **HC-SR04** (optional): Proximity sensor (in case you want to include it)
- **LDR**: Light-dependent resistor to measure ambient light
- **Fan**: Controlled via a relay or transistor to turn on/off based on temperature
- **LED**: Controlled to turn on/off based on proximity and light conditions 
- **LCD**: 16x2 LCD with I2C for displaying temperature and status 📺
- **Arduino**: Microcontroller to handle all sensor readings and control the outputs 🖥

## 💡 Features:
- **Proximity-based Light Control**: The light will automatically turn on when someone is detected nearby (via a proximity sensor) and the ambient light level is low. 🔦
- **Temperature-based Fan Control**: If the temperature exceeds a threshold (30°C), the fan will turn on.
- **LCD Display**: The LCD will show a greeting message when someone is detected and will display the current temperature. 📺
- **Serial Monitor Output**: Data about the light level, temperature, and proximity detection is printed to the serial monitor for debugging purposes.

## 🔌 Wiring:
- **DHT11**: Connect to pin `2` for temperature readings 
- **LDR**: Connect to analog pin `A0` for light level sensing 
- **Proximity Sensor**: Connect to pin `7` to detect motion or presence 
- **Fan**: Connect to pin `8` to control fan operation 
- **Light**: Connect to pin `9` to control the light 

## 📜 Code Walkthrough:
1. **Libraries**:
   - `DHT.h`: For interacting with the DHT11 temperature sensor 🌡
   - `Wire.h` and `LiquidCrystal_I2C.h`: For communicating with the LCD display over I2C 📺

2. **Pin Definitions**:
   - Defines the pins for the temperature sensor, light, fan, and proximity sensor.
   
3. **Thresholds**:
   - The temperature threshold is set to 30°C 🌡 for fan control.
   - The light threshold is set to 200 for ambient light levels.
   - The proximity threshold is set to detect motion based on the sensor input.

4. **LCD Setup**:
   - LCD initialized to show "Welcome Back" when proximity is detected and will display the current temperature 🌡.
   
5. **Control Logic**:
   - If the proximity sensor detects motion and the ambient light is low, the light turns on.
   - If the temperature exceeds the threshold, the fan turns on.
   - Data is also printed to the serial monitor for debugging 🖥.
