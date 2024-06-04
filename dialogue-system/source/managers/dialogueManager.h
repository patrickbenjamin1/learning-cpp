#ifndef DIALOGUE_MANAGER_DEF
#define DIALOGUE_MANAGER_DEF

#include <vector>

#include "../entities/dialogue.h"
#include "../entities/character.h"
#include "../entities/response.h"
#include "../entities/collection.h"
#include "../controllers/controller.h"

class DialogueManager
{
private:
    Collection<Dialogue, DialogueId> &dialogues;
    Collection<Character, CharacterId> &characters;
    Collection<Response, ResponseId> &responses;
    Controller &controller;

public:
    DialogueManager(Collection<Dialogue, DialogueId> &dialogues, Collection<Character, CharacterId> &characters, Collection<Response, ResponseId> &responses, Controller &controller);

    // actions
    void startDialogue(DialogueId dialogueId);
    std::vector<Response &> getResponses(DialogueId dialogueId);
    void speakToCharacter(CharacterId characterId);
    Response &getUserResponse(std::vector<Response &> responses);
};

#endif // DIALOGUE_MANAGER_DEF