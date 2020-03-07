#include "Event.h"
#include "EventDispatcher.h"

EventDispatcher::EventDispatcher()
{
    // Default constructor, use create to initialise in a 2-step process
    event_id = -1;
    owner_id = -1;
    this->callbacks = std::list<CallbackFunction>();
}

EventDispatcher::EventDispatcher(int owner_id)
{
    this->owner_id = owner_id;
    this->event_id = -1;
    this->callbacks = std::list<CallbackFunction>();
}

EventDispatcher::EventDispatcher(int owner_id, int event_id)
{
    this->owner_id = owner_id;
    this->event_id = event_id;
    this->callbacks = std::list<CallbackFunction>();
}

void EventDispatcher::Create(int owner_id)
{
    this->owner_id = owner_id;
    this->event_id = -1;
}

void EventDispatcher::Create(int owner_id, int event_id)
{
    this->owner_id = owner_id;
    this->event_id = event_id;
}

Event EventDispatcher::DispatchEvent()
{
    return Event{event_id,owner_id};
}

bool EventDispatcher::operator==(const EventDispatcher& a)
{
    if (this->event_id == a.event_id)
    {
        return true;
    }
    return false;
}

int EventDispatcher::GetId()
{
    return event_id;
}

int EventDispatcher::GetOwnerId()
{
    return owner_id;
}

std::list<CallbackFunction>* EventDispatcher::GetCallbacks()
{
    return &callbacks;
}