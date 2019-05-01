//
// Created by James Daehn on 2019-04-30.
//

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const std::string &message)
        : std::logic_error("Precondition Violated Exception: " + message) {
}  // end constructor