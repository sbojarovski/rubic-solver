//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CUBE_H
#define RUBIC_SOLVER_CUBE_H

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

enum CubeFacePosition
{
    FRONT,
    BACK,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};

class CellPosition
{
private:
    CubeFacePosition face;
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
private:
    CellColor color;
    CellPosition position;
};

//
// Represents a virtual Rubik's cube, consisting of faces and cells in different colors.
// It has a current configuration which is either 'solved' or not, and it allows transformations.
// The transformations are reflected in the change of the colors of the cells.
//
class Cube
{
private:
    CubeFace front;
    CubeFace back;
    CubeFace left;
    CubeFace right;
    CubeFace top;
    CubeFace bottom;
public:
    bool isSolved();
    void scramble();
    void solve();
};


#endif //RUBIC_SOLVER_CUBE_H
