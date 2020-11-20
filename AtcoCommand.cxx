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

AtcoCommand &AtcoCommand::operator=(const AtcoCommand &AtcocommandObject)
{
    if (this != &AtcocommandObject)
    {
        this->commands = AtcocommandObject.commands;
        this->date = AtcocommandObject.date;
        this->time = AtcocommandObject.time;
        this->fileName = AtcocommandObject.fileName;
        this->wordSequence = AtcocommandObject.wordSequence;
        this->formattedDateTime = AtcocommandObject.formattedDateTime;
    };

    return *this;
}

void AtcoCommand::readCommands(std::string commandsInput)
{
    commands = DynCommandArray(1);
     
    std::istringstream f(commandsInput);
    std::string line;
    while (getline(f, line))
    {
        Command cmd = Command(line);
        commands.add(cmd);
    }
   
}

void AtcoCommand::readDateTime(std::string input)
{
    date = input.substr(0, input.find("__"));
    time = input.substr(input.find("__") + 2, input.length()).substr(0, input.substr(input.find("__") + 2, input.length()).find(":"));
}

std::string AtcoCommand::toString()
{
    std::string output = fileName + " \n" + wordSequence + " :\n", command = "";
    for (int i = 0; i < commands.getSize(); i++)
    {
        if (commands.getElementArray(i).getCommands().length() > 10)
        {
            command += commands.getElementArray(i).getCommands() + ";";
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
    return commands.getElementArray(k);
};

const int AtcoCommand::getSizeCommands(){
    return commands.getSize();
};

DateTime AtcoCommand::getFormattedDateTime()
{
    return formattedDateTime;
}