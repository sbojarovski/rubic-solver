//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CELL_H
#define RUBIC_SOLVER_CELL_H

#include "CubeFace.h"

//
// A cell is one face of a piece.
// In the world, cells are of fixed color and they belong to one unique piece.
// Then the pieces move around, and the cells and colors with them.
// Here, I consider a cell to have a fixed position and a floating color.
//

class Cube::CubeFace::Cell
{
public:
    typedef CellColor Color;
    Cell(const Color & color);
    void setColor(const Color &color);
    const Color &getColor() const;

protected:
    Color color;
};

#endif //RUBIC_SOLVER_CELL_H
