#include <vector>

#include "./collection.h"

template <class T, typename IdDerived>

Collection<T, IdDerived>::Collection()
{
}

template <class T, typename IdDerived>

Collection<T, IdDerived>::Collection(std::vector<T> entities) : entities(entities)
{
}

template <class T, typename IdDerived>

T Collection<T, IdDerived>::getById(IdDerived id)
{
    for (T &entity : entities)
    {
        if (entity.id == id)
        {
            return entity;
        }
    }

    // Throw an exception or handle the case when the entity is not found
    throw std::runtime_error("Entity not found");
}

template <class T, typename IdDerived>

std::vector<T &> Collection<T, IdDerived>::getByIds(std::vector<IdDerived> ids)
{
    std::vector<T &> foundEntities;

    for (EntityId<IdDerived> id : ids)
    {
        T &entity = this->getById(id);
        foundEntities.push_back(entity);
    }

    return foundEntities;
}