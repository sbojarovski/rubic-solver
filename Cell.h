//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CELL_H
#define RUBIC_SOLVER_CELL_H

#include <assert.h>

enum CellColor
{
    UNKNOWN = 0,
    WHITE,
    YELLOW,
    BLUE,
    GREEN,
    ORANGE,
    RED
};

//
// A cell is one face of a piece.
// In the world, cells are of fixed color and they belong to one unique piece.
// Then the pieces move around, and the cells and colors with them.
// Here, I consider a cell to have a fixed position and a floating color.
//
class Cell
{
public:
    Cell(const CellColor & color);

    void setColor(const CellColor &color) {
        Cell::color = color;
    }

    const CellColor &getColor() const {
        return color;
    }

private:
    CellColor color;
};

#endif //RUBIC_SOLVER_CELL_H
