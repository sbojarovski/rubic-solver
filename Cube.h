//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CUBE_H
#define RUBIC_SOLVER_CUBE_H

#include <vector>
#include <map>

enum CubeTransforms
{
    FRONT_CW = 1,
    FRONT_CCW,
    BACK_CW,
    BACK_CCW,
    LEFT_CW,
    LEFT_CCW,
    RIGHT_CW,
    RIGHT_CCW,
    TOP_CW,
    TOP_CCW,
    BOTTOM_CW,
    BOTTOM_CCW
};

//
// Represents a virtual Rubik's cube, consisting of faces and cells in different colors.
// It has a current configuration which is either 'solved' or not, and it allows transformations.
// The transformations are reflected in the change of the colors of the cells.
//
class Cube
{
public:
    class CubeFace;

private:
    CubeFace * front;
    CubeFace * back;
    CubeFace * left;
    CubeFace * right;
    CubeFace * top;
    CubeFace * bottom;

    bool solved;
    bool valid;

    std::vector<CubeFace *> faces;

    typedef void(Cube::*transformPtr)();
    static std::map<CubeTransforms , transformPtr> rotationsMap;

    //TODO: write the transforms :)
    void frontCW();
    void frontCCW();
    void backCW();
    void backCCW();
    void leftCW();
    void leftCCW();
    void rightCW();
    void rightCCW();
    void topCW();
    void topCCW();
    void bottomCW();

    void bottomCCW();
public:
    Cube();
    void transform(const CubeTransforms & transform);

    // 9 cells of each color, center pieces all different etc.
    bool isValid() const;
    bool isSolved() const;;
    void scramble(const int & steps);
    const CubeTransforms getRandomTransform() const;

    void solve();
    bool areCenterCellsCorrect() const;

    bool areNinePerColor() const;
};


#endif //RUBIC_SOLVER_CUBE_H
