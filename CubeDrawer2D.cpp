//
// Created by stefan on 12/27/15.
//

#include <opencv2/imgproc.hpp>
#include "CubeDrawer2D.h"

std::map<CellColor , cv::Scalar> CubeDrawer2D::mDefaultColorMap;

CubeDrawer2D::CubeDrawer2D(const Cube &cube) {
    mDefaultColorMap[CellColor::WHITE ] = cv::Scalar(255, 255, 255);
    mDefaultColorMap[CellColor::YELLOW] = cv::Scalar(  0, 255, 255);
    mDefaultColorMap[CellColor::BLUE  ] = cv::Scalar(  0,   0, 255);
    mDefaultColorMap[CellColor::GREEN ] = cv::Scalar(  0, 255,   0);
    mDefaultColorMap[CellColor::ORANGE] = cv::Scalar(255,  50,  50);
    mDefaultColorMap[CellColor::RED   ] = cv::Scalar(255,   0,   0);

    std::vector<CellColor > colors = cube.getState();
    this->front.c11.mColor = mDefaultColorMap[colors[0]];
    this->front.c12.mColor = mDefaultColorMap[colors[1]];
    this->front.c13.mColor = mDefaultColorMap[colors[2]];
    this->front.c21.mColor = mDefaultColorMap[colors[3]];
    this->front.c22.mColor = mDefaultColorMap[colors[4]];
    this->front.c23.mColor = mDefaultColorMap[colors[5]];
    this->front.c31.mColor = mDefaultColorMap[colors[6]];
    this->front.c32.mColor = mDefaultColorMap[colors[7]];
    this->front.c33.mColor = mDefaultColorMap[colors[8]];

    this->back.c11.mColor = mDefaultColorMap[colors[9]];
    this->back.c12.mColor = mDefaultColorMap[colors[10]];
    this->back.c13.mColor = mDefaultColorMap[colors[11]];
    this->back.c21.mColor = mDefaultColorMap[colors[12]];
    this->back.c22.mColor = mDefaultColorMap[colors[13]];
    this->back.c23.mColor = mDefaultColorMap[colors[14]];
    this->back.c31.mColor = mDefaultColorMap[colors[15]];
    this->back.c32.mColor = mDefaultColorMap[colors[16]];
    this->back.c33.mColor = mDefaultColorMap[colors[17]];

    this->left.c11.mColor = mDefaultColorMap[colors[18]];
    this->left.c12.mColor = mDefaultColorMap[colors[19]];
    this->left.c13.mColor = mDefaultColorMap[colors[20]];
    this->left.c21.mColor = mDefaultColorMap[colors[21]];
    this->left.c22.mColor = mDefaultColorMap[colors[22]];
    this->left.c23.mColor = mDefaultColorMap[colors[23]];
    this->left.c31.mColor = mDefaultColorMap[colors[24]];
    this->left.c32.mColor = mDefaultColorMap[colors[25]];
    this->left.c33.mColor = mDefaultColorMap[colors[26]];

    this->right.c11.mColor = mDefaultColorMap[colors[27]];
    this->right.c12.mColor = mDefaultColorMap[colors[28]];
    this->right.c13.mColor = mDefaultColorMap[colors[29]];
    this->right.c21.mColor = mDefaultColorMap[colors[30]];
    this->right.c22.mColor = mDefaultColorMap[colors[31]];
    this->right.c23.mColor = mDefaultColorMap[colors[32]];
    this->right.c31.mColor = mDefaultColorMap[colors[33]];
    this->right.c32.mColor = mDefaultColorMap[colors[34]];
    this->right.c33.mColor = mDefaultColorMap[colors[35]];

    this->top.c11.mColor = mDefaultColorMap[colors[36]];
    this->top.c12.mColor = mDefaultColorMap[colors[37]];
    this->top.c13.mColor = mDefaultColorMap[colors[38]];
    this->top.c21.mColor = mDefaultColorMap[colors[39]];
    this->top.c22.mColor = mDefaultColorMap[colors[40]];
    this->top.c23.mColor = mDefaultColorMap[colors[41]];
    this->top.c31.mColor = mDefaultColorMap[colors[42]];
    this->top.c32.mColor = mDefaultColorMap[colors[43]];
    this->top.c33.mColor = mDefaultColorMap[colors[44]];

    this->bottom.c11.mColor = mDefaultColorMap[colors[45]];
    this->bottom.c12.mColor = mDefaultColorMap[colors[46]];
    this->bottom.c13.mColor = mDefaultColorMap[colors[47]];
    this->bottom.c21.mColor = mDefaultColorMap[colors[48]];
    this->bottom.c22.mColor = mDefaultColorMap[colors[49]];
    this->bottom.c23.mColor = mDefaultColorMap[colors[50]];
    this->bottom.c31.mColor = mDefaultColorMap[colors[51]];
    this->bottom.c32.mColor = mDefaultColorMap[colors[52]];
    this->bottom.c33.mColor = mDefaultColorMap[colors[53]];
}

