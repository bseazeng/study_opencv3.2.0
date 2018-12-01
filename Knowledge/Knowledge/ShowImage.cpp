#include <opencv2/opencv.hpp>  //头文件
using namespace cv;  //包含cv命名空间

int ShowImage(int argc, char *argv[])
{
	// 【1】读入一张图片，载入图像
	Mat srcImage = imread("..\\..\\opencv\\sources\\samples\\data\\aero1.jpg");
	// 【2】显示载入的图片
	imshow("【原始图】", srcImage);

	Mat img_color;
	// Apply the colormap:
	applyColorMap(srcImage, img_color, COLORMAP_JET);
	// Show the result:
	imshow("colorMap", img_color);

	//等待任意按键按下
	waitKey(0);

	return 0;
}