//
// Created by stefan on 12/24/15.
//

#include "Cell.h"

Cell::Cell(const CellColor &color):color(CellColor::UNKNOWN)
{
    //TODO: assert color inside enum range
    this->color = color;
}
