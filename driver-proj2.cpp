/*
 * CSI 3334
 * Project 2 - Shortest-path word-melt solver
 * Filename: driver-proj2.cpp
 * Name: Isaac Marsh
 *
 * This file holds logic to find the shortest path
 *
 */

#include <iostream>
#include <map>
#include <stack>

#include "arrayqueue-student-proj2.h"
#include "location-proj2.h"
#include "maze-proj2.h"

using namespace std;

int main() {
    map<Location, Location> map;
    ArrayQueue<Location> queue;
    Maze maze;

    cin >> maze;
    assert(maze.isValidLocation(maze.getStartLocation()));

    if(maze.isEndLocation(maze.getStartLocation())){
        cout << "Solution found:" << endl;
        cout << maze.getStartLocation() << endl;
        return 0;
    }


    Location curr;
    curr = maze.getStartLocation();
    queue.add(curr);
    map[curr] = curr;

    curr.start();

    while(queue.getLength() != 0) {
        Location neighbor;
        neighbor = curr.nextNeighbor();

        if (maze.isValidLocation(neighbor) && (map.find(neighbor) == map.end())) {
            map[neighbor] = curr;
            queue.add(neighbor);
        }

        if(maze.isEndLocation(neighbor) && maze.isValidLocation(neighbor)){
            cout << "Solution found:" << endl;
            curr = neighbor;
            stack<Location> solution;
            solution.push(curr);
            while(!(map[curr] == curr)){
                solution.push(map[curr]);
                curr = map[curr];
            }
            while(!solution.empty()){
                cout << solution.top() << endl;
                solution.pop();
            }

            return 0;
        }

        if(curr.isDone()){
            queue.remove();
            curr = queue.getFront();
            curr.start();
        }
    }

    cout << "No solution found" << endl;


    return 0;
}
