# Smart Room Automation System: Working Explanation

### Overview: 🏠
The **Smart Room Automation System** is designed to automate various functions in a room using sensors, including temperature control, light control, and motion detection. The system utilizes an **IR sensor**, **LDR sensor**, and a **DHT11 temperature sensor** to detect the environment and adjust actions accordingly.

---

### Components Used: 🔧
- **DHT11 Sensor**: Measures temperature and humidity.
- **IR Sensor**: Detects the presence of people in the room.
- **LDR Sensor**: Measures light intensity to control room lighting.
- **Fan**: A cooling device controlled by temperature.
- **Light**: Controlled based on light intensity (via LDR) and presence detection (via IR sensor).
- **LCD Display**: Displays temperature and messages.

---

### 1. **Libraries and Setup** 📚
The code includes necessary libraries:
- `DHT.h`: For handling the DHT11 temperature sensor.
- `Wire.h` and `LiquidCrystal_I2C.h`: For controlling the I2C LCD display.

The `setup()` function initializes:
- **Serial communication** for debugging.
- **DHT sensor** for temperature measurement.
- **Pins** for IR sensor, LDR sensor, fan, and light control.
- **LCD display** for showing messages like "Welcome Back" and the current temperature.

---

### 2. **Sensor Pin Initialization** ⚙️
- **IR Sensor (Pin 7)**: Detects if someone is present in the room (motion detection).
- **LDR Sensor (Pin A0)**: Reads light intensity in the room.
- **Fan (Pin 8)**: Controlled based on temperature.
- **Light (Pin 9)**: Controlled based on ambient light and motion detection.

---

### 3. **Main Logic Flow** 🔄
The `loop()` function runs continuously, monitoring and responding to sensor readings.

#### 3.1 **Light Control** 💡
- The **LDR sensor** continuously checks the light intensity.
  - If the light level is below the threshold (`LIGHT_THRESHOLD`), the light will be turned on.
  - If the room is bright enough, the light is turned off.
  
---

#### 3.2 **Fan Control** 🌬
- The **temperature** is read from the DHT11 sensor.
  - If the temperature is **above the upper threshold** (`TEMP_THRESHOLD_HIGH`), the fan runs at full speed.
  - If the temperature is between the **lower threshold** (`TEMP_THRESHOLD_LOW`) and upper threshold, the fan runs at a medium speed.
  - If the temperature is **below the lower threshold**, the fan is turned off.

---

#### 3.3 **IR Sensor** 🛠
- The **IR sensor** detects the presence of a person.
  - If motion is detected (IR sensor output is `HIGH`), the system will display "Welcome Back" on the LCD and show the current **temperature**.
  - If no motion is detected, the LCD remains inactive.

---

#### 3.4 **LCD Display** 📺
- When a person enters the room (IR sensor detects), the LCD shows:
  - "Welcome Back" on the first row.
  - The current temperature on the second row.
  
---

#### 3.5 **Serial Monitor Output** 💻
The system sends regular updates to the **Serial Monitor** for debugging:
- Current **light level** (LDR sensor reading).
- Current **temperature** (from DHT11 sensor).
- **IR sensor status** (whether motion was detected or not).

---

### 4. **Flow Summary**:

1. **When someone enters the room**:
   - The **IR sensor** detects motion.
   - If the room is dark (LDR sensor detects low light), the **light** turns on.
   - The **LCD** displays a welcome message and the current **temperature**.
   - The **fan** turns on if the temperature is above the defined threshold.

2. **When no one is in the room**:
   - The **IR sensor** does not detect motion.
   - The **light** turns off if it was on.
   - The **fan** remains off if the temperature is below the threshold.

3. **General Behavior**:
   - The **fan** adjusts its speed based on the temperature.
   - The **light** adjusts its brightness based on the room's ambient light.

---

### 5. **Key Features**:
- **Proximity Detection**: IR sensor detects when someone enters the room and triggers actions such as displaying a message or adjusting fan speed.
- **Temperature Control**: Automatically turns the fan on or off based on temperature.
- **Light Control**: Automatically adjusts the lighting based on ambient light levels.
- **Real-time Feedback**: LCD display and Serial Monitor provide real-time feedback of sensor data and system status.

This system creates a more intelligent environment, adapting to changes and providing a comfortable atmosphere!

---
