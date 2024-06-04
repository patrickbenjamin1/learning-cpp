#include "./dialogue.h"
#include "./character.h"

Dialogue::Dialogue(const DialogueId id, const std::string text, CharacterId speakerId, std::vector<ResponseId> responses, bool isEnd)
    : id(id), text(text), speakerId(speakerId), responses(responses), isEnd(isEnd)
{
}

bool Dialogue::operator==(Dialogue &other)
{
    return this->id == other.getId();
}

bool Dialogue::operator!=(Dialogue &other)
{
    return this->id != other.getId();
}

DialogueId Dialogue::getId()
{
    return this->id;
}

std::string Dialogue::getText()
{
    return this->text;
}

CharacterId Dialogue::getSpeakerId()
{
    return this->speakerId;
}

std::vector<ResponseId> Dialogue::getResponseIds()
{
    return this->responses;
}

bool Dialogue::getIsEnd()
{
    return this->isEnd;
}