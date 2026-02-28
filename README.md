# 🎄 C++ Embedded Firmware: IoT ESP32 Smart Christmas Tree

A professional C++ firmware for ESP32 designed to control a tree-shaped LED installation via Bluetooth. This project demonstrates advanced embedded programming techniques, including State-Machine architecture and asynchronous (non-blocking) logic.

## 🚀 Technical Highlights (C++ Based)
- **C++ State-Machine:** The core logic is structured as a state machine to handle 6 distinct lighting modes efficiently.
- **Asynchronous Execution:** Developed entirely without `delay()` functions. It utilizes `millis()`-based timing to ensure the Bluetooth stack remains responsive and animations run at a consistent frame rate.
- **Object-Oriented Mindset:** While optimized for microcontrollers, the code follows C++ principles for modularity and readability.
- **Real-time Communication:** Implements the `BluetoothSerial` library for low-latency command processing.

## 🔌 Hardware Setup & Wiring (Assembly Guide)

To replicate this project safely, follow the wiring instructions below. Using resistors is critical to protect the ESP32 pins from damage.

### 1. Connecting LEDs and Resistors
* **Current Limiting:** Each LED **must** be connected in series with a **220Ω - 330Ω resistor**. This prevents the LED from burning out and protects the ESP32 GPIO pins from overcurrent.
* **Anode (Long leg):** Connect directly to the corresponding ESP32 GPIO pin listed in the table below.
* **Cathode (Short leg):** Connect to one end of the resistor. The other end of the resistor connects to the **GND** (Ground) rail.

### 2. Pinout Table
| Component | ESP32 Pin (GPIO) | Connection Detail |
| :--- | :--- | :--- |
| **LED 1** | GPIO 15 | Tree Base |
| **LED 2** | GPIO 17 | Tree Body |
| **LED 3** | GPIO 18 | Tree Body |
| **LED 4** | GPIO 19 | Tree Body |
| **LED 5** | GPIO 21 | Tree Body |
| **LED 6** | GPIO 22 | Tree Top / Star |
| **Buzzer** | GPIO 33 | PWM Audio Signal (Passive Buzzer) |

### 3. Important Notes
* **Common Ground:** Ensure all components (LEDs and Buzzer) are connected to the same ground (GND) rail on the ESP32.
* **Power Supply:** The system is powered via the ESP32's USB port.

## 🕹️ Control Commands
Connect to the device named **"ESP32_Snake"** using any Bluetooth Serial Terminal app. Send the following digits to switch modes:

1. **Mode 1:** Successive LED pairs.
2. **Mode 2:** Sequential fill and drain.
3. **Mode 3:** Successive LED groups.
4. **Mode 4:** Full tree blink.
5. **Mode 5:** Custom branch sequence.
6. **Mode 6:** **"The Snake"** - Plays a startup melody and runs a tracking animation.

## 💻 Installation & Usage
1. Download the `Smart_Xmas_Tree.ino` file.
2. Open the file in **Arduino IDE**.
3. Ensure you have the **ESP32 board support** installed.
4. Select the correct COM port and your board model (e.g., ESP32 Dev Module).
5. Upload the code.

## 📜 License
This project is licensed under the MIT License - feel free to use and modify it for your own holiday projects!
