#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat srcImage = imread("../TestFiles/Test.png");
    if (!srcImage.data) {
        std::cout << "Image not loaded";

        return -1;
    }
    imshow("image", srcImage);
    waitKey(0);
    return 0;
}