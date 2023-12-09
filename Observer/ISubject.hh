#ifndef I_SUBJECT_HH
#define I_SUBJECT_HH

class IObserver;

class ISubject
{
public:
    virtual ~ISubject() {}
    virtual void attachObserver(IObserver *observer) = 0;
    virtual void detachObserver(IObserver *observer) = 0;
    virtual void notify() = 0;
};

#endif
