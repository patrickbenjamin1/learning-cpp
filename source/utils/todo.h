#include <string>

#include "./date.h"

#ifndef TODO_DEFS

#define TODO_DEFS

class Todo
{
private:
    std::string text;
    Date createdDate;
    Date dueDate;
    bool complete;

public:
    Todo(std::string text, Date dueDate);

    std::string getText();

    Date getCreatedDate();

    Date getDueDate();

    bool isOverdue();

    std::string render();

    void markComplete();

    bool isComplete();
};

#endif