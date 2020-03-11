#include "Event.h"
#include "EventDispatcher.h"
EventDispatcher::EventDispatcher()
{
    // Default constructor, use create to initialise in a 2-step process
    event_id = -1;
    this->callbacks = std::list<CallbackFunction>();
}
EventDispatcher::EventDispatcher(int event_id)
{
    this->event_id = event_id;
    this->callbacks = std::list<CallbackFunction>();
}
void EventDispatcher::Create(int event_id)
{
    this->event_id = event_id;
}
Event EventDispatcher::DispatchEvent()
{
    return Event(event_id);
}
bool EventDispatcher::operator==(const EventDispatcher& a)
{
    return (this->event_id == a.event_id) ? true : false;
}
int EventDispatcher::GetId()
{
    return event_id;
}
std::list<CallbackFunction>* EventDispatcher::GetCallbacks()
{
    return &callbacks;
}