//
// Created by stefan on 12/24/15.
//


// Example copied from
// http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html
#include "opencv2/opencv.hpp"
#include "Cube.h"
#include "CubeDrawer2D.h"

int main(int, char**)
{
    cv::Mat img(320, 320, CV_8UC3, cv::Scalar::all(0));

    cv::namedWindow("Rubik Solver", 1);
    Cube cube;
    cube.transform(LEFT_CCW);
    cube.transform(TOP_CW);
    cube.transform(BACK_CCW);
    //cube.scramble(3);
    CubeDrawer2D dCube(cube);
    dCube.draw(&img, dCube.mDefaultColorMap);
    imshow("Rubik Solver", img);

    cv::waitKey();
    return 0;
}
