# MoodBot
# Social Media

https://www.tiktok.com/@moodbot_uog?_t=ZN-8vjAwkBpf6c&_r=1
# Product Introduction: Mood Bot

Mood Bot is a smart desktop robot designed for personal and home use. It consists of two motors, one servo, a screen, and an HD camera. It is also equipped with environmental sensors to monitor air quality and temperature. The device features an intelligent facial expression recognition system and a web-based interface for real-time interaction and control.

## Key Features

- **Facial Expression Recognition:**  
  Mood Bot can detect and analyze human facial expressions, including happy, sad, and tired. When a face is detected but not aligned with the camera, the robot automatically adjusts its angle to ensure accurate face tracking and recognition.

- **Environmental Monitoring:**  
  Built-in sensors continuously monitor the air quality and temperature of the surrounding environment, providing real-time updates.

- **Remote Interaction Interface:**  
  Users can remotely control the robot’s movement (forward, backward, left, right), turn the camera on or off, and view real-time expression recognition results through a web interface.

## Market Demand and Product Positioning

With the increasing popularity of smart home devices and emotionally interactive technologies, Mood Bot meets a growing need for emotional awareness, home environment monitoring, and remote family care:

1. **Emotional Connection:**  
   Mood Bot offers companionship and emotional support, especially for children and the elderly living alone. Family members can remotely check on their loved ones' emotional states, strengthening family bonds.

2. **Remote Monitoring:**  
   Through the web interface, users can see what the robot sees in real time, making it possible to remotely supervise and care for home members.

3. **Environmental Alerts:**  
   The air quality and temperature sensors help family members stay informed about their home environment, which is especially useful when taking care of seniors or young children.

4. **Strong Expandability:**  
   Mood Bot has great potential for future upgrades, such as integrating voice assistants, notification systems, or more AI features to enhance the user experience.

## Why Are We Building Mood Bot?

- **Rising Demand for Emotional Well-being:**  
  In today's fast-paced society, people—especially the elderly and children—often face emotional isolation. Mood Bot provides a way to stay emotionally connected and cared for.

- **The Growth of AI Companion Devices:**  
  With the advancement of AI and IoT, there is an increasing demand for emotionally intelligent devices in the market.

- **Home Safety Awareness:**  
  Since the pandemic, people have become more aware of the importance of home safety and remote monitoring. Mood Bot combines emotion recognition with environmental sensing to provide a comprehensive solution.

- **Practical AI Application:**  
  This product reflects our desire to explore real-world applications of AI in emotional recognition, human-robot interaction, and home caregiving—making technology more empathetic and human-centered.

## Team Members

-  Yuxiang Cui - 2864612C
[Jyc66ui](https://github.com/Jyc66ui)

-  Linzheng Li - 2930588L
  [[MoonupLee](https://github.com/MoonupLee)]
  
-  Sicheng Li - 3049797L
  [yanmomomimomo](https://github.com/yanmomomimomo)
  
-  Quan Yuan - 3046818Y
  [yquan0000](https://github.com/yquan0000)
  
-  Zihan Xu - 2764591X
[Mccona](https://github.com/Mccona)

## Contribution
-  Quan Yuan - 3046818Y: Designed and developed the MoodBot frontend using React with Hooks, modularized into emotion recognition with LED feedback, environment monitoring, motion control, and remote monitoring. Integrated real-time communication via Socket.IO with backend WebSocket and conducted debugging for I2C and SPI screens.

   Implemented a responsive UI with dynamic states, managed component lifecycle and state effectively. Created a systemd service for deployment and provided detailed technical documentation.

   Optimized resource cleanup and modular CSS to ensure stable and independent module operation.

-  Linzheng Li - 2930588L: Developed a comprehensive three-layer event-driven architecture consisting of the Hardware Layer, Event-driven Interface Layer, and Event Bus Layer. This evolved the control framework from a simple point-to-point model into a fully asynchronous event-driven system.

   Enhanced the Event Bus to support numerical data transmission, enabling complex asynchronous interactions including one-to-many, many-to-one, and many-to-many event relationships.

   Integrated and implemented drivers for eight hardware modules, covering sensors such as the QM2 smoke sensor, DHT11 temperature and humidity sensor, 5516 photosensitive resistor sensor, and RD-03 human radar module, as well as actuators and displays including a USB speaker (using SDL2), servo motor, and L298N DC motor driver board.

-  Sicheng Li - 3049797L: Developed driver programs for the servo motor and two DC motors, configuring Raspberry Pi GPIO to support multithreaded PWM signal output and control. Enabled the servo and motors to track faces based on recognized facial data and execute predefined movement actions accordingly.

   Managed TikTok operations by creating engaging content, optimizing posting schedules based on data analysis, and collaborating with influencers to boost brand awareness and user engagement.
  
   Designed the hardware circuitry for the robot to support these functionalities.
  
-  Yuxiang Cui - 2864612C: Trained ONNX emotion recognition model and developed corresponding code. Created animations and managed social media operations. Refactored code to improve readability and maintainability. Conducted market research and calculated the center coordinates of detected faces for precise tracking.

-  Zihan Xu - 2764591X: Developed emotion recognition code and tested its accuracy. Designed animation storyboards and scripts. Assisted in code packaging and compared advantages of different vision libraries and classification models. Classified expressions of detected faces and wrote detailed README documentation.

## Hardware List

| Hardware Component                              | Description                                                              | Quantity |
|------------------------------------------------|--------------------------------------------------------------------------|----------|
| Raspberry Pi 5                                  | Main control computing platform                                         | 1        |
| L298N Motor Driver Board                        | Motor driver control                                                    | 1        |
| Motors                                          | Execute motion control                                                  | 2        |
| 0.52-inch 4-pin Serial Protocol OLED Screen    | Serial communication, display environment and status info               | 1        |
| 1.47-inch 8-pin SPI Protocol LCD Screen        | SPI communication, high resolution display interface                    | 1        |
| 5516 Light Sensor                               | Detect ambient light intensity                                          | 1        |
| DHT11 Environmental Temperature and Humidity Sensor | Collects temperature and humidity data                                   | 1        |
| RD-03 Human Radar Sensor                        | Human presence detection via GPIO signal                                | 1        |
| MG996R 360-degree Servo Motor                   | Servo rotation control                                                  | 1        |
| USB Speaker                                    | Audio playback output                                                   | 1        |
| CSI Interface Camera Module                     | High-definition video capture                                           | 1        |
| QM2 Smoke Sensor                               | Smoke concentration detection                                           | 1        |
## Software Requirements

- Operating System: Raspberry Pi official Debian 20.03 64-bit version (Raspbian OS based on Debian Bookworm).
- Programming Language: C++ (for core system development including motor control, sensor management, and facial expression recognition).
- GPIO Library: `gpiod` library for GPIO pin management and event-driven hardware interaction.
- Multimedia Libraries:
  - OpenCV for video capture and face detection.
  - mediapipe framework (TensorFlow Lite int8 quantized Blazeface model) for fast and lightweight face detection.
  - ONNX Runtime for efficient emotion recognition model inference.
  - SDL2 and SDL_mixer for audio playback control.
- UI Framework: Qt5 (Qt Creator as IDE) for building graphical user interface and multimedia interaction.
- Web Frontend: React with Socket.IO for real-time web-based remote control and monitoring interface.

## How to use this project
- Recommended OS: Latest Raspberry Pi OS
- Install the required dependencies:

```bash
sudo apt update
sudo apt install libgpiod-dev libsdl2-dev cmake g++
```

### Enable Raspberry Pi Hardware Interfaces

Enable SPI, I2C, and Serial interfaces via:

```bash
sudo raspi-config
# Activate SPI, I2C, and Serial interfaces
```

### Clone Project and Build

```bash
git clone https://github.com/yanmomomimomo/Mood_Bot_UoG.git
cd Mood_Bot_UoG
mkdir build && cd build
cmake ..
make -j
./OpenCV-4-11-0.sh
```

## System Architecture 



### Evolution of Event-Driven Architecture (Core Section)

#### Five-Stage Evolution Process

1. **Stage One: Basic Hardware Layer**
   - Class encapsulation for direct point-to-point hardware control.

2. **Stage Two: Multi-threaded Approach**
   - Multi-threaded drivers enabling concurrent hardware operations via global state sharing.

3. **Stage Three: Event-Driven Interface Foundations**
   - Introduction of interface base classes (`Getter`, `Setter`, `EventNotifier`), establishing a preliminary event-driven model.

4. **Stage Four: Three-Layer Event Architecture**
   - Implemented a clear three-layer architecture:
     - Hardware Layer → Event Interface Layer → Event Bus Layer.
   - Developed the `EventBus` class for event subscription/publishing, standardized blocking and event-triggering mechanisms.

5. **Stage Five: Enhanced Event Bus for Data Transmission**
   - Extended the EventBus to handle complex numeric states and events beyond binary (0/1) values.
   - Enabled asynchronous interaction models (one-to-many, many-to-one, many-to-many).
   - Achieved a robust and flexible three-layer event-driven architecture.

#### Implementation Method (Virtual Function-based Polymorphism)

The architecture utilizes polymorphism via C++ virtual functions:

- Defined abstract methods (`blockAndWaitEvent()`, `run()`, and `registerCallback()`) within base classes.
- Specific sensor and actuator drivers inherit and override these methods to implement custom hardware logic.

#### Quick Driver Implementation (Pseudo-code Example)

To integrate a new hardware module quickly:

```cpp
// Example getter class (pseudo-code)
class MyDeviceGetter : public GetterEventDriven {
public:
    MyDeviceGetter(MyDevice& device, EventBus& bus);
    int blockAndWaitEvent() override;
    void run() override;
    void registerCallback() override;
};

// Registration (pseudo-code)
bus.registerGetter("my_device_event", &myDeviceGetter);

// Main function setup (pseudo-code)
int main() {
    MyDevice device;
    MyDeviceGetter deviceGetter(device, bus);

    deviceGetter.start();
    // main loop
    while(true) pause();
    
    deviceGetter.stop();
    return 0;
}
```

---
### LCD Display Functions  

| Function          | Description                                           |  
|-------------------|-----------------------------------------------------|  
| Basic Display     | Display static images, text, and geometric shapes (points/lines/rectangles) |  
| Full Screen Control | Clear screen (solid color fill), full-screen image display |  
| Partial Refresh   | Update specified coordinate area content (e.g., partial animation) |  
| Orientation Adaptation | Support switching between horizontal (HORIZONTAL) and vertical (VERTICAL) modes |  
| Low Power Management | Backlight control (BL pin), sleep/wake commands      |  

#### Simplified Code Architecture  

##### 1.Header File (LCD_class.hpp)  

```cpp  
class LCD_class {  
public:  
    LCD_class(uint16_t width, uint16_t height, uint8_t scan_dir); // Constructor: resolution + orientation  
    void DrawPixel(uint16_t x, uint16_t y, uint16_t color);      // Draw point (input: coordinates + RGB565 color)  
    void FillScreen(uint16_t color);                             // Fill full screen (input: RGB565 color)  
    void DisplayImage(const uint16_t* img);                      // Display image (input: RGB565 array)  
private:  
    void SendCommand(uint8_t cmd);                               // Send command (input: 1-byte command)  
    void SendData(uint8_t data);                                 // Send data (input: 1-byte data)  
    // ... private members for GPIO pins and SPI handles  
};
```
##### 2.Driver Implementation (LCD.cpp)

| Function           | Purpose                                   | Input/Output                  |
|--------------------|-----------------------------------------|--------------------------------|
| LCD_SendCommand    | Send control command (e.g., 0x2A for column address) | Input: 1-byte command        |
| LCD_SendData_16Bit | Send RGB565 pixel data                   | Input: 16-bit color value     |
| LCD_SetWindows     | Set display coordinate region           | Input: x_start, y_start, x_end, y_end |
| LCD_1IN47_InitReg | Send screen initialization command sequence | No input                     |
##### 3.Hardware Configuration (LCD_Config.cpp)
```cpp  
// Pin definitions (must match actual hardware)
#define LCD_CS_PIN  10   // GPIO10 connected to screen CS
#define LCD_DC_PIN  4    // GPIO4 connected to screen DC
#define LCD_RST_PIN 17   // GPIO17 connected to screen RST
#define LCD_BL_PIN  18   // GPIO18 connected to backlight control

// SPI Configuration
#define SPI_CLOCK_SPEED 40000000 // 40MHz

```
##### 4.Hardware Configuration (LCD_Config.cpp)

| LCD Pin | Master GPIO | Function            | Signal Description     |  
|---------|-------------|---------------------|-----------------------|  
| CS      | GPIO10      | Chip Select         | Active low            |  
| DC      | GPIO4       | Data/Command Select | 0 = Command, 1 = Data |  
| RST     | GPIO17      | Hardware Reset      | Active low trigger    |  
| BL      | GPIO18      | Backlight Control   | High level turns on   |  
| SCL     | SPI0_SCK    | SPI Clock           | Output from master    |  
| SDA     | SPI0_MOSI   | SPI Data Output     | Output from master    |  
| VCC     | 3.3V        | Power Positive      | -                     |  
| GND     | GND         | Power Ground        | -                     |  

---  
##### 5.Hardware Configuration (LCD_Config.cpp)
Summary of Code Files and Core Content  

| File           | Core Content                                                        |  
|----------------|-------------------------------------------------------------------|  
| LCD_class.hpp  | Defines LCD operation interface (drawing, control, resolution, orientation etc.) |  
| LCD.cpp        | Implements SPI communication, pixel drawing, window setting       |  
| LCD_Config.cpp | Hardware parameters configuration: pins, SPI speed, initialization commands |  
| LCD_main.cpp   | Test cases: image display, color fills, performance tests         | 

##### 6.Example Key Function Call Flow
Draw a red pixel at (50, 80):  

- `LCD_SetWindows(50, 80, 51, 81)` → Set single-pixel window  
- `LCD_SendCommand(0x2C)` → Enter data write mode  
- `LCD_SendData_16Bit(0xF800)` → Send red color (RGB565: 0xF800)
##### 7.Porting Notes  

- **Pin Check:** Confirm GPIO numbers in `LCD_Config.cpp` match hardware connections  
- **SPI Configuration:** Ensure master SPI clock speed is within screen specifications (ST7789 usually supports 80MHz)  
- **Orientation Calibration:** If displayed content is rotated incorrectly, adjust `Scan_dir` parameter or initialization commands

### OLED Display Functions  
#### Function Summary  

| Function            | Implementation Method                                     | Display Example                     |  
|---------------------|-----------------------------------------------------------|-----------------------------------|  
| Basic Display Init   | Send initialization command sequence (0xAE Off → config → 0xAF On) | Blank screen (after initialization) |  
| Border & Fixed Text  | Pre-stored bitmap data (`oled_frame`) + character rendering | Border + "Chr" text + "C" icon    |  
| Date Display        | Retrieve system time in real-time + render with Font12    | "25MAY2023 Wed" (dynamic update)  |  
| Timer Display       | Number formatting (5 digits separated by spaces) + Font16 rendering | "1 2 3 4 5"                      |  
| Warning Interface   | Display pre-stored full-screen bitmap (`warningPattern`)   | Fullscreen warning icon            |  
| Clear Screen / Shutdown | Clear display buffer or send 0xAE command               | Black screen                      |  
#### Simplified Code Architecture  
##### 1. OLED_class.hpp  

```cpp  
class OLED_class {  
public:  
    // User Interface  
    bool Border_Show();       // Display border and fixed text  
    bool TM_upgrade(int TM);  // Update timer display (input: integer)  
    bool Date_upgrade();      // Update date display  
    void OLED_Shootdown();    // Turn off screen  
private:  
    int i2c_fd_;             // I2C file descriptor  
};  
```
##### 2. OLED.cpp  
| Function       | Purpose                                    | Input/Output                     | Key Dependency           |
|----------------|--------------------------------------------|---------------------------------|--------------------------|
| OLED_init()    | Initialize screen (send command sequence) | None                            | I2C_writeCommand()       |
| OLED_setPixel()| Set single pixel state in display buffer   | (x, y, on)                      | displayBuffer array      |
| DrawChar()     | Render character to display buffer          | (x, y, char, font pointer)      | Font library in fonts.h  |
| TM_upgrade()   | Format and display 5-digit timer value      | Input: integer (e.g., 12345)    | Font16                   |
| Date_upgrade() | Display current date (auto fetch system time) | None                         | GetDate() + Font12       |
##### 3. OLED_Config.cpp
```cpp  
// Hardware configuration (user editable)
#define OLED_WIDTH   128     // Screen width (pixels)
#define OLED_HEIGHT  64      // Screen height (pixels)
#define I2C1_DEV    "/dev/i2c-1"  // I2C device path
#define I2C1_ADDRESS 0x3C    // OLED I2C address

```
##### 4. Hardware Pin Mapping Table
| OLED Pin | Master Connection           | Configuration Location                  | Notes                              |
|----------|----------------------------|---------------------------------------|-----------------------------------|
| SDA      | I2C Data Line (e.g., GPIO2)| System level I2C config (not direct code) | Enable via device tree or /boot/config.txt |
| SCL      | I2C Clock Line (e.g., GPIO3)| Same as above                         | Requires 4.7KΩ pull-up resistor    |
| VCC      | 3.3V                       | -                                     | Insufficient power causes display issues |
| GND      | Ground                     | -                                     |                                   |

**Key Configuration Points:**

- I2C device path is `devName_` in OLED.cpp (default: "/dev/i2c-1")  
- I2C address set by `ioctl(i2c_fd, I2C_SLAVE, I2C1_ADDRESS)` (usually 0x3C or 0x3D)  
##### 5. Core Code Logic Flow
###### 1. Initialization Stage

- OLED_class constructor is called  
  - 1.1 Open I2C device (`/dev/i2c-1`)  
    - Failure: output error and return  
    - Success: set I2C slave address (0x3C)  
  - 1.2 Call `OLED_init()`  
    - Send initialization command sequence (0xAE → 0xD5 → ... → 0xAF)  
    - Clear display buffer (`displayBuffer` zeroed)  

###### 2. Default Interface Display

- Constructor continues  
  - 2.1 Call `Border_Show()`  
    - Clear display buffer  
    - Draw pre-stored border bitmap (`oled_frame`)  
    - Render fixed characters ("Chr" and "C")  
  - 2.2 Call `Date_upgrade()`  
    - Fetch system time (`GetDate()`)  
    - Render date string (e.g., "25MAY2023 Wed") with Font12  
  - 2.3 Call `TM_upgrade(12345)`  
    - Format number as "1 2 3 4 5"  
    - Render with Font16 at specified position  

###### 3. Runtime Interactions

- User-invoked functions  
  - 3.1 Update timer (`TM_upgrade`)  
    - Clear old number region (`clearRegion`)  
    - Render new number and refresh display  
  - 3.2 Show warning (`Warning_Show`)  
    - Clear display buffer  
    - Display stored warning bitmap fullscreen  
  - 3.3 Shutdown (`OLED_Shootdown`)  
    - Send command 0xAE to turn off display  

###### 4. Display Refresh Process

- Any display update calls `OLED_updateDisplay()`  
  - 4.1 Set column address (0x21 + start/end columns)  
  - 4.2 Set page address (0x22 + start/end pages)  
  - 4.3 Write entire display buffer (`I2C_writeData`)  

###### Key Points

- All graphic operations modify `displayBuffer` in memory first  
- Final flush to hardware via single call to `OLED_updateDisplay()`  
- Hardware relies on success of I2C connection and initialization commands  
- Display content limited by monochrome OLED features (1 = on, 0 = off)  
- Time sensitive: `GetDate()` depends on system RTC; `TM_upgrade()` requires fast int-to-string conversion
##### 6. Porting and Debugging Suggestions  
###### First Use Checks  

- Confirm I2C enabled (`i2cdetect -y 1` to scan device address)  
- Measure VCC voltage (3.3V ±5%)  

###### Common Issues  

- No display: check return of `I2C_writeCommand()`, confirm I2C communication success  
- Garbled screen: confirm full execution of `OLED_init()`, especially command 0xA6 (normal display mode)  

###### Performance Optimization  

- Reduce frequency of `OLED_updateDisplay()` calls (e.g., use partial refresh)

### MoodBot Intelligent Desktop Companion - Frontend Interface Overview

MoodBot is an innovative intelligent desktop companion system frontend built with React. It provides real-time interaction and status monitoring functionalities with hardware devices.

#### Main Functional Modules

1. **Mood Recognition and LED Display**
   - Real-time mood feedback: Receives mood status updates pushed from the backend, displaying current mood icons (😊 Happy / 😢 Sad / 😴 Tired)
   - Visual representation: Highlights the currently active mood status
   - Dynamic update: Uses WebSocket to receive mood changes in real time

2. **Smart Environment Control**
   - Environmental data monitoring: Displays real-time temperature and CO₂ concentration
   - Manual detection button: Allows triggering environment detection requests anytime
   - Automatic updates: Environment data is also automatically pushed via WebSocket

3. **Motion Control**
   - Direction control: Offers four movement buttons for forward, backward, left, and right
   - Real-time command sending: Clicking a button immediately sends a move command to the backend

4. **Remote Monitoring**
   - Monitoring activation: Starts remote monitoring feature via a button

#### Technical Features

- Real-time communication with full-duplex via Socket.IO
- Responsive design using card-style layout for clear module displays
- State management using React Hooks
- Automatic cleanup: event listeners unsubscribed and connections closed on component unmount

#### Usage Instructions

- Ensure backend service is running at http://localhost:3000  
- WebSocket connection is established automatically on page load  
- Modules operate independently without interference  
- All data updates are pushed in real time without manual refresh  

This frontend serves as the control center of the MoodBot system, providing users with intuitive interactions and real-time status feedback, making the intelligent desktop companion easy and enjoyable to operate.

---

### MoodBot Frontend Technology Stack Analysis

#### Core Frameworks and Technologies

- **React**: Main JavaScript library for building user interfaces  
  - Function components and Hooks (`useState`, `useEffect`)  
  - Component-based development  

- **Socket.IO client**: For real-time bidirectional communication  
  - Connects via `io('http://localhost:3000')`  
  - Listens with `socket.on()` for server events  
  - Sends events with `socket.emit()`  

- **CSS Modularization**: Style management  
  - Separate CSS file (App.css)  
  - Class selectors (`.container`, `.card` etc.)  
  - Includes transition animations  

#### Detailed Technical Implementation

- **State Management**  
  - React Hooks  
    - `useState`: manages internal state (`currentMood`, `temperature`, `co2Level`)  
    - `useEffect`: handles side effects (subscribe/unsubscribe to socket events, component cleanup)  

- **Real-time Communication**  
  - Event-driven architecture  
  - Listens to backend pushed events `'moodUpdate'` and `'environment'`  
  - Emits `'move'`, `'gameMode'`, `'startMonitoring'` events to backend  

- **UI Design**  
  - Responsive layout  
  - Card-style design with `.card` class  
  - Hover effect with `:hover` pseudo-class  
  - Adaptive width with `max-width: 600px`  
  - Interactive elements for buttons (`button` selector), status display (`.status-box`), and mood selector (`.mood-item`)  

#### Featured Technical Applications

- **CSS Transition Effects**  
  ```css
  .card {
    transition: transform 0.3s, box-shadow 0.3s;
  }
  .card:hover {
    transform: translateY(-5px);
    box-shadow: 0 8px 16px rgba(0, 0, 0, 0.2);
  }
#### Dynamic Class Name Switching

```jsx
<div className={`mood-item ${currentMood === '😊' ? 'active' : ''}`}>
```
#### WebSocket Connection Management
```javascript
useEffect(() => {
  return () => {
    socket.disconnect();
  };
}, []);

```
#### Technical Highlights  

- Real-time updates at millisecond level via Socket.IO  
- Responsive design adapts to various screen sizes  
- User-friendly interactions with button feedback and card hover effects  
- Modularized functional components that facilitate maintenance and scalability  
Script Content:
#!/bin/bash
SERVICE_NAME=npmdev
WORKING_DIR="/home/pi/Download
"SERVICE_FILE="/etc/systemd/system/${SERVICE_NAME}.service

# Check if the target directory exists
if [ ! -d "$WORKING_DIR" ]; then
    echo "❌ Directory $WORKING_DIR does not exist. Please verify the project path!"
    exit 1
fi

# Create systemd service file
sudo tee "$SERVICE_FILE" > /dev/null <<EOF
[Unit]
Description=Start npm dev server on boot
After=network.target

[Service]
ExecStart=/bin/bash -c 'cd ${WORKING_DIR} && npm run dev'
WorkingDirectory=${WORKING_DIR}
User=pi
Restart=always
Environment=PATH=/usr/bin:/usr/local/bin
Environment=NODE_ENV=production

[Install]
WantedBy=multi-user.target
EOF

# Reload systemd and enable the service
echo "🔄 Reloading systemd and enabling the service..."
sudo systemctl daemon-reexec
sudo systemctl daemon-reload
sudo systemctl enable "$SERVICE_NAME"
sudo systemctl start "$SERVICE_NAME"

# Display service status
echo "✅ Service started. Current status:"
sudo systemctl status "$SERVICE_NAME" --no-pager

echo -e "\n🎉 Setup complete! The service will now run automatically on boot."
Auto-run Script:
Usage:
1.	Save the script as setup_npm_service.sh
2.	Grant execute permissions:
bash
Copy
Download
chmod +x setup_npm_service.sh
3.	Run the script:
bash
Copy
Download
./setup_npm_service.sh
________________________________________
Mood Recognition and LED Display
Button:
•	Trigger Function: handleMoodChange(mood)
•	Send Event: socket.emit('mood', mood)
•	Data Passed: A string representing the current mood: '😊', '😢', or '😴'.
•	Backend Handling: The backend listens for the 'mood' event and updates the LED display or performs corresponding actions based on the received mood value.
Smart Environment Control
Button:
•	Check Environment
•	Trigger Function: socket.emit('checkEnvironment')
•	Send Event: 'checkEnvironment'
•	Backend Handling: The backend listens for the 'checkEnvironment' event, reads the current temperature and CO₂ concentration data, and sends the data back to the frontend via the 'environment' event.
•	Frontend Reception: In useEffect, the frontend listens for the 'environment' event, receives the data, and updates the state.
Movement Control
Buttons:
•	Forward, Left, Right, Backward
•	Trigger Function: handleMove(direction)
•	Send Event: socket.emit('move', direction)
•	Data Passed: A string representing the movement direction: 'forward', 'left', 'right', 'backward'.
•	Backend Handling: The backend listens for the 'move' event and controls MoodyBot's movement based on the received direction command.
Game Mode
Button:
•	Start Game Mode
•	Trigger Function: startGameMode()
•	Send Event: socket.emit('gameMode', true)
•	Data Passed: A boolean true, indicating the activation of game mode.
•	Backend Handling: The backend listens for the 'gameMode' event and activates the corresponding game mode functionality.
Remote Monitoring
Button:
•	Start Monitoring
•	Trigger Function: startMonitoring()
•	Send Event: socket.emit('startMonitoring', true)
•	Data Passed: A boolean true, indicating the activation of remote monitoring.
•	Backend Handling: The backend listens for the 'startMonitoring' event and activates the remote monitoring functionality.


This technology stack combination balances efficient development, excellent user experience, and maintainability, making it ideal for IoT control panel applications.  

### Emotion Detection
#### 1. Project Motivation

This project aims to build an emotion regulation software that can run on Raspberry Pi. The system detects a human face through a video camera, recognizes the current emotion of the person, and gives corresponding reactions. It enhances human-computer interaction and helps people cope with negative emotions such as anger, sadness, fear, or tiredness.

#### 2. Planned Delivery Content

- Main coding will be done in C++.  
- The system runs on Raspbian OS based on Debian Bookworm on a Raspberry Pi 5 with 4GB memory.  
- Video frames are captured via a video camera using OpenCV and faces and emotions are detected at about 10 FPS.  
- Upon detecting happy emotions, the system displays a happy emoji and phrases like “You are happy and I am happy too” and plays a notification sound.  
- For negative emotions, it displays a sad emoji with comforting words like “do not be sad.”  
- If the person looks very tired, it suggests taking a rest.

#### 3. Related Work

- A facial emotion recognition system mainly consists of face detection and emotion recognition.  
- Common face detection methods include SSD, YOLO, OpenCV Haar, and MediaPipe.  
- Emotion recognition often uses CNN-based neural networks or vision transformers.  
- Considering the constraints of Raspberry Pi 5 (4GB RAM), real-time performance, and C++ implementation, MediaPipe detection was chosen.  
- MediaPipe uses a TensorFlowLite int8 quantized Blazeface model that is fast, memory efficient, and effective.

#### 4. Development Progress

##### a. Hardware Selection

- Main board: Raspberry Pi 5  
  - Features a 64-bit quad-core Arm Cortex-A76 processor at 2.4 GHz, delivering up to 3x the performance of its predecessor.  
  - Supports graphics-intensive tasks like 4K video playback and 3D rendering.  
  - The 4GB memory model is used.  
- Camera: Logitech USB HD webcam C270  
  - Provides reliable 720p HD video with autofocus for sharp images under moderate lighting.  
  - Compatible with Raspberry Pi 5 and OpenCV.

##### b. Software Design

- Development environment: Qt Creator  
- GUI library: Qt5  
- Build toolchains: bazel, cmake, GNU configured  
- Libraries: Qt5, OpenCV from Ubuntu source, MediaPipe from GitHub  
- Software process: Two threads  
  - GUI thread: displays interface, video frames, and emotion reactions  
  - Background thread: detects faces, extracts face regions, runs emotion recognition model  
- Emotion recognition model: MobileNetV3-Small optimized using Adam optimizer and cross-entropy in PyTorch  
- Dataset: RAF-DB plus additional tired-face images, split into training and validation sets  
- Model accuracy: 83% on validation set  
- Model converted to ONNX format for efficient inference using ONNX Runtime  
- Sound playback via Qt Multimedia library  
- Final integration and build with bazel toolchain

#### 5. Performance Evaluation

- Runs smoothly on Raspberry Pi 5 at ~10 FPS with no crashes during tests.  
- Accurately detects single faces in camera view.  
- Emotion recognition results are satisfactory with correct identification of varied facial expressions.  
- Weakness: tired face recognition is less accurate.

#### 6. Remaining Tasks in Final Project Demonstration and Report

- The system effectively performs face detection and emotion recognition with appropriate responses.  
- It operates well on Raspberry Pi 5 and has promising applications and development potential.  
- Future work includes improving emotion recognition performance, especially for tired faces.
### Motor Control

#### File Structure and Function Description

1. **pwm_class.hpp**  
- Defines the `PWM_class`, responsible for managing PWM signals and controlling the motor.  
- Main members:  
  - Constructor `PWM_class(uint8_t PWM_number)`: Initializes corresponding GPIO pins based on the given PWM number.  
  - Destructor `~PWM_class()`: Releases GPIO resources and stops PWM output.  
  - Member function `Rotation(uint8_t dir)`: Controls motor rotation direction (stop, clockwise, counterclockwise).  
- Private members include two PWM pins, period and duty cycle parameters, and a pointer linked to the GPIO controller.

2. **gpio_pwm.hpp**  
- Defines constants and structs related to PWM control.  
- Contains PWM-related GPIO numbers and consumer identifiers.  
- Defines PWM operation command constants: Stop, Clockwise, Cou_Clockwise.  
- Struct `PWM_Pin` encapsulates GPIO line pointer, consumer string, and GPIO pin number.

3. **gpio_pwm.cpp**  
- Implements the `PWM_class` functions.  
- Constructor obtains GPIO lines for the given PWM group number and requests them as outputs.  
- `Rotation` sets the high/low levels of two PWM pins according to the direction parameter, using delay to control pulse width.  
- Destructor sets PWM pins low and releases GPIO resources.

#### Detailed Function Description

- `PWM_class(uint8_t PWM_number)`  
  Initializes a PWM instance, binds two GPIO pins of the corresponding PWM group, and requests output permission to prepare for PWM signal output.

- `~PWM_class()`  
  Stops PWM output and releases GPIO line resources.

- `void Rotation(uint8_t dir)`  
  Generates PWM signals for different motor directions by controlling GPIO pin voltage levels and duty cycle delays:  
  - **Stop**: outputs all low levels, motor stops.  
  - **Clockwise**: sets `PWM_0_` pin high first; controls power-on duration via duty cycle to rotate clockwise.  
  - **Cou_Clockwise**: sets `PWM_1_` pin high first; controls power-on duration via duty cycle to rotate counterclockwise.

#### Basic Principle of PWM Motor Driving and Code Implementation

##### Principle Summary  
PWM (Pulse Width Modulation) controls the average voltage supplied to the motor by adjusting the duty cycle—the ratio of high-level (on) time to the signal period—thus regulating motor speed and direction. Two PWM signals alternately control power on both ends of the motor to achieve forward and reverse rotations.

##### Code Implementation Details  
- A period variable is defined (1000 microseconds), with a default duty cycle of 50%.  
- In the `Rotation` function, based on the target rotation direction, PWM output is achieved by setting two GPIO pins’ levels:  
  - High/low voltage combinations determine motor polarity and rotation direction.  
  - Use of `usleep` delays generates the corresponding high and low level durations to form periodic PWM signals.

### Servo Control

#### File Structure and Function Description

1. **Servo.hpp**  
- Defines basic macros and constants needed for servo control.  
- Includes PWM period macro definition (`PERIOD_US`, 1ms) and GPIO chip path (`GPIO_CHIP`).  
- Defines GPIO pin numbers for two servos: Servo1 (24) and Servo2 (25).  
- Includes necessary multithreading and mutex header files.

2. **Servo_class.hpp**  
- Declares the `Servo_class` C++ class to manage GPIO resources based on the `gpiod` library and implement PWM control of servos.  
- Main public member methods:  
  - Constructor `Servo_class(const char* chip_path = GPIO_CHIP)`: Opens the specified GPIO chip.  
  - Destructor `~Servo_class()`: Closes the GPIO chip.  
  - `Servo_init()`: Initializes and checks if the chip was successfully opened.  
  - `set_pwm_output(int pin, int duty_cycle_percent)`: Sets PWM output based on duty cycle percentage.  
  - `set_pwm_pulse_ms(int pin, float pulse_ms)`: Sets PWM signal using pulse width in milliseconds.  
  - `Servo_disable(int pin)`: Stops PWM output on the specified GPIO pin.  
  - `release_gpio()`: Releases all requested GPIO resources.  
  - Servo movement helper functions: `Servo_up(int pin)` and `Servo_down(int pin)` implement upward and downward servo movements respectively.  
- Private members include:  
  - Pointer managing the GPIO chip, threads, running states, and GPIO line mappings.  
  - Private interface `get_gpio_line(int pin)` to obtain GPIO lines.

3. **Servo.cpp**  
- Implements the `Servo_class`.  
- Uses the `gpiod` library to manage GPIO line requests and releases, ensuring thread safety.  
- The `set_pwm_output` method stops existing PWM threads (if any) and creates new threads that simulate PWM output via software delay, with a 1ms signal period.  
- The `set_pwm_pulse_ms` method generates pulse width signals common in servo control (0.5ms–2.5ms) with a 20ms period (50Hz), conforming to standard servo PWM protocol.  
- The `Servo_disable` method stops and cleans up the PWM thread on the GPIO pin, effectively stopping PWM output.  
- The `release_gpio` method releases all occupied GPIO lines.  
- `Servo_up` and `Servo_down` call `set_pwm_pulse_ms` to generate corresponding pulse signals for servo rising and lowering, then stop PWM output afterward.

#### Detailed Function Description

- `Servo_class::Servo_class(const char* chip_path)`  
  Initializes the object and opens the specified GPIO chip device.

- `bool Servo_class::Servo_init()`  
  Checks whether the GPIO chip was successfully opened and sets initialization status.

- `gpiod_line* Servo_class::get_gpio_line(int pin)`  
  Obtains the GPIO line for the specified pin and requests output rights if not already acquired.

- `void Servo_class::set_pwm_output(int pin, int duty_cycle_percent)`  
  Software PWM controlled by duty cycle percentage: starts a thread that continuously toggles the pin high/low to generate PWM.

- `void Servo_class::set_pwm_pulse_ms(int pin, float pulse_ms)`  
  Generates PWM signals with pulse widths ranging from 0.5ms to 2.5ms at 20ms period to control servo angle.

- `void Servo_class::Servo_disable(int pin)`  
  Stops and cleans up the PWM control thread on the given pin, disabling PWM output.

- `void Servo_class::release_gpio()`  
  Releases all requested GPIO lines to ensure clean GPIO states at program exit.

- `void Servo_class::Servo_up(int pin)`, `void Servo_class::Servo_down(int pin)`  
  Perform servo upward or downward movements by sending specific pulse widths, then disable PWM output after the action.

#### Basic Principle of PWM Servo Driving and Code Implementation

##### Principle  
Servo control signals are PWM signals with a 20ms period (50Hz). The servo angle is controlled by adjusting pulse width within approximately 0.5ms to 2.5ms, corresponding to minimum and maximum angles. The duty cycle of the PWM directly determines the servo shaft position.

##### Code Implementation  
- The function `set_pwm_pulse_ms` starts a dedicated thread that continuously outputs a high level for the specified pulse duration (`pulse_ms`), then outputs low level to complete the 20ms cycle.  
- The high-level duration controls the servo angle; the thread keeps generating PWM to maintain servo position.  
- Software PWM is implemented by controlling GPIO output via the `gpiod` library and `usleep` for microsecond-level timing, emulating hardware PWM.  
- This method allows Raspberry Pi GPIO to precisely drive MG996R servos, achieving the required rotational control.

### RD-03 Human Presence Detection Sensor

#### File Structure and Function Description

1. **Rd-03.hpp**  
- Defines macros for RD-03 related GPIO pin numbers, serial communication baud rate, and human detection status constants (`NO_HUM` and `HUM`).  
- Includes necessary GPIO and system header files.  
- Declares external variable `chip0` linked to GPIO chip operations.

2. **Rd-03_class.hpp**  
- Defines the `RD_class` responsible for low-level interaction with the RD-03 sensor.  
- Member variables include pointers for GPIO operations (`gpiod_chip*` and `gpiod_line*`), serial device offset `offset_`, and sensor configuration parameters such as minimum detection distance `min_dist_cm`, maximum detection distance `max_dist_cm`, and target disappearance delay `delay_s`.  
- Provides constructors, destructor, and core reading function `GetValue()`.

3. **Rd-03.cpp**  
- Implements the functionality of `RD_class`.  
- Opens and initializes serial communication via `open_serial`, configuring baud rate and communication parameters.  
- Uses `enter_cmd_mode`, `set_param`, and `exit_cmd_mode` to configure sensor parameters (minimum/maximum distance and delay) through a specific protocol.  
- Uses Linux `gpiod` library to read GPIO input, and through repeated sampling via `GetValue` determines human presence.

4. **Rd-03_register.cpp**  
- Provides `RDGetter` class that monitors `RD_class` state changes based on event-driven mechanism.  
- Creates an event file descriptor (`eventfd`) and monitoring thread that continuously reads sensor values and notifies the event bus (`EventBus`).  
- Implements event blocking wait and thread lifecycle management (start/stop).

---

#### Key Function Descriptions

- **RD_class Constructor `RD_class(uint8_t offset, const std::string &consumer)`**  
  Initializes the serial connection and enters command mode to configure sensor parameters (min/max distance, delay time).  
  Initializes GPIO interface and binds corresponding GPIO line number.  
  Parameter `offset` specifies GPIO offset address; `consumer` is the consumer identifier string.

- **`int RD_class::GetValue()`**  
  Reads GPIO input line multiple times (5 samples).  
  If high level is detected more than 3 times, returns human detected (`HUM`), otherwise no human (`NO_HUM`).

- **Serial Communication Helper Functions**  
  - `open_serial(const char *dev)`: Opens the serial device and configures baud rate and operating mode.  
  - `enter_cmd_mode(int fd)` and `exit_cmd_mode(int fd)`: Control sensor entry and exit from command mode.  
  - `set_param(int fd, uint16_t param_id, uint16_t value)`: Writes configuration parameters according to sensor protocol.

- **RDGetter Core Functions (Event Monitoring Related)**  
  - `startWatcher()`: Starts a background thread continuously reading sensor status and triggers event notification upon state changes.  
  - `blockAndWaitEvent()`: Blocks and waits for event trigger.

---

#### RD-03 Sensor Basic Principle and Code Implementation

The RD-03 sensor configures internal parameters via serial communication and reads output signals from a GPIO pin. The basic detection logic is:

- When the sensor detects a human presence, the GPIO outputs a high-level signal; otherwise, it outputs low level.  
- Through serial configuration, the effective detection distance (`min_dist_cm` and `max_dist_cm`) and the target disappearance delay (`delay_s`) can be set.  
- The code opens serial port and enters command mode, sets these parameters via protocol frames, then exits command mode.  
- It monitors GPIO pin levels via repeated sampling with debounce filtering to accurately detect presence.  
- The event monitoring thread uses the `eventfd` mechanism to respond to and notify about state changes, facilitating integration with higher-level business logic.

### DHT11 Environmental Temperature and Humidity Sensor

#### File Structure and Function Description

1. **`DHT11.hpp`**  
- Defines the GPIO pin for the DHT11 sensor (BCM pin 4, macro `DHT_GPIO`).  
- Sets communication-related constants: response timeout (`RESPONSE_TIMEOUT_MS`, 7 ms), logic level threshold (`LOGIC_THRESHOLD_US`, 56 µs), and maximum signal edges (`MAX_EDGES`, 82).  
- Includes GPIO-related header files and required C++ standard libraries.

2. **`DHT11_class.hpp`**  
- Implements the `DHT11_class` responsible for managing the hardware interface of the DHT11 sensor.  
- Contains constructor and destructor, with member variables including GPIO chip (`chip_`), GPIO line (`line_`), GPIO offset, and consumer identifier.  
- Core interface is `MT_check()`, which reads temperature and humidity data.

3. **`DHT11.cpp`**  
- Implements `DHT11_class` core functionality.  
- `MT_check()` communicates with the DHT11 sensor by:  
  - Sending a start signal to activate the sensor.  
  - Listening to GPIO line signal edges, recording timestamps and interpreting bit values based on timing intervals.  
  - Parsing the sequence to extract integer and decimal parts of humidity and temperature.  
  - Encoding temperature and humidity values as an integer using `pack5DigitsFromFloat`.  
- Provides microsecond and millisecond delay functions (`delay_us`, `delay_ms`) to meet communication timing requirements.

4. **`DHT11_register.cpp`**  
- Implements `DHTGetter` class for periodic reading and publishing of sensor data to an event bus.  
- Binds event bus via callback mechanism for real-time data publishing.  
- Maintains a background sampling thread that calls `MT_check()` every 2 seconds and writes data to an event file descriptor (`eventfd`).  
- Provides blocking wait on events (`blockAndWaitEvent()`) and safe thread stopping (`stopWatcher()`).

---

#### Key Function Descriptions

- **`DHT11_class::MT_check()`**  
  Sends a wake-up signal (pulls GPIO low for 20 ms then high for 30 µs) to start the sensor.  
  Requests GPIO to capture both edges, monitoring up to 82 signal edges during data transmission.  
  Parses timing intervals to distinguish 0/1 bits using the threshold.  
  Extracts humidity and temperature integer and fractional parts, encoding them into a single integer.  
  Returns -1 if any error occurs.

- **`DHTGetter::startWatcher()`**  
  Starts a dedicated thread that calls `MT_check()` every 2 seconds, writing valid readings to eventfd to notify other modules.

- **`DHTGetter::blockAndWaitEvent()`**  
  Blocks reading the eventfd, waiting for new data to ensure synchronized communication.

---

#### DHT11 Sensor Basic Principle and Code Implementation

The DHT11 sensor uses a single-wire digital communication protocol to transmit temperature and humidity data through timing sequences on a single GPIO line:

- The host (Raspberry Pi) initiates by pulling the GPIO line low for at least 18 ms to activate the sensor.  
- The sensor responds with a start signal, then sends 40 bits of data: 8 bits humidity integer, 8 bits humidity decimal, 8 bits temperature integer, 8 bits temperature decimal, and a checksum.  
- Each bit is determined by measuring the length of the high-level pulse (approximately 26-28 µs for "0" and about 70 µs for "1").  
- The code uses the `gpiod` library to monitor GPIO edge events, precisely recording timestamps of rising and falling edges and calculating timing differences to decode the binary data.  
- Temperature and humidity data are compiled and encoded into an integer for further transmission and handling.  
- The solution combines event-driven design and multithreading for stable and efficient environmental temperature and humidity acquisition.
### DHT11 Environmental Temperature and Humidity Sensor & 5516 Light Intensity Detection Module

#### File Structure and Function Description

1. **`5516.hpp`**  
- Defines the GPIO pin number connected to the 5516 sensor (BCM 17) and the consumer identifier `"light-sensor"`.  
- Defines sensor status constants: `LIGHT` (light detected, value 0) and `NO_LIGHT` (no light detected, value 1).  
- Includes the GPIO operation library header `gpiod`.  
- Declares external variable `chip0` for unified GPIO chip access.

2. **`5516_class.hpp`**  
- Defines the `S5516_class` encapsulating hardware operations for the sensor.  
- Constructor `S5516_class(uint8_t offset, const std::string &consumer)` initializes the GPIO line.  
- Provides `GetValue()` to obtain the current light detection status.

3. **`5516.cpp`**  
- Implements constructor, destructor, and core methods of `S5516_class`.  
- Constructor acquires GPIO line via `gpiod_chip_get_line` and requests input mode.  
- `GetValue()` samples the GPIO input 5 times, counts high level instances. If high level ≥3 times, returns `NO_LIGHT` (no light); else returns `LIGHT`. Implements simple debounce filtering.  
- Destructor releases resources.

4. **`5516_register.cpp`**  
- Implements `S5516Getter` class for event-driven sensor state monitoring and notification.  
- Uses Linux event file descriptor (`eventfd`) for blocking listening and event triggers.  
- `startWatcher()` launches a background thread that continuously reads the sensor state and notifies event bus on abnormal conditions.  
- `blockAndWaitEvent()` blocks until event signals occur, mainly detecting no-light events.  
- `stopWatcher()` stops the thread and safely exits monitoring.

---

#### Key Function Descriptions

- **`S5516_class::S5516_class(uint8_t offset, const std::string &consumer)`**  
  Initializes the GPIO chip and the specified GPIO line offset as input.  
  Parameters: `offset` for GPIO line offset number; `consumer` as the user identifier.

- **`int S5516_class::GetValue()`**  
  Reads the GPIO line state 5 times.  
  Counts the number of high levels detected; high level represents "no light".  
  If 3 or more times are high, returns `NO_LIGHT`; otherwise returns `LIGHT`.  
  Multiple sampling reduces noise and debounce effects.

- **`S5516Getter` class related functions**  
  Constructor creates `eventfd` and registers callback to notify the event bus.  
  `startWatcher()` runs a thread repeatedly calling `GetValue()`, writing to eventfd on detecting abnormal states.  
  `blockAndWaitEvent()` blocks waiting on eventfd signal, returns upon no-light event.  
  `stopWatcher()` safely stops the monitoring thread.

---

#### 5516 Light Sensor Basic Principle and Code Implementation

The 5516 light sensor outputs digital signal (DO pin) indicating light detection status via GPIO:

- When light is detected, the DO pin outputs low level (0), indicating light presence.  
- When no light is detected, the DO pin outputs high level (1), indicating no light.  
- The code uses the `gpiod` library to access GPIO pin BCM 17 configured as input to read this digital signal.  
- `GetValue()` samples the GPIO input 5 times, counts the number of high levels, if ≥3 judged as "no light", otherwise "light".  
- This simple multiple sampling method effectively filters noise and signal jitter, reducing false detection.  
- Using event listening modules allows timely response to changes in light intensity state.
### QM2 Smoke Detection Module

#### File Structure and Function Description

1. **`QM2.hpp`**  
- Defines parameters related to the QM2 smoke sensor:  
  - Connected GPIO pin number (`GPIO_QM2`, BCM pin 21).  
  - Device consumer identifier (`QM2_CONSUMER`).  
  - Sampling count (`SAMPLE_COUNT`), sampling interval (`SAMPLE_INTERVAL_MS`), and threshold for high-level count to judge alarm (`THRESHOLD_COUNT`).  
  - Smoke detection status codes: normal state `SMOKE_NOR` and smoke alarm `SMOKE_ERR`.

2. **`QM2_class.hpp`**  
- Defines the `QM2_class` that encapsulates GPIO resource management and smoke detection logic.  
- Constructor takes GPIO offset and consumer name to initialize the GPIO chip and line.  
- Contains `Smoke_check()` function for smoke status detection and `getState()` to get current GPIO line state.  
- Private members include GPIO chip pointer, GPIO line pointer, sampling parameters, and thresholds.

3. **`QM2.cpp`**  
- Implements `QM2_class`:  
  - Constructor opens and binds to `gpiochip0`, requests the specified GPIO line as input.  
  - `Smoke_check()` reads GPIO multiple times, counts high-level occurrences.  
  - If high-level count is below threshold, smoke concentration is considered abnormal, returning `SMOKE_ERR`; otherwise returns `SMOKE_NOR`.  
  - Destructor releases GPIO resources.

4. **`QM2_register.cpp`**  
- Implements `QM2Getter` class for event-based smoke monitoring and notification.  
- Constructor creates event file descriptor (`eventfd`) for blocking wait and registers callback to publish messages to the event bus (`EventBus`).  
- `startWatcher()` runs in a separate thread, continuously calling `Smoke_check()`, writes to eventfd on abnormal smoke detection to trigger notification.  
- `blockAndWaitEvent()` blocks reading eventfd to synchronously wait for smoke events.  
- `stopWatcher()` stops the monitoring thread and safely exits.

---

#### Key Function Descriptions

- **QM2_class Constructor**  
  `QM2_class(uint8_t offset, const std::string &consumer_key)`  
  Opens GPIO chip, gets GPIO line with specified offset, and requests input mode.  
  Initializes the smoke detection line.

- **`int QM2_class::Smoke_check()`**  
  Performs multiple (`SAMPLE_COUNT`) GPIO readings, each spaced by `SAMPLE_INTERVAL_MS` milliseconds.  
  Counts the number of high-level reads.  
  If high-level count is less than or equal to threshold `THRESHOLD_COUNT`, returns smoke alarm `SMOKE_ERR`.  
  Otherwise returns normal status `SMOKE_NOR`.  
  Implements smoke concentration detection via GPIO level sampling.

- **QM2Getter’s `startWatcher()` and `blockAndWaitEvent()`**  
  Monitors smoke status in a thread loop by calling `Smoke_check()`.  
  On detecting smoke alarm, writes to eventfd to trigger notification.  
  Blocks waiting for event occurrence enabling event-driven upper-level logic.

---

#### QM2 Smoke Sensor Basic Principle and Code Implementation

The QM2 smoke sensor provides digital output (DO) reflecting smoke concentration:

- The sensor's digital output DO connects to Raspberry Pi’s GPIO pin.  
- When smoke concentration exceeds threshold, DO outputs low level (logic 0); otherwise high level (logic 1).  
- The code uses `gpiod` library to access GPIO input line state and performs multiple fast samplings counting high-level instances.  
- When sampled high-level counts fall below the set threshold, smoke alarm is indicated.  
- The event monitoring module enables real-time detection and response to smoke alarm states, facilitating integration with higher-level systems for smoke alert handling.

### USB Speaker

#### File Structure and Function Description

1. **`Audio.hpp`**  
- Includes headers for SDL2 and SDL_mixer libraries required for audio playback.  
- Defines preset music file paths categorized by mood (tired, happy, sad).  
- Includes standard IO, threading, atomic operations, and signal handling libraries to support multi-threaded audio playback and event management.

2. **`Audio_class.hpp`**  
- Defines `Audio_class` as the core interface for sound playback functionality.  
- Members include private `Mix_Music* music_` pointer to manage audio stream and current volume `volume_`.  
- Public interface includes constructor (initializes volume and audio system), destructor (frees resources), `AudioPlay` (plays specified audio file), `AudioStop` (stops playback), and `SetVol` (sets playback volume).

3. **`Audio.cpp`**  
- Implements `Audio_class`.  
- Constructor initializes SDL audio subsystem and SDL_mixer library, configuring sample rate and audio format, setting initial volume, with error handling.  
- `AudioPlay` loads the specified music file and plays it once.  
- `AudioStop` stops any currently playing audio immediately.  
- `SetVol` adjusts playback volume.  
- Destructor cleans up audio resources and closes audio system.

4. **`Audio_register.cpp`**  
- Contains `AudioSetter` class responsible for event listening and command response for audio playback control.  
- Uses `timerfd` for periodic event triggering and `eventfd` for event notifications.  
- `blockAndWaitEvent()` blocks waiting on timer or event file descriptors using `poll`.  
- `toggle(int cmd)` plays the audio associated with the given command or mutes.  
- Provides state retrieval and event notification interfaces.

---

#### Key Function Descriptions

- **`Audio_class::Audio_class(uint8_t volume)`**  
  Initializes SDL audio modules and SDL_mixer library.  
  Configures audio playback format: 44100 Hz sample rate, stereo, 2048 byte buffer.  
  Sets initial volume as passed, prints error on failure.

- **`void Audio_class::AudioPlay(std::string Music)`**  
  Loads music file from given path.  
  If successful, plays the music once via SDL_mixer.  
  Prints error messages if loading fails.

- **`void Audio_class::AudioStop()`**  
  Immediately stops any currently playing music.

- **`void Audio_class::SetVol(uint8_t Vol)`**  
  Adjusts the playback volume dynamically.

- **`AudioSetter::blockAndWaitEvent()`**  
  Blocks waiting on timer and event file descriptors.  
  Returns current command to process or timer interrupts after event occurrence.

- **`AudioSetter::toggle(int cmd)`**  
  Plays the corresponding audio file based on the command (happy, sad, tired, etc.).  
  Command 0 means mute and sets volume to 0.

---

#### USB Speaker Basic Principle and Code Implementation

The USB speaker connects to the Raspberry Pi via USB and serves as the system's default audio output device. The Raspberry Pi routes digital audio data to the USB speaker through the OS audio subsystem (e.g., ALSA). This project uses SDL2 and SDL_mixer for audio playback abstraction:

- SDL initializes the audio subsystem; SDL_mixer handles decoding and playback of multiple audio formats.  
- Audio files are loaded into memory with SDL_mixer, then playback calls output audio via the system sound card (the USB speaker).  
- Supports dynamic volume adjustment and stopping playback.  
- Event-driven and timer-based control logic enables flexible and intelligent audio playback management.

## Code Structure

```
📦 
├─ BSP
│  ├─ BSP_5516
│  │  ├─ 5516.cpp
│  │  ├─ 5516.hpp
│  │  ├─ 5516_class.hpp
│  │  ├─ 5516_main.cpp
│  │  ├─ 5516_register.cpp
│  │  ├─ CMakeLists.txt
│  │  └─ build
│  │     ├─ 5516_EG
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ 5516_EG.dir
│  │     │  │  ├─ 5516.cpp.o
│  │     │  │  ├─ 5516.cpp.o.d
│  │     │  │  ├─ 5516_main.cpp.o
│  │     │  │  ├─ 5516_main.cpp.o.d
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.internal
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  ├─ BSP_KEYS
│  │     │  │  │        │  │  ├─ Key_register.cpp.o
│  │     │  │  │        │  │  ├─ Key_register.cpp.o.d
│  │     │  │  │        │  │  ├─ Keys.cpp.o
│  │     │  │  │        │  │  └─ Keys.cpp.o.d
│  │     │  │  │        │  └─ BSP_LED
│  │     │  │  │        │     ├─ Led.cpp.o
│  │     │  │  │        │     ├─ Led.cpp.o.d
│  │     │  │  │        │     ├─ Led_register.cpp.o
│  │     │  │  │        │     └─ Led_register.cpp.o.d
│  │     │  │  │        └─ SYS_Con
│  │     │  │  │           ├─ Getter_EventDriven.cpp.o
│  │     │  │  │           ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │           ├─ Sys_Functions.cpp.o
│  │     │  │  │           ├─ Sys_Functions.cpp.o.d
│  │     │  │  │           └─ src
│  │     │  │  │              ├─ EventBus.cpp.o
│  │     │  │  │              ├─ EventBus.cpp.o.d
│  │     │  │  │              ├─ Getter_EventDriven.cpp.o
│  │     │  │  │              ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │              ├─ I2C_Command.cpp.o
│  │     │  │  │              ├─ I2C_Command.cpp.o.d
│  │     │  │  │              ├─ SPI_Command.cpp.o
│  │     │  │  │              ├─ SPI_Command.cpp.o.d
│  │     │  │  │              ├─ Setter_EventDriven.cpp.o
│  │     │  │  │              ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │              ├─ Sys_Functions.cpp.o
│  │     │  │  │              └─ Sys_Functions.cpp.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ Makefile
│  │     └─ cmake_install.cmake
│  ├─ BSP_Audio
│  │  ├─ Audio.cpp
│  │  ├─ Audio.hpp
│  │  ├─ Audio_class.hpp
│  │  ├─ Audio_main.cpp
│  │  ├─ Audio_register.cpp
│  │  ├─ CMakeLists.txt
│  │  └─ build
│  │     ├─ AUD_EG
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ AUD_EG.dir
│  │     │  │  ├─ Audio.cpp.o
│  │     │  │  ├─ Audio.cpp.o.d
│  │     │  │  ├─ Audio_main.cpp.o
│  │     │  │  ├─ Audio_main.cpp.o.d
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.internal
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  ├─ BSP_5516
│  │     │  │  │        │  │  ├─ 5516.cpp.o
│  │     │  │  │        │  │  ├─ 5516.cpp.o.d
│  │     │  │  │        │  │  ├─ 5516_register.cpp.o
│  │     │  │  │        │  │  └─ 5516_register.cpp.o.d
│  │     │  │  │        │  ├─ BSP_KEYS
│  │     │  │  │        │  │  ├─ Key_register.cpp.o
│  │     │  │  │        │  │  ├─ Key_register.cpp.o.d
│  │     │  │  │        │  │  ├─ Keys.cpp.o
│  │     │  │  │        │  │  └─ Keys.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LCD
│  │     │  │  │        │  │  ├─ LCD.cpp.o
│  │     │  │  │        │  │  ├─ LCD.cpp.o.d
│  │     │  │  │        │  │  ├─ LCD_Config.cpp.o
│  │     │  │  │        │  │  └─ LCD_Config.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LED
│  │     │  │  │        │  │  ├─ Led.cpp.o
│  │     │  │  │        │  │  ├─ Led.cpp.o.d
│  │     │  │  │        │  │  ├─ Led_register.cpp.o
│  │     │  │  │        │  │  └─ Led_register.cpp.o.d
│  │     │  │  │        │  ├─ BSP_PWM
│  │     │  │  │        │  │  ├─ gpio_pwm.cpp.o
│  │     │  │  │        │  │  ├─ gpio_pwm.cpp.o.d
│  │     │  │  │        │  │  ├─ pwm_register.cpp.o
│  │     │  │  │        │  │  └─ pwm_register.cpp.o.d
│  │     │  │  │        │  ├─ BSP_QM2
│  │     │  │  │        │  │  ├─ QM2.cpp.o
│  │     │  │  │        │  │  └─ QM2.cpp.o.d
│  │     │  │  │        │  ├─ BSP_RD-03
│  │     │  │  │        │  │  ├─ Rd-03.cpp.o
│  │     │  │  │        │  │  ├─ Rd-03.cpp.o.d
│  │     │  │  │        │  │  ├─ Rd-03_register.cpp.o
│  │     │  │  │        │  │  └─ Rd-03_register.cpp.o.d
│  │     │  │  │        │  └─ BSP_Servo
│  │     │  │  │        │     ├─ Servo.cpp.o
│  │     │  │  │        │     ├─ Servo.cpp.o.d
│  │     │  │  │        │     ├─ ServoPro.cpp.o
│  │     │  │  │        │     └─ ServoPro.cpp.o.d
│  │     │  │  │        ├─ SYS_Con
│  │     │  │  │        │  ├─ Getter_EventDriven.cpp.o
│  │     │  │  │        │  ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │        │  ├─ Setter_EventDriven.cpp.o
│  │     │  │  │        │  ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │        │  ├─ Sys_Functions.cpp.o
│  │     │  │  │        │  ├─ Sys_Functions.cpp.o.d
│  │     │  │  │        │  └─ src
│  │     │  │  │        │     ├─ EventBus.cpp.o
│  │     │  │  │        │     ├─ EventBus.cpp.o.d
│  │     │  │  │        │     ├─ Getter_EventDriven.cpp.o
│  │     │  │  │        │     ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │        │     ├─ I2C_Command.cpp.o
│  │     │  │  │        │     ├─ I2C_Command.cpp.o.d
│  │     │  │  │        │     ├─ SPI_Command.cpp.o
│  │     │  │  │        │     ├─ SPI_Command.cpp.o.d
│  │     │  │  │        │     ├─ Setter_EventDriven.cpp.o
│  │     │  │  │        │     ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │        │     ├─ Sys_Functions.cpp.o
│  │     │  │  │        │     └─ Sys_Functions.cpp.o.d
│  │     │  │  │        └─ lib
│  │     │  │  │           └─ Fonts
│  │     │  │  │              ├─ font12.c.o
│  │     │  │  │              ├─ font12.c.o.d
│  │     │  │  │              ├─ font16.c.o
│  │     │  │  │              └─ font16.c.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ SER_EG.dir
│  │     │  │  ├─ Audio.cpp.o
│  │     │  │  ├─ Audio.cpp.o.d
│  │     │  │  ├─ Audio_main.cpp.o
│  │     │  │  ├─ Audio_main.cpp.o.d
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.internal
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  ├─ BSP_5516
│  │     │  │  │        │  │  ├─ 5516.cpp.o
│  │     │  │  │        │  │  ├─ 5516.cpp.o.d
│  │     │  │  │        │  │  ├─ 5516_register.cpp.o
│  │     │  │  │        │  │  └─ 5516_register.cpp.o.d
│  │     │  │  │        │  ├─ BSP_KEYS
│  │     │  │  │        │  │  ├─ Key_register.cpp.o
│  │     │  │  │        │  │  ├─ Key_register.cpp.o.d
│  │     │  │  │        │  │  ├─ Keys.cpp.o
│  │     │  │  │        │  │  └─ Keys.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LCD
│  │     │  │  │        │  │  ├─ LCD.cpp.o
│  │     │  │  │        │  │  ├─ LCD.cpp.o.d
│  │     │  │  │        │  │  ├─ LCD_Config.cpp.o
│  │     │  │  │        │  │  └─ LCD_Config.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LED
│  │     │  │  │        │  │  ├─ Led.cpp.o
│  │     │  │  │        │  │  ├─ Led.cpp.o.d
│  │     │  │  │        │  │  ├─ Led_register.cpp.o
│  │     │  │  │        │  │  └─ Led_register.cpp.o.d
│  │     │  │  │        │  ├─ BSP_PWM
│  │     │  │  │        │  │  ├─ gpio_pwm.cpp.o
│  │     │  │  │        │  │  ├─ gpio_pwm.cpp.o.d
│  │     │  │  │        │  │  ├─ pwm_register.cpp.o
│  │     │  │  │        │  │  └─ pwm_register.cpp.o.d
│  │     │  │  │        │  ├─ BSP_RD-03
│  │     │  │  │        │  │  ├─ Rd-03.cpp.o
│  │     │  │  │        │  │  ├─ Rd-03.cpp.o.d
│  │     │  │  │        │  │  ├─ Rd-03_register.cpp.o
│  │     │  │  │        │  │  └─ Rd-03_register.cpp.o.d
│  │     │  │  │        │  └─ BSP_Servo
│  │     │  │  │        │     ├─ Servo.cpp.o
│  │     │  │  │        │     ├─ Servo.cpp.o.d
│  │     │  │  │        │     ├─ ServoPro.cpp.o
│  │     │  │  │        │     ├─ ServoPro.cpp.o.d
│  │     │  │  │        │     ├─ Servo_main.cpp.o
│  │     │  │  │        │     └─ Servo_main.cpp.o.d
│  │     │  │  │        ├─ SYS_Con
│  │     │  │  │        │  └─ src
│  │     │  │  │        │     ├─ EventBus.cpp.o
│  │     │  │  │        │     ├─ EventBus.cpp.o.d
│  │     │  │  │        │     ├─ Getter_EventDriven.cpp.o
│  │     │  │  │        │     ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │        │     ├─ I2C_Command.cpp.o
│  │     │  │  │        │     ├─ I2C_Command.cpp.o.d
│  │     │  │  │        │     ├─ SPI_Command.cpp.o
│  │     │  │  │        │     ├─ SPI_Command.cpp.o.d
│  │     │  │  │        │     ├─ Setter_EventDriven.cpp.o
│  │     │  │  │        │     ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │        │     ├─ Sys_Functions.cpp.o
│  │     │  │  │        │     └─ Sys_Functions.cpp.o.d
│  │     │  │  │        └─ lib
│  │     │  │  │           └─ Fonts
│  │     │  │  │              ├─ font12.c.o
│  │     │  │  │              ├─ font12.c.o.d
│  │     │  │  │              ├─ font16.c.o
│  │     │  │  │              └─ font16.c.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ Makefile
│  │     └─ cmake_install.cmake
│  ├─ BSP_Camera
│  │  ├─ CMakeLists.txt
│  │  ├─ Camera.cpp
│  │  ├─ Camera.hpp
│  │  ├─ Camera_class.hpp
│  │  ├─ Camera_register.cpp
│  │  ├─ Interpreter.cpp
│  │  ├─ Interpreter.h
│  │  ├─ Types.h
│  │  ├─ build
│  │  │  ├─ CMakeCache.txt
│  │  │  ├─ CMakeFiles
│  │  │  │  ├─ 3.25.1
│  │  │  │  │  ├─ CMakeASMCompiler.cmake
│  │  │  │  │  ├─ CMakeCCompiler.cmake
│  │  │  │  │  ├─ CMakeCXXCompiler.cmake
│  │  │  │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │  │  │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │  │  │  │  ├─ CMakeSystem.cmake
│  │  │  │  │  ├─ CompilerIdC
│  │  │  │  │  │  ├─ CMakeCCompilerId.c
│  │  │  │  │  │  └─ a.out
│  │  │  │  │  └─ CompilerIdCXX
│  │  │  │  │     ├─ CMakeCXXCompilerId.cpp
│  │  │  │  │     └─ a.out
│  │  │  │  ├─ CMakeDirectoryInformation.cmake
│  │  │  │  ├─ CMakeOutput.log
│  │  │  │  ├─ Detector.dir
│  │  │  │  │  ├─ DependInfo.cmake
│  │  │  │  │  ├─ build.make
│  │  │  │  │  ├─ cmake_clean.cmake
│  │  │  │  │  ├─ compiler_depend.internal
│  │  │  │  │  ├─ compiler_depend.make
│  │  │  │  │  ├─ compiler_depend.ts
│  │  │  │  │  ├─ depend.make
│  │  │  │  │  ├─ flags.make
│  │  │  │  │  ├─ link.txt
│  │  │  │  │  ├─ main.cpp.o
│  │  │  │  │  ├─ main.cpp.o.d
│  │  │  │  │  └─ progress.make
│  │  │  │  ├─ FindOpenMP
│  │  │  │  │  ├─ ompver_C.bin
│  │  │  │  │  └─ ompver_CXX.bin
│  │  │  │  ├─ Makefile.cmake
│  │  │  │  ├─ Makefile2
│  │  │  │  ├─ Progress
│  │  │  │  │  ├─ 1
│  │  │  │  │  ├─ 10
│  │  │  │  │  ├─ 100
│  │  │  │  │  ├─ 11
│  │  │  │  │  ├─ 12
│  │  │  │  │  ├─ 13
│  │  │  │  │  ├─ 14
│  │  │  │  │  ├─ 15
│  │  │  │  │  ├─ 16
│  │  │  │  │  ├─ 17
│  │  │  │  │  ├─ 18
│  │  │  │  │  ├─ 19
│  │  │  │  │  ├─ 2
│  │  │  │  │  ├─ 20
│  │  │  │  │  ├─ 21
│  │  │  │  │  ├─ 22
│  │  │  │  │  ├─ 23
│  │  │  │  │  ├─ 24
│  │  │  │  │  ├─ 25
│  │  │  │  │  ├─ 26
│  │  │  │  │  ├─ 27
│  │  │  │  │  ├─ 28
│  │  │  │  │  ├─ 29
│  │  │  │  │  ├─ 3
│  │  │  │  │  ├─ 30
│  │  │  │  │  ├─ 31
│  │  │  │  │  ├─ 32
│  │  │  │  │  ├─ 33
│  │  │  │  │  ├─ 34
│  │  │  │  │  ├─ 35
│  │  │  │  │  ├─ 36
│  │  │  │  │  ├─ 37
│  │  │  │  │  ├─ 38
│  │  │  │  │  ├─ 39
│  │  │  │  │  ├─ 4
│  │  │  │  │  ├─ 40
│  │  │  │  │  ├─ 41
│  │  │  │  │  ├─ 42
│  │  │  │  │  ├─ 43
│  │  │  │  │  ├─ 44
│  │  │  │  │  ├─ 45
│  │  │  │  │  ├─ 46
│  │  │  │  │  ├─ 47
│  │  │  │  │  ├─ 48
│  │  │  │  │  ├─ 49
│  │  │  │  │  ├─ 5
│  │  │  │  │  ├─ 50
│  │  │  │  │  ├─ 51
│  │  │  │  │  ├─ 52
│  │  │  │  │  ├─ 53
│  │  │  │  │  ├─ 54
│  │  │  │  │  ├─ 55
│  │  │  │  │  ├─ 56
│  │  │  │  │  ├─ 57
│  │  │  │  │  ├─ 58
│  │  │  │  │  ├─ 59
│  │  │  │  │  ├─ 6
│  │  │  │  │  ├─ 60
│  │  │  │  │  ├─ 61
│  │  │  │  │  ├─ 62
│  │  │  │  │  ├─ 63
│  │  │  │  │  ├─ 64
│  │  │  │  │  ├─ 65
│  │  │  │  │  ├─ 66
│  │  │  │  │  ├─ 67
│  │  │  │  │  ├─ 68
│  │  │  │  │  ├─ 69
│  │  │  │  │  ├─ 7
│  │  │  │  │  ├─ 70
│  │  │  │  │  ├─ 71
│  │  │  │  │  ├─ 72
│  │  │  │  │  ├─ 73
│  │  │  │  │  ├─ 74
│  │  │  │  │  ├─ 75
│  │  │  │  │  ├─ 76
│  │  │  │  │  ├─ 77
│  │  │  │  │  ├─ 78
│  │  │  │  │  ├─ 79
│  │  │  │  │  ├─ 8
│  │  │  │  │  ├─ 80
│  │  │  │  │  ├─ 81
│  │  │  │  │  ├─ 82
│  │  │  │  │  ├─ 83
│  │  │  │  │  ├─ 84
│  │  │  │  │  ├─ 85
│  │  │  │  │  ├─ 86
│  │  │  │  │  ├─ 87
│  │  │  │  │  ├─ 88
│  │  │  │  │  ├─ 89
│  │  │  │  │  ├─ 9
│  │  │  │  │  ├─ 90
│  │  │  │  │  ├─ 91
│  │  │  │  │  ├─ 92
│  │  │  │  │  ├─ 93
│  │  │  │  │  ├─ 94
│  │  │  │  │  ├─ 95
│  │  │  │  │  ├─ 96
│  │  │  │  │  ├─ 97
│  │  │  │  │  ├─ 98
│  │  │  │  │  ├─ 99
│  │  │  │  │  └─ count.txt
│  │  │  │  ├─ TargetDirectories.txt
│  │  │  │  ├─ cmake.check_cache
│  │  │  │  ├─ dmcv.dir
│  │  │  │  │  ├─ Camera.cpp.o
│  │  │  │  │  ├─ Camera.cpp.o.d
│  │  │  │  │  ├─ DependInfo.cmake
│  │  │  │  │  ├─ Interpreter.cpp.o
│  │  │  │  │  ├─ Interpreter.cpp.o.d
│  │  │  │  │  ├─ build.make
│  │  │  │  │  ├─ classification.cpp.o
│  │  │  │  │  ├─ classification.cpp.o.d
│  │  │  │  │  ├─ cmake_clean.cmake
│  │  │  │  │  ├─ compiler_depend.internal
│  │  │  │  │  ├─ compiler_depend.make
│  │  │  │  │  ├─ compiler_depend.ts
│  │  │  │  │  ├─ depend.make
│  │  │  │  │  ├─ flags.make
│  │  │  │  │  ├─ link.txt
│  │  │  │  │  ├─ object_detection.cpp.o
│  │  │  │  │  ├─ object_detection.cpp.o.d
│  │  │  │  │  └─ progress.make
│  │  │  │  └─ progress.marks
│  │  │  ├─ Detector
│  │  │  ├─ Makefile
│  │  │  ├─ TNN_build
│  │  │  │  ├─ CMakeFiles
│  │  │  │  │  ├─ CMakeDirectoryInformation.cmake
│  │  │  │  │  ├─ TNN.dir
│  │  │  │  │  │  ├─ DependInfo.cmake
│  │  │  │  │  │  ├─ build.make
│  │  │  │  │  │  ├─ cmake_clean.cmake
│  │  │  │  │  │  ├─ compiler_depend.internal
│  │  │  │  │  │  ├─ compiler_depend.make
│  │  │  │  │  │  ├─ compiler_depend.ts
│  │  │  │  │  │  ├─ depend.make
│  │  │  │  │  │  ├─ flags.make
│  │  │  │  │  │  ├─ link.txt
│  │  │  │  │  │  ├─ progress.make
│  │  │  │  │  │  └─ source
│  │  │  │  │  │     └─ tnn
│  │  │  │  │  │        ├─ core
│  │  │  │  │  │        │  ├─ abstract_device.cc.o
│  │  │  │  │  │        │  ├─ abstract_device.cc.o.d
│  │  │  │  │  │        │  ├─ abstract_layer_acc.cc.o
│  │  │  │  │  │        │  ├─ abstract_layer_acc.cc.o.d
│  │  │  │  │  │        │  ├─ abstract_network.cc.o
│  │  │  │  │  │        │  ├─ abstract_network.cc.o.d
│  │  │  │  │  │        │  ├─ blob.cc.o
│  │  │  │  │  │        │  ├─ blob.cc.o.d
│  │  │  │  │  │        │  ├─ blob_impl.cc.o
│  │  │  │  │  │        │  ├─ blob_impl.cc.o.d
│  │  │  │  │  │        │  ├─ blob_int8.cc.o
│  │  │  │  │  │        │  ├─ blob_int8.cc.o.d
│  │  │  │  │  │        │  ├─ blob_manager.cc.o
│  │  │  │  │  │        │  ├─ blob_manager.cc.o.d
│  │  │  │  │  │        │  ├─ const_folder.cc.o
│  │  │  │  │  │        │  ├─ const_folder.cc.o.d
│  │  │  │  │  │        │  ├─ context.cc.o
│  │  │  │  │  │        │  ├─ context.cc.o.d
│  │  │  │  │  │        │  ├─ default_network.cc.o
│  │  │  │  │  │        │  ├─ default_network.cc.o.d
│  │  │  │  │  │        │  ├─ instance.cc.o
│  │  │  │  │  │        │  ├─ instance.cc.o.d
│  │  │  │  │  │        │  ├─ layer_type.cc.o
│  │  │  │  │  │        │  ├─ layer_type.cc.o.d
│  │  │  │  │  │        │  ├─ mat.cc.o
│  │  │  │  │  │        │  ├─ mat.cc.o.d
│  │  │  │  │  │        │  ├─ profile.cc.o
│  │  │  │  │  │        │  ├─ profile.cc.o.d
│  │  │  │  │  │        │  ├─ status.cc.o
│  │  │  │  │  │        │  ├─ status.cc.o.d
│  │  │  │  │  │        │  ├─ tnn.cc.o
│  │  │  │  │  │        │  ├─ tnn.cc.o.d
│  │  │  │  │  │        │  ├─ tnn_impl.cc.o
│  │  │  │  │  │        │  ├─ tnn_impl.cc.o.d
│  │  │  │  │  │        │  ├─ tnn_impl_default.cc.o
│  │  │  │  │  │        │  └─ tnn_impl_default.cc.o.d
│  │  │  │  │  │        ├─ extern_wrapper
│  │  │  │  │  │        │  ├─ base_layer_builder.cc.o
│  │  │  │  │  │        │  ├─ base_layer_builder.cc.o.d
│  │  │  │  │  │        │  ├─ foreign_blob.cc.o
│  │  │  │  │  │        │  └─ foreign_blob.cc.o.d
│  │  │  │  │  │        ├─ interpreter
│  │  │  │  │  │        │  ├─ abstract_model_interpreter.cc.o
│  │  │  │  │  │        │  ├─ abstract_model_interpreter.cc.o.d
│  │  │  │  │  │        │  ├─ default_model_interpreter.cc.o
│  │  │  │  │  │        │  ├─ default_model_interpreter.cc.o.d
│  │  │  │  │  │        │  ├─ default_model_packer.cc.o
│  │  │  │  │  │        │  ├─ default_model_packer.cc.o.d
│  │  │  │  │  │        │  ├─ layer_resource_generator.cc.o
│  │  │  │  │  │        │  ├─ layer_resource_generator.cc.o.d
│  │  │  │  │  │        │  ├─ ncnn
│  │  │  │  │  │        │  │  ├─ layer_interpreter
│  │  │  │  │  │        │  │  │  ├─ batch_norm_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ batch_norm_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ binary_op_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ binary_op_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ clip_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ clip_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ concat_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ concat_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ conv_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ conv_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ crop_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ crop_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ deconv_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ deconv_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ default_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ default_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ detection_output_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ detection_output_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ eltwise_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ eltwise_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ elu_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ elu_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ hard_sigmoid_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ hard_sigmoid_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ hard_swish_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ hard_swish_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ inner_product_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ inner_product_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ instance_norm_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ instance_norm_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ interp_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ interp_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ lrn_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ lrn_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ memory_data_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ memory_data_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ normalize_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ normalize_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ pad_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ pad_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ permute_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ permute_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ pooling_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ pooling_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ prelu_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ prelu_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ prior_box_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ prior_box_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ reduce_op_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ reduce_op_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ relu_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ relu_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ reorg_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ reorg_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ reshape_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ reshape_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ roi_pooling_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ roi_pooling_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ scale_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ scale_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ selu_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ selu_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ shuffle_channel_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ shuffle_channel_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ slice_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ slice_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ softmax_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  ├─ softmax_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  │  ├─ unary_op_layer_interpreter.cc.o
│  │  │  │  │  │        │  │  │  └─ unary_op_layer_interpreter.cc.o.d
│  │  │  │  │  │        │  │  ├─ ncnn_layer_type.cc.o
│  │  │  │  │  │        │  │  ├─ ncnn_layer_type.cc.o.d
│  │  │  │  │  │        │  │  ├─ ncnn_model_interpreter.cc.o
│  │  │  │  │  │        │  │  ├─ ncnn_model_interpreter.cc.o.d
│  │  │  │  │  │        │  │  ├─ ncnn_param_utils.cc.o
│  │  │  │  │  │        │  │  ├─ ncnn_param_utils.cc.o.d
│  │  │  │  │  │        │  │  └─ optimizer
│  │  │  │  │  │        │  │     ├─ expand_slice_optimizer.cc.o
│  │  │  │  │  │        │  │     ├─ expand_slice_optimizer.cc.o.d
│  │  │  │  │  │        │  │     ├─ memory_data_optimizer.cc.o
│  │  │  │  │  │        │  │     ├─ memory_data_optimizer.cc.o.d
│  │  │  │  │  │        │  │     ├─ ncnn_optimizer_manager.cc.o
│  │  │  │  │  │        │  │     └─ ncnn_optimizer_manager.cc.o.d
│  │  │  │  │  │        │  ├─ net_resource.cc.o
│  │  │  │  │  │        │  ├─ net_resource.cc.o.d
│  │  │  │  │  │        │  ├─ net_structure.cc.o
│  │  │  │  │  │        │  ├─ net_structure.cc.o.d
│  │  │  │  │  │        │  ├─ raw_buffer.cc.o
│  │  │  │  │  │        │  ├─ raw_buffer.cc.o.d
│  │  │  │  │  │        │  └─ tnn
│  │  │  │  │  │        │     ├─ layer_interpreter
│  │  │  │  │  │        │     │  ├─ add_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ add_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ arg_max_or_min_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ arg_max_or_min_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ batch_norm_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ batch_norm_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ bias_add_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ bias_add_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ bitshift_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ bitshift_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ blob_scale_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ blob_scale_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ cast_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ cast_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ clip_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ clip_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ concat_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ concat_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ const_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ const_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ constantofshape_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ constantofshape_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ conv_1d_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ conv_1d_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ conv_3d_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ conv_3d_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ conv_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ conv_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ detection_output_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ detection_output_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ detection_post_process_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ detection_post_process_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ div_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ div_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ einsum_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ einsum_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ elu_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ elu_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ expand_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ expand_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ flatten_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ flatten_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ gather_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ gather_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ gathernd_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ gathernd_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ gridsample_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ gridsample_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ group_norm_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ group_norm_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ hard_sigmoid_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ hard_sigmoid_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ hard_swish_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ hard_swish_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ hdrguide_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ hdrguide_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ histogram_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ histogram_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ inner_product_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ inner_product_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ instance_norm_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ instance_norm_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ layer_norm_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ layer_norm_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ lrn_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ lrn_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ lstm_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ lstm_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ mat_mul_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ mat_mul_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ max_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ max_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ min_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ min_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ mul_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ mul_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ normalize_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ normalize_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ onehot_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ onehot_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ pad_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ pad_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ padv2_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ padv2_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ permute_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ permute_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ pixel_shuffle_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ pixel_shuffle_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ pooling_3d_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ pooling_3d_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ pooling_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ pooling_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ pow_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ pow_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ prelu_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ prelu_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ prior_box_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ prior_box_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ range_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ range_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ reduce_op_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ reduce_op_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ reformat_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ reformat_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ reorg_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ reorg_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ reshape_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ reshape_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ roi_pooling_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ roi_pooling_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ roialign_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ roialign_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ scale_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ scale_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ scatter_nd_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ scatter_nd_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ selu_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ selu_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ shape_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ shape_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ shuffle_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ shuffle_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ signed_mul_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ signed_mul_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ size_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ size_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ softmax_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ softmax_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ splitv_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ splitv_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ squared_difference_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ squared_difference_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ squeeze_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ squeeze_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ stride_slice_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ stride_slice_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ stride_slice_v2_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ stride_slice_v2_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ sub_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ sub_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ tile_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ tile_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ topk_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ topk_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ unary_op_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ unary_op_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ unsqueeze_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  ├─ unsqueeze_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     │  ├─ upsample_layer_interpreter.cc.o
│  │  │  │  │  │        │     │  └─ upsample_layer_interpreter.cc.o.d
│  │  │  │  │  │        │     ├─ model_interpreter.cc.o
│  │  │  │  │  │        │     ├─ model_interpreter.cc.o.d
│  │  │  │  │  │        │     ├─ model_packer.cc.o
│  │  │  │  │  │        │     └─ model_packer.cc.o.d
│  │  │  │  │  │        ├─ layer
│  │  │  │  │  │        │  ├─ abs_layer.cc.o
│  │  │  │  │  │        │  ├─ abs_layer.cc.o.d
│  │  │  │  │  │        │  ├─ acos_layer.cc.o
│  │  │  │  │  │        │  ├─ acos_layer.cc.o.d
│  │  │  │  │  │        │  ├─ add_layer.cc.o
│  │  │  │  │  │        │  ├─ add_layer.cc.o.d
│  │  │  │  │  │        │  ├─ arg_max_or_min_layer.cc.o
│  │  │  │  │  │        │  ├─ arg_max_or_min_layer.cc.o.d
│  │  │  │  │  │        │  ├─ asin_layer.cc.o
│  │  │  │  │  │        │  ├─ asin_layer.cc.o.d
│  │  │  │  │  │        │  ├─ atan_layer.cc.o
│  │  │  │  │  │        │  ├─ atan_layer.cc.o.d
│  │  │  │  │  │        │  ├─ base_layer.cc.o
│  │  │  │  │  │        │  ├─ base_layer.cc.o.d
│  │  │  │  │  │        │  ├─ batch_norm_layer.cc.o
│  │  │  │  │  │        │  ├─ batch_norm_layer.cc.o.d
│  │  │  │  │  │        │  ├─ bias_add_layer.cc.o
│  │  │  │  │  │        │  ├─ bias_add_layer.cc.o.d
│  │  │  │  │  │        │  ├─ bitshift_layer.cc.o
│  │  │  │  │  │        │  ├─ bitshift_layer.cc.o.d
│  │  │  │  │  │        │  ├─ cast_layer.cc.o
│  │  │  │  │  │        │  ├─ cast_layer.cc.o.d
│  │  │  │  │  │        │  ├─ cbam_fused_pooling_layer.cc.o
│  │  │  │  │  │        │  ├─ cbam_fused_pooling_layer.cc.o.d
│  │  │  │  │  │        │  ├─ cbam_fused_reduce_layer.cc.o
│  │  │  │  │  │        │  ├─ cbam_fused_reduce_layer.cc.o.d
│  │  │  │  │  │        │  ├─ ceil_layer.cc.o
│  │  │  │  │  │        │  ├─ ceil_layer.cc.o.d
│  │  │  │  │  │        │  ├─ clip_layer.cc.o
│  │  │  │  │  │        │  ├─ clip_layer.cc.o.d
│  │  │  │  │  │        │  ├─ concat_layer.cc.o
│  │  │  │  │  │        │  ├─ concat_layer.cc.o.d
│  │  │  │  │  │        │  ├─ constantofshape_layer.cc.o
│  │  │  │  │  │        │  ├─ constantofshape_layer.cc.o.d
│  │  │  │  │  │        │  ├─ conv1d_layer.cc.o
│  │  │  │  │  │        │  ├─ conv1d_layer.cc.o.d
│  │  │  │  │  │        │  ├─ conv3d_layer.cc.o
│  │  │  │  │  │        │  ├─ conv3d_layer.cc.o.d
│  │  │  │  │  │        │  ├─ conv_layer.cc.o
│  │  │  │  │  │        │  ├─ conv_layer.cc.o.d
│  │  │  │  │  │        │  ├─ cos_layer.cc.o
│  │  │  │  │  │        │  ├─ cos_layer.cc.o.d
│  │  │  │  │  │        │  ├─ deconv_layer.cc.o
│  │  │  │  │  │        │  ├─ deconv_layer.cc.o.d
│  │  │  │  │  │        │  ├─ detection_output_layer.cc.o
│  │  │  │  │  │        │  ├─ detection_output_layer.cc.o.d
│  │  │  │  │  │        │  ├─ detection_post_process_layer.cc.o
│  │  │  │  │  │        │  ├─ detection_post_process_layer.cc.o.d
│  │  │  │  │  │        │  ├─ div_layer.cc.o
│  │  │  │  │  │        │  ├─ div_layer.cc.o.d
│  │  │  │  │  │        │  ├─ einsum_layer.cc.o
│  │  │  │  │  │        │  ├─ einsum_layer.cc.o.d
│  │  │  │  │  │        │  ├─ elementwise_layer.cc.o
│  │  │  │  │  │        │  ├─ elementwise_layer.cc.o.d
│  │  │  │  │  │        │  ├─ elu_layer.cc.o
│  │  │  │  │  │        │  ├─ elu_layer.cc.o.d
│  │  │  │  │  │        │  ├─ equal_layer.cc.o
│  │  │  │  │  │        │  ├─ equal_layer.cc.o.d
│  │  │  │  │  │        │  ├─ erf_layer.cc.o
│  │  │  │  │  │        │  ├─ erf_layer.cc.o.d
│  │  │  │  │  │        │  ├─ exp_layer.cc.o
│  │  │  │  │  │        │  ├─ exp_layer.cc.o.d
│  │  │  │  │  │        │  ├─ expand_layer.cc.o
│  │  │  │  │  │        │  ├─ expand_layer.cc.o.d
│  │  │  │  │  │        │  ├─ flatten_layer.cc.o
│  │  │  │  │  │        │  ├─ flatten_layer.cc.o.d
│  │  │  │  │  │        │  ├─ floor_layer.cc.o
│  │  │  │  │  │        │  ├─ floor_layer.cc.o.d
│  │  │  │  │  │        │  ├─ gather_layer.cc.o
│  │  │  │  │  │        │  ├─ gather_layer.cc.o.d
│  │  │  │  │  │        │  ├─ gathernd_layer.cc.o
│  │  │  │  │  │        │  ├─ gathernd_layer.cc.o.d
│  │  │  │  │  │        │  ├─ gelu_layer.cc.o
│  │  │  │  │  │        │  ├─ gelu_layer.cc.o.d
│  │  │  │  │  │        │  ├─ gridsample_layer.cc.o
│  │  │  │  │  │        │  ├─ gridsample_layer.cc.o.d
│  │  │  │  │  │        │  ├─ group_norm_layer.cc.o
│  │  │  │  │  │        │  ├─ group_norm_layer.cc.o.d
│  │  │  │  │  │        │  ├─ hard_sigmoid_layer.cc.o
│  │  │  │  │  │        │  ├─ hard_sigmoid_layer.cc.o.d
│  │  │  │  │  │        │  ├─ hard_swish_layer.cc.o
│  │  │  │  │  │        │  ├─ hard_swish_layer.cc.o.d
│  │  │  │  │  │        │  ├─ hdrguide_layer.cc.o
│  │  │  │  │  │        │  ├─ hdrguide_layer.cc.o.d
│  │  │  │  │  │        │  ├─ histogram_layer.cc.o
│  │  │  │  │  │        │  ├─ histogram_layer.cc.o.d
│  │  │  │  │  │        │  ├─ inner_product_layer.cc.o
│  │  │  │  │  │        │  ├─ inner_product_layer.cc.o.d
│  │  │  │  │  │        │  ├─ instance_norm_layer.cc.o
│  │  │  │  │  │        │  ├─ instance_norm_layer.cc.o.d
│  │  │  │  │  │        │  ├─ inverse_layer.cc.o
│  │  │  │  │  │        │  ├─ inverse_layer.cc.o.d
│  │  │  │  │  │        │  ├─ layer_norm_layer.cc.o
│  │  │  │  │  │        │  ├─ layer_norm_layer.cc.o.d
│  │  │  │  │  │        │  ├─ log_layer.cc.o
│  │  │  │  │  │        │  ├─ log_layer.cc.o.d
│  │  │  │  │  │        │  ├─ log_sigmoid_layer.cc.o
│  │  │  │  │  │        │  ├─ log_sigmoid_layer.cc.o.d
│  │  │  │  │  │        │  ├─ lrn_layer.cc.o
│  │  │  │  │  │        │  ├─ lrn_layer.cc.o.d
│  │  │  │  │  │        │  ├─ lstm_layer.cc.o
│  │  │  │  │  │        │  ├─ lstm_layer.cc.o.d
│  │  │  │  │  │        │  ├─ mat_mul_layer.cc.o
│  │  │  │  │  │        │  ├─ mat_mul_layer.cc.o.d
│  │  │  │  │  │        │  ├─ max_layer.cc.o
│  │  │  │  │  │        │  ├─ max_layer.cc.o.d
│  │  │  │  │  │        │  ├─ min_layer.cc.o
│  │  │  │  │  │        │  ├─ min_layer.cc.o.d
│  │  │  │  │  │        │  ├─ mul_layer.cc.o
│  │  │  │  │  │        │  ├─ mul_layer.cc.o.d
│  │  │  │  │  │        │  ├─ multidir_broadcast_layer.cc.o
│  │  │  │  │  │        │  ├─ multidir_broadcast_layer.cc.o.d
│  │  │  │  │  │        │  ├─ neg_layer.cc.o
│  │  │  │  │  │        │  ├─ neg_layer.cc.o.d
│  │  │  │  │  │        │  ├─ nonzero_layer.cc.o
│  │  │  │  │  │        │  ├─ nonzero_layer.cc.o.d
│  │  │  │  │  │        │  ├─ normalize_layer.cc.o
│  │  │  │  │  │        │  ├─ normalize_layer.cc.o.d
│  │  │  │  │  │        │  ├─ onehot_layer.cc.o
│  │  │  │  │  │        │  ├─ onehot_layer.cc.o.d
│  │  │  │  │  │        │  ├─ pad_layer.cc.o
│  │  │  │  │  │        │  ├─ pad_layer.cc.o.d
│  │  │  │  │  │        │  ├─ padv2_layer.cc.o
│  │  │  │  │  │        │  ├─ padv2_layer.cc.o.d
│  │  │  │  │  │        │  ├─ permute_layer.cc.o
│  │  │  │  │  │        │  ├─ permute_layer.cc.o.d
│  │  │  │  │  │        │  ├─ pixel_shuffle_layer.cc.o
│  │  │  │  │  │        │  ├─ pixel_shuffle_layer.cc.o.d
│  │  │  │  │  │        │  ├─ pooling_3d_layer.cc.o
│  │  │  │  │  │        │  ├─ pooling_3d_layer.cc.o.d
│  │  │  │  │  │        │  ├─ pooling_layer.cc.o
│  │  │  │  │  │        │  ├─ pooling_layer.cc.o.d
│  │  │  │  │  │        │  ├─ pow_layer.cc.o
│  │  │  │  │  │        │  ├─ pow_layer.cc.o.d
│  │  │  │  │  │        │  ├─ prelu_layer.cc.o
│  │  │  │  │  │        │  ├─ prelu_layer.cc.o.d
│  │  │  │  │  │        │  ├─ prior_box_layer.cc.o
│  │  │  │  │  │        │  ├─ prior_box_layer.cc.o.d
│  │  │  │  │  │        │  ├─ range_layer.cc.o
│  │  │  │  │  │        │  ├─ range_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reciprocal_layer.cc.o
│  │  │  │  │  │        │  ├─ reciprocal_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_l1_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_l1_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_l2_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_l2_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_log_sum_exp_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_log_sum_exp_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_log_sum_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_log_sum_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_max_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_max_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_mean_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_mean_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_min_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_min_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_prod_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_prod_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_sum_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_sum_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reduce_sum_square_layer.cc.o
│  │  │  │  │  │        │  ├─ reduce_sum_square_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reformat_layer.cc.o
│  │  │  │  │  │        │  ├─ reformat_layer.cc.o.d
│  │  │  │  │  │        │  ├─ relu6_layer.cc.o
│  │  │  │  │  │        │  ├─ relu6_layer.cc.o.d
│  │  │  │  │  │        │  ├─ relu_layer.cc.o
│  │  │  │  │  │        │  ├─ relu_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reorg_layer.cc.o
│  │  │  │  │  │        │  ├─ reorg_layer.cc.o.d
│  │  │  │  │  │        │  ├─ reshape_layer.cc.o
│  │  │  │  │  │        │  ├─ reshape_layer.cc.o.d
│  │  │  │  │  │        │  ├─ roi_pooling_layer.cc.o
│  │  │  │  │  │        │  ├─ roi_pooling_layer.cc.o.d
│  │  │  │  │  │        │  ├─ roialign_layer.cc.o
│  │  │  │  │  │        │  ├─ roialign_layer.cc.o.d
│  │  │  │  │  │        │  ├─ rsqrt_layer.cc.o
│  │  │  │  │  │        │  ├─ rsqrt_layer.cc.o.d
│  │  │  │  │  │        │  ├─ scale_layer.cc.o
│  │  │  │  │  │        │  ├─ scale_layer.cc.o.d
│  │  │  │  │  │        │  ├─ scatter_nd_layer.cc.o
│  │  │  │  │  │        │  ├─ scatter_nd_layer.cc.o.d
│  │  │  │  │  │        │  ├─ selu_layer.cc.o
│  │  │  │  │  │        │  ├─ selu_layer.cc.o.d
│  │  │  │  │  │        │  ├─ shape_layer.cc.o
│  │  │  │  │  │        │  ├─ shape_layer.cc.o.d
│  │  │  │  │  │        │  ├─ shuffle_layer.cc.o
│  │  │  │  │  │        │  ├─ shuffle_layer.cc.o.d
│  │  │  │  │  │        │  ├─ sigmoid_layer.cc.o
│  │  │  │  │  │        │  ├─ sigmoid_layer.cc.o.d
│  │  │  │  │  │        │  ├─ sign_layer.cc.o
│  │  │  │  │  │        │  ├─ sign_layer.cc.o.d
│  │  │  │  │  │        │  ├─ signed_mul_layer.cc.o
│  │  │  │  │  │        │  ├─ signed_mul_layer.cc.o.d
│  │  │  │  │  │        │  ├─ sin_layer.cc.o
│  │  │  │  │  │        │  ├─ sin_layer.cc.o.d
│  │  │  │  │  │        │  ├─ size_layer.cc.o
│  │  │  │  │  │        │  ├─ size_layer.cc.o.d
│  │  │  │  │  │        │  ├─ softmax_layer.cc.o
│  │  │  │  │  │        │  ├─ softmax_layer.cc.o.d
│  │  │  │  │  │        │  ├─ softplus_layer.cc.o
│  │  │  │  │  │        │  ├─ softplus_layer.cc.o.d
│  │  │  │  │  │        │  ├─ softsign_layer.cc.o
│  │  │  │  │  │        │  ├─ softsign_layer.cc.o.d
│  │  │  │  │  │        │  ├─ split_layer.cc.o
│  │  │  │  │  │        │  ├─ split_layer.cc.o.d
│  │  │  │  │  │        │  ├─ splitv_layer.cc.o
│  │  │  │  │  │        │  ├─ splitv_layer.cc.o.d
│  │  │  │  │  │        │  ├─ sqrt_layer.cc.o
│  │  │  │  │  │        │  ├─ sqrt_layer.cc.o.d
│  │  │  │  │  │        │  ├─ squared_difference_layer.cc.o
│  │  │  │  │  │        │  ├─ squared_difference_layer.cc.o.d
│  │  │  │  │  │        │  ├─ squeeze_layer.cc.o
│  │  │  │  │  │        │  ├─ squeeze_layer.cc.o.d
│  │  │  │  │  │        │  ├─ stride_slice_layer.cc.o
│  │  │  │  │  │        │  ├─ stride_slice_layer.cc.o.d
│  │  │  │  │  │        │  ├─ stride_slice_v2_layer.cc.o
│  │  │  │  │  │        │  ├─ stride_slice_v2_layer.cc.o.d
│  │  │  │  │  │        │  ├─ sub_layer.cc.o
│  │  │  │  │  │        │  ├─ sub_layer.cc.o.d
│  │  │  │  │  │        │  ├─ tan_layer.cc.o
│  │  │  │  │  │        │  ├─ tan_layer.cc.o.d
│  │  │  │  │  │        │  ├─ tanh_layer.cc.o
│  │  │  │  │  │        │  ├─ tanh_layer.cc.o.d
│  │  │  │  │  │        │  ├─ tile_layer.cc.o
│  │  │  │  │  │        │  ├─ tile_layer.cc.o.d
│  │  │  │  │  │        │  ├─ topk_layer.cc.o
│  │  │  │  │  │        │  ├─ topk_layer.cc.o.d
│  │  │  │  │  │        │  ├─ unsqueeze_layer.cc.o
│  │  │  │  │  │        │  ├─ unsqueeze_layer.cc.o.d
│  │  │  │  │  │        │  ├─ upsample_layer.cc.o
│  │  │  │  │  │        │  ├─ upsample_layer.cc.o.d
│  │  │  │  │  │        │  ├─ where_layer.cc.o
│  │  │  │  │  │        │  └─ where_layer.cc.o.d
│  │  │  │  │  │        ├─ memory_manager
│  │  │  │  │  │        │  ├─ blob_1d_memory.cc.o
│  │  │  │  │  │        │  ├─ blob_1d_memory.cc.o.d
│  │  │  │  │  │        │  ├─ blob_1d_memory_pool.cc.o
│  │  │  │  │  │        │  ├─ blob_1d_memory_pool.cc.o.d
│  │  │  │  │  │        │  ├─ blob_2d_memory.cc.o
│  │  │  │  │  │        │  ├─ blob_2d_memory.cc.o.d
│  │  │  │  │  │        │  ├─ blob_2d_memory_pool.cc.o
│  │  │  │  │  │        │  ├─ blob_2d_memory_pool.cc.o.d
│  │  │  │  │  │        │  ├─ blob_memory.cc.o
│  │  │  │  │  │        │  ├─ blob_memory.cc.o.d
│  │  │  │  │  │        │  ├─ blob_memory_pool.cc.o
│  │  │  │  │  │        │  ├─ blob_memory_pool.cc.o.d
│  │  │  │  │  │        │  ├─ blob_memory_pool_factory.cc.o
│  │  │  │  │  │        │  ├─ blob_memory_pool_factory.cc.o.d
│  │  │  │  │  │        │  ├─ blob_memory_size_info.cc.o
│  │  │  │  │  │        │  ├─ blob_memory_size_info.cc.o.d
│  │  │  │  │  │        │  ├─ memory_mode_state.cc.o
│  │  │  │  │  │        │  ├─ memory_mode_state.cc.o.d
│  │  │  │  │  │        │  ├─ memory_mode_state_factory.cc.o
│  │  │  │  │  │        │  ├─ memory_mode_state_factory.cc.o.d
│  │  │  │  │  │        │  ├─ memory_seperate_assign_strategy.cc.o
│  │  │  │  │  │        │  ├─ memory_seperate_assign_strategy.cc.o.d
│  │  │  │  │  │        │  ├─ memory_unify_assign_strategy.cc.o
│  │  │  │  │  │        │  ├─ memory_unify_assign_strategy.cc.o.d
│  │  │  │  │  │        │  ├─ others_memory_mode_state.cc.o
│  │  │  │  │  │        │  ├─ others_memory_mode_state.cc.o.d
│  │  │  │  │  │        │  ├─ share_one_thread_memory_mode_state.cc.o
│  │  │  │  │  │        │  ├─ share_one_thread_memory_mode_state.cc.o.d
│  │  │  │  │  │        │  ├─ shared_memory_manager.cc.o
│  │  │  │  │  │        │  └─ shared_memory_manager.cc.o.d
│  │  │  │  │  │        ├─ optimizer
│  │  │  │  │  │        │  ├─ net_optimizer_cbam_fused_pooling.cc.o
│  │  │  │  │  │        │  ├─ net_optimizer_cbam_fused_pooling.cc.o.d
│  │  │  │  │  │        │  ├─ net_optimizer_cbam_fused_reduce.cc.o
│  │  │  │  │  │        │  ├─ net_optimizer_cbam_fused_reduce.cc.o.d
│  │  │  │  │  │        │  ├─ net_optimizer_fuse_conv_add.cc.o
│  │  │  │  │  │        │  ├─ net_optimizer_fuse_conv_add.cc.o.d
│  │  │  │  │  │        │  ├─ net_optimizer_fuse_conv_post.cc.o
│  │  │  │  │  │        │  ├─ net_optimizer_fuse_conv_post.cc.o.d
│  │  │  │  │  │        │  ├─ net_optimizer_insert_fp16_reformat.cc.o
│  │  │  │  │  │        │  ├─ net_optimizer_insert_fp16_reformat.cc.o.d
│  │  │  │  │  │        │  ├─ net_optimizer_insert_int8_reformat.cc.o
│  │  │  │  │  │        │  ├─ net_optimizer_insert_int8_reformat.cc.o.d
│  │  │  │  │  │        │  ├─ net_optimizer_insert_layout_reformat.cc.o
│  │  │  │  │  │        │  ├─ net_optimizer_insert_layout_reformat.cc.o.d
│  │  │  │  │  │        │  ├─ net_optimizer_manager.cc.o
│  │  │  │  │  │        │  ├─ net_optimizer_manager.cc.o.d
│  │  │  │  │  │        │  ├─ net_optimizer_remove_layers.cc.o
│  │  │  │  │  │        │  └─ net_optimizer_remove_layers.cc.o.d
│  │  │  │  │  │        └─ utils
│  │  │  │  │  │           ├─ bbox_util.cc.o
│  │  │  │  │  │           ├─ bbox_util.cc.o.d
│  │  │  │  │  │           ├─ bfp16_utils.cc.o
│  │  │  │  │  │           ├─ bfp16_utils.cc.o.d
│  │  │  │  │  │           ├─ blob_converter_default.cc.o
│  │  │  │  │  │           ├─ blob_converter_default.cc.o.d
│  │  │  │  │  │           ├─ blob_converter_internal.cc.o
│  │  │  │  │  │           ├─ blob_converter_internal.cc.o.d
│  │  │  │  │  │           ├─ blob_dump_utils.cc.o
│  │  │  │  │  │           ├─ blob_dump_utils.cc.o.d
│  │  │  │  │  │           ├─ blob_memory_size_utils.cc.o
│  │  │  │  │  │           ├─ blob_memory_size_utils.cc.o.d
│  │  │  │  │  │           ├─ blob_transfer_utils.cc.o
│  │  │  │  │  │           ├─ blob_transfer_utils.cc.o.d
│  │  │  │  │  │           ├─ cpu_info.cc.o
│  │  │  │  │  │           ├─ cpu_info.cc.o.d
│  │  │  │  │  │           ├─ cpu_utils.cc.o
│  │  │  │  │  │           ├─ cpu_utils.cc.o.d
│  │  │  │  │  │           ├─ data_flag_utils.cc.o
│  │  │  │  │  │           ├─ data_flag_utils.cc.o.d
│  │  │  │  │  │           ├─ data_format_converter.cc.o
│  │  │  │  │  │           ├─ data_format_converter.cc.o.d
│  │  │  │  │  │           ├─ data_type_utils.cc.o
│  │  │  │  │  │           ├─ data_type_utils.cc.o.d
│  │  │  │  │  │           ├─ detection_post_process_utils.cc.o
│  │  │  │  │  │           ├─ detection_post_process_utils.cc.o.d
│  │  │  │  │  │           ├─ dims_function_utils.cc.o
│  │  │  │  │  │           ├─ dims_function_utils.cc.o.d
│  │  │  │  │  │           ├─ dims_offset_utils.cc.o
│  │  │  │  │  │           ├─ dims_offset_utils.cc.o.d
│  │  │  │  │  │           ├─ dims_vector_utils.cc.o
│  │  │  │  │  │           ├─ dims_vector_utils.cc.o.d
│  │  │  │  │  │           ├─ half_utils.cc.o
│  │  │  │  │  │           ├─ half_utils.cc.o.d
│  │  │  │  │  │           ├─ mat_converter_acc.cc.o
│  │  │  │  │  │           ├─ mat_converter_acc.cc.o.d
│  │  │  │  │  │           ├─ mat_converter_utils.cc.o
│  │  │  │  │  │           ├─ mat_converter_utils.cc.o.d
│  │  │  │  │  │           ├─ mat_utils.cc.o
│  │  │  │  │  │           ├─ mat_utils.cc.o.d
│  │  │  │  │  │           ├─ md5.cc.o
│  │  │  │  │  │           ├─ md5.cc.o.d
│  │  │  │  │  │           ├─ naive_compute.cc.o
│  │  │  │  │  │           ├─ naive_compute.cc.o.d
│  │  │  │  │  │           ├─ npu_common_utils.cc.o
│  │  │  │  │  │           ├─ npu_common_utils.cc.o.d
│  │  │  │  │  │           ├─ pad_utils.cc.o
│  │  │  │  │  │           ├─ pad_utils.cc.o.d
│  │  │  │  │  │           ├─ pribox_generator_utils.cc.o
│  │  │  │  │  │           ├─ pribox_generator_utils.cc.o.d
│  │  │  │  │  │           ├─ random_data_utils.cc.o
│  │  │  │  │  │           ├─ random_data_utils.cc.o.d
│  │  │  │  │  │           ├─ split_utils.cc.o
│  │  │  │  │  │           ├─ split_utils.cc.o.d
│  │  │  │  │  │           ├─ string_format.cc.o
│  │  │  │  │  │           ├─ string_format.cc.o.d
│  │  │  │  │  │           ├─ string_utils.cc.o
│  │  │  │  │  │           ├─ string_utils.cc.o.d
│  │  │  │  │  │           ├─ winograd_generator.cc.o
│  │  │  │  │  │           └─ winograd_generator.cc.o.d
│  │  │  │  │  └─ progress.marks
│  │  │  │  ├─ Makefile
│  │  │  │  ├─ cmake_install.cmake
│  │  │  │  ├─ libTNN.so
│  │  │  │  ├─ libTNN.so.0
│  │  │  │  ├─ libTNN.so.0.1.0.0
│  │  │  │  └─ source
│  │  │  │     └─ tnn
│  │  │  │        └─ device
│  │  │  │           ├─ cpu
│  │  │  │           │  ├─ CMakeFiles
│  │  │  │           │  │  ├─ CMakeDirectoryInformation.cmake
│  │  │  │           │  │  ├─ TNNCpu.dir
│  │  │  │           │  │  │  ├─ DependInfo.cmake
│  │  │  │           │  │  │  ├─ acc
│  │  │  │           │  │  │  │  ├─ compute
│  │  │  │           │  │  │  │  │  ├─ compute_elewise.cc.o
│  │  │  │           │  │  │  │  │  ├─ compute_elewise.cc.o.d
│  │  │  │           │  │  │  │  │  ├─ compute_int8.cc.o
│  │  │  │           │  │  │  │  │  └─ compute_int8.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu__histogram_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu__histogram_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_abs_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_abs_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_acos_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_acos_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_add_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_add_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_arg_max_or_min_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_arg_max_or_min_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_asin_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_asin_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_atan_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_atan_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_batch_norm_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_batch_norm_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_bias_add_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_bias_add_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_binary_op_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_binary_op_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_bitshift_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_bitshift_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_cast_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_cast_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_ceil_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_ceil_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_clip_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_clip_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_concat_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_concat_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_const_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_const_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_constantofshape_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_constantofshape_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_conv_1d_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_conv_1d_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_conv_3d_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_conv_3d_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_conv_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_conv_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_cos_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_cos_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_deconv_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_deconv_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_detection_output_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_detection_output_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_detection_post_process_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_detection_post_process_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_div_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_div_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_einsum_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_einsum_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_elu_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_elu_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_equal_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_equal_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_erf_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_erf_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_exp_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_exp_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_expand_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_expand_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_flatten_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_flatten_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_floor_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_floor_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_gather_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_gather_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_gathernd_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_gathernd_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_gelu_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_gelu_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_gridsample_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_gridsample_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_group_norm_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_group_norm_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_hard_sigmoid_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_hard_sigmoid_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_hard_swish_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_hard_swish_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_hdrguide_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_hdrguide_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_inner_product_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_inner_product_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_instance_norm_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_instance_norm_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_inverse_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_inverse_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_layer_norm_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_layer_norm_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_log_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_log_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_log_sigmoid_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_log_sigmoid_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_lrn_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_lrn_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_lstm_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_lstm_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_mat_mul_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_mat_mul_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_max_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_max_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_min_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_min_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_mul_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_mul_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_neg_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_neg_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_nonzero_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_nonzero_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_normalize_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_normalize_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_onehot_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_onehot_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_pad_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_pad_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_padv2_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_padv2_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_permute_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_permute_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_pixel_shuffle_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_pixel_shuffle_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_pool_3d_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_pool_3d_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_pool_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_pool_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_pow_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_pow_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_prelu_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_prelu_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_prior_box_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_prior_box_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_range_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_range_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reciprocal_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reciprocal_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_l1_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_l1_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_l2_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_l2_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_log_sum_exp_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_log_sum_exp_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_log_sum_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_log_sum_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_max_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_max_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_mean_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_mean_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_min_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_min_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_prod_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_prod_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_sum_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_sum_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reduce_sum_square_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reduce_sum_square_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reformat_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reformat_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_relu6_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_relu6_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_relu_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_relu_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reorg_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reorg_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_reshape_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_reshape_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_roialign_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_roialign_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_rsqrt_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_rsqrt_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_scale_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_scale_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_scatter_nd_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_scatter_nd_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_selu_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_selu_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_shape_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_shape_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_shuffle_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_shuffle_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_sigmoid_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_sigmoid_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_sign_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_sign_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_signed_mul_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_signed_mul_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_sin_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_sin_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_size_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_size_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_softmax_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_softmax_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_softplus_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_softplus_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_splitv_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_splitv_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_sqrt_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_sqrt_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_squared_difference_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_squared_difference_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_squeeze_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_squeeze_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_stride_slice_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_stride_slice_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_stride_slice_v2_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_stride_slice_v2_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_sub_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_sub_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_tan_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_tan_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_tanh_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_tanh_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_tile_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_tile_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_topk_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_topk_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_unary_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_unary_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_unsqueeze_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_unsqueeze_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_upsample_layer_acc.cc.o
│  │  │  │           │  │  │  │  ├─ cpu_upsample_layer_acc.cc.o.d
│  │  │  │           │  │  │  │  ├─ cpu_where_layer_acc.cc.o
│  │  │  │           │  │  │  │  └─ cpu_where_layer_acc.cc.o.d
│  │  │  │           │  │  │  ├─ build.make
│  │  │  │           │  │  │  ├─ cmake_clean.cmake
│  │  │  │           │  │  │  ├─ compiler_depend.internal
│  │  │  │           │  │  │  ├─ compiler_depend.make
│  │  │  │           │  │  │  ├─ compiler_depend.ts
│  │  │  │           │  │  │  ├─ cpu_blob_converter.cc.o
│  │  │  │           │  │  │  ├─ cpu_blob_converter.cc.o.d
│  │  │  │           │  │  │  ├─ cpu_context.cc.o
│  │  │  │           │  │  │  ├─ cpu_context.cc.o.d
│  │  │  │           │  │  │  ├─ cpu_device.cc.o
│  │  │  │           │  │  │  ├─ cpu_device.cc.o.d
│  │  │  │           │  │  │  ├─ cpu_mat_converter.cc.o
│  │  │  │           │  │  │  ├─ cpu_mat_converter.cc.o.d
│  │  │  │           │  │  │  ├─ cpu_mat_util.cc.o
│  │  │  │           │  │  │  ├─ cpu_mat_util.cc.o.d
│  │  │  │           │  │  │  ├─ depend.make
│  │  │  │           │  │  │  ├─ flags.make
│  │  │  │           │  │  │  └─ progress.make
│  │  │  │           │  │  └─ progress.marks
│  │  │  │           │  ├─ Makefile
│  │  │  │           │  └─ cmake_install.cmake
│  │  │  │           └─ opencl
│  │  │  │              ├─ CMakeFiles
│  │  │  │              │  ├─ CMakeDirectoryInformation.cmake
│  │  │  │              │  ├─ TNNOpenCL.dir
│  │  │  │              │  │  ├─ DependInfo.cmake
│  │  │  │              │  │  ├─ acc
│  │  │  │              │  │  │  ├─ convolution
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_1x1_acc.cc.o
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_1x1_acc.cc.o.d
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_acc.cc.o
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_acc.cc.o.d
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_acc_impl.cc.o
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_acc_impl.cc.o.d
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_common_acc.cc.o
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_common_acc.cc.o.d
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_depthwise_acc.cc.o
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_depthwise_acc.cc.o.d
│  │  │  │              │  │  │  │  ├─ opencl_conv_layer_winograd_acc.cc.o
│  │  │  │              │  │  │  │  └─ opencl_conv_layer_winograd_acc.cc.o.d
│  │  │  │              │  │  │  ├─ deconvolution
│  │  │  │              │  │  │  │  ├─ opencl_deconv_layer_acc.cc.o
│  │  │  │              │  │  │  │  ├─ opencl_deconv_layer_acc.cc.o.d
│  │  │  │              │  │  │  │  ├─ opencl_deconv_layer_acc_impl.cc.o
│  │  │  │              │  │  │  │  ├─ opencl_deconv_layer_acc_impl.cc.o.d
│  │  │  │              │  │  │  │  ├─ opencl_deconv_layer_common_acc.cc.o
│  │  │  │              │  │  │  │  ├─ opencl_deconv_layer_common_acc.cc.o.d
│  │  │  │              │  │  │  │  ├─ opencl_deconv_layer_depthwise_acc.cc.o
│  │  │  │              │  │  │  │  └─ opencl_deconv_layer_depthwise_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_abs_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_abs_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_acos_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_acos_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_add_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_add_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_arg_max_or_min_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_arg_max_or_min_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_asin_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_asin_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_atan_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_atan_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_batch_norm_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_batch_norm_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_binary_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_binary_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_cast_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_cast_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_ceil_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_ceil_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_clip_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_clip_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_concat_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_concat_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_cos_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_cos_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_cpu_adapter_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_cpu_adapter_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_div_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_div_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_elu_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_elu_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_exp_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_exp_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_expand_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_expand_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_floor_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_floor_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_gather_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_gather_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_gridsample_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_gridsample_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_hard_sigmoid_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_hard_sigmoid_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_hard_swish_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_hard_swish_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_hdr_guide_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_hdr_guide_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_inner_product_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_inner_product_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_instance_norm_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_instance_norm_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_inverse_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_inverse_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_log_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_log_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_logsigmoid_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_logsigmoid_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_lstm_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_lstm_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_mat_mul_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_mat_mul_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_max_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_max_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_min_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_min_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_mul_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_mul_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_neg_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_neg_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_normalize_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_normalize_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_pad_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_pad_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_padv2_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_padv2_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_permute_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_permute_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_pixel_shuffle_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_pixel_shuffle_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_pooling_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_pooling_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_pow_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_pow_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_prelu_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_prelu_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_prior_box_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_prior_box_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reciprocal_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reciprocal_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_l1_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_l1_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_l2_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_l2_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_log_sum_exp_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_log_sum_exp_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_log_sum_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_log_sum_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_max_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_max_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_mean_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_mean_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_min_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_min_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_prod_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_prod_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_sum_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_sum_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reduce_sum_square_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reduce_sum_square_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reformat_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reformat_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_relu6_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_relu6_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_relu_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_relu_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reorg_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reorg_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_reshape_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_reshape_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_selu_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_selu_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_shuffle_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_shuffle_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_sigmoid_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_sigmoid_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_sign_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_sign_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_signed_mul_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_signed_mul_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_sin_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_sin_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_softmax_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_softmax_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_softplus_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_softplus_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_split_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_split_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_splitv_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_splitv_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_sqrt_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_sqrt_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_squeeze_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_squeeze_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_stride_slice_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_stride_slice_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_stride_slice_v2_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_stride_slice_v2_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_sub_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_sub_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_tan_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_tan_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_tanh_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_tanh_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_tile_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_tile_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_unary_layer_acc.cc.o
│  │  │  │              │  │  │  ├─ opencl_unary_layer_acc.cc.o.d
│  │  │  │              │  │  │  ├─ opencl_upsample_layer_acc.cc.o
│  │  │  │              │  │  │  └─ opencl_upsample_layer_acc.cc.o.d
│  │  │  │              │  │  ├─ build.make
│  │  │  │              │  │  ├─ cl
│  │  │  │              │  │  │  ├─ opencl_program.cc.o
│  │  │  │              │  │  │  └─ opencl_program.cc.o.d
│  │  │  │              │  │  ├─ cmake_clean.cmake
│  │  │  │              │  │  ├─ compiler_depend.internal
│  │  │  │              │  │  ├─ compiler_depend.make
│  │  │  │              │  │  ├─ compiler_depend.ts
│  │  │  │              │  │  ├─ depend.make
│  │  │  │              │  │  ├─ flags.make
│  │  │  │              │  │  ├─ imagebuffer_convertor.cc.o
│  │  │  │              │  │  ├─ imagebuffer_convertor.cc.o.d
│  │  │  │              │  │  ├─ opencl_blob_converter.cc.o
│  │  │  │              │  │  ├─ opencl_blob_converter.cc.o.d
│  │  │  │              │  │  ├─ opencl_context.cc.o
│  │  │  │              │  │  ├─ opencl_context.cc.o.d
│  │  │  │              │  │  ├─ opencl_device.cc.o
│  │  │  │              │  │  ├─ opencl_device.cc.o.d
│  │  │  │              │  │  ├─ opencl_mat_converter.cc.o
│  │  │  │              │  │  ├─ opencl_mat_converter.cc.o.d
│  │  │  │              │  │  ├─ opencl_memory.cc.o
│  │  │  │              │  │  ├─ opencl_memory.cc.o.d
│  │  │  │              │  │  ├─ opencl_runtime.cc.o
│  │  │  │              │  │  ├─ opencl_runtime.cc.o.d
│  │  │  │              │  │  ├─ opencl_utils.cc.o
│  │  │  │              │  │  ├─ opencl_utils.cc.o.d
│  │  │  │              │  │  ├─ opencl_wrapper.cc.o
│  │  │  │              │  │  ├─ opencl_wrapper.cc.o.d
│  │  │  │              │  │  └─ progress.make
│  │  │  │              │  └─ progress.marks
│  │  │  │              ├─ Makefile
│  │  │  │              └─ cmake_install.cmake
│  │  │  ├─ base_build
│  │  │  │  ├─ CMakeFiles
│  │  │  │  │  ├─ CMakeDirectoryInformation.cmake
│  │  │  │  │  ├─ base_utils.dir
│  │  │  │  │  │  ├─ DependInfo.cmake
│  │  │  │  │  │  ├─ build.make
│  │  │  │  │  │  ├─ cmake_clean.cmake
│  │  │  │  │  │  ├─ cmake_clean_target.cmake
│  │  │  │  │  │  ├─ compiler_depend.internal
│  │  │  │  │  │  ├─ compiler_depend.make
│  │  │  │  │  │  ├─ compiler_depend.ts
│  │  │  │  │  │  ├─ depend.make
│  │  │  │  │  │  ├─ flags.make
│  │  │  │  │  │  ├─ link.txt
│  │  │  │  │  │  ├─ progress.make
│  │  │  │  │  │  └─ src
│  │  │  │  │  │     ├─ debug.cpp.o
│  │  │  │  │  │     ├─ debug.cpp.o.d
│  │  │  │  │  │     ├─ file_utils.cpp.o
│  │  │  │  │  │     ├─ file_utils.cpp.o.d
│  │  │  │  │  │     ├─ filter
│  │  │  │  │  │     │  ├─ kalman_filter.cpp.o
│  │  │  │  │  │     │  ├─ kalman_filter.cpp.o.d
│  │  │  │  │  │     │  ├─ mean_filter.cpp.o
│  │  │  │  │  │     │  ├─ mean_filter.cpp.o.d
│  │  │  │  │  │     │  ├─ tracking_flow.cpp.o
│  │  │  │  │  │     │  └─ tracking_flow.cpp.o.d
│  │  │  │  │  │     ├─ image_utils.cpp.o
│  │  │  │  │  │     ├─ image_utils.cpp.o.d
│  │  │  │  │  │     ├─ math_utils.cpp.o
│  │  │  │  │  │     └─ math_utils.cpp.o.d
│  │  │  │  │  └─ progress.marks
│  │  │  │  ├─ Makefile
│  │  │  │  ├─ cmake_install.cmake
│  │  │  │  └─ libbase_utils.a
│  │  │  ├─ cmake_install.cmake
│  │  │  └─ libdmcv.so
│  │  ├─ classification.cpp
│  │  ├─ classification.h
│  │  ├─ main.cpp
│  │  ├─ object_detection.cpp
│  │  └─ object_detection.h
│  ├─ BSP_DHT11
│  │  ├─ CMakeLists.txt
│  │  ├─ DHT11.cpp
│  │  ├─ DHT11.hpp
│  │  ├─ DHT11_class.hpp
│  │  ├─ DHT11_main.cpp
│  │  ├─ DHT11_register.cpp
│  │  └─ build
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ DHT_EG.dir
│  │     │  │  ├─ DHT11.cpp.o
│  │     │  │  ├─ DHT11.cpp.o.d
│  │     │  │  ├─ DHT11_main.cpp.o
│  │     │  │  ├─ DHT11_main.cpp.o.d
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  ├─ BSP_KEYS
│  │     │  │  │        │  │  ├─ Keys.cpp.o
│  │     │  │  │        │  │  └─ Keys.cpp.o.d
│  │     │  │  │        │  └─ BSP_LED
│  │     │  │  │        │     ├─ Led.cpp.o
│  │     │  │  │        │     └─ Led.cpp.o.d
│  │     │  │  │        └─ SYS_Con
│  │     │  │  │           ├─ EventDriven.cpp.o
│  │     │  │  │           ├─ EventDriven.cpp.o.d
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │           ├─ Sys_Functions.cpp.o
│  │     │  │  │           ├─ Sys_Functions.cpp.o.d
│  │     │  │  │           └─ src
│  │     │  │  │              ├─ Setter_EventDriven.cpp.o
│  │     │  │  │              ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │              ├─ Sys_Functions.cpp.o
│  │     │  │  │              └─ Sys_Functions.cpp.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ Progress
│  │     │  │  ├─ 3
│  │     │  │  ├─ 5
│  │     │  │  └─ count.txt
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ DHT_EG
│  │     ├─ Makefile
│  │     ├─ cmake_install.cmake
│  │     └─ dht11.c
│  ├─ BSP_KEYS
│  │  ├─ CMakeLists.txt
│  │  ├─ Key_class.hpp
│  │  ├─ Key_main.cpp
│  │  ├─ Key_register.cpp
│  │  ├─ Keys.cpp
│  │  ├─ Keys.hpp
│  │  └─ build
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ KEY_EG.dir
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ Key_main.cpp.o
│  │     │  │  ├─ Key_main.cpp.o.d
│  │     │  │  ├─ Key_register.cpp.o
│  │     │  │  ├─ Key_register.cpp.o.d
│  │     │  │  ├─ Keys.cpp.o
│  │     │  │  ├─ Keys.cpp.o.d
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.internal
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  └─ BSP_LED
│  │     │  │  │        │     ├─ Led.cpp.o
│  │     │  │  │        │     ├─ Led.cpp.o.d
│  │     │  │  │        │     ├─ Led_register.cpp.o
│  │     │  │  │        │     └─ Led_register.cpp.o.d
│  │     │  │  │        └─ SYS_Con
│  │     │  │  │           ├─ EventBus.cpp.o
│  │     │  │  │           ├─ EventBus.cpp.o.d
│  │     │  │  │           ├─ EventDriven.cpp.o
│  │     │  │  │           ├─ EventDriven.cpp.o.d
│  │     │  │  │           ├─ Getter_EventDriven.cpp.o
│  │     │  │  │           ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │           ├─ Sys_Functions.cpp.o
│  │     │  │  │           ├─ Sys_Functions.cpp.o.d
│  │     │  │  │           └─ src
│  │     │  │  │              ├─ EventBus.cpp.o
│  │     │  │  │              ├─ EventBus.cpp.o.d
│  │     │  │  │              ├─ Getter_EventDriven.cpp.o
│  │     │  │  │              ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │              ├─ Setter_EventDriven.cpp.o
│  │     │  │  │              ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │              ├─ Sys_Functions.cpp.o
│  │     │  │  │              └─ Sys_Functions.cpp.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ Packages.dir
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ cmake_clean_target.cmake
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ KEY_EG
│  │     ├─ Makefile
│  │     └─ cmake_install.cmake
│  ├─ BSP_LCD
│  │  ├─ CMakeLists.txt
│  │  ├─ LCD.cpp
│  │  ├─ LCD.hpp
│  │  ├─ LCD_Config.cpp
│  │  ├─ LCD_class.hpp
│  │  ├─ LCD_main.cpp
│  │  ├─ LCD_register.cpp
│  │  └─ build
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ LCD_EG.dir
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ LCD.cpp.o
│  │     │  │  ├─ LCD.cpp.o.d
│  │     │  │  ├─ LCD_Config.cpp.o
│  │     │  │  ├─ LCD_Config.cpp.o.d
│  │     │  │  ├─ LCD_main.cpp.o
│  │     │  │  ├─ LCD_main.cpp.o.d
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.internal
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  ├─ BSP_KEYS
│  │     │  │  │        │  │  ├─ Keys.cpp.o
│  │     │  │  │        │  │  └─ Keys.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LED
│  │     │  │  │        │  │  ├─ Led.cpp.o
│  │     │  │  │        │  │  └─ Led.cpp.o.d
│  │     │  │  │        │  └─ Fonts
│  │     │  │  │        │     ├─ font12.c.o
│  │     │  │  │        │     ├─ font12.c.o.d
│  │     │  │  │        │     ├─ font16.c.o
│  │     │  │  │        │     └─ font16.c.o.d
│  │     │  │  │        ├─ SYS_Con
│  │     │  │  │        │  ├─ I2C_Command.cpp.o
│  │     │  │  │        │  ├─ I2C_Command.cpp.o.d
│  │     │  │  │        │  ├─ SPI_Command.cpp.o
│  │     │  │  │        │  ├─ SPI_Command.cpp.o.d
│  │     │  │  │        │  ├─ Setter_EventDriven.cpp.o
│  │     │  │  │        │  ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │        │  ├─ Sys_Functions.cpp.o
│  │     │  │  │        │  └─ Sys_Functions.cpp.o.d
│  │     │  │  │        └─ lib
│  │     │  │  │           └─ Face
│  │     │  │  │              ├─ angry_face.cpp.o
│  │     │  │  │              ├─ angry_face.cpp.o.d
│  │     │  │  │              ├─ happy_face.cpp.o
│  │     │  │  │              ├─ happy_face.cpp.o.d
│  │     │  │  │              ├─ normal_face.cpp.o
│  │     │  │  │              ├─ normal_face.cpp.o.d
│  │     │  │  │              ├─ sad_face.cpp.o
│  │     │  │  │              ├─ sad_face.cpp.o.d
│  │     │  │  │              ├─ sleep_face.cpp.o
│  │     │  │  │              ├─ sleep_face.cpp.o.d
│  │     │  │  │              ├─ think_face.cpp.o
│  │     │  │  │              └─ think_face.cpp.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ Progress
│  │     │  │  ├─ 1
│  │     │  │  └─ count.txt
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ LCD_EG
│  │     ├─ Makefile
│  │     └─ cmake_install.cmake
│  ├─ BSP_LED
│  │  ├─ CMakeLists.txt
│  │  ├─ Led.cpp
│  │  ├─ Led.hpp
│  │  ├─ Led_class.hpp
│  │  ├─ Led_main.cpp
│  │  ├─ Led_register.cpp
│  │  └─ build
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ LED_EG.dir
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ Led.cpp.o
│  │     │  │  ├─ Led.cpp.o.d
│  │     │  │  ├─ Led_main.cpp.o
│  │     │  │  ├─ Led_main.cpp.o.d
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.internal
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        └─ SYS_Con
│  │     │  │  │           ├─ EventDriven.cpp.o
│  │     │  │  │           ├─ EventDriven.cpp.o.d
│  │     │  │  │           ├─ Sys_Functions.cpp.o
│  │     │  │  │           └─ Sys_Functions.cpp.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ LED_EG
│  │     ├─ Makefile
│  │     └─ cmake_install.cmake
│  ├─ BSP_OLED
│  │  ├─ CMakeLists.txt
│  │  ├─ Frame.cpp
│  │  ├─ OLED.cpp
│  │  ├─ OLED.hpp
│  │  ├─ OLED_Config.cpp
│  │  ├─ OLED_class.hpp
│  │  ├─ OLED_main.cpp
│  │  ├─ OLED_register.cpp
│  │  └─ build
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ OLED_EG.dir
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ Frame.cpp.o
│  │     │  │  ├─ Frame.cpp.o.d
│  │     │  │  ├─ OLED.cpp.o
│  │     │  │  ├─ OLED.cpp.o.d
│  │     │  │  ├─ OLED_Config.cpp.o
│  │     │  │  ├─ OLED_Config.cpp.o.d
│  │     │  │  ├─ OLED_main.cpp.o
│  │     │  │  ├─ OLED_main.cpp.o.d
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.internal
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  ├─ BSP_KEYS
│  │     │  │  │        │  │  ├─ Keys.cpp.o
│  │     │  │  │        │  │  └─ Keys.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LCD
│  │     │  │  │        │  │  ├─ LCD.cpp.o
│  │     │  │  │        │  │  └─ LCD.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LED
│  │     │  │  │        │  │  ├─ Led.cpp.o
│  │     │  │  │        │  │  └─ Led.cpp.o.d
│  │     │  │  │        │  └─ Fonts
│  │     │  │  │        │     ├─ font12.c.o
│  │     │  │  │        │     ├─ font12.c.o.d
│  │     │  │  │        │     ├─ font16.c.o
│  │     │  │  │        │     └─ font16.c.o.d
│  │     │  │  │        └─ SYS_Con
│  │     │  │  │           ├─ EventDriven.cpp.o
│  │     │  │  │           ├─ EventDriven.cpp.o.d
│  │     │  │  │           ├─ I2C_Command.cpp.o
│  │     │  │  │           ├─ I2C_Command.cpp.o.d
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │           ├─ Sys_Functions.cpp.o
│  │     │  │  │           └─ Sys_Functions.cpp.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ Makefile
│  │     ├─ OLED_EG
│  │     └─ cmake_install.cmake
│  ├─ BSP_PWM
│  │  ├─ CMakeLists.txt
│  │  ├─ build
│  │  │  ├─ CMakeCache.txt
│  │  │  ├─ CMakeFiles
│  │  │  │  ├─ 3.25.1
│  │  │  │  │  ├─ CMakeCCompiler.cmake
│  │  │  │  │  ├─ CMakeCXXCompiler.cmake
│  │  │  │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │  │  │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │  │  │  │  ├─ CMakeSystem.cmake
│  │  │  │  │  ├─ CompilerIdC
│  │  │  │  │  │  ├─ CMakeCCompilerId.c
│  │  │  │  │  │  └─ a.out
│  │  │  │  │  └─ CompilerIdCXX
│  │  │  │  │     ├─ CMakeCXXCompilerId.cpp
│  │  │  │  │     └─ a.out
│  │  │  │  ├─ CMakeDirectoryInformation.cmake
│  │  │  │  ├─ CMakeOutput.log
│  │  │  │  ├─ Makefile.cmake
│  │  │  │  ├─ Makefile2
│  │  │  │  ├─ PWM_EG.dir
│  │  │  │  │  ├─ DependInfo.cmake
│  │  │  │  │  ├─ build.make
│  │  │  │  │  ├─ cmake_clean.cmake
│  │  │  │  │  ├─ compiler_depend.internal
│  │  │  │  │  ├─ compiler_depend.make
│  │  │  │  │  ├─ compiler_depend.ts
│  │  │  │  │  ├─ depend.make
│  │  │  │  │  ├─ flags.make
│  │  │  │  │  ├─ gpio_pwm.cpp.o
│  │  │  │  │  ├─ gpio_pwm.cpp.o.d
│  │  │  │  │  ├─ home
│  │  │  │  │  │  └─ MootBot
│  │  │  │  │  │     └─ MoodBot_Product
│  │  │  │  │  │        ├─ BSP
│  │  │  │  │  │        │  ├─ BSP_KEYS
│  │  │  │  │  │        │  │  ├─ Keys.cpp.o
│  │  │  │  │  │        │  │  └─ Keys.cpp.o.d
│  │  │  │  │  │        │  └─ BSP_LED
│  │  │  │  │  │        │     ├─ Led.cpp.o
│  │  │  │  │  │        │     └─ Led.cpp.o.d
│  │  │  │  │  │        └─ SYS_Con
│  │  │  │  │  │           ├─ EventDriven.cpp.o
│  │  │  │  │  │           ├─ EventDriven.cpp.o.d
│  │  │  │  │  │           ├─ Setter_EventDriven.cpp.o
│  │  │  │  │  │           ├─ Setter_EventDriven.cpp.o.d
│  │  │  │  │  │           ├─ Sys_Functions.cpp.o
│  │  │  │  │  │           └─ Sys_Functions.cpp.o.d
│  │  │  │  │  ├─ link.txt
│  │  │  │  │  ├─ progress.make
│  │  │  │  │  ├─ pwm_main.cpp.o
│  │  │  │  │  └─ pwm_main.cpp.o.d
│  │  │  │  ├─ Progress
│  │  │  │  │  ├─ 2
│  │  │  │  │  └─ count.txt
│  │  │  │  ├─ TargetDirectories.txt
│  │  │  │  ├─ cmake.check_cache
│  │  │  │  └─ progress.marks
│  │  │  ├─ Makefile
│  │  │  ├─ PWM_EG
│  │  │  └─ cmake_install.cmake
│  │  ├─ gpio_pwm.cpp
│  │  ├─ gpio_pwm.hpp
│  │  ├─ pwm_class.hpp
│  │  ├─ pwm_main.cpp
│  │  └─ pwm_register.cpp
│  ├─ BSP_QM2
│  │  ├─ CMakeLists.txt
│  │  ├─ QM2.cpp
│  │  ├─ QM2.hpp
│  │  ├─ QM2_class.hpp
│  │  ├─ QM2_main.cpp
│  │  ├─ QM2_register.cpp
│  │  └─ build
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ QM2_EG.dir
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ QM2.cpp.o
│  │     │  │  ├─ QM2.cpp.o.d
│  │     │  │  ├─ QM2_main.cpp.o
│  │     │  │  ├─ QM2_main.cpp.o.d
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.internal
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  ├─ BSP_5516
│  │     │  │  │        │  │  ├─ 5516.cpp.o
│  │     │  │  │        │  │  └─ 5516.cpp.o.d
│  │     │  │  │        │  ├─ BSP_KEYS
│  │     │  │  │        │  │  ├─ Key_register.cpp.o
│  │     │  │  │        │  │  ├─ Key_register.cpp.o.d
│  │     │  │  │        │  │  ├─ Keys.cpp.o
│  │     │  │  │        │  │  └─ Keys.cpp.o.d
│  │     │  │  │        │  └─ BSP_LED
│  │     │  │  │        │     ├─ Led.cpp.o
│  │     │  │  │        │     ├─ Led.cpp.o.d
│  │     │  │  │        │     ├─ Led_register.cpp.o
│  │     │  │  │        │     └─ Led_register.cpp.o.d
│  │     │  │  │        └─ SYS_Con
│  │     │  │  │           ├─ Getter_EventDriven.cpp.o
│  │     │  │  │           ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o
│  │     │  │  │           ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │           ├─ Sys_Functions.cpp.o
│  │     │  │  │           ├─ Sys_Functions.cpp.o.d
│  │     │  │  │           └─ src
│  │     │  │  │              ├─ EventBus.cpp.o
│  │     │  │  │              ├─ EventBus.cpp.o.d
│  │     │  │  │              ├─ Getter_EventDriven.cpp.o
│  │     │  │  │              ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │              ├─ I2C_Command.cpp.o
│  │     │  │  │              ├─ I2C_Command.cpp.o.d
│  │     │  │  │              ├─ SPI_Command.cpp.o
│  │     │  │  │              ├─ SPI_Command.cpp.o.d
│  │     │  │  │              ├─ Setter_EventDriven.cpp.o
│  │     │  │  │              ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │              ├─ Sys_Functions.cpp.o
│  │     │  │  │              └─ Sys_Functions.cpp.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ Makefile
│  │     ├─ QM2_EG
│  │     └─ cmake_install.cmake
│  ├─ BSP_RD-03
│  │  ├─ CMakeLists.txt
│  │  ├─ Rd-03.cpp
│  │  ├─ Rd-03.hpp
│  │  ├─ Rd-03_class.hpp
│  │  ├─ Rd-03_main.cpp
│  │  ├─ Rd-03_register.cpp
│  │  └─ build
│  │     ├─ CMakeCache.txt
│  │     ├─ CMakeFiles
│  │     │  ├─ 3.25.1
│  │     │  │  ├─ CMakeCCompiler.cmake
│  │     │  │  ├─ CMakeCXXCompiler.cmake
│  │     │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │     │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │     │  │  ├─ CMakeSystem.cmake
│  │     │  │  ├─ CompilerIdC
│  │     │  │  │  ├─ CMakeCCompilerId.c
│  │     │  │  │  └─ a.out
│  │     │  │  └─ CompilerIdCXX
│  │     │  │     ├─ CMakeCXXCompilerId.cpp
│  │     │  │     └─ a.out
│  │     │  ├─ CMakeDirectoryInformation.cmake
│  │     │  ├─ CMakeOutput.log
│  │     │  ├─ Makefile.cmake
│  │     │  ├─ Makefile2
│  │     │  ├─ Progress
│  │     │  │  ├─ 10
│  │     │  │  ├─ 11
│  │     │  │  ├─ 12
│  │     │  │  ├─ 13
│  │     │  │  ├─ 14
│  │     │  │  ├─ 17
│  │     │  │  ├─ 2
│  │     │  │  ├─ 3
│  │     │  │  ├─ 4
│  │     │  │  ├─ 6
│  │     │  │  ├─ 7
│  │     │  │  ├─ 9
│  │     │  │  └─ count.txt
│  │     │  ├─ RD_EG.dir
│  │     │  │  ├─ DependInfo.cmake
│  │     │  │  ├─ Rd-03.cpp.o
│  │     │  │  ├─ Rd-03.cpp.o.d
│  │     │  │  ├─ Rd-03_main.cpp.o
│  │     │  │  ├─ Rd-03_main.cpp.o.d
│  │     │  │  ├─ build.make
│  │     │  │  ├─ cmake_clean.cmake
│  │     │  │  ├─ compiler_depend.make
│  │     │  │  ├─ compiler_depend.ts
│  │     │  │  ├─ depend.make
│  │     │  │  ├─ flags.make
│  │     │  │  ├─ home
│  │     │  │  │  └─ MootBot
│  │     │  │  │     └─ MoodBot_Product
│  │     │  │  │        ├─ BSP
│  │     │  │  │        │  ├─ BSP_5516
│  │     │  │  │        │  │  ├─ 5516.cpp.o
│  │     │  │  │        │  │  ├─ 5516.cpp.o.d
│  │     │  │  │        │  │  ├─ 5516_main.cpp.o
│  │     │  │  │        │  │  ├─ 5516_main.cpp.o.d
│  │     │  │  │        │  │  ├─ 5516_register.cpp.o
│  │     │  │  │        │  │  └─ 5516_register.cpp.o.d
│  │     │  │  │        │  ├─ BSP_KEYS
│  │     │  │  │        │  │  ├─ Key_register.cpp.o
│  │     │  │  │        │  │  ├─ Key_register.cpp.o.d
│  │     │  │  │        │  │  ├─ Keys.cpp.o
│  │     │  │  │        │  │  └─ Keys.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LCD
│  │     │  │  │        │  │  ├─ LCD.cpp.o
│  │     │  │  │        │  │  ├─ LCD.cpp.o.d
│  │     │  │  │        │  │  ├─ LCD_Config.cpp.o
│  │     │  │  │        │  │  ├─ LCD_Config.cpp.o.d
│  │     │  │  │        │  │  ├─ LCD_main.cpp.o
│  │     │  │  │        │  │  └─ LCD_main.cpp.o.d
│  │     │  │  │        │  ├─ BSP_LED
│  │     │  │  │        │  │  ├─ Led.cpp.o
│  │     │  │  │        │  │  ├─ Led.cpp.o.d
│  │     │  │  │        │  │  ├─ Led_register.cpp.o
│  │     │  │  │        │  │  └─ Led_register.cpp.o.d
│  │     │  │  │        │  └─ Fonts
│  │     │  │  │        │     ├─ font12.c.o
│  │     │  │  │        │     ├─ font12.c.o.d
│  │     │  │  │        │     ├─ font16.c.o
│  │     │  │  │        │     └─ font16.c.o.d
│  │     │  │  │        ├─ SYS_Con
│  │     │  │  │        │  ├─ EventDriven.cpp.o
│  │     │  │  │        │  ├─ EventDriven.cpp.o.d
│  │     │  │  │        │  ├─ I2C_Command.cpp.o
│  │     │  │  │        │  ├─ I2C_Command.cpp.o.d
│  │     │  │  │        │  ├─ SPI_Command.cpp.o
│  │     │  │  │        │  ├─ SPI_Command.cpp.o.d
│  │     │  │  │        │  ├─ Setter_EventDriven.cpp.o
│  │     │  │  │        │  ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │        │  ├─ Sys_Functions.cpp.o
│  │     │  │  │        │  ├─ Sys_Functions.cpp.o.d
│  │     │  │  │        │  └─ src
│  │     │  │  │        │     ├─ EventBus.cpp.o
│  │     │  │  │        │     ├─ EventBus.cpp.o.d
│  │     │  │  │        │     ├─ Getter_EventDriven.cpp.o
│  │     │  │  │        │     ├─ Getter_EventDriven.cpp.o.d
│  │     │  │  │        │     ├─ I2C_Command.cpp.o
│  │     │  │  │        │     ├─ I2C_Command.cpp.o.d
│  │     │  │  │        │     ├─ SPI_Command.cpp.o
│  │     │  │  │        │     ├─ SPI_Command.cpp.o.d
│  │     │  │  │        │     ├─ Setter_EventDriven.cpp.o
│  │     │  │  │        │     ├─ Setter_EventDriven.cpp.o.d
│  │     │  │  │        │     ├─ Sys_Functions.cpp.o
│  │     │  │  │        │     └─ Sys_Functions.cpp.o.d
│  │     │  │  │        └─ lib
│  │     │  │  │           └─ Fonts
│  │     │  │  │              ├─ font12.c.o
│  │     │  │  │              ├─ font12.c.o.d
│  │     │  │  │              ├─ font16.c.o
│  │     │  │  │              └─ font16.c.o.d
│  │     │  │  ├─ link.txt
│  │     │  │  └─ progress.make
│  │     │  ├─ TargetDirectories.txt
│  │     │  ├─ cmake.check_cache
│  │     │  └─ progress.marks
│  │     ├─ Makefile
│  │     ├─ RD_EG
│  │     └─ cmake_install.cmake
│  └─ BSP_Servo
│     ├─ CMakeLists.txt
│     ├─ Servo.cpp
│     ├─ Servo.hpp
│     ├─ ServoPro.cpp
│     ├─ ServoPro_register.cpp
│     ├─ Servo_class.hpp
│     ├─ Servo_main.cpp
│     ├─ Servo_register.cpp
│     └─ build
│        ├─ CMakeCache.txt
│        ├─ CMakeFiles
│        │  ├─ 3.25.1
│        │  │  ├─ CMakeCCompiler.cmake
│        │  │  ├─ CMakeCXXCompiler.cmake
│        │  │  ├─ CMakeDetermineCompilerABI_C.bin
│        │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│        │  │  ├─ CMakeSystem.cmake
│        │  │  ├─ CompilerIdC
│        │  │  │  ├─ CMakeCCompilerId.c
│        │  │  │  └─ a.out
│        │  │  └─ CompilerIdCXX
│        │  │     ├─ CMakeCXXCompilerId.cpp
│        │  │     └─ a.out
│        │  ├─ CMakeDirectoryInformation.cmake
│        │  ├─ CMakeOutput.log
│        │  ├─ Makefile.cmake
│        │  ├─ Makefile2
│        │  ├─ SER_EG.dir
│        │  │  ├─ DependInfo.cmake
│        │  │  ├─ Servo.cpp.o
│        │  │  ├─ Servo.cpp.o.d
│        │  │  ├─ ServoPro.cpp.o
│        │  │  ├─ ServoPro.cpp.o.d
│        │  │  ├─ Servo_main.cpp.o
│        │  │  ├─ Servo_main.cpp.o.d
│        │  │  ├─ build.make
│        │  │  ├─ cmake_clean.cmake
│        │  │  ├─ compiler_depend.internal
│        │  │  ├─ compiler_depend.make
│        │  │  ├─ compiler_depend.ts
│        │  │  ├─ depend.make
│        │  │  ├─ flags.make
│        │  │  ├─ home
│        │  │  │  └─ MootBot
│        │  │  │     └─ MoodBot_Product
│        │  │  │        ├─ BSP
│        │  │  │        │  ├─ BSP_5516
│        │  │  │        │  │  ├─ 5516.cpp.o
│        │  │  │        │  │  ├─ 5516.cpp.o.d
│        │  │  │        │  │  ├─ 5516_register.cpp.o
│        │  │  │        │  │  └─ 5516_register.cpp.o.d
│        │  │  │        │  ├─ BSP_KEYS
│        │  │  │        │  │  ├─ Key_register.cpp.o
│        │  │  │        │  │  ├─ Key_register.cpp.o.d
│        │  │  │        │  │  ├─ Keys.cpp.o
│        │  │  │        │  │  └─ Keys.cpp.o.d
│        │  │  │        │  ├─ BSP_LCD
│        │  │  │        │  │  ├─ LCD.cpp.o
│        │  │  │        │  │  ├─ LCD.cpp.o.d
│        │  │  │        │  │  ├─ LCD_Config.cpp.o
│        │  │  │        │  │  └─ LCD_Config.cpp.o.d
│        │  │  │        │  ├─ BSP_LED
│        │  │  │        │  │  ├─ Led.cpp.o
│        │  │  │        │  │  ├─ Led.cpp.o.d
│        │  │  │        │  │  ├─ Led_register.cpp.o
│        │  │  │        │  │  └─ Led_register.cpp.o.d
│        │  │  │        │  ├─ BSP_PWM
│        │  │  │        │  │  ├─ gpio_pwm.cpp.o
│        │  │  │        │  │  └─ gpio_pwm.cpp.o.d
│        │  │  │        │  └─ BSP_RD-03
│        │  │  │        │     ├─ Rd-03.cpp.o
│        │  │  │        │     ├─ Rd-03.cpp.o.d
│        │  │  │        │     ├─ Rd-03_register.cpp.o
│        │  │  │        │     └─ Rd-03_register.cpp.o.d
│        │  │  │        ├─ SYS_Con
│        │  │  │        │  ├─ EventDriven.cpp.o
│        │  │  │        │  ├─ EventDriven.cpp.o.d
│        │  │  │        │  ├─ Setter_EventDriven.cpp.o
│        │  │  │        │  ├─ Setter_EventDriven.cpp.o.d
│        │  │  │        │  ├─ Sys_Functions.cpp.o
│        │  │  │        │  ├─ Sys_Functions.cpp.o.d
│        │  │  │        │  └─ src
│        │  │  │        │     ├─ EventBus.cpp.o
│        │  │  │        │     ├─ EventBus.cpp.o.d
│        │  │  │        │     ├─ Getter_EventDriven.cpp.o
│        │  │  │        │     ├─ Getter_EventDriven.cpp.o.d
│        │  │  │        │     ├─ I2C_Command.cpp.o
│        │  │  │        │     ├─ I2C_Command.cpp.o.d
│        │  │  │        │     ├─ SPI_Command.cpp.o
│        │  │  │        │     ├─ SPI_Command.cpp.o.d
│        │  │  │        │     ├─ Setter_EventDriven.cpp.o
│        │  │  │        │     ├─ Setter_EventDriven.cpp.o.d
│        │  │  │        │     ├─ Sys_Functions.cpp.o
│        │  │  │        │     └─ Sys_Functions.cpp.o.d
│        │  │  │        └─ lib
│        │  │  │           └─ Fonts
│        │  │  │              ├─ font12.c.o
│        │  │  │              ├─ font12.c.o.d
│        │  │  │              ├─ font16.c.o
│        │  │  │              └─ font16.c.o.d
│        │  │  ├─ link.txt
│        │  │  └─ progress.make
│        │  ├─ TargetDirectories.txt
│        │  ├─ cmake.check_cache
│        │  └─ progress.marks
│        ├─ Makefile
│        ├─ SER_EG
│        └─ cmake_install.cmake
├─ CMakeLists.txt
├─ OpenCV-4-11-0.sh
├─ README.md
├─ SYS_Con
│  ├─ inc
│  │  ├─ COM_List.hpp
│  │  ├─ EventBus.hpp
│  │  ├─ EventDriven_class.hpp
│  │  ├─ Getter_Register.hpp
│  │  ├─ SYS.hpp
│  │  └─ Setter_Register.hpp
│  └─ src
│     ├─ EventBus.cpp
│     ├─ Getter_EventDriven.cpp
│     ├─ I2C_Command.cpp
│     ├─ SPI_Command.cpp
│     ├─ Setter_EventDriven.cpp
│     └─ Sys_Functions.cpp
├─ build.sh
├─ build
│  ├─ CMakeCache.txt
│  ├─ CMakeFiles
│  │  ├─ 3.25.1
│  │  │  ├─ CMakeASMCompiler.cmake
│  │  │  ├─ CMakeCCompiler.cmake
│  │  │  ├─ CMakeCXXCompiler.cmake
│  │  │  ├─ CMakeDetermineCompilerABI_C.bin
│  │  │  ├─ CMakeDetermineCompilerABI_CXX.bin
│  │  │  ├─ CMakeSystem.cmake
│  │  │  ├─ CompilerIdC
│  │  │  │  ├─ CMakeCCompilerId.c
│  │  │  │  └─ a.out
│  │  │  └─ CompilerIdCXX
│  │  │     ├─ CMakeCXXCompilerId.cpp
│  │  │     └─ a.out
│  │  ├─ CMakeDirectoryInformation.cmake
│  │  ├─ CMakeOutput.log
│  │  ├─ FindOpenMP
│  │  │  ├─ ompver_C.bin
│  │  │  └─ ompver_CXX.bin
│  │  ├─ MAIN.dir
│  │  │  ├─ BSP
│  │  │  │  ├─ BSP_5516
│  │  │  │  │  ├─ 5516.cpp.o
│  │  │  │  │  ├─ 5516.cpp.o.d
│  │  │  │  │  ├─ 5516_register.cpp.o
│  │  │  │  │  └─ 5516_register.cpp.o.d
│  │  │  │  ├─ BSP_Audio
│  │  │  │  │  ├─ Audio.cpp.o
│  │  │  │  │  ├─ Audio.cpp.o.d
│  │  │  │  │  ├─ Audio_register.cpp.o
│  │  │  │  │  └─ Audio_register.cpp.o.d
│  │  │  │  ├─ BSP_DHT11
│  │  │  │  │  ├─ DHT11.cpp.o
│  │  │  │  │  ├─ DHT11.cpp.o.d
│  │  │  │  │  ├─ DHT11_register.cpp.o
│  │  │  │  │  └─ DHT11_register.cpp.o.d
│  │  │  │  ├─ BSP_KEYS
│  │  │  │  │  ├─ Key_register.cpp.o
│  │  │  │  │  ├─ Key_register.cpp.o.d
│  │  │  │  │  ├─ Keys.cpp.o
│  │  │  │  │  └─ Keys.cpp.o.d
│  │  │  │  ├─ BSP_LCD
│  │  │  │  │  ├─ LCD.cpp.o
│  │  │  │  │  ├─ LCD.cpp.o.d
│  │  │  │  │  ├─ LCD_Config.cpp.o
│  │  │  │  │  ├─ LCD_Config.cpp.o.d
│  │  │  │  │  ├─ LCD_register.cpp.o
│  │  │  │  │  └─ LCD_register.cpp.o.d
│  │  │  │  ├─ BSP_LED
│  │  │  │  │  ├─ Led.cpp.o
│  │  │  │  │  ├─ Led.cpp.o.d
│  │  │  │  │  ├─ Led_register.cpp.o
│  │  │  │  │  └─ Led_register.cpp.o.d
│  │  │  │  ├─ BSP_OLED
│  │  │  │  │  ├─ Frame.cpp.o
│  │  │  │  │  ├─ Frame.cpp.o.d
│  │  │  │  │  ├─ OLED.cpp.o
│  │  │  │  │  ├─ OLED.cpp.o.d
│  │  │  │  │  ├─ OLED_Config.cpp.o
│  │  │  │  │  ├─ OLED_Config.cpp.o.d
│  │  │  │  │  ├─ OLED_register.cpp.o
│  │  │  │  │  └─ OLED_register.cpp.o.d
│  │  │  │  ├─ BSP_PWM
│  │  │  │  │  ├─ gpio_pwm.cpp.o
│  │  │  │  │  ├─ gpio_pwm.cpp.o.d
│  │  │  │  │  ├─ pwm_register.cpp.o
│  │  │  │  │  └─ pwm_register.cpp.o.d
│  │  │  │  ├─ BSP_QM2
│  │  │  │  │  ├─ QM2.cpp.o
│  │  │  │  │  ├─ QM2.cpp.o.d
│  │  │  │  │  ├─ QM2_register.cpp.o
│  │  │  │  │  └─ QM2_register.cpp.o.d
│  │  │  │  ├─ BSP_RD-03
│  │  │  │  │  ├─ Rd-03.cpp.o
│  │  │  │  │  ├─ Rd-03.cpp.o.d
│  │  │  │  │  ├─ Rd-03_register.cpp.o
│  │  │  │  │  └─ Rd-03_register.cpp.o.d
│  │  │  │  └─ BSP_Servo
│  │  │  │     ├─ Servo.cpp.o
│  │  │  │     ├─ Servo.cpp.o.d
│  │  │  │     ├─ ServoPro.cpp.o
│  │  │  │     ├─ ServoPro.cpp.o.d
│  │  │  │     ├─ ServoPro_register.cpp.o
│  │  │  │     ├─ ServoPro_register.cpp.o.d
│  │  │  │     ├─ Servo_register.cpp.o
│  │  │  │     └─ Servo_register.cpp.o.d
│  │  │  ├─ DependInfo.cmake
│  │  │  ├─ SYS_Con
│  │  │  │  └─ src
│  │  │  │     ├─ EventBus.cpp.o
│  │  │  │     ├─ EventBus.cpp.o.d
│  │  │  │     ├─ Getter_EventDriven.cpp.o
│  │  │  │     ├─ Getter_EventDriven.cpp.o.d
│  │  │  │     ├─ I2C_Command.cpp.o
│  │  │  │     ├─ I2C_Command.cpp.o.d
│  │  │  │     ├─ SPI_Command.cpp.o
│  │  │  │     ├─ SPI_Command.cpp.o.d
│  │  │  │     ├─ Setter_EventDriven.cpp.o
│  │  │  │     ├─ Setter_EventDriven.cpp.o.d
│  │  │  │     ├─ Sys_Functions.cpp.o
│  │  │  │     └─ Sys_Functions.cpp.o.d
│  │  │  ├─ build.make
│  │  │  ├─ cmake_clean.cmake
│  │  │  ├─ compiler_depend.internal
│  │  │  ├─ compiler_depend.make
│  │  │  ├─ compiler_depend.ts
│  │  │  ├─ depend.make
│  │  │  ├─ flags.make
│  │  │  ├─ lib
│  │  │  │  ├─ Face
│  │  │  │  │  ├─ angry_face.cpp.o
│  │  │  │  │  ├─ angry_face.cpp.o.d
│  │  │  │  │  ├─ comfort_face.cpp.o
│  │  │  │  │  ├─ comfort_face.cpp.o.d
│  │  │  │  │  ├─ happy_face.cpp.o
│  │  │  │  │  ├─ happy_face.cpp.o.d
│  │  │  │  │  ├─ normal_face.cpp.o
│  │  │  │  │  ├─ normal_face.cpp.o.d
│  │  │  │  │  ├─ sad_face.cpp.o
│  │  │  │  │  ├─ sad_face.cpp.o.d
│  │  │  │  │  ├─ singing_face.cpp.o
│  │  │  │  │  ├─ singing_face.cpp.o.d
│  │  │  │  │  ├─ sleep_face.cpp.o
│  │  │  │  │  ├─ sleep_face.cpp.o.d
│  │  │  │  │  ├─ think_face.cpp.o
│  │  │  │  │  └─ think_face.cpp.o.d
│  │  │  │  └─ Fonts
│  │  │  │     ├─ font12.c.o
│  │  │  │     ├─ font12.c.o.d
│  │  │  │     ├─ font16.c.o
│  │  │  │     └─ font16.c.o.d
│  │  │  ├─ link.txt
│  │  │  ├─ main.cpp.o
│  │  │  ├─ main.cpp.o.d
│  │  │  └─ progress.make
│  │  ├─ Makefile.cmake
│  │  ├─ Makefile2
│  │  ├─ TargetDirectories.txt
│  │  ├─ cmake.check_cache
│  │  ├─ dmcv.dir
│  │  │  ├─ BSP
│  │  │  │  └─ BSP_Camera
│  │  │  │     ├─ Camera.cpp.o
│  │  │  │     ├─ Camera.cpp.o.d
│  │  │  │     ├─ Camera_register.cpp.o
│  │  │  │     ├─ Camera_register.cpp.o.d
│  │  │  │     ├─ Interpreter.cpp.o
│  │  │  │     ├─ Interpreter.cpp.o.d
│  │  │  │     ├─ classification.cpp.o
│  │  │  │     ├─ classification.cpp.o.d
│  │  │  │     ├─ object_detection.cpp.o
│  │  │  │     └─ object_detection.cpp.o.d
│  │  │  ├─ DependInfo.cmake
│  │  │  ├─ build.make
│  │  │  ├─ cmake_clean.cmake
│  │  │  ├─ compiler_depend.internal
│  │  │  ├─ compiler_depend.make
│  │  │  ├─ compiler_depend.ts
│  │  │  ├─ depend.make
│  │  │  ├─ flags.make
│  │  │  ├─ link.txt
│  │  │  └─ progress.make
│  │  └─ progress.marks
│  ├─ MAIN
│  ├─ Makefile
│  ├─ TNN_build
│  │  ├─ CMakeFiles
│  │  │  ├─ CMakeDirectoryInformation.cmake
│  │  │  ├─ TNN.dir
│  │  │  │  ├─ DependInfo.cmake
│  │  │  │  ├─ build.make
│  │  │  │  ├─ cmake_clean.cmake
│  │  │  │  ├─ compiler_depend.internal
│  │  │  │  ├─ compiler_depend.make
│  │  │  │  ├─ compiler_depend.ts
│  │  │  │  ├─ depend.make
│  │  │  │  ├─ flags.make
│  │  │  │  ├─ link.txt
│  │  │  │  ├─ progress.make
│  │  │  │  └─ source
│  │  │  │     └─ tnn
│  │  │  │        ├─ core
│  │  │  │        │  ├─ abstract_device.cc.o
│  │  │  │        │  ├─ abstract_device.cc.o.d
│  │  │  │        │  ├─ abstract_layer_acc.cc.o
│  │  │  │        │  ├─ abstract_layer_acc.cc.o.d
│  │  │  │        │  ├─ abstract_network.cc.o
│  │  │  │        │  ├─ abstract_network.cc.o.d
│  │  │  │        │  ├─ blob.cc.o
│  │  │  │        │  ├─ blob.cc.o.d
│  │  │  │        │  ├─ blob_impl.cc.o
│  │  │  │        │  ├─ blob_impl.cc.o.d
│  │  │  │        │  ├─ blob_int8.cc.o
│  │  │  │        │  ├─ blob_int8.cc.o.d
│  │  │  │        │  ├─ blob_manager.cc.o
│  │  │  │        │  ├─ blob_manager.cc.o.d
│  │  │  │        │  ├─ const_folder.cc.o
│  │  │  │        │  ├─ const_folder.cc.o.d
│  │  │  │        │  ├─ context.cc.o
│  │  │  │        │  ├─ context.cc.o.d
│  │  │  │        │  ├─ default_network.cc.o
│  │  │  │        │  ├─ default_network.cc.o.d
│  │  │  │        │  ├─ instance.cc.o
│  │  │  │        │  ├─ instance.cc.o.d
│  │  │  │        │  ├─ layer_type.cc.o
│  │  │  │        │  ├─ layer_type.cc.o.d
│  │  │  │        │  ├─ mat.cc.o
│  │  │  │        │  ├─ mat.cc.o.d
│  │  │  │        │  ├─ profile.cc.o
│  │  │  │        │  ├─ profile.cc.o.d
│  │  │  │        │  ├─ status.cc.o
│  │  │  │        │  ├─ status.cc.o.d
│  │  │  │        │  ├─ tnn.cc.o
│  │  │  │        │  ├─ tnn.cc.o.d
│  │  │  │        │  ├─ tnn_impl.cc.o
│  │  │  │        │  ├─ tnn_impl.cc.o.d
│  │  │  │        │  ├─ tnn_impl_default.cc.o
│  │  │  │        │  └─ tnn_impl_default.cc.o.d
│  │  │  │        ├─ extern_wrapper
│  │  │  │        │  ├─ base_layer_builder.cc.o
│  │  │  │        │  ├─ base_layer_builder.cc.o.d
│  │  │  │        │  ├─ foreign_blob.cc.o
│  │  │  │        │  └─ foreign_blob.cc.o.d
│  │  │  │        ├─ interpreter
│  │  │  │        │  ├─ abstract_model_interpreter.cc.o
│  │  │  │        │  ├─ abstract_model_interpreter.cc.o.d
│  │  │  │        │  ├─ default_model_interpreter.cc.o
│  │  │  │        │  ├─ default_model_interpreter.cc.o.d
│  │  │  │        │  ├─ default_model_packer.cc.o
│  │  │  │        │  ├─ default_model_packer.cc.o.d
│  │  │  │        │  ├─ layer_resource_generator.cc.o
│  │  │  │        │  ├─ layer_resource_generator.cc.o.d
│  │  │  │        │  ├─ ncnn
│  │  │  │        │  │  ├─ layer_interpreter
│  │  │  │        │  │  │  ├─ batch_norm_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ batch_norm_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ binary_op_interpreter.cc.o
│  │  │  │        │  │  │  ├─ binary_op_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ clip_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ clip_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ concat_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ concat_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ conv_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ conv_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ crop_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ crop_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ deconv_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ deconv_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ default_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ default_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ detection_output_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ detection_output_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ eltwise_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ eltwise_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ elu_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ elu_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ hard_sigmoid_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ hard_sigmoid_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ hard_swish_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ hard_swish_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ inner_product_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ inner_product_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ instance_norm_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ instance_norm_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ interp_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ interp_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ lrn_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ lrn_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ memory_data_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ memory_data_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ normalize_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ normalize_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ pad_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ pad_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ permute_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ permute_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ pooling_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ pooling_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ prelu_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ prelu_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ prior_box_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ prior_box_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ reduce_op_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ reduce_op_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ relu_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ relu_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ reorg_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ reorg_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ reshape_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ reshape_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ roi_pooling_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ roi_pooling_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ scale_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ scale_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ selu_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ selu_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ shuffle_channel_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ shuffle_channel_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ slice_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ slice_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ softmax_layer_interpreter.cc.o
│  │  │  │        │  │  │  ├─ softmax_layer_interpreter.cc.o.d
│  │  │  │        │  │  │  ├─ unary_op_layer_interpreter.cc.o
│  │  │  │        │  │  │  └─ unary_op_layer_interpreter.cc.o.d
│  │  │  │        │  │  ├─ ncnn_layer_type.cc.o
│  │  │  │        │  │  ├─ ncnn_layer_type.cc.o.d
│  │  │  │        │  │  ├─ ncnn_model_interpreter.cc.o
│  │  │  │        │  │  ├─ ncnn_model_interpreter.cc.o.d
│  │  │  │        │  │  ├─ ncnn_param_utils.cc.o
│  │  │  │        │  │  ├─ ncnn_param_utils.cc.o.d
│  │  │  │        │  │  └─ optimizer
│  │  │  │        │  │     ├─ expand_slice_optimizer.cc.o
│  │  │  │        │  │     ├─ expand_slice_optimizer.cc.o.d
│  │  │  │        │  │     ├─ memory_data_optimizer.cc.o
│  │  │  │        │  │     ├─ memory_data_optimizer.cc.o.d
│  │  │  │        │  │     ├─ ncnn_optimizer_manager.cc.o
│  │  │  │        │  │     └─ ncnn_optimizer_manager.cc.o.d
│  │  │  │        │  ├─ net_resource.cc.o
│  │  │  │        │  ├─ net_resource.cc.o.d
│  │  │  │        │  ├─ net_structure.cc.o
│  │  │  │        │  ├─ net_structure.cc.o.d
│  │  │  │        │  ├─ raw_buffer.cc.o
│  │  │  │        │  ├─ raw_buffer.cc.o.d
│  │  │  │        │  └─ tnn
│  │  │  │        │     ├─ layer_interpreter
│  │  │  │        │     │  ├─ add_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ add_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ arg_max_or_min_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ arg_max_or_min_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ batch_norm_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ batch_norm_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ bias_add_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ bias_add_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ bitshift_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ bitshift_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ blob_scale_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ blob_scale_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ cast_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ cast_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ clip_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ clip_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ concat_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ concat_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ const_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ const_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ constantofshape_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ constantofshape_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ conv_1d_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ conv_1d_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ conv_3d_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ conv_3d_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ conv_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ conv_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ detection_output_interpreter.cc.o
│  │  │  │        │     │  ├─ detection_output_interpreter.cc.o.d
│  │  │  │        │     │  ├─ detection_post_process_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ detection_post_process_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ div_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ div_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ einsum_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ einsum_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ elu_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ elu_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ expand_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ expand_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ flatten_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ flatten_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ gather_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ gather_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ gathernd_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ gathernd_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ gridsample_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ gridsample_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ group_norm_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ group_norm_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ hard_sigmoid_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ hard_sigmoid_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ hard_swish_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ hard_swish_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ hdrguide_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ hdrguide_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ histogram_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ histogram_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ inner_product_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ inner_product_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ instance_norm_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ instance_norm_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ layer_norm_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ layer_norm_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ lrn_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ lrn_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ lstm_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ lstm_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ mat_mul_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ mat_mul_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ max_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ max_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ min_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ min_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ mul_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ mul_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ normalize_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ normalize_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ onehot_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ onehot_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ pad_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ pad_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ padv2_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ padv2_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ permute_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ permute_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ pixel_shuffle_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ pixel_shuffle_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ pooling_3d_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ pooling_3d_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ pooling_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ pooling_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ pow_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ pow_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ prelu_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ prelu_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ prior_box_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ prior_box_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ range_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ range_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ reduce_op_interpreter.cc.o
│  │  │  │        │     │  ├─ reduce_op_interpreter.cc.o.d
│  │  │  │        │     │  ├─ reformat_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ reformat_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ reorg_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ reorg_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ reshape_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ reshape_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ roi_pooling_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ roi_pooling_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ roialign_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ roialign_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ scale_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ scale_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ scatter_nd_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ scatter_nd_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ selu_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ selu_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ shape_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ shape_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ shuffle_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ shuffle_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ signed_mul_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ signed_mul_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ size_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ size_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ softmax_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ softmax_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ splitv_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ splitv_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ squared_difference_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ squared_difference_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ squeeze_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ squeeze_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ stride_slice_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ stride_slice_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ stride_slice_v2_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ stride_slice_v2_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ sub_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ sub_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ tile_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ tile_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ topk_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ topk_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ unary_op_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ unary_op_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ unsqueeze_layer_interpreter.cc.o
│  │  │  │        │     │  ├─ unsqueeze_layer_interpreter.cc.o.d
│  │  │  │        │     │  ├─ upsample_layer_interpreter.cc.o
│  │  │  │        │     │  └─ upsample_layer_interpreter.cc.o.d
│  │  │  │        │     ├─ model_interpreter.cc.o
│  │  │  │        │     ├─ model_interpreter.cc.o.d
│  │  │  │        │     ├─ model_packer.cc.o
│  │  │  │        │     └─ model_packer.cc.o.d
│  │  │  │        ├─ layer
│  │  │  │        │  ├─ abs_layer.cc.o
│  │  │  │        │  ├─ abs_layer.cc.o.d
│  │  │  │        │  ├─ acos_layer.cc.o
│  │  │  │        │  ├─ acos_layer.cc.o.d
│  │  │  │        │  ├─ add_layer.cc.o
│  │  │  │        │  ├─ add_layer.cc.o.d
│  │  │  │        │  ├─ arg_max_or_min_layer.cc.o
│  │  │  │        │  ├─ arg_max_or_min_layer.cc.o.d
│  │  │  │        │  ├─ asin_layer.cc.o
│  │  │  │        │  ├─ asin_layer.cc.o.d
│  │  │  │        │  ├─ atan_layer.cc.o
│  │  │  │        │  ├─ atan_layer.cc.o.d
│  │  │  │        │  ├─ base_layer.cc.o
│  │  │  │        │  ├─ base_layer.cc.o.d
│  │  │  │        │  ├─ batch_norm_layer.cc.o
│  │  │  │        │  ├─ batch_norm_layer.cc.o.d
│  │  │  │        │  ├─ bias_add_layer.cc.o
│  │  │  │        │  ├─ bias_add_layer.cc.o.d
│  │  │  │        │  ├─ bitshift_layer.cc.o
│  │  │  │        │  ├─ bitshift_layer.cc.o.d
│  │  │  │        │  ├─ cast_layer.cc.o
│  │  │  │        │  ├─ cast_layer.cc.o.d
│  │  │  │        │  ├─ cbam_fused_pooling_layer.cc.o
│  │  │  │        │  ├─ cbam_fused_pooling_layer.cc.o.d
│  │  │  │        │  ├─ cbam_fused_reduce_layer.cc.o
│  │  │  │        │  ├─ cbam_fused_reduce_layer.cc.o.d
│  │  │  │        │  ├─ ceil_layer.cc.o
│  │  │  │        │  ├─ ceil_layer.cc.o.d
│  │  │  │        │  ├─ clip_layer.cc.o
│  │  │  │        │  ├─ clip_layer.cc.o.d
│  │  │  │        │  ├─ concat_layer.cc.o
│  │  │  │        │  ├─ concat_layer.cc.o.d
│  │  │  │        │  ├─ constantofshape_layer.cc.o
│  │  │  │        │  ├─ constantofshape_layer.cc.o.d
│  │  │  │        │  ├─ conv1d_layer.cc.o
│  │  │  │        │  ├─ conv1d_layer.cc.o.d
│  │  │  │        │  ├─ conv3d_layer.cc.o
│  │  │  │        │  ├─ conv3d_layer.cc.o.d
│  │  │  │        │  ├─ conv_layer.cc.o
│  │  │  │        │  ├─ conv_layer.cc.o.d
│  │  │  │        │  ├─ cos_layer.cc.o
│  │  │  │        │  ├─ cos_layer.cc.o.d
│  │  │  │        │  ├─ deconv_layer.cc.o
│  │  │  │        │  ├─ deconv_layer.cc.o.d
│  │  │  │        │  ├─ detection_output_layer.cc.o
│  │  │  │        │  ├─ detection_output_layer.cc.o.d
│  │  │  │        │  ├─ detection_post_process_layer.cc.o
│  │  │  │        │  ├─ detection_post_process_layer.cc.o.d
│  │  │  │        │  ├─ div_layer.cc.o
│  │  │  │        │  ├─ div_layer.cc.o.d
│  │  │  │        │  ├─ einsum_layer.cc.o
│  │  │  │        │  ├─ einsum_layer.cc.o.d
│  │  │  │        │  ├─ elementwise_layer.cc.o
│  │  │  │        │  ├─ elementwise_layer.cc.o.d
│  │  │  │        │  ├─ elu_layer.cc.o
│  │  │  │        │  ├─ elu_layer.cc.o.d
│  │  │  │        │  ├─ equal_layer.cc.o
│  │  │  │        │  ├─ equal_layer.cc.o.d
│  │  │  │        │  ├─ erf_layer.cc.o
│  │  │  │        │  ├─ erf_layer.cc.o.d
│  │  │  │        │  ├─ exp_layer.cc.o
│  │  │  │        │  ├─ exp_layer.cc.o.d
│  │  │  │        │  ├─ expand_layer.cc.o
│  │  │  │        │  ├─ expand_layer.cc.o.d
│  │  │  │        │  ├─ flatten_layer.cc.o
│  │  │  │        │  ├─ flatten_layer.cc.o.d
│  │  │  │        │  ├─ floor_layer.cc.o
│  │  │  │        │  ├─ floor_layer.cc.o.d
│  │  │  │        │  ├─ gather_layer.cc.o
│  │  │  │        │  ├─ gather_layer.cc.o.d
│  │  │  │        │  ├─ gathernd_layer.cc.o
│  │  │  │        │  ├─ gathernd_layer.cc.o.d
│  │  │  │        │  ├─ gelu_layer.cc.o
│  │  │  │        │  ├─ gelu_layer.cc.o.d
│  │  │  │        │  ├─ gridsample_layer.cc.o
│  │  │  │        │  ├─ gridsample_layer.cc.o.d
│  │  │  │        │  ├─ group_norm_layer.cc.o
│  │  │  │        │  ├─ group_norm_layer.cc.o.d
│  │  │  │        │  ├─ hard_sigmoid_layer.cc.o
│  │  │  │        │  ├─ hard_sigmoid_layer.cc.o.d
│  │  │  │        │  ├─ hard_swish_layer.cc.o
│  │  │  │        │  ├─ hard_swish_layer.cc.o.d
│  │  │  │        │  ├─ hdrguide_layer.cc.o
│  │  │  │        │  ├─ hdrguide_layer.cc.o.d
│  │  │  │        │  ├─ histogram_layer.cc.o
│  │  │  │        │  ├─ histogram_layer.cc.o.d
│  │  │  │        │  ├─ inner_product_layer.cc.o
│  │  │  │        │  ├─ inner_product_layer.cc.o.d
│  │  │  │        │  ├─ instance_norm_layer.cc.o
│  │  │  │        │  ├─ instance_norm_layer.cc.o.d
│  │  │  │        │  ├─ inverse_layer.cc.o
│  │  │  │        │  ├─ inverse_layer.cc.o.d
│  │  │  │        │  ├─ layer_norm_layer.cc.o
│  │  │  │        │  ├─ layer_norm_layer.cc.o.d
│  │  │  │        │  ├─ log_layer.cc.o
│  │  │  │        │  ├─ log_layer.cc.o.d
│  │  │  │        │  ├─ log_sigmoid_layer.cc.o
│  │  │  │        │  ├─ log_sigmoid_layer.cc.o.d
│  │  │  │        │  ├─ lrn_layer.cc.o
│  │  │  │        │  ├─ lrn_layer.cc.o.d
│  │  │  │        │  ├─ lstm_layer.cc.o
│  │  │  │        │  ├─ lstm_layer.cc.o.d
│  │  │  │        │  ├─ mat_mul_layer.cc.o
│  │  │  │        │  ├─ mat_mul_layer.cc.o.d
│  │  │  │        │  ├─ max_layer.cc.o
│  │  │  │        │  ├─ max_layer.cc.o.d
│  │  │  │        │  ├─ min_layer.cc.o
│  │  │  │        │  ├─ min_layer.cc.o.d
│  │  │  │        │  ├─ mul_layer.cc.o
│  │  │  │        │  ├─ mul_layer.cc.o.d
│  │  │  │        │  ├─ multidir_broadcast_layer.cc.o
│  │  │  │        │  ├─ multidir_broadcast_layer.cc.o.d
│  │  │  │        │  ├─ neg_layer.cc.o
│  │  │  │        │  ├─ neg_layer.cc.o.d
│  │  │  │        │  ├─ nonzero_layer.cc.o
│  │  │  │        │  ├─ nonzero_layer.cc.o.d
│  │  │  │        │  ├─ normalize_layer.cc.o
│  │  │  │        │  ├─ normalize_layer.cc.o.d
│  │  │  │        │  ├─ onehot_layer.cc.o
│  │  │  │        │  ├─ onehot_layer.cc.o.d
│  │  │  │        │  ├─ pad_layer.cc.o
│  │  │  │        │  ├─ pad_layer.cc.o.d
│  │  │  │        │  ├─ padv2_layer.cc.o
│  │  │  │        │  ├─ padv2_layer.cc.o.d
│  │  │  │        │  ├─ permute_layer.cc.o
│  │  │  │        │  ├─ permute_layer.cc.o.d
│  │  │  │        │  ├─ pixel_shuffle_layer.cc.o
│  │  │  │        │  ├─ pixel_shuffle_layer.cc.o.d
│  │  │  │        │  ├─ pooling_3d_layer.cc.o
│  │  │  │        │  ├─ pooling_3d_layer.cc.o.d
│  │  │  │        │  ├─ pooling_layer.cc.o
│  │  │  │        │  ├─ pooling_layer.cc.o.d
│  │  │  │        │  ├─ pow_layer.cc.o
│  │  │  │        │  ├─ pow_layer.cc.o.d
│  │  │  │        │  ├─ prelu_layer.cc.o
│  │  │  │        │  ├─ prelu_layer.cc.o.d
│  │  │  │        │  ├─ prior_box_layer.cc.o
│  │  │  │        │  ├─ prior_box_layer.cc.o.d
│  │  │  │        │  ├─ range_layer.cc.o
│  │  │  │        │  ├─ range_layer.cc.o.d
│  │  │  │        │  ├─ reciprocal_layer.cc.o
│  │  │  │        │  ├─ reciprocal_layer.cc.o.d
│  │  │  │        │  ├─ reduce_l1_layer.cc.o
│  │  │  │        │  ├─ reduce_l1_layer.cc.o.d
│  │  │  │        │  ├─ reduce_l2_layer.cc.o
│  │  │  │        │  ├─ reduce_l2_layer.cc.o.d
│  │  │  │        │  ├─ reduce_layer.cc.o
│  │  │  │        │  ├─ reduce_layer.cc.o.d
│  │  │  │        │  ├─ reduce_log_sum_exp_layer.cc.o
│  │  │  │        │  ├─ reduce_log_sum_exp_layer.cc.o.d
│  │  │  │        │  ├─ reduce_log_sum_layer.cc.o
│  │  │  │        │  ├─ reduce_log_sum_layer.cc.o.d
│  │  │  │        │  ├─ reduce_max_layer.cc.o
│  │  │  │        │  ├─ reduce_max_layer.cc.o.d
│  │  │  │        │  ├─ reduce_mean_layer.cc.o
│  │  │  │        │  ├─ reduce_mean_layer.cc.o.d
│  │  │  │        │  ├─ reduce_min_layer.cc.o
│  │  │  │        │  ├─ reduce_min_layer.cc.o.d
│  │  │  │        │  ├─ reduce_prod_layer.cc.o
│  │  │  │        │  ├─ reduce_prod_layer.cc.o.d
│  │  │  │        │  ├─ reduce_sum_layer.cc.o
│  │  │  │        │  ├─ reduce_sum_layer.cc.o.d
│  │  │  │        │  ├─ reduce_sum_square_layer.cc.o
│  │  │  │        │  ├─ reduce_sum_square_layer.cc.o.d
│  │  │  │        │  ├─ reformat_layer.cc.o
│  │  │  │        │  ├─ reformat_layer.cc.o.d
│  │  │  │        │  ├─ relu6_layer.cc.o
│  │  │  │        │  ├─ relu6_layer.cc.o.d
│  │  │  │        │  ├─ relu_layer.cc.o
│  │  │  │        │  ├─ relu_layer.cc.o.d
│  │  │  │        │  ├─ reorg_layer.cc.o
│  │  │  │        │  ├─ reorg_layer.cc.o.d
│  │  │  │        │  ├─ reshape_layer.cc.o
│  │  │  │        │  ├─ reshape_layer.cc.o.d
│  │  │  │        │  ├─ roi_pooling_layer.cc.o
│  │  │  │        │  ├─ roi_pooling_layer.cc.o.d
│  │  │  │        │  ├─ roialign_layer.cc.o
│  │  │  │        │  ├─ roialign_layer.cc.o.d
│  │  │  │        │  ├─ rsqrt_layer.cc.o
│  │  │  │        │  ├─ rsqrt_layer.cc.o.d
│  │  │  │        │  ├─ scale_layer.cc.o
│  │  │  │        │  ├─ scale_layer.cc.o.d
│  │  │  │        │  ├─ scatter_nd_layer.cc.o
│  │  │  │        │  ├─ scatter_nd_layer.cc.o.d
│  │  │  │        │  ├─ selu_layer.cc.o
│  │  │  │        │  ├─ selu_layer.cc.o.d
│  │  │  │        │  ├─ shape_layer.cc.o
│  │  │  │        │  ├─ shape_layer.cc.o.d
│  │  │  │        │  ├─ shuffle_layer.cc.o
│  │  │  │        │  ├─ shuffle_layer.cc.o.d
│  │  │  │        │  ├─ sigmoid_layer.cc.o
│  │  │  │        │  ├─ sigmoid_layer.cc.o.d
│  │  │  │        │  ├─ sign_layer.cc.o
│  │  │  │        │  ├─ sign_layer.cc.o.d
│  │  │  │        │  ├─ signed_mul_layer.cc.o
│  │  │  │        │  ├─ signed_mul_layer.cc.o.d
│  │  │  │        │  ├─ sin_layer.cc.o
│  │  │  │        │  ├─ sin_layer.cc.o.d
│  │  │  │        │  ├─ size_layer.cc.o
│  │  │  │        │  ├─ size_layer.cc.o.d
│  │  │  │        │  ├─ softmax_layer.cc.o
│  │  │  │        │  ├─ softmax_layer.cc.o.d
│  │  │  │        │  ├─ softplus_layer.cc.o
│  │  │  │        │  ├─ softplus_layer.cc.o.d
│  │  │  │        │  ├─ softsign_layer.cc.o
│  │  │  │        │  ├─ softsign_layer.cc.o.d
│  │  │  │        │  ├─ split_layer.cc.o
│  │  │  │        │  ├─ split_layer.cc.o.d
│  │  │  │        │  ├─ splitv_layer.cc.o
│  │  │  │        │  ├─ splitv_layer.cc.o.d
│  │  │  │        │  ├─ sqrt_layer.cc.o
│  │  │  │        │  ├─ sqrt_layer.cc.o.d
│  │  │  │        │  ├─ squared_difference_layer.cc.o
│  │  │  │        │  ├─ squared_difference_layer.cc.o.d
│  │  │  │        │  ├─ squeeze_layer.cc.o
│  │  │  │        │  ├─ squeeze_layer.cc.o.d
│  │  │  │        │  ├─ stride_slice_layer.cc.o
│  │  │  │        │  ├─ stride_slice_layer.cc.o.d
│  │  │  │        │  ├─ stride_slice_v2_layer.cc.o
│  │  │  │        │  ├─ stride_slice_v2_layer.cc.o.d
│  │  │  │        │  ├─ sub_layer.cc.o
│  │  │  │        │  ├─ sub_layer.cc.o.d
│  │  │  │        │  ├─ tan_layer.cc.o
│  │  │  │        │  ├─ tan_layer.cc.o.d
│  │  │  │        │  ├─ tanh_layer.cc.o
│  │  │  │        │  ├─ tanh_layer.cc.o.d
│  │  │  │        │  ├─ tile_layer.cc.o
│  │  │  │        │  ├─ tile_layer.cc.o.d
│  │  │  │        │  ├─ topk_layer.cc.o
│  │  │  │        │  ├─ topk_layer.cc.o.d
│  │  │  │        │  ├─ unsqueeze_layer.cc.o
│  │  │  │        │  ├─ unsqueeze_layer.cc.o.d
│  │  │  │        │  ├─ upsample_layer.cc.o
│  │  │  │        │  ├─ upsample_layer.cc.o.d
│  │  │  │        │  ├─ where_layer.cc.o
│  │  │  │        │  └─ where_layer.cc.o.d
│  │  │  │        ├─ memory_manager
│  │  │  │        │  ├─ blob_1d_memory.cc.o
│  │  │  │        │  ├─ blob_1d_memory.cc.o.d
│  │  │  │        │  ├─ blob_1d_memory_pool.cc.o
│  │  │  │        │  ├─ blob_1d_memory_pool.cc.o.d
│  │  │  │        │  ├─ blob_2d_memory.cc.o
│  │  │  │        │  ├─ blob_2d_memory.cc.o.d
│  │  │  │        │  ├─ blob_2d_memory_pool.cc.o
│  │  │  │        │  ├─ blob_2d_memory_pool.cc.o.d
│  │  │  │        │  ├─ blob_memory.cc.o
│  │  │  │        │  ├─ blob_memory.cc.o.d
│  │  │  │        │  ├─ blob_memory_pool.cc.o
│  │  │  │        │  ├─ blob_memory_pool.cc.o.d
│  │  │  │        │  ├─ blob_memory_pool_factory.cc.o
│  │  │  │        │  ├─ blob_memory_pool_factory.cc.o.d
│  │  │  │        │  ├─ blob_memory_size_info.cc.o
│  │  │  │        │  ├─ blob_memory_size_info.cc.o.d
│  │  │  │        │  ├─ memory_mode_state.cc.o
│  │  │  │        │  ├─ memory_mode_state.cc.o.d
│  │  │  │        │  ├─ memory_mode_state_factory.cc.o
│  │  │  │        │  ├─ memory_mode_state_factory.cc.o.d
│  │  │  │        │  ├─ memory_seperate_assign_strategy.cc.o
│  │  │  │        │  ├─ memory_seperate_assign_strategy.cc.o.d
│  │  │  │        │  ├─ memory_unify_assign_strategy.cc.o
│  │  │  │        │  ├─ memory_unify_assign_strategy.cc.o.d
│  │  │  │        │  ├─ others_memory_mode_state.cc.o
│  │  │  │        │  ├─ others_memory_mode_state.cc.o.d
│  │  │  │        │  ├─ share_one_thread_memory_mode_state.cc.o
│  │  │  │        │  ├─ share_one_thread_memory_mode_state.cc.o.d
│  │  │  │        │  ├─ shared_memory_manager.cc.o
│  │  │  │        │  └─ shared_memory_manager.cc.o.d
│  │  │  │        ├─ optimizer
│  │  │  │        │  ├─ net_optimizer_cbam_fused_pooling.cc.o
│  │  │  │        │  ├─ net_optimizer_cbam_fused_pooling.cc.o.d
│  │  │  │        │  ├─ net_optimizer_cbam_fused_reduce.cc.o
│  │  │  │        │  ├─ net_optimizer_cbam_fused_reduce.cc.o.d
│  │  │  │        │  ├─ net_optimizer_fuse_conv_add.cc.o
│  │  │  │        │  ├─ net_optimizer_fuse_conv_add.cc.o.d
│  │  │  │        │  ├─ net_optimizer_fuse_conv_post.cc.o
│  │  │  │        │  ├─ net_optimizer_fuse_conv_post.cc.o.d
│  │  │  │        │  ├─ net_optimizer_insert_fp16_reformat.cc.o
│  │  │  │        │  ├─ net_optimizer_insert_fp16_reformat.cc.o.d
│  │  │  │        │  ├─ net_optimizer_insert_int8_reformat.cc.o
│  │  │  │        │  ├─ net_optimizer_insert_int8_reformat.cc.o.d
│  │  │  │        │  ├─ net_optimizer_insert_layout_reformat.cc.o
│  │  │  │        │  ├─ net_optimizer_insert_layout_reformat.cc.o.d
│  │  │  │        │  ├─ net_optimizer_manager.cc.o
│  │  │  │        │  ├─ net_optimizer_manager.cc.o.d
│  │  │  │        │  ├─ net_optimizer_remove_layers.cc.o
│  │  │  │        │  └─ net_optimizer_remove_layers.cc.o.d
│  │  │  │        └─ utils
│  │  │  │           ├─ bbox_util.cc.o
│  │  │  │           ├─ bbox_util.cc.o.d
│  │  │  │           ├─ bfp16_utils.cc.o
│  │  │  │           ├─ bfp16_utils.cc.o.d
│  │  │  │           ├─ blob_converter_default.cc.o
│  │  │  │           ├─ blob_converter_default.cc.o.d
│  │  │  │           ├─ blob_converter_internal.cc.o
│  │  │  │           ├─ blob_converter_internal.cc.o.d
│  │  │  │           ├─ blob_dump_utils.cc.o
│  │  │  │           ├─ blob_dump_utils.cc.o.d
│  │  │  │           ├─ blob_memory_size_utils.cc.o
│  │  │  │           ├─ blob_memory_size_utils.cc.o.d
│  │  │  │           ├─ blob_transfer_utils.cc.o
│  │  │  │           ├─ blob_transfer_utils.cc.o.d
│  │  │  │           ├─ cpu_info.cc.o
│  │  │  │           ├─ cpu_info.cc.o.d
│  │  │  │           ├─ cpu_utils.cc.o
│  │  │  │           ├─ cpu_utils.cc.o.d
│  │  │  │           ├─ data_flag_utils.cc.o
│  │  │  │           ├─ data_flag_utils.cc.o.d
│  │  │  │           ├─ data_format_converter.cc.o
│  │  │  │           ├─ data_format_converter.cc.o.d
│  │  │  │           ├─ data_type_utils.cc.o
│  │  │  │           ├─ data_type_utils.cc.o.d
│  │  │  │           ├─ detection_post_process_utils.cc.o
│  │  │  │           ├─ detection_post_process_utils.cc.o.d
│  │  │  │           ├─ dims_function_utils.cc.o
│  │  │  │           ├─ dims_function_utils.cc.o.d
│  │  │  │           ├─ dims_offset_utils.cc.o
│  │  │  │           ├─ dims_offset_utils.cc.o.d
│  │  │  │           ├─ dims_vector_utils.cc.o
│  │  │  │           ├─ dims_vector_utils.cc.o.d
│  │  │  │           ├─ half_utils.cc.o
│  │  │  │           ├─ half_utils.cc.o.d
│  │  │  │           ├─ mat_converter_acc.cc.o
│  │  │  │           ├─ mat_converter_acc.cc.o.d
│  │  │  │           ├─ mat_converter_utils.cc.o
│  │  │  │           ├─ mat_converter_utils.cc.o.d
│  │  │  │           ├─ mat_utils.cc.o
│  │  │  │           ├─ mat_utils.cc.o.d
│  │  │  │           ├─ md5.cc.o
│  │  │  │           ├─ md5.cc.o.d
│  │  │  │           ├─ naive_compute.cc.o
│  │  │  │           ├─ naive_compute.cc.o.d
│  │  │  │           ├─ npu_common_utils.cc.o
│  │  │  │           ├─ npu_common_utils.cc.o.d
│  │  │  │           ├─ pad_utils.cc.o
│  │  │  │           ├─ pad_utils.cc.o.d
│  │  │  │           ├─ pribox_generator_utils.cc.o
│  │  │  │           ├─ pribox_generator_utils.cc.o.d
│  │  │  │           ├─ random_data_utils.cc.o
│  │  │  │           ├─ random_data_utils.cc.o.d
│  │  │  │           ├─ split_utils.cc.o
│  │  │  │           ├─ split_utils.cc.o.d
│  │  │  │           ├─ string_format.cc.o
│  │  │  │           ├─ string_format.cc.o.d
│  │  │  │           ├─ string_utils.cc.o
│  │  │  │           ├─ string_utils.cc.o.d
│  │  │  │           ├─ winograd_generator.cc.o
│  │  │  │           └─ winograd_generator.cc.o.d
│  │  │  └─ progress.marks
│  │  ├─ Makefile
│  │  ├─ cmake_install.cmake
│  │  ├─ libTNN.so
│  │  ├─ libTNN.so.0
│  │  ├─ libTNN.so.0.1.0.0
│  │  └─ source
│  │     └─ tnn
│  │        └─ device
│  │           ├─ cpu
│  │           │  ├─ CMakeFiles
│  │           │  │  ├─ CMakeDirectoryInformation.cmake
│  │           │  │  ├─ TNNCpu.dir
│  │           │  │  │  ├─ DependInfo.cmake
│  │           │  │  │  ├─ acc
│  │           │  │  │  │  ├─ compute
│  │           │  │  │  │  │  ├─ compute_elewise.cc.o
│  │           │  │  │  │  │  ├─ compute_elewise.cc.o.d
│  │           │  │  │  │  │  ├─ compute_int8.cc.o
│  │           │  │  │  │  │  └─ compute_int8.cc.o.d
│  │           │  │  │  │  ├─ cpu__histogram_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu__histogram_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_abs_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_abs_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_acos_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_acos_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_add_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_add_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_arg_max_or_min_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_arg_max_or_min_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_asin_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_asin_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_atan_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_atan_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_batch_norm_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_batch_norm_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_bias_add_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_bias_add_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_binary_op_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_binary_op_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_bitshift_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_bitshift_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_cast_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_cast_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_ceil_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_ceil_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_clip_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_clip_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_concat_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_concat_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_const_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_const_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_constantofshape_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_constantofshape_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_conv_1d_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_conv_1d_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_conv_3d_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_conv_3d_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_conv_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_conv_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_cos_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_cos_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_deconv_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_deconv_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_detection_output_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_detection_output_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_detection_post_process_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_detection_post_process_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_div_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_div_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_einsum_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_einsum_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_elu_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_elu_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_equal_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_equal_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_erf_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_erf_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_exp_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_exp_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_expand_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_expand_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_flatten_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_flatten_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_floor_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_floor_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_gather_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_gather_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_gathernd_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_gathernd_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_gelu_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_gelu_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_gridsample_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_gridsample_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_group_norm_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_group_norm_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_hard_sigmoid_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_hard_sigmoid_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_hard_swish_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_hard_swish_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_hdrguide_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_hdrguide_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_inner_product_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_inner_product_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_instance_norm_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_instance_norm_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_inverse_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_inverse_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_layer_norm_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_layer_norm_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_log_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_log_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_log_sigmoid_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_log_sigmoid_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_lrn_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_lrn_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_lstm_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_lstm_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_mat_mul_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_mat_mul_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_max_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_max_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_min_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_min_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_mul_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_mul_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_neg_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_neg_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_nonzero_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_nonzero_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_normalize_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_normalize_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_onehot_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_onehot_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_pad_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_pad_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_padv2_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_padv2_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_permute_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_permute_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_pixel_shuffle_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_pixel_shuffle_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_pool_3d_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_pool_3d_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_pool_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_pool_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_pow_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_pow_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_prelu_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_prelu_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_prior_box_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_prior_box_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_range_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_range_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reciprocal_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reciprocal_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_l1_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_l1_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_l2_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_l2_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_log_sum_exp_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_log_sum_exp_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_log_sum_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_log_sum_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_max_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_max_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_mean_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_mean_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_min_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_min_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_prod_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_prod_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_sum_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_sum_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reduce_sum_square_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reduce_sum_square_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reformat_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reformat_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_relu6_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_relu6_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_relu_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_relu_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reorg_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reorg_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_reshape_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_reshape_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_roialign_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_roialign_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_rsqrt_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_rsqrt_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_scale_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_scale_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_scatter_nd_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_scatter_nd_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_selu_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_selu_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_shape_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_shape_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_shuffle_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_shuffle_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_sigmoid_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_sigmoid_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_sign_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_sign_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_signed_mul_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_signed_mul_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_sin_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_sin_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_size_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_size_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_softmax_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_softmax_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_softplus_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_softplus_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_splitv_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_splitv_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_sqrt_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_sqrt_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_squared_difference_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_squared_difference_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_squeeze_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_squeeze_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_stride_slice_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_stride_slice_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_stride_slice_v2_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_stride_slice_v2_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_sub_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_sub_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_tan_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_tan_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_tanh_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_tanh_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_tile_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_tile_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_topk_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_topk_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_unary_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_unary_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_unsqueeze_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_unsqueeze_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_upsample_layer_acc.cc.o
│  │           │  │  │  │  ├─ cpu_upsample_layer_acc.cc.o.d
│  │           │  │  │  │  ├─ cpu_where_layer_acc.cc.o
│  │           │  │  │  │  └─ cpu_where_layer_acc.cc.o.d
│  │           │  │  │  ├─ build.make
│  │           │  │  │  ├─ cmake_clean.cmake
│  │           │  │  │  ├─ compiler_depend.internal
│  │           │  │  │  ├─ compiler_depend.make
│  │           │  │  │  ├─ compiler_depend.ts
│  │           │  │  │  ├─ cpu_blob_converter.cc.o
│  │           │  │  │  ├─ cpu_blob_converter.cc.o.d
│  │           │  │  │  ├─ cpu_context.cc.o
│  │           │  │  │  ├─ cpu_context.cc.o.d
│  │           │  │  │  ├─ cpu_device.cc.o
│  │           │  │  │  ├─ cpu_device.cc.o.d
│  │           │  │  │  ├─ cpu_mat_converter.cc.o
│  │           │  │  │  ├─ cpu_mat_converter.cc.o.d
│  │           │  │  │  ├─ cpu_mat_util.cc.o
│  │           │  │  │  ├─ cpu_mat_util.cc.o.d
│  │           │  │  │  ├─ depend.make
│  │           │  │  │  ├─ flags.make
│  │           │  │  │  └─ progress.make
│  │           │  │  └─ progress.marks
│  │           │  ├─ Makefile
│  │           │  └─ cmake_install.cmake
│  │           └─ opencl
│  │              ├─ CMakeFiles
│  │              │  ├─ CMakeDirectoryInformation.cmake
│  │              │  ├─ TNNOpenCL.dir
│  │              │  │  ├─ DependInfo.cmake
│  │              │  │  ├─ acc
│  │              │  │  │  ├─ convolution
│  │              │  │  │  │  ├─ opencl_conv_layer_1x1_acc.cc.o
│  │              │  │  │  │  ├─ opencl_conv_layer_1x1_acc.cc.o.d
│  │              │  │  │  │  ├─ opencl_conv_layer_acc.cc.o
│  │              │  │  │  │  ├─ opencl_conv_layer_acc.cc.o.d
│  │              │  │  │  │  ├─ opencl_conv_layer_acc_impl.cc.o
│  │              │  │  │  │  ├─ opencl_conv_layer_acc_impl.cc.o.d
│  │              │  │  │  │  ├─ opencl_conv_layer_common_acc.cc.o
│  │              │  │  │  │  ├─ opencl_conv_layer_common_acc.cc.o.d
│  │              │  │  │  │  ├─ opencl_conv_layer_depthwise_acc.cc.o
│  │              │  │  │  │  ├─ opencl_conv_layer_depthwise_acc.cc.o.d
│  │              │  │  │  │  ├─ opencl_conv_layer_winograd_acc.cc.o
│  │              │  │  │  │  └─ opencl_conv_layer_winograd_acc.cc.o.d
│  │              │  │  │  ├─ deconvolution
│  │              │  │  │  │  ├─ opencl_deconv_layer_acc.cc.o
│  │              │  │  │  │  ├─ opencl_deconv_layer_acc.cc.o.d
│  │              │  │  │  │  ├─ opencl_deconv_layer_acc_impl.cc.o
│  │              │  │  │  │  ├─ opencl_deconv_layer_acc_impl.cc.o.d
│  │              │  │  │  │  ├─ opencl_deconv_layer_common_acc.cc.o
│  │              │  │  │  │  ├─ opencl_deconv_layer_common_acc.cc.o.d
│  │              │  │  │  │  ├─ opencl_deconv_layer_depthwise_acc.cc.o
│  │              │  │  │  │  └─ opencl_deconv_layer_depthwise_acc.cc.o.d
│  │              │  │  │  ├─ opencl_abs_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_abs_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_acos_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_acos_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_add_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_add_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_arg_max_or_min_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_arg_max_or_min_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_asin_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_asin_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_atan_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_atan_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_batch_norm_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_batch_norm_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_binary_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_binary_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_cast_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_cast_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_ceil_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_ceil_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_clip_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_clip_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_concat_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_concat_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_cos_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_cos_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_cpu_adapter_acc.cc.o
│  │              │  │  │  ├─ opencl_cpu_adapter_acc.cc.o.d
│  │              │  │  │  ├─ opencl_div_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_div_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_elu_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_elu_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_exp_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_exp_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_expand_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_expand_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_floor_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_floor_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_gather_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_gather_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_gridsample_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_gridsample_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_hard_sigmoid_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_hard_sigmoid_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_hard_swish_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_hard_swish_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_hdr_guide_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_hdr_guide_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_inner_product_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_inner_product_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_instance_norm_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_instance_norm_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_inverse_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_inverse_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_log_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_log_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_logsigmoid_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_logsigmoid_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_lstm_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_lstm_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_mat_mul_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_mat_mul_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_max_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_max_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_min_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_min_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_mul_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_mul_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_neg_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_neg_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_normalize_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_normalize_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_pad_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_pad_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_padv2_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_padv2_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_permute_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_permute_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_pixel_shuffle_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_pixel_shuffle_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_pooling_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_pooling_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_pow_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_pow_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_prelu_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_prelu_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_prior_box_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_prior_box_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reciprocal_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reciprocal_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_l1_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_l1_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_l2_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_l2_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_log_sum_exp_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_log_sum_exp_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_log_sum_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_log_sum_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_max_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_max_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_mean_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_mean_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_min_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_min_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_prod_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_prod_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_sum_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_sum_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reduce_sum_square_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reduce_sum_square_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reformat_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reformat_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_relu6_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_relu6_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_relu_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_relu_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reorg_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reorg_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_reshape_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_reshape_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_selu_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_selu_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_shuffle_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_shuffle_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_sigmoid_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_sigmoid_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_sign_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_sign_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_signed_mul_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_signed_mul_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_sin_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_sin_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_softmax_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_softmax_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_softplus_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_softplus_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_split_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_split_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_splitv_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_splitv_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_sqrt_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_sqrt_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_squeeze_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_squeeze_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_stride_slice_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_stride_slice_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_stride_slice_v2_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_stride_slice_v2_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_sub_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_sub_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_tan_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_tan_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_tanh_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_tanh_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_tile_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_tile_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_unary_layer_acc.cc.o
│  │              │  │  │  ├─ opencl_unary_layer_acc.cc.o.d
│  │              │  │  │  ├─ opencl_upsample_layer_acc.cc.o
│  │              │  │  │  └─ opencl_upsample_layer_acc.cc.o.d
│  │              │  │  ├─ build.make
│  │              │  │  ├─ cl
│  │              │  │  │  ├─ opencl_program.cc.o
│  │              │  │  │  └─ opencl_program.cc.o.d
│  │              │  │  ├─ cmake_clean.cmake
│  │              │  │  ├─ compiler_depend.internal
│  │              │  │  ├─ compiler_depend.make
│  │              │  │  ├─ compiler_depend.ts
│  │              │  │  ├─ depend.make
│  │              │  │  ├─ flags.make
│  │              │  │  ├─ imagebuffer_convertor.cc.o
│  │              │  │  ├─ imagebuffer_convertor.cc.o.d
│  │              │  │  ├─ opencl_blob_converter.cc.o
│  │              │  │  ├─ opencl_blob_converter.cc.o.d
│  │              │  │  ├─ opencl_context.cc.o
│  │              │  │  ├─ opencl_context.cc.o.d
│  │              │  │  ├─ opencl_device.cc.o
│  │              │  │  ├─ opencl_device.cc.o.d
│  │              │  │  ├─ opencl_mat_converter.cc.o
│  │              │  │  ├─ opencl_mat_converter.cc.o.d
│  │              │  │  ├─ opencl_memory.cc.o
│  │              │  │  ├─ opencl_memory.cc.o.d
│  │              │  │  ├─ opencl_runtime.cc.o
│  │              │  │  ├─ opencl_runtime.cc.o.d
│  │              │  │  ├─ opencl_utils.cc.o
│  │              │  │  ├─ opencl_utils.cc.o.d
│  │              │  │  ├─ opencl_wrapper.cc.o
│  │              │  │  ├─ opencl_wrapper.cc.o.d
│  │              │  │  └─ progress.make
│  │              │  └─ progress.marks
│  │              ├─ Makefile
│  │              └─ cmake_install.cmake
│  ├─ base_build
│  │  ├─ CMakeFiles
│  │  │  ├─ CMakeDirectoryInformation.cmake
│  │  │  ├─ base_utils.dir
│  │  │  │  ├─ DependInfo.cmake
│  │  │  │  ├─ build.make
│  │  │  │  ├─ cmake_clean.cmake
│  │  │  │  ├─ cmake_clean_target.cmake
│  │  │  │  ├─ compiler_depend.internal
│  │  │  │  ├─ compiler_depend.make
│  │  │  │  ├─ compiler_depend.ts
│  │  │  │  ├─ depend.make
│  │  │  │  ├─ flags.make
│  │  │  │  ├─ link.txt
│  │  │  │  ├─ progress.make
│  │  │  │  └─ src
│  │  │  │     ├─ debug.cpp.o
│  │  │  │     ├─ debug.cpp.o.d
│  │  │  │     ├─ file_utils.cpp.o
│  │  │  │     ├─ file_utils.cpp.o.d
│  │  │  │     ├─ filter
│  │  │  │     │  ├─ kalman_filter.cpp.o
│  │  │  │     │  ├─ kalman_filter.cpp.o.d
│  │  │  │     │  ├─ mean_filter.cpp.o
│  │  │  │     │  ├─ mean_filter.cpp.o.d
│  │  │  │     │  ├─ tracking_flow.cpp.o
│  │  │  │     │  └─ tracking_flow.cpp.o.d
│  │  │  │     ├─ image_utils.cpp.o
│  │  │  │     ├─ image_utils.cpp.o.d
│  │  │  │     ├─ math_utils.cpp.o
│  │  │  │     └─ math_utils.cpp.o.d
│  │  │  └─ progress.marks
│  │  ├─ Makefile
│  │  ├─ cmake_install.cmake
│  │  └─ libbase_utils.a
│  ├─ cmake_install.cmake
│  └─ libdmcv.so
├─ gitignore.txt
└─ lib
   ├─ 3rdparty
   │  ├─ TNN
   │  │  ├─ .clang-format
   │  │  ├─ .github
   │  │  │  ├─ ISSUE_TEMPLATE
   │  │  │  │  ├─ feature_request.md
   │  │  │  │  ├─ model-converter-issue.md
   │  │  │  │  └─ tnn-inference-issue.md
   │  │  │  ├─ release-drafter.yml
   │  │  │  └─ workflows
   │  │  │     ├─ android-arm-cpu.yml
   │  │  │     ├─ ios-cpu.yml
   │  │  │     ├─ linux-x86-cpu-gcc.yml
   │  │  │     ├─ macos-x64-cpu.yml
   │  │  │     ├─ release-drafter.yml
   │  │  │     └─ release.yml
   │  │  ├─ .gitignore
   │  │  ├─ .travis.yml
   │  │  ├─ CMakeLists.txt
   │  │  ├─ Dockerfile
   │  │  ├─ LICENSE
   │  │  ├─ README.md
   │  │  ├─ README_CH.md
   │  │  ├─ RELEASE.md
   │  │  ├─ TNN-QQ.png
   │  │  ├─ TNN.png
   │  │  ├─ _config.yml
   │  │  ├─ benchmark
   │  │  │  ├─ .gitignore
   │  │  │  ├─ benchmark-model
   │  │  │  │  ├─ densenet.tnnproto
   │  │  │  │  ├─ inception_v3.tnnproto
   │  │  │  │  ├─ inception_v4.tnnproto
   │  │  │  │  ├─ mobilenet_v1.tnnproto
   │  │  │  │  ├─ mobilenet_v2.tnnproto
   │  │  │  │  ├─ quant_inception_v3.tnnproto
   │  │  │  │  ├─ quant_mobilenet_v1.tnnproto
   │  │  │  │  ├─ quant_mobilenet_v2.tnnproto
   │  │  │  │  ├─ quant_resnet50.tnnproto
   │  │  │  │  ├─ quant_squeezenet_v1.0.tnnproto
   │  │  │  │  ├─ quant_squeezenet_v1.1.tnnproto
   │  │  │  │  ├─ resnet50.tnnproto
   │  │  │  │  ├─ shufflenet_v2.tnnproto
   │  │  │  │  ├─ squeezenet_v1.0.tnnproto
   │  │  │  │  └─ squeezenet_v1.1.tnnproto
   │  │  │  ├─ benchmark_android
   │  │  │  │  ├─ .gitignore
   │  │  │  │  ├─ README.md
   │  │  │  │  ├─ benchmark-release.apk
   │  │  │  │  ├─ benchmark_app
   │  │  │  │  │  ├─ .gitignore
   │  │  │  │  │  ├─ benchmark
   │  │  │  │  │  │  ├─ build.gradle
   │  │  │  │  │  │  ├─ gradle
   │  │  │  │  │  │  │  └─ wrapper
   │  │  │  │  │  │  │     ├─ gradle-wrapper.jar
   │  │  │  │  │  │  │     └─ gradle-wrapper.properties
   │  │  │  │  │  │  ├─ gradlew
   │  │  │  │  │  │  ├─ gradlew.bat
   │  │  │  │  │  │  ├─ proguard-rules.pro
   │  │  │  │  │  │  └─ src
   │  │  │  │  │  │     └─ main
   │  │  │  │  │  │        ├─ AndroidManifest.xml
   │  │  │  │  │  │        ├─ java
   │  │  │  │  │  │        │  └─ com
   │  │  │  │  │  │        │     └─ tencent
   │  │  │  │  │  │        │        └─ tnn
   │  │  │  │  │  │        │           └─ benchmark
   │  │  │  │  │  │        │              ├─ BenchmarkModel.java
   │  │  │  │  │  │        │              ├─ FileUtils.java
   │  │  │  │  │  │        │              └─ MainActivity.java
   │  │  │  │  │  │        ├─ jni
   │  │  │  │  │  │        │  └─ cc
   │  │  │  │  │  │        │     ├─ benchmark_model_jni.cc
   │  │  │  │  │  │        │     └─ benchmark_model_jni.h
   │  │  │  │  │  │        └─ res
   │  │  │  │  │  │           ├─ drawable
   │  │  │  │  │  │           │  └─ tnn.png
   │  │  │  │  │  │           ├─ ic_launcher.png
   │  │  │  │  │  │           ├─ layout
   │  │  │  │  │  │           │  └─ activity_main.xml
   │  │  │  │  │  │           ├─ mipmap-hdpi
   │  │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │  │           ├─ mipmap-ldpi
   │  │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │  │           ├─ mipmap-mdpi
   │  │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │  │           ├─ mipmap-xhdpi
   │  │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │  │           ├─ mipmap-xxhdpi
   │  │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │  │           └─ mipmap-xxxhdpi
   │  │  │  │  │  │              └─ ic_launcher.png
   │  │  │  │  │  ├─ build.gradle
   │  │  │  │  │  ├─ gradle.properties
   │  │  │  │  │  ├─ gradle
   │  │  │  │  │  │  └─ wrapper
   │  │  │  │  │  │     ├─ gradle-wrapper.jar
   │  │  │  │  │  │     └─ gradle-wrapper.properties
   │  │  │  │  │  ├─ gradlew
   │  │  │  │  │  ├─ gradlew.bat
   │  │  │  │  │  └─ settings.gradle
   │  │  │  │  ├─ benchmark_layer.sh
   │  │  │  │  └─ benchmark_models.sh
   │  │  │  ├─ benchmark_armlinux
   │  │  │  │  └─ benchmark_models.sh
   │  │  │  ├─ benchmark_cuda_linux
   │  │  │  │  └─ benchmark_models.sh
   │  │  │  ├─ benchmark_ios
   │  │  │  │  ├─ benchmark.xcodeproj
   │  │  │  │  │  ├─ project.pbxproj
   │  │  │  │  │  ├─ project.xcworkspace
   │  │  │  │  │  │  ├─ contents.xcworkspacedata
   │  │  │  │  │  │  └─ xcshareddata
   │  │  │  │  │  │     └─ IDEWorkspaceChecks.plist
   │  │  │  │  │  ├─ xcshareddata
   │  │  │  │  │  │  └─ xcschemes
   │  │  │  │  │  │     └─ benchmark.xcscheme
   │  │  │  │  │  └─ xcuserdata
   │  │  │  │  │     └─ darrenyao.xcuserdatad
   │  │  │  │  │        └─ xcdebugger
   │  │  │  │  │           └─ Breakpoints_v2.xcbkptlist
   │  │  │  │  └─ benchmark
   │  │  │  │     ├─ AppDelegate.h
   │  │  │  │     ├─ AppDelegate.m
   │  │  │  │     ├─ Assets.xcassets
   │  │  │  │     │  ├─ AppIcon.appiconset
   │  │  │  │     │  │  └─ Contents.json
   │  │  │  │     │  └─ Contents.json
   │  │  │  │     ├─ Base.lproj
   │  │  │  │     │  ├─ LaunchScreen.storyboard
   │  │  │  │     │  └─ Main.storyboard
   │  │  │  │     ├─ BenchmarkController.h
   │  │  │  │     ├─ BenchmarkController.mm
   │  │  │  │     ├─ BenchmarkListController.h
   │  │  │  │     ├─ BenchmarkListController.mm
   │  │  │  │     ├─ Info.plist
   │  │  │  │     ├─ RootNavController.h
   │  │  │  │     ├─ RootNavController.mm
   │  │  │  │     ├─ SceneDelegate.h
   │  │  │  │     ├─ SceneDelegate.m
   │  │  │  │     └─ main.m
   │  │  │  ├─ benchmark_linux
   │  │  │  │  ├─ benchmark_layer.sh
   │  │  │  │  └─ benchmark_models.sh
   │  │  │  ├─ benchmark_windows
   │  │  │  │  └─ benchmark_models.bat
   │  │  │  └─ benchmark_x86_linux
   │  │  │     └─ benchmark_models.sh
   │  │  ├─ build_linux_native
   │  │  │  ├─ libTNN.so.0
   │  │  │  ├─ libTNN.so.0.1.0.0
   │  │  │  ├─ test
   │  │  │  │  └─ TNNTest
   │  │  │  └─ third_party
   │  │  │     └─ gflags
   │  │  │        ├─ gflags-config-install.cmake
   │  │  │        ├─ gflags-config-version.cmake
   │  │  │        ├─ gflags-config.cmake
   │  │  │        ├─ gflags-targets.cmake
   │  │  │        ├─ gflags.pc
   │  │  │        └─ include
   │  │  │           └─ gflags
   │  │  │              ├─ config.h
   │  │  │              ├─ gflags.h
   │  │  │              ├─ gflags_completions.h
   │  │  │              └─ gflags_declare.h
   │  │  ├─ cmake
   │  │  │  └─ macros.cmake
   │  │  ├─ doc
   │  │  │  ├─ benchmark_data.md
   │  │  │  ├─ cn
   │  │  │  │  ├─ development
   │  │  │  │  │  ├─ add_op.md
   │  │  │  │  │  ├─ architecture.md
   │  │  │  │  │  ├─ contributing.md
   │  │  │  │  │  ├─ model_check.md
   │  │  │  │  │  ├─ profiling.md
   │  │  │  │  │  ├─ resource
   │  │  │  │  │  │  ├─ android_profiling.jpg
   │  │  │  │  │  │  ├─ ios_add_account_benchmark.jpg
   │  │  │  │  │  │  ├─ ios_benchmark_result.jpg
   │  │  │  │  │  │  ├─ ios_set_account.jpg
   │  │  │  │  │  │  ├─ ios_set_bundleid_benchmark.jpg
   │  │  │  │  │  │  ├─ ios_verify_certificate_benchmark.jpg
   │  │  │  │  │  │  └─ opencl_profiling.jpg
   │  │  │  │  │  └─ unit_test.md
   │  │  │  │  ├─ faq.md
   │  │  │  │  ├─ front_page.md
   │  │  │  │  ├─ get_started.md
   │  │  │  │  ├─ imgs
   │  │  │  │  │  ├─ blob_memory.png
   │  │  │  │  │  ├─ device.png
   │  │  │  │  │  ├─ device_factory.png
   │  │  │  │  │  ├─ group.png
   │  │  │  │  │  ├─ model_align.png
   │  │  │  │  │  ├─ model_reinterpreter.png
   │  │  │  │  │  ├─ roadmap.jpg
   │  │  │  │  │  └─ tnn_architect.jpg
   │  │  │  │  ├─ jobs.md
   │  │  │  │  ├─ model_align.md
   │  │  │  │  └─ user
   │  │  │  │     ├─ api.md
   │  │  │  │     ├─ caffe2tnn.md
   │  │  │  │     ├─ compile.md
   │  │  │  │     ├─ convert.md
   │  │  │  │     ├─ demo.md
   │  │  │  │     ├─ ncnn.md
   │  │  │  │     ├─ onnx2tnn.md
   │  │  │  │     ├─ openvino.md
   │  │  │  │     ├─ quantization.md
   │  │  │  │     ├─ resource
   │  │  │  │     │  ├─ android_face_detector_image.jpg
   │  │  │  │     │  ├─ android_face_detector_stream.jpg
   │  │  │  │     │  ├─ android_image_classify.jpg
   │  │  │  │     │  ├─ convert.png
   │  │  │  │     │  ├─ face_detector.jpg
   │  │  │  │     │  ├─ image_classify.jpg
   │  │  │  │     │  ├─ ios_add_account_demo.jpg
   │  │  │  │     │  ├─ ios_add_framework.jpg
   │  │  │  │     │  ├─ ios_add_framework_from_files.jpg
   │  │  │  │     │  ├─ ios_framework_notembed.jpg
   │  │  │  │     │  ├─ ios_framework_search_path.jpg
   │  │  │  │     │  ├─ ios_set_account.jpg
   │  │  │  │     │  ├─ ios_set_bundleid_demo.jpg
   │  │  │  │     │  ├─ ios_verify_certificate_demo.jpg
   │  │  │  │     │  └─ tnn-netron.jpg
   │  │  │  │     ├─ roadmap.md
   │  │  │  │     ├─ support.md
   │  │  │  │     ├─ support_tflite_mode.md
   │  │  │  │     ├─ tech_solution.md
   │  │  │  │     ├─ test.md
   │  │  │  │     ├─ tf2tnn.md
   │  │  │  │     ├─ tflite2tnn.md
   │  │  │  │     └─ tnn2mem.md
   │  │  │  ├─ conf.py
   │  │  │  ├─ en
   │  │  │  │  ├─ development
   │  │  │  │  │  ├─ add_op_en.md
   │  │  │  │  │  ├─ architecture_en.md
   │  │  │  │  │  ├─ contributing_en.md
   │  │  │  │  │  ├─ model_check_en.md
   │  │  │  │  │  ├─ profiling_en.md
   │  │  │  │  │  ├─ resource
   │  │  │  │  │  │  ├─ android_profiling.jpg
   │  │  │  │  │  │  ├─ ios_add_account_benchmark.jpg
   │  │  │  │  │  │  ├─ ios_benchmark_result.jpg
   │  │  │  │  │  │  ├─ ios_set_account.jpg
   │  │  │  │  │  │  ├─ ios_set_bundleid_benchmark.jpg
   │  │  │  │  │  │  ├─ ios_verify_certificate_benchmark.jpg
   │  │  │  │  │  │  └─ opencl_profiling.jpg
   │  │  │  │  │  └─ unit_test_en.md
   │  │  │  │  ├─ faq_en.md
   │  │  │  │  ├─ front_page_en.md
   │  │  │  │  ├─ get_started_en.md
   │  │  │  │  ├─ imgs
   │  │  │  │  │  └─ model_align.png
   │  │  │  │  ├─ jobs_en.md
   │  │  │  │  ├─ model_align_en.md
   │  │  │  │  └─ user
   │  │  │  │     ├─ api_en.md
   │  │  │  │     ├─ caffe2tnn_en.md
   │  │  │  │     ├─ compile_en.md
   │  │  │  │     ├─ convert_en.md
   │  │  │  │     ├─ demo_en.md
   │  │  │  │     ├─ ncnn_en.md
   │  │  │  │     ├─ onnx2tnn_en.md
   │  │  │  │     ├─ openvino_en.md
   │  │  │  │     ├─ quantization_en.md
   │  │  │  │     ├─ support_en.md
   │  │  │  │     ├─ support_tflite_mode_en.md
   │  │  │  │     ├─ tech_solution_en.md
   │  │  │  │     ├─ test_en.md
   │  │  │  │     ├─ tf2tnn_en.md
   │  │  │  │     └─ tflite2tnn_en.md
   │  │  │  ├─ index.rst
   │  │  │  ├─ make.bat
   │  │  │  └─ requirements.txt
   │  │  ├─ examples
   │  │  │  ├─ .gitignore
   │  │  │  ├─ android
   │  │  │  │  ├─ .gitignore
   │  │  │  │  ├─ build.gradle
   │  │  │  │  ├─ demo
   │  │  │  │  │  ├─ .gitignore
   │  │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  │  ├─ build.gradle
   │  │  │  │  │  ├─ gradle
   │  │  │  │  │  │  └─ wrapper
   │  │  │  │  │  │     ├─ gradle-wrapper.jar
   │  │  │  │  │  │     └─ gradle-wrapper.properties
   │  │  │  │  │  ├─ gradlew
   │  │  │  │  │  ├─ gradlew.bat
   │  │  │  │  │  ├─ proguard-rules.pro
   │  │  │  │  │  └─ src
   │  │  │  │  │     └─ main
   │  │  │  │  │        ├─ AndroidManifest.xml
   │  │  │  │  │        ├─ assets
   │  │  │  │  │        │  ├─ 004545.jpg
   │  │  │  │  │        │  ├─ blazeface_anchors.txt
   │  │  │  │  │        │  ├─ car.png
   │  │  │  │  │        │  ├─ dog.png
   │  │  │  │  │        │  ├─ dog_cropped.jpg
   │  │  │  │  │        │  ├─ mean_pts_phase1.txt
   │  │  │  │  │        │  ├─ mean_pts_phase2.txt
   │  │  │  │  │        │  ├─ synset.txt
   │  │  │  │  │        │  ├─ test_blazeface.jpg
   │  │  │  │  │        │  ├─ test_face.jpg
   │  │  │  │  │        │  ├─ test_ocr.jpg
   │  │  │  │  │        │  └─ tiger_cat.jpg
   │  │  │  │  │        ├─ java
   │  │  │  │  │        │  └─ com
   │  │  │  │  │        │     └─ tencent
   │  │  │  │  │        │        └─ tnn
   │  │  │  │  │        │           └─ demo
   │  │  │  │  │        │              ├─ BlazeFaceDetector.java
   │  │  │  │  │        │              ├─ DeviceConst.java
   │  │  │  │  │        │              ├─ FaceAlign.java
   │  │  │  │  │        │              ├─ FaceDetector.java
   │  │  │  │  │        │              ├─ FaceInfo.java
   │  │  │  │  │        │              ├─ FileUtils.java
   │  │  │  │  │        │              ├─ FpsCounter.java
   │  │  │  │  │        │              ├─ HairSegmentation.java
   │  │  │  │  │        │              ├─ Helper.java
   │  │  │  │  │        │              ├─ ImageBlazeFaceDetector
   │  │  │  │  │        │              │  ├─ ImageBlazeFaceDetectActivity.java
   │  │  │  │  │        │              │  └─ ImageBlazeFaceDetectFragment.java
   │  │  │  │  │        │              ├─ ImageClassify.java
   │  │  │  │  │        │              ├─ ImageClassifyDetector
   │  │  │  │  │        │              │  ├─ ImageClassifyDetectActivity.java
   │  │  │  │  │        │              │  └─ ImageClassifyDetectFragment.java
   │  │  │  │  │        │              ├─ ImageFaceDetector
   │  │  │  │  │        │              │  ├─ ImageFaceDetectActivity.java
   │  │  │  │  │        │              │  └─ ImageFaceDetectFragment.java
   │  │  │  │  │        │              ├─ ImageInfo.java
   │  │  │  │  │        │              ├─ ImageOCRDetector
   │  │  │  │  │        │              │  ├─ ImageOCRDetectActivity.java
   │  │  │  │  │        │              │  └─ ImageOCRDetectFragment.java
   │  │  │  │  │        │              ├─ ImageObjectDetector
   │  │  │  │  │        │              │  ├─ ImageObjectDetectActivity.java
   │  │  │  │  │        │              │  └─ ImageObjectDetectFragment.java
   │  │  │  │  │        │              ├─ ImageObjectDetectorSSD
   │  │  │  │  │        │              │  ├─ ImageObjectDetectSSDActivity.java
   │  │  │  │  │        │              │  └─ ImageObjectDetectSSDFragment.java
   │  │  │  │  │        │              ├─ MainActivity.java
   │  │  │  │  │        │              ├─ OCRDetector.java
   │  │  │  │  │        │              ├─ ObjectDetector.java
   │  │  │  │  │        │              ├─ ObjectDetectorSSD.java
   │  │  │  │  │        │              ├─ ObjectInfo.java
   │  │  │  │  │        │              ├─ PoseDetectLandmark.java
   │  │  │  │  │        │              ├─ SkeletonDetector.java
   │  │  │  │  │        │              ├─ StreamBlazeFaceAlign
   │  │  │  │  │        │              │  ├─ StreamBlazeFaceAlignActivity.java
   │  │  │  │  │        │              │  └─ StreamBlazeFaceAlignFragment.java
   │  │  │  │  │        │              ├─ StreamBlazeFaceDetector
   │  │  │  │  │        │              │  ├─ StreamBlazeFaceDetectActivity.java
   │  │  │  │  │        │              │  └─ StreamBlazeFaceDetectFragment.java
   │  │  │  │  │        │              ├─ StreamFaceDetector
   │  │  │  │  │        │              │  ├─ StreamFaceDetectActivity.java
   │  │  │  │  │        │              │  └─ StreamFaceDetectFragment.java
   │  │  │  │  │        │              ├─ StreamHairSegmentation
   │  │  │  │  │        │              │  ├─ StreamHairSegmentationActivity.java
   │  │  │  │  │        │              │  └─ StreamHairSegmentationFragment.java
   │  │  │  │  │        │              ├─ StreamOCRDetector
   │  │  │  │  │        │              │  ├─ StreamOCRDetectActivity.java
   │  │  │  │  │        │              │  └─ StreamOCRDetectFragment.java
   │  │  │  │  │        │              ├─ StreamObjectDetector
   │  │  │  │  │        │              │  ├─ StreamObjectDetectActivity.java
   │  │  │  │  │        │              │  └─ StreamObjectDetectFragment.java
   │  │  │  │  │        │              ├─ StreamObjectDetectorSSD
   │  │  │  │  │        │              │  ├─ StreamObjectDetectSSDActivity.java
   │  │  │  │  │        │              │  └─ StreamObjectDetectSSDFragment.java
   │  │  │  │  │        │              ├─ StreamPoseDetectLandmark
   │  │  │  │  │        │              │  ├─ StreamPoseDetectLandmarkActivity.java
   │  │  │  │  │        │              │  └─ StreamPoseDetectLandmarkFragment.java
   │  │  │  │  │        │              ├─ StreamSkeletonDetector
   │  │  │  │  │        │              │  ├─ StreamSkeletonDetectActivity.java
   │  │  │  │  │        │              │  └─ StreamSkeletonDetectFragment.java
   │  │  │  │  │        │              ├─ TNNLib.java
   │  │  │  │  │        │              └─ common
   │  │  │  │  │        │                 ├─ activity
   │  │  │  │  │        │                 │  └─ DemoBaseActivity.java
   │  │  │  │  │        │                 ├─ component
   │  │  │  │  │        │                 │  ├─ CameraSetting.java
   │  │  │  │  │        │                 │  ├─ CustomDialog.java
   │  │  │  │  │        │                 │  ├─ DrawView.java
   │  │  │  │  │        │                 │  ├─ PreviewFrameLayout.java
   │  │  │  │  │        │                 │  └─ TitleBar.java
   │  │  │  │  │        │                 ├─ fragment
   │  │  │  │  │        │                 │  └─ BaseFragment.java
   │  │  │  │  │        │                 └─ sufaceHolder
   │  │  │  │  │        │                    └─ DemoSurfaceHolder.java
   │  │  │  │  │        ├─ jni
   │  │  │  │  │        │  ├─ cc
   │  │  │  │  │        │  │  ├─ blazeface_align_jni.cc
   │  │  │  │  │        │  │  ├─ blazeface_align_jni.h
   │  │  │  │  │        │  │  ├─ blazeface_detector_jni.cc
   │  │  │  │  │        │  │  ├─ blazeface_detector_jni.h
   │  │  │  │  │        │  │  ├─ face_detector_jni.cc
   │  │  │  │  │        │  │  ├─ face_detector_jni.h
   │  │  │  │  │        │  │  ├─ fps_counter_jni.cc
   │  │  │  │  │        │  │  ├─ fps_counter_jni.h
   │  │  │  │  │        │  │  ├─ hair_segmentation_jni.cc
   │  │  │  │  │        │  │  ├─ hair_segmentation_jni.h
   │  │  │  │  │        │  │  ├─ helper_jni.cc
   │  │  │  │  │        │  │  ├─ helper_jni.h
   │  │  │  │  │        │  │  ├─ image_classify_jni.cc
   │  │  │  │  │        │  │  ├─ image_classify_jni.h
   │  │  │  │  │        │  │  ├─ objectdetector_jni.cc
   │  │  │  │  │        │  │  ├─ objectdetector_jni.h
   │  │  │  │  │        │  │  ├─ objectdetectorssd_jni.cc
   │  │  │  │  │        │  │  ├─ objectdetectorssd_jni.h
   │  │  │  │  │        │  │  ├─ ocr_detector_jni.cc
   │  │  │  │  │        │  │  ├─ ocr_detector_jni.h
   │  │  │  │  │        │  │  ├─ pose_detect_landmark_jni.cc
   │  │  │  │  │        │  │  ├─ pose_detect_landmark_jni.h
   │  │  │  │  │        │  │  ├─ skeleton_detector_jni.cc
   │  │  │  │  │        │  │  ├─ skeleton_detector_jni.h
   │  │  │  │  │        │  │  ├─ tnn_jni.cc
   │  │  │  │  │        │  │  ├─ tnn_jni.h
   │  │  │  │  │        │  │  ├─ tnn_lib.cc
   │  │  │  │  │        │  │  └─ tnn_lib.h
   │  │  │  │  │        │  └─ thirdparty
   │  │  │  │  │        │     ├─ kannarotate-android-lib
   │  │  │  │  │        │     │  ├─ include
   │  │  │  │  │        │     │  │  └─ kannarotate.h
   │  │  │  │  │        │     │  └─ src
   │  │  │  │  │        │     │     ├─ kannarotate.c
   │  │  │  │  │        │     │     ├─ rotate_2.c
   │  │  │  │  │        │     │     ├─ rotate_3.c
   │  │  │  │  │        │     │     ├─ rotate_4.c
   │  │  │  │  │        │     │     ├─ rotate_5.c
   │  │  │  │  │        │     │     ├─ rotate_6.c
   │  │  │  │  │        │     │     ├─ rotate_7.c
   │  │  │  │  │        │     │     ├─ rotate_8.c
   │  │  │  │  │        │     │     └─ rotate_x.h
   │  │  │  │  │        │     └─ yuv420sp_to_rgb_fast_asm.h
   │  │  │  │  │        └─ res
   │  │  │  │  │           ├─ drawable
   │  │  │  │  │           │  ├─ blue_radio_button_bg.xml
   │  │  │  │  │           │  ├─ blue_radio_button_selected_style.xml
   │  │  │  │  │           │  ├─ blue_radio_button_unselected_style.xml
   │  │  │  │  │           │  ├─ button_bg.xml
   │  │  │  │  │           │  ├─ button_bg_cancle.xml
   │  │  │  │  │           │  ├─ cyan_radio_button_bg.xml
   │  │  │  │  │           │  ├─ cyan_radio_button_selected_style.xml
   │  │  │  │  │           │  ├─ cyan_radio_button_unselected_style.xml
   │  │  │  │  │           │  ├─ green_radio_button_bg.xml
   │  │  │  │  │           │  ├─ green_radio_button_selected_style.xml
   │  │  │  │  │           │  ├─ green_radio_button_unselected_style.xml
   │  │  │  │  │           │  ├─ ic_launcher_background.xml
   │  │  │  │  │           │  ├─ purple_radio_button_bg.xml
   │  │  │  │  │           │  ├─ purple_radio_button_selected_style.xml
   │  │  │  │  │           │  ├─ purple_radio_button_unselected_style.xml
   │  │  │  │  │           │  ├─ red_radio_button_bg.xml
   │  │  │  │  │           │  ├─ red_radio_button_selected_style.xml
   │  │  │  │  │           │  ├─ red_radio_button_unselected_style.xml
   │  │  │  │  │           │  ├─ round_corner_bg.xml
   │  │  │  │  │           │  ├─ round_corner_bg_cancel.xml
   │  │  │  │  │           │  ├─ round_corner_bg_press.xml
   │  │  │  │  │           │  ├─ toggle_off.png
   │  │  │  │  │           │  ├─ toggle_on.png
   │  │  │  │  │           │  └─ toggle_selector.xml
   │  │  │  │  │           ├─ ic_launcher.png
   │  │  │  │  │           ├─ layout
   │  │  │  │  │           │  ├─ activity_main.xml
   │  │  │  │  │           │  ├─ base_activity_layout.xml
   │  │  │  │  │           │  ├─ base_fragment_layout.xml
   │  │  │  │  │           │  ├─ dialog_layout.xml
   │  │  │  │  │           │  ├─ fragment_image_detector.xml
   │  │  │  │  │           │  ├─ fragment_stream_detector.xml
   │  │  │  │  │           │  ├─ fragment_stream_hair_segmentation.xml
   │  │  │  │  │           │  ├─ fragment_stream_pose_detect_landmark.xml
   │  │  │  │  │           │  ├─ fragment_stream_skeleton_detector.xml
   │  │  │  │  │           │  └─ title_bar_layout.xml
   │  │  │  │  │           ├─ mipmap-hdpi
   │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │           ├─ mipmap-ldpi
   │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │           ├─ mipmap-mdpi
   │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │           ├─ mipmap-xhdpi
   │  │  │  │  │           │  ├─ back.png
   │  │  │  │  │           │  ├─ back_ic.png
   │  │  │  │  │           │  ├─ camera_rotate_fill.png
   │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │           ├─ mipmap-xxhdpi
   │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │           ├─ mipmap-xxxhdpi
   │  │  │  │  │           │  └─ ic_launcher.png
   │  │  │  │  │           ├─ values-w820dp
   │  │  │  │  │           │  └─ dimens.xml
   │  │  │  │  │           └─ values
   │  │  │  │  │              ├─ attrs.xml
   │  │  │  │  │              ├─ colors.xml
   │  │  │  │  │              ├─ dimens.xml
   │  │  │  │  │              ├─ strings.xml
   │  │  │  │  │              └─ styles.xml
   │  │  │  │  ├─ gradle.properties
   │  │  │  │  ├─ gradle
   │  │  │  │  │  └─ wrapper
   │  │  │  │  │     ├─ gradle-wrapper.jar
   │  │  │  │  │     └─ gradle-wrapper.properties
   │  │  │  │  ├─ gradlew
   │  │  │  │  ├─ gradlew.bat
   │  │  │  │  └─ settings.gradle
   │  │  │  ├─ assets
   │  │  │  │  ├─ 004545.jpg
   │  │  │  │  ├─ blazepose_full_body.png
   │  │  │  │  ├─ blazepose_upper_body.png
   │  │  │  │  ├─ car.png
   │  │  │  │  ├─ dog.png
   │  │  │  │  ├─ full.png
   │  │  │  │  ├─ lite.png
   │  │  │  │  ├─ synset.txt
   │  │  │  │  ├─ test.jpg
   │  │  │  │  ├─ test_blazeface.jpg
   │  │  │  │  ├─ test_face.jpg
   │  │  │  │  └─ tiger_cat.jpg
   │  │  │  ├─ base
   │  │  │  │  ├─ bert_tokenizer.cc
   │  │  │  │  ├─ bert_tokenizer.h
   │  │  │  │  ├─ blazeface_detector.cc
   │  │  │  │  ├─ blazeface_detector.h
   │  │  │  │  ├─ blazepose_detector.cc
   │  │  │  │  ├─ blazepose_detector.h
   │  │  │  │  ├─ blazepose_landmark.cc
   │  │  │  │  ├─ blazepose_landmark.h
   │  │  │  │  ├─ face_detect_aligner.cc
   │  │  │  │  ├─ face_detect_aligner.h
   │  │  │  │  ├─ face_detect_mesh.cc
   │  │  │  │  ├─ face_detect_mesh.h
   │  │  │  │  ├─ face_gray_transfer.cc
   │  │  │  │  ├─ face_gray_transfer.h
   │  │  │  │  ├─ face_mesh.cc
   │  │  │  │  ├─ face_mesh.h
   │  │  │  │  ├─ hair_segmentation.cc
   │  │  │  │  ├─ hair_segmentation.h
   │  │  │  │  ├─ image_classifier.cc
   │  │  │  │  ├─ image_classifier.h
   │  │  │  │  ├─ macro.h
   │  │  │  │  ├─ object_detector_ssd.cc
   │  │  │  │  ├─ object_detector_ssd.h
   │  │  │  │  ├─ object_detector_yolo.cc
   │  │  │  │  ├─ object_detector_yolo.h
   │  │  │  │  ├─ ocr_angle_predictor.cc
   │  │  │  │  ├─ ocr_angle_predictor.h
   │  │  │  │  ├─ ocr_driver.cc
   │  │  │  │  ├─ ocr_driver.h
   │  │  │  │  ├─ ocr_text_recognizer.cc
   │  │  │  │  ├─ ocr_text_recognizer.h
   │  │  │  │  ├─ ocr_textbox_detector.cc
   │  │  │  │  ├─ ocr_textbox_detector.h
   │  │  │  │  ├─ pose_detect_landmark.cc
   │  │  │  │  ├─ pose_detect_landmark.h
   │  │  │  │  ├─ sample_timer.cc
   │  │  │  │  ├─ sample_timer.h
   │  │  │  │  ├─ skeleton_detector.cc
   │  │  │  │  ├─ skeleton_detector.h
   │  │  │  │  ├─ tnn_fps_counter.cc
   │  │  │  │  ├─ tnn_fps_counter.h
   │  │  │  │  ├─ tnn_sdk_sample.cc
   │  │  │  │  ├─ tnn_sdk_sample.h
   │  │  │  │  ├─ ultra_face_detector.cc
   │  │  │  │  ├─ ultra_face_detector.h
   │  │  │  │  ├─ utils
   │  │  │  │  │  ├─ utils.cc
   │  │  │  │  │  └─ utils.h
   │  │  │  │  ├─ youtu_face_align.cc
   │  │  │  │  └─ youtu_face_align.h
   │  │  │  ├─ ios
   │  │  │  │  ├─ TNNExamples.xcodeproj
   │  │  │  │  │  ├─ project.pbxproj
   │  │  │  │  │  ├─ project.xcworkspace
   │  │  │  │  │  │  ├─ contents.xcworkspacedata
   │  │  │  │  │  │  └─ xcshareddata
   │  │  │  │  │  │     └─ IDEWorkspaceChecks.plist
   │  │  │  │  │  └─ xcshareddata
   │  │  │  │  │     └─ xcschemes
   │  │  │  │  │        └─ TNNExamples.xcscheme
   │  │  │  │  └─ TNNExamples
   │  │  │  │     ├─ AppDelegate.h
   │  │  │  │     ├─ AppDelegate.mm
   │  │  │  │     ├─ Assets.xcassets
   │  │  │  │     │  ├─ AppIcon.appiconset
   │  │  │  │     │  │  ├─ Contents.json
   │  │  │  │     │  │  ├─ icon-1024.png
   │  │  │  │     │  │  ├─ icon-20-ipad.png
   │  │  │  │     │  │  ├─ icon-20@2x-ipad.png
   │  │  │  │     │  │  ├─ icon-20@2x.png
   │  │  │  │     │  │  ├─ icon-20@3x.png
   │  │  │  │     │  │  ├─ icon-29-ipad.png
   │  │  │  │     │  │  ├─ icon-29.png
   │  │  │  │     │  │  ├─ icon-29@2x-ipad.png
   │  │  │  │     │  │  ├─ icon-29@2x.png
   │  │  │  │     │  │  ├─ icon-29@3x.png
   │  │  │  │     │  │  ├─ icon-40.png
   │  │  │  │     │  │  ├─ icon-40@2x.png
   │  │  │  │     │  │  ├─ icon-40@3x.png
   │  │  │  │     │  │  ├─ icon-60@2x.png
   │  │  │  │     │  │  ├─ icon-60@3x.png
   │  │  │  │     │  │  ├─ icon-76.png
   │  │  │  │     │  │  ├─ icon-76@2x.png
   │  │  │  │     │  │  └─ icon-83.5@2x.png
   │  │  │  │     │  └─ Contents.json
   │  │  │  │     ├─ Base.lproj
   │  │  │  │     │  ├─ LaunchScreen.storyboard
   │  │  │  │     │  └─ Main.storyboard
   │  │  │  │     ├─ Component
   │  │  │  │     │  ├─ DYFlatButton.h
   │  │  │  │     │  ├─ DYFlatButton.m
   │  │  │  │     │  ├─ UIColor+Utility.h
   │  │  │  │     │  └─ UIColor+Utility.m
   │  │  │  │     ├─ Info.plist
   │  │  │  │     ├─ RootNavController.h
   │  │  │  │     ├─ RootNavController.mm
   │  │  │  │     ├─ SceneDelegate.h
   │  │  │  │     ├─ SceneDelegate.mm
   │  │  │  │     ├─ TNNBlazefaceDetectorController
   │  │  │  │     │  ├─ TNNBlazefaceDetectorController.h
   │  │  │  │     │  ├─ TNNBlazefaceDetectorController.mm
   │  │  │  │     │  ├─ blazeface_anchors.txt
   │  │  │  │     │  └─ test_blazeface.jpg
   │  │  │  │     ├─ TNNCameraPreviewController
   │  │  │  │     │  ├─ CameraDevice
   │  │  │  │     │  │  ├─ TNNBoundingBox.h
   │  │  │  │     │  │  ├─ TNNBoundingBox.mm
   │  │  │  │     │  │  ├─ TNNCameraVideoDevice.h
   │  │  │  │     │  │  ├─ TNNCameraVideoDevice.mm
   │  │  │  │     │  │  ├─ TNNMaskImage.h
   │  │  │  │     │  │  ├─ TNNMaskImage.mm
   │  │  │  │     │  │  └─ camera_rotate_fill.png
   │  │  │  │     │  ├─ TNNCameraPreviewController.h
   │  │  │  │     │  ├─ TNNCameraPreviewController.mm
   │  │  │  │     │  └─ TNNViewModel
   │  │  │  │     │     ├─ TNNBlazeFaceDetectorViewModel.h
   │  │  │  │     │     ├─ TNNBlazeFaceDetectorViewModel.mm
   │  │  │  │     │     ├─ TNNFaceDetectAlignerViewModel.h
   │  │  │  │     │     ├─ TNNFaceDetectAlignerViewModel.mm
   │  │  │  │     │     ├─ TNNFaceDetectMeshViewModel.h
   │  │  │  │     │     ├─ TNNFaceDetectMeshViewModel.mm
   │  │  │  │     │     ├─ TNNFaceDetectorViewModel.h
   │  │  │  │     │     ├─ TNNFaceDetectorViewModel.mm
   │  │  │  │     │     ├─ TNNHairSegmentationViewModel.h
   │  │  │  │     │     ├─ TNNHairSegmentationViewModel.mm
   │  │  │  │     │     ├─ TNNOCRViewModel.h
   │  │  │  │     │     ├─ TNNOCRViewModel.mm
   │  │  │  │     │     ├─ TNNPoseDetectLandmarkViewModel.h
   │  │  │  │     │     ├─ TNNPoseDetectLandmarkViewModel.mm
   │  │  │  │     │     ├─ TNNSSDObjectDetectorViewModel.h
   │  │  │  │     │     ├─ TNNSSDObjectDetectorViewModel.mm
   │  │  │  │     │     ├─ TNNSkeletonDetectorViewModel.h
   │  │  │  │     │     ├─ TNNSkeletonDetectorViewModel.mm
   │  │  │  │     │     ├─ TNNViewModel.h
   │  │  │  │     │     ├─ TNNViewModel.mm
   │  │  │  │     │     ├─ TNNYoloObjectDetectorViewModel.h
   │  │  │  │     │     └─ TNNYoloObjectDetectorViewModel.mm
   │  │  │  │     ├─ TNNExamplesController
   │  │  │  │     │  ├─ TNNExamplesController.h
   │  │  │  │     │  ├─ TNNExamplesController.mm
   │  │  │  │     │  ├─ TNNExamplesListCell.h
   │  │  │  │     │  ├─ TNNExamplesListCell.m
   │  │  │  │     │  ├─ TNNExamplesListController.h
   │  │  │  │     │  └─ TNNExamplesListController.mm
   │  │  │  │     ├─ TNNFaceDetectorController
   │  │  │  │     │  ├─ TNNFaceDetectorController.h
   │  │  │  │     │  ├─ TNNFaceDetectorController.mm
   │  │  │  │     │  └─ test.jpg
   │  │  │  │     ├─ TNNFacemeshController
   │  │  │  │     │  ├─ TNNFacemeshController.h
   │  │  │  │     │  ├─ TNNFacemeshController.mm
   │  │  │  │     │  └─ test_facemesh.jpg
   │  │  │  │     ├─ TNNImageClassifyController
   │  │  │  │     │  ├─ TNNImageClassifyController.h
   │  │  │  │     │  ├─ TNNImageClassifyController.mm
   │  │  │  │     │  ├─ synset.txt
   │  │  │  │     │  └─ tiger_cat.jpg
   │  │  │  │     ├─ TNNImageColourController
   │  │  │  │     │  ├─ TNNImageColourController.h
   │  │  │  │     │  ├─ TNNImageColourController.mm
   │  │  │  │     │  └─ gray_00001.jpg
   │  │  │  │     ├─ TNNObjectDetectorController
   │  │  │  │     │  ├─ 004545.jpg
   │  │  │  │     │  ├─ TNNObjectDetectorController.h
   │  │  │  │     │  └─ TNNObjectDetectorController.mm
   │  │  │  │     ├─ TNNYoloObjectDetectorController
   │  │  │  │     │  ├─ TNNYoloObjectDetectorController.h
   │  │  │  │     │  ├─ TNNYoloObjectDetectorController.mm
   │  │  │  │     │  └─ dog_cropped.jpg
   │  │  │  │     ├─ UIImage+Utility.h
   │  │  │  │     ├─ UIImage+Utility.mm
   │  │  │  │     ├─ logo@2x.png
   │  │  │  │     └─ main.m
   │  │  │  ├─ linux
   │  │  │  │  ├─ .gitignore
   │  │  │  │  ├─ cross
   │  │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  │  ├─ build_aarch64_linux.sh
   │  │  │  │  │  └─ build_armhf_linux.sh
   │  │  │  │  ├─ cuda
   │  │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  │  └─ build_linux.sh
   │  │  │  │  ├─ src
   │  │  │  │  │  ├─ BertReadingComprehension
   │  │  │  │  │  │  └─ BertReadingComprehension.cc
   │  │  │  │  │  ├─ TNNFaceDetector
   │  │  │  │  │  │  └─ TNNFaceDetector.cc
   │  │  │  │  │  ├─ TNNImageClassify
   │  │  │  │  │  │  └─ TNNImageClassify.cc
   │  │  │  │  │  ├─ TNNObjectDetector
   │  │  │  │  │  │  └─ TNNObjectDetector.cc
   │  │  │  │  │  ├─ TNNWebCamBasedDemo
   │  │  │  │  │  │  ├─ webcam_demo.cc
   │  │  │  │  │  │  ├─ worker.cc
   │  │  │  │  │  │  └─ worker.h
   │  │  │  │  │  ├─ flags.cc
   │  │  │  │  │  └─ flags.h
   │  │  │  │  └─ x86
   │  │  │  │     ├─ CMakeLists.txt
   │  │  │  │     ├─ build_linux_native.sh
   │  │  │  │     └─ build_linux_openvino.sh
   │  │  │  ├─ mac
   │  │  │  │  ├─ .gitignore
   │  │  │  │  └─ x86
   │  │  │  │     ├─ CMakeLists.txt
   │  │  │  │     ├─ build_macos_native.sh
   │  │  │  │     └─ build_macos_openvino.sh
   │  │  │  ├─ utils
   │  │  │  │  ├─ clipper.cc
   │  │  │  │  ├─ clipper.h
   │  │  │  │  ├─ landmark_smoothing_filter.cc
   │  │  │  │  ├─ landmark_smoothing_filter.h
   │  │  │  │  ├─ low_pass_filter.cc
   │  │  │  │  ├─ low_pass_filter.h
   │  │  │  │  ├─ relative_velocity_filter.cc
   │  │  │  │  ├─ relative_velocity_filter.h
   │  │  │  │  ├─ time_stamp.cc
   │  │  │  │  └─ time_stamp.h
   │  │  │  └─ windows
   │  │  │     ├─ .gitignore
   │  │  │     └─ x86
   │  │  │        ├─ CMakeLists.txt
   │  │  │        ├─ build_msvc_native.bat
   │  │  │        └─ build_msvc_openvino.bat
   │  │  ├─ include
   │  │  │  └─ tnn
   │  │  │     ├─ core
   │  │  │     │  ├─ blob.h
   │  │  │     │  ├─ common.h
   │  │  │     │  ├─ instance.h
   │  │  │     │  ├─ macro.h
   │  │  │     │  ├─ mat.h
   │  │  │     │  ├─ status.h
   │  │  │     │  └─ tnn.h
   │  │  │     ├─ utils
   │  │  │     │  ├─ bfp16_utils.h
   │  │  │     │  ├─ blob_converter.h
   │  │  │     │  ├─ cpu_utils.h
   │  │  │     │  ├─ data_type_utils.h
   │  │  │     │  ├─ dims_vector_utils.h
   │  │  │     │  ├─ half_utils.h
   │  │  │     │  ├─ mat_utils.h
   │  │  │     │  └─ string_utils.h
   │  │  │     └─ version.h
   │  │  ├─ platforms
   │  │  │  ├─ android
   │  │  │  │  ├─ .gitignore
   │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  ├─ model_check_android.sh
   │  │  │  │  ├─ test_android.sh
   │  │  │  │  └─ unit_test_android.sh
   │  │  │  ├─ ios
   │  │  │  │  ├─ .gitignore
   │  │  │  │  ├─ scripts
   │  │  │  │  │  ├─ build_ios.sh
   │  │  │  │  │  └─ version.sh
   │  │  │  │  ├─ tnn.xcodeproj
   │  │  │  │  │  ├─ project.pbxproj
   │  │  │  │  │  ├─ project.xcworkspace
   │  │  │  │  │  │  ├─ contents.xcworkspacedata
   │  │  │  │  │  │  └─ xcshareddata
   │  │  │  │  │  │     └─ IDEWorkspaceChecks.plist
   │  │  │  │  │  └─ xcshareddata
   │  │  │  │  │     └─ xcschemes
   │  │  │  │  │        └─ tnn.xcscheme
   │  │  │  │  ├─ tnn
   │  │  │  │  │  ├─ Info.plist
   │  │  │  │  │  └─ tnn.h
   │  │  │  │  └─ unit_test_x86_metal.sh
   │  │  │  ├─ linux
   │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  ├─ build_model_check.sh
   │  │  │  │  ├─ build_quanttool.sh
   │  │  │  │  ├─ test_x86_cpu.sh
   │  │  │  │  ├─ test_x86_ocl.sh
   │  │  │  │  └─ unit_test_x86_ocl.sh
   │  │  │  ├─ mac
   │  │  │  │  └─ CMakeLists.txt
   │  │  │  └─ windows
   │  │  │     ├─ CMakeLists.txt
   │  │  │     └─ build_model_check.bat
   │  │  ├─ scripts
   │  │  │  ├─ .ci
   │  │  │  │  └─ preflight.sh
   │  │  │  ├─ .gitignore
   │  │  │  ├─ build_aarch64_linux.sh
   │  │  │  ├─ build_aarch64_macos.sh
   │  │  │  ├─ build_android.sh
   │  │  │  ├─ build_armhf_linux.sh
   │  │  │  ├─ build_cuda_linux.sh
   │  │  │  ├─ build_cuda_msvc.bat
   │  │  │  ├─ build_ios.sh
   │  │  │  ├─ build_linux.sh
   │  │  │  ├─ build_linux_native.sh
   │  │  │  ├─ build_linux_pjq.sh
   │  │  │  ├─ build_macos.sh
   │  │  │  ├─ build_macos_native.sh
   │  │  │  ├─ build_msvc.bat
   │  │  │  ├─ build_msvc_native.bat
   │  │  │  ├─ build_test.sh
   │  │  │  ├─ build_win_x86_opencl.bat
   │  │  │  ├─ build_x86_linux.sh
   │  │  │  ├─ download_opencv.sh
   │  │  │  └─ version
   │  │  │     ├─ add_version_attr.sh
   │  │  │     ├─ add_version_plist.sh
   │  │  │     ├─ get_git_version.sh
   │  │  │     └─ version.sh
   │  │  ├─ source
   │  │  │  └─ tnn
   │  │  │     ├─ core
   │  │  │     │  ├─ abstract_device.cc
   │  │  │     │  ├─ abstract_device.h
   │  │  │     │  ├─ abstract_layer_acc.cc
   │  │  │     │  ├─ abstract_layer_acc.h
   │  │  │     │  ├─ abstract_network.cc
   │  │  │     │  ├─ abstract_network.h
   │  │  │     │  ├─ blob.cc
   │  │  │     │  ├─ blob_impl.cc
   │  │  │     │  ├─ blob_impl.h
   │  │  │     │  ├─ blob_int8.cc
   │  │  │     │  ├─ blob_int8.h
   │  │  │     │  ├─ blob_manager.cc
   │  │  │     │  ├─ blob_manager.h
   │  │  │     │  ├─ const_folder.cc
   │  │  │     │  ├─ const_folder.h
   │  │  │     │  ├─ context.cc
   │  │  │     │  ├─ context.h
   │  │  │     │  ├─ default_network.cc
   │  │  │     │  ├─ default_network.h
   │  │  │     │  ├─ instance.cc
   │  │  │     │  ├─ layer_type.cc
   │  │  │     │  ├─ layer_type.h
   │  │  │     │  ├─ mat.cc
   │  │  │     │  ├─ profile.cc
   │  │  │     │  ├─ profile.h
   │  │  │     │  ├─ status.cc
   │  │  │     │  ├─ tnn.cc
   │  │  │     │  ├─ tnn_impl.cc
   │  │  │     │  ├─ tnn_impl.h
   │  │  │     │  ├─ tnn_impl_default.cc
   │  │  │     │  └─ tnn_impl_default.h
   │  │  │     ├─ device
   │  │  │     │  ├─ arm
   │  │  │     │  │  ├─ CMakeLists.txt
   │  │  │     │  │  ├─ acc
   │  │  │     │  │  │  ├─ Float4.h
   │  │  │     │  │  │  ├─ Half8.h
   │  │  │     │  │  │  ├─ TNNVector.h
   │  │  │     │  │  │  ├─ arm_abs_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_add_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_add_layer_acc.h
   │  │  │     │  │  │  ├─ arm_arg_max_or_min_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_batch_norm_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_batch_norm_layer_acc.h
   │  │  │     │  │  │  ├─ arm_binary_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_binary_layer_acc.h
   │  │  │     │  │  │  ├─ arm_cast_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_clip_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_concat_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_concat_layer_acc.h
   │  │  │     │  │  │  ├─ arm_detection_output_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_div_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_elu_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_exp_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_expand_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_expand_layer_acc.h
   │  │  │     │  │  │  ├─ arm_floor_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_gather_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_grid_sample_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_hard_sigmoid_acc.cc
   │  │  │     │  │  │  ├─ arm_hard_swish_acc.cc
   │  │  │     │  │  │  ├─ arm_inner_product_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_inner_product_layer_acc.h
   │  │  │     │  │  │  ├─ arm_instance_norm_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_inverse_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_layer_acc.h
   │  │  │     │  │  │  ├─ arm_log_acc_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_log_sigmoid_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_lstm_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_lstm_layer_acc.h
   │  │  │     │  │  │  ├─ arm_mat_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_mat_mul_layer_acc.h
   │  │  │     │  │  │  ├─ arm_max_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_min_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_nchw_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_nchw_layer_acc.h
   │  │  │     │  │  │  ├─ arm_neg_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_normalize_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_pad_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_padv2_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_permute_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_pixel_shuffle_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_pool_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_pool_layer_acc.h
   │  │  │     │  │  │  ├─ arm_pow_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_prelu_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_prelu_layer_acc.h
   │  │  │     │  │  │  ├─ arm_priorbox_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reciprocal_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_l1_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_l2_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_layer_acc.h
   │  │  │     │  │  │  ├─ arm_reduce_log_sum_exp_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_log_sum_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_max_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_mean_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_min_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_prod_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_sum_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reduce_sum_square_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reformat_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reformat_layer_acc.h
   │  │  │     │  │  │  ├─ arm_relu6_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_relu_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_relu_layer_acc.h
   │  │  │     │  │  │  ├─ arm_reorg_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reshape_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_reshape_layer_acc.h
   │  │  │     │  │  │  ├─ arm_scale_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_selu_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_shuffle_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_sigmoid_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_sign_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_signed_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_signed_mul_layer_acc.h
   │  │  │     │  │  │  ├─ arm_softmax_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_softmax_layer_acc.h
   │  │  │     │  │  │  ├─ arm_softplus_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_splitv_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_sqrt_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_squeeze_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_stride_slice_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_sub_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_tile_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_trig_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_unary_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_unary_layer_acc.h
   │  │  │     │  │  │  ├─ arm_unsqueeze_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_upsample_layer_acc.cc
   │  │  │     │  │  │  ├─ arm_upsample_layer_acc.h
   │  │  │     │  │  │  ├─ compute
   │  │  │     │  │  │  │  ├─ arm32
   │  │  │     │  │  │  │  │  ├─ CONV_BFP16_O4.S
   │  │  │     │  │  │  │  │  ├─ CONV_BFP16_SLIDEW_C3.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3_BFP16_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3_FLOAT_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3_INT8_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_5X5_BFP16_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_5X5_FLOAT_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_FLOAT_O4.S
   │  │  │     │  │  │  │  │  ├─ CONV_FLOAT_SLIDEW_C3.S
   │  │  │     │  │  │  │  │  ├─ DECONV_FLOAT_O4.S
   │  │  │     │  │  │  │  │  ├─ GEMM_BFP16_N4.S
   │  │  │     │  │  │  │  │  ├─ GEMM_FLOAT_N4.S
   │  │  │     │  │  │  │  │  ├─ GEMM_INT8_4X4.S
   │  │  │     │  │  │  │  │  └─ GEMM_INT8_4X8.S
   │  │  │     │  │  │  │  ├─ arm64
   │  │  │     │  │  │  │  │  ├─ CONV_BFP16_O4.S
   │  │  │     │  │  │  │  │  ├─ CONV_BFP16_SLIDEW_C3.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3_FLOAT_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3_INT8_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3x3_BFP16_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_5X5_FLOAT_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_5x5_BFP16_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_FLOAT_O4.S
   │  │  │     │  │  │  │  │  ├─ CONV_FLOAT_SLIDEW_C3.S
   │  │  │     │  │  │  │  │  ├─ DECONV_FLOAT_O4.S
   │  │  │     │  │  │  │  │  ├─ GEMM_BFP16_N8.S
   │  │  │     │  │  │  │  │  ├─ GEMM_FLOAT_N8.S
   │  │  │     │  │  │  │  │  ├─ GEMM_INT8_4X4.S
   │  │  │     │  │  │  │  │  └─ GEMM_INT8_8X8.S
   │  │  │     │  │  │  │  ├─ asm_func_name.S
   │  │  │     │  │  │  │  ├─ binary_function.cc
   │  │  │     │  │  │  │  ├─ binary_function.h
   │  │  │     │  │  │  │  ├─ compute.cc
   │  │  │     │  │  │  │  ├─ compute.h
   │  │  │     │  │  │  │  ├─ compute_int8.cc
   │  │  │     │  │  │  │  ├─ compute_int8.h
   │  │  │     │  │  │  │  ├─ gemm_function.cc
   │  │  │     │  │  │  │  ├─ gemm_function.h
   │  │  │     │  │  │  │  ├─ winograd_function.cc
   │  │  │     │  │  │  │  └─ winograd_function.h
   │  │  │     │  │  │  ├─ compute_arm82
   │  │  │     │  │  │  │  ├─ CMakeLists.txt
   │  │  │     │  │  │  │  ├─ arm_batch_norm_fp16_layer.cc
   │  │  │     │  │  │  │  ├─ arm_binary_fp16_layer_acc.cc
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_3x3.cc
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_c3.cc
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_common.cc
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_depthwise.cc
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_depthwise_s1.cc
   │  │  │     │  │  │  │  ├─ arm_conv_int8_sdot_layer_common.cc
   │  │  │     │  │  │  │  ├─ arm_conv_int8_sdot_layer_depthwise_3x3.cc
   │  │  │     │  │  │  │  ├─ arm_deconv_fp16_layer_common.cc
   │  │  │     │  │  │  │  ├─ arm_deconv_fp16_layer_depthwise.cc
   │  │  │     │  │  │  │  ├─ arm_inner_product_fp16_layer.cc
   │  │  │     │  │  │  │  ├─ arm_lstm_fp16_layer.cc
   │  │  │     │  │  │  │  ├─ arm_prelu_fp16_layer.cc
   │  │  │     │  │  │  │  ├─ arm_relu6_fp16_layer.cc
   │  │  │     │  │  │  │  ├─ arm_relu_fp16_layer.cc
   │  │  │     │  │  │  │  ├─ arm_sigmoid_fp16_layer.cc
   │  │  │     │  │  │  │  ├─ arm_softmax_fp16_layer.cc
   │  │  │     │  │  │  │  ├─ arm_unary_fp16_layer.h
   │  │  │     │  │  │  │  ├─ asm_32
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3S1_INT8_SDOT_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3S2_INT8_SDOT_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3_FP16_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_FP16_SLIDEW_C3.S
   │  │  │     │  │  │  │  │  ├─ DECONV_FP16_O8.S
   │  │  │     │  │  │  │  │  ├─ DECONV_FP16_O8_C1.S
   │  │  │     │  │  │  │  │  ├─ FLOAT2HALF.S
   │  │  │     │  │  │  │  │  ├─ GEMM_FP16_N8.S
   │  │  │     │  │  │  │  │  ├─ GEMM_INT8_SDOT_4X4.S
   │  │  │     │  │  │  │  │  ├─ GEMM_INT8_SDOT_4X8.S
   │  │  │     │  │  │  │  │  ├─ GEMV_INT8_SDOT.S
   │  │  │     │  │  │  │  │  └─ HALF2FLOAT.S
   │  │  │     │  │  │  │  ├─ asm_64
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3S1_INT8_SDOT_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3S2_INT8_SDOT_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_DW_3X3_FP16_SLIDEW.S
   │  │  │     │  │  │  │  │  ├─ CONV_FP16_SLIDEW_C3.S
   │  │  │     │  │  │  │  │  ├─ DECONV_FP16_O8.S
   │  │  │     │  │  │  │  │  ├─ DECONV_FP16_O8_C1.S
   │  │  │     │  │  │  │  │  ├─ FLOAT2HALF.S
   │  │  │     │  │  │  │  │  ├─ GEMM_FP16_N8.S
   │  │  │     │  │  │  │  │  ├─ GEMM_INT8_SDOT_8X4.S
   │  │  │     │  │  │  │  │  ├─ GEMM_INT8_SDOT_8X8.S
   │  │  │     │  │  │  │  │  ├─ GEMV_INT8_SDOT.S
   │  │  │     │  │  │  │  │  └─ HALF2FLOAT.S
   │  │  │     │  │  │  │  ├─ compute_half.cc
   │  │  │     │  │  │  │  ├─ compute_half.h
   │  │  │     │  │  │  │  ├─ compute_sdot_int8.cc
   │  │  │     │  │  │  │  ├─ compute_sdot_int8.h
   │  │  │     │  │  │  │  ├─ gemm_function_fp16.cc
   │  │  │     │  │  │  │  └─ winograd_function_fp16.cc
   │  │  │     │  │  │  ├─ convolution
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_3x3.h
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_c3.h
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_common.h
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_depthwise.h
   │  │  │     │  │  │  │  ├─ arm_conv_fp16_layer_depthwise_s1.h
   │  │  │     │  │  │  │  ├─ arm_conv_int8_layer_1x1.cc
   │  │  │     │  │  │  │  ├─ arm_conv_int8_layer_1x1.h
   │  │  │     │  │  │  │  ├─ arm_conv_int8_layer_common.cc
   │  │  │     │  │  │  │  ├─ arm_conv_int8_layer_common.h
   │  │  │     │  │  │  │  ├─ arm_conv_int8_layer_depthwise.cc
   │  │  │     │  │  │  │  ├─ arm_conv_int8_layer_depthwise.h
   │  │  │     │  │  │  │  ├─ arm_conv_int8_sdot_layer_common.h
   │  │  │     │  │  │  │  ├─ arm_conv_int8_sdot_layer_depthwise_3x3.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_1x1.cc
   │  │  │     │  │  │  │  ├─ arm_conv_layer_1x1.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_3x3.cc
   │  │  │     │  │  │  │  ├─ arm_conv_layer_3x3.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_acc.cc
   │  │  │     │  │  │  │  ├─ arm_conv_layer_acc.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_acc_factory.cc
   │  │  │     │  │  │  │  ├─ arm_conv_layer_acc_factory.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_c3.cc
   │  │  │     │  │  │  │  ├─ arm_conv_layer_c3.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_common.cc
   │  │  │     │  │  │  │  ├─ arm_conv_layer_common.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_depthwise.cc
   │  │  │     │  │  │  │  ├─ arm_conv_layer_depthwise.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_depthwise_s1.cc
   │  │  │     │  │  │  │  ├─ arm_conv_layer_depthwise_s1.h
   │  │  │     │  │  │  │  ├─ arm_conv_layer_group.cc
   │  │  │     │  │  │  │  └─ arm_conv_layer_group.h
   │  │  │     │  │  │  ├─ deconvolution
   │  │  │     │  │  │  │  ├─ arm_deconv_fp16_layer_common.h
   │  │  │     │  │  │  │  ├─ arm_deconv_fp16_layer_depthwise.h
   │  │  │     │  │  │  │  ├─ arm_deconv_layer_acc.cc
   │  │  │     │  │  │  │  ├─ arm_deconv_layer_acc.h
   │  │  │     │  │  │  │  ├─ arm_deconv_layer_common.cc
   │  │  │     │  │  │  │  ├─ arm_deconv_layer_common.h
   │  │  │     │  │  │  │  ├─ arm_deconv_layer_depthwise.cc
   │  │  │     │  │  │  │  ├─ arm_deconv_layer_depthwise.h
   │  │  │     │  │  │  │  ├─ arm_deconv_layer_stride.cc
   │  │  │     │  │  │  │  └─ arm_deconv_layer_stride.h
   │  │  │     │  │  │  └─ neon_mathfun.h
   │  │  │     │  │  ├─ arm_blob_converter.cc
   │  │  │     │  │  ├─ arm_blob_converter.h
   │  │  │     │  │  ├─ arm_common.h
   │  │  │     │  │  ├─ arm_context.cc
   │  │  │     │  │  ├─ arm_context.h
   │  │  │     │  │  ├─ arm_device.cc
   │  │  │     │  │  ├─ arm_device.h
   │  │  │     │  │  ├─ arm_mat_converter.cc
   │  │  │     │  │  ├─ arm_mat_converter.h
   │  │  │     │  │  ├─ arm_mat_util.cc
   │  │  │     │  │  ├─ arm_mat_util.h
   │  │  │     │  │  ├─ arm_util.cc
   │  │  │     │  │  └─ arm_util.h
   │  │  │     │  ├─ cpu
   │  │  │     │  │  ├─ CMakeLists.txt
   │  │  │     │  │  ├─ acc
   │  │  │     │  │  │  ├─ compute
   │  │  │     │  │  │  │  ├─ compute_elewise.cc
   │  │  │     │  │  │  │  ├─ compute_elewise.h
   │  │  │     │  │  │  │  ├─ compute_int8.cc
   │  │  │     │  │  │  │  ├─ compute_int8.h
   │  │  │     │  │  │  │  └─ normalized_bbox.h
   │  │  │     │  │  │  ├─ cpu_ histogram_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_abs_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_acos_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_add_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_arg_max_or_min_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_asin_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_atan_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_batch_norm_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_bias_add_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_binary_op_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_binary_op_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_bitshift_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_cast_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_ceil_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_clip_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_concat_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_const_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_constantofshape_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_conv_1d_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_conv_1d_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_conv_3d_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_conv_3d_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_conv_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_conv_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_cos_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_deconv_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_deconv_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_detection_output_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_detection_output_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_detection_post_process_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_detection_post_process_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_div_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_einsum_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_elu_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_equal_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_erf_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_exp_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_expand_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_flatten_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_floor_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_gather_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_gathernd_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_gelu_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_gridsample_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_group_norm_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_hard_sigmoid_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_hard_swish_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_hdrguide_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_inner_product_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_instance_norm_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_inverse_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_layer_norm_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_log_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_log_sigmoid_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_lrn_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_lstm_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_mat_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_max_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_min_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_neg_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_nonzero_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_normalize_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_onehot_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_pad_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_padv2_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_permute_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_permute_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_pixel_shuffle_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_pool_3d_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_pool_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_pow_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_prelu_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_prior_box_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_prior_box_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_range_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reciprocal_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_l1_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_l2_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_reduce_log_sum_exp_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_log_sum_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_max_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_mean_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_min_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_prod_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_sum_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reduce_sum_square_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reformat_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_relu6_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_relu_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reorg_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_reshape_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_roialign_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_rsqrt_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_scale_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_scatter_nd_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_selu_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_shape_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_shuffle_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_sigmoid_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_sign_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_signed_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_sin_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_size_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_softmax_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_softplus_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_splitv_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_sqrt_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_squared_difference_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_squeeze_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_stride_slice_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_stride_slice_v2_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_sub_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_tan_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_tanh_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_tile_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_topk_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_unary_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_unary_layer_acc.h
   │  │  │     │  │  │  ├─ cpu_unsqueeze_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_upsample_layer_acc.cc
   │  │  │     │  │  │  ├─ cpu_upsample_layer_acc.h
   │  │  │     │  │  │  └─ cpu_where_layer_acc.cc
   │  │  │     │  │  ├─ cpu_blob_converter.cc
   │  │  │     │  │  ├─ cpu_context.cc
   │  │  │     │  │  ├─ cpu_context.h
   │  │  │     │  │  ├─ cpu_device.cc
   │  │  │     │  │  ├─ cpu_device.h
   │  │  │     │  │  ├─ cpu_mat_converter.cc
   │  │  │     │  │  ├─ cpu_mat_converter.h
   │  │  │     │  │  ├─ cpu_mat_util.cc
   │  │  │     │  │  └─ cpu_mat_util.h
   │  │  │     │  ├─ cuda
   │  │  │     │  │  ├─ CMakeLists.txt
   │  │  │     │  │  ├─ acc
   │  │  │     │  │  │  ├─ cuda_abs_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_acos_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_add_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_arg_max_or_min_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_asin_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_atan_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_batch_norm_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_bitshift_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_cast_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_cbam_fused_pooling_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_cbam_fused_reduce_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_ceil_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_clip_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_concat_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_constantofshape_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_conv_1d_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_conv_3d_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_conv_3d_layer_acc.h
   │  │  │     │  │  │  ├─ cuda_conv_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_conv_layer_acc.h
   │  │  │     │  │  │  ├─ cuda_cos_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_deconv_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_detection_output_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_detection_output_layer_acc.h
   │  │  │     │  │  │  ├─ cuda_detection_output_layer_acc_kernel.cu
   │  │  │     │  │  │  ├─ cuda_detection_output_layer_acc_kernel.cuh
   │  │  │     │  │  │  ├─ cuda_div_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_einsum_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_elu_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_erf_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_exp_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_expand_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_flatten_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_floor_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_gather_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_gather_layer_acc.h
   │  │  │     │  │  │  ├─ cuda_gather_layer_acc_kernel.cu
   │  │  │     │  │  │  ├─ cuda_gather_layer_acc_kernel.cuh
   │  │  │     │  │  │  ├─ cuda_gather_nd_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_gelu_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_gridsample_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_group_norm_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_hard_sigmoid_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_hard_swish_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_histogram_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_inner_product_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_inner_product_layer_acc.h
   │  │  │     │  │  │  ├─ cuda_instance_norm_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_inverse_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_layer_acc.cc
   │  │  │     │  │  │  ├─ cuda_layer_acc.h
   │  │  │     │  │  │  ├─ cuda_layer_norm_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_log_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_log_sigmoid_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_lrn_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_lstm_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_lstm_layer_acc.h
   │  │  │     │  │  │  ├─ cuda_mat_mul_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_max_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_min_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_mul_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_neg_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_normalize_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_onehot_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_pad_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_pad_v2_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_permute_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_pixel_shuffle_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_pooling_3d_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_pooling_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_pooling_layer_acc.h
   │  │  │     │  │  │  ├─ cuda_power_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_prelu_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_prior_box_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_reciprocal_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_reduce_l2_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_reduce_log_sum_exp_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_reduce_max_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_reduce_mean_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_reduce_min_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_reduce_sum_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_relu6_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_relu_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_reshape_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_roialign_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_scatter_nd_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_shape_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_shuffle_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_sigmoid_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_sign_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_sin_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_softmax_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_softplus_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_splitv_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_sqrt_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_squeeze_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_strided_slice_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_strided_slice_layer_acc_kernel.cu
   │  │  │     │  │  │  ├─ cuda_strided_slice_layer_acc_kernel.cuh
   │  │  │     │  │  │  ├─ cuda_strided_slice_v2_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_sub_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_tan_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_tanh_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_tile_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_topk_layer_acc.cu
   │  │  │     │  │  │  ├─ cuda_unsqueeze_layer_acc.cu
   │  │  │     │  │  │  └─ cuda_upsample_layer_acc.cu
   │  │  │     │  │  ├─ cuda_blob_converter.cc
   │  │  │     │  │  ├─ cuda_blob_converter.h
   │  │  │     │  │  ├─ cuda_blob_converter_kernel.cu
   │  │  │     │  │  ├─ cuda_blob_converter_kernel.cuh
   │  │  │     │  │  ├─ cuda_context.cc
   │  │  │     │  │  ├─ cuda_context.h
   │  │  │     │  │  ├─ cuda_device.cc
   │  │  │     │  │  ├─ cuda_device.h
   │  │  │     │  │  ├─ cuda_macro.h
   │  │  │     │  │  ├─ cuda_mat_converter.cc
   │  │  │     │  │  ├─ cuda_mat_converter.h
   │  │  │     │  │  ├─ cuda_mat_util.cu
   │  │  │     │  │  ├─ cuda_mat_util.cuh
   │  │  │     │  │  ├─ fastdiv.h
   │  │  │     │  │  ├─ thirdparty
   │  │  │     │  │  │  └─ cub-1.9.10-1
   │  │  │     │  │  │     ├─ .cproject
   │  │  │     │  │  │     ├─ .gitignore
   │  │  │     │  │  │     ├─ .project
   │  │  │     │  │  │     ├─ .settings
   │  │  │     │  │  │     │  ├─ .gitignore
   │  │  │     │  │  │     │  ├─ org.eclipse.cdt.codan.core.prefs
   │  │  │     │  │  │     │  ├─ org.eclipse.cdt.core.prefs
   │  │  │     │  │  │     │  ├─ org.eclipse.cdt.ui.prefs
   │  │  │     │  │  │     │  └─ org.eclipse.core.runtime.prefs
   │  │  │     │  │  │     ├─ CHANGELOG.md
   │  │  │     │  │  │     ├─ CMakeLists.txt
   │  │  │     │  │  │     ├─ DEVELOPMENT_MODEL.md
   │  │  │     │  │  │     ├─ LICENSE.TXT
   │  │  │     │  │  │     ├─ README.md
   │  │  │     │  │  │     ├─ cmake
   │  │  │     │  │  │     │  ├─ AppendOptionIfAvailable.cmake
   │  │  │     │  │  │     │  ├─ header_test.in
   │  │  │     │  │  │     │  ├─ run_example.cmake
   │  │  │     │  │  │     │  └─ run_test.cmake
   │  │  │     │  │  │     ├─ common.mk
   │  │  │     │  │  │     ├─ cub
   │  │  │     │  │  │     │  ├─ agent
   │  │  │     │  │  │     │  │  ├─ agent_histogram.cuh
   │  │  │     │  │  │     │  │  ├─ agent_radix_sort_downsweep.cuh
   │  │  │     │  │  │     │  │  ├─ agent_radix_sort_upsweep.cuh
   │  │  │     │  │  │     │  │  ├─ agent_reduce.cuh
   │  │  │     │  │  │     │  │  ├─ agent_reduce_by_key.cuh
   │  │  │     │  │  │     │  │  ├─ agent_rle.cuh
   │  │  │     │  │  │     │  │  ├─ agent_scan.cuh
   │  │  │     │  │  │     │  │  ├─ agent_segment_fixup.cuh
   │  │  │     │  │  │     │  │  ├─ agent_select_if.cuh
   │  │  │     │  │  │     │  │  ├─ agent_spmv_orig.cuh
   │  │  │     │  │  │     │  │  └─ single_pass_scan_operators.cuh
   │  │  │     │  │  │     │  ├─ block
   │  │  │     │  │  │     │  │  ├─ block_adjacent_difference.cuh
   │  │  │     │  │  │     │  │  ├─ block_discontinuity.cuh
   │  │  │     │  │  │     │  │  ├─ block_exchange.cuh
   │  │  │     │  │  │     │  │  ├─ block_histogram.cuh
   │  │  │     │  │  │     │  │  ├─ block_load.cuh
   │  │  │     │  │  │     │  │  ├─ block_radix_rank.cuh
   │  │  │     │  │  │     │  │  ├─ block_radix_sort.cuh
   │  │  │     │  │  │     │  │  ├─ block_raking_layout.cuh
   │  │  │     │  │  │     │  │  ├─ block_reduce.cuh
   │  │  │     │  │  │     │  │  ├─ block_scan.cuh
   │  │  │     │  │  │     │  │  ├─ block_shuffle.cuh
   │  │  │     │  │  │     │  │  ├─ block_store.cuh
   │  │  │     │  │  │     │  │  └─ specializations
   │  │  │     │  │  │     │  │     ├─ block_histogram_atomic.cuh
   │  │  │     │  │  │     │  │     ├─ block_histogram_sort.cuh
   │  │  │     │  │  │     │  │     ├─ block_reduce_raking.cuh
   │  │  │     │  │  │     │  │     ├─ block_reduce_raking_commutative_only.cuh
   │  │  │     │  │  │     │  │     ├─ block_reduce_warp_reductions.cuh
   │  │  │     │  │  │     │  │     ├─ block_scan_raking.cuh
   │  │  │     │  │  │     │  │     ├─ block_scan_warp_scans.cuh
   │  │  │     │  │  │     │  │     ├─ block_scan_warp_scans2.cuh
   │  │  │     │  │  │     │  │     └─ block_scan_warp_scans3.cuh
   │  │  │     │  │  │     │  ├─ cmake
   │  │  │     │  │  │     │  │  ├─ cub-config-version.cmake
   │  │  │     │  │  │     │  │  └─ cub-config.cmake
   │  │  │     │  │  │     │  ├─ config.cuh
   │  │  │     │  │  │     │  ├─ cub.cuh
   │  │  │     │  │  │     │  ├─ device
   │  │  │     │  │  │     │  │  ├─ device_histogram.cuh
   │  │  │     │  │  │     │  │  ├─ device_partition.cuh
   │  │  │     │  │  │     │  │  ├─ device_radix_sort.cuh
   │  │  │     │  │  │     │  │  ├─ device_reduce.cuh
   │  │  │     │  │  │     │  │  ├─ device_run_length_encode.cuh
   │  │  │     │  │  │     │  │  ├─ device_scan.cuh
   │  │  │     │  │  │     │  │  ├─ device_segmented_radix_sort.cuh
   │  │  │     │  │  │     │  │  ├─ device_segmented_reduce.cuh
   │  │  │     │  │  │     │  │  ├─ device_select.cuh
   │  │  │     │  │  │     │  │  ├─ device_spmv.cuh
   │  │  │     │  │  │     │  │  └─ dispatch
   │  │  │     │  │  │     │  │     ├─ dispatch_histogram.cuh
   │  │  │     │  │  │     │  │     ├─ dispatch_radix_sort.cuh
   │  │  │     │  │  │     │  │     ├─ dispatch_reduce.cuh
   │  │  │     │  │  │     │  │     ├─ dispatch_reduce_by_key.cuh
   │  │  │     │  │  │     │  │     ├─ dispatch_rle.cuh
   │  │  │     │  │  │     │  │     ├─ dispatch_scan.cuh
   │  │  │     │  │  │     │  │     ├─ dispatch_select_if.cuh
   │  │  │     │  │  │     │  │     └─ dispatch_spmv_orig.cuh
   │  │  │     │  │  │     │  ├─ grid
   │  │  │     │  │  │     │  │  ├─ grid_barrier.cuh
   │  │  │     │  │  │     │  │  ├─ grid_even_share.cuh
   │  │  │     │  │  │     │  │  ├─ grid_mapping.cuh
   │  │  │     │  │  │     │  │  └─ grid_queue.cuh
   │  │  │     │  │  │     │  ├─ host
   │  │  │     │  │  │     │  │  └─ mutex.cuh
   │  │  │     │  │  │     │  ├─ iterator
   │  │  │     │  │  │     │  │  ├─ arg_index_input_iterator.cuh
   │  │  │     │  │  │     │  │  ├─ cache_modified_input_iterator.cuh
   │  │  │     │  │  │     │  │  ├─ cache_modified_output_iterator.cuh
   │  │  │     │  │  │     │  │  ├─ constant_input_iterator.cuh
   │  │  │     │  │  │     │  │  ├─ counting_input_iterator.cuh
   │  │  │     │  │  │     │  │  ├─ discard_output_iterator.cuh
   │  │  │     │  │  │     │  │  ├─ tex_obj_input_iterator.cuh
   │  │  │     │  │  │     │  │  ├─ tex_ref_input_iterator.cuh
   │  │  │     │  │  │     │  │  └─ transform_input_iterator.cuh
   │  │  │     │  │  │     │  ├─ thread
   │  │  │     │  │  │     │  │  ├─ thread_load.cuh
   │  │  │     │  │  │     │  │  ├─ thread_operators.cuh
   │  │  │     │  │  │     │  │  ├─ thread_reduce.cuh
   │  │  │     │  │  │     │  │  ├─ thread_scan.cuh
   │  │  │     │  │  │     │  │  ├─ thread_search.cuh
   │  │  │     │  │  │     │  │  └─ thread_store.cuh
   │  │  │     │  │  │     │  ├─ util_allocator.cuh
   │  │  │     │  │  │     │  ├─ util_arch.cuh
   │  │  │     │  │  │     │  ├─ util_compiler.cuh
   │  │  │     │  │  │     │  ├─ util_cpp_dialect.cuh
   │  │  │     │  │  │     │  ├─ util_debug.cuh
   │  │  │     │  │  │     │  ├─ util_deprecated.cuh
   │  │  │     │  │  │     │  ├─ util_device.cuh
   │  │  │     │  │  │     │  ├─ util_macro.cuh
   │  │  │     │  │  │     │  ├─ util_namespace.cuh
   │  │  │     │  │  │     │  ├─ util_ptx.cuh
   │  │  │     │  │  │     │  ├─ util_type.cuh
   │  │  │     │  │  │     │  ├─ version.cuh
   │  │  │     │  │  │     │  └─ warp
   │  │  │     │  │  │     │     ├─ specializations
   │  │  │     │  │  │     │     │  ├─ warp_reduce_shfl.cuh
   │  │  │     │  │  │     │     │  ├─ warp_reduce_smem.cuh
   │  │  │     │  │  │     │     │  ├─ warp_scan_shfl.cuh
   │  │  │     │  │  │     │     │  └─ warp_scan_smem.cuh
   │  │  │     │  │  │     │     ├─ warp_reduce.cuh
   │  │  │     │  │  │     │     └─ warp_scan.cuh
   │  │  │     │  │  │     ├─ eclipse code style profile.xml
   │  │  │     │  │  │     ├─ examples
   │  │  │     │  │  │     │  ├─ block
   │  │  │     │  │  │     │  │  ├─ .gitignore
   │  │  │     │  │  │     │  │  ├─ example_block_radix_sort.cu
   │  │  │     │  │  │     │  │  ├─ example_block_reduce.cu
   │  │  │     │  │  │     │  │  ├─ example_block_scan.cu
   │  │  │     │  │  │     │  │  └─ reduce_by_key.cu
   │  │  │     │  │  │     │  └─ device
   │  │  │     │  │  │     │     ├─ .gitignore
   │  │  │     │  │  │     │     ├─ example_device_partition_flagged.cu
   │  │  │     │  │  │     │     ├─ example_device_partition_if.cu
   │  │  │     │  │  │     │     ├─ example_device_radix_sort.cu
   │  │  │     │  │  │     │     ├─ example_device_reduce.cu
   │  │  │     │  │  │     │     ├─ example_device_scan.cu
   │  │  │     │  │  │     │     ├─ example_device_select_flagged.cu
   │  │  │     │  │  │     │     ├─ example_device_select_if.cu
   │  │  │     │  │  │     │     ├─ example_device_select_unique.cu
   │  │  │     │  │  │     │     └─ example_device_sort_find_non_trivial_runs.cu
   │  │  │     │  │  │     ├─ experimental
   │  │  │     │  │  │     │  ├─ .gitignore
   │  │  │     │  │  │     │  ├─ defunct
   │  │  │     │  │  │     │  │  ├─ example_coo_spmv.cu
   │  │  │     │  │  │     │  │  └─ test_device_seg_reduce.cu
   │  │  │     │  │  │     │  ├─ histogram
   │  │  │     │  │  │     │  │  ├─ histogram_cub.h
   │  │  │     │  │  │     │  │  ├─ histogram_gmem_atomics.h
   │  │  │     │  │  │     │  │  └─ histogram_smem_atomics.h
   │  │  │     │  │  │     │  ├─ histogram_compare.cu
   │  │  │     │  │  │     │  ├─ sparse_matrix.h
   │  │  │     │  │  │     │  ├─ spmv_compare.cu
   │  │  │     │  │  │     │  └─ spmv_script.sh
   │  │  │     │  │  │     ├─ test
   │  │  │     │  │  │     │  ├─ .gitignore
   │  │  │     │  │  │     │  ├─ half.h
   │  │  │     │  │  │     │  ├─ link_a.cu
   │  │  │     │  │  │     │  ├─ link_b.cu
   │  │  │     │  │  │     │  ├─ link_main.cpp
   │  │  │     │  │  │     │  ├─ mersenne.h
   │  │  │     │  │  │     │  ├─ test_allocator.cu
   │  │  │     │  │  │     │  ├─ test_block_histogram.cu
   │  │  │     │  │  │     │  ├─ test_block_load_store.cu
   │  │  │     │  │  │     │  ├─ test_block_radix_sort.cu
   │  │  │     │  │  │     │  ├─ test_block_reduce.cu
   │  │  │     │  │  │     │  ├─ test_block_scan.cu
   │  │  │     │  │  │     │  ├─ test_device_histogram.cu
   │  │  │     │  │  │     │  ├─ test_device_radix_sort.cu
   │  │  │     │  │  │     │  ├─ test_device_reduce.cu
   │  │  │     │  │  │     │  ├─ test_device_reduce_by_key.cu
   │  │  │     │  │  │     │  ├─ test_device_run_length_encode.cu
   │  │  │     │  │  │     │  ├─ test_device_scan.cu
   │  │  │     │  │  │     │  ├─ test_device_select_if.cu
   │  │  │     │  │  │     │  ├─ test_device_select_unique.cu
   │  │  │     │  │  │     │  ├─ test_grid_barrier.cu
   │  │  │     │  │  │     │  ├─ test_iterator.cu
   │  │  │     │  │  │     │  ├─ test_util.h
   │  │  │     │  │  │     │  ├─ test_warp_reduce.cu
   │  │  │     │  │  │     │  └─ test_warp_scan.cu
   │  │  │     │  │  │     └─ tune
   │  │  │     │  │  │        ├─ .gitignore
   │  │  │     │  │  │        └─ tune_device_reduce.cu
   │  │  │     │  │  ├─ utils.cu
   │  │  │     │  │  └─ utils.cuh
   │  │  │     │  ├─ huawei_npu
   │  │  │     │  │  ├─ CMakeLists.txt
   │  │  │     │  │  ├─ convert
   │  │  │     │  │  │  ├─ math
   │  │  │     │  │  │  │  ├─ npu_acos_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_add_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_asin_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_atan_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_binary_layer_convert.h
   │  │  │     │  │  │  │  ├─ npu_ceil_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_cos_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_div_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_exp_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_floor_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_hardswish_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_log_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_log_sigmoid_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_max_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_min_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_mul_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_neg_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_pow_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_reciprocal_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_sign_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_sin_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_sqrt_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_sub_layer_convert.cc
   │  │  │     │  │  │  │  ├─ npu_tan_layer_convert.cc
   │  │  │     │  │  │  │  └─ npu_unary_operator.h
   │  │  │     │  │  │  ├─ npu_activation_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_arg_max_or_min_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_base_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_base_layer_convert.h
   │  │  │     │  │  │  ├─ npu_batch_norm_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_cast_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_clip_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_concat_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_conv_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_conv_layer_convert_impl.h
   │  │  │     │  │  │  ├─ npu_deconv_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_flatten_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_gather_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_inner_product_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_instance_norm_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_lrn_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_matmul_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_normalize_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_pad_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_permute_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_pooling_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_prelu_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_prior_box_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_reduce_layer_convert.h
   │  │  │     │  │  │  ├─ npu_reduce_logsumexp_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_reduce_max_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_reduce_mean_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_reduce_min_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_reduce_prod_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_reduce_sum_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_reshape_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_shape_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_shuffle_channel_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_softmax_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_splitv_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_squeeze_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_stride_slice_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_stride_slicev2_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_unsqueeze_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_upsample_layer_convert.cc
   │  │  │     │  │  │  ├─ npu_utils.cc
   │  │  │     │  │  │  └─ npu_utils.h
   │  │  │     │  │  ├─ npu_blob_converter.cc
   │  │  │     │  │  ├─ npu_context.cc
   │  │  │     │  │  ├─ npu_context.h
   │  │  │     │  │  ├─ npu_device.cc
   │  │  │     │  │  ├─ npu_device.h
   │  │  │     │  │  ├─ npu_network.cc
   │  │  │     │  │  └─ npu_network.h
   │  │  │     │  ├─ metal
   │  │  │     │  │  ├─ CMakeLists.txt
   │  │  │     │  │  ├─ acc
   │  │  │     │  │  │  ├─ convolution
   │  │  │     │  │  │  │  ├─ metal_conv_layer_1x1.h
   │  │  │     │  │  │  │  ├─ metal_conv_layer_1x1.metal
   │  │  │     │  │  │  │  ├─ metal_conv_layer_1x1.mm
   │  │  │     │  │  │  │  ├─ metal_conv_layer_acc.h
   │  │  │     │  │  │  │  ├─ metal_conv_layer_acc.mm
   │  │  │     │  │  │  │  ├─ metal_conv_layer_common.h
   │  │  │     │  │  │  │  ├─ metal_conv_layer_common.metal
   │  │  │     │  │  │  │  ├─ metal_conv_layer_common.mm
   │  │  │     │  │  │  │  ├─ metal_conv_layer_depthwise.h
   │  │  │     │  │  │  │  ├─ metal_conv_layer_depthwise.metal
   │  │  │     │  │  │  │  ├─ metal_conv_layer_depthwise.mm
   │  │  │     │  │  │  │  ├─ metal_conv_layer_winograd.h
   │  │  │     │  │  │  │  ├─ metal_conv_layer_winograd.metal
   │  │  │     │  │  │  │  ├─ metal_conv_layer_winograd.mm
   │  │  │     │  │  │  │  ├─ metal_inner_product_layer_acc.h
   │  │  │     │  │  │  │  ├─ metal_inner_product_layer_acc.metal
   │  │  │     │  │  │  │  └─ metal_inner_product_layer_acc.mm
   │  │  │     │  │  │  ├─ deconvolution
   │  │  │     │  │  │  │  ├─ metal_deconv_layer_acc.h
   │  │  │     │  │  │  │  ├─ metal_deconv_layer_acc.mm
   │  │  │     │  │  │  │  ├─ metal_deconv_layer_common.h
   │  │  │     │  │  │  │  ├─ metal_deconv_layer_common.metal
   │  │  │     │  │  │  │  ├─ metal_deconv_layer_common.mm
   │  │  │     │  │  │  │  ├─ metal_deconv_layer_depthwise.h
   │  │  │     │  │  │  │  ├─ metal_deconv_layer_depthwise.metal
   │  │  │     │  │  │  │  └─ metal_deconv_layer_depthwise.mm
   │  │  │     │  │  │  ├─ metal_abs_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_abs_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_acos_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_acos_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_add_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_add_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_arg_max_or_min_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_arg_max_or_min_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_asin_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_asin_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_atan_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_atan_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_batch_norm_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_batch_norm_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_cast_layer_acc.h
   │  │  │     │  │  │  ├─ metal_cast_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_cast_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_ceil_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_ceil_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_clip_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_clip_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_common.h
   │  │  │     │  │  │  ├─ metal_common.metal
   │  │  │     │  │  │  ├─ metal_concat_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_concat_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_cos_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_cos_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_cpu_adapter_acc.h
   │  │  │     │  │  │  ├─ metal_cpu_adapter_acc.mm
   │  │  │     │  │  │  ├─ metal_div_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_div_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_elu_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_elu_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_exp_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_exp_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_flatten_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_floor_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_floor_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_gather_layer_acc.h
   │  │  │     │  │  │  ├─ metal_gather_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_gather_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_hard_sigmoid_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_hard_sigmoid_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_hard_swish_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_hard_swish_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_hdrguide_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_hdrguide_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_instance_norm_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_instance_norm_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_layer_acc.h
   │  │  │     │  │  │  ├─ metal_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_log_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_log_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_log_sigmoid_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_log_sigmoid_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_lrn_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_lrn_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_mat_mul_layer_acc.h
   │  │  │     │  │  │  ├─ metal_mat_mul_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_mat_mul_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_max_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_max_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_min_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_min_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_mul_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_mul_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_multidir_broadcast_layer_acc.h
   │  │  │     │  │  │  ├─ metal_multidir_broadcast_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_neg_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_neg_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_normalize_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_normalize_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_pad_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_pad_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_permute_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_permute_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_pixel_shuffle_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_pixel_shuffle_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_pooling_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_pooling_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_pow_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_pow_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_prelu_layer_acc.h
   │  │  │     │  │  │  ├─ metal_prelu_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_prelu_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_prior_box_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_prior_box_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reciprocal_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_reciprocal_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_l1_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_l2_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_layer_acc.h
   │  │  │     │  │  │  ├─ metal_reduce_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_reduce_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_log_sum_exp_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_log_sum_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_max_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_mean_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_min_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_prod_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_sum_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reduce_sum_square_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reformat_layer_acc.h
   │  │  │     │  │  │  ├─ metal_reformat_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_reformat_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_relu6_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_relu6_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_relu_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_relu_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reorg_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_reorg_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_reshape_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_reshape_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_selu_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_selu_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_shuffle_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_shuffle_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_sigmoid_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_sigmoid_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_sign_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_sign_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_signed_mul_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_signed_mul_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_sin_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_sin_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_softmax_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_softmax_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_softplus_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_softplus_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_splitv_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_splitv_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_sqrt_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_sqrt_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_squeeze_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_squeeze_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_stride_slice_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_stride_slice_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_stride_slice_v2_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_sub_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_sub_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_tan_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_tan_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_tanh_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_tanh_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_tile_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_tile_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_unary_layer_acc.h
   │  │  │     │  │  │  ├─ metal_unary_layer_acc.mm
   │  │  │     │  │  │  ├─ metal_upsample_layer_acc.metal
   │  │  │     │  │  │  ├─ metal_upsample_layer_acc.mm
   │  │  │     │  │  │  └─ recurrent
   │  │  │     │  │  │     ├─ metal_lstm_layer_acc.h
   │  │  │     │  │  │     ├─ metal_lstm_layer_acc.metal
   │  │  │     │  │  │     └─ metal_lstm_layer_acc.mm
   │  │  │     │  │  ├─ build_tnn_metallib.sh
   │  │  │     │  │  ├─ coreml_network.h
   │  │  │     │  │  ├─ coreml_network.mm
   │  │  │     │  │  ├─ metal_blob_converter.metal
   │  │  │     │  │  ├─ metal_blob_converter.mm
   │  │  │     │  │  ├─ metal_command_queue.h
   │  │  │     │  │  ├─ metal_command_queue.mm
   │  │  │     │  │  ├─ metal_context.h
   │  │  │     │  │  ├─ metal_context.mm
   │  │  │     │  │  ├─ metal_device.h
   │  │  │     │  │  ├─ metal_device.mm
   │  │  │     │  │  ├─ metal_macro.h
   │  │  │     │  │  ├─ metal_mat_converter.metal
   │  │  │     │  │  ├─ metal_mat_converter.mm
   │  │  │     │  │  ├─ tnn_impl_coreml.h
   │  │  │     │  │  └─ tnn_impl_coreml.mm
   │  │  │     │  ├─ opencl
   │  │  │     │  │  ├─ CMakeLists.txt
   │  │  │     │  │  ├─ acc
   │  │  │     │  │  │  ├─ convolution
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_1x1_acc.cc
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_1x1_acc.h
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_acc.cc
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_acc_impl.cc
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_acc_impl.h
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_common_acc.cc
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_common_acc.h
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_depthwise_acc.cc
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_depthwise_acc.h
   │  │  │     │  │  │  │  ├─ opencl_conv_layer_winograd_acc.cc
   │  │  │     │  │  │  │  └─ opencl_conv_layer_winograd_acc.h
   │  │  │     │  │  │  ├─ deconvolution
   │  │  │     │  │  │  │  ├─ opencl_deconv_layer_acc.cc
   │  │  │     │  │  │  │  ├─ opencl_deconv_layer_acc_impl.cc
   │  │  │     │  │  │  │  ├─ opencl_deconv_layer_acc_impl.h
   │  │  │     │  │  │  │  ├─ opencl_deconv_layer_common_acc.cc
   │  │  │     │  │  │  │  ├─ opencl_deconv_layer_common_acc.h
   │  │  │     │  │  │  │  ├─ opencl_deconv_layer_depthwise_acc.cc
   │  │  │     │  │  │  │  └─ opencl_deconv_layer_depthwise_acc.h
   │  │  │     │  │  │  ├─ opencl_abs_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_acos_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_add_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_arg_max_or_min_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_asin_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_atan_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_batch_norm_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_binary_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_binary_layer_acc.h
   │  │  │     │  │  │  ├─ opencl_cast_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_ceil_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_clip_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_concat_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_cos_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_cpu_adapter_acc.cc
   │  │  │     │  │  │  ├─ opencl_cpu_adapter_acc.h
   │  │  │     │  │  │  ├─ opencl_div_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_elu_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_exp_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_expand_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_expand_layer_acc.h
   │  │  │     │  │  │  ├─ opencl_floor_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_gather_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_gridsample_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_hard_sigmoid_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_hard_swish_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_hdr_guide_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_inner_product_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_instance_norm_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_inverse_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_layer_acc.h
   │  │  │     │  │  │  ├─ opencl_log_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_logsigmoid_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_lstm_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_lstm_layer_acc.h
   │  │  │     │  │  │  ├─ opencl_mat_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_mat_mul_layer_acc.h
   │  │  │     │  │  │  ├─ opencl_max_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_min_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_neg_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_normalize_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_pad_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_padv2_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_permute_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_pixel_shuffle_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_pooling_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_pow_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_prelu_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_prior_box_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reciprocal_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_l1_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_l2_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_layer_acc.h
   │  │  │     │  │  │  ├─ opencl_reduce_log_sum_exp_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_log_sum_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_max_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_mean_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_min_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_prod_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_sum_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reduce_sum_square_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reformat_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reformat_layer_acc.h
   │  │  │     │  │  │  ├─ opencl_relu6_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_relu_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reorg_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reshape_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_reshape_layer_acc.h
   │  │  │     │  │  │  ├─ opencl_selu_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_shuffle_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_sigmoid_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_sign_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_signed_mul_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_sin_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_softmax_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_softplus_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_split_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_splitv_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_sqrt_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_squeeze_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_stride_slice_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_stride_slice_v2_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_sub_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_tan_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_tanh_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_tile_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_unary_layer_acc.cc
   │  │  │     │  │  │  ├─ opencl_unary_layer_acc.h
   │  │  │     │  │  │  └─ opencl_upsample_layer_acc.cc
   │  │  │     │  │  ├─ cl
   │  │  │     │  │  │  ├─ activation.inc
   │  │  │     │  │  │  ├─ arg.cl
   │  │  │     │  │  │  ├─ base.inc
   │  │  │     │  │  │  ├─ batch_norm.cl
   │  │  │     │  │  │  ├─ binary.cl
   │  │  │     │  │  │  ├─ blob_5d_convert_from_mat.cl
   │  │  │     │  │  │  ├─ blob_5d_convert_to_mat.cl
   │  │  │     │  │  │  ├─ blob_6d_convert_from_mat.cl
   │  │  │     │  │  │  ├─ blob_6d_convert_to_mat.cl
   │  │  │     │  │  │  ├─ buffer_to_buffer.cl
   │  │  │     │  │  │  ├─ buffer_to_image.cl
   │  │  │     │  │  │  ├─ buffer_to_image_5d.cl
   │  │  │     │  │  │  ├─ buffer_to_image_6d.cl
   │  │  │     │  │  │  ├─ concat.cl
   │  │  │     │  │  │  ├─ convert_from_mat.cl
   │  │  │     │  │  │  ├─ convert_to_mat.cl
   │  │  │     │  │  │  ├─ convolution.cl
   │  │  │     │  │  │  ├─ convolution_1x1.cl
   │  │  │     │  │  │  ├─ convolution_1x1_gws_3d.cl
   │  │  │     │  │  │  ├─ convolution_1x1_mix.cl
   │  │  │     │  │  │  ├─ convolution_depthwise.cl
   │  │  │     │  │  │  ├─ convolution_gws_3d.cl
   │  │  │     │  │  │  ├─ convolution_mix.cl
   │  │  │     │  │  │  ├─ copy.cl
   │  │  │     │  │  │  ├─ copy_buffer_to_image2d.cl
   │  │  │     │  │  │  ├─ copy_image_5d.cl
   │  │  │     │  │  │  ├─ copy_image_6d.cl
   │  │  │     │  │  │  ├─ deconvolution.cl
   │  │  │     │  │  │  ├─ expand.cl
   │  │  │     │  │  │  ├─ gather.cl
   │  │  │     │  │  │  ├─ gridsample.cl
   │  │  │     │  │  │  ├─ hard_sigmoid.cl
   │  │  │     │  │  │  ├─ hdr_guide.cl
   │  │  │     │  │  │  ├─ image_5d_to_buffer.cl
   │  │  │     │  │  │  ├─ image_6d_to_buffer.cl
   │  │  │     │  │  │  ├─ image_to_buffer.cl
   │  │  │     │  │  │  ├─ image_to_image.cl
   │  │  │     │  │  │  ├─ innerproduct.cl
   │  │  │     │  │  │  ├─ instance_norm.cl
   │  │  │     │  │  │  ├─ inverse.cl
   │  │  │     │  │  │  ├─ io.inc
   │  │  │     │  │  │  ├─ lstm.cl
   │  │  │     │  │  │  ├─ matmul.cl
   │  │  │     │  │  │  ├─ normalize.cl
   │  │  │     │  │  │  ├─ opencl_codegen.py
   │  │  │     │  │  │  ├─ pad.cl
   │  │  │     │  │  │  ├─ pixel_shuffle.cl
   │  │  │     │  │  │  ├─ pooling.cl
   │  │  │     │  │  │  ├─ pow.cl
   │  │  │     │  │  │  ├─ prelu.cl
   │  │  │     │  │  │  ├─ reduce.cl
   │  │  │     │  │  │  ├─ reduce_max.cl
   │  │  │     │  │  │  ├─ reduce_mean.cl
   │  │  │     │  │  │  ├─ reorg.cl
   │  │  │     │  │  │  ├─ selu.cl
   │  │  │     │  │  │  ├─ shuffle.cl
   │  │  │     │  │  │  ├─ signed_mul.cl
   │  │  │     │  │  │  ├─ softmax.cl
   │  │  │     │  │  │  ├─ stride_slice.cl
   │  │  │     │  │  │  ├─ tile.cl
   │  │  │     │  │  │  ├─ unary.cl
   │  │  │     │  │  │  ├─ upsample.cl
   │  │  │     │  │  │  ├─ warp_affine.cl
   │  │  │     │  │  │  └─ winograd.cl
   │  │  │     │  │  ├─ imagebuffer_convertor.cc
   │  │  │     │  │  ├─ imagebuffer_convertor.h
   │  │  │     │  │  ├─ opencl_blob_converter.cc
   │  │  │     │  │  ├─ opencl_blob_converter.h
   │  │  │     │  │  ├─ opencl_context.cc
   │  │  │     │  │  ├─ opencl_context.h
   │  │  │     │  │  ├─ opencl_device.cc
   │  │  │     │  │  ├─ opencl_device.h
   │  │  │     │  │  ├─ opencl_execute_unit.h
   │  │  │     │  │  ├─ opencl_mat_converter.cc
   │  │  │     │  │  ├─ opencl_mat_converter.h
   │  │  │     │  │  ├─ opencl_memory.cc
   │  │  │     │  │  ├─ opencl_memory.h
   │  │  │     │  │  ├─ opencl_runtime.cc
   │  │  │     │  │  ├─ opencl_runtime.h
   │  │  │     │  │  ├─ opencl_utils.cc
   │  │  │     │  │  ├─ opencl_utils.h
   │  │  │     │  │  ├─ opencl_wrapper.cc
   │  │  │     │  │  └─ opencl_wrapper.h
   │  │  │     │  ├─ rknpu
   │  │  │     │  │  ├─ CMakeLists.txt
   │  │  │     │  │  ├─ convert
   │  │  │     │  │  │  ├─ math
   │  │  │     │  │  │  │  ├─ rknpu_abs_layer.cc
   │  │  │     │  │  │  │  ├─ rknpu_add_layer.cc
   │  │  │     │  │  │  │  ├─ rknpu_binary_layer.h
   │  │  │     │  │  │  │  ├─ rknpu_max_layer.cc
   │  │  │     │  │  │  │  ├─ rknpu_mul_layer.cc
   │  │  │     │  │  │  │  ├─ rknpu_neg_layer.cc
   │  │  │     │  │  │  │  ├─ rknpu_sqrt_layer.cc
   │  │  │     │  │  │  │  ├─ rknpu_sub_layer.cc
   │  │  │     │  │  │  │  └─ rknpu_unary_operator.h
   │  │  │     │  │  │  ├─ rknpu_activation_layer.cc
   │  │  │     │  │  │  ├─ rknpu_base_layer.cc
   │  │  │     │  │  │  ├─ rknpu_base_layer.h
   │  │  │     │  │  │  ├─ rknpu_batch_norm_layer.cc
   │  │  │     │  │  │  ├─ rknpu_batch_norm_layer_impl.h
   │  │  │     │  │  │  ├─ rknpu_concat_layer.cc
   │  │  │     │  │  │  ├─ rknpu_conv_layer.cc
   │  │  │     │  │  │  ├─ rknpu_conv_layer_impl.h
   │  │  │     │  │  │  ├─ rknpu_flatten_layer.cc
   │  │  │     │  │  │  ├─ rknpu_gather_layer.cc
   │  │  │     │  │  │  ├─ rknpu_inner_product_layer.cc
   │  │  │     │  │  │  ├─ rknpu_normalize_layer.cc
   │  │  │     │  │  │  ├─ rknpu_pad_layer.cc
   │  │  │     │  │  │  ├─ rknpu_permute_layer.cc
   │  │  │     │  │  │  ├─ rknpu_pooling_layer.cc
   │  │  │     │  │  │  ├─ rknpu_reduce_mean_layer.cc
   │  │  │     │  │  │  ├─ rknpu_reshape_layer.cc
   │  │  │     │  │  │  ├─ rknpu_slice_layer.cc
   │  │  │     │  │  │  ├─ rknpu_softmax_layer.cc
   │  │  │     │  │  │  ├─ rknpu_stride_slice_layer.cc
   │  │  │     │  │  │  ├─ rknpu_utils.cc
   │  │  │     │  │  │  └─ rknpu_utils.h
   │  │  │     │  │  ├─ rknpu_blob_converter.cc
   │  │  │     │  │  ├─ rknpu_context.cc
   │  │  │     │  │  ├─ rknpu_context.h
   │  │  │     │  │  ├─ rknpu_device.cc
   │  │  │     │  │  ├─ rknpu_device.h
   │  │  │     │  │  ├─ rknpu_model_interpreter.cc
   │  │  │     │  │  ├─ rknpu_network.cc
   │  │  │     │  │  ├─ rknpu_network.h
   │  │  │     │  │  ├─ tnn_impl_rknpu.cc
   │  │  │     │  │  └─ tnn_impl_rknpu.h
   │  │  │     │  └─ x86
   │  │  │     │     ├─ CMakeLists.txt
   │  │  │     │     ├─ acc
   │  │  │     │     │  ├─ Float4.h
   │  │  │     │     │  ├─ Float8.h
   │  │  │     │     │  ├─ avx_mathfun.h
   │  │  │     │     │  ├─ compute
   │  │  │     │     │  │  ├─ jit
   │  │  │     │     │  │  │  ├─ cblas.h
   │  │  │     │     │  │  │  ├─ cblas_driver.cc
   │  │  │     │     │  │  │  ├─ common
   │  │  │     │     │  │  │  │  ├─ abi_info.h
   │  │  │     │     │  │  │  │  ├─ asm_common.h
   │  │  │     │     │  │  │  │  └─ type_def.h
   │  │  │     │     │  │  │  ├─ conv_data_packing.cc
   │  │  │     │     │  │  │  ├─ conv_data_packing.h
   │  │  │     │     │  │  │  ├─ conv_gemm_config.cc
   │  │  │     │     │  │  │  ├─ conv_gemm_config.h
   │  │  │     │     │  │  │  ├─ conv_sgemm_driver.cc
   │  │  │     │     │  │  │  ├─ conv_sgemm_driver.h
   │  │  │     │     │  │  │  ├─ data_packing.cc
   │  │  │     │     │  │  │  ├─ data_packing.h
   │  │  │     │     │  │  │  ├─ gemm_config.cc
   │  │  │     │     │  │  │  ├─ gemm_config.h
   │  │  │     │     │  │  │  ├─ kernels
   │  │  │     │     │  │  │  │  ├─ base_jit_kernel.h
   │  │  │     │     │  │  │  │  ├─ conv_sgemm_avx_16_i.h
   │  │  │     │     │  │  │  │  ├─ conv_sgemm_avx_1_i.h
   │  │  │     │     │  │  │  │  ├─ conv_sgemm_avx_2_i.h
   │  │  │     │     │  │  │  │  ├─ conv_sgemm_avx_4_i.h
   │  │  │     │     │  │  │  │  ├─ conv_sgemm_avx_8_i.h
   │  │  │     │     │  │  │  │  ├─ conv_sgemm_avx_kernels.h
   │  │  │     │     │  │  │  │  ├─ jit_kernels.h
   │  │  │     │     │  │  │  │  ├─ sgemm_avx_16_i.h
   │  │  │     │     │  │  │  │  ├─ sgemm_avx_1_i.h
   │  │  │     │     │  │  │  │  ├─ sgemm_avx_2_i.h
   │  │  │     │     │  │  │  │  ├─ sgemm_avx_4_i.h
   │  │  │     │     │  │  │  │  ├─ sgemm_avx_8_i.h
   │  │  │     │     │  │  │  │  ├─ sgemm_avx_kernels.h
   │  │  │     │     │  │  │  │  ├─ sgemm_fetch_n.h
   │  │  │     │     │  │  │  │  ├─ sgemm_fetch_n_6.h
   │  │  │     │     │  │  │  │  ├─ sgemm_fetch_t.h
   │  │  │     │     │  │  │  │  ├─ sgemm_fetch_t_16.h
   │  │  │     │     │  │  │  │  ├─ sgemm_fetch_t_4.h
   │  │  │     │     │  │  │  │  ├─ sgemm_fetch_t_4x16.h
   │  │  │     │     │  │  │  │  └─ sgemm_fetch_t_8.h
   │  │  │     │     │  │  │  ├─ sgemm_driver.cc
   │  │  │     │     │  │  │  └─ utils
   │  │  │     │     │  │  │     ├─ cpu_isa.cc
   │  │  │     │     │  │  │     ├─ cpu_isa.h
   │  │  │     │     │  │  │     ├─ macro.h
   │  │  │     │     │  │  │     ├─ timer.hpp
   │  │  │     │     │  │  │     └─ utils.h
   │  │  │     │     │  │  ├─ x86_compute.cc
   │  │  │     │     │  │  ├─ x86_compute.h
   │  │  │     │     │  │  ├─ x86_compute_int8.cc
   │  │  │     │     │  │  └─ x86_compute_int8.h
   │  │  │     │     │  ├─ convolution
   │  │  │     │     │  │  ├─ x86_conv_int8_layer_common.cc
   │  │  │     │     │  │  ├─ x86_conv_int8_layer_common.h
   │  │  │     │     │  │  ├─ x86_conv_int8_layer_depthwise.cc
   │  │  │     │     │  │  ├─ x86_conv_int8_layer_depthwise.h
   │  │  │     │     │  │  ├─ x86_conv_layer_1x1.cc
   │  │  │     │     │  │  ├─ x86_conv_layer_1x1.h
   │  │  │     │     │  │  ├─ x86_conv_layer_3x3.cc
   │  │  │     │     │  │  ├─ x86_conv_layer_3x3.h
   │  │  │     │     │  │  ├─ x86_conv_layer_acc_factory.cc
   │  │  │     │     │  │  ├─ x86_conv_layer_acc_factory.h
   │  │  │     │     │  │  ├─ x86_conv_layer_common.cc
   │  │  │     │     │  │  ├─ x86_conv_layer_common.h
   │  │  │     │     │  │  ├─ x86_conv_layer_depthwise.cc
   │  │  │     │     │  │  └─ x86_conv_layer_depthwise.h
   │  │  │     │     │  ├─ deconvolution
   │  │  │     │     │  │  ├─ x86_deconv_layer_common.cc
   │  │  │     │     │  │  └─ x86_deconv_layer_common.h
   │  │  │     │     │  ├─ sse_mathfun.h
   │  │  │     │     │  ├─ x86_abs_layer_acc.cc
   │  │  │     │     │  ├─ x86_acos_layer_acc.cc
   │  │  │     │     │  ├─ x86_add_layer_acc.cc
   │  │  │     │     │  ├─ x86_add_layer_acc.h
   │  │  │     │     │  ├─ x86_arg_max_or_min_layer_acc.cc
   │  │  │     │     │  ├─ x86_asin_layer_acc.cc
   │  │  │     │     │  ├─ x86_atan_layer_acc.cc
   │  │  │     │     │  ├─ x86_batch_norm_layer_acc.cc
   │  │  │     │     │  ├─ x86_batch_norm_layer_acc.h
   │  │  │     │     │  ├─ x86_binary_op_layer_acc.cc
   │  │  │     │     │  ├─ x86_binary_op_layer_acc.h
   │  │  │     │     │  ├─ x86_cast_layer_acc.cc
   │  │  │     │     │  ├─ x86_ceil_layer_acc.cc
   │  │  │     │     │  ├─ x86_clip_layer_acc.cc
   │  │  │     │     │  ├─ x86_concat_layer_acc.cc
   │  │  │     │     │  ├─ x86_conv_layer_acc.cc
   │  │  │     │     │  ├─ x86_conv_layer_acc.h
   │  │  │     │     │  ├─ x86_cos_layer_acc.cc
   │  │  │     │     │  ├─ x86_deconv_layer_acc.cc
   │  │  │     │     │  ├─ x86_deconv_layer_acc.h
   │  │  │     │     │  ├─ x86_detection_output_layer_acc.cc
   │  │  │     │     │  ├─ x86_div_layer_acc.cc
   │  │  │     │     │  ├─ x86_elu_layer_acc.cc
   │  │  │     │     │  ├─ x86_erf_layer_acc.cc
   │  │  │     │     │  ├─ x86_exp_layer_acc.cc
   │  │  │     │     │  ├─ x86_expand_layer_acc.cc
   │  │  │     │     │  ├─ x86_expand_layer_acc.h
   │  │  │     │     │  ├─ x86_flatten_layer_acc.cc
   │  │  │     │     │  ├─ x86_floor_layer_acc.cc
   │  │  │     │     │  ├─ x86_gather_layer_acc.cc
   │  │  │     │     │  ├─ x86_gelu_layer_acc.cc
   │  │  │     │     │  ├─ x86_hard_sigmoid_layer_acc.cc
   │  │  │     │     │  ├─ x86_hard_swish_layer_acc.cc
   │  │  │     │     │  ├─ x86_inner_product_layer_acc.cc
   │  │  │     │     │  ├─ x86_inner_product_layer_acc.h
   │  │  │     │     │  ├─ x86_inst_norm_layer_acc.cc
   │  │  │     │     │  ├─ x86_layer_acc.cc
   │  │  │     │     │  ├─ x86_layer_acc.h
   │  │  │     │     │  ├─ x86_layer_norm_layer_acc.cc
   │  │  │     │     │  ├─ x86_log_layer_acc.cc
   │  │  │     │     │  ├─ x86_log_sigmoid_layer_acc.cc
   │  │  │     │     │  ├─ x86_lrn_layer_acc.cc
   │  │  │     │     │  ├─ x86_lstm_layer_acc.cc
   │  │  │     │     │  ├─ x86_lstm_layer_acc.h
   │  │  │     │     │  ├─ x86_mat_mul_layer_acc.cc
   │  │  │     │     │  ├─ x86_mat_mul_layer_acc.h
   │  │  │     │     │  ├─ x86_max_layer_acc.cc
   │  │  │     │     │  ├─ x86_min_layer_acc.cc
   │  │  │     │     │  ├─ x86_mul_layer_acc.cc
   │  │  │     │     │  ├─ x86_neg_layer_acc.cc
   │  │  │     │     │  ├─ x86_normalize_layer_acc.cc
   │  │  │     │     │  ├─ x86_onehot_layer_acc.cc
   │  │  │     │     │  ├─ x86_pad_layer_acc.cc
   │  │  │     │     │  ├─ x86_permute_layer_acc.cc
   │  │  │     │     │  ├─ x86_permute_layer_acc.h
   │  │  │     │     │  ├─ x86_pixel_shuffle_layer_acc.cc
   │  │  │     │     │  ├─ x86_pool_layer_acc.cc
   │  │  │     │     │  ├─ x86_pool_layer_acc.h
   │  │  │     │     │  ├─ x86_pow_layer_acc.cc
   │  │  │     │     │  ├─ x86_prelu_layer_acc.cc
   │  │  │     │     │  ├─ x86_prelu_layer_acc.h
   │  │  │     │     │  ├─ x86_prior_box_layer_acc.cc
   │  │  │     │     │  ├─ x86_prior_box_layer_acc.h
   │  │  │     │     │  ├─ x86_reciprocal_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_l1_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_l2_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_log_sum_exp_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_log_sum_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_max_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_mean_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_min_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_op_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_op_layer_acc.h
   │  │  │     │     │  ├─ x86_reduce_prod_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_sum_layer_acc.cc
   │  │  │     │     │  ├─ x86_reduce_sum_square_layer_acc.cc
   │  │  │     │     │  ├─ x86_reformat_layer_acc.cc
   │  │  │     │     │  ├─ x86_reformat_layer_acc.h
   │  │  │     │     │  ├─ x86_relu6_layer_acc.cc
   │  │  │     │     │  ├─ x86_relu_layer_acc.cc
   │  │  │     │     │  ├─ x86_relu_layer_acc.h
   │  │  │     │     │  ├─ x86_reorg_layer_acc.cc
   │  │  │     │     │  ├─ x86_reshape_layer_acc.cc
   │  │  │     │     │  ├─ x86_scale_layer_acc.cc
   │  │  │     │     │  ├─ x86_scatter_nd_layer_acc.cc
   │  │  │     │     │  ├─ x86_selu_layer_acc.cc
   │  │  │     │     │  ├─ x86_shuffle_layer_acc.cc
   │  │  │     │     │  ├─ x86_sigmoid_layer_acc.cc
   │  │  │     │     │  ├─ x86_sign_layer_acc.cc
   │  │  │     │     │  ├─ x86_signed_mul_layer_acc.cc
   │  │  │     │     │  ├─ x86_sin_layer_acc.cc
   │  │  │     │     │  ├─ x86_softmax_layer_acc.cc
   │  │  │     │     │  ├─ x86_softplus_layer_acc.cc
   │  │  │     │     │  ├─ x86_softsign_layer_acc.cc
   │  │  │     │     │  ├─ x86_splitv_layer_acc.cc
   │  │  │     │     │  ├─ x86_sqrt_layer_acc.cc
   │  │  │     │     │  ├─ x86_squeeze_layer_acc.cc
   │  │  │     │     │  ├─ x86_stride_slice_layer_acc.cc
   │  │  │     │     │  ├─ x86_stride_slice_v2_layer_acc.cc
   │  │  │     │     │  ├─ x86_stride_slice_v2_layer_acc.h
   │  │  │     │     │  ├─ x86_sub_layer_acc.cc
   │  │  │     │     │  ├─ x86_tan_layer_acc.cc
   │  │  │     │     │  ├─ x86_tanh_layer_acc.cc
   │  │  │     │     │  ├─ x86_unary2_layer_acc.cc
   │  │  │     │     │  ├─ x86_unary2_layer_acc.h
   │  │  │     │     │  ├─ x86_unary_layer_acc.cc
   │  │  │     │     │  ├─ x86_unary_layer_acc.h
   │  │  │     │     │  ├─ x86_unsqueeze_layer_acc.cc
   │  │  │     │     │  ├─ x86_upsample_layer_acc.cc
   │  │  │     │     │  └─ x86_upsample_layer_acc.h
   │  │  │     │     ├─ x86_blob_converter.cc
   │  │  │     │     ├─ x86_blob_converter.h
   │  │  │     │     ├─ x86_common.h
   │  │  │     │     ├─ x86_context.cc
   │  │  │     │     ├─ x86_context.h
   │  │  │     │     ├─ x86_device.cc
   │  │  │     │     ├─ x86_device.h
   │  │  │     │     ├─ x86_mat_converter.cc
   │  │  │     │     ├─ x86_mat_converter.h
   │  │  │     │     ├─ x86_mat_util.cc
   │  │  │     │     ├─ x86_mat_util.h
   │  │  │     │     ├─ x86_util.cc
   │  │  │     │     └─ x86_util.h
   │  │  │     ├─ extern_wrapper
   │  │  │     │  ├─ base_layer_builder.cc
   │  │  │     │  ├─ base_layer_builder.h
   │  │  │     │  ├─ foreign_blob.cc
   │  │  │     │  ├─ foreign_blob.h
   │  │  │     │  └─ foreign_tensor.h
   │  │  │     ├─ interpreter
   │  │  │     │  ├─ abstract_model_interpreter.cc
   │  │  │     │  ├─ abstract_model_interpreter.h
   │  │  │     │  ├─ default_model_interpreter.cc
   │  │  │     │  ├─ default_model_interpreter.h
   │  │  │     │  ├─ default_model_packer.cc
   │  │  │     │  ├─ default_model_packer.h
   │  │  │     │  ├─ layer_param.h
   │  │  │     │  ├─ layer_resource.h
   │  │  │     │  ├─ layer_resource_generator.cc
   │  │  │     │  ├─ layer_resource_generator.h
   │  │  │     │  ├─ ncnn
   │  │  │     │  │  ├─ layer_interpreter
   │  │  │     │  │  │  ├─ abstract_layer_interpreter.h
   │  │  │     │  │  │  ├─ batch_norm_layer_interpreter.cc
   │  │  │     │  │  │  ├─ binary_op_interpreter.cc
   │  │  │     │  │  │  ├─ clip_layer_interpreter.cc
   │  │  │     │  │  │  ├─ concat_layer_interpreter.cc
   │  │  │     │  │  │  ├─ conv_layer_interpreter.cc
   │  │  │     │  │  │  ├─ crop_layer_interpreter.cc
   │  │  │     │  │  │  ├─ deconv_layer_interpreter.cc
   │  │  │     │  │  │  ├─ default_layer_interpreter.cc
   │  │  │     │  │  │  ├─ detection_output_layer_interpreter.cc
   │  │  │     │  │  │  ├─ eltwise_layer_interpreter.cc
   │  │  │     │  │  │  ├─ elu_layer_interpreter.cc
   │  │  │     │  │  │  ├─ hard_sigmoid_layer_interpreter.cc
   │  │  │     │  │  │  ├─ hard_swish_layer_interpreter.cc
   │  │  │     │  │  │  ├─ inner_product_layer_interpreter.cc
   │  │  │     │  │  │  ├─ instance_norm_layer_interpreter.cc
   │  │  │     │  │  │  ├─ interp_layer_interpreter.cc
   │  │  │     │  │  │  ├─ lrn_layer_interpreter.cc
   │  │  │     │  │  │  ├─ memory_data_layer_interpreter.cc
   │  │  │     │  │  │  ├─ normalize_layer_interpreter.cc
   │  │  │     │  │  │  ├─ pad_layer_interpreter.cc
   │  │  │     │  │  │  ├─ permute_layer_interpreter.cc
   │  │  │     │  │  │  ├─ pooling_layer_interpreter.cc
   │  │  │     │  │  │  ├─ prelu_layer_interpreter.cc
   │  │  │     │  │  │  ├─ prior_box_layer_interpreter.cc
   │  │  │     │  │  │  ├─ reduce_op_layer_interpreter.cc
   │  │  │     │  │  │  ├─ relu_layer_interpreter.cc
   │  │  │     │  │  │  ├─ reorg_layer_interpreter.cc
   │  │  │     │  │  │  ├─ reshape_layer_interpreter.cc
   │  │  │     │  │  │  ├─ roi_pooling_layer_interpreter.cc
   │  │  │     │  │  │  ├─ scale_layer_interpreter.cc
   │  │  │     │  │  │  ├─ selu_layer_interpreter.cc
   │  │  │     │  │  │  ├─ shuffle_channel_layer_interpreter.cc
   │  │  │     │  │  │  ├─ slice_layer_interpreter.cc
   │  │  │     │  │  │  ├─ softmax_layer_interpreter.cc
   │  │  │     │  │  │  └─ unary_op_layer_interpreter.cc
   │  │  │     │  │  ├─ ncnn_layer_type.cc
   │  │  │     │  │  ├─ ncnn_layer_type.h
   │  │  │     │  │  ├─ ncnn_model_interpreter.cc
   │  │  │     │  │  ├─ ncnn_model_interpreter.h
   │  │  │     │  │  ├─ ncnn_param_utils.cc
   │  │  │     │  │  ├─ ncnn_param_utils.h
   │  │  │     │  │  ├─ optimizer
   │  │  │     │  │  │  ├─ expand_slice_optimizer.cc
   │  │  │     │  │  │  ├─ memory_data_optimizer.cc
   │  │  │     │  │  │  ├─ ncnn_optimizer.h
   │  │  │     │  │  │  ├─ ncnn_optimizer_manager.cc
   │  │  │     │  │  │  └─ ncnn_optimizer_manager.h
   │  │  │     │  │  └─ serializer.h
   │  │  │     │  ├─ net_resource.cc
   │  │  │     │  ├─ net_resource.h
   │  │  │     │  ├─ net_structure.cc
   │  │  │     │  ├─ net_structure.h
   │  │  │     │  ├─ raw_buffer.cc
   │  │  │     │  ├─ raw_buffer.h
   │  │  │     │  └─ tnn
   │  │  │     │     ├─ layer_interpreter
   │  │  │     │     │  ├─ abstract_layer_interpreter.h
   │  │  │     │     │  ├─ add_layer_interpreter.cc
   │  │  │     │     │  ├─ arg_max_or_min_layer_interpreter.cc
   │  │  │     │     │  ├─ batch_norm_layer_interpreter.cc
   │  │  │     │     │  ├─ bias_add_layer_interpreter.cc
   │  │  │     │     │  ├─ bitshift_layer_interpreter.cc
   │  │  │     │     │  ├─ blob_scale_layer_interpreter.cc
   │  │  │     │     │  ├─ cast_layer_interpreter.cc
   │  │  │     │     │  ├─ clip_layer_interpreter.cc
   │  │  │     │     │  ├─ concat_layer_interpreter.cc
   │  │  │     │     │  ├─ const_layer_interpreter.cc
   │  │  │     │     │  ├─ constantofshape_layer_interpreter.cc
   │  │  │     │     │  ├─ conv_1d_layer_interpreter.cc
   │  │  │     │     │  ├─ conv_3d_layer_interpreter.cc
   │  │  │     │     │  ├─ conv_layer_interpreter.cc
   │  │  │     │     │  ├─ detection_output_interpreter.cc
   │  │  │     │     │  ├─ detection_post_process_layer_interpreter.cc
   │  │  │     │     │  ├─ div_layer_interpreter.cc
   │  │  │     │     │  ├─ einsum_layer_interpreter.cc
   │  │  │     │     │  ├─ elu_layer_interpreter.cc
   │  │  │     │     │  ├─ expand_layer_interpreter.cc
   │  │  │     │     │  ├─ flatten_layer_interpreter.cc
   │  │  │     │     │  ├─ gather_layer_interpreter.cc
   │  │  │     │     │  ├─ gathernd_layer_interpreter.cc
   │  │  │     │     │  ├─ gridsample_layer_interpreter.cc
   │  │  │     │     │  ├─ group_norm_layer_interpreter.cc
   │  │  │     │     │  ├─ hard_sigmoid_layer_interpreter.cc
   │  │  │     │     │  ├─ hard_swish_layer_interpreter.cc
   │  │  │     │     │  ├─ hdrguide_layer_interpreter.cc
   │  │  │     │     │  ├─ histogram_layer_interpreter.cc
   │  │  │     │     │  ├─ inner_product_layer_interpreter.cc
   │  │  │     │     │  ├─ instance_norm_layer_interpreter.cc
   │  │  │     │     │  ├─ layer_interpreter_macro.h
   │  │  │     │     │  ├─ layer_norm_layer_interpreter.cc
   │  │  │     │     │  ├─ lrn_layer_interpreter.cc
   │  │  │     │     │  ├─ lstm_layer_interpreter.cc
   │  │  │     │     │  ├─ mat_mul_layer_interpreter.cc
   │  │  │     │     │  ├─ max_layer_interpreter.cc
   │  │  │     │     │  ├─ min_layer_interpreter.cc
   │  │  │     │     │  ├─ mul_layer_interpreter.cc
   │  │  │     │     │  ├─ normalize_layer_interpreter.cc
   │  │  │     │     │  ├─ onehot_layer_interpreter.cc
   │  │  │     │     │  ├─ pad_layer_interpreter.cc
   │  │  │     │     │  ├─ padv2_layer_interpreter.cc
   │  │  │     │     │  ├─ permute_layer_interpreter.cc
   │  │  │     │     │  ├─ pixel_shuffle_layer_interpreter.cc
   │  │  │     │     │  ├─ pooling_3d_layer_interpreter.cc
   │  │  │     │     │  ├─ pooling_layer_interpreter.cc
   │  │  │     │     │  ├─ pow_layer_interpreter.cc
   │  │  │     │     │  ├─ prelu_layer_interpreter.cc
   │  │  │     │     │  ├─ prior_box_layer_interpreter.cc
   │  │  │     │     │  ├─ range_layer_interpreter.cc
   │  │  │     │     │  ├─ reduce_op_interpreter.cc
   │  │  │     │     │  ├─ reduce_op_interpreter.h
   │  │  │     │     │  ├─ reformat_layer_interpreter.cc
   │  │  │     │     │  ├─ reorg_layer_interpreter.cc
   │  │  │     │     │  ├─ reshape_layer_interpreter.cc
   │  │  │     │     │  ├─ roi_pooling_layer_interpreter.cc
   │  │  │     │     │  ├─ roialign_layer_interpreter.cc
   │  │  │     │     │  ├─ scale_layer_interpreter.cc
   │  │  │     │     │  ├─ scatter_nd_layer_interpreter.cc
   │  │  │     │     │  ├─ selu_layer_interpreter.cc
   │  │  │     │     │  ├─ shape_layer_interpreter.cc
   │  │  │     │     │  ├─ shuffle_layer_interpreter.cc
   │  │  │     │     │  ├─ signed_mul_layer_interpreter.cc
   │  │  │     │     │  ├─ size_layer_interpreter.cc
   │  │  │     │     │  ├─ softmax_layer_interpreter.cc
   │  │  │     │     │  ├─ splitv_layer_interpreter.cc
   │  │  │     │     │  ├─ squared_difference_layer_interpreter.cc
   │  │  │     │     │  ├─ squeeze_layer_interpreter.cc
   │  │  │     │     │  ├─ stride_slice_layer_interpreter.cc
   │  │  │     │     │  ├─ stride_slice_v2_layer_interpreter.cc
   │  │  │     │     │  ├─ sub_layer_interpreter.cc
   │  │  │     │     │  ├─ tile_layer_interpreter.cc
   │  │  │     │     │  ├─ topk_layer_interpreter.cc
   │  │  │     │     │  ├─ unary_op_layer_interpreter.cc
   │  │  │     │     │  ├─ unary_op_layer_interpreter.h
   │  │  │     │     │  ├─ unsqueeze_layer_interpreter.cc
   │  │  │     │     │  └─ upsample_layer_interpreter.cc
   │  │  │     │     ├─ model_interpreter.cc
   │  │  │     │     ├─ model_interpreter.h
   │  │  │     │     ├─ model_packer.cc
   │  │  │     │     ├─ model_packer.h
   │  │  │     │     └─ objseri.h
   │  │  │     ├─ layer
   │  │  │     │  ├─ abs_layer.cc
   │  │  │     │  ├─ acos_layer.cc
   │  │  │     │  ├─ add_layer.cc
   │  │  │     │  ├─ arg_max_or_min_layer.cc
   │  │  │     │  ├─ asin_layer.cc
   │  │  │     │  ├─ atan_layer.cc
   │  │  │     │  ├─ base_layer.cc
   │  │  │     │  ├─ base_layer.h
   │  │  │     │  ├─ batch_norm_layer.cc
   │  │  │     │  ├─ bias_add_layer.cc
   │  │  │     │  ├─ bitshift_layer.cc
   │  │  │     │  ├─ cast_layer.cc
   │  │  │     │  ├─ cbam_fused_pooling_layer.cc
   │  │  │     │  ├─ cbam_fused_reduce_layer.cc
   │  │  │     │  ├─ ceil_layer.cc
   │  │  │     │  ├─ clip_layer.cc
   │  │  │     │  ├─ concat_layer.cc
   │  │  │     │  ├─ constantofshape_layer.cc
   │  │  │     │  ├─ conv1d_layer.cc
   │  │  │     │  ├─ conv3d_layer.cc
   │  │  │     │  ├─ conv_layer.cc
   │  │  │     │  ├─ cos_layer.cc
   │  │  │     │  ├─ deconv_layer.cc
   │  │  │     │  ├─ detection_output_layer.cc
   │  │  │     │  ├─ detection_post_process_layer.cc
   │  │  │     │  ├─ div_layer.cc
   │  │  │     │  ├─ einsum_layer.cc
   │  │  │     │  ├─ elementwise_layer.cc
   │  │  │     │  ├─ elementwise_layer.h
   │  │  │     │  ├─ elu_layer.cc
   │  │  │     │  ├─ equal_layer.cc
   │  │  │     │  ├─ erf_layer.cc
   │  │  │     │  ├─ exp_layer.cc
   │  │  │     │  ├─ expand_layer.cc
   │  │  │     │  ├─ flatten_layer.cc
   │  │  │     │  ├─ floor_layer.cc
   │  │  │     │  ├─ gather_layer.cc
   │  │  │     │  ├─ gathernd_layer.cc
   │  │  │     │  ├─ gelu_layer.cc
   │  │  │     │  ├─ gridsample_layer.cc
   │  │  │     │  ├─ group_norm_layer.cc
   │  │  │     │  ├─ hard_sigmoid_layer.cc
   │  │  │     │  ├─ hard_swish_layer.cc
   │  │  │     │  ├─ hdrguide_layer.cc
   │  │  │     │  ├─ histogram_layer.cc
   │  │  │     │  ├─ inner_product_layer.cc
   │  │  │     │  ├─ instance_norm_layer.cc
   │  │  │     │  ├─ inverse_layer.cc
   │  │  │     │  ├─ layer_norm_layer.cc
   │  │  │     │  ├─ log_layer.cc
   │  │  │     │  ├─ log_sigmoid_layer.cc
   │  │  │     │  ├─ lrn_layer.cc
   │  │  │     │  ├─ lstm_layer.cc
   │  │  │     │  ├─ mat_mul_layer.cc
   │  │  │     │  ├─ max_layer.cc
   │  │  │     │  ├─ min_layer.cc
   │  │  │     │  ├─ mul_layer.cc
   │  │  │     │  ├─ multidir_broadcast_layer.cc
   │  │  │     │  ├─ multidir_broadcast_layer.h
   │  │  │     │  ├─ neg_layer.cc
   │  │  │     │  ├─ nonzero_layer.cc
   │  │  │     │  ├─ normalize_layer.cc
   │  │  │     │  ├─ onehot_layer.cc
   │  │  │     │  ├─ pad_layer.cc
   │  │  │     │  ├─ padv2_layer.cc
   │  │  │     │  ├─ permute_layer.cc
   │  │  │     │  ├─ pixel_shuffle_layer.cc
   │  │  │     │  ├─ pooling_3d_layer.cc
   │  │  │     │  ├─ pooling_layer.cc
   │  │  │     │  ├─ pow_layer.cc
   │  │  │     │  ├─ prelu_layer.cc
   │  │  │     │  ├─ prior_box_layer.cc
   │  │  │     │  ├─ range_layer.cc
   │  │  │     │  ├─ reciprocal_layer.cc
   │  │  │     │  ├─ reduce_l1_layer.cc
   │  │  │     │  ├─ reduce_l2_layer.cc
   │  │  │     │  ├─ reduce_layer.cc
   │  │  │     │  ├─ reduce_layer.h
   │  │  │     │  ├─ reduce_log_sum_exp_layer.cc
   │  │  │     │  ├─ reduce_log_sum_layer.cc
   │  │  │     │  ├─ reduce_max_layer.cc
   │  │  │     │  ├─ reduce_mean_layer.cc
   │  │  │     │  ├─ reduce_min_layer.cc
   │  │  │     │  ├─ reduce_prod_layer.cc
   │  │  │     │  ├─ reduce_sum_layer.cc
   │  │  │     │  ├─ reduce_sum_square_layer.cc
   │  │  │     │  ├─ reformat_layer.cc
   │  │  │     │  ├─ relu6_layer.cc
   │  │  │     │  ├─ relu_layer.cc
   │  │  │     │  ├─ reorg_layer.cc
   │  │  │     │  ├─ reshape_layer.cc
   │  │  │     │  ├─ roi_pooling_layer.cc
   │  │  │     │  ├─ roialign_layer.cc
   │  │  │     │  ├─ rsqrt_layer.cc
   │  │  │     │  ├─ scale_layer.cc
   │  │  │     │  ├─ scatter_nd_layer.cc
   │  │  │     │  ├─ selu_layer.cc
   │  │  │     │  ├─ shape_layer.cc
   │  │  │     │  ├─ shuffle_layer.cc
   │  │  │     │  ├─ sigmoid_layer.cc
   │  │  │     │  ├─ sign_layer.cc
   │  │  │     │  ├─ signed_mul_layer.cc
   │  │  │     │  ├─ sin_layer.cc
   │  │  │     │  ├─ size_layer.cc
   │  │  │     │  ├─ softmax_layer.cc
   │  │  │     │  ├─ softplus_layer.cc
   │  │  │     │  ├─ softsign_layer.cc
   │  │  │     │  ├─ split_layer.cc
   │  │  │     │  ├─ splitv_layer.cc
   │  │  │     │  ├─ sqrt_layer.cc
   │  │  │     │  ├─ squared_difference_layer.cc
   │  │  │     │  ├─ squeeze_layer.cc
   │  │  │     │  ├─ stride_slice_layer.cc
   │  │  │     │  ├─ stride_slice_v2_layer.cc
   │  │  │     │  ├─ sub_layer.cc
   │  │  │     │  ├─ tan_layer.cc
   │  │  │     │  ├─ tanh_layer.cc
   │  │  │     │  ├─ tile_layer.cc
   │  │  │     │  ├─ topk_layer.cc
   │  │  │     │  ├─ unsqueeze_layer.cc
   │  │  │     │  ├─ upsample_layer.cc
   │  │  │     │  └─ where_layer.cc
   │  │  │     ├─ memory_manager
   │  │  │     │  ├─ blob_1d_memory.cc
   │  │  │     │  ├─ blob_1d_memory.h
   │  │  │     │  ├─ blob_1d_memory_pool.cc
   │  │  │     │  ├─ blob_1d_memory_pool.h
   │  │  │     │  ├─ blob_2d_memory.cc
   │  │  │     │  ├─ blob_2d_memory.h
   │  │  │     │  ├─ blob_2d_memory_pool.cc
   │  │  │     │  ├─ blob_2d_memory_pool.h
   │  │  │     │  ├─ blob_memory.cc
   │  │  │     │  ├─ blob_memory.h
   │  │  │     │  ├─ blob_memory_pool.cc
   │  │  │     │  ├─ blob_memory_pool.h
   │  │  │     │  ├─ blob_memory_pool_factory.cc
   │  │  │     │  ├─ blob_memory_pool_factory.h
   │  │  │     │  ├─ blob_memory_size_info.cc
   │  │  │     │  ├─ blob_memory_size_info.h
   │  │  │     │  ├─ memory_assign_strategy.h
   │  │  │     │  ├─ memory_mode_state.cc
   │  │  │     │  ├─ memory_mode_state.h
   │  │  │     │  ├─ memory_mode_state_factory.cc
   │  │  │     │  ├─ memory_mode_state_factory.h
   │  │  │     │  ├─ memory_seperate_assign_strategy.cc
   │  │  │     │  ├─ memory_seperate_assign_strategy.h
   │  │  │     │  ├─ memory_unify_assign_strategy.cc
   │  │  │     │  ├─ memory_unify_assign_strategy.h
   │  │  │     │  ├─ others_memory_mode_state.cc
   │  │  │     │  ├─ others_memory_mode_state.h
   │  │  │     │  ├─ share_one_thread_memory_mode_state.cc
   │  │  │     │  ├─ share_one_thread_memory_mode_state.h
   │  │  │     │  ├─ shared_memory_manager.cc
   │  │  │     │  └─ shared_memory_manager.h
   │  │  │     ├─ network
   │  │  │     │  ├─ openvino
   │  │  │     │  │  ├─ .gitignore
   │  │  │     │  │  ├─ CMakeLists.txt
   │  │  │     │  │  ├─ custom_layer
   │  │  │     │  │  │  ├─ custom_abs.h
   │  │  │     │  │  │  ├─ custom_batch_norm.h
   │  │  │     │  │  │  ├─ custom_expand.h
   │  │  │     │  │  │  ├─ custom_hard_swish.h
   │  │  │     │  │  │  ├─ custom_implementation.h
   │  │  │     │  │  │  ├─ custom_instance_norm.h
   │  │  │     │  │  │  ├─ custom_layer_norm.h
   │  │  │     │  │  │  ├─ custom_lstm_onnx.h
   │  │  │     │  │  │  ├─ custom_pad_v2.h
   │  │  │     │  │  │  ├─ custom_pooling.h
   │  │  │     │  │  │  ├─ custom_reshape.h
   │  │  │     │  │  │  ├─ custom_softplus.h
   │  │  │     │  │  │  ├─ custom_softsign.h
   │  │  │     │  │  │  └─ custom_stride_slice_v2.h
   │  │  │     │  │  ├─ layer_builder
   │  │  │     │  │  │  ├─ abs_layer_builder.cc
   │  │  │     │  │  │  ├─ acos_layer_builder.cc
   │  │  │     │  │  │  ├─ add_layer_builder.cc
   │  │  │     │  │  │  ├─ arg_max_or_min_layer_builder.cc
   │  │  │     │  │  │  ├─ asin_layer_builder.cc
   │  │  │     │  │  │  ├─ atan_layer_budiler.cc
   │  │  │     │  │  │  ├─ batch_norm_layer_builder.cc
   │  │  │     │  │  │  ├─ binary_layer_builder.cc
   │  │  │     │  │  │  ├─ binary_layer_builder.h
   │  │  │     │  │  │  ├─ cast_layer_builder.cc
   │  │  │     │  │  │  ├─ ceil_layer_builder.cc
   │  │  │     │  │  │  ├─ clip_layer_builder.cc
   │  │  │     │  │  │  ├─ concat_layer_builder.cc
   │  │  │     │  │  │  ├─ conv_layer_builder.cc
   │  │  │     │  │  │  ├─ cos_layer_builder.cc
   │  │  │     │  │  │  ├─ deconv_layer_builder.cc
   │  │  │     │  │  │  ├─ detection_output_layer_builder.cc
   │  │  │     │  │  │  ├─ div_layer_builder.cc
   │  │  │     │  │  │  ├─ elu_layer_builder.cc
   │  │  │     │  │  │  ├─ erf_layer_builder.cc
   │  │  │     │  │  │  ├─ exp_layer_builder.cc
   │  │  │     │  │  │  ├─ expand_layer_builder.cc
   │  │  │     │  │  │  ├─ flatten_layer_builder.cc
   │  │  │     │  │  │  ├─ floor_layer_builder.cc
   │  │  │     │  │  │  ├─ gather_layer_builder.cc
   │  │  │     │  │  │  ├─ gelu_layer_builder.cc
   │  │  │     │  │  │  ├─ hard_sigmoid_layer_builder.cc
   │  │  │     │  │  │  ├─ hard_swish_layer_builder.cc
   │  │  │     │  │  │  ├─ inner_product_layer_builder.cc
   │  │  │     │  │  │  ├─ instance_norm_builder.cc
   │  │  │     │  │  │  ├─ layer_norm_builder.cc
   │  │  │     │  │  │  ├─ log_layer_builder.cc
   │  │  │     │  │  │  ├─ log_sigmoid_layer_builder.cc
   │  │  │     │  │  │  ├─ lrn_layer_builder.cc
   │  │  │     │  │  │  ├─ lstm_layer_builder.cc
   │  │  │     │  │  │  ├─ matmul_layer_builder.cc
   │  │  │     │  │  │  ├─ max_layer_builder.cc
   │  │  │     │  │  │  ├─ min_layer_builder.cc
   │  │  │     │  │  │  ├─ multiply_layer_builder.cc
   │  │  │     │  │  │  ├─ neg_layer_builder.cc
   │  │  │     │  │  │  ├─ normalize_layer_builder.cc
   │  │  │     │  │  │  ├─ onehot_layer_build.cc
   │  │  │     │  │  │  ├─ openvino_layer_builder.cc
   │  │  │     │  │  │  ├─ openvino_layer_builder.h
   │  │  │     │  │  │  ├─ pad_layer_builder.cc
   │  │  │     │  │  │  ├─ pad_v2_layer_builder.cc
   │  │  │     │  │  │  ├─ permute_layer_builder.cc
   │  │  │     │  │  │  ├─ pool_layer_builder.cc
   │  │  │     │  │  │  ├─ pow_layer_builder.cc
   │  │  │     │  │  │  ├─ prelu_layer_builder.cc
   │  │  │     │  │  │  ├─ prior_box_layer_builder.cc
   │  │  │     │  │  │  ├─ reciprocal_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_l1_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_l2_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_log_sum_exp_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_log_sum_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_max_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_mean_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_min_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_prod_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_sum_layer_builder.cc
   │  │  │     │  │  │  ├─ reduce_sum_square_layer_builder.cc
   │  │  │     │  │  │  ├─ relu6_layer_builder.cc
   │  │  │     │  │  │  ├─ relu_layer_builder.cc
   │  │  │     │  │  │  ├─ reorg_layer_builder.cc
   │  │  │     │  │  │  ├─ reshape_layer_builder.cc
   │  │  │     │  │  │  ├─ roi_pooling_layer_builder.cc
   │  │  │     │  │  │  ├─ scatter_nd_layer_builder.cc
   │  │  │     │  │  │  ├─ selu_layer_builder.cc
   │  │  │     │  │  │  ├─ shape_layer_builder.cc
   │  │  │     │  │  │  ├─ shuffle_channel_layer_builder.cc
   │  │  │     │  │  │  ├─ sigmoid_layer_builder.cc
   │  │  │     │  │  │  ├─ sign_layer_builder.cc
   │  │  │     │  │  │  ├─ sin_layer_builder.cc
   │  │  │     │  │  │  ├─ softmax_layer_builder.cc
   │  │  │     │  │  │  ├─ softplus_layer_builder.cc
   │  │  │     │  │  │  ├─ softsign_layer_builder.cc
   │  │  │     │  │  │  ├─ splitv_layer_builder.cc
   │  │  │     │  │  │  ├─ sqrt_layer_builder.cc
   │  │  │     │  │  │  ├─ squeeze_layer_builder.cc
   │  │  │     │  │  │  ├─ stride_slice_layer_builder.cc
   │  │  │     │  │  │  ├─ stride_slice_v2_layer_builder.cc
   │  │  │     │  │  │  ├─ sub_layer_builder.cc
   │  │  │     │  │  │  ├─ tan_layer_builder.cc
   │  │  │     │  │  │  ├─ tanh_layer_builder.cc
   │  │  │     │  │  │  ├─ unary_layer_builder.h
   │  │  │     │  │  │  ├─ unsqueeze_layer_builder.cc
   │  │  │     │  │  │  └─ upsample_layer_builder.cc
   │  │  │     │  │  ├─ openvino_network.cc
   │  │  │     │  │  ├─ openvino_network.h
   │  │  │     │  │  ├─ openvino_types.cc
   │  │  │     │  │  ├─ openvino_types.h
   │  │  │     │  │  ├─ utils.cc
   │  │  │     │  │  └─ utils.h
   │  │  │     │  └─ tensorrt
   │  │  │     │     ├─ CMakeLists.txt
   │  │  │     │     ├─ dimension_expr.cc
   │  │  │     │     ├─ dimension_expr.h
   │  │  │     │     ├─ exclusive_file.cc
   │  │  │     │     ├─ exclusive_file.h
   │  │  │     │     ├─ layer_builder
   │  │  │     │     │  ├─ abs_layer_builder.cc
   │  │  │     │     │  ├─ acos_layer_builder.cc
   │  │  │     │     │  ├─ activation_layer_builder.cc
   │  │  │     │     │  ├─ activation_layer_builder.h
   │  │  │     │     │  ├─ add_layer_builder.cc
   │  │  │     │     │  ├─ argmax_or_min_layer_builder.cc
   │  │  │     │     │  ├─ asin_layer_builder.cc
   │  │  │     │     │  ├─ atan_layer_builder.cc
   │  │  │     │     │  ├─ batch_norm_layer_builder.cc
   │  │  │     │     │  ├─ binary_layer_builder.cc
   │  │  │     │     │  ├─ binary_layer_builder.h
   │  │  │     │     │  ├─ bitshift_layer_builder.cc
   │  │  │     │     │  ├─ cast_layer_builder.cc
   │  │  │     │     │  ├─ cbam_fused_pooling_layer_builder.cc
   │  │  │     │     │  ├─ cbam_fused_reduce_layer_builder.cc
   │  │  │     │     │  ├─ ceil_layer_builder.cc
   │  │  │     │     │  ├─ clip_layer_builder.cc
   │  │  │     │     │  ├─ concat_layer_builder.cc
   │  │  │     │     │  ├─ constantofshape_layer_builder.cc
   │  │  │     │     │  ├─ conv_1d_layer_builder.cc
   │  │  │     │     │  ├─ conv_3d_layer_builder.cc
   │  │  │     │     │  ├─ conv_layer_builder.cc
   │  │  │     │     │  ├─ cos_layer_builder.cc
   │  │  │     │     │  ├─ deconv_layer_builder.cc
   │  │  │     │     │  ├─ detection_output_layer_builder.cc
   │  │  │     │     │  ├─ div_layer_builder.cc
   │  │  │     │     │  ├─ einsum_layer_builder.cc
   │  │  │     │     │  ├─ elu_layer_builder.cc
   │  │  │     │     │  ├─ erf_layer_builder.cc
   │  │  │     │     │  ├─ exp_layer_builder.cc
   │  │  │     │     │  ├─ expand_layer_builder.cc
   │  │  │     │     │  ├─ flatten_layer_builder.cc
   │  │  │     │     │  ├─ floor_layer_builder.cc
   │  │  │     │     │  ├─ gather_layer_builder.cc
   │  │  │     │     │  ├─ gather_nd_layer_builder.cc
   │  │  │     │     │  ├─ gelu_layer_builder.cc
   │  │  │     │     │  ├─ gridsample_layer_builder.cc
   │  │  │     │     │  ├─ group_norm_layer_builder.cc
   │  │  │     │     │  ├─ hard_sigmoid_layer_builder.cc
   │  │  │     │     │  ├─ hard_swish_layer_builder.cc
   │  │  │     │     │  ├─ histogram_layer_builder.cc
   │  │  │     │     │  ├─ inner_product_layer_builder.cc
   │  │  │     │     │  ├─ inner_product_layer_plugin_builder.cc
   │  │  │     │     │  ├─ instance_norm_layer_builder.cc
   │  │  │     │     │  ├─ inverse_layer_builder.cc
   │  │  │     │     │  ├─ layer_norm_layer_builder.cc
   │  │  │     │     │  ├─ log_layer_builder.cc
   │  │  │     │     │  ├─ lrn_layer_builder.cc
   │  │  │     │     │  ├─ lstm_layer_builder.cc
   │  │  │     │     │  ├─ mat_mul_layer_builder.cc
   │  │  │     │     │  ├─ max_layer_builder.cc
   │  │  │     │     │  ├─ min_layer_builder.cc
   │  │  │     │     │  ├─ mul_layer_builder.cc
   │  │  │     │     │  ├─ neg_layer_builder.cc
   │  │  │     │     │  ├─ normalize_layer_builder.cc
   │  │  │     │     │  ├─ onehot_layer_builder.cc
   │  │  │     │     │  ├─ pad_layer_builder.cc
   │  │  │     │     │  ├─ pad_v2_layer_builder.cc
   │  │  │     │     │  ├─ permute_layer_builder.cc
   │  │  │     │     │  ├─ pixel_shuffle_layer_builder.cc
   │  │  │     │     │  ├─ pooling_layer_builder.cc
   │  │  │     │     │  ├─ power_layer_builder.cc
   │  │  │     │     │  ├─ prelu_layer_builder.cc
   │  │  │     │     │  ├─ prior_box_layer_builder.cc
   │  │  │     │     │  ├─ reciprocal_layer_builder.cc
   │  │  │     │     │  ├─ reduce_l2_layer_builder.cc
   │  │  │     │     │  ├─ reduce_layer_builder.cc
   │  │  │     │     │  ├─ reduce_layer_builder.h
   │  │  │     │     │  ├─ reduce_log_sum_exp_layer_builder.cc
   │  │  │     │     │  ├─ reduce_log_sum_exp_layer_builder.h
   │  │  │     │     │  ├─ reduce_max_layer_builder.cc
   │  │  │     │     │  ├─ reduce_mean_layer_builder.cc
   │  │  │     │     │  ├─ reduce_min_layer_builder.cc
   │  │  │     │     │  ├─ reduce_sum_layer_builder.cc
   │  │  │     │     │  ├─ relu6_layer_builder.cc
   │  │  │     │     │  ├─ relu_layer_builder.cc
   │  │  │     │     │  ├─ reshape_layer_builder.cc
   │  │  │     │     │  ├─ roialign_layer_builder.cc
   │  │  │     │     │  ├─ scatter_nd_layer_builder.cc
   │  │  │     │     │  ├─ shape_layer_builder.cc
   │  │  │     │     │  ├─ shuffle_layer_builder.cc
   │  │  │     │     │  ├─ sigmoid_layer.cc
   │  │  │     │     │  ├─ sign_layer_builder.cc
   │  │  │     │     │  ├─ sin_layer_builder.cc
   │  │  │     │     │  ├─ softmax_layer_builder.cc
   │  │  │     │     │  ├─ softplus_layer_builder.cc
   │  │  │     │     │  ├─ splitv_layer_builder.cc
   │  │  │     │     │  ├─ sqrt_layer_builder.cc
   │  │  │     │     │  ├─ squeeze_layer_builder.cc
   │  │  │     │     │  ├─ strided_slice_layer_builder.cc
   │  │  │     │     │  ├─ strided_slice_v2_layer_builder.cc
   │  │  │     │     │  ├─ sub_layer_builder.cc
   │  │  │     │     │  ├─ tan_layer_builder.cc
   │  │  │     │     │  ├─ tanh_layer_builder.cc
   │  │  │     │     │  ├─ tensorrt_base_layer_builder.cc
   │  │  │     │     │  ├─ tensorrt_base_layer_builder.h
   │  │  │     │     │  ├─ tensorrt_layer_builder.cc
   │  │  │     │     │  ├─ tensorrt_layer_builder.h
   │  │  │     │     │  ├─ tensorrt_plugin_layer_builder.cc
   │  │  │     │     │  ├─ tensorrt_plugin_layer_builder.h
   │  │  │     │     │  ├─ tile_layer_builder.cc
   │  │  │     │     │  ├─ topk_layer_builder.cc
   │  │  │     │     │  ├─ unsqueeze_layer_builder.cc
   │  │  │     │     │  └─ upsample_layer_builder.cc
   │  │  │     │     ├─ tensorrt_blob_manager.cc
   │  │  │     │     ├─ tensorrt_blob_manager.h
   │  │  │     │     ├─ tensorrt_network.cc
   │  │  │     │     ├─ tensorrt_network.h
   │  │  │     │     ├─ tensorrt_tensor.h
   │  │  │     │     ├─ utils.cc
   │  │  │     │     └─ utils.h
   │  │  │     ├─ optimizer
   │  │  │     │  ├─ net_optimizer.h
   │  │  │     │  ├─ net_optimizer_cbam_fused_pooling.cc
   │  │  │     │  ├─ net_optimizer_cbam_fused_pooling.h
   │  │  │     │  ├─ net_optimizer_cbam_fused_reduce.cc
   │  │  │     │  ├─ net_optimizer_cbam_fused_reduce.h
   │  │  │     │  ├─ net_optimizer_fuse_conv_add.cc
   │  │  │     │  ├─ net_optimizer_fuse_conv_add.h
   │  │  │     │  ├─ net_optimizer_fuse_conv_post.cc
   │  │  │     │  ├─ net_optimizer_fuse_conv_post.h
   │  │  │     │  ├─ net_optimizer_insert_fp16_reformat.cc
   │  │  │     │  ├─ net_optimizer_insert_fp16_reformat.h
   │  │  │     │  ├─ net_optimizer_insert_int8_reformat.cc
   │  │  │     │  ├─ net_optimizer_insert_int8_reformat.h
   │  │  │     │  ├─ net_optimizer_insert_layout_reformat.cc
   │  │  │     │  ├─ net_optimizer_insert_layout_reformat.h
   │  │  │     │  ├─ net_optimizer_manager.cc
   │  │  │     │  ├─ net_optimizer_manager.h
   │  │  │     │  ├─ net_optimizer_remove_layers.cc
   │  │  │     │  ├─ net_optimizer_remove_layers.h
   │  │  │     │  └─ optimizer_const.h
   │  │  │     └─ utils
   │  │  │        ├─ bbox_util.cc
   │  │  │        ├─ bbox_util.h
   │  │  │        ├─ bfp16.h
   │  │  │        ├─ bfp16_utils.cc
   │  │  │        ├─ blob_converter_default.cc
   │  │  │        ├─ blob_converter_default.h
   │  │  │        ├─ blob_converter_internal.cc
   │  │  │        ├─ blob_converter_internal.h
   │  │  │        ├─ blob_dump_utils.cc
   │  │  │        ├─ blob_dump_utils.h
   │  │  │        ├─ blob_memory_size_utils.cc
   │  │  │        ├─ blob_memory_size_utils.h
   │  │  │        ├─ blob_transfer_utils.cc
   │  │  │        ├─ blob_transfer_utils.h
   │  │  │        ├─ cpu_info.cc
   │  │  │        ├─ cpu_info.h
   │  │  │        ├─ cpu_utils.cc
   │  │  │        ├─ data_flag_utils.cc
   │  │  │        ├─ data_flag_utils.h
   │  │  │        ├─ data_format_converter.cc
   │  │  │        ├─ data_format_converter.h
   │  │  │        ├─ data_type_utils.cc
   │  │  │        ├─ detection_post_process_utils.cc
   │  │  │        ├─ detection_post_process_utils.h
   │  │  │        ├─ dims_function_utils.cc
   │  │  │        ├─ dims_function_utils.h
   │  │  │        ├─ dims_offset_utils.cc
   │  │  │        ├─ dims_offset_utils.h
   │  │  │        ├─ dims_utils.h
   │  │  │        ├─ dims_vector_utils.cc
   │  │  │        ├─ half.hpp
   │  │  │        ├─ half_utils.cc
   │  │  │        ├─ half_utils_inner.h
   │  │  │        ├─ mat_converter_acc.cc
   │  │  │        ├─ mat_converter_acc.h
   │  │  │        ├─ mat_converter_utils.cc
   │  │  │        ├─ mat_converter_utils.h
   │  │  │        ├─ mat_utils.cc
   │  │  │        ├─ md5.cc
   │  │  │        ├─ md5.h
   │  │  │        ├─ naive_compute.cc
   │  │  │        ├─ naive_compute.h
   │  │  │        ├─ npu_common_utils.cc
   │  │  │        ├─ npu_common_utils.h
   │  │  │        ├─ omp_utils.h
   │  │  │        ├─ pad_utils.cc
   │  │  │        ├─ pad_utils.h
   │  │  │        ├─ pribox_generator_utils.cc
   │  │  │        ├─ pribox_generator_utils.h
   │  │  │        ├─ random_data_utils.cc
   │  │  │        ├─ random_data_utils.h
   │  │  │        ├─ split_utils.cc
   │  │  │        ├─ split_utils.h
   │  │  │        ├─ string_format.cc
   │  │  │        ├─ string_format.h
   │  │  │        ├─ string_utils.cc
   │  │  │        ├─ string_utils_inner.h
   │  │  │        ├─ winograd_generator.cc
   │  │  │        └─ winograd_generator.h
   │  │  ├─ test
   │  │  │  ├─ CMakeLists.txt
   │  │  │  ├─ flags.cc
   │  │  │  ├─ flags.h
   │  │  │  ├─ test.cc
   │  │  │  ├─ test.h
   │  │  │  ├─ test_utils.cc
   │  │  │  ├─ test_utils.h
   │  │  │  ├─ timer.cc
   │  │  │  ├─ timer.h
   │  │  │  └─ unit_test
   │  │  │     ├─ CMakeLists.txt
   │  │  │     ├─ README.md
   │  │  │     ├─ blob_converter_test.cc
   │  │  │     ├─ blob_converter_test.h
   │  │  │     ├─ layer_test
   │  │  │     │  ├─ layer_test.cc
   │  │  │     │  ├─ layer_test.h
   │  │  │     │  ├─ layer_test_utils.cc
   │  │  │     │  ├─ layer_test_utils.h
   │  │  │     │  ├─ test_abs_layer.cc
   │  │  │     │  ├─ test_acos_layer.cc
   │  │  │     │  ├─ test_add_layer.cc
   │  │  │     │  ├─ test_arg_max_or_min_layer.cc
   │  │  │     │  ├─ test_asin_layer.cc
   │  │  │     │  ├─ test_atan_layer.cc
   │  │  │     │  ├─ test_batch_norm_layer.cc
   │  │  │     │  ├─ test_binary_layer.cc
   │  │  │     │  ├─ test_binary_layer.h
   │  │  │     │  ├─ test_ceil_layer.cc
   │  │  │     │  ├─ test_clip_layer.cc
   │  │  │     │  ├─ test_concat_layer.cc
   │  │  │     │  ├─ test_conv_3d_layer.cc
   │  │  │     │  ├─ test_conv_layer.cc
   │  │  │     │  ├─ test_conv_quant_layer.cc
   │  │  │     │  ├─ test_cos_layer.cc
   │  │  │     │  ├─ test_deconv_layer.cc
   │  │  │     │  ├─ test_div_layer.cc
   │  │  │     │  ├─ test_elu_layer.cc
   │  │  │     │  ├─ test_exp_layer.cc
   │  │  │     │  ├─ test_floor_layer.cc
   │  │  │     │  ├─ test_gelu_layer.cc
   │  │  │     │  ├─ test_grid_sample_layer.cc
   │  │  │     │  ├─ test_hard_sigmoid_layer.cc
   │  │  │     │  ├─ test_hard_swish_broadcast_layer.cc
   │  │  │     │  ├─ test_hard_swish_layer.cc
   │  │  │     │  ├─ test_hdrguide_layer.cc
   │  │  │     │  ├─ test_innerproduct_int8_layer.cc
   │  │  │     │  ├─ test_innerproduct_layer.cc
   │  │  │     │  ├─ test_instance_norm_layer.cc
   │  │  │     │  ├─ test_inverse_layer.cc
   │  │  │     │  ├─ test_layer_norm_layer.cc
   │  │  │     │  ├─ test_log_layer.cc
   │  │  │     │  ├─ test_log_sigmoid_layer.cc
   │  │  │     │  ├─ test_lstm_layer.cc
   │  │  │     │  ├─ test_matmul_layer.cc
   │  │  │     │  ├─ test_max_layer.cc
   │  │  │     │  ├─ test_min_layer.cc
   │  │  │     │  ├─ test_mul_layer.cc
   │  │  │     │  ├─ test_neg_layer.cc
   │  │  │     │  ├─ test_normalize_layer.cc
   │  │  │     │  ├─ test_pad_layer.cc
   │  │  │     │  ├─ test_padv2_layer.cc
   │  │  │     │  ├─ test_permute_layer.cc
   │  │  │     │  ├─ test_pixel_shuffle_layer.cc
   │  │  │     │  ├─ test_pooling_3d_layer.cc
   │  │  │     │  ├─ test_pooling_layer.cc
   │  │  │     │  ├─ test_pow_layer.cc
   │  │  │     │  ├─ test_prelu_layer.cc
   │  │  │     │  ├─ test_priox_box_layer.cc
   │  │  │     │  ├─ test_reciprocal_layer.cc
   │  │  │     │  ├─ test_reduce_op_layer.cc
   │  │  │     │  ├─ test_reformat_layer.cc
   │  │  │     │  ├─ test_relu6_layer.cc
   │  │  │     │  ├─ test_relu_layer.cc
   │  │  │     │  ├─ test_reorg_layer.cc
   │  │  │     │  ├─ test_reshape_layer.cc
   │  │  │     │  ├─ test_selu_layer.cc
   │  │  │     │  ├─ test_shuffle_layer.cc
   │  │  │     │  ├─ test_sigmoid_layer.cc
   │  │  │     │  ├─ test_sign_layer.cc
   │  │  │     │  ├─ test_signed_mul_layer.cc
   │  │  │     │  ├─ test_sin_layer.cc
   │  │  │     │  ├─ test_softmax_layer.cc
   │  │  │     │  ├─ test_softplus_layer.cc
   │  │  │     │  ├─ test_splitv_layer.cc
   │  │  │     │  ├─ test_sqrt_layer.cc
   │  │  │     │  ├─ test_squeeze_layer.cc
   │  │  │     │  ├─ test_stride_slice_layer.cc
   │  │  │     │  ├─ test_sub_layer.cc
   │  │  │     │  ├─ test_tan_layer.cc
   │  │  │     │  ├─ test_tanh_layer.cc
   │  │  │     │  ├─ test_tile_layer.cc
   │  │  │     │  ├─ test_unary_layer.cc
   │  │  │     │  ├─ test_unary_layer.h
   │  │  │     │  ├─ test_unsqueeze_layer.cc
   │  │  │     │  └─ test_upsample_layer.cc
   │  │  │     ├─ mat_converter_test.cc
   │  │  │     ├─ mat_converter_test.h
   │  │  │     ├─ third_party
   │  │  │     │  └─ googletest
   │  │  │     │     ├─ .clang-format
   │  │  │     │     ├─ .gitignore
   │  │  │     │     ├─ .travis.yml
   │  │  │     │     ├─ BUILD.bazel
   │  │  │     │     ├─ CMakeLists.txt
   │  │  │     │     ├─ CONTRIBUTING.md
   │  │  │     │     ├─ LICENSE
   │  │  │     │     ├─ README.md
   │  │  │     │     ├─ WORKSPACE
   │  │  │     │     ├─ appveyor.yml
   │  │  │     │     ├─ ci
   │  │  │     │     │  ├─ build-linux-bazel.sh
   │  │  │     │     │  ├─ build-platformio.sh
   │  │  │     │     │  ├─ env-linux.sh
   │  │  │     │     │  ├─ env-osx.sh
   │  │  │     │     │  ├─ get-nprocessors.sh
   │  │  │     │     │  ├─ install-linux.sh
   │  │  │     │     │  ├─ install-osx.sh
   │  │  │     │     │  ├─ install-platformio.sh
   │  │  │     │     │  ├─ log-config.sh
   │  │  │     │     │  └─ travis.sh
   │  │  │     │     ├─ googlemock
   │  │  │     │     │  ├─ CMakeLists.txt
   │  │  │     │     │  ├─ CONTRIBUTORS
   │  │  │     │     │  ├─ LICENSE
   │  │  │     │     │  ├─ README.md
   │  │  │     │     │  ├─ cmake
   │  │  │     │     │  │  ├─ gmock.pc.in
   │  │  │     │     │  │  └─ gmock_main.pc.in
   │  │  │     │     │  ├─ docs
   │  │  │     │     │  │  ├─ cheat_sheet.md
   │  │  │     │     │  │  ├─ cook_book.md
   │  │  │     │     │  │  ├─ for_dummies.md
   │  │  │     │     │  │  └─ gmock_faq.md
   │  │  │     │     │  ├─ include
   │  │  │     │     │  │  └─ gmock
   │  │  │     │     │  │     ├─ gmock-actions.h
   │  │  │     │     │  │     ├─ gmock-cardinalities.h
   │  │  │     │     │  │     ├─ gmock-function-mocker.h
   │  │  │     │     │  │     ├─ gmock-generated-actions.h
   │  │  │     │     │  │     ├─ gmock-generated-actions.h.pump
   │  │  │     │     │  │     ├─ gmock-generated-function-mockers.h
   │  │  │     │     │  │     ├─ gmock-generated-function-mockers.h.pump
   │  │  │     │     │  │     ├─ gmock-generated-matchers.h
   │  │  │     │     │  │     ├─ gmock-generated-matchers.h.pump
   │  │  │     │     │  │     ├─ gmock-matchers.h
   │  │  │     │     │  │     ├─ gmock-more-actions.h
   │  │  │     │     │  │     ├─ gmock-more-matchers.h
   │  │  │     │     │  │     ├─ gmock-nice-strict.h
   │  │  │     │     │  │     ├─ gmock-spec-builders.h
   │  │  │     │     │  │     ├─ gmock.h
   │  │  │     │     │  │     └─ internal
   │  │  │     │     │  │        ├─ custom
   │  │  │     │     │  │        │  ├─ README.md
   │  │  │     │     │  │        │  ├─ gmock-generated-actions.h
   │  │  │     │     │  │        │  ├─ gmock-generated-actions.h.pump
   │  │  │     │     │  │        │  ├─ gmock-matchers.h
   │  │  │     │     │  │        │  └─ gmock-port.h
   │  │  │     │     │  │        ├─ gmock-internal-utils.h
   │  │  │     │     │  │        ├─ gmock-port.h
   │  │  │     │     │  │        └─ gmock-pp.h
   │  │  │     │     │  ├─ scripts
   │  │  │     │     │  │  ├─ fuse_gmock_files.py
   │  │  │     │     │  │  ├─ generator
   │  │  │     │     │  │  │  ├─ LICENSE
   │  │  │     │     │  │  │  ├─ README
   │  │  │     │     │  │  │  ├─ README.cppclean
   │  │  │     │     │  │  │  ├─ cpp
   │  │  │     │     │  │  │  │  ├─ __init__.py
   │  │  │     │     │  │  │  │  ├─ ast.py
   │  │  │     │     │  │  │  │  ├─ gmock_class.py
   │  │  │     │     │  │  │  │  ├─ gmock_class_test.py
   │  │  │     │     │  │  │  │  ├─ keywords.py
   │  │  │     │     │  │  │  │  ├─ tokenize.py
   │  │  │     │     │  │  │  │  └─ utils.py
   │  │  │     │     │  │  │  └─ gmock_gen.py
   │  │  │     │     │  │  ├─ gmock-config.in
   │  │  │     │     │  │  ├─ gmock_doctor.py
   │  │  │     │     │  │  ├─ upload.py
   │  │  │     │     │  │  └─ upload_gmock.py
   │  │  │     │     │  ├─ src
   │  │  │     │     │  │  ├─ gmock-all.cc
   │  │  │     │     │  │  ├─ gmock-cardinalities.cc
   │  │  │     │     │  │  ├─ gmock-internal-utils.cc
   │  │  │     │     │  │  ├─ gmock-matchers.cc
   │  │  │     │     │  │  ├─ gmock-spec-builders.cc
   │  │  │     │     │  │  ├─ gmock.cc
   │  │  │     │     │  │  └─ gmock_main.cc
   │  │  │     │     │  └─ test
   │  │  │     │     │     ├─ BUILD.bazel
   │  │  │     │     │     ├─ gmock-actions_test.cc
   │  │  │     │     │     ├─ gmock-cardinalities_test.cc
   │  │  │     │     │     ├─ gmock-function-mocker_nc.cc
   │  │  │     │     │     ├─ gmock-function-mocker_nc_test.py
   │  │  │     │     │     ├─ gmock-function-mocker_test.cc
   │  │  │     │     │     ├─ gmock-generated-actions_test.cc
   │  │  │     │     │     ├─ gmock-generated-function-mockers_test.cc
   │  │  │     │     │     ├─ gmock-generated-matchers_test.cc
   │  │  │     │     │     ├─ gmock-internal-utils_test.cc
   │  │  │     │     │     ├─ gmock-matchers_test.cc
   │  │  │     │     │     ├─ gmock-more-actions_test.cc
   │  │  │     │     │     ├─ gmock-nice-strict_test.cc
   │  │  │     │     │     ├─ gmock-port_test.cc
   │  │  │     │     │     ├─ gmock-pp-string_test.cc
   │  │  │     │     │     ├─ gmock-pp_test.cc
   │  │  │     │     │     ├─ gmock-spec-builders_test.cc
   │  │  │     │     │     ├─ gmock_all_test.cc
   │  │  │     │     │     ├─ gmock_ex_test.cc
   │  │  │     │     │     ├─ gmock_leak_test.py
   │  │  │     │     │     ├─ gmock_leak_test_.cc
   │  │  │     │     │     ├─ gmock_link2_test.cc
   │  │  │     │     │     ├─ gmock_link_test.cc
   │  │  │     │     │     ├─ gmock_link_test.h
   │  │  │     │     │     ├─ gmock_output_test.py
   │  │  │     │     │     ├─ gmock_output_test_.cc
   │  │  │     │     │     ├─ gmock_output_test_golden.txt
   │  │  │     │     │     ├─ gmock_stress_test.cc
   │  │  │     │     │     ├─ gmock_test.cc
   │  │  │     │     │     └─ gmock_test_utils.py
   │  │  │     │     ├─ googletest
   │  │  │     │     │  ├─ CMakeLists.txt
   │  │  │     │     │  ├─ CONTRIBUTORS
   │  │  │     │     │  ├─ LICENSE
   │  │  │     │     │  ├─ README.md
   │  │  │     │     │  ├─ cmake
   │  │  │     │     │  │  ├─ Config.cmake.in
   │  │  │     │     │  │  ├─ gtest.pc.in
   │  │  │     │     │  │  ├─ gtest_main.pc.in
   │  │  │     │     │  │  ├─ internal_utils.cmake
   │  │  │     │     │  │  └─ libgtest.la.in
   │  │  │     │     │  ├─ docs
   │  │  │     │     │  │  ├─ advanced.md
   │  │  │     │     │  │  ├─ faq.md
   │  │  │     │     │  │  ├─ pkgconfig.md
   │  │  │     │     │  │  ├─ primer.md
   │  │  │     │     │  │  ├─ pump_manual.md
   │  │  │     │     │  │  └─ samples.md
   │  │  │     │     │  ├─ include
   │  │  │     │     │  │  └─ gtest
   │  │  │     │     │  │     ├─ gtest-death-test.h
   │  │  │     │     │  │     ├─ gtest-matchers.h
   │  │  │     │     │  │     ├─ gtest-message.h
   │  │  │     │     │  │     ├─ gtest-param-test.h
   │  │  │     │     │  │     ├─ gtest-printers.h
   │  │  │     │     │  │     ├─ gtest-spi.h
   │  │  │     │     │  │     ├─ gtest-test-part.h
   │  │  │     │     │  │     ├─ gtest-typed-test.h
   │  │  │     │     │  │     ├─ gtest.h
   │  │  │     │     │  │     ├─ gtest_pred_impl.h
   │  │  │     │     │  │     ├─ gtest_prod.h
   │  │  │     │     │  │     └─ internal
   │  │  │     │     │  │        ├─ custom
   │  │  │     │     │  │        │  ├─ README.md
   │  │  │     │     │  │        │  ├─ gtest-port.h
   │  │  │     │     │  │        │  ├─ gtest-printers.h
   │  │  │     │     │  │        │  └─ gtest.h
   │  │  │     │     │  │        ├─ gtest-death-test-internal.h
   │  │  │     │     │  │        ├─ gtest-filepath.h
   │  │  │     │     │  │        ├─ gtest-internal.h
   │  │  │     │     │  │        ├─ gtest-param-util.h
   │  │  │     │     │  │        ├─ gtest-port-arch.h
   │  │  │     │     │  │        ├─ gtest-port.h
   │  │  │     │     │  │        ├─ gtest-string.h
   │  │  │     │     │  │        ├─ gtest-type-util.h
   │  │  │     │     │  │        └─ gtest-type-util.h.pump
   │  │  │     │     │  ├─ samples
   │  │  │     │     │  │  ├─ prime_tables.h
   │  │  │     │     │  │  ├─ sample1.cc
   │  │  │     │     │  │  ├─ sample1.h
   │  │  │     │     │  │  ├─ sample10_unittest.cc
   │  │  │     │     │  │  ├─ sample1_unittest.cc
   │  │  │     │     │  │  ├─ sample2.cc
   │  │  │     │     │  │  ├─ sample2.h
   │  │  │     │     │  │  ├─ sample2_unittest.cc
   │  │  │     │     │  │  ├─ sample3-inl.h
   │  │  │     │     │  │  ├─ sample3_unittest.cc
   │  │  │     │     │  │  ├─ sample4.cc
   │  │  │     │     │  │  ├─ sample4.h
   │  │  │     │     │  │  ├─ sample4_unittest.cc
   │  │  │     │     │  │  ├─ sample5_unittest.cc
   │  │  │     │     │  │  ├─ sample6_unittest.cc
   │  │  │     │     │  │  ├─ sample7_unittest.cc
   │  │  │     │     │  │  ├─ sample8_unittest.cc
   │  │  │     │     │  │  └─ sample9_unittest.cc
   │  │  │     │     │  ├─ scripts
   │  │  │     │     │  │  ├─ common.py
   │  │  │     │     │  │  ├─ fuse_gtest_files.py
   │  │  │     │     │  │  ├─ gen_gtest_pred_impl.py
   │  │  │     │     │  │  ├─ gtest-config.in
   │  │  │     │     │  │  ├─ pump.py
   │  │  │     │     │  │  ├─ release_docs.py
   │  │  │     │     │  │  ├─ upload.py
   │  │  │     │     │  │  └─ upload_gtest.py
   │  │  │     │     │  ├─ src
   │  │  │     │     │  │  ├─ gtest-all.cc
   │  │  │     │     │  │  ├─ gtest-death-test.cc
   │  │  │     │     │  │  ├─ gtest-filepath.cc
   │  │  │     │     │  │  ├─ gtest-internal-inl.h
   │  │  │     │     │  │  ├─ gtest-matchers.cc
   │  │  │     │     │  │  ├─ gtest-port.cc
   │  │  │     │     │  │  ├─ gtest-printers.cc
   │  │  │     │     │  │  ├─ gtest-test-part.cc
   │  │  │     │     │  │  ├─ gtest-typed-test.cc
   │  │  │     │     │  │  ├─ gtest.cc
   │  │  │     │     │  │  └─ gtest_main.cc
   │  │  │     │     │  └─ test
   │  │  │     │     │     ├─ BUILD.bazel
   │  │  │     │     │     ├─ googletest-break-on-failure-unittest.py
   │  │  │     │     │     ├─ googletest-break-on-failure-unittest_.cc
   │  │  │     │     │     ├─ googletest-catch-exceptions-test.py
   │  │  │     │     │     ├─ googletest-catch-exceptions-test_.cc
   │  │  │     │     │     ├─ googletest-color-test.py
   │  │  │     │     │     ├─ googletest-color-test_.cc
   │  │  │     │     │     ├─ googletest-death-test-test.cc
   │  │  │     │     │     ├─ googletest-death-test_ex_test.cc
   │  │  │     │     │     ├─ googletest-env-var-test.py
   │  │  │     │     │     ├─ googletest-env-var-test_.cc
   │  │  │     │     │     ├─ googletest-filepath-test.cc
   │  │  │     │     │     ├─ googletest-filter-unittest.py
   │  │  │     │     │     ├─ googletest-filter-unittest_.cc
   │  │  │     │     │     ├─ googletest-json-outfiles-test.py
   │  │  │     │     │     ├─ googletest-json-output-unittest.py
   │  │  │     │     │     ├─ googletest-list-tests-unittest.py
   │  │  │     │     │     ├─ googletest-list-tests-unittest_.cc
   │  │  │     │     │     ├─ googletest-listener-test.cc
   │  │  │     │     │     ├─ googletest-message-test.cc
   │  │  │     │     │     ├─ googletest-options-test.cc
   │  │  │     │     │     ├─ googletest-output-test-golden-lin.txt
   │  │  │     │     │     ├─ googletest-output-test.py
   │  │  │     │     │     ├─ googletest-output-test_.cc
   │  │  │     │     │     ├─ googletest-param-test-invalid-name1-test.py
   │  │  │     │     │     ├─ googletest-param-test-invalid-name1-test_.cc
   │  │  │     │     │     ├─ googletest-param-test-invalid-name2-test.py
   │  │  │     │     │     ├─ googletest-param-test-invalid-name2-test_.cc
   │  │  │     │     │     ├─ googletest-param-test-test.cc
   │  │  │     │     │     ├─ googletest-param-test-test.h
   │  │  │     │     │     ├─ googletest-param-test2-test.cc
   │  │  │     │     │     ├─ googletest-port-test.cc
   │  │  │     │     │     ├─ googletest-printers-test.cc
   │  │  │     │     │     ├─ googletest-shuffle-test.py
   │  │  │     │     │     ├─ googletest-shuffle-test_.cc
   │  │  │     │     │     ├─ googletest-test-part-test.cc
   │  │  │     │     │     ├─ googletest-test2_test.cc
   │  │  │     │     │     ├─ googletest-throw-on-failure-test.py
   │  │  │     │     │     ├─ googletest-throw-on-failure-test_.cc
   │  │  │     │     │     ├─ googletest-uninitialized-test.py
   │  │  │     │     │     ├─ googletest-uninitialized-test_.cc
   │  │  │     │     │     ├─ gtest-typed-test2_test.cc
   │  │  │     │     │     ├─ gtest-typed-test_test.cc
   │  │  │     │     │     ├─ gtest-typed-test_test.h
   │  │  │     │     │     ├─ gtest-unittest-api_test.cc
   │  │  │     │     │     ├─ gtest_all_test.cc
   │  │  │     │     │     ├─ gtest_assert_by_exception_test.cc
   │  │  │     │     │     ├─ gtest_environment_test.cc
   │  │  │     │     │     ├─ gtest_help_test.py
   │  │  │     │     │     ├─ gtest_help_test_.cc
   │  │  │     │     │     ├─ gtest_json_test_utils.py
   │  │  │     │     │     ├─ gtest_list_output_unittest.py
   │  │  │     │     │     ├─ gtest_list_output_unittest_.cc
   │  │  │     │     │     ├─ gtest_main_unittest.cc
   │  │  │     │     │     ├─ gtest_no_test_unittest.cc
   │  │  │     │     │     ├─ gtest_pred_impl_unittest.cc
   │  │  │     │     │     ├─ gtest_premature_exit_test.cc
   │  │  │     │     │     ├─ gtest_prod_test.cc
   │  │  │     │     │     ├─ gtest_repeat_test.cc
   │  │  │     │     │     ├─ gtest_skip_environment_check_output_test.py
   │  │  │     │     │     ├─ gtest_skip_in_environment_setup_test.cc
   │  │  │     │     │     ├─ gtest_skip_test.cc
   │  │  │     │     │     ├─ gtest_sole_header_test.cc
   │  │  │     │     │     ├─ gtest_stress_test.cc
   │  │  │     │     │     ├─ gtest_test_macro_stack_footprint_test.cc
   │  │  │     │     │     ├─ gtest_test_utils.py
   │  │  │     │     │     ├─ gtest_testbridge_test.py
   │  │  │     │     │     ├─ gtest_testbridge_test_.cc
   │  │  │     │     │     ├─ gtest_throw_on_failure_ex_test.cc
   │  │  │     │     │     ├─ gtest_unittest.cc
   │  │  │     │     │     ├─ gtest_xml_outfile1_test_.cc
   │  │  │     │     │     ├─ gtest_xml_outfile2_test_.cc
   │  │  │     │     │     ├─ gtest_xml_outfiles_test.py
   │  │  │     │     │     ├─ gtest_xml_output_unittest.py
   │  │  │     │     │     ├─ gtest_xml_output_unittest_.cc
   │  │  │     │     │     ├─ gtest_xml_test_utils.py
   │  │  │     │     │     ├─ production.cc
   │  │  │     │     │     └─ production.h
   │  │  │     │     ├─ library.json
   │  │  │     │     └─ platformio.ini
   │  │  │     ├─ unit_test.cc
   │  │  │     ├─ unit_test_common.cc
   │  │  │     ├─ unit_test_common.h
   │  │  │     ├─ unit_test_macro.h
   │  │  │     └─ utils
   │  │  │        ├─ network_helpers.cc
   │  │  │        └─ network_helpers.h
   │  │  ├─ third_party
   │  │  │  ├─ flatbuffers
   │  │  │  │  ├─ .appveyor
   │  │  │  │  │  └─ check-generate-code.bat
   │  │  │  │  ├─ .bazelci
   │  │  │  │  │  └─ presubmit.yml
   │  │  │  │  ├─ .clang-format
   │  │  │  │  ├─ .editorconfig
   │  │  │  │  ├─ .eslintrc.js
   │  │  │  │  ├─ .gitattributes
   │  │  │  │  ├─ .github
   │  │  │  │  │  ├─ ISSUE_TEMPLATE.md
   │  │  │  │  │  ├─ PULL_REQUEST_TEMPLATE.md
   │  │  │  │  │  ├─ labeler.yml
   │  │  │  │  │  └─ workflows
   │  │  │  │  │     ├─ build.yml
   │  │  │  │  │     ├─ label.yml
   │  │  │  │  │     └─ stale.yml
   │  │  │  │  ├─ .gitignore
   │  │  │  │  ├─ .travis.yml
   │  │  │  │  ├─ .travis
   │  │  │  │  │  ├─ build-and-run-docker-test-containers.sh
   │  │  │  │  │  ├─ check-sources.sh
   │  │  │  │  │  ├─ check-sources.sh.py
   │  │  │  │  │  ├─ deploy-python.sh
   │  │  │  │  │  ├─ format_check.sh
   │  │  │  │  │  └─ format_install.sh
   │  │  │  │  ├─ BUILD.bazel
   │  │  │  │  ├─ CMake
   │  │  │  │  │  ├─ BuildFlatBuffers.cmake
   │  │  │  │  │  ├─ DESCRIPTION.txt
   │  │  │  │  │  ├─ FindFlatBuffers.cmake
   │  │  │  │  │  ├─ FlatbuffersConfig.cmake
   │  │  │  │  │  ├─ FlatbuffersConfigVersion.cmake.in
   │  │  │  │  │  ├─ PackageDebian.cmake
   │  │  │  │  │  ├─ PackageRedhat.cmake
   │  │  │  │  │  ├─ Version.cmake
   │  │  │  │  │  └─ flatbuffers.pc.in
   │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  ├─ CONTRIBUTING.md
   │  │  │  │  ├─ Formatters.md
   │  │  │  │  ├─ LICENSE.txt
   │  │  │  │  ├─ WORKSPACE
   │  │  │  │  ├─ android
   │  │  │  │  │  ├─ AndroidManifest.xml
   │  │  │  │  │  ├─ app
   │  │  │  │  │  │  ├─ .gitignore
   │  │  │  │  │  │  ├─ build.gradle
   │  │  │  │  │  │  ├─ proguard-rules.pro
   │  │  │  │  │  │  └─ src
   │  │  │  │  │  │     └─ main
   │  │  │  │  │  │        ├─ AndroidManifest.xml
   │  │  │  │  │  │        ├─ cpp
   │  │  │  │  │  │        │  ├─ CMakeLists.txt
   │  │  │  │  │  │        │  ├─ animals.cpp
   │  │  │  │  │  │        │  ├─ flatbuffers
   │  │  │  │  │  │        │  │  └─ CMakeLists.txt
   │  │  │  │  │  │        │  └─ generated
   │  │  │  │  │  │        │     └─ animal_generated.h
   │  │  │  │  │  │        ├─ fbs
   │  │  │  │  │  │        │  └─ animal.fbs
   │  │  │  │  │  │        ├─ java
   │  │  │  │  │  │        │  ├─ com
   │  │  │  │  │  │        │  │  └─ flatbuffers
   │  │  │  │  │  │        │  │     └─ app
   │  │  │  │  │  │        │  │        └─ MainActivity.kt
   │  │  │  │  │  │        │  └─ generated
   │  │  │  │  │  │        │     └─ com
   │  │  │  │  │  │        │        └─ fbs
   │  │  │  │  │  │        │           └─ app
   │  │  │  │  │  │        │              └─ Animal.kt
   │  │  │  │  │  │        └─ res
   │  │  │  │  │  │           ├─ drawable-v24
   │  │  │  │  │  │           │  └─ ic_launcher_foreground.xml
   │  │  │  │  │  │           ├─ drawable
   │  │  │  │  │  │           │  └─ ic_launcher_background.xml
   │  │  │  │  │  │           ├─ layout
   │  │  │  │  │  │           │  └─ activity_main.xml
   │  │  │  │  │  │           ├─ mipmap-anydpi-v26
   │  │  │  │  │  │           │  ├─ ic_launcher.xml
   │  │  │  │  │  │           │  └─ ic_launcher_round.xml
   │  │  │  │  │  │           ├─ mipmap-hdpi
   │  │  │  │  │  │           │  ├─ ic_launcher.png
   │  │  │  │  │  │           │  └─ ic_launcher_round.png
   │  │  │  │  │  │           ├─ mipmap-mdpi
   │  │  │  │  │  │           │  ├─ ic_launcher.png
   │  │  │  │  │  │           │  └─ ic_launcher_round.png
   │  │  │  │  │  │           ├─ mipmap-xhdpi
   │  │  │  │  │  │           │  ├─ ic_launcher.png
   │  │  │  │  │  │           │  └─ ic_launcher_round.png
   │  │  │  │  │  │           ├─ mipmap-xxhdpi
   │  │  │  │  │  │           │  ├─ ic_launcher.png
   │  │  │  │  │  │           │  └─ ic_launcher_round.png
   │  │  │  │  │  │           ├─ mipmap-xxxhdpi
   │  │  │  │  │  │           │  ├─ ic_launcher.png
   │  │  │  │  │  │           │  └─ ic_launcher_round.png
   │  │  │  │  │  │           └─ values
   │  │  │  │  │  │              ├─ colors.xml
   │  │  │  │  │  │              ├─ strings.xml
   │  │  │  │  │  │              └─ styles.xml
   │  │  │  │  │  ├─ build.gradle
   │  │  │  │  │  ├─ gradle.properties
   │  │  │  │  │  ├─ gradle
   │  │  │  │  │  │  └─ wrapper
   │  │  │  │  │  │     ├─ gradle-wrapper.jar
   │  │  │  │  │  │     └─ gradle-wrapper.properties
   │  │  │  │  │  ├─ gradlew
   │  │  │  │  │  ├─ gradlew.bat
   │  │  │  │  │  └─ settings.gradle
   │  │  │  │  ├─ appveyor.yml
   │  │  │  │  ├─ bazel
   │  │  │  │  │  └─ BUILD.bazel
   │  │  │  │  ├─ build_defs.bzl
   │  │  │  │  ├─ composer.json
   │  │  │  │  ├─ conan
   │  │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  │  ├─ appveyor
   │  │  │  │  │  │  ├─ build.py
   │  │  │  │  │  │  └─ install.py
   │  │  │  │  │  ├─ build.py
   │  │  │  │  │  ├─ test_package
   │  │  │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  │  │  ├─ conanfile.py
   │  │  │  │  │  │  └─ test_package.cpp
   │  │  │  │  │  └─ travis
   │  │  │  │  │     ├─ build.sh
   │  │  │  │  │     └─ install.sh
   │  │  │  │  ├─ conanfile.py
   │  │  │  │  ├─ dart
   │  │  │  │  │  ├─ CHANGELOG.md
   │  │  │  │  │  ├─ LICENSE
   │  │  │  │  │  ├─ README.md
   │  │  │  │  │  ├─ example
   │  │  │  │  │  │  ├─ example.dart
   │  │  │  │  │  │  └─ monster_my_game.sample_generated.dart
   │  │  │  │  │  ├─ publish.sh
   │  │  │  │  │  ├─ pubspec.yaml
   │  │  │  │  │  └─ test
   │  │  │  │  │     ├─ flat_buffers_test.dart
   │  │  │  │  │     ├─ flex_builder_test.dart
   │  │  │  │  │     ├─ flex_reader_test.dart
   │  │  │  │  │     ├─ flex_types_test.dart
   │  │  │  │  │     ├─ monster_test_my_game.example2_generated.dart
   │  │  │  │  │     ├─ monster_test_my_game.example_generated.dart
   │  │  │  │  │     └─ monster_test_my_game_generated.dart
   │  │  │  │  ├─ docs
   │  │  │  │  │  ├─ footer.html
   │  │  │  │  │  ├─ header.html
   │  │  │  │  │  ├─ images
   │  │  │  │  │  │  ├─ fpl_logo_small.png
   │  │  │  │  │  │  ├─ ftv2mnode.png
   │  │  │  │  │  │  └─ ftv2pnode.png
   │  │  │  │  │  └─ source
   │  │  │  │  │     ├─ Benchmarks.md
   │  │  │  │  │     ├─ Building.md
   │  │  │  │  │     ├─ CONTRIBUTING.md
   │  │  │  │  │     ├─ CUsage.md
   │  │  │  │  │     ├─ Compiler.md
   │  │  │  │  │     ├─ CppUsage.md
   │  │  │  │  │     ├─ CsharpUsage.md
   │  │  │  │  │     ├─ DartUsage.md
   │  │  │  │  │     ├─ FlatBuffers.md
   │  │  │  │  │     ├─ FlexBuffers.md
   │  │  │  │  │     ├─ GoApi.md
   │  │  │  │  │     ├─ GoApi_generated.txt
   │  │  │  │  │     ├─ GoUsage.md
   │  │  │  │  │     ├─ Grammar.md
   │  │  │  │  │     ├─ Internals.md
   │  │  │  │  │     ├─ JavaScriptUsage.md
   │  │  │  │  │     ├─ JavaUsage.md
   │  │  │  │  │     ├─ KotlinUsage.md
   │  │  │  │  │     ├─ LobsterUsage.md
   │  │  │  │  │     ├─ LuaUsage.md
   │  │  │  │  │     ├─ PHPUsage.md
   │  │  │  │  │     ├─ PythonUsage.md
   │  │  │  │  │     ├─ README_TO_GENERATE_DOCS.md
   │  │  │  │  │     ├─ RustUsage.md
   │  │  │  │  │     ├─ Schemas.md
   │  │  │  │  │     ├─ Support.md
   │  │  │  │  │     ├─ SwiftUsage.md
   │  │  │  │  │     ├─ Tutorial.md
   │  │  │  │  │     ├─ TypeScriptUsage.md
   │  │  │  │  │     ├─ WhitePaper.md
   │  │  │  │  │     ├─ doxyfile
   │  │  │  │  │     ├─ doxygen_layout.xml
   │  │  │  │  │     ├─ gRPC
   │  │  │  │  │     │  └─ CppUsage.md
   │  │  │  │  │     ├─ groups
   │  │  │  │  │     └─ style.css
   │  │  │  │  ├─ go
   │  │  │  │  │  ├─ BUILD.bazel
   │  │  │  │  │  ├─ builder.go
   │  │  │  │  │  ├─ doc.go
   │  │  │  │  │  ├─ encode.go
   │  │  │  │  │  ├─ grpc.go
   │  │  │  │  │  ├─ lib.go
   │  │  │  │  │  ├─ sizes.go
   │  │  │  │  │  ├─ struct.go
   │  │  │  │  │  └─ table.go
   │  │  │  │  ├─ grpc
   │  │  │  │  │  ├─ BUILD.bazel
   │  │  │  │  │  ├─ README.md
   │  │  │  │  │  ├─ boringssl.patch
   │  │  │  │  │  ├─ build_grpc.sh
   │  │  │  │  │  ├─ examples
   │  │  │  │  │  │  ├─ README.md
   │  │  │  │  │  │  ├─ generate.sh
   │  │  │  │  │  │  ├─ go
   │  │  │  │  │  │  │  ├─ format.sh
   │  │  │  │  │  │  │  └─ greeter
   │  │  │  │  │  │  │     ├─ .gitignore
   │  │  │  │  │  │  │     ├─ README.md
   │  │  │  │  │  │  │     └─ models
   │  │  │  │  │  │  │        ├─ Greeter_grpc.go
   │  │  │  │  │  │  │        ├─ HelloReply.go
   │  │  │  │  │  │  │        └─ HelloRequest.go
   │  │  │  │  │  │  ├─ greeter.fbs
   │  │  │  │  │  │  ├─ python
   │  │  │  │  │  │  │  └─ greeter
   │  │  │  │  │  │  │     ├─ README.md
   │  │  │  │  │  │  │     ├─ client.py
   │  │  │  │  │  │  │     ├─ models
   │  │  │  │  │  │  │     │  ├─ HelloReply.py
   │  │  │  │  │  │  │     │  ├─ HelloRequest.py
   │  │  │  │  │  │  │     │  ├─ __init__.py
   │  │  │  │  │  │  │     │  └─ greeter_grpc_fb.py
   │  │  │  │  │  │  │     └─ server.py
   │  │  │  │  │  │  ├─ swift
   │  │  │  │  │  │  │  └─ Greeter
   │  │  │  │  │  │  │     ├─ Package.swift
   │  │  │  │  │  │  │     ├─ README.md
   │  │  │  │  │  │  │     └─ Sources
   │  │  │  │  │  │  │        ├─ client
   │  │  │  │  │  │  │        │  └─ main.swift
   │  │  │  │  │  │  │        └─ server
   │  │  │  │  │  │  │           └─ main.swift
   │  │  │  │  │  │  └─ ts
   │  │  │  │  │  │     └─ greeter
   │  │  │  │  │  │        ├─ README.md
   │  │  │  │  │  │        ├─ package.json
   │  │  │  │  │  │        ├─ src
   │  │  │  │  │  │        │  ├─ client.ts
   │  │  │  │  │  │        │  ├─ greeter_grpc.d.ts
   │  │  │  │  │  │        │  ├─ greeter_grpc.js
   │  │  │  │  │  │        │  ├─ models
   │  │  │  │  │  │        │  │  ├─ hello-reply.ts
   │  │  │  │  │  │        │  │  └─ hello-request.ts
   │  │  │  │  │  │        │  └─ server.ts
   │  │  │  │  │  │        └─ tsconfig.json
   │  │  │  │  │  ├─ flatbuffers-java-grpc
   │  │  │  │  │  │  ├─ pom.xml
   │  │  │  │  │  │  └─ src
   │  │  │  │  │  │     └─ main
   │  │  │  │  │  │        └─ java
   │  │  │  │  │  │           └─ com
   │  │  │  │  │  │              └─ google
   │  │  │  │  │  │                 └─ flatbuffers
   │  │  │  │  │  │                    └─ grpc
   │  │  │  │  │  │                       └─ FlatbuffersUtils.java
   │  │  │  │  │  ├─ pom.xml
   │  │  │  │  │  ├─ samples
   │  │  │  │  │  │  └─ greeter
   │  │  │  │  │  │     ├─ client.cpp
   │  │  │  │  │  │     ├─ greeter.fbs
   │  │  │  │  │  │     └─ server.cpp
   │  │  │  │  │  ├─ src
   │  │  │  │  │  │  └─ compiler
   │  │  │  │  │  │     ├─ BUILD.bazel
   │  │  │  │  │  │     ├─ config.h
   │  │  │  │  │  │     ├─ cpp_generator.cc
   │  │  │  │  │  │     ├─ cpp_generator.h
   │  │  │  │  │  │     ├─ go_generator.cc
   │  │  │  │  │  │     ├─ go_generator.h
   │  │  │  │  │  │     ├─ java_generator.cc
   │  │  │  │  │  │     ├─ java_generator.h
   │  │  │  │  │  │     ├─ python_generator.cc
   │  │  │  │  │  │     ├─ python_generator.h
   │  │  │  │  │  │     ├─ schema_interface.h
   │  │  │  │  │  │     ├─ swift_generator.cc
   │  │  │  │  │  │     ├─ swift_generator.h
   │  │  │  │  │  │     ├─ ts_generator.cc
   │  │  │  │  │  │     └─ ts_generator.h
   │  │  │  │  │  └─ tests
   │  │  │  │  │     ├─ GameFactory.java
   │  │  │  │  │     ├─ JavaGrpcTest.java
   │  │  │  │  │     ├─ go_test.go
   │  │  │  │  │     ├─ grpctest.cpp
   │  │  │  │  │     ├─ grpctest.py
   │  │  │  │  │     ├─ java-grpc-test.sh
   │  │  │  │  │     ├─ message_builder_test.cpp
   │  │  │  │  │     └─ pom.xml
   │  │  │  │  ├─ include
   │  │  │  │  │  └─ flatbuffers
   │  │  │  │  │     ├─ base.h
   │  │  │  │  │     ├─ code_generators.h
   │  │  │  │  │     ├─ flatbuffers.h
   │  │  │  │  │     ├─ flatc.h
   │  │  │  │  │     ├─ flexbuffers.h
   │  │  │  │  │     ├─ grpc.h
   │  │  │  │  │     ├─ hash.h
   │  │  │  │  │     ├─ idl.h
   │  │  │  │  │     ├─ minireflect.h
   │  │  │  │  │     ├─ pch
   │  │  │  │  │     │  ├─ flatc_pch.h
   │  │  │  │  │     │  └─ pch.h
   │  │  │  │  │     ├─ reflection.h
   │  │  │  │  │     ├─ reflection_generated.h
   │  │  │  │  │     ├─ registry.h
   │  │  │  │  │     ├─ stl_emulation.h
   │  │  │  │  │     └─ util.h
   │  │  │  │  ├─ java
   │  │  │  │  │  └─ com
   │  │  │  │  │     └─ google
   │  │  │  │  │        └─ flatbuffers
   │  │  │  │  │           ├─ ArrayReadWriteBuf.java
   │  │  │  │  │           ├─ BaseVector.java
   │  │  │  │  │           ├─ BooleanVector.java
   │  │  │  │  │           ├─ ByteBufferReadWriteBuf.java
   │  │  │  │  │           ├─ ByteBufferUtil.java
   │  │  │  │  │           ├─ ByteVector.java
   │  │  │  │  │           ├─ Constants.java
   │  │  │  │  │           ├─ DoubleVector.java
   │  │  │  │  │           ├─ FlatBufferBuilder.java
   │  │  │  │  │           ├─ FlexBuffers.java
   │  │  │  │  │           ├─ FlexBuffersBuilder.java
   │  │  │  │  │           ├─ FloatVector.java
   │  │  │  │  │           ├─ IntVector.java
   │  │  │  │  │           ├─ LongVector.java
   │  │  │  │  │           ├─ ReadBuf.java
   │  │  │  │  │           ├─ ReadWriteBuf.java
   │  │  │  │  │           ├─ ShortVector.java
   │  │  │  │  │           ├─ StringVector.java
   │  │  │  │  │           ├─ Struct.java
   │  │  │  │  │           ├─ Table.java
   │  │  │  │  │           ├─ UnionVector.java
   │  │  │  │  │           ├─ Utf8.java
   │  │  │  │  │           ├─ Utf8Old.java
   │  │  │  │  │           └─ Utf8Safe.java
   │  │  │  │  ├─ js
   │  │  │  │  │  └─ README.md
   │  │  │  │  ├─ kotlin
   │  │  │  │  │  ├─ benchmark
   │  │  │  │  │  │  ├─ build.gradle.kts
   │  │  │  │  │  │  └─ src
   │  │  │  │  │  │     └─ jvmMain
   │  │  │  │  │  │        ├─ java
   │  │  │  │  │  │        │  └─ com
   │  │  │  │  │  │        │     └─ google
   │  │  │  │  │  │        │        └─ flatbuffers
   │  │  │  │  │  │        │           ├─ ArrayReadWriteBuf.java
   │  │  │  │  │  │        │           ├─ BaseVector.java
   │  │  │  │  │  │        │           ├─ BooleanVector.java
   │  │  │  │  │  │        │           ├─ ByteBufferReadWriteBuf.java
   │  │  │  │  │  │        │           ├─ ByteBufferUtil.java
   │  │  │  │  │  │        │           ├─ ByteVector.java
   │  │  │  │  │  │        │           ├─ Constants.java
   │  │  │  │  │  │        │           ├─ DoubleVector.java
   │  │  │  │  │  │        │           ├─ FlatBufferBuilder.java
   │  │  │  │  │  │        │           ├─ FlexBuffers.java
   │  │  │  │  │  │        │           ├─ FlexBuffersBuilder.java
   │  │  │  │  │  │        │           ├─ FloatVector.java
   │  │  │  │  │  │        │           ├─ IntVector.java
   │  │  │  │  │  │        │           ├─ LongVector.java
   │  │  │  │  │  │        │           ├─ ReadBuf.java
   │  │  │  │  │  │        │           ├─ ReadWriteBuf.java
   │  │  │  │  │  │        │           ├─ ShortVector.java
   │  │  │  │  │  │        │           ├─ StringVector.java
   │  │  │  │  │  │        │           ├─ Struct.java
   │  │  │  │  │  │        │           ├─ Table.java
   │  │  │  │  │  │        │           ├─ UnionVector.java
   │  │  │  │  │  │        │           ├─ Utf8.java
   │  │  │  │  │  │        │           ├─ Utf8Old.java
   │  │  │  │  │  │        │           └─ Utf8Safe.java
   │  │  │  │  │  │        └─ kotlin
   │  │  │  │  │  │           └─ com
   │  │  │  │  │  │              └─ google
   │  │  │  │  │  │                 └─ flatbuffers
   │  │  │  │  │  │                    └─ kotlin
   │  │  │  │  │  │                       └─ benchmark
   │  │  │  │  │  │                          ├─ FlexBuffersBenchmark.kt
   │  │  │  │  │  │                          ├─ JsonBenchmark.kt
   │  │  │  │  │  │                          └─ UTF8Benchmark.kt
   │  │  │  │  │  ├─ build.gradle.kts
   │  │  │  │  │  ├─ flatbuffers-kotlin
   │  │  │  │  │  │  ├─ build.gradle.kts
   │  │  │  │  │  │  └─ src
   │  │  │  │  │  │     ├─ commonMain
   │  │  │  │  │  │     │  └─ kotlin
   │  │  │  │  │  │     │     └─ com
   │  │  │  │  │  │     │        └─ google
   │  │  │  │  │  │     │           └─ flatbuffers
   │  │  │  │  │  │     │              └─ kotlin
   │  │  │  │  │  │     │                 ├─ Buffers.kt
   │  │  │  │  │  │     │                 ├─ ByteArray.kt
   │  │  │  │  │  │     │                 ├─ FlexBuffers.kt
   │  │  │  │  │  │     │                 ├─ FlexBuffersBuilder.kt
   │  │  │  │  │  │     │                 ├─ FlexBuffersInternals.kt
   │  │  │  │  │  │     │                 ├─ JSON.kt
   │  │  │  │  │  │     │                 └─ Utf8.kt
   │  │  │  │  │  │     ├─ commonTest
   │  │  │  │  │  │     │  └─ kotlin
   │  │  │  │  │  │     │     └─ com
   │  │  │  │  │  │     │        └─ google
   │  │  │  │  │  │     │           └─ flatbuffers
   │  │  │  │  │  │     │              └─ kotlin
   │  │  │  │  │  │     │                 ├─ ByteArrayTest.kt
   │  │  │  │  │  │     │                 ├─ FlexBuffersTest.kt
   │  │  │  │  │  │     │                 └─ JSONTest.kt
   │  │  │  │  │  │     ├─ jsMain
   │  │  │  │  │  │     │  └─ kotlin
   │  │  │  │  │  │     │     └─ com
   │  │  │  │  │  │     │        └─ google
   │  │  │  │  │  │     │           └─ flatbuffers
   │  │  │  │  │  │     │              └─ kotlin
   │  │  │  │  │  │     │                 └─ ByteArray.kt
   │  │  │  │  │  │     ├─ jvmMain
   │  │  │  │  │  │     │  └─ kotlin
   │  │  │  │  │  │     │     └─ com
   │  │  │  │  │  │     │        └─ google
   │  │  │  │  │  │     │           └─ flatbuffers
   │  │  │  │  │  │     │              └─ kotlin
   │  │  │  │  │  │     │                 └─ ByteArray.kt
   │  │  │  │  │  │     ├─ jvmTest
   │  │  │  │  │  │     │  ├─ kotlin
   │  │  │  │  │  │     │  │  └─ com
   │  │  │  │  │  │     │  │     └─ google
   │  │  │  │  │  │     │  │        └─ flatbuffers
   │  │  │  │  │  │     │  │           └─ kotlin
   │  │  │  │  │  │     │  │              └─ Utf8Test.kt
   │  │  │  │  │  │     │  └─ resources
   │  │  │  │  │  │     │     └─ utf8_sample.txt
   │  │  │  │  │  │     └─ nativeMain
   │  │  │  │  │  │        └─ kotlin
   │  │  │  │  │  │           └─ com
   │  │  │  │  │  │              └─ google
   │  │  │  │  │  │                 └─ flatbuffers
   │  │  │  │  │  │                    └─ kotlin
   │  │  │  │  │  │                       └─ ByteArray.kt
   │  │  │  │  │  ├─ gradle
   │  │  │  │  │  │  └─ wrapper
   │  │  │  │  │  │     ├─ gradle-wrapper.jar
   │  │  │  │  │  │     └─ gradle-wrapper.properties
   │  │  │  │  │  ├─ gradlew
   │  │  │  │  │  ├─ gradlew.bat
   │  │  │  │  │  ├─ settings.gradle
   │  │  │  │  │  └─ spotless
   │  │  │  │  │     └─ spotless.kt
   │  │  │  │  ├─ lobster
   │  │  │  │  │  └─ flatbuffers.lobster
   │  │  │  │  ├─ lua
   │  │  │  │  │  ├─ flatbuffers.lua
   │  │  │  │  │  └─ flatbuffers
   │  │  │  │  │     ├─ binaryarray.lua
   │  │  │  │  │     ├─ builder.lua
   │  │  │  │  │     ├─ compat.lua
   │  │  │  │  │     ├─ compat_5_1.lua
   │  │  │  │  │     ├─ compat_5_3.lua
   │  │  │  │  │     ├─ compat_luajit.lua
   │  │  │  │  │     ├─ numTypes.lua
   │  │  │  │  │     └─ view.lua
   │  │  │  │  ├─ mjs
   │  │  │  │  │  └─ README.md
   │  │  │  │  ├─ net
   │  │  │  │  │  └─ FlatBuffers
   │  │  │  │  │     ├─ ByteBuffer.cs
   │  │  │  │  │     ├─ ByteBufferUtil.cs
   │  │  │  │  │     ├─ FlatBufferBuilder.cs
   │  │  │  │  │     ├─ FlatBufferConstants.cs
   │  │  │  │  │     ├─ FlatBuffers.csproj
   │  │  │  │  │     ├─ FlatBuffers.net35.csproj
   │  │  │  │  │     ├─ IFlatbufferObject.cs
   │  │  │  │  │     ├─ Offset.cs
   │  │  │  │  │     ├─ Properties
   │  │  │  │  │     │  └─ AssemblyInfo.cs
   │  │  │  │  │     ├─ Struct.cs
   │  │  │  │  │     └─ Table.cs
   │  │  │  │  ├─ package.json
   │  │  │  │  ├─ php
   │  │  │  │  │  ├─ ByteBuffer.php
   │  │  │  │  │  ├─ Constants.php
   │  │  │  │  │  ├─ FlatbufferBuilder.php
   │  │  │  │  │  ├─ Struct.php
   │  │  │  │  │  └─ Table.php
   │  │  │  │  ├─ pom.xml
   │  │  │  │  ├─ python
   │  │  │  │  │  ├─ .gitignore
   │  │  │  │  │  ├─ __init__.py
   │  │  │  │  │  ├─ flatbuffers
   │  │  │  │  │  │  ├─ __init__.py
   │  │  │  │  │  │  ├─ _version.py
   │  │  │  │  │  │  ├─ builder.py
   │  │  │  │  │  │  ├─ compat.py
   │  │  │  │  │  │  ├─ encode.py
   │  │  │  │  │  │  ├─ flexbuffers.py
   │  │  │  │  │  │  ├─ number_types.py
   │  │  │  │  │  │  ├─ packer.py
   │  │  │  │  │  │  ├─ table.py
   │  │  │  │  │  │  └─ util.py
   │  │  │  │  │  ├─ setup.cfg
   │  │  │  │  │  └─ setup.py
   │  │  │  │  ├─ readme.md
   │  │  │  │  ├─ reflection
   │  │  │  │  │  ├─ generate_code.bat
   │  │  │  │  │  ├─ generate_code.sh
   │  │  │  │  │  └─ reflection.fbs
   │  │  │  │  ├─ rust
   │  │  │  │  │  ├─ flatbuffers
   │  │  │  │  │  │  ├─ Cargo.toml
   │  │  │  │  │  │  └─ src
   │  │  │  │  │  │     ├─ array.rs
   │  │  │  │  │  │     ├─ builder.rs
   │  │  │  │  │  │     ├─ endian_scalar.rs
   │  │  │  │  │  │     ├─ follow.rs
   │  │  │  │  │  │     ├─ get_root.rs
   │  │  │  │  │  │     ├─ lib.rs
   │  │  │  │  │  │     ├─ primitives.rs
   │  │  │  │  │  │     ├─ push.rs
   │  │  │  │  │  │     ├─ table.rs
   │  │  │  │  │  │     ├─ vector.rs
   │  │  │  │  │  │     ├─ verifier.rs
   │  │  │  │  │  │     ├─ vtable.rs
   │  │  │  │  │  │     └─ vtable_writer.rs
   │  │  │  │  │  └─ flexbuffers
   │  │  │  │  │     ├─ .gitignore
   │  │  │  │  │     ├─ Cargo.toml
   │  │  │  │  │     ├─ README.md
   │  │  │  │  │     └─ src
   │  │  │  │  │        ├─ bitwidth.rs
   │  │  │  │  │        ├─ buffer.rs
   │  │  │  │  │        ├─ builder
   │  │  │  │  │        │  ├─ map.rs
   │  │  │  │  │        │  ├─ mod.rs
   │  │  │  │  │        │  ├─ push.rs
   │  │  │  │  │        │  ├─ ser.rs
   │  │  │  │  │        │  ├─ value.rs
   │  │  │  │  │        │  └─ vector.rs
   │  │  │  │  │        ├─ flexbuffer_type.rs
   │  │  │  │  │        ├─ lib.rs
   │  │  │  │  │        └─ reader
   │  │  │  │  │           ├─ de.rs
   │  │  │  │  │           ├─ iter.rs
   │  │  │  │  │           ├─ map.rs
   │  │  │  │  │           ├─ mod.rs
   │  │  │  │  │           └─ vector.rs
   │  │  │  │  ├─ samples
   │  │  │  │  │  ├─ SampleBinary.cs
   │  │  │  │  │  ├─ SampleBinary.java
   │  │  │  │  │  ├─ SampleBinary.kt
   │  │  │  │  │  ├─ SampleBinary.php
   │  │  │  │  │  ├─ csharp_sample.sh
   │  │  │  │  │  ├─ dart_sample.sh
   │  │  │  │  │  ├─ go_sample.sh
   │  │  │  │  │  ├─ java_sample.sh
   │  │  │  │  │  ├─ javascript_sample.sh
   │  │  │  │  │  ├─ kotlin_sample.sh
   │  │  │  │  │  ├─ lua
   │  │  │  │  │  │  └─ MyGame
   │  │  │  │  │  │     └─ Sample
   │  │  │  │  │  │        ├─ Color.lua
   │  │  │  │  │  │        ├─ Equipment.lua
   │  │  │  │  │  │        ├─ Monster.lua
   │  │  │  │  │  │        ├─ Vec3.lua
   │  │  │  │  │  │        └─ Weapon.lua
   │  │  │  │  │  ├─ monster.bfbs
   │  │  │  │  │  ├─ monster.fbs
   │  │  │  │  │  ├─ monster_generated.h
   │  │  │  │  │  ├─ monster_generated.lobster
   │  │  │  │  │  ├─ monster_generated.rs
   │  │  │  │  │  ├─ monster_generated.swift
   │  │  │  │  │  ├─ monsterdata.json
   │  │  │  │  │  ├─ php_sample.sh
   │  │  │  │  │  ├─ python_sample.sh
   │  │  │  │  │  ├─ sample_bfbs.cpp
   │  │  │  │  │  ├─ sample_binary.cpp
   │  │  │  │  │  ├─ sample_binary.go
   │  │  │  │  │  ├─ sample_binary.lobster
   │  │  │  │  │  ├─ sample_binary.lua
   │  │  │  │  │  ├─ sample_binary.py
   │  │  │  │  │  ├─ sample_binary.rs
   │  │  │  │  │  ├─ sample_binary.swift
   │  │  │  │  │  ├─ sample_flexbuffers.rs
   │  │  │  │  │  ├─ sample_flexbuffers_serde.rs
   │  │  │  │  │  ├─ sample_text.cpp
   │  │  │  │  │  └─ sample_text.lobster
   │  │  │  │  ├─ scripts
   │  │  │  │  │  ├─ check-generate-code.sh
   │  │  │  │  │  └─ check-grpc-generated-code.sh
   │  │  │  │  ├─ snap
   │  │  │  │  │  └─ snapcraft.yaml
   │  │  │  │  ├─ src
   │  │  │  │  │  ├─ BUILD.bazel
   │  │  │  │  │  ├─ clang-format-all.sh
   │  │  │  │  │  ├─ clang-format-git.sh
   │  │  │  │  │  ├─ code_generators.cpp
   │  │  │  │  │  ├─ flatc.cpp
   │  │  │  │  │  ├─ flatc_main.cpp
   │  │  │  │  │  ├─ flathash.cpp
   │  │  │  │  │  ├─ idl_gen_cpp.cpp
   │  │  │  │  │  ├─ idl_gen_csharp.cpp
   │  │  │  │  │  ├─ idl_gen_dart.cpp
   │  │  │  │  │  ├─ idl_gen_fbs.cpp
   │  │  │  │  │  ├─ idl_gen_go.cpp
   │  │  │  │  │  ├─ idl_gen_grpc.cpp
   │  │  │  │  │  ├─ idl_gen_java.cpp
   │  │  │  │  │  ├─ idl_gen_json_schema.cpp
   │  │  │  │  │  ├─ idl_gen_kotlin.cpp
   │  │  │  │  │  ├─ idl_gen_lobster.cpp
   │  │  │  │  │  ├─ idl_gen_lua.cpp
   │  │  │  │  │  ├─ idl_gen_php.cpp
   │  │  │  │  │  ├─ idl_gen_python.cpp
   │  │  │  │  │  ├─ idl_gen_rust.cpp
   │  │  │  │  │  ├─ idl_gen_swift.cpp
   │  │  │  │  │  ├─ idl_gen_text.cpp
   │  │  │  │  │  ├─ idl_gen_ts.cpp
   │  │  │  │  │  ├─ idl_parser.cpp
   │  │  │  │  │  ├─ reflection.cpp
   │  │  │  │  │  └─ util.cpp
   │  │  │  │  ├─ swift.swiftformat
   │  │  │  │  ├─ swift
   │  │  │  │  │  ├─ FlatBuffers.podspec
   │  │  │  │  │  ├─ LICENSE
   │  │  │  │  │  ├─ Package.swift
   │  │  │  │  │  ├─ README.md
   │  │  │  │  │  └─ Sources
   │  │  │  │  │     └─ FlatBuffers
   │  │  │  │  │        ├─ ByteBuffer.swift
   │  │  │  │  │        ├─ Constants.swift
   │  │  │  │  │        ├─ FlatBufferBuilder.swift
   │  │  │  │  │        ├─ FlatBufferObject.swift
   │  │  │  │  │        ├─ FlatBuffersUtils.swift
   │  │  │  │  │        ├─ Int+extension.swift
   │  │  │  │  │        ├─ Message.swift
   │  │  │  │  │        ├─ Mutable.swift
   │  │  │  │  │        ├─ NativeObject.swift
   │  │  │  │  │        ├─ Offset.swift
   │  │  │  │  │        ├─ String+extension.swift
   │  │  │  │  │        ├─ Struct.swift
   │  │  │  │  │        └─ Table.swift
   │  │  │  │  ├─ tests
   │  │  │  │  │  ├─ BUILD.bazel
   │  │  │  │  │  ├─ DartTest.sh
   │  │  │  │  │  ├─ FlatBuffers.Benchmarks.swift
   │  │  │  │  │  │  ├─ Package.swift
   │  │  │  │  │  │  └─ Sources
   │  │  │  │  │  │     └─ FlatBuffers.Benchmarks.swift
   │  │  │  │  │  │        └─ main.swift
   │  │  │  │  │  ├─ FlatBuffers.Benchmarks
   │  │  │  │  │  │  ├─ FlatBufferBuilderBenchmark.cs
   │  │  │  │  │  │  ├─ FlatBuffers.Benchmarks.csproj
   │  │  │  │  │  │  └─ Program.cs
   │  │  │  │  │  ├─ FlatBuffers.Test.Swift
   │  │  │  │  │  │  ├─ Package.swift
   │  │  │  │  │  │  ├─ Sources
   │  │  │  │  │  │  │  └─ SwiftFlatBuffers
   │  │  │  │  │  │  │     └─ main.swift
   │  │  │  │  │  │  ├─ SwiftTest.sh
   │  │  │  │  │  │  ├─ Tests
   │  │  │  │  │  │  │  ├─ FlatBuffers.Test.SwiftTests
   │  │  │  │  │  │  │  │  ├─ FlatBuffersMonsterWriterTests.swift
   │  │  │  │  │  │  │  │  ├─ FlatBuffersStructsTests.swift
   │  │  │  │  │  │  │  │  ├─ FlatBuffersTests.swift
   │  │  │  │  │  │  │  │  ├─ FlatBuffersUnionTests.swift
   │  │  │  │  │  │  │  │  ├─ FlatBuffersVectorsTests.swift
   │  │  │  │  │  │  │  │  ├─ FlatbuffersDoubleTests.swift
   │  │  │  │  │  │  │  │  ├─ FlatbuffersMoreDefaults.swift
   │  │  │  │  │  │  │  │  ├─ MutatingBool_generated.swift
   │  │  │  │  │  │  │  │  ├─ XCTestManifests.swift
   │  │  │  │  │  │  │  │  ├─ monster_test.grpc.swift
   │  │  │  │  │  │  │  │  ├─ monster_test_generated.swift
   │  │  │  │  │  │  │  │  ├─ more_defaults_generated.swift
   │  │  │  │  │  │  │  │  ├─ optional_scalars_generated.swift
   │  │  │  │  │  │  │  │  └─ union_vector_generated.swift
   │  │  │  │  │  │  │  └─ LinuxMain.swift
   │  │  │  │  │  │  └─ monsterdata_test.mon
   │  │  │  │  │  ├─ FlatBuffers.Test
   │  │  │  │  │  │  ├─ .gitignore
   │  │  │  │  │  │  ├─ Assert.cs
   │  │  │  │  │  │  ├─ ByteBufferTests.cs
   │  │  │  │  │  │  ├─ FlatBufferBuilderTests.cs
   │  │  │  │  │  │  ├─ FlatBuffers.Core.Test.csproj
   │  │  │  │  │  │  ├─ FlatBuffers.Test.csproj
   │  │  │  │  │  │  ├─ FlatBuffersExampleTests.cs
   │  │  │  │  │  │  ├─ FlatBuffersFuzzTests.cs
   │  │  │  │  │  │  ├─ FlatBuffersTestClassAttribute.cs
   │  │  │  │  │  │  ├─ FlatBuffersTestMethodAttribute.cs
   │  │  │  │  │  │  ├─ FuzzTestData.cs
   │  │  │  │  │  │  ├─ Lcg.cs
   │  │  │  │  │  │  ├─ NetTest.bat
   │  │  │  │  │  │  ├─ NetTest.sh
   │  │  │  │  │  │  ├─ Program.cs
   │  │  │  │  │  │  ├─ Properties
   │  │  │  │  │  │  │  └─ AssemblyInfo.cs
   │  │  │  │  │  │  ├─ README.md
   │  │  │  │  │  │  ├─ TestTable.cs
   │  │  │  │  │  │  ├─ clean.sh
   │  │  │  │  │  │  └─ packages.config
   │  │  │  │  │  ├─ GoTest.sh
   │  │  │  │  │  ├─ JavaScriptFlexBuffersTest.js
   │  │  │  │  │  ├─ JavaScriptTest.js
   │  │  │  │  │  ├─ JavaScriptUnionVectorTest.js
   │  │  │  │  │  ├─ JavaTest.bat
   │  │  │  │  │  ├─ JavaTest.java
   │  │  │  │  │  ├─ JavaTest.sh
   │  │  │  │  │  ├─ KotlinTest.kt
   │  │  │  │  │  ├─ KotlinTest.sh
   │  │  │  │  │  ├─ LuaTest.bat
   │  │  │  │  │  ├─ LuaTest.sh
   │  │  │  │  │  ├─ MyGame
   │  │  │  │  │  │  ├─ Example
   │  │  │  │  │  │  │  ├─ Ability.cs
   │  │  │  │  │  │  │  ├─ Ability.go
   │  │  │  │  │  │  │  ├─ Ability.java
   │  │  │  │  │  │  │  ├─ Ability.kt
   │  │  │  │  │  │  │  ├─ Ability.lua
   │  │  │  │  │  │  │  ├─ Ability.php
   │  │  │  │  │  │  │  ├─ Ability.py
   │  │  │  │  │  │  │  ├─ Any.cs
   │  │  │  │  │  │  │  ├─ Any.go
   │  │  │  │  │  │  │  ├─ Any.java
   │  │  │  │  │  │  │  ├─ Any.kt
   │  │  │  │  │  │  │  ├─ Any.lua
   │  │  │  │  │  │  │  ├─ Any.php
   │  │  │  │  │  │  │  ├─ Any.py
   │  │  │  │  │  │  │  ├─ AnyAmbiguousAliases.cs
   │  │  │  │  │  │  │  ├─ AnyAmbiguousAliases.go
   │  │  │  │  │  │  │  ├─ AnyAmbiguousAliases.java
   │  │  │  │  │  │  │  ├─ AnyAmbiguousAliases.kt
   │  │  │  │  │  │  │  ├─ AnyAmbiguousAliases.lua
   │  │  │  │  │  │  │  ├─ AnyAmbiguousAliases.php
   │  │  │  │  │  │  │  ├─ AnyAmbiguousAliases.py
   │  │  │  │  │  │  │  ├─ AnyUniqueAliases.cs
   │  │  │  │  │  │  │  ├─ AnyUniqueAliases.go
   │  │  │  │  │  │  │  ├─ AnyUniqueAliases.java
   │  │  │  │  │  │  │  ├─ AnyUniqueAliases.kt
   │  │  │  │  │  │  │  ├─ AnyUniqueAliases.lua
   │  │  │  │  │  │  │  ├─ AnyUniqueAliases.php
   │  │  │  │  │  │  │  ├─ AnyUniqueAliases.py
   │  │  │  │  │  │  │  ├─ ArrayStruct.cs
   │  │  │  │  │  │  │  ├─ ArrayStruct.java
   │  │  │  │  │  │  │  ├─ ArrayStruct.py
   │  │  │  │  │  │  │  ├─ ArrayTable.cs
   │  │  │  │  │  │  │  ├─ ArrayTable.java
   │  │  │  │  │  │  │  ├─ ArrayTable.py
   │  │  │  │  │  │  │  ├─ Color.cs
   │  │  │  │  │  │  │  ├─ Color.go
   │  │  │  │  │  │  │  ├─ Color.java
   │  │  │  │  │  │  │  ├─ Color.kt
   │  │  │  │  │  │  │  ├─ Color.lua
   │  │  │  │  │  │  │  ├─ Color.php
   │  │  │  │  │  │  │  ├─ Color.py
   │  │  │  │  │  │  │  ├─ Monster.cs
   │  │  │  │  │  │  │  ├─ Monster.go
   │  │  │  │  │  │  │  ├─ Monster.java
   │  │  │  │  │  │  │  ├─ Monster.kt
   │  │  │  │  │  │  │  ├─ Monster.lua
   │  │  │  │  │  │  │  ├─ Monster.php
   │  │  │  │  │  │  │  ├─ Monster.py
   │  │  │  │  │  │  │  ├─ MonsterStorageGrpc.java
   │  │  │  │  │  │  │  ├─ MonsterStorage_grpc.go
   │  │  │  │  │  │  │  ├─ NestedStruct.cs
   │  │  │  │  │  │  │  ├─ NestedStruct.java
   │  │  │  │  │  │  │  ├─ NestedStruct.py
   │  │  │  │  │  │  │  ├─ Race.cs
   │  │  │  │  │  │  │  ├─ Race.go
   │  │  │  │  │  │  │  ├─ Race.java
   │  │  │  │  │  │  │  ├─ Race.kt
   │  │  │  │  │  │  │  ├─ Race.lua
   │  │  │  │  │  │  │  ├─ Race.php
   │  │  │  │  │  │  │  ├─ Race.py
   │  │  │  │  │  │  │  ├─ Referrable.cs
   │  │  │  │  │  │  │  ├─ Referrable.go
   │  │  │  │  │  │  │  ├─ Referrable.java
   │  │  │  │  │  │  │  ├─ Referrable.kt
   │  │  │  │  │  │  │  ├─ Referrable.lua
   │  │  │  │  │  │  │  ├─ Referrable.php
   │  │  │  │  │  │  │  ├─ Referrable.py
   │  │  │  │  │  │  │  ├─ Stat.cs
   │  │  │  │  │  │  │  ├─ Stat.go
   │  │  │  │  │  │  │  ├─ Stat.java
   │  │  │  │  │  │  │  ├─ Stat.kt
   │  │  │  │  │  │  │  ├─ Stat.lua
   │  │  │  │  │  │  │  ├─ Stat.php
   │  │  │  │  │  │  │  ├─ Stat.py
   │  │  │  │  │  │  │  ├─ StructOfStructs.cs
   │  │  │  │  │  │  │  ├─ StructOfStructs.go
   │  │  │  │  │  │  │  ├─ StructOfStructs.java
   │  │  │  │  │  │  │  ├─ StructOfStructs.kt
   │  │  │  │  │  │  │  ├─ StructOfStructs.lua
   │  │  │  │  │  │  │  ├─ StructOfStructs.php
   │  │  │  │  │  │  │  ├─ StructOfStructs.py
   │  │  │  │  │  │  │  ├─ Test.cs
   │  │  │  │  │  │  │  ├─ Test.go
   │  │  │  │  │  │  │  ├─ Test.java
   │  │  │  │  │  │  │  ├─ Test.kt
   │  │  │  │  │  │  │  ├─ Test.lua
   │  │  │  │  │  │  │  ├─ Test.php
   │  │  │  │  │  │  │  ├─ Test.py
   │  │  │  │  │  │  │  ├─ TestEnum.cs
   │  │  │  │  │  │  │  ├─ TestEnum.java
   │  │  │  │  │  │  │  ├─ TestEnum.kt
   │  │  │  │  │  │  │  ├─ TestEnum.py
   │  │  │  │  │  │  │  ├─ TestSimpleTableWithEnum.cs
   │  │  │  │  │  │  │  ├─ TestSimpleTableWithEnum.go
   │  │  │  │  │  │  │  ├─ TestSimpleTableWithEnum.java
   │  │  │  │  │  │  │  ├─ TestSimpleTableWithEnum.kt
   │  │  │  │  │  │  │  ├─ TestSimpleTableWithEnum.lua
   │  │  │  │  │  │  │  ├─ TestSimpleTableWithEnum.php
   │  │  │  │  │  │  │  ├─ TestSimpleTableWithEnum.py
   │  │  │  │  │  │  │  ├─ TypeAliases.cs
   │  │  │  │  │  │  │  ├─ TypeAliases.go
   │  │  │  │  │  │  │  ├─ TypeAliases.java
   │  │  │  │  │  │  │  ├─ TypeAliases.kt
   │  │  │  │  │  │  │  ├─ TypeAliases.lua
   │  │  │  │  │  │  │  ├─ TypeAliases.php
   │  │  │  │  │  │  │  ├─ TypeAliases.py
   │  │  │  │  │  │  │  ├─ Vec3.cs
   │  │  │  │  │  │  │  ├─ Vec3.go
   │  │  │  │  │  │  │  ├─ Vec3.java
   │  │  │  │  │  │  │  ├─ Vec3.kt
   │  │  │  │  │  │  │  ├─ Vec3.lua
   │  │  │  │  │  │  │  ├─ Vec3.php
   │  │  │  │  │  │  │  ├─ Vec3.py
   │  │  │  │  │  │  │  ├─ __init__.py
   │  │  │  │  │  │  │  └─ monster_test_grpc_fb.py
   │  │  │  │  │  │  ├─ Example2
   │  │  │  │  │  │  │  ├─ Monster.cs
   │  │  │  │  │  │  │  ├─ Monster.go
   │  │  │  │  │  │  │  ├─ Monster.java
   │  │  │  │  │  │  │  ├─ Monster.kt
   │  │  │  │  │  │  │  ├─ Monster.lua
   │  │  │  │  │  │  │  ├─ Monster.php
   │  │  │  │  │  │  │  ├─ Monster.py
   │  │  │  │  │  │  │  └─ __init__.py
   │  │  │  │  │  │  ├─ InParentNamespace.cs
   │  │  │  │  │  │  ├─ InParentNamespace.go
   │  │  │  │  │  │  ├─ InParentNamespace.java
   │  │  │  │  │  │  ├─ InParentNamespace.kt
   │  │  │  │  │  │  ├─ InParentNamespace.lua
   │  │  │  │  │  │  ├─ InParentNamespace.php
   │  │  │  │  │  │  ├─ InParentNamespace.py
   │  │  │  │  │  │  ├─ MonsterExtra.cs
   │  │  │  │  │  │  ├─ MonsterExtra.java
   │  │  │  │  │  │  ├─ MonsterExtra.kt
   │  │  │  │  │  │  ├─ MonsterExtra.py
   │  │  │  │  │  │  └─ __init__.py
   │  │  │  │  │  ├─ PythonTest.sh
   │  │  │  │  │  ├─ RustTest.bat
   │  │  │  │  │  ├─ RustTest.sh
   │  │  │  │  │  ├─ TestAll.sh
   │  │  │  │  │  ├─ TypeScriptTest.bat
   │  │  │  │  │  ├─ TypeScriptTest.sh
   │  │  │  │  │  ├─ arrays_test.bfbs
   │  │  │  │  │  ├─ arrays_test.fbs
   │  │  │  │  │  ├─ arrays_test.golden
   │  │  │  │  │  ├─ arrays_test.schema.json
   │  │  │  │  │  ├─ arrays_test_generated.h
   │  │  │  │  │  ├─ arrays_test_generated.rs
   │  │  │  │  │  ├─ cpp17
   │  │  │  │  │  │  ├─ generated_cpp17
   │  │  │  │  │  │  │  ├─ monster_test_generated.h
   │  │  │  │  │  │  │  ├─ optional_scalars2_generated.h
   │  │  │  │  │  │  │  └─ optional_scalars_generated.h
   │  │  │  │  │  │  ├─ stringify_util.h
   │  │  │  │  │  │  └─ test_cpp17.cpp
   │  │  │  │  │  ├─ docker
   │  │  │  │  │  │  ├─ Dockerfile.testing.build_flatc_debian_stretch
   │  │  │  │  │  │  ├─ Dockerfile.testing.cpp.debian_buster
   │  │  │  │  │  │  ├─ TODO.Dockerfile.testing.php.hhvm_2019_01_16
   │  │  │  │  │  │  ├─ TODO.Dockerfile.testing.python.cpython_with_conda
   │  │  │  │  │  │  ├─ TODO.Dockerfile.testing.python.cpython_with_numpy
   │  │  │  │  │  │  ├─ TODO.Dockerfile.testing.python.pypy_6_0_0_py2
   │  │  │  │  │  │  ├─ TODO.Dockerfile.testing.python.pypy_6_0_0_py3
   │  │  │  │  │  │  ├─ build_flatc.run.sh
   │  │  │  │  │  │  ├─ cpp_test.run.sh
   │  │  │  │  │  │  └─ languages
   │  │  │  │  │  │     ├─ Dockerfile.testing.csharp.mono_5_18
   │  │  │  │  │  │     ├─ Dockerfile.testing.golang.1_11
   │  │  │  │  │  │     ├─ Dockerfile.testing.java.openjdk_10_0_2
   │  │  │  │  │  │     ├─ Dockerfile.testing.java.openjdk_11_0_1
   │  │  │  │  │  │     ├─ Dockerfile.testing.node.12_20_1
   │  │  │  │  │  │     ├─ Dockerfile.testing.node.14_15_4
   │  │  │  │  │  │     ├─ Dockerfile.testing.php.zend_7_3
   │  │  │  │  │  │     ├─ Dockerfile.testing.python.cpython_2_7_15
   │  │  │  │  │  │     ├─ Dockerfile.testing.python.cpython_3_7_1
   │  │  │  │  │  │     ├─ Dockerfile.testing.python.numpy.cpython_2_7_15
   │  │  │  │  │  │     ├─ Dockerfile.testing.python.numpy.cpython_3_7_1
   │  │  │  │  │  │     ├─ Dockerfile.testing.rust.1_51_0
   │  │  │  │  │  │     ├─ Dockerfile.testing.rust.big_endian.1_51_0
   │  │  │  │  │  │     ├─ Dockerfile.testing.rust.nightly
   │  │  │  │  │  │     └─ Dockerfile.testing.swift_5_2
   │  │  │  │  │  ├─ evolution_test
   │  │  │  │  │  │  ├─ evolution_v1.fbs
   │  │  │  │  │  │  ├─ evolution_v1.json
   │  │  │  │  │  │  ├─ evolution_v1_generated.h
   │  │  │  │  │  │  ├─ evolution_v2.fbs
   │  │  │  │  │  │  ├─ evolution_v2.json
   │  │  │  │  │  │  └─ evolution_v2_generated.h
   │  │  │  │  │  ├─ fuzzer
   │  │  │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  │  │  ├─ flatbuffers_monster_fuzzer.cc
   │  │  │  │  │  │  ├─ flatbuffers_parser_fuzzer.cc
   │  │  │  │  │  │  ├─ flatbuffers_scalar_fuzzer.cc
   │  │  │  │  │  │  ├─ flatbuffers_verifier_fuzzer.cc
   │  │  │  │  │  │  ├─ fuzzer_assert.h
   │  │  │  │  │  │  ├─ monster_debug.cpp
   │  │  │  │  │  │  ├─ monster_fuzzer.dict
   │  │  │  │  │  │  ├─ parser_fuzzer.dict
   │  │  │  │  │  │  ├─ readme.md
   │  │  │  │  │  │  ├─ scalar_debug.cpp
   │  │  │  │  │  │  ├─ scalar_fuzzer.dict
   │  │  │  │  │  │  └─ test_init.h
   │  │  │  │  │  ├─ generate_code.bat
   │  │  │  │  │  ├─ generate_code.sh
   │  │  │  │  │  ├─ go_test.go
   │  │  │  │  │  ├─ gold_flexbuffer_example.bin
   │  │  │  │  │  ├─ include_test
   │  │  │  │  │  │  ├─ include_test1.fbs
   │  │  │  │  │  │  ├─ include_test1_generated.rs
   │  │  │  │  │  │  └─ sub
   │  │  │  │  │  │     ├─ include_test2.fbs
   │  │  │  │  │  │     └─ include_test2_generated.rs
   │  │  │  │  │  ├─ javatest.bin
   │  │  │  │  │  ├─ lobstertest.lobster
   │  │  │  │  │  ├─ luatest.lua
   │  │  │  │  │  ├─ monster_extra.fbs
   │  │  │  │  │  ├─ monster_extra_generated.h
   │  │  │  │  │  ├─ monster_extra_my_game_generated.dart
   │  │  │  │  │  ├─ monster_test.bfbs
   │  │  │  │  │  ├─ monster_test.fbs
   │  │  │  │  │  ├─ monster_test.grpc.fb.cc
   │  │  │  │  │  ├─ monster_test.grpc.fb.h
   │  │  │  │  │  ├─ monster_test.schema.json
   │  │  │  │  │  ├─ monster_test_bfbs_generated.h
   │  │  │  │  │  ├─ monster_test_generated.h
   │  │  │  │  │  ├─ monster_test_generated.lobster
   │  │  │  │  │  ├─ monster_test_generated.rs
   │  │  │  │  │  ├─ monster_test_grpc.d.ts
   │  │  │  │  │  ├─ monster_test_grpc.js
   │  │  │  │  │  ├─ monster_test_my_game.example2_generated.dart
   │  │  │  │  │  ├─ monster_test_my_game.example_generated.dart
   │  │  │  │  │  ├─ monster_test_my_game_generated.dart
   │  │  │  │  │  ├─ monsterdata_extra.json
   │  │  │  │  │  ├─ monsterdata_go_wire.mon.sp
   │  │  │  │  │  ├─ monsterdata_python_wire.mon
   │  │  │  │  │  ├─ monsterdata_test.golden
   │  │  │  │  │  ├─ monsterdata_test.json
   │  │  │  │  │  ├─ monsterdata_test.mon
   │  │  │  │  │  ├─ more_defaults.fbs
   │  │  │  │  │  ├─ more_defaults_generated.rs
   │  │  │  │  │  ├─ my-game
   │  │  │  │  │  │  ├─ example
   │  │  │  │  │  │  │  ├─ ability.js
   │  │  │  │  │  │  │  ├─ ability.ts
   │  │  │  │  │  │  │  ├─ any-ambiguous-aliases.js
   │  │  │  │  │  │  │  ├─ any-ambiguous-aliases.ts
   │  │  │  │  │  │  │  ├─ any-unique-aliases.js
   │  │  │  │  │  │  │  ├─ any-unique-aliases.ts
   │  │  │  │  │  │  │  ├─ any.js
   │  │  │  │  │  │  │  ├─ any.ts
   │  │  │  │  │  │  │  ├─ color.js
   │  │  │  │  │  │  │  ├─ color.ts
   │  │  │  │  │  │  │  ├─ monster.js
   │  │  │  │  │  │  │  ├─ monster.ts
   │  │  │  │  │  │  │  ├─ race.js
   │  │  │  │  │  │  │  ├─ race.ts
   │  │  │  │  │  │  │  ├─ referrable.js
   │  │  │  │  │  │  │  ├─ referrable.ts
   │  │  │  │  │  │  │  ├─ stat.js
   │  │  │  │  │  │  │  ├─ stat.ts
   │  │  │  │  │  │  │  ├─ struct-of-structs.js
   │  │  │  │  │  │  │  ├─ struct-of-structs.ts
   │  │  │  │  │  │  │  ├─ test-simple-table-with-enum.js
   │  │  │  │  │  │  │  ├─ test-simple-table-with-enum.ts
   │  │  │  │  │  │  │  ├─ test.js
   │  │  │  │  │  │  │  ├─ test.ts
   │  │  │  │  │  │  │  ├─ type-aliases.js
   │  │  │  │  │  │  │  ├─ type-aliases.ts
   │  │  │  │  │  │  │  ├─ vec3.js
   │  │  │  │  │  │  │  └─ vec3.ts
   │  │  │  │  │  │  ├─ example2
   │  │  │  │  │  │  │  ├─ monster.js
   │  │  │  │  │  │  │  └─ monster.ts
   │  │  │  │  │  │  ├─ in-parent-namespace.js
   │  │  │  │  │  │  └─ in-parent-namespace.ts
   │  │  │  │  │  ├─ namespace_test
   │  │  │  │  │  │  ├─ NamespaceA
   │  │  │  │  │  │  │  ├─ NamespaceB
   │  │  │  │  │  │  │  │  ├─ EnumInNestedNS.cs
   │  │  │  │  │  │  │  │  ├─ EnumInNestedNS.go
   │  │  │  │  │  │  │  │  ├─ EnumInNestedNS.java
   │  │  │  │  │  │  │  │  ├─ EnumInNestedNS.kt
   │  │  │  │  │  │  │  │  ├─ EnumInNestedNS.lua
   │  │  │  │  │  │  │  │  ├─ EnumInNestedNS.php
   │  │  │  │  │  │  │  │  ├─ EnumInNestedNS.py
   │  │  │  │  │  │  │  │  ├─ StructInNestedNS.cs
   │  │  │  │  │  │  │  │  ├─ StructInNestedNS.go
   │  │  │  │  │  │  │  │  ├─ StructInNestedNS.java
   │  │  │  │  │  │  │  │  ├─ StructInNestedNS.kt
   │  │  │  │  │  │  │  │  ├─ StructInNestedNS.lua
   │  │  │  │  │  │  │  │  ├─ StructInNestedNS.php
   │  │  │  │  │  │  │  │  ├─ StructInNestedNS.py
   │  │  │  │  │  │  │  │  ├─ TableInNestedNS.cs
   │  │  │  │  │  │  │  │  ├─ TableInNestedNS.go
   │  │  │  │  │  │  │  │  ├─ TableInNestedNS.java
   │  │  │  │  │  │  │  │  ├─ TableInNestedNS.kt
   │  │  │  │  │  │  │  │  ├─ TableInNestedNS.lua
   │  │  │  │  │  │  │  │  ├─ TableInNestedNS.php
   │  │  │  │  │  │  │  │  ├─ TableInNestedNS.py
   │  │  │  │  │  │  │  │  ├─ UnionInNestedNS.cs
   │  │  │  │  │  │  │  │  ├─ UnionInNestedNS.go
   │  │  │  │  │  │  │  │  ├─ UnionInNestedNS.java
   │  │  │  │  │  │  │  │  ├─ UnionInNestedNS.kt
   │  │  │  │  │  │  │  │  ├─ UnionInNestedNS.lua
   │  │  │  │  │  │  │  │  ├─ UnionInNestedNS.php
   │  │  │  │  │  │  │  │  ├─ UnionInNestedNS.py
   │  │  │  │  │  │  │  │  └─ __init__.py
   │  │  │  │  │  │  │  ├─ SecondTableInA.cs
   │  │  │  │  │  │  │  ├─ SecondTableInA.go
   │  │  │  │  │  │  │  ├─ SecondTableInA.java
   │  │  │  │  │  │  │  ├─ SecondTableInA.kt
   │  │  │  │  │  │  │  ├─ SecondTableInA.lua
   │  │  │  │  │  │  │  ├─ SecondTableInA.php
   │  │  │  │  │  │  │  ├─ SecondTableInA.py
   │  │  │  │  │  │  │  ├─ TableInC.cs
   │  │  │  │  │  │  │  ├─ TableInC.go
   │  │  │  │  │  │  │  ├─ TableInC.php
   │  │  │  │  │  │  │  ├─ TableInC.py
   │  │  │  │  │  │  │  ├─ TableInFirstNS.cs
   │  │  │  │  │  │  │  ├─ TableInFirstNS.go
   │  │  │  │  │  │  │  ├─ TableInFirstNS.java
   │  │  │  │  │  │  │  ├─ TableInFirstNS.kt
   │  │  │  │  │  │  │  ├─ TableInFirstNS.lua
   │  │  │  │  │  │  │  ├─ TableInFirstNS.php
   │  │  │  │  │  │  │  ├─ TableInFirstNS.py
   │  │  │  │  │  │  │  └─ __init__.py
   │  │  │  │  │  │  ├─ NamespaceC
   │  │  │  │  │  │  │  ├─ TableInC.cs
   │  │  │  │  │  │  │  ├─ TableInC.go
   │  │  │  │  │  │  │  ├─ TableInC.java
   │  │  │  │  │  │  │  ├─ TableInC.kt
   │  │  │  │  │  │  │  ├─ TableInC.lua
   │  │  │  │  │  │  │  ├─ TableInC.php
   │  │  │  │  │  │  │  ├─ TableInC.py
   │  │  │  │  │  │  │  └─ __init__.py
   │  │  │  │  │  │  ├─ namespace-a
   │  │  │  │  │  │  │  ├─ namespace-b
   │  │  │  │  │  │  │  │  ├─ enum-in-nested-n-s.js
   │  │  │  │  │  │  │  │  ├─ enum-in-nested-n-s.ts
   │  │  │  │  │  │  │  │  ├─ struct-in-nested-n-s.js
   │  │  │  │  │  │  │  │  ├─ struct-in-nested-n-s.ts
   │  │  │  │  │  │  │  │  ├─ table-in-nested-n-s.js
   │  │  │  │  │  │  │  │  ├─ table-in-nested-n-s.ts
   │  │  │  │  │  │  │  │  ├─ union-in-nested-n-s.js
   │  │  │  │  │  │  │  │  └─ union-in-nested-n-s.ts
   │  │  │  │  │  │  │  ├─ second-table-in-a.js
   │  │  │  │  │  │  │  ├─ second-table-in-a.ts
   │  │  │  │  │  │  │  ├─ table-in-first-n-s.js
   │  │  │  │  │  │  │  └─ table-in-first-n-s.ts
   │  │  │  │  │  │  ├─ namespace-c
   │  │  │  │  │  │  │  ├─ table-in-c.js
   │  │  │  │  │  │  │  └─ table-in-c.ts
   │  │  │  │  │  │  ├─ namespace_test1.fbs
   │  │  │  │  │  │  ├─ namespace_test1_generated.h
   │  │  │  │  │  │  ├─ namespace_test1_generated.lobster
   │  │  │  │  │  │  ├─ namespace_test1_generated.rs
   │  │  │  │  │  │  ├─ namespace_test1_namespace_a.namespace_b_generated.dart
   │  │  │  │  │  │  ├─ namespace_test2.fbs
   │  │  │  │  │  │  ├─ namespace_test2_generated.h
   │  │  │  │  │  │  ├─ namespace_test2_generated.lobster
   │  │  │  │  │  │  ├─ namespace_test2_generated.rs
   │  │  │  │  │  │  ├─ namespace_test2_namespace_a_generated.dart
   │  │  │  │  │  │  └─ namespace_test2_namespace_c_generated.dart
   │  │  │  │  │  ├─ native_type_test.fbs
   │  │  │  │  │  ├─ native_type_test_generated.h
   │  │  │  │  │  ├─ native_type_test_impl.cpp
   │  │  │  │  │  ├─ native_type_test_impl.h
   │  │  │  │  │  ├─ optional_scalars.fbs
   │  │  │  │  │  ├─ optional_scalars
   │  │  │  │  │  │  ├─ OptionalByte.cs
   │  │  │  │  │  │  ├─ OptionalByte.java
   │  │  │  │  │  │  ├─ OptionalByte.kt
   │  │  │  │  │  │  ├─ ScalarStuff.cs
   │  │  │  │  │  │  ├─ ScalarStuff.java
   │  │  │  │  │  │  ├─ ScalarStuff.kt
   │  │  │  │  │  │  ├─ optional-byte.js
   │  │  │  │  │  │  ├─ optional-byte.ts
   │  │  │  │  │  │  ├─ scalar-stuff.js
   │  │  │  │  │  │  └─ scalar-stuff.ts
   │  │  │  │  │  ├─ optional_scalars_generated.h
   │  │  │  │  │  ├─ optional_scalars_generated.lobster
   │  │  │  │  │  ├─ optional_scalars_generated.rs
   │  │  │  │  │  ├─ package.json
   │  │  │  │  │  ├─ phpTest.php
   │  │  │  │  │  ├─ phpUnionVectorTest.php
   │  │  │  │  │  ├─ phpUnionVectorTest.sh
   │  │  │  │  │  ├─ prototest
   │  │  │  │  │  │  ├─ imported.proto
   │  │  │  │  │  │  ├─ test.golden
   │  │  │  │  │  │  ├─ test.proto
   │  │  │  │  │  │  ├─ test_include.golden
   │  │  │  │  │  │  ├─ test_suffix.golden
   │  │  │  │  │  │  ├─ test_union.golden
   │  │  │  │  │  │  ├─ test_union_include.golden
   │  │  │  │  │  │  └─ test_union_suffix.golden
   │  │  │  │  │  ├─ py_flexbuffers_test.py
   │  │  │  │  │  ├─ py_test.py
   │  │  │  │  │  ├─ rust_usage_test
   │  │  │  │  │  │  ├─ Cargo.toml
   │  │  │  │  │  │  ├─ benches
   │  │  │  │  │  │  │  ├─ benchmarks.rs
   │  │  │  │  │  │  │  ├─ flatbuffers_benchmarks.rs
   │  │  │  │  │  │  │  └─ flexbuffers_benchmarks.rs
   │  │  │  │  │  │  ├─ outdir
   │  │  │  │  │  │  │  ├─ Cargo.toml
   │  │  │  │  │  │  │  ├─ build.rs
   │  │  │  │  │  │  │  └─ src
   │  │  │  │  │  │  │     └─ main.rs
   │  │  │  │  │  │  └─ tests
   │  │  │  │  │  │     ├─ arrays_test.rs
   │  │  │  │  │  │     ├─ flexbuffers_tests
   │  │  │  │  │  │     │  ├─ binary_format.rs
   │  │  │  │  │  │     │  ├─ interop.rs
   │  │  │  │  │  │     │  ├─ mod.rs
   │  │  │  │  │  │     │  ├─ other_api.rs
   │  │  │  │  │  │     │  ├─ qc_serious.rs
   │  │  │  │  │  │     │  └─ rwyw.rs
   │  │  │  │  │  │     ├─ integration_test.rs
   │  │  │  │  │  │     ├─ more_defaults_test.rs
   │  │  │  │  │  │     └─ optional_scalars_test.rs
   │  │  │  │  │  ├─ test.cpp
   │  │  │  │  │  ├─ test_assert.cpp
   │  │  │  │  │  ├─ test_assert.h
   │  │  │  │  │  ├─ test_builder.cpp
   │  │  │  │  │  ├─ test_builder.h
   │  │  │  │  │  ├─ tsconfig.json
   │  │  │  │  │  ├─ unicode_test.json
   │  │  │  │  │  ├─ unicode_test.mon
   │  │  │  │  │  └─ union_vector
   │  │  │  │  │     ├─ Attacker.cs
   │  │  │  │  │     ├─ Attacker.java
   │  │  │  │  │     ├─ Attacker.kt
   │  │  │  │  │     ├─ Attacker.php
   │  │  │  │  │     ├─ BookReader.cs
   │  │  │  │  │     ├─ BookReader.java
   │  │  │  │  │     ├─ BookReader.kt
   │  │  │  │  │     ├─ BookReader.php
   │  │  │  │  │     ├─ Character.cs
   │  │  │  │  │     ├─ Character.java
   │  │  │  │  │     ├─ Character.kt
   │  │  │  │  │     ├─ Character.php
   │  │  │  │  │     ├─ Movie.cs
   │  │  │  │  │     ├─ Movie.java
   │  │  │  │  │     ├─ Movie.kt
   │  │  │  │  │     ├─ Movie.php
   │  │  │  │  │     ├─ Rapunzel.cs
   │  │  │  │  │     ├─ Rapunzel.java
   │  │  │  │  │     ├─ Rapunzel.kt
   │  │  │  │  │     ├─ Rapunzel.php
   │  │  │  │  │     ├─ attacker.js
   │  │  │  │  │     ├─ attacker.ts
   │  │  │  │  │     ├─ book-reader.js
   │  │  │  │  │     ├─ book-reader.ts
   │  │  │  │  │     ├─ character.js
   │  │  │  │  │     ├─ character.ts
   │  │  │  │  │     ├─ movie.js
   │  │  │  │  │     ├─ movie.ts
   │  │  │  │  │     ├─ rapunzel.js
   │  │  │  │  │     ├─ rapunzel.ts
   │  │  │  │  │     ├─ union_vector.fbs
   │  │  │  │  │     ├─ union_vector.json
   │  │  │  │  │     └─ union_vector_generated.h
   │  │  │  │  ├─ ts
   │  │  │  │  │  ├─ builder.ts
   │  │  │  │  │  ├─ byte-buffer.ts
   │  │  │  │  │  ├─ constants.ts
   │  │  │  │  │  ├─ encoding.ts
   │  │  │  │  │  ├─ flatbuffers.ts
   │  │  │  │  │  ├─ flexbuffers.ts
   │  │  │  │  │  ├─ flexbuffers
   │  │  │  │  │  │  ├─ bit-width-util.ts
   │  │  │  │  │  │  ├─ bit-width.ts
   │  │  │  │  │  │  ├─ builder.ts
   │  │  │  │  │  │  ├─ flexbuffers-util.ts
   │  │  │  │  │  │  ├─ reference-util.ts
   │  │  │  │  │  │  ├─ reference.ts
   │  │  │  │  │  │  ├─ stack-value.ts
   │  │  │  │  │  │  ├─ value-type-util.ts
   │  │  │  │  │  │  └─ value-type.ts
   │  │  │  │  │  ├─ long.ts
   │  │  │  │  │  ├─ types.ts
   │  │  │  │  │  └─ utils.ts
   │  │  │  │  ├─ tsconfig.json
   │  │  │  │  └─ tsconfig.mjs.json
   │  │  │  ├─ gflags
   │  │  │  │  ├─ .gitattributes
   │  │  │  │  ├─ .gitignore
   │  │  │  │  ├─ .gitmodules
   │  │  │  │  ├─ .travis.yml
   │  │  │  │  ├─ AUTHORS.txt
   │  │  │  │  ├─ CMakeLists.txt
   │  │  │  │  ├─ COPYING.txt
   │  │  │  │  ├─ ChangeLog.txt
   │  │  │  │  ├─ INSTALL.md
   │  │  │  │  ├─ README.md
   │  │  │  │  ├─ WORKSPACE
   │  │  │  │  ├─ appveyor.yml
   │  │  │  │  ├─ bazel
   │  │  │  │  │  └─ gflags.bzl
   │  │  │  │  ├─ cmake
   │  │  │  │  │  ├─ README_runtime.txt
   │  │  │  │  │  ├─ config.cmake.in
   │  │  │  │  │  ├─ execute_test.cmake
   │  │  │  │  │  ├─ package.cmake.in
   │  │  │  │  │  ├─ package.pc.in
   │  │  │  │  │  ├─ utils.cmake
   │  │  │  │  │  └─ version.cmake.in
   │  │  │  │  ├─ doc
   │  │  │  │  │  ├─ .nojekyll
   │  │  │  │  │  ├─ designstyle.css
   │  │  │  │  │  └─ index.html
   │  │  │  │  ├─ gflags-config-install.cmake
   │  │  │  │  ├─ gflags-config-version.cmake
   │  │  │  │  ├─ gflags-config.cmake
   │  │  │  │  ├─ gflags-targets.cmake
   │  │  │  │  ├─ gflags.pc
   │  │  │  │  ├─ src
   │  │  │  │  │  ├─ config.h.in
   │  │  │  │  │  ├─ gflags.cc
   │  │  │  │  │  ├─ gflags.h.in
   │  │  │  │  │  ├─ gflags_completions.cc
   │  │  │  │  │  ├─ gflags_completions.h.in
   │  │  │  │  │  ├─ gflags_completions.sh
   │  │  │  │  │  ├─ gflags_declare.h.in
   │  │  │  │  │  ├─ gflags_ns.h.in
   │  │  │  │  │  ├─ gflags_reporting.cc
   │  │  │  │  │  ├─ mutex.h
   │  │  │  │  │  ├─ util.h
   │  │  │  │  │  ├─ windows_port.cc
   │  │  │  │  │  └─ windows_port.h
   │  │  │  │  └─ test
   │  │  │  │     ├─ CMakeLists.txt
   │  │  │  │     ├─ config
   │  │  │  │     │  ├─ CMakeLists.txt
   │  │  │  │     │  └─ main.cc
   │  │  │  │     ├─ flagfile.1
   │  │  │  │     ├─ flagfile.2
   │  │  │  │     ├─ flagfile.3
   │  │  │  │     ├─ gflags_build.py.in
   │  │  │  │     ├─ gflags_declare_flags.cc
   │  │  │  │     ├─ gflags_declare_test.cc
   │  │  │  │     ├─ gflags_strip_flags_test.cc
   │  │  │  │     ├─ gflags_strip_flags_test.cmake
   │  │  │  │     ├─ gflags_unittest.cc
   │  │  │  │     ├─ gflags_unittest_flagfile
   │  │  │  │     └─ nc
   │  │  │  │        ├─ CMakeLists.txt
   │  │  │  │        └─ gflags_nc.cc
   │  │  │  ├─ huawei_npu
   │  │  │  │  ├─ README.md
   │  │  │  │  └─ download_ddk.sh
   │  │  │  ├─ opencl
   │  │  │  │  └─ include
   │  │  │  │     └─ CL
   │  │  │  │        ├─ cl.h
   │  │  │  │        ├─ cl.hpp
   │  │  │  │        ├─ cl2.hpp
   │  │  │  │        ├─ cl_d3d10.h
   │  │  │  │        ├─ cl_d3d11.h
   │  │  │  │        ├─ cl_dx9_media_sharing.h
   │  │  │  │        ├─ cl_dx9_media_sharing_intel.h
   │  │  │  │        ├─ cl_egl.h
   │  │  │  │        ├─ cl_ext.h
   │  │  │  │        ├─ cl_ext_intel.h
   │  │  │  │        ├─ cl_gl.h
   │  │  │  │        ├─ cl_gl_ext.h
   │  │  │  │        ├─ cl_platform.h
   │  │  │  │        ├─ cl_va_api_media_sharing_intel.h
   │  │  │  │        ├─ cl_version.h
   │  │  │  │        └─ opencl.h
   │  │  │  ├─ stb
   │  │  │  │  ├─ stb_image.h
   │  │  │  │  ├─ stb_image_resize.h
   │  │  │  │  └─ stb_image_write.h
   │  │  │  └─ xbyak
   │  │  │     ├─ COPYRIGHT
   │  │  │     └─ xbyak
   │  │  │        ├─ xbyak.h
   │  │  │        ├─ xbyak_bin2hex.h
   │  │  │        ├─ xbyak_mnemonic.h
   │  │  │        └─ xbyak_util.h
   │  │  └─ tools
   │  │     ├─ caffe2onnx
   │  │     │  ├─ .gitignore
   │  │     │  ├─ caffe2onnx.py
   │  │     │  ├─ doc
   │  │     │  │  └─ onnx-version.md
   │  │     │  ├─ proto
   │  │     │  │  ├─ __init__.py
   │  │     │  │  ├─ caffe_upsample.proto
   │  │     │  │  └─ caffe_upsample_pb2.py
   │  │     │  └─ src
   │  │     │     ├─ OPs
   │  │     │     │  ├─ Add.py
   │  │     │     │  ├─ Axpy.py
   │  │     │     │  ├─ BatchNorm.py
   │  │     │     │  ├─ Clip.py
   │  │     │     │  ├─ Concat.py
   │  │     │     │  ├─ Conv.py
   │  │     │     │  ├─ ConvTranspose.py
   │  │     │     │  ├─ Crop.py
   │  │     │     │  ├─ DetectionOutput.py
   │  │     │     │  ├─ Dropout.py
   │  │     │     │  ├─ Eltwise.py
   │  │     │     │  ├─ Flatten.py
   │  │     │     │  ├─ Gemm.py
   │  │     │     │  ├─ InstanceNorm.py
   │  │     │     │  ├─ Interp.py
   │  │     │     │  ├─ LRN.py
   │  │     │     │  ├─ Log.py
   │  │     │     │  ├─ LpNormalization.py
   │  │     │     │  ├─ Min.py
   │  │     │     │  ├─ Mul.py
   │  │     │     │  ├─ PRelu.py
   │  │     │     │  ├─ Pooling.py
   │  │     │     │  ├─ Power.py
   │  │     │     │  ├─ PriroBox.py
   │  │     │     │  ├─ ReLU.py
   │  │     │     │  ├─ Reshape.py
   │  │     │     │  ├─ Resize.py
   │  │     │     │  ├─ Shuffle.py
   │  │     │     │  ├─ Sigmoid.py
   │  │     │     │  ├─ Slice.py
   │  │     │     │  ├─ Softmax.py
   │  │     │     │  ├─ Tanh.py
   │  │     │     │  ├─ Transpose.py
   │  │     │     │  ├─ UnPooling.py
   │  │     │     │  ├─ Upsample.py
   │  │     │     │  └─ __init__.py
   │  │     │     ├─ __init__.py
   │  │     │     ├─ args_parser.py
   │  │     │     ├─ c2oObject.py
   │  │     │     ├─ caffe2onnx.py
   │  │     │     ├─ load_save_model.py
   │  │     │     ├─ op_layer_info.py
   │  │     │     └─ utils.py
   │  │     ├─ clang-format
   │  │     │  ├─ README.md
   │  │     │  ├─ clang-format.sh
   │  │     │  ├─ install.sh
   │  │     │  ├─ xcode-clang-format.workflow.backup.workflow
   │  │     │  │  └─ Contents
   │  │     │  │     ├─ Info.plist
   │  │     │  │     ├─ QuickLook
   │  │     │  │     │  └─ Thumbnail.png
   │  │     │  │     └─ document.wflow
   │  │     │  └─ xcode-clang-format.workflow
   │  │     │     └─ Contents
   │  │     │        ├─ Info.plist
   │  │     │        ├─ QuickLook
   │  │     │        │  └─ Thumbnail.png
   │  │     │        └─ document.wflow
   │  │     ├─ common
   │  │     │  ├─ file_reader.cc
   │  │     │  └─ file_reader.h
   │  │     ├─ convert2tnn
   │  │     │  ├─ .gitignore
   │  │     │  ├─ build.sh
   │  │     │  ├─ caffe_converter
   │  │     │  │  ├─ __init__.py
   │  │     │  │  └─ caffe2tnn.py
   │  │     │  ├─ converter.py
   │  │     │  ├─ onnx_converter
   │  │     │  │  ├─ __init__.py
   │  │     │  │  └─ onnx2tnn.py
   │  │     │  ├─ requirements.txt
   │  │     │  ├─ tf_converter
   │  │     │  │  ├─ __init__.py
   │  │     │  │  └─ tf2tnn.py
   │  │     │  ├─ tflite_converter
   │  │     │  │  ├─ __init__.py
   │  │     │  │  └─ tflite2tnn.py
   │  │     │  └─ utils
   │  │     │     ├─ __init__.py
   │  │     │     ├─ align_model.py
   │  │     │     ├─ args_parser.py
   │  │     │     ├─ checker.py
   │  │     │     ├─ cmd.py
   │  │     │     ├─ convert_name.py
   │  │     │     ├─ data.py
   │  │     │     ├─ differ.py
   │  │     │     ├─ fix_tnn_output.py
   │  │     │     ├─ parse_path.py
   │  │     │     ├─ return_code.py
   │  │     │     ├─ run_onnx_model.py
   │  │     │     └─ run_src_model.py
   │  │     ├─ converter
   │  │     │  ├─ CMakeLists.txt
   │  │     │  └─ source
   │  │     │     ├─ onnx
   │  │     │     │  ├─ onnx-proto
   │  │     │     │  │  ├─ onnx.proto
   │  │     │     │  │  └─ onnx.proto3
   │  │     │     │  ├─ onnx_base_converter.cc
   │  │     │     │  ├─ onnx_base_converter.h
   │  │     │     │  ├─ onnx_batchnorm_converter.cc
   │  │     │     │  ├─ onnx_binary_converter.cc
   │  │     │     │  ├─ onnx_cast_converter.cc
   │  │     │     │  ├─ onnx_clip_converter.cc
   │  │     │     │  ├─ onnx_concate_converter.cc
   │  │     │     │  ├─ onnx_constant_converter.cc
   │  │     │     │  ├─ onnx_conv_converter.cc
   │  │     │     │  ├─ onnx_converter.cc
   │  │     │     │  ├─ onnx_converter.h
   │  │     │     │  ├─ onnx_gather_converter.cc
   │  │     │     │  ├─ onnx_gemm_converter.cc
   │  │     │     │  ├─ onnx_matmul_converter.cc
   │  │     │     │  ├─ onnx_pool_converter.cc
   │  │     │     │  ├─ onnx_pow_converter.cc
   │  │     │     │  ├─ onnx_proxy_graph.cc
   │  │     │     │  ├─ onnx_proxy_graph.h
   │  │     │     │  ├─ onnx_reduce_converter.cc
   │  │     │     │  ├─ onnx_reshape_converter.cc
   │  │     │     │  ├─ onnx_sigmoid_converter.cc
   │  │     │     │  ├─ onnx_slice_converter.cc
   │  │     │     │  ├─ onnx_softmax_converter.cc
   │  │     │     │  ├─ onnx_split_converter.cc
   │  │     │     │  ├─ onnx_squeeze_converter.cc
   │  │     │     │  ├─ onnx_transpose_converter.cc
   │  │     │     │  ├─ onnx_unary_converter.cc
   │  │     │     │  ├─ onnx_unsqueeze_converter.cc
   │  │     │     │  ├─ onnx_upsample_converter.cc
   │  │     │     │  ├─ onnx_utils.cc
   │  │     │     │  ├─ onnx_utils.h
   │  │     │     │  └─ quantized_operator
   │  │     │     │     ├─ onnx_int8_binary_converter.cc
   │  │     │     │     ├─ onnx_int8_conv_relu_converter.cc
   │  │     │     │     ├─ onnx_int8_dequantized_converter.cc
   │  │     │     │     ├─ onnx_int8_fc_converter.cc
   │  │     │     │     ├─ onnx_int8_quantized_converter.cc
   │  │     │     │     ├─ onnx_int8_relu_converter.cc
   │  │     │     │     ├─ onnx_int8_transpose_converter.cc
   │  │     │     │     └─ onnx_int8_unary_converter.cc
   │  │     │     ├─ optimizer
   │  │     │     │  ├─ tnn_constant_folding.cc
   │  │     │     │  ├─ tnn_eliminate_reformat_node_pass.cc
   │  │     │     │  ├─ tnn_eliminate_unuseful_node_pass.cc
   │  │     │     │  ├─ tnn_fuse_instance_normalization_pass.cc
   │  │     │     │  ├─ tnn_fuse_shuffle_channel_pass.cc
   │  │     │     │  ├─ tnn_optimize_pass.cc
   │  │     │     │  ├─ tnn_optimize_pass.h
   │  │     │     │  ├─ tnn_optimizer.cc
   │  │     │     │  ├─ tnn_optimizer.h
   │  │     │     │  ├─ tnn_reshape_const_folding_pass.cc
   │  │     │     │  ├─ tnn_separate_relu_and_relu6_pass.cc
   │  │     │     │  ├─ tnn_transform_dequantized_pass.cc
   │  │     │     │  └─ tnn_transform_reduce_mean_pass.cc
   │  │     │     ├─ runtime
   │  │     │     │  ├─ tnn_runtime.cc
   │  │     │     │  └─ tnn_runtime.h
   │  │     │     ├─ tflite
   │  │     │     │  ├─ tflite-schema
   │  │     │     │  │  ├─ schema.fbs
   │  │     │     │  │  └─ schema_generated.h
   │  │     │     │  ├─ tflite_binary_converter.cc
   │  │     │     │  ├─ tflite_concate_converter.cc
   │  │     │     │  ├─ tflite_conv2d_converter.cc
   │  │     │     │  ├─ tflite_converter.cc
   │  │     │     │  ├─ tflite_converter.h
   │  │     │     │  ├─ tflite_custom_converter.cc
   │  │     │     │  ├─ tflite_depthtospace_converter.cc
   │  │     │     │  ├─ tflite_elu_converter.cc
   │  │     │     │  ├─ tflite_fully_connected_converter.cc
   │  │     │     │  ├─ tflite_hardswish_converter.cc
   │  │     │     │  ├─ tflite_l2_normalization_conveter.cc
   │  │     │     │  ├─ tflite_op_converter.cc
   │  │     │     │  ├─ tflite_op_converter.h
   │  │     │     │  ├─ tflite_pack_converter.cc
   │  │     │     │  ├─ tflite_pad_converter.cc
   │  │     │     │  ├─ tflite_pool2d_converter.cc
   │  │     │     │  ├─ tflite_prelu_converter.cc
   │  │     │     │  ├─ tflite_reduce_converter.cc
   │  │     │     │  ├─ tflite_reshape_converter.cc
   │  │     │     │  ├─ tflite_resize_converter.cc
   │  │     │     │  ├─ tflite_softmax_converter.cc
   │  │     │     │  ├─ tflite_splitv_converter.cc
   │  │     │     │  ├─ tflite_square_converter.cc
   │  │     │     │  ├─ tflite_squeeze_converter.cc
   │  │     │     │  ├─ tflite_strided_slice_converter.cc
   │  │     │     │  ├─ tflite_transpose_conv_converter.cc
   │  │     │     │  ├─ tflite_transpose_converter.cc
   │  │     │     │  ├─ tflite_unary_converter.cc
   │  │     │     │  ├─ tflite_utils.cc
   │  │     │     │  └─ tflite_utils.h
   │  │     │     ├─ tnn_converter.cc
   │  │     │     └─ utils
   │  │     │        ├─ command.cc
   │  │     │        ├─ command.h
   │  │     │        ├─ flags.cc
   │  │     │        ├─ flags.h
   │  │     │        ├─ generate_model.cc
   │  │     │        ├─ generate_model.h
   │  │     │        ├─ model_config.cc
   │  │     │        └─ model_config.h
   │  │     ├─ hooks
   │  │     │  ├─ README.md
   │  │     │  └─ add_hooks.sh
   │  │     ├─ model_check
   │  │     │  ├─ CMakeLists.txt
   │  │     │  ├─ flags.cc
   │  │     │  ├─ flags.h
   │  │     │  ├─ main.cc
   │  │     │  ├─ model_checker.cc
   │  │     │  └─ model_checker.h
   │  │     ├─ onnx2tnn
   │  │     │  ├─ onnx-converter
   │  │     │  │  ├─ CMakeLists.txt
   │  │     │  │  ├─ __init__.py
   │  │     │  │  ├─ build.sh
   │  │     │  │  ├─ onnx2tnn.py
   │  │     │  │  ├─ onnx2tnn_convert.cc
   │  │     │  │  ├─ onnx_model_cheker.py
   │  │     │  │  ├─ onnx_optimizer
   │  │     │  │  │  ├─ __init__.py
   │  │     │  │  │  ├─ __main__.py
   │  │     │  │  │  └─ onnx_optimizer.py
   │  │     │  │  ├─ pybind11
   │  │     │  │  │  ├─ CMakeLists.txt
   │  │     │  │  │  ├─ CONTRIBUTING.md
   │  │     │  │  │  ├─ ISSUE_TEMPLATE.md
   │  │     │  │  │  ├─ LICENSE
   │  │     │  │  │  ├─ MANIFEST.in
   │  │     │  │  │  ├─ README.md
   │  │     │  │  │  ├─ docs
   │  │     │  │  │  │  ├─ Doxyfile
   │  │     │  │  │  │  ├─ _static
   │  │     │  │  │  │  │  └─ theme_overrides.css
   │  │     │  │  │  │  ├─ advanced
   │  │     │  │  │  │  │  ├─ cast
   │  │     │  │  │  │  │  │  ├─ chrono.rst
   │  │     │  │  │  │  │  │  ├─ custom.rst
   │  │     │  │  │  │  │  │  ├─ eigen.rst
   │  │     │  │  │  │  │  │  ├─ functional.rst
   │  │     │  │  │  │  │  │  ├─ index.rst
   │  │     │  │  │  │  │  │  ├─ overview.rst
   │  │     │  │  │  │  │  │  ├─ stl.rst
   │  │     │  │  │  │  │  │  └─ strings.rst
   │  │     │  │  │  │  │  ├─ classes.rst
   │  │     │  │  │  │  │  ├─ embedding.rst
   │  │     │  │  │  │  │  ├─ exceptions.rst
   │  │     │  │  │  │  │  ├─ functions.rst
   │  │     │  │  │  │  │  ├─ misc.rst
   │  │     │  │  │  │  │  ├─ pycpp
   │  │     │  │  │  │  │  │  ├─ index.rst
   │  │     │  │  │  │  │  │  ├─ numpy.rst
   │  │     │  │  │  │  │  │  ├─ object.rst
   │  │     │  │  │  │  │  │  └─ utilities.rst
   │  │     │  │  │  │  │  └─ smart_ptrs.rst
   │  │     │  │  │  │  ├─ basics.rst
   │  │     │  │  │  │  ├─ benchmark.py
   │  │     │  │  │  │  ├─ benchmark.rst
   │  │     │  │  │  │  ├─ changelog.rst
   │  │     │  │  │  │  ├─ classes.rst
   │  │     │  │  │  │  ├─ compiling.rst
   │  │     │  │  │  │  ├─ conf.py
   │  │     │  │  │  │  ├─ faq.rst
   │  │     │  │  │  │  ├─ index.rst
   │  │     │  │  │  │  ├─ intro.rst
   │  │     │  │  │  │  ├─ limitations.rst
   │  │     │  │  │  │  ├─ pybind11-logo.png
   │  │     │  │  │  │  ├─ pybind11_vs_boost_python1.png
   │  │     │  │  │  │  ├─ pybind11_vs_boost_python1.svg
   │  │     │  │  │  │  ├─ pybind11_vs_boost_python2.png
   │  │     │  │  │  │  ├─ pybind11_vs_boost_python2.svg
   │  │     │  │  │  │  ├─ reference.rst
   │  │     │  │  │  │  ├─ release.rst
   │  │     │  │  │  │  ├─ requirements.txt
   │  │     │  │  │  │  └─ upgrade.rst
   │  │     │  │  │  ├─ include
   │  │     │  │  │  │  └─ pybind11
   │  │     │  │  │  │     ├─ attr.h
   │  │     │  │  │  │     ├─ buffer_info.h
   │  │     │  │  │  │     ├─ cast.h
   │  │     │  │  │  │     ├─ chrono.h
   │  │     │  │  │  │     ├─ common.h
   │  │     │  │  │  │     ├─ complex.h
   │  │     │  │  │  │     ├─ detail
   │  │     │  │  │  │     │  ├─ class.h
   │  │     │  │  │  │     │  ├─ common.h
   │  │     │  │  │  │     │  ├─ descr.h
   │  │     │  │  │  │     │  ├─ init.h
   │  │     │  │  │  │     │  ├─ internals.h
   │  │     │  │  │  │     │  └─ typeid.h
   │  │     │  │  │  │     ├─ eigen.h
   │  │     │  │  │  │     ├─ embed.h
   │  │     │  │  │  │     ├─ eval.h
   │  │     │  │  │  │     ├─ functional.h
   │  │     │  │  │  │     ├─ iostream.h
   │  │     │  │  │  │     ├─ numpy.h
   │  │     │  │  │  │     ├─ operators.h
   │  │     │  │  │  │     ├─ options.h
   │  │     │  │  │  │     ├─ pybind11.h
   │  │     │  │  │  │     ├─ pytypes.h
   │  │     │  │  │  │     ├─ stl.h
   │  │     │  │  │  │     └─ stl_bind.h
   │  │     │  │  │  ├─ pybind11
   │  │     │  │  │  │  ├─ __init__.py
   │  │     │  │  │  │  ├─ __main__.py
   │  │     │  │  │  │  └─ _version.py
   │  │     │  │  │  ├─ setup.cfg
   │  │     │  │  │  ├─ setup.py
   │  │     │  │  │  ├─ tests
   │  │     │  │  │  │  ├─ CMakeLists.txt
   │  │     │  │  │  │  ├─ conftest.py
   │  │     │  │  │  │  ├─ constructor_stats.h
   │  │     │  │  │  │  ├─ cross_module_gil_utils.cc
   │  │     │  │  │  │  ├─ cross_module_gil_utils.cpp
   │  │     │  │  │  │  ├─ local_bindings.h
   │  │     │  │  │  │  ├─ object.h
   │  │     │  │  │  │  ├─ pybind11_cross_module_tests.cc
   │  │     │  │  │  │  ├─ pybind11_cross_module_tests.cpp
   │  │     │  │  │  │  ├─ pybind11_tests.cc
   │  │     │  │  │  │  ├─ pybind11_tests.cpp
   │  │     │  │  │  │  ├─ pybind11_tests.h
   │  │     │  │  │  │  ├─ pytest.ini
   │  │     │  │  │  │  ├─ test_async.cc
   │  │     │  │  │  │  ├─ test_async.cpp
   │  │     │  │  │  │  ├─ test_async.py
   │  │     │  │  │  │  ├─ test_buffers.cc
   │  │     │  │  │  │  ├─ test_buffers.cpp
   │  │     │  │  │  │  ├─ test_buffers.py
   │  │     │  │  │  │  ├─ test_builtin_casters.cc
   │  │     │  │  │  │  ├─ test_builtin_casters.cpp
   │  │     │  │  │  │  ├─ test_builtin_casters.py
   │  │     │  │  │  │  ├─ test_call_policies.cc
   │  │     │  │  │  │  ├─ test_call_policies.cpp
   │  │     │  │  │  │  ├─ test_call_policies.py
   │  │     │  │  │  │  ├─ test_callbacks.cc
   │  │     │  │  │  │  ├─ test_callbacks.cpp
   │  │     │  │  │  │  ├─ test_callbacks.py
   │  │     │  │  │  │  ├─ test_chrono.cc
   │  │     │  │  │  │  ├─ test_chrono.cpp
   │  │     │  │  │  │  ├─ test_chrono.py
   │  │     │  │  │  │  ├─ test_class.cc
   │  │     │  │  │  │  ├─ test_class.cpp
   │  │     │  │  │  │  ├─ test_class.py
   │  │     │  │  │  │  ├─ test_cmake_build
   │  │     │  │  │  │  │  ├─ CMakeLists.txt
   │  │     │  │  │  │  │  ├─ embed.cc
   │  │     │  │  │  │  │  ├─ embed.cpp
   │  │     │  │  │  │  │  ├─ installed_embed
   │  │     │  │  │  │  │  │  └─ CMakeLists.txt
   │  │     │  │  │  │  │  ├─ installed_function
   │  │     │  │  │  │  │  │  └─ CMakeLists.txt
   │  │     │  │  │  │  │  ├─ installed_target
   │  │     │  │  │  │  │  │  └─ CMakeLists.txt
   │  │     │  │  │  │  │  ├─ main.cc
   │  │     │  │  │  │  │  ├─ main.cpp
   │  │     │  │  │  │  │  ├─ subdirectory_embed
   │  │     │  │  │  │  │  │  └─ CMakeLists.txt
   │  │     │  │  │  │  │  ├─ subdirectory_function
   │  │     │  │  │  │  │  │  └─ CMakeLists.txt
   │  │     │  │  │  │  │  ├─ subdirectory_target
   │  │     │  │  │  │  │  │  └─ CMakeLists.txt
   │  │     │  │  │  │  │  └─ test.py
   │  │     │  │  │  │  ├─ test_constants_and_functions.cc
   │  │     │  │  │  │  ├─ test_constants_and_functions.cpp
   │  │     │  │  │  │  ├─ test_constants_and_functions.py
   │  │     │  │  │  │  ├─ test_copy_move.cc
   │  │     │  │  │  │  ├─ test_copy_move.cpp
   │  │     │  │  │  │  ├─ test_copy_move.py
   │  │     │  │  │  │  ├─ test_docstring_options.cc
   │  │     │  │  │  │  ├─ test_docstring_options.cpp
   │  │     │  │  │  │  ├─ test_docstring_options.py
   │  │     │  │  │  │  ├─ test_eigen.cc
   │  │     │  │  │  │  ├─ test_eigen.cpp
   │  │     │  │  │  │  ├─ test_eigen.py
   │  │     │  │  │  │  ├─ test_embed
   │  │     │  │  │  │  │  ├─ CMakeLists.txt
   │  │     │  │  │  │  │  ├─ catch.cc
   │  │     │  │  │  │  │  ├─ catch.cpp
   │  │     │  │  │  │  │  ├─ external_module.cc
   │  │     │  │  │  │  │  ├─ external_module.cpp
   │  │     │  │  │  │  │  ├─ test_interpreter.cc
   │  │     │  │  │  │  │  ├─ test_interpreter.cpp
   │  │     │  │  │  │  │  └─ test_interpreter.py
   │  │     │  │  │  │  ├─ test_enum.cc
   │  │     │  │  │  │  ├─ test_enum.cpp
   │  │     │  │  │  │  ├─ test_enum.py
   │  │     │  │  │  │  ├─ test_eval.cc
   │  │     │  │  │  │  ├─ test_eval.cpp
   │  │     │  │  │  │  ├─ test_eval.py
   │  │     │  │  │  │  ├─ test_eval_call.py
   │  │     │  │  │  │  ├─ test_exceptions.cc
   │  │     │  │  │  │  ├─ test_exceptions.cpp
   │  │     │  │  │  │  ├─ test_exceptions.py
   │  │     │  │  │  │  ├─ test_factory_constructors.cc
   │  │     │  │  │  │  ├─ test_factory_constructors.cpp
   │  │     │  │  │  │  ├─ test_factory_constructors.py
   │  │     │  │  │  │  ├─ test_gil_scoped.cc
   │  │     │  │  │  │  ├─ test_gil_scoped.cpp
   │  │     │  │  │  │  ├─ test_gil_scoped.py
   │  │     │  │  │  │  ├─ test_iostream.cc
   │  │     │  │  │  │  ├─ test_iostream.cpp
   │  │     │  │  │  │  ├─ test_iostream.py
   │  │     │  │  │  │  ├─ test_kwargs_and_defaults.cc
   │  │     │  │  │  │  ├─ test_kwargs_and_defaults.cpp
   │  │     │  │  │  │  ├─ test_kwargs_and_defaults.py
   │  │     │  │  │  │  ├─ test_local_bindings.cc
   │  │     │  │  │  │  ├─ test_local_bindings.cpp
   │  │     │  │  │  │  ├─ test_local_bindings.py
   │  │     │  │  │  │  ├─ test_methods_and_attributes.cc
   │  │     │  │  │  │  ├─ test_methods_and_attributes.cpp
   │  │     │  │  │  │  ├─ test_methods_and_attributes.py
   │  │     │  │  │  │  ├─ test_modules.cc
   │  │     │  │  │  │  ├─ test_modules.cpp
   │  │     │  │  │  │  ├─ test_modules.py
   │  │     │  │  │  │  ├─ test_multiple_inheritance.cc
   │  │     │  │  │  │  ├─ test_multiple_inheritance.cpp
   │  │     │  │  │  │  ├─ test_multiple_inheritance.py
   │  │     │  │  │  │  ├─ test_numpy_array.cc
   │  │     │  │  │  │  ├─ test_numpy_array.cpp
   │  │     │  │  │  │  ├─ test_numpy_array.py
   │  │     │  │  │  │  ├─ test_numpy_dtypes.cc
   │  │     │  │  │  │  ├─ test_numpy_dtypes.cpp
   │  │     │  │  │  │  ├─ test_numpy_dtypes.py
   │  │     │  │  │  │  ├─ test_numpy_vectorize.cc
   │  │     │  │  │  │  ├─ test_numpy_vectorize.cpp
   │  │     │  │  │  │  ├─ test_numpy_vectorize.py
   │  │     │  │  │  │  ├─ test_opaque_types.cc
   │  │     │  │  │  │  ├─ test_opaque_types.cpp
   │  │     │  │  │  │  ├─ test_opaque_types.py
   │  │     │  │  │  │  ├─ test_operator_overloading.cc
   │  │     │  │  │  │  ├─ test_operator_overloading.cpp
   │  │     │  │  │  │  ├─ test_operator_overloading.py
   │  │     │  │  │  │  ├─ test_pickling.cc
   │  │     │  │  │  │  ├─ test_pickling.cpp
   │  │     │  │  │  │  ├─ test_pickling.py
   │  │     │  │  │  │  ├─ test_pytypes.cc
   │  │     │  │  │  │  ├─ test_pytypes.cpp
   │  │     │  │  │  │  ├─ test_pytypes.py
   │  │     │  │  │  │  ├─ test_sequences_and_iterators.cc
   │  │     │  │  │  │  ├─ test_sequences_and_iterators.cpp
   │  │     │  │  │  │  ├─ test_sequences_and_iterators.py
   │  │     │  │  │  │  ├─ test_smart_ptr.cc
   │  │     │  │  │  │  ├─ test_smart_ptr.cpp
   │  │     │  │  │  │  ├─ test_smart_ptr.py
   │  │     │  │  │  │  ├─ test_stl.cc
   │  │     │  │  │  │  ├─ test_stl.cpp
   │  │     │  │  │  │  ├─ test_stl.py
   │  │     │  │  │  │  ├─ test_stl_binders.cc
   │  │     │  │  │  │  ├─ test_stl_binders.cpp
   │  │     │  │  │  │  ├─ test_stl_binders.py
   │  │     │  │  │  │  ├─ test_tagbased_polymorphic.cc
   │  │     │  │  │  │  ├─ test_tagbased_polymorphic.cpp
   │  │     │  │  │  │  ├─ test_tagbased_polymorphic.py
   │  │     │  │  │  │  ├─ test_union.cc
   │  │     │  │  │  │  ├─ test_union.cpp
   │  │     │  │  │  │  ├─ test_union.py
   │  │     │  │  │  │  ├─ test_virtual_functions.cc
   │  │     │  │  │  │  ├─ test_virtual_functions.cpp
   │  │     │  │  │  │  └─ test_virtual_functions.py
   │  │     │  │  │  └─ tools
   │  │     │  │  │     ├─ FindCatch.cmake
   │  │     │  │  │     ├─ FindEigen3.cmake
   │  │     │  │  │     ├─ FindPythonLibsNew.cmake
   │  │     │  │  │     ├─ check-style.sh
   │  │     │  │  │     ├─ libsize.py
   │  │     │  │  │     ├─ mkdoc.py
   │  │     │  │  │     ├─ pybind11Config.cmake.in
   │  │     │  │  │     └─ pybind11Tools.cmake
   │  │     │  │  ├─ script
   │  │     │  │  │  ├─ build_protoc.sh
   │  │     │  │  │  ├─ detect_dependency.py
   │  │     │  │  │  ├─ protobuf.cmake
   │  │     │  │  │  └─ setup.py
   │  │     │  │  └─ version.py
   │  │     │  ├─ onnx-coreml
   │  │     │  │  ├─ coreml2onnx.py
   │  │     │  │  ├─ coreml_fp6.py
   │  │     │  │  ├─ onnx2coreml.py
   │  │     │  │  ├─ onnx_net.py
   │  │     │  │  └─ 安装说明-CoreML.md
   │  │     │  ├─ onnx-tnn-operators.md
   │  │     │  └─ src
   │  │     │     ├─ core
   │  │     │     │  ├─ layer
   │  │     │     │  │  ├─ onnx_converter_ histogram.cc
   │  │     │     │  │  ├─ onnx_converter_abs.cc
   │  │     │     │  │  ├─ onnx_converter_acos.cc
   │  │     │     │  │  ├─ onnx_converter_adaptive_pool.cc
   │  │     │     │  │  ├─ onnx_converter_add.cc
   │  │     │     │  │  ├─ onnx_converter_arg_max_or_min.cc
   │  │     │     │  │  ├─ onnx_converter_asin.cc
   │  │     │     │  │  ├─ onnx_converter_atan.cc
   │  │     │     │  │  ├─ onnx_converter_batchnorm.cc
   │  │     │     │  │  ├─ onnx_converter_bitshift.cc
   │  │     │     │  │  ├─ onnx_converter_cast.cc
   │  │     │     │  │  ├─ onnx_converter_ceil.cc
   │  │     │     │  │  ├─ onnx_converter_clip.cc
   │  │     │     │  │  ├─ onnx_converter_concat.cc
   │  │     │     │  │  ├─ onnx_converter_const.cc
   │  │     │     │  │  ├─ onnx_converter_constantofshape.cc
   │  │     │     │  │  ├─ onnx_converter_convolution.cc
   │  │     │     │  │  ├─ onnx_converter_cos.cc
   │  │     │     │  │  ├─ onnx_converter_depthtospace.cc
   │  │     │     │  │  ├─ onnx_converter_detection_output.cc
   │  │     │     │  │  ├─ onnx_converter_div.cc
   │  │     │     │  │  ├─ onnx_converter_dropout.cc
   │  │     │     │  │  ├─ onnx_converter_einsum.cc
   │  │     │     │  │  ├─ onnx_converter_elu.cc
   │  │     │     │  │  ├─ onnx_converter_equal.cc
   │  │     │     │  │  ├─ onnx_converter_erf.cc
   │  │     │     │  │  ├─ onnx_converter_exp.cc
   │  │     │     │  │  ├─ onnx_converter_expand.cc
   │  │     │     │  │  ├─ onnx_converter_flatten.cc
   │  │     │     │  │  ├─ onnx_converter_floor.cc
   │  │     │     │  │  ├─ onnx_converter_gather.cc
   │  │     │     │  │  ├─ onnx_converter_gathernd.cc
   │  │     │     │  │  ├─ onnx_converter_gelu.cc
   │  │     │     │  │  ├─ onnx_converter_gemm.cc
   │  │     │     │  │  ├─ onnx_converter_gridsample.cc
   │  │     │     │  │  ├─ onnx_converter_group_norm.cc
   │  │     │     │  │  ├─ onnx_converter_hard_sigmoid.cc
   │  │     │     │  │  ├─ onnx_converter_hard_swish.cc
   │  │     │     │  │  ├─ onnx_converter_hdrguide.cc
   │  │     │     │  │  ├─ onnx_converter_instance_norm.cc
   │  │     │     │  │  ├─ onnx_converter_inverse.cc
   │  │     │     │  │  ├─ onnx_converter_layer_norm.cc
   │  │     │     │  │  ├─ onnx_converter_leakyrelu.cc
   │  │     │     │  │  ├─ onnx_converter_log.cc
   │  │     │     │  │  ├─ onnx_converter_logsigmoid.cc
   │  │     │     │  │  ├─ onnx_converter_lp_normalization.cc
   │  │     │     │  │  ├─ onnx_converter_lrn.cc
   │  │     │     │  │  ├─ onnx_converter_lstm.cc
   │  │     │     │  │  ├─ onnx_converter_matmul.cc
   │  │     │     │  │  ├─ onnx_converter_max.cc
   │  │     │     │  │  ├─ onnx_converter_min.cc
   │  │     │     │  │  ├─ onnx_converter_mul.cc
   │  │     │     │  │  ├─ onnx_converter_multidir_broadcast.cc
   │  │     │     │  │  ├─ onnx_converter_multidir_broadcast.h
   │  │     │     │  │  ├─ onnx_converter_neg.cc
   │  │     │     │  │  ├─ onnx_converter_nonzero.cc
   │  │     │     │  │  ├─ onnx_converter_normalize.cc
   │  │     │     │  │  ├─ onnx_converter_not.cc
   │  │     │     │  │  ├─ onnx_converter_onehot.cc
   │  │     │     │  │  ├─ onnx_converter_pad.cc
   │  │     │     │  │  ├─ onnx_converter_pixel_shuffle.cc
   │  │     │     │  │  ├─ onnx_converter_pool.cc
   │  │     │     │  │  ├─ onnx_converter_pow.cc
   │  │     │     │  │  ├─ onnx_converter_prelu.cc
   │  │     │     │  │  ├─ onnx_converter_prior_box.cc
   │  │     │     │  │  ├─ onnx_converter_range.cc
   │  │     │     │  │  ├─ onnx_converter_reciprocal.cc
   │  │     │     │  │  ├─ onnx_converter_reduce.cc
   │  │     │     │  │  ├─ onnx_converter_reduce.h
   │  │     │     │  │  ├─ onnx_converter_relu.cc
   │  │     │     │  │  ├─ onnx_converter_reshape.cc
   │  │     │     │  │  ├─ onnx_converter_resize.cc
   │  │     │     │  │  ├─ onnx_converter_roialign.cc
   │  │     │     │  │  ├─ onnx_converter_scatter_nd.cc
   │  │     │     │  │  ├─ onnx_converter_selu.cc
   │  │     │     │  │  ├─ onnx_converter_shape.cc
   │  │     │     │  │  ├─ onnx_converter_shuffle_channel.cc
   │  │     │     │  │  ├─ onnx_converter_sigmoid.cc
   │  │     │     │  │  ├─ onnx_converter_sign.cc
   │  │     │     │  │  ├─ onnx_converter_signed_mul.cc
   │  │     │     │  │  ├─ onnx_converter_sin.cc
   │  │     │     │  │  ├─ onnx_converter_size.cc
   │  │     │     │  │  ├─ onnx_converter_slice.cc
   │  │     │     │  │  ├─ onnx_converter_softmax.cc
   │  │     │     │  │  ├─ onnx_converter_softplus.cc
   │  │     │     │  │  ├─ onnx_converter_softsign.cc
   │  │     │     │  │  ├─ onnx_converter_split.cc
   │  │     │     │  │  ├─ onnx_converter_sqrt.cc
   │  │     │     │  │  ├─ onnx_converter_squeeze.cc
   │  │     │     │  │  ├─ onnx_converter_sub.cc
   │  │     │     │  │  ├─ onnx_converter_tan.cc
   │  │     │     │  │  ├─ onnx_converter_tanh.cc
   │  │     │     │  │  ├─ onnx_converter_tile.cc
   │  │     │     │  │  ├─ onnx_converter_topk.cc
   │  │     │     │  │  ├─ onnx_converter_transpose.cc
   │  │     │     │  │  ├─ onnx_converter_unsqueeze.cc
   │  │     │     │  │  ├─ onnx_converter_upsample.cc
   │  │     │     │  │  ├─ onnx_converter_where.cc
   │  │     │     │  │  ├─ onnx_op_converter.cc
   │  │     │     │  │  └─ onnx_op_converter.h
   │  │     │     │  ├─ onnx2tnn.cc
   │  │     │     │  ├─ onnx2tnn.h
   │  │     │     │  ├─ onnx2tnn_model.cc
   │  │     │     │  ├─ onnx2tnn_prefix.h
   │  │     │     │  ├─ onnx_fuse
   │  │     │     │  │  ├─ onnx2tnn_fuse_arg_max_or_min.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_batchnorm.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_conv.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_deconv.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_depth_to_space.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_flatten.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_gelu.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_gemm.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_global_average_pool.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_group_normalization.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_hard_sigmoid.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_hard_swish.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_hdr_guide.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_histogram.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_instance_normalization.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_layer_normalization.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_logsigmoid.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_lstm.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_matmul.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_normalize.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_pooling.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_prelu.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_relu6.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_shuffle_channel.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_signed_mul.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_softmax.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_spacetodepth.cc
   │  │     │     │  │  ├─ onnx2tnn_fuse_transpose.cc
   │  │     │     │  │  ├─ onnx2tnn_transfer_global_max_pool.cc
   │  │     │     │  │  ├─ onnx2tnn_transfer_gridsample.cc
   │  │     │     │  │  ├─ onnx2tnn_transfer_group_normalization.cc
   │  │     │     │  │  ├─ onnx2tnn_transfer_input_name.cc
   │  │     │     │  │  ├─ onnx2tnn_transfer_inverse.cc
   │  │     │     │  │  └─ onnx2tnn_transfer_reduce_max.cc
   │  │     │     │  ├─ onnx_process_tf
   │  │     │     │  │  ├─ onnx2tnn_remove_transpose.cc
   │  │     │     │  │  ├─ onnx2tnn_transfer_concat.cc
   │  │     │     │  │  └─ onnx2tnn_transfer_split.cc
   │  │     │     │  ├─ onnx_remove
   │  │     │     │  │  ├─ onnx2tnn_remove_concat.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_dropout.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_expand.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_identity.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_image_scaler.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_pad.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_pool.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_reshape.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_reshape_where.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_split_unsqueeze_concat.cc
   │  │     │     │  │  ├─ onnx2tnn_remove_squeeze.cc
   │  │     │     │  │  └─ onnx2tnn_remove_unsqueeze.cc
   │  │     │     │  ├─ onnx_utility.cc
   │  │     │     │  └─ onnx_utility.h
   │  │     │     ├─ onnx-proto
   │  │     │     │  └─ onnx.proto
   │  │     │     └─ onnx-proto3
   │  │     │        ├─ onnx.proto3
   │  │     │        ├─ onnx.proto3.pb.cc
   │  │     │        └─ onnx.proto3.pb.h
   │  │     ├─ quantization
   │  │     │  ├─ CMakeLists.txt
   │  │     │  ├─ calibration.cc
   │  │     │  ├─ calibration.h
   │  │     │  ├─ calibration_common.h
   │  │     │  ├─ quantize.cc
   │  │     │  ├─ scale_calculator.cc
   │  │     │  └─ scale_calculator.h
   │  │     └─ tnn2mem
   │  │        ├─ CMakeLists.txt
   │  │        └─ tnn2mem.cpp
   │  └─ base-utils
   │     ├─ .gitignore
   │     ├─ LICENCE
   │     ├─ README.md
   │     ├─ base_utils
   │     │  ├─ CMakeLists.txt
   │     │  ├─ include
   │     │  │  ├─ android_utils.h
   │     │  │  ├─ base.h
   │     │  │  ├─ debug.h
   │     │  │  ├─ file_utils.h
   │     │  │  ├─ filter
   │     │  │  │  ├─ kalman_filter.h
   │     │  │  │  ├─ mean_filter.h
   │     │  │  │  └─ tracking_flow.h
   │     │  │  ├─ image_utils.h
   │     │  │  └─ math_utils.h
   │     │  └─ src
   │     │     ├─ debug.cpp
   │     │     ├─ file_utils.cpp
   │     │     ├─ filter
   │     │     │  ├─ kalman_filter.cpp
   │     │     │  ├─ mean_filter.cpp
   │     │     │  └─ tracking_flow.cpp
   │     │     ├─ image_utils.cpp
   │     │     └─ math_utils.cpp
   │     ├─ cmakelists
   │     │  ├─ qt.txt
   │     │  └─ qt_opencv_opengl.txt
   │     ├─ data
   │     │  ├─ boxes.txt
   │     │  ├─ camera
   │     │  │  ├─ Left1.bmp
   │     │  │  ├─ Left2.bmp
   │     │  │  ├─ Right1.bmp
   │     │  │  └─ Right2.bmp
   │     │  ├─ labelme
   │     │  │  ├─ mask.jpg
   │     │  │  └─ mask.json
   │     │  ├─ mask.jpg
   │     │  ├─ scores.txt
   │     │  ├─ test.png
   │     │  ├─ test_image
   │     │  │  ├─ grid1.png
   │     │  │  ├─ grid2.png
   │     │  │  ├─ grid3.png
   │     │  │  └─ test1.jpg
   │     │  ├─ video
   │     │  │  └─ kunkun_cut.mp4
   │     │  └─ write_contents.txt
   │     ├─ deploy.sh
   │     ├─ docs
   │     │  └─ README.md
   │     ├─ pybaseutils
   │     │  ├─ __init__.py
   │     │  ├─ base64_utils.py
   │     │  ├─ batch_utils.py
   │     │  ├─ color_utils.py
   │     │  ├─ config_utils.py
   │     │  ├─ coords_utils.py
   │     │  ├─ dataloader
   │     │  │  ├─ __init__.py
   │     │  │  ├─ dataset.py
   │     │  │  ├─ parser_labelme.py
   │     │  │  ├─ parser_textdata.py
   │     │  │  └─ parser_voc.py
   │     │  ├─ debug.py
   │     │  ├─ file_utils.py
   │     │  ├─ font_style
   │     │  │  ├─ __init__.py
   │     │  │  ├─ simfang.ttf
   │     │  │  ├─ simhei.ttf
   │     │  │  ├─ simkai.ttf
   │     │  │  ├─ simsun.ttc
   │     │  │  └─ 方正粗黑宋简体.ttf
   │     │  ├─ font_utils.py
   │     │  ├─ geometry_tools.py
   │     │  ├─ heatmap_utils.py
   │     │  ├─ image_utils.py
   │     │  ├─ json_utils.py
   │     │  ├─ log.py
   │     │  ├─ maker
   │     │  │  ├─ __init__.py
   │     │  │  ├─ convert_text2voc.py
   │     │  │  ├─ convert_voc2text.py
   │     │  │  ├─ maker_labelme.py
   │     │  │  └─ maker_voc.py
   │     │  ├─ metrics
   │     │  │  ├─ __init__.py
   │     │  │  ├─ class_report.py
   │     │  │  ├─ plot_pr.py
   │     │  │  └─ plot_roc.py
   │     │  ├─ numpy_utils.py
   │     │  ├─ pandas_utils.py
   │     │  ├─ plot_utils.py
   │     │  ├─ pycpp
   │     │  │  ├─ CMakeLists.txt
   │     │  │  ├─ README.md
   │     │  │  ├─ __init__.py
   │     │  │  ├─ build.sh
   │     │  │  ├─ demo.py
   │     │  │  ├─ docs
   │     │  │  │  └─ C和ctypes的类型.png
   │     │  │  ├─ image.png
   │     │  │  ├─ main.cpp
   │     │  │  ├─ main.py
   │     │  │  ├─ src
   │     │  │  │  ├─ ctypes_utils.cpp
   │     │  │  │  └─ ctypes_utils.h
   │     │  │  └─ test.png
   │     │  ├─ setup_config.py
   │     │  ├─ thread_utils.py
   │     │  ├─ time_utils.py
   │     │  ├─ transforms
   │     │  │  ├─ __init__.py
   │     │  │  ├─ affine_transform.py
   │     │  │  └─ test.jpg
   │     │  ├─ video_utils.py
   │     │  ├─ word_utils.py
   │     │  ├─ worker.py
   │     │  └─ yaml_utils.py
   │     ├─ requirements.txt
   │     ├─ setup.py
   │     ├─ setup.sh
   │     ├─ test_cpp
   │     │  ├─ CMakeLists.txt
   │     │  ├─ README.md
   │     │  ├─ build.sh
   │     │  ├─ contrib
   │     │  │  └─ base_cl
   │     │  │     ├─ CMakeLists.txt
   │     │  │     ├─ README.md
   │     │  │     ├─ include
   │     │  │     │  ├─ Convolution.h
   │     │  │     │  ├─ HelloWorld.h
   │     │  │     │  ├─ HelloWorld_str.h
   │     │  │     │  └─ cl_info.h
   │     │  │     ├─ kernel
   │     │  │     │  ├─ Convolution.cl
   │     │  │     │  ├─ HelloWorld.cl
   │     │  │     │  └─ HelloWorld_Kernel.cl
   │     │  │     └─ src
   │     │  │        └─ cl_info.cpp
   │     │  ├─ filter
   │     │  │  ├─ Types1.h
   │     │  │  ├─ pose_filter1.cpp
   │     │  │  └─ pose_filter1.h
   │     │  ├─ filter_test.cpp
   │     │  ├─ main.cpp
   │     │  ├─ opencl_test.cpp
   │     │  ├─ opencv
   │     │  │  ├─ README.md
   │     │  │  ├─ opencv_nms.cpp
   │     │  │  ├─ stereo_match_bm.cpp
   │     │  │  └─ stereo_match_sgbm.cpp
   │     │  ├─ openmp_test.cpp
   │     │  └─ qt
   │     │     ├─ CMakeLists.txt
   │     │     ├─ README.md
   │     │     ├─ assets
   │     │     │  └─ ui
   │     │     │     └─ mainwindow.ui
   │     │     └─ src
   │     │        ├─ main.cpp
   │     │        ├─ mainwindow.cpp
   │     │        └─ mainwindow.h
   │     └─ test_py
   │        ├─ __init__.py
   │        ├─ confusion_matrix.csv
   │        ├─ csdn0.html
   │        ├─ csdn1.html
   │        ├─ demo.py
   │        ├─ get_file_list.py
   │        ├─ metrics_demo.py
   │        ├─ pandas_demo.py
   │        ├─ pybaseutils-example.py
   │        ├─ taichi_demo.py
   │        ├─ test.png
   │        └─ worker-example.py
   ├─ Face
   │  ├─ angry_face.cpp
   │  ├─ comfort_face.cpp
   │  ├─ faces.hpp
   │  ├─ happy_face.cpp
   │  ├─ normal_face.cpp
   │  ├─ sad_face.cpp
   │  ├─ singing_face.cpp
   │  ├─ sleep_face.cpp
   │  └─ think_face.cpp
   ├─ Fonts
   │  ├─ font12.c
   │  ├─ font16.c
   │  └─ fonts.h
   ├─ data
   │  └─ tnn
   │     ├─ emotion
   │     │  ├─ mobilenet_v2_112_112.tnnmodel
   │     │  └─ mobilenet_v2_112_112.tnnproto
   │     └─ face
   │        ├─ rfb-face-mask-320-320_sim.opt.tnnmodel
   │        ├─ rfb-face-mask-320-320_sim.opt.tnnproto
   │        ├─ rfb1.0_face_320_320.opt.tnnmodel
   │        ├─ rfb1.0_face_320_320.opt.tnnproto
   │        ├─ rfb1.0_face_320_320_freeze_header.opt.tnnmodel
   │        └─ rfb1.0_face_320_320_freeze_header.opt.tnnproto
   ├─ music
   │  ├─ happy
   │  │  └─ happy_test.MP3
   │  ├─ sad
   │  │  └─ sad_test.mp3
   │  └─ tired
   │     └─ tired_test.mp3
   └─ web
      ├─ README.md
      ├─ eslint.config.js
      ├─ index.html
      ├─ mood_logger
      ├─ mood_logger.cpp
      ├─ node_modules.zip
      ├─ package-lock.json
      ├─ package.json
      ├─ public
      │  ├─ index.html
      │  └─ vite.svg
      ├─ server.cpp
      ├─ server.js
      ├─ setup_npm_service.sh
      ├─ src
      │  ├─ App.css
      │  ├─ App.jsx
      │  ├─ assets
      │  │  ├─ react.svg
      │  │  └─ socket.js
      │  ├─ index.css
      │  └─ main.jsx
      ├─ vite.config.js
      ├─ websocket
      └─ websocket.cpp
```





