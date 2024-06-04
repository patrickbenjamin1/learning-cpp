#ifndef CONTROLLER_DEF
#define CONTROLLER_DEF

#include <string>

class Controller
{
public:
    virtual void write(std::string text);
    virtual std::string read();
};

#endif // CONTROLLER_DEF