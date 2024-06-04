#ifndef CHARACTER_DEF
#define CHARACTER_DEF

#include <string>

#include "./id.h"
#include "./dialogue.h"

// opaque ID type

class CharacterId : public EntityId<CharacterId>
{
public:
    explicit CharacterId(const std::string &id);
};

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