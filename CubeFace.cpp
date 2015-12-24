//
// Created by stefan on 12/24/15.
//

#include "Cube.h"
#include "CubeFace.h"
#include "Cell.h"

void CubeFace::fill(const CellColor &color) {
    for (Cell c : cells)
        c.setColor(color);
}