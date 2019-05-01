//
// Created by James Daehn on 2019-04-30.
//

#ifndef LAB11_NODE_H
#define LAB11_NODE_H

template <typename Object>
class Node {
private:
    Object value;
    Node<Object>* nextPtr;
public:
    Node();
    explicit Node<Object>(Object value);
    Node<Object>(Object value, Node<Object>* nextPtr);
    Object getItem() const;
    void setItem(const Object &value);
    Node<Object>* getNext() const;
    void setNext(Node<Object>* nextPtr);
};

#endif //LAB11_NODE_H
