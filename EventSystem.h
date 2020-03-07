#include <iostream>
#include <list>
#include <map>
#include <thread>
struct Event;
class EventDispatcher;
class EventSystem;
typedef void (*CallbackFunction)(Event event);
#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H
class EventSystem
{
    std::map<int, EventDispatcher*> event_dispatchers;
public:
    EventSystem();
    void CallEvent(int event_id);
    void AddEvent(EventDispatcher &event_dispatcher);
    void RemoveEvent(EventDispatcher &event_dispatcher);
    void Bind(int event_id, CallbackFunction callback_function);
    //void Unbind(int event_id, void* callback_function);
    void ProcessQueue();
    void ProcessAll();
    void Yield();
    void YieldAll();
    void ProcessAllAndYieldAll();
    std::list<std::thread> threads;
    std::list<EventDispatcher*> event_queue;
};

#endif