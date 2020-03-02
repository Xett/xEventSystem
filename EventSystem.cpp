#include <iostream>
#include <list>
#include <map>
#include <thread>
#include "Event.h"
#include "EventDispatcher.h"
#include "EventSystem.h"

EventSystem::EventSystem()
{
    std::list<std::thread>* threads = new std::list<std::thread>;
    std::map<int, EventDispatcher>* events = new std::map<int, EventDispatcher>();
    std::list<Event>* event_queue = new std::list<Event>();
}

void EventSystem::AddEvent(EventDispatcher dispatcher)
{
    events.insert(std::pair<int, EventDispatcher>(dispatcher.GetId(), dispatcher));
}

void EventSystem::RemoveEvent(EventDispatcher dispatcher)
{
    events.erase(events.find(dispatcher.GetId()));
}

void EventSystem::Bind(int event_id_parent, int event_id_child)
{
    events[event_id_parent].GetChildrenIds()->push_back(event_id_child);
    if (events[event_id_parent].GetChildrenIds()->size() != 0)
    {
        std::cout << events[event_id_parent].GetChildrenIds()->front();
    }
}

void EventSystem::Unbind(int event_id_parent, int event_id_child)
{
    events[event_id_parent].GetChildrenIds()->remove(event_id_child);
}

void EventSystem::CallEvent(int event_id)
{
    event_queue.push_back(events[event_id].DispatchEvent());
    if (events[event_id].GetChildrenIds()->size() != 0)
    {
        this->CallEvent(events[event_id].GetChildrenIds()->front());
    }    
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