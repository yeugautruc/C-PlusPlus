#include "Command.h"
#include <string>
#include <ostream>
#include <sstream>
#include <iostream>
#include <fstream>

Command::Command(){

}

Command::Command(std::string input)
{
    commands = input;
    mainCommands = readMainCommand(input);
};

std::string Command::readMainCommand(std::string input)
{
    std::string line;
    std::ifstream myfile("expectedTypes.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (input.find(line) != -1)
            {
                return line;
            }
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open test file " << std::endl;
    }
    return "";
};

const std::string Command::getCommands(){
    return commands;
};
const std::string Command::getMainCommands(){
    return mainCommands;
};

Command::Command(const Command& copy){
    this->commands = copy.commands;
    this->mainCommands = copy.mainCommands;
};

Command::~Command(){

};