//
// Created by Rohit
//

#include "GenericRubiksCube.h"


char RubiksCube::getColorLetter(COLOR color) const {
    if (color == COLOR::RED) return 'R';
    if (color == COLOR::WHITE) return 'W';
    if (color == COLOR::YELLOW) return 'Y';
    if (color == COLOR::GREEN) return 'G';
    if (color == COLOR::BLUE) return 'B';
    return 'O';
}

string RubiksCube::getMove(MOVE mv) const {
    if (mv == MOVE::F) return "F";
    if (mv == MOVE::FP) return "FP";
    if (mv == MOVE::F2) return "F2";
    if (mv == MOVE::U) return "U";
    if (mv == MOVE::UP) return "UP";
    if (mv == MOVE::U2) return "U2";
    if (mv == MOVE::L) return "L";
    if (mv == MOVE::LP) return "LP";
    if (mv == MOVE::L2) return "L2";
    if (mv == MOVE::D) return "D";
    if (mv == MOVE::DP) return "DP";
    if (mv == MOVE::D2) return "D2";
    if (mv == MOVE::R) return "R";
    if (mv == MOVE::RP) return "RP";
    if (mv == MOVE::R2) return "R2";
    if (mv == MOVE::B) return "B";
    if (mv == MOVE::BP) return "BP";
    if (mv == MOVE::B2) return "B2";
}

RubiksCube& RubiksCube::move(MOVE mv) {
    if (mv == MOVE::F) return this->F();
    if (mv == MOVE::FP) return this->FP();
    if (mv == MOVE::F2) return this->F2();
    if (mv == MOVE::U) return this->U();
    if (mv == MOVE::UP) return this->UP();
    if (mv == MOVE::U2) return this->U2();
    if (mv == MOVE::L) return this->L();
    if (mv == MOVE::LP) return this->LP();
    if (mv == MOVE::L2) return this->L2();
    if (mv == MOVE::D) return this->D();
    if (mv == MOVE::DP) return this->DP();
    if (mv == MOVE::D2) return this->D2();
    if (mv == MOVE::R) return this->R();
    if (mv == MOVE::RP) return this->RP();
    if (mv == MOVE::R2) return this->R2();
    if (mv == MOVE::B) return this->B();
    if (mv == MOVE::BP) return this->BP();
    if (mv ==MOVE::B2) return this->B2();
}

RubiksCube& RubiksCube::invert(MOVE mv) {
    if (mv == MOVE::F) return this->FP();
    if (mv == MOVE::FP) return this->F();
    if (mv == MOVE::F2) return this->F2();
    if (mv == MOVE::U) return this->UP();
    if (mv == MOVE::UP) return this->U();
    if (mv == MOVE::U2) return this->U2();
    if (mv == MOVE::L) return this->LP();
    if (mv == MOVE::LP) return this->L();
    if (mv == MOVE::L2) return this->L2();
    if (mv == MOVE::D) return this->DP();
    if (mv == MOVE::DP) return this->D();
    if (mv == MOVE::D2) return this->D2();
    if (mv == MOVE::R) return this->RP();
    if (mv == MOVE::RP) return this->R();
    if (mv == MOVE::R2) return this->R2();
    if (mv == MOVE::B) return this->BP();
    if (mv == MOVE::BP) return this->B();
    if (mv ==MOVE::B2) return this->B2();
}

void RubiksCube::print() const {
    for (int row = 0; row < 3; row++) {
        for (int i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int row = 0; row < 3; row++) {
        for (int i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col < 3; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


vector<RubiksCube::MOVE> RubiksCube::randomShuffle(int t) {
    vector<MOVE> moves;
    srand(time(0));
    for (int i = 0; i < t; i++) {
        int move_made = rand() % 18;
        moves.push_back(static_cast<MOVE>(move_made)); // err...........
        this->move(static_cast<MOVE>(move_made));
    }
    return moves;
}