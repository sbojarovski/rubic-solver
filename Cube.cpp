//
// Created by stefan on 12/24/15.
//

#include <algorithm>

#include "Cube.h"

Cube::Cube() :
        solved  (true),
        valid   (true),
        front   (Cell::CellColor::WHITE),
        back    (Cell::CellColor::YELLOW),
        left    (Cell::CellColor::GREEN),
        right   (Cell::CellColor::BLUE),
        top     (Cell::CellColor::ORANGE),
        bottom  (Cell::CellColor::RED)
{
    // TODO: this is a bit ugly, I want to have a container for the faces
    // so that I can iterate them functional programming style, but I also
    // want to have distinctive names for them for the transformations

    faces.push_back(&front);
    faces.push_back(&back);
    faces.push_back(&left);
    faces.push_back(&right);
    faces.push_back(&top);
    faces.push_back(&bottom);
    rotationsMap[ FRONT_CW  ] = &frontCW;
    rotationsMap[ FRONT_CCW ] = &frontCCW;
    rotationsMap[ BACK_CW   ] = &backCW;
    rotationsMap[ BACK_CCW  ] = &backCCW;
    rotationsMap[ LEFT_CW   ] = &leftCW;
    rotationsMap[ LEFT_CCW  ] = &leftCCW;
    rotationsMap[ RIGHT_CW  ] = &rightCW;
    rotationsMap[ RIGHT_CCW ] = &rightCCW;
    rotationsMap[ TOP_CW    ] = &topCW;
    rotationsMap[ TOP_CCW   ] = &topCCW;
    rotationsMap[ BOTTOM_CW ] = &bottomCW;
    rotationsMap[ BOTTOM_CCW] = &bottomCCW;
}

void Cube::transform(const CubeTransforms &transform) {
    rotationsMap[transform]();
}

bool Cube::isValid() const {
    // are the center cells the same color as the face
    bool centerCorrect = areCenterCellsCorrect();
    // are there exactly nine cells of each color
    bool nineOfEach = areNinePerColor();
    return centerCorrect && nineOfEach;
}

void Cube::scramble() {
// generate a number of random transformations and apply them
}

void Cube::solve() {
// maybe with backtracking?
}

bool Cube::isSolved() const {
    std::vector<bool> isFaceSolved;
    //map
    std::transform(faces.begin(), faces.end(),
                   std::back_inserter(isFaceSolved),
                    [](const CubeFace * f){return f->isSolved();});
    bool allFacesSolved = false;
    //reduce
    allFacesSolved = std::accumulate(isFaceSolved.begin(), isFaceSolved.end(),
                                    true,
                                     [](bool current, bool next){return current && next;});
    return  allFacesSolved;
}

bool Cube::areCenterCellsCorrect() const {
    std::vector<bool> areCentersCorrect;
    // map: are all the center cells the valid color
    std::transform(faces.begin(), faces.end(),
                   std::back_inserter(areCentersCorrect),
                   [](const CubeFace * f){return f->isCenterCorrect();});
    bool centersCorrect = false;
    //reduce
    centersCorrect = std::accumulate(areCentersCorrect.begin(), areCentersCorrect.end(),
                                     true,
                                     [](bool current, bool next){return current && next;});
    return  centersCorrect;
}

bool Cube::areNinePerColor() const {
    std::vector<int> colorHistogram(6);
    for (auto&& f : faces)
    {
        for (auto&& c : f->getCells())
        {
            colorHistogram[c->getColor()]++;
        }
    }
    // as long as the adjacent elements are the same
    // it moves along the vector
    bool allEqual = std::adjacent_find(colorHistogram.begin(),
                                       colorHistogram.end(),
                                       std::not_equal_to<int>())
                    == colorHistogram.end();
    allEqual = allEqual && (colorHistogram[0] == 9);
    return allEqual;
}

void Cube::frontCW() {
    front.rotateCW();

    CubeFace::CellVector oldTop3 = top.getRow(3);
    top.setRow(3, left.getColumn(3));
    left.setColumn(3, bottom.getRow(1));
    bottom.setRow(1, right.getColumn(1));
    right.setColumn(1, oldTop3);
}

void Cube::frontCCW() {
    front.rotateCCW();

    CubeFace::CellVector oldTop3 = top.getRow(3);
    top.setRow(3, right.getColumn(1));
    right.setColumn(1, bottom.getColumn(1));
    bottom.setRow(1, left.getColumn(3));
    left.setColumn(3, oldTop3);
}

void Cube::backCW() {
    back.rotateCW();

    CubeFace::CellVector oldTop1 = top.getRow(1);
    top.setRow(1, left.getColumn(1));
    left.setColumn(1, bottom.getRow(3));
    bottom.setRow(3, right.getColumn(3));
    right.setColumn(3, oldTop1);
}

void Cube::backCCW() {
    back.rotateCCW();

    CubeFace::CellVector oldTop1 = top.getRow(1);
    top.setRow(1, right.getColumn(3));
    right.setColumn(3, bottom.getRow(3));
    bottom.setRow(3, left.getColumn(1));
    left.setColumn(1, oldTop1);
}

void Cube::leftCW() {
    left.rotateCW();

    CubeFace::CellVector oldTop1 = top.getColumn(1);
    top.setColumn(1, back.getColumn(1));
    back.setColumn(1, bottom.getColumn(1));
    bottom.setColumn(1, front.getColumn(1));
    front.setColumn(1, oldTop1);
}

void Cube::leftCCW() {
    left.rotateCCW();

    CubeFace::CellVector oldTop1 = top.getColumn(1);
    top.setColumn(1, front.getColumn(1));
    front.setColumn(1, bottom.getColumn(1));
    bottom.setColumn(1, back.getColumn(1));
    back.setColumn(1, oldTop1);
}

void Cube::rightCW() {
    right.rotateCW();

    CubeFace::CellVector oldTop3 = top.getColumn(3);
    top.setColumn(3, front.getColumn(3));
    front.setColumn(3, bottom.getColumn(3));
    bottom.setColumn(3, back.getColumn(3));
    back.setColumn(3, oldTop3);
}

void Cube::rightCCW() {
    right.rotateCCW();

    CubeFace::CellVector oldTop3 = top.getColumn(3);
    top.setColumn(3, back.getColumn(3));
    back.setColumn(3, bottom.getColumn(3));
    bottom.setColumn(3, front.getColumn(3));
    front.setColumn(3, oldTop3);
}

void Cube::topCW() {
    top.rotateCW();

    CubeFace::CellVector oldFront1 = front.getRow(1);
    front.setRow(1, right.getRow(1));
    right.setRow(1, back.getRow(1));
    back.setRow(1, left.getRow(1));
    left.setRow(1, oldFront1);
}

void Cube::topCCW() {
    top.rotateCCW();

    CubeFace::CellVector oldFront1 = front.getRow(1);
    front.setRow(1, left.getRow(1));
    left.setRow(1, back.getRow(1));
    back.setRow(1, right.getRow(1));
    right.setRow(1, oldFront1);
}

void Cube::bottomCW() {
    bottom.rotateCW();

    CubeFace::CellVector oldFront3 = front.getRow(3);
    front.setRow(3, left.getRow(3));
    left.setRow(3, back.getRow(3));
    back.setRow(3, right.getRow(3));
    right.setRow(3, oldFront3);
}

void Cube::bottomCCW() {
    bottom.rotateCCW();

    CubeFace::CellVector oldFront3 = front.getRow(3);
    front.setRow(3, left.getRow(3));
    right.setRow(3, back.getRow(3));
    back.setRow(3, left.getRow(3));
    left.setRow(3, oldFront3);
}
