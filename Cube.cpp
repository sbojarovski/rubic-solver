//
// Created by stefan on 12/24/15.
//

#include <algorithm>

#include "Cube.h"
#include "Cell.h"

Cube::Cube() :
        solved(true),
        valid(true),
        front(CellColor::WHITE),
        back(CellColor::YELLOW),
        left(CellColor::GREEN),
        right(CellColor::BLUE),
        top(CellColor::ORANGE),
        bottom(CellColor::RED)
{
    // TODO: this is a bit ugly, I want to have a container for the faces
    // so that I can iterate them functional programming style, but I also
    // want to have distinctive names for them for the transformations
    faces.push_back(front);
    faces.push_back(back);
    faces.push_back(left);
    faces.push_back(right);
    faces.push_back(top);
    faces.push_back(bottom);
}

void Cube::transform(const CubeTransforms &transform) {

}

bool Cube::isValid() const {
    // are the center cells the same color as the face
    bool centerCorrect = areCenterCellsCorrect();
    // are there exactly nine cells of each color
    bool nineOfEach = areNinePerColor();
    return centerCorrect && nineOfEach;
}

void Cube::scramble() {

}

void Cube::solve() {

}

bool Cube::isSolved() const {
    std::vector<bool> isFaceSolved;
    //map
    std::transform(faces.begin(), faces.end(),
                   std::back_inserter(isFaceSolved),
                    [](const CubeFace & f){return f.isSolved();});
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
                   [](const CubeFace & f){return f.isCenterCorrect();});
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
        for (auto&& c : f.getCells())
        {
            colorHistogram[c.getColor()]++;
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
