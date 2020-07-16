//
//  Shell.hpp
//  A2
//
//  Created by Fernando Juarez on 9/25/19.
//  Copyright © 2019 Fernando Juarez. All rights reserved.
//

#pragma once
#include <vector>

const int MAXLINE = 80;                                    // max length command

// Implementation of shell
class Shell {
public:
    bool running;                                        // if program should run
    void parseline(char buffer[], char * args[]);        // parses the command into arguments.
    void execShellCommand(char * args[]);                // executes shell command.
    void execUserCommand(char * arg[]);                    // executes user command.
    void saveCommand(char command[]);                    // saves the command into a history list.
    bool isUserCommand(char * arg[]);                    // checks if command is either user or shell command.
    Shell();                                            // default constructor.
    
private:
    std::vector<std::string> history;                    // command history list.
    bool ampersand;                                        // if command contains ampersand.
    void displayHistory();                                // displays command history list.
};
