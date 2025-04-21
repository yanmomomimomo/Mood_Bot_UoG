# Copyright 2019 The MediaPipe Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
load("//:qt.bzl", "qt_cc_library", "qt_ui_library","qt_resource")
licenses(["notice"])

package(default_visibility = ["//mediapipe/examples:__subpackages__"])

cc_binary(
    name = "face_mesh_tflite",
    deps = [
        "//mediapipe/examples/desktop:simple_run_graph_main",
        "//mediapipe/graphs/face_mesh:desktop_calculators",
    ],
)

cc_binary(
    name = "face_mesh_cpu",
    deps = [
        "//mediapipe/examples/desktop:demo_run_graph_main",
        "//mediapipe/graphs/face_mesh:desktop_live_calculators",
    ],
)

# Linux only
cc_binary(
    name = "face_mesh_gpu",
    deps = [
        "//mediapipe/examples/desktop:demo_run_graph_main_gpu",
        "//mediapipe/graphs/face_mesh:desktop_live_gpu_calculators",
    ],
)
qt_cc_library(
    name = "emotion",
    srcs = ["emotionclassifier.cpp"],
    hdrs = ["emotionclassifier.h"],
    linkopts = ["-L/usr/local/lib", "-lonnxruntime","-lonnxruntime_providers_shared"],
    copts = ["-lonnxruntime","-lonnxruntime_providers_shared","-lpthread"],
    deps = ["@qt//:qt_widgets",
               "@qt//:qt_core",
               "@qt//:qt_gui",
               "//mediapipe/examples/desktop:demo_run_graph_main",
               "//mediapipe/graphs/face_mesh:desktop_live_calculators",
           ],
)
qt_cc_library(
    name = "facemesh",
    srcs = ["face_mesh.cpp"],
    hdrs = ["face_mesh.h"],
    deps = [
    ":emotion",
    "@qt//:qt_widgets",
               "@qt//:qt_core",
               "@qt//:qt_gui",
               "//mediapipe/examples/desktop:demo_run_graph_main",
               "//mediapipe/graphs/face_mesh:desktop_live_calculators",
           ],
)
qt_cc_library(
    name = "gui",
    srcs = ["gui.cpp"],
    hdrs = ["gui.h"],
    deps = [
    ":emotion",
    "@qt//:qt_widgets",
               "@qt//:qt_core",
               "@qt//:qt_gui",
               "//mediapipe/examples/desktop:demo_run_graph_main",
               "//mediapipe/graphs/face_mesh:desktop_live_calculators",
           ],
)

cc_binary(
    name = "faceemotionlive",
    srcs=["main.cpp"],
    linkopts = ["-L/usr/local/lib", "-lonnxruntime","-lonnxruntime_providers_shared"],
    copts = ["-lpthread"],
    deps = [
        ":gui",
        ":emotion",
        ":facemesh",
        "//mediapipe/examples/desktop:demo_run_graph_main",
        "//mediapipe/graphs/face_detection:desktop_live_calculators",
    ],
)
