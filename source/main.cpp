#include <iostream>

#include "./utils/console.h"
#include "./utils/todoManager.h"

TodoManager *todoManager = new TodoManager();

void run()
{
    Console::WriteLine("Here are your todos:");

    const std::string output = todoManager->render();
    Console::WriteLine(output.c_str());

    Console::WriteLine("What would you like to do?");
    Console::WriteLine("1. add todo");
    Console::WriteLine("2. complete todo");
    Console::WriteLine("3. close");

    const std::string action = Console::Read(256);
    Console::WriteLine();

    if (action == "1")
    {
        Console::WriteLine("Enter a todo...");
        const std::string todoText = Console::Read(256);
        Console::WriteLine();

        Console::WriteLine("Enter a due year...");
        const std::string dueYear = Console::Read(256);
        Console::WriteLine();

        Console::WriteLine("Enter a due month...");
        const std::string dueMonth = Console::Read(256);
        Console::WriteLine();

        Console::WriteLine("Enter a due day...");
        const std::string dueDay = Console::Read(256);
        Console::WriteLine();

        Date date = Date({std::stoi(dueYear), std::stoi(dueMonth), std::stoi(dueDay)});

        Todo todo = Todo(todoText, date);

        todoManager->add(todo);

        run();
    }
    else if (action == "2")
    {
        Console::WriteLine("Enter the index of the todo you would like to complete...");
        const std::string index = Console::Read(256);
        Console::WriteLine();

        todoManager->markComplete(std::stoi(index));

        run();
    }
    else if (action == "3")
    {
        Console::WriteLine("Goodbye!");
    }
    else
    {
        Console::WriteLine("Invalid action, try again");
        run();
    }
}

int main()
{
    run();
    return 0;
}