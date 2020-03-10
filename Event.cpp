#include "Event.h"

Event::Event(int event_id, int owner_object_id)
{
	this->event_id = event_id;
	this->owner_object_id = owner_object_id;
}

int Event::GetEventId()
{
	return event_id;
}

int Event::GetOwnerObjectId()
{
	return owner_object_id;
}