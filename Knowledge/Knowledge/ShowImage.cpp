#include <opencv2/opencv.hpp>  //ͷ�ļ�
using namespace cv;  //����cv�����ռ�

int ShowImage(int argc, char *argv[])
{
	// ��1������һ��ͼƬ������ͼ��
	Mat srcImage = imread("..\\..\\opencv\\sources\\samples\\data\\aero1.jpg");
	// ��2����ʾ�����ͼƬ
	imshow("��ԭʼͼ��", srcImage);

	Mat img_color;
	// Apply the colormap:
	applyColorMap(srcImage, img_color, COLORMAP_JET);
	// Show the result:
	imshow("colorMap", img_color);

	//�ȴ����ⰴ������
	waitKey(0);

	return 0;
}