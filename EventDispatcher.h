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
	std::list<CallbackFunction> callbacks;
	Event DispatchEvent();
};
#endif