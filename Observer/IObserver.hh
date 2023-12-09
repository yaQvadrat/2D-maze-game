#ifndef I_OBSERVER_HH
#define I_OBSERVER_HH

class IObserver
{
public:
    virtual ~IObserver() {};
    virtual void update() = 0;
};

#endif
