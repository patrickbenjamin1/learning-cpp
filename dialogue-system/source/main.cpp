#include <iostream>

#include "./entities/character.h"
#include "./entities/dialogue.h"
#include "./entities/collection.h"
#include "./entities/response.h"
#include "./managers/dialogueManager.h"
#include "./controllers/consoleController.h"

int main()
{
    auto *characters = new Collection<Character, CharacterId>({
        Character(CharacterId("1"), "Steve", DialogueId("1")),
        Character(CharacterId("2"), "Paul", DialogueId("2")),
        Character(CharacterId("3"), "Bill", DialogueId("3")),
    });

    // why is the formatter doing this.....
    auto *dialogues = new Collection<Dialogue, DialogueId>({
        Dialogue(DialogueId("1"), "Hello, how are you?", CharacterId("1"), std::vector<ResponseId>({ResponseId("1"), ResponseId("2")})),
        Dialogue(DialogueId("2"), "Good", CharacterId("1")),
        Dialogue(DialogueId("3"), "I'm sorry to hear that - why is that?", CharacterId("1"), std::vector<ResponseId>({ResponseId("3"), ResponseId("4"), ResponseId("5")})),
        Dialogue(DialogueId("4"), "Oh, I'm sorry, I'll LEAVE THEN", CharacterId("1")),
        Dialogue(DialogueId("5"), "Fair enough", CharacterId("1")),
        Dialogue(DialogueId("6"), "Means brexit, correct", CharacterId("1")),
    });

    auto *responses = new Collection<Response, ResponseId>({
        Response(ResponseId("1"), "I'm good", DialogueId("2")),
        Response(ResponseId("2"), "I'm not good", DialogueId("3")),
        Response(ResponseId("3"), "Your face is making me not good", DialogueId("4")),
        Response(ResponseId("4"), "Fuck you Steve, it's none of your fucking business", DialogueId("5")),
        Response(ResponseId("5"), "Brexit", DialogueId("6")),
    });

    ConsoleController *controller = new ConsoleController();

    DialogueManager *dialogueManager = new DialogueManager(*dialogues, *characters, *responses, *controller);

    dialogueManager->speakToCharacter(CharacterId("1"));

    return 0;
}