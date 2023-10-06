//
// Created by Rohit
//

#ifndef RUBIKSCUBE_GENERICRUBIKSCUBE_H
#define RUBIKSCUBE_GENERICRUBIKSCUBE_H

#include<bits/stdc++.h>
using namespace std;

class RubiksCube {
public:

    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LP, L2,
        R, RP, R2,
        U, UP, U2,
        D, DP, D2,
        F, FP, F2,
        B, BP, B2
    };

    // 18 possibe operations on any cube
    // rotate front face clcokwise once
    virtual RubiksCube& F() = 0;

    // rotate front face anticlockwise
    virtual RubiksCube& FP() = 0;

    // rotate front face clockwise two times
    virtual RubiksCube& F2() = 0;

    // rotate up face clcokwise once
    virtual RubiksCube& U() = 0;

    // rotate up face anticlockwise
    virtual RubiksCube& UP() = 0;

    // rotate up face clockwise two times
    virtual RubiksCube& U2() = 0;

    // rotate left face clcokwise once
    virtual RubiksCube& L() = 0;

    // rotate left face anticlockwise
    virtual RubiksCube& LP() = 0;

    // rotate left face clockwise two times
    virtual RubiksCube& L2() = 0;

    // rotate down face clcokwise once
    virtual RubiksCube& D() = 0;

    // rotate down face anticlockwise
    virtual RubiksCube& DP() = 0;

    // rotate down face clockwise two times
    virtual RubiksCube& D2() = 0;

    // rotate right face clcokwise once
    virtual RubiksCube& R() = 0;

    // rotate right face anticlockwise
    virtual RubiksCube& RP() = 0;

    // rotate right face clockwise two times
    virtual RubiksCube& R2() = 0;

    // rotate back face clcokwise once
    virtual RubiksCube& B() = 0;

    // rotate back face anticlockwise
    virtual RubiksCube& BP() = 0;

    // rotate back face clockwise two times
    virtual RubiksCube& B2() = 0;


    // function to print the Rubiks Cube
    void print() const; // constant member function -> can't change data members


    // function to check if Rubiks Cube is solved or not
    virtual bool is_solved() const = 0;

    // performs a move on Rubiks Cube
    RubiksCube& move(MOVE mv);

    // inverts a move on Rubiks Cube
    RubiksCube& invert(MOVE mv);

    // randomly shuffle the Rubiks Cube t times and return the moves
    vector<MOVE> randomShuffle(int t);


    // returns the color of the given cubie
    virtual COLOR getColor(FACE face, int row, int col) const = 0;

    // returns the letter associated with color
    // RED -> R, BLUE -> B ...
    char getColorLetter(COLOR color) const;

    // retruns string containing move
    // U -> U, RP -> RP, D2 -> D2
    string getMove(MOVE mv) const;

};

#endif //RUBIKSCUBE_GENERICRUBIKSCUBE_H