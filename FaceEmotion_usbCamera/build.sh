#!/usr/bin/bash
bazel build -c opt --jobs 2 --define MEDIAPIPE_DISABLE_GPU=1 src:faceemotionlive
