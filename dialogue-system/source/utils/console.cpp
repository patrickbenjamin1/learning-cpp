#include <iostream>
#include <thread>

#include "console.h"

void Console::Write(const char *message)
{
    std::cout << message;
}

void Console::WriteLine(const char *message)
{
    std::cout << message << std::endl;
}

// add an empty line
void Console::WriteLine()
{
    std::cout << std::endl;
}

void Console::WriteLine(const std::string *message)
{
    std::cout << message << std::endl;
}

std::string Console::Read(int size)
{
    char buffer[size];
    std::cin.getline(buffer, size);

    std::string result(buffer);
    return result;
}

void Console::Wait(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}