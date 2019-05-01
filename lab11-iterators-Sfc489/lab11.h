/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2019
 *
 * @file lab11.h
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief Lab 11 dependencies and expanded templates.
 */

#ifndef CSC232_LAB11_H
#define CSC232_LAB11_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Node.cpp"
#include "LinkedIterator.cpp"
#include "LinkedList.cpp"

template class Node<int>;
template class Node<std::string>;
template class LinkedIterator<int>;
template class LinkedIterator<std::string>;
template class LinkedList<int>;
template class LinkedList<std::string>;

#endif // CSC232_LAB11_H
