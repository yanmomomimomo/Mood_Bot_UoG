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

## Code Structure
## How it works
### Motor
### GUI
### Camera

It captures video frames through a video camera by Opencv, detect faces and emotions at about 10fps. If it detects happy emotions, it will display a happy emoji and words like “ You are happy and I am happy too” and play notification sound. If it detects negative emotions, it will comfort you by showing a sad emoji and words like ”do not be sad”. If it detects that the person is very tired, it will let him go have a rest.

### Main Thread

## Issues during development

- 

## Future Work

- 





