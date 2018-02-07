#include <iostream>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

	namedWindow("Cat", WINDOW_AUTOSIZE);
	
	VideoCapture cap;
	
	cap.open("cat.avi");
	
	Mat frame;
	
	for (;;) {

		cap >> frame;

		if (frame.empty()) break; // Ran out of film

		imshow("Cat", frame);

		if (waitKey(33) == 27) break;	}
	return 0;

}