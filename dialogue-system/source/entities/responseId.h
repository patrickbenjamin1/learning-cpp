#ifndef RESPONSEID_DEF
#define RESPONSEID_DEF

#include <string>

#include "./id.h"

// opaque ID type

class ResponseId : public EntityId<ResponseId>
{
public:
    ResponseId() : EntityId<ResponseId>(){};
    ResponseId(const std::string &id) : EntityId<ResponseId>(id) {}
};

#endif