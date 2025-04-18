# 人脸检测与表情识别项目改进记录

本文档记录了对`camera_detection.cpp`进行的主要改进和修改，以便追踪和复盘工作流程。

## 主要功能改进

1. **添加人脸中心点坐标显示**
   - 计算每个检测到的人脸的中心坐标
   - 在人脸框下方显示坐标信息
   - 添加黑色背景使文字更易读

2. **添加表情识别功能**
   - 集成TNN表情识别模型
   - 对检测到的人脸进行表情分类
   - 支持7种表情：angry, disgust, fear, happy, neutral, sad, surprise

3. **改进可视化效果**
   - 将人脸标签替换为检测到的表情
   - 使用不同颜色区分不同表情
   - 增大字体和标签背景，提高可读性

4. **持久化显示**
   - 即使在非检测帧也保持显示最新的检测结果
   - 实现流畅的视觉体验

## 关键技术突破

1. **表情识别方法**
   - 最初尝试：单独处理每个人脸ROI进行表情分类
   - 最终解决方案：直接将整个frameInfo传递给分类器，参考main.cpp实现

2. **表情标签问题解决**
   - 发现分类器返回了无效的标签值(32767)
   - 通过直接使用SDK预期的调用方式解决问题

## 代码修改摘要

### 1. 添加表情识别相关代码

```cpp
// 表情识别模型
const char *emo_model_file = (char *) "/home/mood/object-detection-tnn-sdk/data/tnn/emotion/mobilenet_v2_112_112.tnnmodel";
const char *emo_proto_file = (char *) "/home/mood/object-detection-tnn-sdk/data/tnn/emotion/mobilenet_v2_112_112.tnnproto";
ClassificationParam emotion_param = EMOTION_MODEL; // 使用表情识别模型参数

// 表情识别对象
Classification *emotionClassifier = nullptr;

// 初始化表情识别器
emotionClassifier = new Classification(emo_model_file,
                                      emo_proto_file,
                                      emotion_param,
                                      num_thread,
                                      device);
```

### 2. 表情识别处理函数

```cpp
// 对检测到的人脸进行表情识别
void processEmotions(cv::Mat &frame, FrameInfo *frameInfo) {
    if (frameInfo->info.empty() || !emotionClassifier) {
        std::cout << "无法进行表情识别：没有人脸或分类器未初始化" << std::endl;
        return;
    }
    
    std::cout << "直接对整个FrameInfo进行表情分类..." << std::endl;
    
    // 关键突破：直接将frameInfo传递给分类器
    emotionClassifier->detect(frame, frameInfo);
    
    // 输出分类结果
    for (size_t i = 0; i < frameInfo->info.size(); i++) {
        ObjectInfo &faceInfo = frameInfo->info[i];
        if (faceInfo.category.label >= 0 && 
            faceInfo.category.label < static_cast<int>(emotion_param.class_names.size())) {
            
            std::cout << "人脸 #" << i + 1 << " 识别到表情: " 
                      << emotion_param.class_names[faceInfo.category.label]
                      << " (索引:" << faceInfo.category.label << ")"
                      << " 置信度: " << faceInfo.category.score << std::endl;
        } else {
            std::cout << "人脸 #" << i + 1 << " 表情识别失败，标签: " 
                      << faceInfo.category.label << " 置信度: " 
                      << faceInfo.category.score << std::endl;
        }
    }
}
```

### 3. 自定义可视化函数

```cpp
// 自定义可视化方法，将人脸标签替换为检测到的表情
void customVisualizeResult(cv::Mat &imgBRG, FrameInfo *frameInfo) {
    // 使用COLOR_TABLE数组来提供不同的颜色
    static const std::vector<cv::Scalar> COLOR_TABLE = {
        cv::Scalar(0, 0, 255),     // 红色 - angry
        cv::Scalar(128, 0, 128),   // 紫色 - disgust
        cv::Scalar(0, 69, 255),    // 橙色 - fear
        cv::Scalar(0, 255, 0),     // 绿色 - happy
        cv::Scalar(255, 255, 0),   // 青色 - neutral
        cv::Scalar(255, 0, 0),     // 蓝色 - sad
        cv::Scalar(255, 0, 255),   // 品红色 - surprise
        cv::Scalar(0, 255, 255),   // 黄色 - 其他
        cv::Scalar(255, 255, 255)  // 白色 - 其他
    };
    
    // 遍历检测到的对象并绘制
    for (int i = 0; i < frameInfo->info.size(); i++) {
        auto &obj = frameInfo->info.at(i);
        // ...绘制代码...
    }
}
```

### 4. 在主循环中的调用

```cpp
// 如果检测到人脸，执行表情识别
if (!lastResultInfo.info.empty()) {
    processEmotions(resizedFrame, &lastResultInfo);
}

// ...

// 无论是否为检测帧，都根据最新检测结果显示
if (hasDetectionResult) {
    // 可视化检测结果 - 使用自定义函数替代原有函数
    customVisualizeResult(processFrame, &lastResultInfo);
    
    // 计算并显示人脸中心点和表情
    drawFaceCenters(processFrame, lastResultInfo);
}
```

## 未来可能的改进

1. **代码优化**
   - 重构代码，提高可读性和可维护性
   - 创建更小的函数单元，遵循单一职责原则
   - 使用智能指针替代原始指针，避免内存泄漏
   - 引入配置文件，避免硬编码路径和参数
   - 实现更好的错误处理和日志系统
   - 优化算法效率，减少CPU和内存占用

2. **小车集成**
   - 设计模块化接口，便于与小车控制系统集成
   - 添加基于表情的命令系统（如：笑脸前进，生气停止等）
   - 创建JSON/protobuf API用于与其他系统通信
   - 使用消息队列或发布-订阅模式进行系统间通信
   - 实现低延迟数据传输，保证实时性
   - 考虑添加远程控制/监控接口

3. **摄像头视角优化**
   - 调整相机参数，增大视野范围，减小人脸在画面中的占比
   - 实现可调焦距/视角功能，通过键盘快捷键控制缩放级别
   - 添加视野自适应功能，保持人脸在画面中占适当比例
   - 考虑使用广角镜头增加摄像头视野，使得即使在近距离也能拍摄到更大范围
   - 增加预设距离选项，用户可以选择"近距离"、"中等距离"或"远距离"模式
   - 添加画面缩小功能，可以将整个画面按比例缩小显示
   - 实现自动取景功能，保持人脸在画面中居中但不会过大

4. 提高表情识别准确率
5. 添加更多种类的检测（姿态检测、行为识别等）
6. 实现表情变化统计和记录
7. 优化边缘情况下的识别性能
8. 添加滤镜或增强现实效果

## 已知问题

1. libcamera相关的linter错误（不影响实际运行）
2. 极端光线条件下的识别准确率可能有限 