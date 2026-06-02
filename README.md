# CLI TASK MANAGER

## What it does?

* Creates tasks
* Shows a list of tasks
* Completes the tasks
* Writes down completed tasks in completed.txt file

## How to build
Requirements: g++ 13 or higher with C++23 support

git clone <CLI-task-manager>
cd cli-task-manager
g++ -std=c++23 -o taskmanager cli.cpp

## How to use
Run the program:
./taskmanager

Then type commands:
```
>add "Fix the bug" 2
Task added!

>list
ID: 1
Name: Fix the bug
Priority: 2

>complete 1
Task with ID number: 1 is completed!

>list

>bye
```

## Commands

1. add "task name" priority number (For adding tasks)
2. list (To show a list of tasks)
3. complete id of a task (To complete a task)
4. bye or exit (To exit the program)

## Notes

completed.txt creates automatically even if you don't have it or deleted it, the previously completed tasks remain there, they're not overriden.
