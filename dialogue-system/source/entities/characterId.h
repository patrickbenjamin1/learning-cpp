#ifndef CHARACTER_ID_DEF
#define CHARACTER_ID_DEF

#include <string>

#include "./id.h"

// opaque ID type

class CharacterId : public EntityId<CharacterId>
{
public:
    CharacterId() : EntityId<CharacterId>(){};
    CharacterId(const std::string id) : EntityId<CharacterId>(id) {}
};

#endif