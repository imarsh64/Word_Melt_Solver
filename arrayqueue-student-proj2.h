/*
 * CSI 3334
 * Project 2 - Shortest-path word-melt solver
 * Filename: arrayqueue-student-proj2.h
 * Name: Isaac Marsh
 *
 * This file creates a circular array class
 *
 */

#ifndef ARRAY_QUEUE_STUDENT_PROJ2_H
#define ARRAY_QUEUE_STUDENT_PROJ2_H

#include "arrayqueue-prof-proj2.h"
#include <cassert>

/*
* ArrayQueue
*
* Default constructor sets capacity, length, front, and
* allocates space in data
*
* Parameters:
*  NONE
*
* Return value: none
*/
template <class Base>
ArrayQueue<Base>::ArrayQueue(){
    capacity = 1;
    length = 0;
    front = 0;
    data = new Base[capacity];
}

/*
* ArrayQueue
*
* Default constructor sets capacity, length, front, and
* allocates space in data
*
* Parameters:
*  NONE
*
* Return value: none
*/
template <class Base>
ArrayQueue<Base>::ArrayQueue(const ArrayQueue<Base> &q){
    capacity = q.capacity;
    length   = q.length;
    front    = q.front;

    data = new Base[capacity];

    for(int i = 0; i < capacity; i++){
        data[i] = q.data[i];
    }
}

/*
* ~Maze
*
* Frees up memory allocated by data
*
* Parameters:
*  NONE
*
* Return value: none
*/
template <class Base>
ArrayQueue<Base>::~ArrayQueue(){
    delete [] data;
    data = NULL;
}

/*
* add
*
* Insert a value at the end of the queue and expanding
* capacity if needed
*
* Parameters:
*  item: object to be inserted at the end of the queue
*
* Return value: none
*/
template <class Base>
void ArrayQueue<Base>::add(const Base &item){
    if(length == capacity){
        doubleCapacity();
    }

    data[(front + length) % capacity] = item;
    length++;
}

/*
* remove
*
* Remove an object at the front of the queue
*
* Parameters:
*  NONE
*
* Return value: none
*/
template <class Base>
void ArrayQueue<Base>::remove(){
    length--;
    front = (front + 1) % capacity;
}

/*
* getFront
*
* retrieves the value at the front of the queue
*
* Parameters:
*  NONE
*
* Return value: Object stored at the front of the queue
*/
template <class Base>
const Base& ArrayQueue<Base>::getFront() const{
    return data[front];
}

/*
* getLength
*
* retrieves the length of the queue
*
* Parameters:
*  NONE
*
* Return value: length of queue
*/
template <class Base>
int ArrayQueue<Base>::getLength() const{
    return length;
}

/*
* operator=
*
* assign data members in this to match those in q
*
* Parameters:
*  q: the ArrayQueue to be copied
*
* Return value: the given ArrayQueue
*/
template <class Base>
const ArrayQueue<Base>& ArrayQueue<Base>::operator=(const ArrayQueue<Base> &q){
    if(data != q.data && front != q.front){
        capacity = q.capacity;
        length = q.length;
        front = q.front;

        delete [] data;
        data = new Base[capacity];

        for(int i = 0; i < capacity; i++){
            data[i] = q.data[i];
        }
    }
    return q;
}

/*
* doubleCapacity
*
* Doubles the capacity of the ArrayQueue
*
* Parameters:
*  NONE
*
* Return value: none
*/
template <class Base>
void ArrayQueue<Base>::doubleCapacity() {
    Base *temp = new Base[capacity * 2];
    for(int i = 0; i < length; i++){
        temp[i] = data[(front + i) % capacity];
    }

    delete [] data;

    capacity *= 2;

    data = temp;
    front = 0;
}

#endif

