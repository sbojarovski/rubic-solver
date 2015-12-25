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
    cells.push_back(&c11);
    cells.push_back(&c12);
    cells.push_back(&c13);
    cells.push_back(&c21);
    cells.push_back(&c22);
    cells.push_back(&c23);
    cells.push_back(&c31);
    cells.push_back(&c32);
    cells.push_back(&c33);
    centerColor = color;
}

void Cube::CubeFace::fill(const Cell::CellColor & color) {
    for (auto & c : cells)
        c->setColor(color);
}

bool Cube::CubeFace::isSolved() const {
    std::vector<bool> isCenterColor;
    // map: are all cells in the face the same (center) color
    std::transform(cells.begin(), cells.end(),
                   std::back_inserter(isCenterColor),
                   [](const Cell * c){return c->getColor() == centerColor;});
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

CellVector
Cube::CubeFace::getCells() const {
    return cells;
}

void Cube::CubeFace::rotateCW() {
    CellVector coll1 = getColumn(1);

    setColumn(3, getRow(1));
    setRow(3, getColumn(3));
    setColumn(1, getRow(3));
    setRow(1, coll1);
}

void Cube::CubeFace::rotateCCW() {
    CellVector row1 = getRow(1);

    setRow(1, getColumn(3));
    setColumn(3, getRow(3));
    setRow(3, getColumn(1));
    setColumn(1, row1);
}

// if I name the rows and cols explicitly, then I have to make sure
// that they are properly updated when I change something?
const CellVector &
Cube::CubeFace::getColumn(const int & i) const {
}

void
Cube::CubeFace::setColumn(const int & i, const CellVector & column) {

}

const CellVector &
Cube::CubeFace::getRow(const int & i) const {
    return <#initializer#>;
}

void
Cube::CubeFace::setRow(const int & i, const CellVector & row) {

}
