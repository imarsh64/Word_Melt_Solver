/*
 * CSI 3334
 * Project 2 - Shortest-path word-melt solver
 * Filename: location-proj2.cpp
 * Name: Isaac Marsh
 *
 * This file creates a way to store locations and
 * cycle through the neighbors
 *
 */

#include "location-proj2.h"


/*
 * Location
 *
 * Default constructor sets values for iterationMode, indexToChange,
 * and nextLetter
 *
 * Parameters:
 *  NONE
 *
 * Return value: none
 */
Location::Location(){
    iterationMode = DONE;
    indexToChange = 0;
    nextLetter = 'a';
}

/*
 * start
 *
 * Sets the iteration mode to the first iteration method
 *
 * Parameters:
 *  NONE
 *
 * Return value: none
 */
void Location::start(void){
    iterationMode = CHANGE_LETTER;
}


/*
 * nextNeighbor
 *
 * Finds the next neighbor to be visited
 *
 * Parameters:
 *  NONE
 *
 * Return value: the location of the next neighbor
 */
Location Location::nextNeighbor(void){
    const int CHAR_LENGTH = 1;
    Location neighbor;
    neighbor.word = this->word;

    switch(iterationMode){
        case CHANGE_LETTER:
            neighbor.word[indexToChange] = nextLetter;
            nextLetter++;
            if(neighbor.word == word && nextLetter <= 'z'){
                neighbor.word[indexToChange] = nextLetter;
                nextLetter++;
            }

            if(nextLetter > 'z'){
                indexToChange++;
                nextLetter = 'a';
            }
            if(indexToChange >= word.size()){
                iterationMode++;
                nextLetter = 'a';
                indexToChange = 0;
            }
            break;
        case INSERT_LETTER:
            neighbor.word.insert(indexToChange, CHAR_LENGTH, nextLetter);
            nextLetter++;
            if(nextLetter > 'z'){
                indexToChange++;
                nextLetter = 'a';
            }
            if(indexToChange > word.size()){
                iterationMode++;
                nextLetter = 'a';
                indexToChange = 0;
            }

            break;
        case DELETE_LETTER:
            neighbor.word.erase(indexToChange, CHAR_LENGTH);
            indexToChange++;
            if(indexToChange >= word.size()){
                iterationMode++;
            }
            break;
    }
    return neighbor;
}

/*
 * isDone
 *
 * Checks if all the neighbors have been iterated through
 *
 * Parameters:
 *  NONE
 *
 * Return value: true if every neighbor is visited
 *               and false if not
 */
bool Location::isDone(void) const{
    return iterationMode == DONE;
}

/*
 * operator==
 *
 * Checks to see if 2 locations store the same word
 *
 * Parameters:
 *  loc: the Location object that is being compared to this
 *
 * Return value: true if loc is equivalent to this
 *               and false if not
 */
bool Location::operator==(const Location &loc) const{
    return this->word == loc.word;
}

/*
 * operator<<
 *
 * outputs the word in the location to a given stream
 *
 * Parameters:
 *  os: Stream that the location is written to
 *  loc: the Location object that will be pushed to the os
 *
 * Return value: the given stream to allow chaining
 */
ostream &operator<<(ostream &os, const Location &loc){
    os << loc.word;
    return os;
}

/*
 * operator>>
 *
 * sets a location's word from an input stream
 *
 * Parameters:
 *  is: Stream that info is being read from
 *  loc: the Location object that will change values based on input stream
 *
 * Return value: the given stream to allow chaining
 */
istream &operator>>(istream &is, Location &loc){
    is >> loc.word;
    return is;
}

/*
 * operator<
 *
 * compares 2 locations to keep them in order
 *
 * Parameters:
 *  loc: the Location object that is compared to this
 *
 * Return value: true if the word from loc is greater than
 *               word stored in this and false if not
 */
bool Location::operator<(const Location &loc) const{
    return this->word < loc.word;
}
