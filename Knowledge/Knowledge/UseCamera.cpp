#include <opencv2\opencv.hpp>  
using namespace cv;

int UseCamera(int argc, char *argv[])
{
	//��1��������ͷ������Ƶ
	VideoCapture capture(0);
	if (!capture.isOpened())
	{
		std::cout << "open camera failed" << std::endl;
		return -1;
	}

	//��2��ѭ����ʾÿһ֡
	while (1)
	{
		Mat frame;  //����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame;  //��ȡ��ǰ֡
		imshow("��ȡ��Ƶ", frame);  //��ʾ��ǰ֡
		waitKey(30);  //��ʱ30ms
	}

	return 0;
}