#include <string>

#include "./character.h"

Character::Character(CharacterId id, std::string name, DialogueId conversationStartDialogueId)
    : id(id), name(name), conversationStartDialogueId(conversationStartDialogueId)
{
}

CharacterId Character::getId()
{
    return this->id;
}

std::string Character::getName()
{
    return this->name;
}

DialogueId Character::getConversationStartDialogueId()
{
    return this->conversationStartDialogueId;
}

bool Character::operator==(Character &other)
{
    return this->id == other.getId();
}

bool Character::operator!=(Character &other)
{
    return this->id != other.getId();
}
