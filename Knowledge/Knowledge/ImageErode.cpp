
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\opencv.hpp>  
using namespace cv;

int ImageErode(int argc, char *argv[])
{
	//����ԭͼ  
	Mat srcImage = imread("..\\..\\opencv\\sources\\samples\\data\\aero1.jpg");
	if (srcImage.empty())
	{
		std::cout<< "empty image" << std::endl;
		waitKey(0);
		return -1;
	}
	//��ʾԭͼ
	imshow("��ԭͼ����ʴ����", srcImage);
	//���и�ʴ���� 
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	//��ʾЧ��ͼ 
	imshow("��Ч��ͼ����ʴ����", dstImage);
	waitKey(0);

	return 0;
}