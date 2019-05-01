/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2019
 *
 * @file LinkedIterator.h
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief Iterator specification for a LinkedList.
 * @see C++ Interlude 6 for implementation details
 */

#ifndef LAB11_LINKEDITERATOR_H
#define LAB11_LINKEDITERATOR_H

#include <iterator>
#include "Node.h"

template <typename Object>
class LinkedList;

template <typename Object>
class LinkedIterator : public std::iterator<std::input_iterator_tag, int> {
private:
    // ADT associated with iterator
    const LinkedList<Object>* containerPtr;

    // Current location in collection
    Node<Object>* currentItemPtr;

public:
    /**
     *
     * @param someList
     * @param nodePtr
     */
    LinkedIterator(const LinkedList<Object>* someList, Node<Object>* nodePtr);

    /**
     * Dereferencing operator overload.
     * @return the item at the position referenced by the iterator.
     */
    const Object operator*();

    /**
     * Prefix increment operator overload
     * @return the iterator referencing the next position in the list.
     */
    LinkedIterator<Object> operator++();

    /**
     * Equality operator overload.
     * @param rhs the iterator for comparison
     * @return true if this iterator references the same list and the same position as rhs, false otherwise.
     */
    bool operator==(const LinkedIterator<Object>& rhs) const;

    /**
     * Inequality operator overload.
     * @param rhs the iterator for comparison
     * @return true if this iterator does not reference the same list and the same position as rhs, false otherwise.
     */
    bool operator!=(const LinkedIterator<Object> &rhs) const;
};


#endif //LAB11_LINKEDITERATOR_H
