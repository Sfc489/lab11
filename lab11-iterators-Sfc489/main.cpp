/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2019
 *
 * @file main.cpp
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief Entry point for lab11 target.
 */

#include "lab11.h"

static const std::string SRC_DATA{"srcData.txt"};
static const std::string DEST_DATA{"destData.txt"};
std::ifstream srcData{SRC_DATA};
std::ofstream destData{DEST_DATA};

/**
 * Determine whether the given number is a prime number.
 * @param number the value under interrogation
 * @return true if the given number is prime, false otherwise
 */
bool isPrime(int number) {
    int i;
    if (number < 2) return false;
    for (i = 2; i < number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

void writeOneItem(int object) {
    destData << object << " ";
}

int main() {
    if (!srcData) {
        std::cerr << "Error opening input.dat..." << std::endl;
        return EXIT_FAILURE;
    }

    LinkedList<int> idsList;
    LinkedList<std::string> namesList;
    std::cout << "\nInitially..." << std::endl;
    std::cout << "idsList.getLength() = " << idsList.getLength() << std::endl;
    std::cout << "namesList.getLength() = " << namesList.getLength() << "\n" << std::endl;

    for (int i{1}; i < 5; i++) {
        idsList.insert(i, i * 100);
    }
    idsList.insert(5, 300);

    std::cout << "After adding some numbers, idsList.getLength() = " << idsList.getLength() << std::endl;

    LinkedIterator<int> idsListIterator = idsList.begin();
    while (idsListIterator != idsList.end()) {
        std::cout << *idsListIterator << std::endl;
        ++idsListIterator;
    }

    // Demonstrate use of find algorithm (See C++ Interlude 6)
    LinkedIterator<int> luckyNumber = std::find(idsList.begin(), idsList.end(), 300);
    std::cout << "\nlucky number is: " << *luckyNumber << std::endl;

    // Demonstrate use of count algorithm (See C++ Interlude 6)
    std::cout << "luck number count is: " << std::count(idsList.begin(), idsList.end(), *luckyNumber) << std::endl;

    std::vector<int> numbers;
    int srcNumber;

    // Read input file into a vector for subsequent processing
    while (srcData >> srcNumber) {
        numbers.push_back(srcNumber);
        destData << srcNumber << " ";
    }
    destData << std::endl;

    std::cout << std::endl;
    for (auto number : numbers) {
        std::cout << number << " ";
    }

    // TODO: Using vector<int>::iterator, navigate through the numbers vector to create a LinkedList of prime numbers contained in srcData; name your list primesList
    LinkedList<int> PrimesList;
    std::vector<int>::iterator primesItr = numbers.begin();
    while(primesItr != numbers.end()) {
        //if(numbers.isPrime() == true) {
        //PrimesList.push_back(numbers);
        //}
        ++primesItr;
    }

    // DO NOT MODIFY THE NEXT LINE
    destData << "Primes: ";
    // DO NOT MODIFY THE ABOVE LINE

    // TODO: Using the LinkedIterators from your primesList and the writeOneItem function, write out the prime numbers using the std::for_each() function (see Interlude 6)

    for_each(numbers.begin(), numbers.end(), writeOneItem);
    srcData.close();
    destData.close();

    return EXIT_SUCCESS;
}