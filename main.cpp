//
// Created by stefan on 12/24/15.
//


// Example copied from
// http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html
#include "opencv2/opencv.hpp"
#include "Cube.h"
#include "CubeDrawer2D.h"

void drawStepTransform(Cube & cube, std::vector<CubeTransforms > & transforms)
{
    cv::Mat img(320, 320, CV_8UC3, cv::Scalar::all(0));
    cv::namedWindow("Rubik Solver", 1);

    for(auto t : transforms)
    {
        CubeDrawer2D dCube(cube);
        dCube.draw(img, dCube.mDefaultColorMap);
        imshow("Rubik Solver", img);
        cv::waitKey();
        cube.transform(t);
    }
}

void testAllTransforms()
{
    Cube cube;

    std::vector<CubeTransforms > tvec = {
            LEFT_CCW,
            LEFT_CW,
            LEFT_CW,
            LEFT_CCW,
            FRONT_CCW,
            FRONT_CW,
            FRONT_CW,
            FRONT_CCW,
            RIGHT_CCW,
            RIGHT_CW,
            RIGHT_CW,
            RIGHT_CCW,
            BACK_CCW,
            BACK_CW,
            BACK_CW,
            BACK_CCW,
            TOP_CCW,
            TOP_CW,
            TOP_CW,
            TOP_CCW,
            BOTTOM_CCW,
            BOTTOM_CW,
            BOTTOM_CW,
            BOTTOM_CCW
    };

    drawStepTransform(cube, tvec);
}

int main(int, char**)
{
    Cube cube;
    return 0;
}
