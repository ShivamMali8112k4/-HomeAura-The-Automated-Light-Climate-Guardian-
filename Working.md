### Working of the Code: 🌟

The code controls a **Smart Room Automation System** using sensors (proximity, light, and temperature) and an LCD display to provide a personalized experience. Let's break down how it works:

---

### 1. **Libraries and Setup** 📚

The code begins by importing the required libraries:
- `DHT.h`: For interacting with the DHT11 temperature and humidity sensor.
- `Wire.h` and `LiquidCrystal_I2C.h`: For communicating with the I2C-based LCD display.

In the `setup()` function:
- **Serial communication** is initialized to allow debugging and printing data to the Serial Monitor.
- The **DHT sensor** is initialized with `dht.begin()`, setting up the temperature sensor.
- The **pins** are defined for the sensors (proximity, light, LDR, fan, and light control).
- **LCD display** is set up with backlight and is cleared to show fresh content.

### 2. **Sensor Pin Initialization** ⚙️
The following pins are defined for interaction:
- **Proximity Sensor (Pin 7)**: Detects motion or presence in the room. If someone walks by, it will trigger a response.
- **LDR (Pin A0)**: A light sensor that reads ambient light levels in the room.
- **Fan (Pin 8)**: Turns the fan on or off depending on the temperature threshold.
- **Light (Pin 9)**: Controls the light in the room based on proximity and ambient light.

### 3. **Main Loop** 🔄

The `loop()` function is where the core logic runs continuously.

#### 3.1 **Sensor Readings** 📊

- **Light Level**: The LDR reads the current light level in the room using `analogRead(LDR_PIN)`. The value is between `0` (dark) and `1023` (bright).
- **Proximity Detection**: The proximity sensor reads the presence of a person via `digitalRead(PROXIMITY_PIN)`. If motion is detected, it returns `HIGH`; otherwise, it returns `LOW`.
- **Temperature**: The DHT11 sensor reads the current temperature via `dht.readTemperature()`. This returns the temperature in Celsius.

#### 3.2 **Light Control** 💡
The light is turned on or off depending on two conditions:
1. If **proximity is detected** (`proximityDetected == HIGH`), meaning someone is in the room.
2. If the **ambient light is below the defined threshold** (`lightLevel < LIGHT_THRESHOLD`), meaning it's dark in the room.

- **If both conditions are true**, the light will be turned on with `digitalWrite(LIGHT_PIN, HIGH)`.
- **Otherwise**, the light will be turned off with `digitalWrite(LIGHT_PIN, LOW)`.

#### 3.3 **Fan Control** 🌬

The fan turns on or off based on the temperature:
- If the **temperature exceeds the threshold** (30°C in this case), the fan will be turned on using `digitalWrite(FAN_PIN, HIGH)`.
- If the temperature is **below the threshold**, the fan will be turned off with `digitalWrite(FAN_PIN, LOW)`.

#### 3.4 **LCD Display** 📺
- If **proximity is detected** (i.e., someone is in the room), the LCD display will show:
  - "Welcome Back" on the first line (greeting the person).
  - The current **temperature** on the second line in the format `Temp: XX.X C`.

If **no proximity is detected**, the LCD does not display anything specific.

#### 3.5 **Serial Monitor Output** 💻

For debugging purposes, the code prints the following information to the Serial Monitor every second (via `delay(1000)`):
- **Light Level**: The current light intensity detected by the LDR.
- **Temperature**: The current temperature in Celsius.
- **Proximity**: Whether someone is detected by the proximity sensor (either "Detected" or "Not Detected").

---

### 4. **Flow Summary**:

1. **When someone enters the room**:
   - The proximity sensor detects motion.
   - If the light is below the threshold, the light turns on.
   - The LCD displays "Welcome Back" and the current temperature.
   - If the temperature is above 30°C, the fan turns on.

2. **When the room is empty**:
   - The proximity sensor does not detect anyone.
   - The light turns off if it was on.
   - The fan remains off if the temperature is below 30°C.

3. **In any case**:
   - The Serial Monitor logs the current light level, temperature, and proximity detection status for debugging purposes.

---

### Key Points:
- The system operates continuously, monitoring the sensors.
- **Proximity detection** triggers actions like turning on the light and displaying a message on the LCD.
- **Temperature** control ensures the fan turns on when it gets too hot.
- **Ambient light level** controls the light based on how bright it is in the room.
- **LCD display** and **Serial Monitor** are used for feedback and debugging.

This system makes your room more responsive to the environment, automatically adjusting to the needs of the user! 😊
