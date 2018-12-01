
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\opencv.hpp>  
using namespace cv;

int ImageErode(int argc, char *argv[])
{
	//载入原图  
	Mat srcImage = imread("..\\..\\opencv\\sources\\samples\\data\\aero1.jpg");
	if (srcImage.empty())
	{
		std::cout<< "empty image" << std::endl;
		waitKey(0);
		return -1;
	}
	//显示原图
	imshow("【原图】腐蚀操作", srcImage);
	//进行腐蚀操作 
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	//显示效果图 
	imshow("【效果图】腐蚀操作", dstImage);
	waitKey(0);

	return 0;
}