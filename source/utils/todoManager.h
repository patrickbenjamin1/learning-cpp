#include <vector>
#include <string>

#include "./todo.h"

#ifndef TODO_MANAGER_DEFS

#define TODO_MANAGER_DEFS

class TodoManager
{
private:
    std::vector<Todo> todos;

public:
    TodoManager();

    ~TodoManager();

    void add(Todo todo);

    void remove(int index);

    std::string render();

    void markComplete(int index);
};

#endif
