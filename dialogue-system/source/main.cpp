#include <iostream>

#include "./entities/character.h"
#include "./entities/dialogue.h"
#include "./entities/collection.h"
#include "./entities/response.h"
#include "./managers/dialogueManager.h"
#include "./controllers/consoleController.h"

auto *characters = new Collection<Character, CharacterId>({
    Character(CharacterId("1"), "Steve", DialogueId("1")),
    Character(CharacterId("2"), "Paul", DialogueId("2")),
    Character(CharacterId("3"), "Bill", DialogueId("3")),
});

// why is the formatter doing this.....
auto *dialogues = new Collection<Dialogue, DialogueId>({Dialogue(DialogueId("1"), "Hello, how are you?", CharacterId("1"), std::vector<ResponseId>({ResponseId("1"), ResponseId("2")})),
                                                        Dialogue(DialogueId("2"), "Good", CharacterId("1"), std::vector<ResponseId>(), true),
                                                        Dialogue(DialogueId("3"), "I'm sorry to hear that", CharacterId("1"), std::vector<ResponseId>(), true)});

auto *responses = new Collection<Response, ResponseId>({
    Response(ResponseId("1"), "I'm good", DialogueId("2")),
    Response(ResponseId("2"), "I'm not good", DialogueId("3")),
});

ConsoleController *controller = new ConsoleController();

int main()
{
    DialogueManager *dialogueManager = new DialogueManager(*dialogues, *characters, *responses, *controller);

    dialogueManager->speakToCharacter(CharacterId("1"));

    return 0;
}