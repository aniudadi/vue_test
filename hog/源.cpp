#include <opencv2/opencv.hpp>
#include <iostream>
#include<opencv2\highgui\highgui_c.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat img;
	vector<Rect> found;

	img = imread("C:/Users/hi/Desktop/1/20.jpg");

	HOGDescriptor defaultHog;
	defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

	//���м��
	defaultHog.detectMultiScale(img, found);

	//�������Σ��������
	for (int i = 0; i < found.size(); i++) {
		Rect r = found[i];
		rectangle(img, r, Scalar(0, 255, 0), 1);
	}
	namedWindow("�������", CV_WINDOW_AUTOSIZE);
	imshow("�������", img);

	waitKey(0);

	return 0;
}