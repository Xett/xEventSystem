#include <iostream>
#include "Event.h"

Event::Event(const char* name)
{
    this->name = name;
}

void Event::Process()
{
    std::cout << "Event Process: " << this->name << "\n";
    std::cout.flush();
}

bool Event::operator==(const Event& a)
{
    if (this->name == a.name)
    {
        return true;
    }
    return false;
}