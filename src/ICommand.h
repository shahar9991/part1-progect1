// ICommand.h
#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>

class ICommand {
public:
    virtual void execute(const std::string& url) = 0;
    virtual ~ICommand() {}
};

#endif // ICOMMAND_H
