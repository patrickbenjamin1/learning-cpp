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
    // if defined, offer these responses
    std::vector<ResponseId> responses;
    // if defined, continue to this dialogue after this one
    DialogueId nextDialogueId;

public:
    Dialogue(const DialogueId id, const std::string text, CharacterId speakerId, std::vector<ResponseId> responses = std::vector<ResponseId>());
    Dialogue(const DialogueId id, const std::string text, CharacterId speakerId, DialogueId nextDialogueId);

    // accessors
    DialogueId getId();
    std::string getText();
    CharacterId getSpeakerId();
    std::vector<ResponseId> getResponseIds();
    DialogueId getNextDialogueId();

    // operations
    bool operator==(Dialogue &other);
    bool operator!=(Dialogue &other);
};

#endif // DIALOGUE_DEF