#ifndef DIALOGUEID_DEF
#define DIALOGUEID_DEF

#include <string>
#include <vector>

#include "./id.h"

// opaque ID type

class DialogueId : public EntityId<DialogueId>
{
public:
    DialogueId(const std::string &id) : EntityId<DialogueId>(id) {}
};

#endif