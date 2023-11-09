#ifndef IMOVEABLE_H
#define IMOVEABLE_H

class IMoveable {

protected:

    virtual void moveup() = 0;
    virtual void movedown() = 0;
    virtual void moveleft() = 0;
    virtual void moveright() = 0;

    virtual bool good(int, int) = 0; // check if character can move to this position
};

#endif // IMOVEABLE_H
