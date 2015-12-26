//
// Created by stefan on 12/24/15.
//

#include "Cell.h"

Cube::CubeFace::Cell::Cell(const CellColor &color)
        :color(CellColor::UNKNOWN)
{
    //TODO: assert color inside enum range
    this->color = color;
}

void Cube::CubeFace::Cell::setColor(const CellColor &color) {
    this->color = color;
}

const CellColor & Cube::CubeFace::Cell::getColor() const  {
    return this->color;
}

