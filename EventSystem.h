#include <iostream>
#include <list>
#include <map>
#include <thread>
class Event;
#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H
class EventSystem
{
    std::list<Event> event_queue;
    std::map<const char*, std::list<Event>> events;
    std::list<std::thread> threads;
public:
    EventSystem();
    void AddEvent(const char* event_name);
    void RemoveEvent(const char* event_name);
    void Bind(const char* event_name, Event event_return_function);
    void Unbind(const char* event_name, Event event_return_function);
    void CallEvent(const char* event_name);
    void ProcessQueue();
    void ProcessAll();
    void Yield();
    void YieldAll();
    std::thread CreateThread(Event event);
    void ProcessAllAndYieldAll();
};

#endif