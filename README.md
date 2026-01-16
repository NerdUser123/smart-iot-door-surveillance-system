# smart-iot-door-surveillance-system
An end-to-end IoT-based smart door surveillance and access control system built using NodeMCU (ESP8266), multiple environmental and motion sensors, a web dashboard, and Python-based face recognition for secure, automated door operation.

---

## 📌 Project Overview

The system acts as an intelligent surveillance unit installed at an entry point (door).  
It continuously monitors **human presence, air quality, motion/collision events**, and controls **door access** based on **face recognition authorization**.

A **Python application** performs face recognition on a connected laptop and communicates with the NodeMCU via **serial commands** (`OPEN` / `CLOSE`).

---

## 🧠 System Architecture

### Core Components
- **NodeMCU (ESP8266)**  
  Controls sensors, servo, buzzer, OLED display, and hosts the web dashboard.
- **Python (Laptop)**  
  Handles face recognition and sends authorization commands.
- **Serial Communication**  
  Used for real-time door control.

### Data Flow
1. Camera captures face → Python performs recognition  
2. Authorized face → `OPEN` command sent via serial  
3. NodeMCU opens door (servo)  
4. Door auto-closes after inactivity  
5. Sensors continuously monitor environment & security events  

---

## 🔧 Key Features

- 🔐 Servo-controlled door open/close  
- 👤 Ultrasonic-based human proximity detection  
- 🌫️ MQ-135 air quality monitoring with purifier alert  
- 🚨 MPU6050 collision detection with panic buzzer  
- 📟 OLED display for live system status  
- 🌐 Web dashboard hosted on ESP8266  
- 🧠 Python-based face recognition authorization  
- ⏱️ Auto door close after inactivity  
- 🔊 Audible alerts for security events  

---

## 🔌 Hardware Components

| Component | Description |
|---------|------------|
| NodeMCU (ESP8266) | Main controller |
| Servo Motor | Door control (external 5V) |
| Ultrasonic Sensor | Human proximity detection |
| MQ-135 | Air quality / gas sensor |
| MPU6050 | Motion & collision detection |
| OLED Display | System status |
| Buzzer | Panic / alert system |
| Push Button | Manual interaction |

> **Note:** All grounds are connected together. Servo is powered via an external 5V supply.

---

## 📍 Pin Configuration

| Component | Pin |
|--------|-----|
| Servo | D4 |
| Buzzer | D8 |
| Ultrasonic TRIG | D5 |
| Ultrasonic ECHO | D6 |
| MQ-135 | A0 |
| MPU6050 SDA / SCL | D2 / D1 |
| OLED SDA / SCL | D2 / D1 |

---
Images / vids
---

## 🧪 Functional Logic

### Door Control
- Authorized face → Door opens  
- No face detected for 7 seconds → Door auto-closes  

### Proximity Detection
- Detects nearby person (<30 cm)  
- Displays presence status on OLED  

### Air Quality Monitoring
- MQ-135 measures AQI  
- If AQI exceeds threshold → purifier alert generated  

### Collision Detection
- MPU6050 detects sudden motion/collision  
- Buzzer activates for 10 seconds (panic alert)  

### Display Output
OLED shows:
- Door status (OPEN / CLOSED)  
- Person proximity  
- Real-time AQI  
- Collision alerts  

---

## 🗂️ Project Structure

```

smart-iot-door-surveillance/
│
├── README.md
├── LICENSE
│
├── nodemcu/
│   └── door_surveillance.ino
│
├── python/
│   └── face_recognition.py
│
└── web/
    └── dashboard.ino


```

## 🚀 Getting Started

### Prerequisites
- Arduino IDE (ESP8266 board support)
- Python 3.x
- USB cable for NodeMCU

---

### NodeMCU Setup
1. Install ESP8266 board in Arduino IDE  
2. Open `nodemcu/door_surveillance.ino`  
3. Update WiFi credentials
4. Select correct board & COM port  
5. Upload the sketch  

---

### Python Setup
```
bash
pip install opencv-python pyserial
```

### 🔮 Future Enhancements

Cloud-based logging (Firebase / AWS)

Mobile app integration

Multiple user face profiles

MQTT-based communication

Mobile notifications for alerts

Battery-powered deployment

---

### 📜 License

MIT License

--- 

### 👤 Author

Built as part of an IoT workshop project.


