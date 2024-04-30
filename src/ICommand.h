// ICommand.h
#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>

class ICommand {
public:
    virtual std::string execute(const std::string& url) = 0;
    virtual ~ICommand() {}
};

#endif // ICOMMAND_H
