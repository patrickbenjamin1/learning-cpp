#include <vector>

#include "../entities/character.h"
#include "../entities/response.h"
#include "../entities/collection.h"

#include "./dialogueManager.h"

DialogueManager::DialogueManager(
    Collection<Dialogue, DialogueId> &dialogues,
    Collection<Character, CharacterId> &characters,
    Collection<Response, ResponseId> &responses,
    Controller &controller)
    : dialogues(dialogues), characters(characters), responses(responses), controller(controller)
{
}

void DialogueManager::startDialogue(DialogueId dialogueId)
{
    Dialogue dialogue = this->dialogues.getById(dialogueId);
    Character character = this->characters.getById(dialogue.getSpeakerId());

    this->controller.write("[" + character.getName() + "]: " + dialogue.getText());
    this->controller.write("");

    if (dialogue.getIsEnd())
    {
        return;
    }

    this->controller.wait(1000);

    std::vector<Response> responses = this->getResponses(dialogueId);

    Response response = this->getUserResponse(responses);

    this->controller.write("");
    this->controller.write("[you]: " + response.getText());
    this->controller.write("");

    this->controller.wait(1000);

    this->startDialogue(response.getDialogueId());
}

std::vector<Response> DialogueManager::getResponses(DialogueId dialogueId)
{
    Dialogue dialogue = this->dialogues.getById(dialogueId);
    auto responses = this->responses.getByIds(dialogue.getResponseIds());
    return responses;
}

void DialogueManager::speakToCharacter(CharacterId characterId)
{
    Character character = this->characters.getById(characterId);

    this->controller.write("You are speaking to " + character.getName());

    DialogueManager::startDialogue(character.getConversationStartDialogueId());
}

Response DialogueManager::getUserResponse(std::vector<Response> responses)
{
    this->controller.write("Choose a response:");

    for (int i = 0; i < responses.size(); i++)
    {
        Response response = responses[i];
        this->controller.write(std::to_string(i + 1) + ". " + response.getText());
    }

    this->controller.write("");

    std::string response = this->controller.read();

    int responseIndex = std::stoi(response) - 1;

    return responses[responseIndex];
}