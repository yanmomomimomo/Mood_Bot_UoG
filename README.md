<u>Chinese Version</u>

OpenCV 环境配置顺利，没有太多问题。不过，也遇到了一些与 “pkgconfig ”相关的问题。大概是默认安装路径不会生成opencv.pc这些看不懂的玩意。新版的甚至叫opencv4.pc。

brew完opencv后`pkg-config --cflags --libs opencv` 如果报错就移步[这里](https://link.juejin.cn/?target=https%3A%2F%2Fblog.csdn.net%2FPecoHe%2Farticle%2Fdetails%2F97476135)

本来打算用腾讯的TNN，笑死环境根本配不出来。换成dlib，给的CMakeLists是人能看懂的。

dlib配好了省的下载再自己配了。

需要自己装的玩意为：

- OpenCV

	- 按理装好后直接能用

- X11图形显示。

	- X11是执行Unix程序的图形窗口环境。Mac OS X本身的程序是Aqua界面的，但是为了能够兼容unix和linux移植过来的程序（Mac OS X由BSD-UNIX修改而来），比如MatLab，就需要x11窗口环境。

		运行dlib需要X11，但Mac目前没有自带X11，需要重新下载安装，[下载地址](https://www.xquartz.org/)

shape_predictor_68_face_landmarks.dat：dlib用到的模型

SVM_DATA.xml：前人训练好的用SVM来分类的表情数据，目前就Happy；Common；Disgust。

No offense 但是CMake真的很奇怪啊，c++真是低级编程语言来的。

编译方式：

如果你用Clion打开大概会自动生成一个cmake-build-degug的文件夹，可以不管。

```cmd
# 先cd到根目录总之 Mood_Bot_UoG
mkdir build # 建立一个build文件夹（目录）
cd build
cmake ..
make #这个时候应该有test和Mood_Bot_UoG两个可执行文件
# 然后把src里的.bat 和.xml扔进build里
./Mood_Bot_UoG # test是拿来测试dlib特征提取的
```

