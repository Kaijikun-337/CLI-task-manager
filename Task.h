#pragma once

#include <string>

class Task {
   private:
    std::string name;
    int priority;

   public:
    Task ( const std::string& taskName, int numPriority ) : name ( taskName ), priority ( numPriority ) {}

    const std::string& getName () const { return name; }

    int getPriority () const { return priority; }
};