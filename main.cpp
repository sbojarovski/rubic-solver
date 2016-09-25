//
// Created by stefan on 12/24/15.
//


// Example copied from
// http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html
#include "opencv2/opencv.hpp"
#include "Cube.h"
#include "CubeDrawer2D.h"

void drawStepTransform(Cube & cube, const std::vector<CubeTransforms > & transforms)
{
    int imgWidth = 960;
    int imgHeight = 960;
    cv::Point labelPos(imgWidth - imgWidth/3, imgHeight - imgHeight/3);
    cv::Point validPos(labelPos.x, labelPos.y + 30);
    cv::Mat img(imgWidth, imgHeight, CV_8UC3, cv::Scalar::all(0));
    cv::namedWindow("Rubik Solver", cv::WINDOW_FREERATIO | cv::WINDOW_NORMAL );

    CubeDrawer2D dCube(cube);

    for(auto t : transforms)
    {
        // draw the cube and additional info
        dCube.draw(img);

        std::string tLabel = Cube::getTransformString(t);
        cv::rectangle(img, cv::Point(labelPos.x , labelPos.y + 10), cv::Point(labelPos.x + 220, labelPos.y - 20), CV_RGB(0, 0, 0), CV_FILLED);
        cv::putText(img, tLabel, labelPos, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(200, 200, 200), 1.0, cv::LINE_AA);

        cv::rectangle(img, cv::Point(validPos.x , validPos.y + 10), cv::Point(validPos.x + 220, validPos.y - 20), CV_RGB(0, 0, 0), CV_FILLED);
        cv::putText(img, cube.isValid() ? "valid" : "not valid", validPos, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(200, 200, 200), 1.0, cv::LINE_AA);

        imshow("Rubik Solver", img);
        cv::waitKey();
        // apply the transformation
        cube.transform(t);
    }
    dCube.draw(img);
    imshow("Rubik Solver", img);
    cv::waitKey();
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
    //testAllTransforms();
    //drawStepTransform(cube, Cube::getRandomTransformVec(10));
    // TODO: this causes an invalid state of the cube ...
    std::vector<CubeTransforms > tvec = {TOP_CCW, LEFT_CCW};
    drawStepTransform(cube, tvec);
    return 0;
}
