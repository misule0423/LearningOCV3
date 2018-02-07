#include <iostream>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

	namedWindow("Example3", WINDOW_AUTOSIZE);
	
	VideoCapture cap;
	
	cap.open("cat.avi");
	
	Mat frame;
	
	for (;;) {
	
		cap >> frame;
		
		if (frame.empty()) break; // Ran out of film
		
		imshow("Example3", frame);
		
		if (waitKey(1000) == 27) break;
		}
	return 0;

}