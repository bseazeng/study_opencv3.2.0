#include <opencv2\opencv.hpp>
using namespace cv;  //����cv�����ռ�

int  BlurImage(int argc, char *argv[] )
{
	//��1������ԭʼͼ
	Mat srcImage = imread("..\\..\\opencv\\sources\\samples\\data\\aero1.jpg");

	//��2����ʾԭʼͼ
	imshow("��ֵ�˲���ԭͼ��", srcImage);

	//��3�����о�ֵ�˲�����
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	//��4����ʾЧ��ͼ
	imshow("��ֵ�˲���Ч��ͼ��", dstImage);

	waitKey(0);

	return 0;
}