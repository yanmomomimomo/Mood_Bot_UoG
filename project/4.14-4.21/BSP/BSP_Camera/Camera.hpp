#ifndef __CAMERA_HPP
#define __CAMERA_HPP

// 定义一些宏和外调函数
// 返回值定义
#include <stdio.h>
#define CAMERA_OK 0            // 操作成功
#define CAMERA_ERROR -1        // 操作失败
#define CAMERA_NOT_INITIALIZED -2 // 摄像头未初始化

// 情绪类型定义
#define EMOTION_ANGRY 0       // 生气表情
#define EMOTION_DISGUST 1     // 厌恶表情
#define EMOTION_FEAR 2        // 恐惧表情
#define EMOTION_HAPPY 3       // 开心表情
#define EMOTION_NEUTRAL 4     // 中性表情
#define EMOTION_SAD 5         // 悲伤表情
#define EMOTION_SURPRISE 6    // 惊讶表情

// 外调函数声明
/**
 * @brief 初始化摄像头
 * @return bool - 成功返回true，失败返回false
 */
extern bool Camera_Init();

/**
 * @brief 释放摄像头资源
 */
extern void Camera_DeInit();

/**
 * @brief 启动摄像头
 * @return bool - 成功返回true，失败返回false
 */
extern bool Camera_Start();

/**
 * @brief 停止摄像头
 */
extern void Camera_Stop();

/**
 * @brief 获取检测到的人脸数量
 * @return int - 人脸数量，失败返回错误码
 */
extern int Camera_GetFaceCount();

/**
 * @brief 获取指定人脸的表情类型
 * @param faceIndex - 人脸索引，从0开始
 * @return int - 表情类型(EMOTION_*)，失败返回错误码
 */
extern int Camera_GetEmotion(int faceIndex);

/**
 * @brief 获取指定人脸的表情置信度
 * @param faceIndex - 人脸索引，从0开始
 * @return float - 表情置信度(0.0-1.0)，失败返回错误码
 */
extern float Camera_GetEmotionConfidence(int faceIndex);

/**
 * @brief 获取指定人脸的中心点坐标
 * @param faceIndex - 人脸索引，从0开始
 * @param centerX - 返回中心点X坐标
 * @param centerY - 返回中心点Y坐标
 * @return bool - 成功返回true，失败返回false
 */
extern bool Camera_GetFaceCenter(int faceIndex, int *centerX, int *centerY);

/**
 * @brief 保存当前帧为图像文件
 * @param filename - 保存的文件名
 * @return bool - 成功返回true，失败返回false
 */
extern bool Camera_SaveFrame(const char *filename);

#endif // __CAMERA_HPP