void CubeDrawer2D::draw(cv::Mat *image, const std::map<CellColor , cv::Scalar> & colorMap) {
    initLengths(image);
    generateFacePositions();
    drawFaces(image, colorMap);
}

void CubeDrawer2D::initLengths(cv::Mat *image) {
    // take the width of the image
    int imWidth = image->cols;
    // take out a margin of X = 10 pixels from each side
    mCanvasMargin = 10;
    mOrigin = cv::Point2i(mCanvasMargin, mCanvasMargin);
    // divide the resulting length into 4
    mFaceCanvasSize = ((imWidth - 2 * mCanvasMargin) / 4);
}

void CubeDrawer2D::generateFacePositions() {
    front.setOrigin( cv::Point2i(mOrigin.x +     mFaceCanvasSize, mOrigin.y + mFaceCanvasSize));
    back.setOrigin(  cv::Point2i(mOrigin.x + 3 * mFaceCanvasSize, mOrigin.y + mFaceCanvasSize));
    left.setOrigin(  cv::Point2i(mOrigin.x + 2 * mFaceCanvasSize, mOrigin.y + mFaceCanvasSize));
    right.setOrigin( cv::Point2i(mOrigin.x +     mFaceCanvasSize, mOrigin.y));
    top.setOrigin(   cv::Point2i(mOrigin.x +     mFaceCanvasSize, mOrigin.y));
    bottom.setOrigin(cv::Point2i(mOrigin.x +     mFaceCanvasSize, mOrigin.y + 2 * mFaceCanvasSize));

    front.setSize(mFaceCanvasSize);
    back.setSize(mFaceCanvasSize);
    left.setSize(mFaceCanvasSize);
    right.setSize(mFaceCanvasSize);
    top.setSize(mFaceCanvasSize);
    bottom.setSize(mFaceCanvasSize);
}

void CubeDrawer2D::drawFaces(cv::Mat * image, const std::map<CellColor , cv::Scalar> & colorMap) {
    front.draw(image, colorMap);
    back.draw(image, colorMap);
    left.draw(image, colorMap);
    right.draw(image, colorMap);
    top.draw(image, colorMap);
    bottom.draw(image, colorMap);
}

void Face2D::setOrigin(const cv::Point2i &orig) {
    mOrigin = cv::Point2i(orig.x + mInnerMargin, orig.y + mInnerMargin);
}

void Face2D::draw(cv::Mat *image, const std::map<CellColor, cv::Scalar> &colorMap) {
    initCells();
    drawCells(image, colorMap);
}

void Face2D::initCells() {
    c11.setOrigin(mOrigin); c11.setSize(mSize / 3);
    c12.setOrigin(mOrigin); c12.setSize(mSize / 3);
    c13.setOrigin(mOrigin); c13.setSize(mSize / 3);
    c21.setOrigin(mOrigin); c21.setSize(mSize / 3);
    c22.setOrigin(mOrigin); c22.setSize(mSize / 3);
    c23.setOrigin(mOrigin); c23.setSize(mSize / 3);
    c31.setOrigin(mOrigin); c31.setSize(mSize / 3);
    c32.setOrigin(mOrigin); c32.setSize(mSize / 3);
    c33.setOrigin(mOrigin); c33.setSize(mSize / 3);
}

void Face2D::drawCells(cv::Mat *image, const std::map<CellColor, cv::Scalar> &colorMap) {
    c11.draw(image, colorMap);
    c12.draw(image, colorMap);
    c13.draw(image, colorMap);
    c21.draw(image, colorMap);
    c22.draw(image, colorMap);
    c23.draw(image, colorMap);
    c31.draw(image, colorMap);
    c32.draw(image, colorMap);
    c33.draw(image, colorMap);
}

void Face2D::setSize(const int &size) {
    mSize = size;
}

void Cell2D::draw(cv::Mat *image, const std::map<CellColor, cv::Scalar> &colorMap) {
    cv::rectangle(*image, mOrigin, cv::Point2i(mOrigin.x + mSize, mOrigin.y + mSize), mColor);
}

void Cell2D::setOrigin(cv::Point2i &orig) {
    mOrigin = cv::Point2i(orig.x + mInnerCellMargin, orig.y + mInnerCellMargin);
}

void Cell2D::setSize(const int &size) {
    mSize = size - 2 * mInnerCellMargin;
}
