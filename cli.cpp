#include <expected>
#include <iostream>
#include <sstream>
#include <string>

#include "TaskManager.h"

std::expected<std::string, std::string> formatChecker ( std::string name ) {
    if ( name == "" ) {
        return std::unexpected (
            "Ooops, it seems like you ran 'add' command incorrectly. Please try again by following this example: add "
            "\"Fix the bug\" 2" );
    }
    return name;
}

int main () {
    std::string input, name, trash;
    TaskManager tm;
    std::string command;
    int ID = 0, priority;

    const auto& tasks = tm.listTask ();

    while ( true ) {
        std::cout << "> ";
        std::getline ( std::cin, input );

        std::stringstream ss ( input );
        ss >> command;

        if ( command == "exit" || command == "bye" )
            break;

        else if ( command == "list" ) {
            for ( const auto& task : tasks ) {
                std::cout << "ID: " << task.first << "\nName: " << task.second.getName ()
                          << "\nPriority: " << task.second.getPriority () << std::endl;
            }
        }

        else if ( command == "add" ) {
            std::getline ( ss, trash, '"' );
            std::getline ( ss, name, '"' );
            ss >> priority;

            auto result = formatChecker ( name );

            if ( !result ) {
                std::cerr << result.error () << "\n";
            } else if ( ss.fail () ) {
                std::cerr << "Priority number is missing.\n";
            } else {
                tm.addTask ( name, priority );
                std::cout << "Task added!\n";
            }

        }

        else if ( command == "complete" ) {
            ss >> ID;
            if ( ID > 0 && tm.completeTask ( ID ) ) {
                std::cout << "Task with ID number: " << ID << " is completed!\n";
            } else {
                std::cout << "Task with ID number: " << ID << " not found\n";
            }
        }
    }
}