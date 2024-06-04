#ifndef RESPONSE_DEF
#define RESPONSE_DEF

#include <string>

#include "./responseId.h"
#include "./dialogueId.h"
#include "./dialogue.h"

// entity

class Response
{
private:
    ResponseId id;
    std::string text;
    DialogueId dialogueId;

public:
    Response(const ResponseId id, const std::string text, DialogueId dialogueId);

    // accessors
    ResponseId getId() const;
    std::string getText() const;
    DialogueId getDialogueId() const;

    // operations
    bool operator==(Response &other);
    bool operator!=(Response &other);
};

#endif // RESPONSE_DEF