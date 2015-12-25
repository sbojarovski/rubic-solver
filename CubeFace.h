//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CUBEFACE_H
#define RUBIC_SOLVER_CUBEFACE_H

#include <vector>
#include "Cube.h"
#include "Cell.h"

class Cube::CubeFace
{
private:
    class Cell;

    std::vector<Cell &> cells;
    Cell::CellColor centerColor;
    Cell c11;
    Cell c12;
    Cell c13;
    Cell c21;
    Cell c22;
    Cell c23;
    Cell c31;
    Cell c32;
    Cell c33;

public:
    void CubeFace(const Cell::CellColor & color);
    void fill(const Cell::CellColor & color);
    void rotateCW();
    void rotateCCW();
    std::vector<Cell &> & getColumn(const int & i) const;
    void setColumn(const int & i, std::vector<Cell &> & column);
    std::vector<Cell &> & getRow(const int & i) const;
    void setRow(const int & i, std::vector<Cell &> & row);
    bool isSolved() const;
    bool isCenterCorrect() const;
    const std::vector<Cell &> &getCells() const;
};

#endif //RUBIC_SOLVER_CUBEFACE_H
