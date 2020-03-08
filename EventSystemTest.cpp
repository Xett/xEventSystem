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
    std::cout << event.event_id << "\n";
}
int main()
{
    EventSystem event_system = EventSystem();
    EventDispatcher event_dispatcher = EventDispatcher(0,0);
    CallbackTest test = CallbackTest();
    event_system.AddEvent(event_dispatcher);
    event_system.Bind(0,&test.callback);
    event_system.CallEvent(0);
    event_system.ProcessQueue();
    event_system.YieldAll();
    return 0;
}