#ifndef CONSOLE_CONTROLLER_DEF
#define CONSOLE_CONTROLLER_DEF

#include "./controller.h"

class ConsoleController : public Controller
{
public:
    ConsoleController();
    void write(std::string text) override;
    std::string read() override;
    void wait(int ms) override;
};

#endif // CONSOLE_CONTROLLER_DEF