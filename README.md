# MoodBot
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
-  Linzheng Li - 2021000001
  [[MoonupLee](https://github.com/MoonupLee)]
  
-  Sicheng Li - 2021000001
  [yanmomomimomo](https://github.com/yanmomomimomo)
  
-  Quan Yuan - 2021000001
  [yquan0000](https://github.com/yquan0000)
  
-  Zihan Xu - 2764591X
[Mccona](https://github.com/Mccona)

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
- 
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
## How it works




