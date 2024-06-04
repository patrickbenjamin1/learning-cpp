#ifndef COLLECTION_DEF
#define COLLECTION_DEF

#include <vector>

#include "./id.h"

// todo - infer Id from T
template <typename T, typename IdDerived>

class Collection
{
    // ensure given generic has an id member
    // static_assert(std::is_member_object_pointer<decltype(&T::id)>::value, "Type T must have a member named 'id'");

private:
    std::vector<T> entities;

public:
    Collection(){};
    Collection(std::vector<T> entities) : entities(entities){};

    // accessors

    // @todo - return by reference
    T getById(IdDerived id)
    {
        for (T entity : entities)
        {
            if (entity.getId() == id)
            {
                return entity;
            }
        }

        throw "Entity not found";
    }

    // @todo - return by reference
    std::vector<T> getByIds(std::vector<IdDerived> ids)
    {
        std::vector<T> foundEntities;

        for (IdDerived id : ids)
        {
            T entity = this->getById(id);
            foundEntities.push_back(entity);
        }

        return foundEntities;
    };
};

#endif