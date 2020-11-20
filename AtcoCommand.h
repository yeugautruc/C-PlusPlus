#pragma once
#include <string>
#include "FileName.h"
#include "Command.h"

class AtcoCommand
{
private:
    /* data */
    std::string fileName;
    std::string wordSequence;
    Command *commands;
    int sizeCommands;
    std::string date;
    std::string time;
    DateTime formattedDateTime;
    void resizeCommand(Command *&inputArray, int &oldSize, int &newSize);
public:
    AtcoCommand();

    AtcoCommand(std::string fileNameInput, std::string wordSequenceInput, std::string commandsInput);

    void readCommands(std::string commandsInput);

    void readDateTime(std::string input);

    std::string toString();


    const std::string getWordSequence();

    Command getcommands(int k);
    
    const int getSizeCommands();

    const std::string getDate();

    const std::string getTime();

    DateTime getFormattedDateTime();

    ~AtcoCommand();
};