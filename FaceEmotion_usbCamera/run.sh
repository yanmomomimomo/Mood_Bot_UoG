#!/usr/bin/bash
export LD_LIBRARY_PATH=/usr/local/lib/libonnxruntime.so:$LD_LIBRARY_PATH
bazel-bin/src/faceemotionlive /home/pi/mediapipe/mobilenet_v3_small.onnx
