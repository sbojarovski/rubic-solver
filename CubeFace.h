//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CUBEFACE_H
#define RUBIC_SOLVER_CUBEFACE_H

#include <vector>
#include "Cell.h"

class CubeFace
{
public:
    void CubeFace(const CellColor & color);
    void fill(const CellColor & color);
    bool isSolved() const;
    bool isCenterCorrect() const;
    const std::vector<Cell &> &getCells() const {
        return cells;
    }

private:
    std::vector<Cell &> cells;
    CellColor centerColor;
    Cell c11;
    Cell c12;
    Cell c13;
    Cell c21;
    Cell c22;
    Cell c23;
    Cell c31;
    Cell c32;
    Cell c33;
};

#endif //RUBIC_SOLVER_CUBEFACE_H
