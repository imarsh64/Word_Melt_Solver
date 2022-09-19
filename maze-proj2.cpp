/*
 * CSI 3334
 * Project 2 - Shortest-path word-melt solver
 * Filename: maze-proj2.cpp
 * Name: Isaac Marsh
 *
 * This file holds the locations for the given maze.
 *
 */

#include "maze-proj2.h"

/*
 * Maze
 *
 * Objects already have default constructor
 *
 * Parameters:
 *  NONE
 *
 * Return value: none
 */
Maze::Maze(void){}

/*
 * getStartLocation
 *
 * retrieves the starting location of the maze
 *
 * Parameters:
 *  NONE
 *
 * Return value: starting location of maze
 */
Location Maze::getStartLocation(void) const{
    return startLocation;
}

/*
 * isValidLocation
 *
 * Checks to see if given location is in the set of
 * validLocations
 *
 * Parameters:
 *  loc: The Location that is checked for validity
 *
 * Return value: true if loc is in the set and
 *               false if not
 */
bool Maze::isValidLocation(const Location &loc) const{
    return validLocations.find(loc) != validLocations.end();
}

/*
 * isEndLocation
 *
 * Checks to see if a given Location is end location
 *
 * Parameters:
 *  loc: Location given to see if it is the end location
 *
 * Return value: true if loc is the endLocation and
 *               false if not
 */
bool Maze::isEndLocation(const Location &loc) const{
    return loc == endLocation;
}

/*
 * operator>>
 *
 * Provides a way for a Maze object to be filled with values
 * from an input stream
 *
 * Parameters:
 *  is: given input stream that holds the information
 *  m: maze object wanting to be filled
 *
 * Return value: given stream to allow chaining
 */
istream &operator>>(istream &is, Maze &m){
    int dictSize;
    Location word;
    is >> dictSize;

    for(int i = 0; i < dictSize; i++){
        is >> word;
        m.validLocations.insert(word);
    }

    is >> m.startLocation >> m.endLocation;

    return is;
}

