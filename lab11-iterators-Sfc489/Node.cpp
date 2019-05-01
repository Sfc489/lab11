//
// Created by James Daehn on 2019-04-30.
//

#include "Node.h"

template<typename Object>
Node<Object>::Node() : value{Object{}}, nextPtr{nullptr} {

}

template<typename Object>
Node<Object>::Node(Object value) : value{value}, nextPtr{nullptr} {

}

template<typename Object>
Node<Object>::Node(Object value, Node<Object>* nextPtr) : value{value}, nextPtr{nextPtr} {

}

template<typename Object>
Object Node<Object>::getItem() const {
    return value;
}

template<typename Object>
void Node<Object>::setItem(const Object &value) {
    Node<Object>::value = value;
}

template<typename Object>
Node<Object>* Node<Object>::getNext() const {
    return nextPtr;
}

template<typename Object>
void Node<Object>::setNext(Node<Object>* nextPtr) {
    Node<Object>::nextPtr = nextPtr;
}
