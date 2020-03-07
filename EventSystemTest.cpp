//#include "Event.h"
//#include "EventDispatcher.h"
//#include "EventSystem.h"

//struct TestEvent : Event
//{
//    const char* message;
//};

//class TestEventDispatcher : public EventDispatcher
//{
//    const char* message;
//public:
//    TestEventDispatcher();
//    TestEvent DispatchEvent();
//};

//TestEventDispatcher::TestEventDispatcher() : EventDispatcher(0, 0)
//{
 //   message = "Test Message\n";
//}

//TestEvent TestEventDispatcher::DispatchEvent()
//{
//    TestEvent te = TestEvent{};
//    te.event_id = GetId();
//    te.owner_object_id = GetOwnerId();
//    te.message = message;
//    return te;
//}

//int main()
//{
//    std::cout << "Stating Event System Test\n";
//    std::cout << "Creating Event System...\n";
//    EventSystem* event_system = new EventSystem();
//    if (!event_system)
//    {
//        std::cout << "Failed!\n";
//    }
//    else
//    {
//        std::cout << "Success!\n";
//    }

//    TestEventDispatcher test_dispatcher = TestEventDispatcher();
//    int event_id = test_dispatcher.GetId();

//    event_system->AddEvent(test_dispatcher);

//    std::cout << "Test 1\n";
//    event_system->CallEvent(event_id);
//    event_system->ProcessAllAndYieldAll();
//    std::cout << "Finished!\n";
//}

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