//
//  main.cpp
//  A2
//
//  Created by Fernando Juarez on 9/25/19.
//  Copyright © 2019 Fernando Juarez. All rights reserved.
//

#include <cstring>
#include <iostream>
#include "Shell.h"
int main() {
    Shell osh;
    
    while (osh.running) {
        char buffer[MAXLINE];                    // command buffer
        char buffer_save[MAXLINE];                // used to save the command
        char * args[MAXLINE / 2 + 1];            // arguments of the command.
        
        std::cout << "osh> ";
        std::cout.flush();
        
        std::cin.getline(buffer, MAXLINE);        // reads command from input.
        strcpy(buffer_save, buffer);            // copy the buffer
        
        osh.parseline(buffer, args);            // buffer parses into arguments.
        
        if (osh.isUserCommand(args)) {
            osh.execUserCommand(args);            // command is user command.
        }
        
        else {
            osh.saveCommand(buffer_save);        // save command if shell command.
            osh.execShellCommand(args);            // command is shell command.
        }
    }
    
    return 0;
}
