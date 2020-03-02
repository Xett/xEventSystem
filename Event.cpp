#include <iostream>
#include "Event.h"


Event::Event(int id)
{
    this->id = id;
}

void Event::Process()
{
    std::cout << "Event Process: " << this->id << "\n";
    std::cout.flush();
}

bool Event::operator==(const Event& a)
{
    if (this->id == a.id)
    {
        return true;
    }
    return false;
}