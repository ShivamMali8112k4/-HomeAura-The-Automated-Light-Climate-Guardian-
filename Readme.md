# Smart Room Automation System 🏠✨

## Overview 📚
This **Smart Room Automation System** uses an **IR sensor**, **LDR (Light Dependent Resistor)**, and **DHT11 temperature sensor** to manage a **light** and **fan**. The system adjusts to the environment by detecting motion, ambient light, and temperature.

### Features ⚙️:
- **Motion Detection** using an **IR sensor** 👀
- **Light Control** based on **ambient light** 🌞 (including **PWM dimming** for smooth light adjustment)
- **Fan Control** based on **temperature** 🌡️ (multiple fan speeds)
- **LCD Display** showing **temperature** and "Welcome Back" message when motion is detected 💻

## Components Required 🔧:
- **IR Sensor** 👀
- **LDR (Light Dependent Resistor)** 🌞
- **DHT11 Temperature Sensor** 🌡️
- **16x2 I2C LCD Display** 💻
- **Fan** 🌀
- **Light** 💡
- **Arduino Board** 🖥️

## Circuit Diagram 🔌:
1. **IR Sensor** 👀 connected to **Pin 7**.
2. **LDR** 🌞 connected to **Analog Pin A0**.
3. **DHT11** 🌡️ connected to **Pin 2**.
4. **Fan** 🌀 connected to **Pin 8**.
5. **Light** 💡 connected to **Pin 9**.

![image alt](https://github.com/ShivamMali8112k4/img/blob/c5f53badc280e2eb9514871f2bf42eef9c2d1fcd/circuit_image%20(1).png)

## Code Explanation 💡:
- **Light Control**: The LDR controls the light, dimming or turning it on based on ambient light.
- **Fan Control**: The fan adjusts its speed based on temperature.
- **IR Sensor**: When motion is detected, the system displays a welcome message and temperature on the LCD.
  
---

### **How It Works** 🌟:

- **Motion Detection**: When the **IR sensor** detects motion, the system:
  1. Turns on the light if it's dark enough.
  2. Displays the **"Welcome Back"** message and the current **temperature** on the LCD.

- **Fan Control**: The fan speed is adjusted based on the temperature:
  - Above **30°C**, the fan runs at full speed.
  - Between **25°C** and **30°C**, the fan runs at medium speed.
  - Below **25°C**, the fan is off.

- **Light Control**: The light is dimmed based on the **LDR** reading:
  - If the room is dark, the light turns on at full brightness.
  - If it's bright, the light intensity is adjusted proportionally.


