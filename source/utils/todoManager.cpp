#include <vector>

#include "./todoManager.h"

TodoManager::TodoManager()
{
    this->todos = std::vector<Todo>();
};

TodoManager::~TodoManager()
{
    this->todos.clear();
};

void TodoManager::add(Todo todo)
{
    this->todos.push_back(todo);
};

void TodoManager::remove(int index)
{
    this->todos.erase(this->todos.begin() + index);
};

std::string TodoManager::render()
{
    std::string output = "";

    for (int i = 0; i < this->todos.size(); i++)
    {
        output += std::to_string(i) + ": " + this->todos[i].render() + "\n";
        // c++ newline character
        output += "\n";
    }

    return output;
}

void TodoManager::markComplete(int index)
{
    this->todos[index].markComplete();
}