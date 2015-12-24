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

//
// Represents a virtual Rubik's cube, consisting of faces and cells in different colors.
// It has a current configuration which is either 'solved' or not, and it allows transformations.
// The transformations are reflected in the change of the colors of the cells.
//
class Cube {

};


#endif //RUBIC_SOLVER_CUBE_H
