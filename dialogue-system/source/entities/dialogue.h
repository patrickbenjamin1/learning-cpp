#ifndef DIALOGUE_DEF
#define DIALOGUE_DEF

#include <string>
#include <vector>

#include "./dialogueId.h"
#include "./character.h"
#include "./response.h"

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
    Dialogue(const DialogueId id, const std::string text, CharacterId speakerId, std::vector<ResponseId> responses = std::vector<ResponseId>());

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