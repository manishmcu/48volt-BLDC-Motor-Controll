# ⚙️ 48V BLDC Motor Controller with Ultrasonic Sensor

This Arduino-based project demonstrates how to control a 48V, 750W BLDC motor automatically using real-time distance data from an **HC-SR04 Ultrasonic Sensor**. The system detects obstacles ahead and adjusts motor speed, braking, and lighting accordingly.

---

## 🧠 Features

- 🔄 Fully automated motor control with forward, reverse, and braking
- 🧭 Distance-based behavior:
  - **100cm–40cm** → Slow down
  - **40cm–10cm** → Stop & Alert
  - **<10cm** → Apply brake
- 💡 LED indicator for obstacle detection
- 🛑 Emergency brake activation via GPIO pin
- 📊 Serial monitor logs distance and status messages

---

## 🛠️ Hardware Components

- Arduino Uno or equivalent MCU
- HC-SR04 Ultrasonic Sensor
- 48V 750W BLDC Motor
- Motor Driver Circuit
- LED indicator
- Power Supply
- Wiring connections (see diagrams below)

---

## 🔌 Pin Configuration

| Component        | Arduino Pin |
|------------------|-------------|
| HC-SR04 Trigger  | 10          |
| HC-SR04 Echo     | 11          |
| LED Indicator    | 4           |
| Motor Control 1  | mtr1 (needs declaration fix) |
| Motor Control 2  | 6           |
| Brake Control    | 7           |
| Reverse Control  | 8           |

> **Note**: The variable `mtr1` is used in code but not defined. Declare it with an appropriate pin before use.

---

## 💻 Program Behavior

```c
distance = duration * 0.034 / 2
```

Depending on the distance measured:

- 🟡 **Between 40–100 cm**: Reduce motor speed, flash LED
- 🔴 **Between 10–40 cm**: Stop motor, LED ON for 2 seconds
- 🟣 **Less than 10 cm**: Apply brakes and halt
- 🟢 **Else**: Maintain normal driving condition

---

## 📋 Serial Monitor Output Example

```
Distance: 65
OBSTACLE !!!
Distance: 35
Ride Slow <<<
Distance: 9
Brake Applied
```

---

## 🖼️ Hardware Diagrams

### BLDC Motor Wiring

<img src="48v bldc connection.jpg" height="605">

### Controller Interface

<img src="bldc.png" height="450">

---

## 🛠️ Future Enhancements

- Add reverse motor logic
- Integrate buzzer alert system
- Debounce sensor readings for stability
- Display distance on OLED screen

---

## 🙌 Author Notes

This system is a smart prototype for automated vehicle control and obstacle avoidance using low-cost components. Ideal for robotics, e-bikes, and autonomous carts.

