//
// Created by stefan on 12/24/15.
//
#include <algorithm>
#include "CubeFace.h"

Cube::CubeFace::CubeFace(const Cell::CellColor & color)
        :c11(color),
         c12(color),
         c13(color),
         c21(color),
         c22(color),
         c23(color),
         c31(color),
         c32(color),
         c33(color)
{
    cells.push_back(c11);
    cells.push_back(c12);
    cells.push_back(c13);
    cells.push_back(c21);
    cells.push_back(c22);
    cells.push_back(c23);
    cells.push_back(c31);
    cells.push_back(c32);
    cells.push_back(c33);
    centerColor = color;
}

void Cube::CubeFace::fill(const Cell::CellColor & color) {
    for (auto & c : cells)
        c.setColor(color);
}

bool Cube::CubeFace::isSolved() const {
    std::vector<bool> isCenterColor;
    // map: are all cells in the face the same (center) color
    std::transform(cells.begin(), cells.end(),
                   std::back_inserter(isCenterColor),
                   [](const Cell & c){return c.getColor() == centerColor;});
    bool solved = false;
    // reduce
    // TODO: solved was not captured, what was that? ([&solved](...){...})
    // TODO: vector<bool> cannot return reference, check into it
    solved = std::accumulate(cells.begin(), cells.end(),
                    true,
                    [](bool current, bool next){return current && next;});
    return solved;
}

bool Cube::CubeFace::isCenterCorrect() const {
    return c22.getColor() == centerColor;
}

const std::vector<Cell &> &Cube::CubeFace::getCells() const {
    return cells;
}

void Cube::CubeFace::rotateCW() {

}

void Cube::CubeFace::rotateCCW() {

}

std::vector<Cell &> &Cube::CubeFace::getColumn(const int &i) const {
    return <#initializer#>;
}

void Cube::CubeFace::setColumn(const int &i, std::vector<Cell &> &column) {

}

std::vector<Cell &> &Cube::CubeFace::getRow(const int &i) const {
    return <#initializer#>;
}

void Cube::CubeFace::setRow(const int &i, std::vector<Cell &> &row) {

}
