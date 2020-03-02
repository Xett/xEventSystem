#include "Event.h"
#include "EventDispatcher.h"

EventDispatcher::EventDispatcher()
{
    this->id = -1;
}
EventDispatcher::EventDispatcher(int id)
{
    this->id = id;
}

Event EventDispatcher::DispatchEvent()
{
	return Event(this->id);
}

bool EventDispatcher::operator==(const EventDispatcher& a)
{
    if (this->id == a.id)
    {
        return true;
    }
    return false;
}

int EventDispatcher::GetId()
{
    return id;
}
std::list<int>* EventDispatcher::GetChildrenIds()
{
    return &children_ids;
}