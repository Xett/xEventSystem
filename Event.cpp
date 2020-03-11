#include "Event.h"

Event::Event(int event_id)
{
	this->event_id = event_id;
}

int Event::GetEventId()
{
	return event_id;
}