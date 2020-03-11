#include <list>
#include <iostream>
#include <thread>
#include "Event.h"
#include "EventDispatcher.h"
#include "EventSystem.h"
typedef void (*CallbackFunction)(Event event);
class CallbackTest
{
public:
    CallbackTest();
    static void callback(Event event);
};
CallbackTest::CallbackTest()
{

}
void CallbackTest::callback(Event event)
{
    std::cout << event.GetEventId() << "\n";
    std::cout.flush();
}
class TestEventDispatcher : public EventDispatcher
{
public:
    TestEventDispatcher();
    TestEventDispatcher(int id);
};

TestEventDispatcher::TestEventDispatcher() : EventDispatcher()
{

}

TestEventDispatcher::TestEventDispatcher(int id) : EventDispatcher(id)
{

}

int main()
{
    EventSystem event_system = EventSystem();
    TestEventDispatcher event_dispatcher = TestEventDispatcher(0);
    CallbackTest test = CallbackTest();
    event_system.AddEvent(event_dispatcher);
    event_system.Bind(event_dispatcher.GetId(),&test.callback);
    event_system.CallEvent(event_dispatcher.GetId());
    event_system.Start();
    _sleep(5);
    event_system.Close();
    return 0;
}