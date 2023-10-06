//
// Created by Rohit
//


#include"GenericRubiksCube.h"


// cube[i][j][k] -> color of ith face, jth row and kth col
// UP -> 0 (WHITE)
// LEFT -> 1 (GREEN)
// FRONT -> 2 (RED)
// RIGHT -> 3 (BLUE)
// BACK -> 4 (ORANGE)
// DOWN -> 5 (YELLOW)

class RubiksCube3D : public RubiksCube {
    private:
        // rotate the given face of Rubiks Cube clockwise
        void rotateFace(int face) {
            char grid[3][3];
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    grid[row][col] = cube[face][row][col];
                }
            }
            for (int i = 0; i < 3; i++) {
                cube[face][0][i] = grid[2 - i][0];
            }
            for (int i = 0; i < 3; i++) {
                cube[face][i][2] = grid[0][i];
            }
            for (int i = 0; i < 3; i++) {
                cube[face][2][2 - i] = grid[i][2];
            }
            for (int i = 0; i < 3; i++) {
                cube[face][2 - i][0] = grid[2][2 - i];
            }
        }

    public:
        char cube[6][3][3]; // to store Rubiks Cube

        // creating a new solved Rubiks Cube
        RubiksCube3D() {
            for (int face = 0; face < 6; face++) {
                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        cube[face][row][col] = getColorLetter(COLOR(face));
                    }
                }
            }
        }

        // overriding the getColor method in Base Class
        COLOR getColor(FACE face, int row, int col) const override {
            if (cube[(int) face][row][col] == 'R') return COLOR::RED;
            if (cube[(int) face][row][col] == 'B') return COLOR::BLUE;
            if (cube[(int) face][row][col] == 'W') return COLOR::WHITE;
            if (cube[(int) face][row][col] == 'Y') return COLOR::YELLOW;
            if (cube[(int) face][row][col] == 'G') return COLOR::GREEN;
            if (cube[(int) face][row][col] == 'O') return COLOR::ORANGE;
        }

        // overriding the is_solved method
        bool is_solved() const override {
            for (int face = 0; face < 6; face++) {
                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        if (cube[face][row][col] == getColorLetter(COLOR(face))) continue;
                        return false;
                    }
                }
            }
            return true;
        }

        // clockwise rotation of upper face
        RubiksCube& U() override {
            this->rotateFace(0);

            char temp[3];
            for (int i = 0; i < 3; i++) temp[i] = cube[4][0][i];
            for (int i = 0; i < 3; i++) cube[4][0][i] = cube[1][0][i];
            for (int i = 0; i < 3; i++) cube[1][0][i] = cube[2][0][i];
            for (int i = 0; i < 3; i++) cube[2][0][i] = cube[3][0][i];
            for (int i = 0; i < 3; i++) cube[3][0][i] = temp[i];
            return *this;
        }

        // clockwise rotation of left face
        RubiksCube& L() override {
            this->rotateFace(1);

            char temp[3];
            for (int i = 0; i < 3; i++) temp[i] = cube[0][i][0];
            for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
            for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
            for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
            for (int i = 0; i < 3; i++) cube[2][i][0] = temp[i];
            return *this;
        }

        // clockwise rotation of front face
        RubiksCube& F() override {
            this->rotateFace(2);

            char temp[3];
            for (int i = 0; i < 3; i++) temp[i] = cube[0][2][i];
            for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
            for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
            for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
            for (int i = 0; i < 3; i++) cube[3][i][0] = temp[i];
            return *this;
        }

        // clockwise rotation of right face
        RubiksCube& R() override {
            this->rotateFace(3);

            char temp[3];
            for (int i = 0; i < 3; i++) temp[i] = cube[0][2 - i][2];
            for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
            for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
            for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
            for (int i = 0; i < 3; i++) cube[4][i][0] = temp[i];
            return *this;
        }

        // clockwise rotation of back face
        RubiksCube& B() override {
            this->rotateFace(4);

            char temp[3];
            for (int i = 0; i < 3; i++) temp[i] = cube[0][0][2 - i];
            for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
            for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
            for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
            for (int i = 0; i < 3; i++) cube[1][i][0] = temp[i];
            return *this;
        }

        // clockwise rotation of down face
        RubiksCube& D() override {
            this->rotateFace(5);

            char temp[3];
            for (int i = 0; i < 3; i++) temp[i] = cube[2][2][i];
            for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
            for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
            for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
            for (int i = 0; i < 3; i++) cube[3][2][i] = temp[i];
            return *this;
        }

        // anti - clockwise rotations
        RubiksCube& UP() override {
            this->U();
            this->U();
            this->U();
            return *this;
        }

        RubiksCube& LP() override {
            this->L();
            this->L();
            this->L();
            return *this;
        }

        RubiksCube& FP() override {
            this->F();
            this->F();
            this->F();
            return *this;
        }

        RubiksCube& RP() override {
            this->R();
            this->R();
            this->R();
            return *this;
        }

        RubiksCube& BP() override {
            this->B();
            this->B();
            this->B();
            return *this;
        }

        RubiksCube& DP() override {
            this->D();
            this->D();
            this->D();
            return *this;
        }

        // double rotations
        RubiksCube& U2() override {
            this->U();
            this->U();
            return *this;
        }

        RubiksCube& L2() override {
            this->L();
            this->L();
            return *this;
        }

        RubiksCube& F2() override {
            this->F();
            this->F();
            return *this;
        }

        RubiksCube& R2() override {
            this->R();
            this->R();
            return *this;
        }

        RubiksCube& B2() override {
            this->B();
            this->B();
            return *this;
        }

        RubiksCube& D2() override {
            this->D();
            this->D();
            return *this;
        }

        // overloading the == operator
        bool operator==(const RubiksCube3D &obj) const {
            for (int face = 0; face < 6; face++){
                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        if (cube[face][row][col] != obj.cube[face][row][col]) return false;
                    }
                }
            }
            return true;
        }

        // overlaoding the = operator
        RubiksCube3D& operator=(const RubiksCube3D &obj) {
            for (int face = 0; face < 6; face++) {
                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        cube[face][row][col] = obj.cube[face][row][col];
                    }
                }
            }
            return *this;
        }
};

struct Hash3D {
    size_t operator()(const RubiksCube3D &obj) const {
        string s = "";
        for (int face = 0; face < 6; face++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    s += obj.cube[face][row][col];
                }
            }
        }
        return hash<string>()(s);
    }

};