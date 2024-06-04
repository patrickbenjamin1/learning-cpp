#ifndef CHARACTER_DEF
#define CHARACTER_DEF

#include <string>

#include "./characterId.h"
#include "./dialogue.h"

// entity

class Character
{
private:
    CharacterId id;
    std::string name;
    DialogueId conversationStartDialogueId;

public:
    Character(CharacterId id, std::string name, DialogueId conversationStartDialogueId);

    // accessors
    CharacterId getId();
    std::string getName();
    DialogueId getConversationStartDialogueId();

    // operations
    bool operator==(Character &other);
    bool operator!=(Character &other);
};

#endif // CHARACTER_DEF