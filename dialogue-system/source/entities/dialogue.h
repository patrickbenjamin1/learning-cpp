#ifndef DIALOGUE_DEF
#define DIALOGUE_DEF

#include <string>
#include <vector>

#include "./id.h"
#include "./character.h"
#include "./response.h"

// opaque ID type

class DialogueId : public EntityId<DialogueId>
{
public:
    explicit DialogueId(const std::string &id);
};

// entity

class Dialogue
{
private:
    DialogueId id;
    std::string text;
    CharacterId speakerId;
    std::vector<ResponseId> responses;
    bool isEnd;

public:
    Dialogue(const DialogueId id, const std::string text, CharacterId speakerId, std::vector<ResponseId> responses = std::vector<ResponseId>(), bool isEnd = false);

    // accessors
    DialogueId getId();
    std::string getText();
    CharacterId getSpeakerId();
    std::vector<ResponseId> getResponseIds();
    bool getIsEnd();

    // operations
    bool operator==(Dialogue &other);
    bool operator!=(Dialogue &other);
};

#endif // DIALOGUE_DEF