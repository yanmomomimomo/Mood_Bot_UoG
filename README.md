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

- Cui Yuxiang - 2864612C
[Jyc66ui](https://github.com/Jyc66ui)
- Li Linzheng - 2021000001
  [[MoonupLee](https://github.com/MoonupLee)]
  
- Li Sicheng - 2021000001
  [yanmomomimomo](https://github.com/yanmomomimomo)
  
- Yuan Quan - 2021000001
  [yquan0000](https://github.com/yquan0000)
  
- Xu Zihan - 2764591X
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
## Code Structure
## How it works




