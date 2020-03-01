#include <iostream>
#include <list>
#include <map>
#include <thread>
#include "Event.h"
#include "EventSystem.h"

EventSystem::EventSystem()
{
    std::list<std::thread>* threads = new std::list<std::thread>;
    std::map<const char*, std::list<Event>>* events = new std::map<const char*, std::list<Event>>();
    std::list<Event>* event_queue = new std::list<Event>();
}

void EventSystem::AddEvent(const char* event_name)
{
    events.insert(std::pair<const char*, std::list<Event>>(event_name, std::list<Event>()));
}

void EventSystem::RemoveEvent(const char* event_name)
{
    events.erase(events.find(event_name));
}

void EventSystem::Bind(const char* event_name, Event event_return_function)
{
    events[event_name].push_front(event_return_function);
}

void EventSystem::Unbind(const char* event_name, Event event_return_function)
{
    events[event_name].erase(std::find(events[event_name].begin(), events[event_name].end(), event_return_function));
}

void EventSystem::CallEvent(const char* event_name)
{
    event_queue.insert(event_queue.end(), events[event_name].begin(), events[event_name].end());
}

void EventSystem::ProcessQueue()
{
    if (!event_queue.empty())
    {
        Event event = event_queue.front();
        threads.push_back(CreateThread(event));
        event_queue.pop_front();
    }
}

void EventSystem::ProcessAll()
{
    while (!event_queue.empty())
    {
        ProcessQueue();
    }
}

void EventSystem::Yield()
{
    if (!threads.empty())
    {
        threads.front().join();
        threads.pop_front();
    }
}

void EventSystem::YieldAll()
{
    for (std::list<std::thread>::iterator it = threads.begin(); it != threads.end(); ++it)
    {
        it->join();
    }
    threads.clear();
}

std::thread EventSystem::CreateThread(Event event)
{
    return std::thread(&Event::Process, event);
}

void EventSystem::ProcessAllAndYieldAll()
{
    ProcessAll();
    YieldAll();
}