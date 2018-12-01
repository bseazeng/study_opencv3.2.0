#include <opencv2\opencv.hpp>  
using namespace cv;

int PlayVideo(int argc, char *argv[])
{
	Mat frame; //��ǰ֡
	Mat fgMaskMOG2; //ͨ��MOG2�����õ�������ͼ��fgmask
	Mat segm;      //frame�ĸ���
	std::vector<std::vector<Point> > contours;
	std::vector<Vec4i> hierarchy;
	Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor
	//create Background Subtractor objects

	pMOG2 = createBackgroundSubtractorMOG2();

	//VideoCapture capture(0); //����Ϊ0��Ĭ�ϴ�����ͷ��ȡ��Ƶ
	VideoCapture capture("..\\..\\opencv\\sources\\samples\\data\\vtest.avi");

	if (!capture.isOpened())
	{
		std::cout << "Unable to open the camera! " << std::endl;
		return -1;
	}

	while (true){

		if (!capture.read(frame))
		{
			std::cout << "Unable to read next frame." << std::endl;
			return 0;
		}

		//�Ի������һ�������ţ����㴦��
		double scale = 1.3;         //���ű���
		Mat smallImg(frame.rows / scale, frame.cols / scale, CV_8SC1);
		resize(frame, frame, smallImg.size(), 0, 0, INTER_LINEAR);


		pMOG2->apply(frame, fgMaskMOG2);    //���±���ģ��
		frame.copyTo(segm);             //����һ����ǰframe�ĸ���
		findContours(fgMaskMOG2, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0)); //�������

		std::vector <std::vector<Point> > contours_poly(contours.size());
		std::vector <Point2f> center(contours.size());
		std::vector <float> radius(contours.size());
		for (int i = 0; i < contours.size(); i++)
		{
			//findContours���������Ϣcontours���ܹ��ڸ��Ӳ�ƽ����������approxPolyDP�����Ըö�����������ʵ�����
			approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
			//�õ������������Բ
			minEnclosingCircle(contours_poly[i], center[i], radius[i]);
		}
		//�����õ�����������һ����ɸѡ
		for (int i = 0; i < contours.size(); i++)
		{
			if (contourArea(contours[i]) > 500)
			{
				circle(segm, center[i], (int)radius[i], Scalar(100, 100, 0), 2, 8, 0);
				break;
			}
		}

		//get the frame number and write it on the current frame
		std::stringstream ss;
		//        rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
		//                  cv::Scalar(255,255,255), -1);
		ss << capture.get(CAP_PROP_POS_FRAMES);
		std::string frameNumberString = ss.str();
		putText(frame, frameNumberString.c_str(), cv::Point(15, 15), FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));

		//��ʾ
		imshow("frame", frame);
		imshow("Segm", segm);
		imshow("FG Mask MOG 2", fgMaskMOG2);


		int key;
		key = waitKey(100);
		if (key == 'q' || key == 'Q' || key == 27)
			break;


	}

	capture.release();

	//destroyAllWindows();

	return 0;
}