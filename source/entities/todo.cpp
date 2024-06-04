#include <iostream>
#include <string>

#include "./todo.h"

Todo::Todo(std::string text, Date dueDate)
{
    this->text = text;
    this->createdDate = Date();
    this->dueDate = dueDate;
};

std::string Todo::getText()
{
    return this->text;
};

Date Todo::getCreatedDate()
{
    return this->createdDate;
};

Date Todo::getDueDate()
{
    return this->dueDate;
};

bool Todo::isOverdue()
{
    return this->dueDate.getUnix() < (new Date())->getUnix();
};

std::string Todo::render()
{
    std::string output = this->text + " (created: " + this->createdDate.toReadableString() + ", due: " + this->dueDate.toReadableString() + ")";

    if (this->isComplete())
    {
        output += " (complete)";
    }

    else if (this->isOverdue())
    {
        output += " (overdue)";
    }

    return output;
};

void Todo::markComplete()
{
    this->complete = true;
};

bool Todo::isComplete()
{
    return this->complete;
};