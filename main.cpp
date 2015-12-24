//
// Created by stefan on 12/24/15.
//


// Example copied from
// http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    namedWindow("edges", 1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        flip(frame, frame, 1);
        imshow("edges", frame);
        if(waitKey(30) >= 0) break; // Esc to exit
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
