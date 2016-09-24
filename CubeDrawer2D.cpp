//
// Created by stefan on 12/27/15.
//

#include <opencv2/imgproc.hpp>
#include "CubeDrawer2D.h"

// cv::Scalar is actually BGR
std::map<CellColor , cv::Scalar> CubeDrawer2D::mDefaultColorMap =
    {{CellColor::WHITE , cv::Scalar(255, 255, 255)},
    {CellColor::YELLOW, cv::Scalar(  0, 255, 255)},
    {CellColor::BLUE  , cv::Scalar(255,   0,   0)},
    {CellColor::GREEN , cv::Scalar(  0, 255,   0)},
    {CellColor::ORANGE, cv::Scalar(  0, 150, 255)},
    {CellColor::RED   , cv::Scalar(  0,   0, 255)}};

CubeDrawer2D::CubeDrawer2D(const Cube &cube) :mCube(&cube) {

}

void CubeDrawer2D::updateCube() {
    std::vector<CellColor > colors = mCube->getState();

    int fCount = 0;
    for (auto f : mFaces)
    {
        int cCount = 0;
        for (auto c : f->mCells)
        {
            c->mColor = mDefaultColorMap[colors[fCount * 9 + cCount]];
            ++cCount;
        }
        ++fCount;
    }
}

void CubeDrawer2D::draw(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap) {
    initLengths(image);
    generateFacePositions();

    updateCube();

    drawFaces(image, colorMap);
}

void CubeDrawer2D::initLengths(cv::Mat &image) {
    // take the width of the image
    int imWidth = image.cols;
    // take out a margin of X = 10 pixels from each side
    mCanvasMargin = 10;
    mOrigin = cv::Point2i(mCanvasMargin, mCanvasMargin);
    // divide the resulting length into 4
    mFaceCanvasSize = ((imWidth - 2 * mCanvasMargin) / 4);
}

void CubeDrawer2D::generateFacePositions() {
    front.setOrigin( cv::Point2i(mOrigin.x +     mFaceCanvasSize, mOrigin.y +     mFaceCanvasSize));
    back.setOrigin(  cv::Point2i(mOrigin.x + 3 * mFaceCanvasSize, mOrigin.y +     mFaceCanvasSize));
    left.setOrigin(  cv::Point2i(mOrigin.x                      , mOrigin.y +     mFaceCanvasSize));
    right.setOrigin( cv::Point2i(mOrigin.x + 2 * mFaceCanvasSize, mOrigin.y +     mFaceCanvasSize));
    top.setOrigin(   cv::Point2i(mOrigin.x +     mFaceCanvasSize, mOrigin.y                      ));
    bottom.setOrigin(cv::Point2i(mOrigin.x +     mFaceCanvasSize, mOrigin.y + 2 * mFaceCanvasSize));

    for(auto f : mFaces)
    {
        f->setSize(mFaceCanvasSize);
    }
}

void CubeDrawer2D::drawFaces(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap) {
    for(auto f : mFaces)
    {
        f->draw(image, colorMap);
    }
}

void Face2D::setOrigin(const cv::Point2i &orig) {
    mOrigin = cv::Point2i(orig.x + mInnerMargin, orig.y + mInnerMargin);
}

void Face2D::draw(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap) {
    initCells();
    drawCells(image, colorMap);
}

void Face2D::initCells() {
    int cellSize = mSize / 3;
    c11.setOrigin(mOrigin.x               , mOrigin.y               ); c11.setSize(cellSize);
    c12.setOrigin(mOrigin.x +     cellSize, mOrigin.y               ); c12.setSize(cellSize);
    c13.setOrigin(mOrigin.x + 2 * cellSize, mOrigin.y               ); c13.setSize(cellSize);
    c21.setOrigin(mOrigin.x               , mOrigin.y +     cellSize); c21.setSize(cellSize);
    c22.setOrigin(mOrigin.x +     cellSize, mOrigin.y +     cellSize); c22.setSize(cellSize);
    c23.setOrigin(mOrigin.x + 2 * cellSize, mOrigin.y +     cellSize); c23.setSize(cellSize);
    c31.setOrigin(mOrigin.x               , mOrigin.y + 2 * cellSize); c31.setSize(cellSize);
    c32.setOrigin(mOrigin.x +     cellSize, mOrigin.y + 2 * cellSize); c32.setSize(cellSize);
    c33.setOrigin(mOrigin.x + 2 * cellSize, mOrigin.y + 2 * cellSize); c33.setSize(cellSize);
}

void Face2D::drawCells(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap) {

    for(auto c : mCells)
    {
        c->draw(image, colorMap);
    }
}

void Face2D::setSize(const int &size) {
    mSize = size;
}

void Cell2D::draw(cv::Mat &image, const std::map<CellColor, cv::Scalar> &colorMap) {
    cv::rectangle(image, mOrigin, cv::Point2i(mOrigin.x + mSize, mOrigin.y + mSize), mColor, CV_FILLED);
}
void Cell2D::setOrigin(const int & x, const int & y) {
    mOrigin.x = x;
    mOrigin.y = y;
}

void Cell2D::setOrigin(cv::Point2i &orig) {
    mOrigin = cv::Point2i(orig.x + mInnerCellMargin, orig.y + mInnerCellMargin);
}

void Cell2D::setSize(const int &size) {
    mSize = size - 2 * mInnerCellMargin;
}
