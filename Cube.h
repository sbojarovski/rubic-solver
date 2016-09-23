//
// Created by stefan on 12/24/15.
//

#ifndef RUBIC_SOLVER_CUBE_H
#define RUBIC_SOLVER_CUBE_H

#include <vector>
#include <map>

//
// Defines the default colors for the cube
//
enum CellColor
{
    UNKNOWN = 0,
    WHITE = 1,
    YELLOW = 2,
    GREEN = 3,
    BLUE = 4,
    ORANGE = 5,
    RED = 6
};

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
    typedef void(Cube::*transformPtr)();
private:
    // TODO: do these have to be pointers?
    CubeFace * front;
    CubeFace * back;
    CubeFace * left;
    CubeFace * right;
    CubeFace * top;
    CubeFace * bottom;

    bool solved;
    bool valid;

    std::vector<CubeFace *> faces;

    static std::map<CubeTransforms , Cube::transformPtr> rotationsMap;

    std::vector<CubeTransforms> transformLog;

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
    // Warning:   Since this is not a physical model of a cube
    //            the number of colors can be correct, however
    //            the cube might still be in an incorrect state.
    bool isValid() const;
    // Returns true if the cube is solved. Solved means each cell in a face is the same color
    // and each face is a unique color.
    bool isSolved() const;
    // Scramble the faces of the cube
    void scramble(const int & steps);
    // Get a random transformation of the cube's faces
    static const CubeTransforms getRandomTransform();
    static const std::vector<CubeTransforms > getRandomTransformVec(const int & n = 1);

    // Solve the cube
    void solve();
    // Returns true if the centers of the cube are the correct color. They should never change.
    bool areCenterCellsCorrect() const;

    // Returns true if there are exactly 9 cells of each color.
    bool areNinePerColor() const;

    // Returns the colors of the cells in the following order:
    //      front, back, left, right, top bottom
    const std::vector<CellColor> getState() const;
};


#endif //RUBIC_SOLVER_CUBE_H
