#include "Event.h"
#include "EventDispatcher.h"
#include "EventSystem.h"
int TestEventID = 0;
int TestEventID2 = 1;
class TestEvent : public Event
{
public:
    TestEvent();
};

TestEvent::TestEvent() : Event(TestEventID)
{

}

class TestEvent2 : public Event
{
public:
    TestEvent2();
};

TestEvent2::TestEvent2() : Event(TestEventID2)
{

}

class TestEventDispatcher : public EventDispatcher
{
public:
    TestEventDispatcher();
    Event DispatchEvent();
};

TestEventDispatcher::TestEventDispatcher() : EventDispatcher(TestEventID)
{

}

Event TestEventDispatcher::DispatchEvent()
{
    return TestEvent();
}

class TestEventDispatcher2 : public EventDispatcher
{
public:
    TestEventDispatcher2();
    Event DispatchEvent();
};

TestEventDispatcher2::TestEventDispatcher2() : EventDispatcher(TestEventID2)
{

}

Event TestEventDispatcher2::DispatchEvent()
{
    return TestEvent2();
}

int main()
{
    std::cout << "Stating Event System Test\n";
    std::cout << "Creating Event System...\n";
    EventSystem* event_system = new EventSystem();
    if (!event_system)
    {
        std::cout << "Failed!\n";
    }
    else
    {
        std::cout << "Success!\n";
    }
    TestEventDispatcher test_dispatcher = TestEventDispatcher();
    int event_id = test_dispatcher.GetId();
    TestEventDispatcher2 test_dispatcher2 = TestEventDispatcher2();
    int event_id2 = test_dispatcher2.GetId();
    event_system->AddEvent(test_dispatcher);
    event_system->AddEvent(test_dispatcher2);

    std::cout << "Test 1\n";
    event_system->CallEvent(event_id);
    event_system->ProcessQueue();
    event_system->Yield();

    std::cout << "Test 2\n";
    event_system->CallEvent(event_id);
    event_system->CallEvent(event_id);
    event_system->ProcessQueue();
    event_system->ProcessQueue();
    event_system->Yield();

    std::cout << "Test 3\n";
    event_system->CallEvent(event_id);
    event_system->CallEvent(event_id);
    event_system->ProcessQueue();
    event_system->Yield();
    event_system->ProcessQueue();
    event_system->Yield();

    std::cout << "Test 4\n";
    event_system->CallEvent(event_id);
    event_system->CallEvent(event_id);
    event_system->CallEvent(event_id);
    event_system->CallEvent(event_id);
    event_system->ProcessAllAndYieldAll();

    std::cout << "Test 5\n";
    event_system->Bind(event_id, event_id2);
    event_system->CallEvent(event_id);
    event_system->ProcessAllAndYieldAll();
    std::cout << "Finished!\n";
}