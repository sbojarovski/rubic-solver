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
    // The top left corner of the cell
    cv::Point2i mOrigin;
    // The size of the cell in pixels
    int mSize;
    // The margin from the cell's canvas
    int mInnerCellMargin = 2;

    // The cell's color as a cv 3-component vector
    cv::Scalar mColor;

    // Set the cell's size
    void setSize(const int & size);
    // Set the top left corner of the cell
    void setOrigin(const int &x, const int &y);
    // Set the top left corner of the cell
    void setOrigin(cv::Point2i & orig);

    // Draw this cell
    void draw(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap);
};

class Face2D
{
public:
    // The top left corner of the canvas onto which the face will be drawn
    cv::Point2i mOrigin;
    // An inner margin from the face's canvas
    int mInnerMargin = 2;
    // The size of the canvas in pixels, that is dedicated to this face
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

    // Set the top left corner of the canvas
    void setOrigin(const cv::Point2i & orig);
    // Set the canvas size for this face
    void setSize(const int & size);

    // Draw this face
    void draw(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap);
private:
    // Calculate the starting positions where the cells will be drawn
    void initCells();
    // Draw all the cells in this face
    void drawCells(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap);
};

class CubeDrawer2D
{
public:
    CubeDrawer2D(const Cube & cube);
    // The top left corner of the image where the drawing of the faces will start
    cv::Point2i mOrigin;
    // The number of pixels to take away from the borders of the window
    int mCanvasMargin;
    // The size of the window that is left to draw 4x4 faces after taking out the margins
    int mFaceCanvasSize;

    Face2D front;
    Face2D back;
    Face2D left;
    Face2D right;
    Face2D top;
    Face2D bottom;

    // Draws a 2D unwrapped cube to a given image, with a given colormap
    void draw(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap = mDefaultColorMap);

private:
    // Initialize the lengths of the margins, the canvas size for a single face
    // and the starting position of the drawing canvas for the whole cube in the window
    void initLengths(cv::Mat &image);
    // Calculate the positions where the faces will be drawed on the canvas
    void generateFacePositions();
    // Draw the cube's faces
    void drawFaces(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap);
public:
    // assigns a 3-component (BGR) cv color to the default color enum
    static std::map<CellColor , cv::Scalar> mDefaultColorMap;
};

#endif //RUBIC_SOLVER_CUBEDRAWER2D_H
