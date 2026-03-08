🎄 IoT ESP32 Smart Christmas Tree: C++ Embedded Firmware
This repository contains the firmware and documentation for an interactive, smartphone-controlled Christmas lighting system. The project leverages the ESP32's Dual-Core processor to manage both real-time LED animations and stable Bluetooth Low Energy (BLE) communication simultaneously.

📖 Project Overview
The goal of this project was to transition from traditional "static" lighting to an intelligent IoT (Internet of Things) environment. By integrating a mobile interface with embedded hardware, we created a system that allows users to switch between complex visual patterns without physical interaction.

⚙️ Technical Features
Non-blocking Logic: The firmware is written using a state-machine approach rather than delay() functions, ensuring the Bluetooth stack remains responsive even during complex LED transitions.

6 Dynamic Animation Modes: Includes 'Rainbow Flow', 'Twinkle Star', 'Pulse', and 'Steady Glow', all calculated in real-time using mathematical functions (Sine/Cosine waves) for smooth color transitions.

BLE Protocol Stack: Implements custom GATT services and characteristics, allowing for low-latency command reception from any BLE-enabled smartphone.

Audio Feedback: Integrated system alerts that provide acoustic confirmation when a new lighting mode is successfully activated.

🛠 Hardware Architecture
Microcontroller: ESP32 (32-bit Xtensa® Dual-Core).

LED Technology: WS2812B Addressable LEDs (Neopixels), allowing individual control over the color and brightness of every single diode.

Power Management: Regulated 5V DC power supply with a common ground architecture to prevent signal noise in the data line.

Communication: 2.4 GHz Bluetooth 4.2 (BLE).

💻 Software Stack
Framework: Arduino IDE with C++ core.

Libraries: BLEDevice.h (for the wireless stack) and FastLED.h (for high-performance LED manipulation).

Optimization: Use of PWM (Pulse Width Modulation) for brightness control and optimized memory allocation for the LED buffer.

🤝 Team Contribution & Collaboration
This project was a collaborative engineering effort. To ensure success, we divided the tasks based on modularity:

My Role: I focused on the hardware-software bridge. I designed the circuit layout to ensure proper signal integrity and implemented the core BLE pairing logic. I was also responsible for the Integration Testing, ensuring that the software commands correctly translated into the physical lighting effects without lag.

Peer Collaboration: Worked closely with my teammate to synchronize the non-blocking C++ logic with the visual animation states.
