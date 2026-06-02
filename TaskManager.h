#pragma once

#include <expected>
#include <fstream>
#include <map>
#include <string>

#include "Task.h"

class TaskManager {
   private:
    std::map<int, Task> tasks;
    int ID = 1;
    std::ofstream outfile;

    std::expected<bool, std::string> saveCompleted ( int id ) {
        if ( !outfile.is_open () ) {
            return std::unexpected ( "Failed to open the txt file." );
        }
        const Task& task = tasks.at ( id );
        outfile << "ID: " << id << "\tName: " << task.getName () << "\t\tPriority: " << task.getPriority () << "\n";
        return true;
    }

   public:
    TaskManager () : outfile ( "completed.txt", std::ios::app ) {}

    void addTask ( const std::string& name, int priority ) {
        tasks.emplace ( std::piecewise_construct, std::forward_as_tuple ( ID ),
                        std::forward_as_tuple ( name, priority ) );
        ID += 1;
    }

    const std::map<int, Task>& listTask () const { return tasks; }

    bool completeTask ( int id ) {
        if ( tasks.find ( id ) != tasks.end () ) {
            auto result = saveCompleted ( id );
            if ( !result ) {
                std::cerr << "Error: " << result.error () << "\n";
                return false;
            }
            tasks.erase ( id );

        } else {
            return false;
        }
        return true;
    }
};