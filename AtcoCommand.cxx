#include "AtcoCommand.h"
#include "FileName.h"
#include "Command.h"
#include <string>
#include <ostream>
#include <sstream>
#include <iostream>
#include <fstream>

AtcoCommand::AtcoCommand()
{
}

AtcoCommand::AtcoCommand(std::string fileNameInput, std::string wordSequenceInput, std::string commandsInput)
{
    readDateTime(fileNameInput);
    formattedDateTime = DateTime(date, time);
    fileName += date + "__" + time + formattedDateTime.toString();
    wordSequence = wordSequenceInput;
    readCommands(commandsInput);
}

void AtcoCommand::readCommands(std::string commandsInput)
{
    sizeCommands = 1;
    commands = new Command[sizeCommands];
    std::istringstream f(commandsInput);
    std::string line;
    while (getline(f, line))
    {
        int newSize = sizeCommands + 1;
        resizeCommand(commands, sizeCommands, newSize);
        Command cmd = Command(line);
        commands[sizeCommands - 1] = cmd;
        sizeCommands++;
    }

}

void AtcoCommand::resizeCommand(Command *&inputArray, int &oldSize, int &newSize)
{
    Command *temp = new Command[oldSize];
    for (int i = 0; i < oldSize; i++)
    {
        temp[i] = inputArray[i];
    }
    delete[] inputArray;

    inputArray = new Command[newSize];
    for (int i = 0; i < oldSize; i++)
    {
        inputArray[i] = temp[i];
    }
    delete[] temp;
};

void AtcoCommand::readDateTime(std::string input)
{
    date = input.substr(0, input.find("__"));
    time = input.substr(input.find("__") + 2, input.length()).substr(0, input.substr(input.find("__") + 2, input.length()).find(":"));
}

std::string AtcoCommand::toString()
{
    std::string output = fileName + " \n" + wordSequence + " :\n", command = "";
    for (int i = 0; i < sizeCommands; i++)
    {
        if (commands[i].getCommands().length() > 10)
        {
            command += commands[i].getCommands() + ";";
        }
    }
    output += command;

    return output;
}

const std::string AtcoCommand::getWordSequence()
{
    return wordSequence;
}
AtcoCommand::~AtcoCommand()
{
}

const std::string AtcoCommand::getDate()
{
    return date;
}
const std::string AtcoCommand::getTime()
{
    return time;
}
Command AtcoCommand::getcommands(int k)
{
    return commands[k];
};

const int AtcoCommand::getSizeCommands(){
    return sizeCommands;
};

DateTime AtcoCommand::getFormattedDateTime()
{
    return formattedDateTime;
}