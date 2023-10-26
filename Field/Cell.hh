#ifndef CELL_HH
#define CELL_HH

class IEvent;

class Cell
{
    bool passable;
    IEvent *event;

public:
    Cell(bool passable = true, IEvent *event = nullptr);
    ~Cell();

    Cell(const Cell &other);
    Cell& operator = (const Cell &other);
    Cell(Cell &&other);
    Cell& operator = (Cell &&other);

    void setPassable(bool passable = true);

    bool getPassable() const;
    IEvent* getEvent();
};

#endif
