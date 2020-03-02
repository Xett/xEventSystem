#ifndef EVENT_H
#define EVENT_H
class Event
{

public:
    Event(int id);
    void Process();
    bool operator==(const Event& a);
    int id;
};
#endif
