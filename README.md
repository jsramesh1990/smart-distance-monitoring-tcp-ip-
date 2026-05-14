
#  Smart Distance Monitoring System over TCP/IP

##  Overview
The **Smart Distance Monitoring System over TCP/IP** is an IoT-based embedded project that measures distance using an ultrasonic sensor and transmits the data over a network using TCP/IP. The system integrates embedded hardware, networking, and real-time data visualization.

This project demonstrates how sensor data can be collected, transmitted, and visualized in real time using a layered architecture.

---

##  Objectives
- Measure distance using HC-SR04 ultrasonic sensor  
- Transmit sensor data over WiFi using TCP/IP  
- Build a C++ server to receive real-time data  
- Visualize data dynamically using Python  
- Demonstrate end-to-end IoT pipeline  

---

##  System Architecture

```

+-------------------+
|  HC-SR04 Sensor   |
+-------------------+
↓
+-------------------+
|   ESP8266 Node    |
| (WiFi Client)     |
+-------------------+
↓ TCP/IP
+-------------------+
|    C++ Server     |
+-------------------+
↓
+-------------------+
| Python Visualizer |
+-------------------+
↓
Live Graph

```

---

##  System Flow

1. The **HC-SR04 sensor** measures distance using ultrasonic waves  
2. The **ESP8266** processes the signal and calculates distance  
3. Data is sent via **TCP/IP over WiFi**  
4. The **C++ server** receives incoming data  
5. The **Python script** reads and visualizes the data in real-time  

---

##  Technologies Used

| Layer            | Technology            |
|-----------------|---------------------|
| Embedded        | ESP8266 (Arduino)   |
| Sensor          | HC-SR04             |
| Communication   | TCP/IP (WiFi)       |
| Backend         | C++ (Sockets)       |
| Visualization   | Python (Matplotlib) |

---

##  Hardware Requirements

- ESP8266 NodeMCU  
- HC-SR04 Ultrasonic Sensor  
- Jumper wires  
- Breadboard  
- Resistors (for voltage divider)

---

##  Circuit Connections

| HC-SR04 | ESP8266 |
|--------|--------|
| VCC    | Vin (5V) |
| GND    | GND |
| Trig   | D1 |
| Echo   | D2  (Use Voltage Divider) |

 **Important:**  
The Echo pin outputs 5V. Use a **voltage divider** to step it down to 3.3V for ESP8266 safety.

---

##  Project Structure

```

smart-distance-monitoring-tcp-ip/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── esp8266_client/
│   └── esp8266_client.ino
│
├── server_cpp/
│   ├── server.cpp
│   └── Makefile
│
├── python_visualizer/
│   └── visualizer.py
│
├── docs/
│   ├── architecture.png
│   └── flow_diagram.md

````

---

##  Setup & Installation

### 🔹 Step 1: ESP8266 Setup
1. Install Arduino IDE  
2. Add ESP8266 board support  
3. Open `esp8266_client.ino`  
4. Update:
   ```cpp
   const char* ssid = "YOUR_WIFI";
   const char* password = "YOUR_PASSWORD";
   const char* serverIP = "YOUR_PC_IP";
````

5. Upload code to ESP8266

---

### 🔹 Step 2: Run C++ Server

```bash
cd server_cpp
make
./server
```

---

### 🔹 Step 3: Run Python Visualizer

```bash
pip install matplotlib
python visualizer.py
```

---

##  Data Format

Data is transmitted as plain text:

```
<distance_in_cm>
```

Example:

```
42
```

---

##  Features

 Real-time distance measurement
 Wireless data transmission (WiFi)
 TCP/IP communication
 Live graphical visualization
 Modular and scalable architecture

---

##  Example Output

```
Distance: 35 cm
Distance: 36 cm
Distance: 34 cm
```

Python Graph:

* Displays live distance variation
* Updates continuously

---

##  Troubleshooting

###  ESP8266 not connecting

* Check WiFi credentials
* Ensure same network

###  No data on server

* Verify IP address
* Check firewall settings

###  Distance always 0

* Check wiring
* Add delay between readings

---

##  Future Enhancements

*  Web-based dashboard (Flask / React)
*  Cloud integration (AWS / Firebase)
*  Mobile app monitoring
*  MQTT protocol support
*  Data logging (database)

---

##  Learning Outcomes

* Embedded system design
* Sensor interfacing
* TCP/IP socket programming
* Real-time data streaming
* Data visualization

---

##  Author

**Your Name**
Embedded Systems & IoT Developer

---

##  Contribution

Feel free to fork this repository and improve it. Contributions are welcome!

---

##  Acknowledgment

This project is built as a practical implementation of IoT concepts combining hardware and software integration.

```

