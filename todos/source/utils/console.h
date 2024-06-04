#ifndef CONSOLE_CLASS_DEF

#define CONSOLE_CLASS_DEF

#include <iostream>

class Console
{
public:
    static void Write(const char *message);

    static void WriteLine(const char *message);

    static void WriteLine(const std::string *message);

    static void WriteLine();

    static std::string Read(int size);
};

#endif