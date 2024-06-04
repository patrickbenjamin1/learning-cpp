#ifndef RESPONSE_DEF
#define RESPONSE_DEF

#include <string>

#include "./id.h"
#include "./dialogue.h"

// opaque ID type

class ResponseId : public EntityId<ResponseId>
{
public:
    explicit ResponseId(const std::string &id);
};

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