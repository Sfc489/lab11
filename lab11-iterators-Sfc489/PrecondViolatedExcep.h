//
// Created by James Daehn on 2019-04-30.
//

#ifndef LAB11_PRECONDVIOLATEDEXCEP_H
#define LAB11_PRECONDVIOLATEDEXCEP_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error {
public:
    PrecondViolatedExcep(const std::string &message = "");
}; // end PrecondViolatedExcep


#endif //LAB11_PRECONDVIOLATEDEXCEP_H
