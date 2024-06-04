#ifndef CONTROLLER_DEF
#define CONTROLLER_DEF

#include <string>

class Controller
{
public:
    Controller();
    virtual void write(std::string text);
    virtual std::string read();
    virtual void wait(int ms);
};

#endif // CONTROLLER_DEF