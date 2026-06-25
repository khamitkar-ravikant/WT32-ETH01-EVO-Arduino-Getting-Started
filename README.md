# WT32-ETH01-EVO-Arduino-Getting-Started
Getting Started examples for WT32-ETH01 EVO (ESP32-C3 + DM9051 SPI Ethernet) using Arduino IDE 2.3.x and ESP32 Core 3.3.x. 
# WT32-ETH01-EVO Arduino Ethernet Examples

A complete getting started repository for the **WT32-ETH01-EVO** Ethernet development board based on **ESP32-C3** and **DM9051 SPI Ethernet Controller** using the **Arduino IDE**.

This repository demonstrates how to initialize Ethernet, obtain an IP address using DHCP or Static IP, synchronize time using NTP, communicate with web servers over HTTP/HTTPS, and forms the foundation for industrial IoT applications.

---

## Features

* DM9051 SPI Ethernet Initialization
* Ethernet Link Detection
* DHCP Configuration
* Static IP Configuration
* Internet Connectivity Test
* NTP Time Synchronization
* HTTP GET Example
* HTTPS GET Example
* HTTPS POST Example *(Coming Soon)*
* RS485 Modbus RTU Example *(Coming Soon)*
* Industrial IoT Data Logger *(Coming Soon)*

---

## Hardware

Board:

**WT32-ETH01-EVO**

MCU:

**ESP32-C3**

Ethernet Controller:

**DM9051 SPI Ethernet**

---

## Tested Environment

| Component           | Version             |
| ------------------- | ------------------- |
| Arduino IDE         | 2.3.10              |
| ESP32 Board Package | 3.3.0               |
| Selected Board      | ESP32-C3 Dev Module |

---

# Hardware Connections

## Internal Ethernet Connections

The WT32-ETH01-EVO internally connects the ESP32-C3 to the DM9051 Ethernet controller using SPI.

| Function | GPIO   |
| -------- | ------ |
| ETH_CS   | GPIO9  |
| ETH_INT  | GPIO8  |
| ETH_RST  | GPIO6  |
| ETH_SCLK | GPIO7  |
| ETH_MISO | GPIO3  |
| ETH_MOSI | GPIO10 |

---

## External GPIO

| GPIO   | Function           |
| ------ | ------------------ |
| GPIO2  | UART TX            |
| GPIO5  | UART RX            |
| GPIO4  | RS485 DE/RE Enable |
| GPIO18 | User LED           |

---

## Ethernet Initialization

The following configuration has been verified on actual hardware.

```cpp
ETH.begin(
    ETH_PHY_DM9051,
    1,
    9,
    8,
    6,
    SPI2_HOST,
    7,
    3,
    10,
    8
);
```

---

## Static IP Configuration

Example:

```cpp
IPAddress myIP(192,168,0,200);
IPAddress myGW(192,168,0,1);
IPAddress mySN(255,255,255,0);
IPAddress myDNS(8,8,8,8);

ETH.config(myIP,myGW,mySN,myDNS);
```

---

## Internet Connectivity Test

```cpp
HTTPClient http;

http.begin("http://clients3.google.com/generate_204");

int code = http.GET();
```

Expected response:

```
HTTP Response = 204
```

---

## NTP Synchronization

```cpp
configTime(
    19800,
    0,
    "pool.ntp.org",
    "time.nist.gov"
);
```

---

## Verified Serial Output

```
WT32-ETH01-EVO

Starting Ethernet...

ETH.begin() OK

Ethernet Link UP

Waiting for DHCP...

MAC Address : B2:81:84:AD:48:70

IP Address  : 192.168.0.101

Gateway     : 192.168.0.1

DNS         : 8.8.8.8

Ethernet Ready

HTTP Response = 204

Synchronizing Time.........

Time synchronized

25-06-2026 14:03:04
```

---

# Repository Structure

```
WT32-ETH01-EVO-Arduino
│
├── README.md
│
├── docs
│   ├── Pinout.png
│   ├── BoardFront.jpg
│   └── BoardBack.jpg
│
├── examples
│   ├── 01_Ethernet_Bringup
│   ├── 02_DHCP_Test
│   ├── 03_Internet_Test
│   ├── 04_NTP_Test
│   ├── 05_HTTP_GET
│   ├── 06_HTTPS_GET
│   ├── 07_HTTPS_POST
│   ├── 08_RS485_Modbus
│   └── 09_Industrial_DataLogger
│
└── images
    ├── EthernetConnected.png
    └── SerialOutput.png
```

---

# Roadmap

### Version 1.0

* Ethernet Bring-up
* DHCP
* Static IP
* Internet Test
* NTP

### Version 1.1

* HTTP GET

### Version 1.2

* HTTPS GET

### Version 1.3

* HTTPS POST

### Version 1.4

* RS485 Modbus RTU

### Version 2.0

* Industrial IoT Power Monitoring System
* SQL Database Logging
* Cloud Dashboard
* Mobile Monitoring

---

# Troubleshooting

### ETH.begin() FAILED

* Verify ESP32 Board Package version is **3.3.0 or later**.
* Ensure **ESP32-C3 Dev Module** is selected.
* Check the Ethernet cable and switch connection.

---

### Ethernet Link Timeout

* Verify the RJ45 cable.
* Ensure the network switch/router is active.
* Confirm the Ethernet link LEDs are illuminated.

---

### No IP Address

* Verify DHCP is enabled on the router.
* Alternatively configure a static IP using `ETH.config()`.

---

### HTTP Response not 204

* Verify Internet connectivity.
* Check DNS configuration.
* Ensure the gateway is reachable.

---

# Future Work

This repository will be expanded to include:

* HTTPS communication with PHP REST APIs
* SQL database integration
* Modbus RTU over RS485
* MQTT communication
* Firebase Cloud Messaging (FCM)
* OTA Firmware Updates
* Industrial IoT Dashboard

---

# Contributing

Contributions are welcome.

If you have successfully tested this board on different ESP32 board package versions, additional Ethernet features, or new peripherals, please submit a Pull Request.

---

# License

This project is released under the MIT License.

---

# Acknowledgements

Special thanks to the ESP32 Arduino community and Espressif Systems for the ESP32 Arduino framework.

This repository is based on practical hardware validation performed on the WT32-ETH01-EVO development board and is intended to provide a simple starting point for developers working with DM9051-based Ethernet solutions.
