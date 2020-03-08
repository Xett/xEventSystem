#include <list>
struct Event;
class EventSystem;
typedef void (*CallbackFunction)(Event event);
#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H
class EventDispatcher
{
	int event_id;
	int owner_id;
	std::list<CallbackFunction> callbacks;
public:
	EventDispatcher();
	EventDispatcher(int owner_id);
	EventDispatcher(int owner_id, int id);
	void Create(int owner_id);
	void Create(int owner_id, int event_id);
	bool operator==(const EventDispatcher& a);
	int GetId();
	int GetOwnerId();
	std::list<CallbackFunction>* GetCallbacks();
	Event DispatchEvent();
};
#endif