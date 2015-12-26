//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CUBEFACE_H
#define RUBIC_SOLVER_CUBEFACE_H

#include <vector>

#include "Cube.h"

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

class Cube::CubeFace
{
public:
    class Cell;
public:
    typedef std::vector<CubeFace::Cell *> CellVector;
private:
    CellVector cells;
    CellColor centerColor;
    CubeFace::Cell * c11;
    CubeFace::Cell * c12;
    CubeFace::Cell * c13;
    CubeFace::Cell * c21;
    CubeFace::Cell * c22;
    CubeFace::Cell * c23;
    CubeFace::Cell * c31;
    CubeFace::Cell * c32;
    CubeFace::Cell * c33;

public:
    CubeFace(CellColor color);
    void fill(const CellColor & color);
    void rotateCW();
    void rotateCCW();
    const CellVector getColumn(const int & i) const;
    void setColumn(const int & i, const CellVector & column);
    const CellVector getRow(const int & i) const;
    void setRow(const int & i, const CellVector & row);
    bool isSolved() const;
    bool isCenterCorrect() const;
    const CellVector & getCells() const;
};

#endif //RUBIC_SOLVER_CUBEFACE_H
