﻿#include <list>
#include <map>
#include <thread>
class Event;
class EventDispatcher;
class EventSystem;
typedef void (*CallbackFunction)(Event event);
#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H
class EventSystem
{
    std::map<int, EventDispatcher*> event_dispatchers;
    std::list<std::thread> threads;
    std::list<EventDispatcher*> event_queue;
    std::thread main_loop_thread;
    bool running;
public:
    EventSystem();
    void CallEvent(int event_id);
    void AddEvent(EventDispatcher &event_dispatcher);
    void RemoveEvent(EventDispatcher &event_dispatcher);
    void Bind(int event_id, CallbackFunction callback_function);
    void Unbind(int event_id, CallbackFunction callback_function);
    void ProcessQueue();
    void ProcessAll();
    void Yield();
    void YieldAll();
    void ProcessAllAndYieldAll();
    static void MainLoopWorker(EventSystem* event_system);
    void StartMainLoopThread();
    void StopMainLoopThread();
    bool IsRunning();
    void Start();
    void Close();
};
#endif