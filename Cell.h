//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CELL_H
#define RUBIC_SOLVER_CELL_H

enum CellColor
{
    UNKNOWN = -1,
    WHITE,
    YELLOW,
    BLUE,
    GREEN,
    ORANGE,
    RED
};

class CellPosition
{
private:
    int row;
    int column;
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
    void setPosition(const CellPosition &position) {
        Cell::position = position;
    }

    const CellPosition &getPosition() const {
        return position;
    }
    void setColor(const CellColor &color) {
        Cell::color = color;
    }

    const CellColor &getColor() const {
        return color;
    }

private:
    CellPosition position;
    CellColor color;
};

#endif //RUBIC_SOLVER_CELL_H
