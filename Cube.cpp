//
// Created by stefan on 12/24/15.
//

#include "Cube.h"
#include "CubeFace.h"
#include "Cell.h"

Cube::Cube() :
        solved(true),
        valid(true)
{
    front.fill(CellColor::WHITE);
    back.fill(CellColor::YELLOW);
    left.fill(CellColor::GREEN);
    right.fill(CellColor::BLUE);
    top.fill(CellColor::ORANGE);
    bottom.fill(CellColor::RED);
}

void Cube::transform(const CubeTransforms &transform) {

}

bool Cube::isValid() const {
    return false;
}

void Cube::scramble() {

}

void Cube::solve() {

}
