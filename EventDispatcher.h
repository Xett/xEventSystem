#include <list>
class Event;
class EventSystem;
#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H
class EventDispatcher
{
	int id;
	std::list<int> children_ids;
	EventSystem* event_system;
public:
	EventDispatcher();
	EventDispatcher(int id);
	Event DispatchEvent();
	bool operator==(const EventDispatcher& a);
	int GetId();
	std::list<int>* GetChildrenIds();
};
#endif