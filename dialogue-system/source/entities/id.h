#ifndef ENT_ID
#define ENT_ID

#include <string>
#include <functional>

template <typename Derived>
class EntityId
{
public:
    EntityId() : id(""){};
    EntityId(const std::string &id) : id(id) {}

    const std::string &get() const
    {
        return id;
    }

    const bool isDefined() const
    {
        return !id.empty();
    }

    bool operator==(const Derived &other) const
    {
        return id == other.get();
    }

    bool operator!=(const Derived &other) const
    {
        return id != other.get();
    }

protected:
    std::string id;
};

#endif // ENT_ID
