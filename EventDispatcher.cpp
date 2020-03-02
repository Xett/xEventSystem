#include "Event.h"
#include "EventSystem.h"
#include "EventDispatcher.h"

EventDispatcher::EventDispatcher()
{
    
}

EventDispatcher::EventDispatcher(EventSystem* event_system)
{
    this->id = -1;
    this->event_system = event_system;
}

EventDispatcher::EventDispatcher(EventSystem* event_system, int id)
{
    this->id = id;
    this->event_system = event_system;
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