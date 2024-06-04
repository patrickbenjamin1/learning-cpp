#include "./response.h"

Response::Response(const ResponseId id, const std::string text, DialogueId dialogueId)
    : id(id), text(text), dialogueId(dialogueId)
{
}

bool Response::operator==(Response &other)
{
    return this->id == other.id;
}

bool Response::operator!=(Response &other)
{
    return this->id != other.id;
}

ResponseId Response::getId() const
{
    return this->id;
}

std::string Response::getText() const
{
    return this->text;
}

DialogueId Response::getDialogueId() const
{
    return this->dialogueId;
}