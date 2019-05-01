/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2019
 *
 * @file LinkedIterator.cpp
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief Iterator implementation for a LinkedList.
 * @see C++ Interlude 6 for implementation details
 */


#include "LinkedIterator.h"

template<typename Object>
LinkedIterator<Object>::LinkedIterator(const LinkedList<Object> *someList, Node<Object> *nodePtr) : containerPtr{
        someList}, currentItemPtr{nodePtr} {

}

template<typename Object>
const Object LinkedIterator<Object>::operator*() {
    return currentItemPtr->getItem();
}

template<typename Object>
LinkedIterator<Object> LinkedIterator<Object>::operator++() {
    currentItemPtr = currentItemPtr->getNext();
    return *this;
}

template<typename Object>
bool LinkedIterator<Object>::operator==(const LinkedIterator<Object> &rhs) const {
    return ((containerPtr == rhs.containerPtr) &&
            (currentItemPtr == rhs.currentItemPtr));
}

template<typename Object>
bool LinkedIterator<Object>::operator!=(const LinkedIterator<Object> &rhs) const {
    return ((containerPtr != rhs.containerPtr) ||
            (currentItemPtr != rhs.currentItemPtr));
}
