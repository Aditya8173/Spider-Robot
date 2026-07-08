# 🕷️ Bluetooth Controlled Spider Robot using Arduino Uno & HC-05

A quadruped spider robot controlled wirelessly via Bluetooth using an **Arduino Uno** and **HC-05 Bluetooth module**. This is the **first version** of the project before it was upgraded to the ESP32-CAM Wi-Fi based system.

---

# 📖 Overview

This project demonstrates a four-legged spider robot capable of walking and changing direction through Bluetooth commands sent from an Android smartphone. The Arduino Uno controls all servo motors and processes movement commands received from the HC-05 Bluetooth module.

The project focuses on learning robot locomotion, servo motor control, and wireless communication using Bluetooth.

---

# ✨ Features

- 🕷️ Quadruped spider robot
- 📱 Bluetooth control using HC-05
- 🎮 Android app-based control
- 🚶 Forward, Backward, Left and Right movement
- ⚙️ Servo motor-based leg movement
- 🔋 Portable battery-powered design
- 🛠️ Simple and beginner-friendly architecture

---

# 🏗️ System Architecture

<img width="1746" height="942" alt="Work Flow Diagram" src="https://github.com/user-attachments/assets/da881b60-bc09-43e5-b2fd-e281fc161065" />

```text
        Android Phone
              │
         Bluetooth
              │
        +-------------+
        |    HC-05    |
        +------+------+ 
               │
         Serial (UART)
               │
        +------+------+ 
        | Arduino Uno |
        +------+------+ 
               │
         PWM Signals
               │
         Servo Motors
               │
        Spider Robot
```

---

# 🧰 Hardware Requirements

- Arduino Uno
- HC-05 Bluetooth Module
- SG90/MG90S Servo Motors (8 or 12)
- Spider Robot Chassis
- Servo Mounts
- Jumper Wires
- Breadboard or PCB
- 5V Battery Pack
- Voltage Regulator
- Power Switch
- USB Cable

---

# 💻 Software Requirements

- Arduino IDE
- Servo Library
- SoftwareSerial Library
- Bluetooth Terminal App or Custom Android App

---

# ⚙️ Working Principle

1. Pair the smartphone with the HC-05 Bluetooth module.
2. Open the Bluetooth control application.
3. Press a movement button.
4. The phone sends a character command through Bluetooth.
5. HC-05 receives the command.
6. Arduino Uno reads the command through serial communication.
7. Arduino executes the corresponding walking routine.
8. Servo motors move the robot.

---

# 📡 Communication

### Bluetooth Communication

- Module: HC-05
- Communication Type: UART Serial
- Wireless Range: Approximately 10 meters

Example Commands

```text
F → Forward
B → Backward
L → Left
R → Right
S → Stop
```

---

# 🚶 Walking Mechanism

The robot walks using predefined gait sequences.

Movement Types

- Forward
- Backward
- Left Turn
- Right Turn
- Stop

---

# 📊 Arduino Uno Specifications

| Specification | Value |
|--------------|-------|
| Microcontroller | ATmega328P |
| Clock Speed | 16 MHz |
| Flash Memory | 32 KB |
| SRAM | 2 KB |
| EEPROM | 1 KB |
| Digital Pins | 14 |
| PWM Pins | 6 |
| Analog Pins | 6 |
| Operating Voltage | 5V |

---

# 📊 HC-05 Specifications

| Specification | Value |
|--------------|-------|
| Bluetooth Version | 2.0 + EDR |
| Communication | UART |
| Operating Voltage | 3.6V–6V |
| Logic Level | 3.3V |
| Default Baud Rate | 9600 bps |
| Range | ~10 meters |
| Frequency | 2.4 GHz |

---

# 📂 Project Structure

```text
Spider-Robot-Bluetooth/
│
├── Arduino_Code/
│   ├── SpiderRobot.ino
│   ├── ServoControl.h
│   └── Gait.h
│
├── Circuit_Diagram/
│
├── Images/
│
├── Documentation/
│
├── README.md
│
└── LICENSE
```

---

# 🎯 Applications

- Educational Robotics
- Robotics Competitions
- Learning Embedded Systems
- Servo Motor Control
- Bluetooth Communication Projects
- Robotics Research

---

# ⚠️ Limitations

- Limited Bluetooth range (~10 m)
- No live video monitoring
- Requires a Bluetooth-enabled device
- Single controller handles all tasks
- Basic walking algorithm with less smooth movement
- No browser-based interface
- Not suitable for remote internet control

---

# 🔄 Future Upgrades

The next version of this project introduces:

- ESP32-CAM Wi-Fi control
- HTML Web Dashboard
- WebSocket communication
- Live camera streaming
- Master-Slave architecture
- Smooth walking gait
- Better stability
- Modular software architecture

---

# 🆚 Comparison

| Feature | Bluetooth Version | Upgraded Version |
|---------|-------------------|------------------|
| Controller | Arduino Uno | Arduino Uno + ESP32-CAM |
| Communication | HC-05 Bluetooth | Wi-Fi |
| Interface | Android Bluetooth App | HTML Dashboard |
| Camera | ❌ No | ✅ Live Streaming |
| Architecture | Single Controller | Master-Slave |
| Control Range | ~10 m | Same Wi-Fi Network |
| Motion | Basic Walking | Smooth Walking |
| Real-Time Communication | Bluetooth UART | WebSocket |
| Expandability | Limited | High |

---

# 👨‍💻 Authors

Developed as the initial version of the Spider Robot project using **Arduino Uno** and **HC-05 Bluetooth**. This project served as the foundation for the upgraded ESP32-CAM-based smart spider robot.

---

# 📜 Credits

Credit goes out to [regishsu](https://github.com/regishsu)  for creating the original Instructable, as well as [Donnie Plumly](https://github.com/dplumly) and [robertcedwards](https://github.com/robertcedwards)for guiding me through the process of making this robot a reality.

---

## ⭐ If you like this project, don't forget to **Star ⭐ the repository** and check out the upgraded Wi-Fi version!
