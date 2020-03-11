#include <list>
class Event;
class EventSystem;
typedef void (*CallbackFunction)(Event event);
#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H
class EventDispatcher
{
	int event_id;
	std::list<CallbackFunction> callbacks;
public:
	EventDispatcher();
	EventDispatcher(int event_id);
	void Create(int event_id);
	bool operator==(const EventDispatcher& a);
	int GetId();
	std::list<CallbackFunction>* GetCallbacks();
	Event DispatchEvent();
};
#endif