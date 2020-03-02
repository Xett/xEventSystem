#include <iostream>
#include <list>
#include <map>
#include <thread>
class Event;
class EventDispatcher;
#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H
class EventSystem
{
    std::list<Event> event_queue;
    std::map<int, EventDispatcher> events;
    std::list<std::thread> threads;
public:
    EventSystem();
    void AddEvent(EventDispatcher dispatcher);
    void RemoveEvent(EventDispatcher dispatcher);
    void Bind(int event_id_parent, int event_id_child);
    void Unbind(int event_id_parent, int event_id_child);
    void CallEvent(int event_id);
    void ProcessQueue();
    void ProcessAll();
    void Yield();
    void YieldAll();
    std::thread CreateThread(Event event);
    void ProcessAllAndYieldAll();
};

#endif