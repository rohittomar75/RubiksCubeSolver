//
// created by Rohit
//

#include<bits/stdc++.h>
using namespace std;

#include"RubiksCube3D.cpp"
#include"RubiksCubeBFS.h"

int main() {
    RubiksCube3D cube;
    cube.print();

    vector<RubiksCube::MOVE> shuffmoves = cube.randomShuffle(6);
    cout << "Moves to randomly shuffle the cube: ";
    for (auto &ele : shuffmoves) cout << cube.getMove(ele) << " ";
    cout << "\n";
    cout << "Randomly shuffled cube: " << "\n";
    cube.print();

    RubiksCubeBFS<RubiksCube3D, Hash3D> bfssolve(cube);
    vector<RubiksCube::MOVE> moves = bfssolve.solve();
    cout << "Moves to solve the cube are: " << moves.size() << "\n";
    for (auto &ele : moves) cout << cube.getMove(ele) << " ";
    cout << "\n";
    bfssolve.rubikscube.print();
}