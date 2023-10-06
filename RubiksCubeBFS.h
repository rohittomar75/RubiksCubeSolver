//
// Created by Rohit
//

#include<bits/stdc++.h>
#include"GenericRubiksCube.h"

#ifndef RUBIKSCUBE_RUBIKSCUBEBFS_H
#define RUBIKSCUBE_RUBIKSCUBEBFS_H

template<typename T, typename H>
class RubiksCubeBFS {
    private:
        vector<RubiksCube::MOVE> moves;
        unordered_map<T, bool, H> visited;
        unordered_map<T, RubiksCube::MOVE, H> backptr;

        // bfs to find the minimum number of moves to solve the cube
        T bfs() {
            queue<T> q;
            q.push(rubikscube);
            visited[rubikscube] = true;
            while (!q.empty()) {
                T state = q.front();
                q.pop();
                if (state.is_solved()) return state;
                for (int i = 0; i < 18; i++) {
                    RubiksCube::MOVE curr = RubiksCube::MOVE (i);
                    state.move(curr);
                    if (!visited[state]) {
                        visited[state] = true;
                        q.push(state);
                        backptr[state] = curr;
                    }
                    state.invert(curr);
                }
            }
            return rubikscube;
        }


    public:
        T rubikscube;

        RubiksCubeBFS(T _rubikscube) {
            rubikscube = _rubikscube;
        }
        // returns the moves to perform to solve the cube
        vector<RubiksCube::MOVE> solve() {
            T solved_cube = bfs();
            assert(solved_cube.is_solved());
            T curr_cube = solved_cube;
            while (!(curr_cube == rubikscube)) {
                RubiksCube::MOVE curr_move = backptr[curr_cube];
                moves.push_back(curr_move);
                curr_cube.invert(curr_move);
            }
            rubikscube = solved_cube;
            reverse(moves.begin(), moves.end());
            return moves;
        }
};


#endif //RUBIKSCUBE_RUBIKSCUBEBFS_H
