#ifndef EVENT_H
#define EVENT_H
class Event
{

public:
    Event();
    Event(const char* name);
    void Process();
    bool operator==(const Event& a);
    const char* name;
};
#endif
