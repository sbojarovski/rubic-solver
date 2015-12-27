//
// Created by stefan on 12/27/15.
//

#ifndef RUBIC_SOLVER_CUBEDRAWER2D_H
#define RUBIC_SOLVER_CUBEDRAWER2D_H

#include <opencv2/core/mat.hpp>

#include "Cube.h"

class Cell2D
{
public:
    cv::Point2i mOrigin;
    int mSize;
    int mInnerCellMargin = 2;

    cv::Scalar mColor;

    void draw(cv::Mat * image, const std::map<CellColor, cv::Scalar> &colorMap);
    void setOrigin(cv::Point2i & orig);
    void setSize(const int & size);
};

class Face2D
{
public:
    // take out a margin of Y = 2 pixels from it, as a spacing between faces
    cv::Point2i mOrigin;
    int mInnerMargin = 2;
    int mSize;

    Cell2D c11;
    Cell2D c12;
    Cell2D c13;
    Cell2D c21;
    Cell2D c22;
    Cell2D c23;
    Cell2D c31;
    Cell2D c32;
    Cell2D c33;

    void draw(cv::Mat * image, const std::map<CellColor , cv::Scalar> & colorMap);
    void setOrigin(const cv::Point2i & orig);
    void setSize(const int & size);
private:
    void initCells();
    void drawCells(cv::Mat * image, const std::map<CellColor , cv::Scalar> & colorMap);
};

class CubeDrawer2D
{
public:
    CubeDrawer2D(const Cube & cube);
    cv::Point2i mOrigin;
    int mCanvasMargin;
    int mFaceCanvasSize;

    Face2D front;
    Face2D back;
    Face2D left;
    Face2D right;
    Face2D top;
    Face2D bottom;

    void draw(cv::Mat * image, const std::map<CellColor , cv::Scalar> & colorMap);

private:
    void initLengths(cv::Mat *image);
    void generateFacePositions();
    void drawFaces(cv::Mat * image, const std::map<CellColor , cv::Scalar> & colorMap);
public:
    static std::map<CellColor , cv::Scalar> mDefaultColorMap;
};

#endif //RUBIC_SOLVER_CUBEDRAWER2D_H
