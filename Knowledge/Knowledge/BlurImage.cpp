#include <opencv2\opencv.hpp>
using namespace cv;  //包含cv命名空间

int  BlurImage(int argc, char *argv[] )
{
	//【1】载入原始图
	Mat srcImage = imread("..\\..\\opencv\\sources\\samples\\data\\aero1.jpg");

	//【2】显示原始图
	imshow("均值滤波【原图】", srcImage);

	//【3】进行均值滤波操作
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	//【4】显示效果图
	imshow("均值滤波【效果图】", dstImage);

	waitKey(0);

	return 0;
}