/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2019
 *
 * @file LinkedList.cpp
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief Linked List implementation.
 */

#include <cassert>
#include "LinkedList.h"

template<class Object>
Node<Object> *LinkedList<Object>::getNodeAt(int position) const {
    // Debugging check of precondition
    assert( (position >= 1) && (position <= itemCount) );

    // Count from the beginning of the chain
    Node<Object>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}

template<class Object>
LinkedList<Object>::LinkedList() : headPtr(nullptr), itemCount(0) {

}

template<class Object>
LinkedList<Object>::LinkedList(const LinkedList<Object> &aList) : itemCount(aList.itemCount) {
    Node<Object> *origChainPtr = aList.headPtr;  // Points to nodes in original chain

    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original list is empty
    else {
        // Copy first node
        headPtr = new Node<Object>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<Object> *newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
        while (origChainPtr != nullptr) {
            // Get next item from original chain
            Object nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<Object> *newNodePtr = new Node<Object>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainPtr->setNext(nullptr);              // Flag end of chain
    }
}

template<class Object>
LinkedList<Object>::~LinkedList() {
    clear();
}

template<class Object>
bool LinkedList<Object>::isEmpty() const {
    return itemCount == 0;
}

template<class Object>
int LinkedList<Object>::getLength() const {
    return itemCount;
}

template<class Object>
bool LinkedList<Object>::insert(int newPosition, const Object &newEntry) {
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<Object>* newNodePtr = new Node<Object>(newEntry);

        // Attach new node to chain
        if (newPosition == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<Object>* prevPtr = getNodeAt(newPosition - 1);

            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }  // end if

        itemCount++;  // Increase count of entries
    }  // end if

    return ableToInsert;
}

template<class Object>
bool LinkedList<Object>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<Object>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to delete
            Node<Object>* prevPtr = getNodeAt(position - 1);

            // Point to node to delete
            curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }  // end if

        // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;  // Decrease count of entries
    }  // end if

    return ableToRemove;
}

template<class Object>
void LinkedList<Object>::clear() {
    while (!isEmpty())
        remove(1);
}

template<class Object>
Object LinkedList<Object>::getEntry(int position) const throw(PrecondViolatedExcep) {
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<Object>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message  = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}

template<class Object>
void LinkedList<Object>::replace(int position, const Object &newEntry) throw(PrecondViolatedExcep) {
// Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
    {
        Node<Object>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    }
    else
    {
        std::string message = "replace() called with an invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}

template<class Object>
LinkedIterator<Object> LinkedList<Object>::begin() {
    return LinkedIterator<Object>(this, headPtr);
}

template<class Object>
LinkedIterator<Object> LinkedList<Object>::end() {
    return LinkedIterator<Object>(this, nullptr);
}
