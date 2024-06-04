#include "./consoleController.h"
#include "../utils/console.h"

std::string ConsoleController::read()
{
    return Console::Read(255);
}

void ConsoleController::write(std::string text)
{
    Console::WriteLine(text.c_str());
}