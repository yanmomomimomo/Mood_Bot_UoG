# About Emotion Detection

FaceEmotion_v0 is the very initial trying to have a try about face detection and emotion classification. Although he programming platform was MacOS. But helped with understanding programming in c++ together with CMAKE.

FaceEmotion_sciCamera  is the next version, trying to use more open-sourced libraries, including [libcamera2opencv](https://github.com/berndporr/libcamera2opencv). It is built on the foundation of an [open-source project](https://blog.csdn.net/guyuealian/article/details/129467023). (Note that there is a spelling mistake in the folder name, due to a bad and massive libs management, it would be hard to fix that, so this method was abandoned.) But a wired bug encountered while testing. The example “qtviewer” provided within the libcamera2opencv seems to be incompatible with Logitech C270 USB Camera. 

![qtviewer_bug](assets\qtviewer_bug.png)

In our previous design, we found that the Raspberry Pi's arithmetic power was still on the low side and could overheat easily, so after comparing many different models as well as visual processing libraries. It was found that Mediapipe would be a very good choice. In our previous design, we found that the Raspberry Pi's arithmetic power was still on the low side and could overheat easily, so after comparing many different models as well as visual processing libraries. It was found that Mediapipe would be a very good choice. It is specially designed for mobile, especially suitable for devices with limited resources for real-time face detection, expression recognition, face tracking and other complex tasks, and it has an official C++ API, which can be well integrated into embedded C++ projects. What's even more surprising is that Mediapipe provides a Face Mesh of up to 468 keypoints while maintaining a very fast inference speed.

But the ensuing problem is that Mediapipe doesn't quite support CMAKE.However, the problem was that Mediapipe required Bazel and had little support for CMAKE, whereas the previous design had been using CMAKE, so we had to think about switching from CMAKE to Bazel. Fortunately, Bazel could be bridged to the CMAKE project, which made it possible to co-operate with the projects of the other members of the team. Moreover, Bazel has more uniform rules than CMAKE, so we only need to spend a little bit of configuration time at the beginning and then we can enjoy the high build speed and high extensibility.

That leads to the third version “FaceEmotion_usbCamera”. That camera comes with a longer cable and a solid case which will make establishment more easier.

# To use this module separately

## Prerequisites

1. OpenCv：https://qengineering.eu/install%20opencv%20on%20raspberry%20pi%205.html

2. Bazel：https://bazel.build/install

3. Mediapipe：```git clone https://github.com/google-ai-edge/mediapipe```

4. Onnxruntime：

	```bash
	git clone --recursive https://github.com/microsoft/onnxruntime
	cd onnxruntime
	./build.sh --config Release --build_shared_lib --parallel
	```

## Compilation

Clone this branch and move all files inside FaceEmotion_usbCamera/ into the root folder of Mediapipe.

```bash
cd Mediapipe
sudo bash ./build.sh
sudo ./run.sh
```

