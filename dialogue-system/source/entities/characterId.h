#ifndef CHARACTER_ID_DEF
#define CHARACTER_ID_DEF

#include <string>

#include "./id.h"

// opaque ID type

class CharacterId : public EntityId<CharacterId>
{
private:
    std::string id;

public:
    CharacterId(const std::string id) : EntityId<CharacterId>(id) {}
};

#endif