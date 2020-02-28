// EventSystemTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "EventSystem.h"

class TestEvent : public Event
{
public:
    TestEvent();
};

TestEvent::TestEvent() : Event("TEST")
{
    
}

TestEvent CreateEvent()
{
    return TestEvent();
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
    const char* event_name = "TEST_EVENT_NAME";
    event_system->AddEvent(event_name);
    event_system->Bind(event_name, CreateEvent());

    std::cout << "Test 1\n";
    event_system->CallEvent(event_name);
    event_system->ProcessQueue();
    event_system->Yield();

    std::cout << "Test 2\n";
    event_system->CallEvent(event_name);
    event_system->CallEvent(event_name);
    event_system->ProcessQueue();
    event_system->ProcessQueue();
    event_system->Yield();

    std::cout << "Test 3\n";
    event_system->CallEvent(event_name);
    event_system->CallEvent(event_name);
    event_system->ProcessQueue();
    event_system->Yield();
    event_system->ProcessQueue();
    event_system->Yield();

    std::cout << "Test 4\n";
    event_system->CallEvent(event_name);
    event_system->CallEvent(event_name);
    event_system->CallEvent(event_name);
    event_system->CallEvent(event_name);
    event_system->ProcessAllAndYieldAll();
    std::cout << "Finished!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
