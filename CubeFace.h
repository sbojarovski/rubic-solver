//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CUBEFACE_H
#define RUBIC_SOLVER_CUBEFACE_H

#include "Cell.h"

class CubeFace
{
public:
    void fill(const CellColor & color);
private:
    std::vector<Cell> cells;
};

#include <vector>

#endif //RUBIC_SOLVER_CUBEFACE_H
