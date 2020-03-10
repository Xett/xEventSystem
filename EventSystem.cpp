#include "Event.h"
#include "EventDispatcher.h"
#include "EventSystem.h"
#include <iostream>
EventSystem::EventSystem()
{
    std::map<int, EventDispatcher*> event_dispatchers = std::map<int, EventDispatcher*>();
    std::list<EventDispatcher*> event_queue = std::list<EventDispatcher*>();
    std::list<std::thread> threads = std::list<std::thread>();
    running = true;
}
void EventSystem::CallEvent(int event_id)
{
    event_queue.push_back(event_dispatchers[event_id]); 
}
void EventSystem::AddEvent(EventDispatcher &event_dispatcher)
{
    event_dispatchers.insert(std::pair<int, EventDispatcher*>(event_dispatcher.GetId(), &event_dispatcher));
}
void EventSystem::RemoveEvent(EventDispatcher &event_dispatcher)
{
    event_dispatchers.erase(event_dispatchers.find(event_dispatcher.GetId()));
}
void EventSystem::Bind(int event_id, CallbackFunction callback_function)
{
    event_dispatchers[event_id]->GetCallbacks()->push_back(callback_function);
}
void EventSystem::Unbind(int event_id, CallbackFunction callback_function)
{
    event_dispatchers[event_id]->GetCallbacks()->remove(callback_function);
}
void EventSystem::ProcessQueue()
{
    if (!event_queue.empty())
    {
        EventDispatcher event_dispatcher = *event_queue.front();
        std::list<CallbackFunction>* callbacks = event_dispatcher.GetCallbacks();
        for (std::list<CallbackFunction>::iterator it = callbacks->begin(); it != callbacks->end(); ++it)
        {
            Event event = event_dispatcher.DispatchEvent();
            threads.push_back(std::thread(*it, event));
        }
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
void EventSystem::ProcessAllAndYieldAll()
{
    ProcessAll();
    YieldAll();
}

void EventSystem::MainLoopWorker(EventSystem* event_system)
{
    while (event_system->IsRunning())
    {
        event_system->ProcessAllAndYieldAll();
    }
}

void EventSystem::StartMainLoopThread()
{
    main_loop_thread = std::thread(MainLoopWorker, this);
}

void EventSystem::StopMainLoopThread()
{
    main_loop_thread.join();
}

bool EventSystem::IsRunning()
{
    return running;
}

void EventSystem::Close()
{
    running = false;
    StopMainLoopThread();
    YieldAll();
}

void EventSystem::Start()
{
    running = true;
    StartMainLoopThread();
}