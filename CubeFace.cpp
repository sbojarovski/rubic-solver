//
// Created by stefan on 12/24/15.
//
#include <algorithm>
#include "Cube.h"
#include "CubeFace.h"
#include "Cell.h"

CubeFace::CubeFace(const CellColor & color)
        :c11(1, 1, color),
         c12(1, 2, color),
         c13(1, 3, color),
         c21(2, 1, color),
         c22(2, 2, color),
         c23(2, 3, color),
         c31(3, 1, color),
         c32(3, 2, color),
         c33(3, 3, color)
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

void CubeFace::fill(const CellColor & color) {
    for (auto & c : cells)
        c.setColor(color);
}

bool CubeFace::isSolved() const {
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

bool CubeFace::isCenterCorrect() const {
    return c22.getColor() == centerColor;
}
