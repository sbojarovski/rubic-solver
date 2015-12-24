//
// Created by stefan on 12/24/15.
//

#include "Cell.h"

Cell::Cell(const int &row, const int &column, const CellColor &color)
{
    position.row    = row;
    position.column = column;
    this->color = color;
}
