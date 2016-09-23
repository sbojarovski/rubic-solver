//
// Created by stefan on 12/24/15.
//

#include <assert.h>
#include "Cell.h"

Cube::CubeFace::Cell::Cell(const CellColor &color)
        :color(CellColor::UNKNOWN)
{
    assert(color <= 0 && color <= 6);
    this->color = color;
}

void Cube::CubeFace::Cell::setColor(const CellColor &color) {
    assert(color <= 0 && color <= 6);
    this->color = color;
}

const CellColor & Cube::CubeFace::Cell::getColor() const  {
    return this->color;
}

