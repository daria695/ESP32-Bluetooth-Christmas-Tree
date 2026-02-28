# ESP32-Bluetooth-Christmas-Tree
A high-performance C++ firmware for ESP32 designed to control a tree-shaped LED installation via Bluetooth. This project demonstrates advanced embedded programming techniques, including state-machine architecture and asynchronous (non-blocking) logic.

## 🚀 Technical Highlights (C++ Based)
- **C++ State-Machine:** The core logic is structured as a state machine to handle 6 distinct lighting modes efficiently.
- **Asynchronous Execution:** Developed entirely without `delay()` functions. It utilizes `millis()`-based timing to ensure the Bluetooth stack remains responsive and animations run at a consistent frame rate.
- **Object-Oriented Mindset:** While optimized for microcontrollers, the code follows C++ principles for modularity and readability.
- **Real-time Communication:** Implements the `BluetoothSerial` library for low-latency command processing.

## 🔌 Circuit Setup & Pin Mapping

To replicate the project, connect the components as follows. Each LED requires a **220Ω - 330Ω resistor** for current limiting.

| Component | ESP32 Pin (GPIO) | Connection Description |
| :--- | :--- | :--- |
| **LED 1** | GPIO 15 | Branch / Base |
| **LED 2** | GPIO 17 | Branch |
| **LED 3** | GPIO 18 | Branch |
| **LED 4** | GPIO 19 | Branch |
| **LED 5** | GPIO 21 | Branch |
| **LED 6** | GPIO 22 | Top / Star |
| **Buzzer** | GPIO 33 | PWM Signal for Audio |

*Note: All components share a common Ground (GND).*

## 🕹️ Control Commands
Connect to the device named **"ESP32_Snake"** using any Bluetooth Serial Terminal app. Send the following digits to switch modes:

1. **Mode 1:** Successive LED pairs.
2. **Mode 2:** Sequential fill and drain.
3. **Mode 3:** Successive LED groups.
4. **Mode 4:** Full tree blink.
5. **Mode 5:** Custom branch sequence.
6. **Mode 6:** **"The Snake"** - Plays a startup melody and runs a tracking animation.

## 📂 Installation
1. Flash the `Smart_Xmas_Tree.ino` using the Arduino IDE.
2. Ensure the ESP32 toolchain is correctly configured for your board.
