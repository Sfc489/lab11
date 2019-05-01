/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2019
 *
 * @file LinkedList.h
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief Linked List specification.
 */

#ifndef LAB11_LINKEDLIST_H
#define LAB11_LINKEDLIST_H

#include "List.h"
#include "LinkedIterator.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"


template<class Object>
class LinkedList : public List<Object> {
private:
    Node<Object> *headPtr; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int itemCount;           // Current count of list items

    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<Object> *getNodeAt(int position) const;

public:
    LinkedList();

    LinkedList(const LinkedList<Object> &aList);

    virtual ~LinkedList();

    bool isEmpty() const override;

    int getLength() const override;

    bool insert(int newPosition, const Object &newEntry) override;

    bool remove(int position) override;

    void clear() override;

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    Object getEntry(int position) const throw(PrecondViolatedExcep) override;

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    void replace(int position, const Object &newEntry) throw(PrecondViolatedExcep) override;

    // Iterators
    LinkedIterator<Object> begin();

    LinkedIterator<Object> end();

}; // end LinkedList


#endif //LAB11_LINKEDLIST_H
