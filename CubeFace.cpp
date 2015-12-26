//
// Created by stefan on 12/24/15.
//
#include <algorithm>
#include <assert.h>
#include "CubeFace.h"
#include "Cell.h"

Cube::CubeFace::CubeFace(CellColor color)
        :c11(new Cell(color)),
         c12(new Cell(color)),
         c13(new Cell(color)),
         c21(new Cell(color)),
         c22(new Cell(color)),
         c23(new Cell(color)),
         c31(new Cell(color)),
         c32(new Cell(color)),
         c33(new Cell(color))
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

void Cube::CubeFace::fill(const CellColor & color) {
    for (auto & c : cells)
        c->setColor(color);
}

bool Cube::CubeFace::isSolved() const {
    std::vector<bool> isCenterColor;
    // map: are all cells in the face the same (center) color
    std::transform(cells.begin(), cells.end(),
                   std::back_inserter(isCenterColor),
                   [this](Cell * c){return c->getColor() == centerColor;});
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
    return c22->getColor() == centerColor;
}

const Cube::CubeFace::CellVector &
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
const Cube::CubeFace::CellVector
Cube::CubeFace::getColumn(const int & i) const {
    assert(i >= 1 && i <= 3);
    // TODO: warning returning ref to temp
    switch(i){
        case 1  :
            return CellVector{c11, c21, c31};
        case 2  :
            return CellVector{c12, c22, c32};
        case 3  :
            return CellVector{c13, c23, c33};
        default :
            return CellVector{};
    }
}

void
Cube::CubeFace::setColumn(const int & i, const CellVector & column) {
    switch(i){
        case 1  :
            c11->setColor(column.at(0)->getColor());
            c21->setColor(column.at(1)->getColor());
            c31->setColor(column.at(2)->getColor());
            break;
        case 2  :
            c12->setColor(column.at(0)->getColor());
            c22->setColor(column.at(1)->getColor());
            c32->setColor(column.at(2)->getColor());
            break;
        case 3  :
            c13->setColor(column.at(0)->getColor());
            c23->setColor(column.at(1)->getColor());
            c33->setColor(column.at(2)->getColor());
            break;
        default :
            return;
    }
}

const Cube::CubeFace::CellVector
Cube::CubeFace::getRow(const int & i) const {
    assert(i >= 1 && i <= 3);
    switch(i){
        case 1  :
            return CellVector{c11, c12, c13};
        case 2  :
            return CellVector{c21, c22, c23};
        case 3  :
            return CellVector{c31, c32, c33};
        default :
            return CellVector{};
    }
}

void
Cube::CubeFace::setRow(const int & i, const CellVector & row) {
    switch(i){
        case 1  :
            c11->setColor(row.at(0)->getColor());
            c12->setColor(row.at(1)->getColor());
            c13->setColor(row.at(2)->getColor());
            break;
        case 2  :
            c21->setColor(row.at(0)->getColor());
            c22->setColor(row.at(1)->getColor());
            c23->setColor(row.at(2)->getColor());
            break;
        case 3  :
            c31->setColor(row.at(0)->getColor());
            c32->setColor(row.at(1)->getColor());
            c33->setColor(row.at(2)->getColor());
            break;
        default :
            return;
    }
}
