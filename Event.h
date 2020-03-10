#ifndef EVENT_H
#define EVENT_H
class Event
{
    int event_id;
    int owner_object_id;
public:
    Event(int event_id, int owner_object_id);
    int GetEventId();
    int GetOwnerObjectId();
};
#endif
