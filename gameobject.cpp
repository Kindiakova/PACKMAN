#include "gameobject.h"
#include "options.h"

GameObject::GameObject(ObjectType t, QPixmap pixmap, int x, int y, int tmp_x, int tmp_y)
    : QGraphicsPixmapItem(pixmap)
{
    type = t;
    _x = x;
    _y = y;
    if (type != Blank) setPos(tmp_x, tmp_y);

    switch (type) {
    case PowerBall:
        set_score(POWERBALL_SCORE);
        break;
    case Ball:
        set_score(BALL_SCORE);
        break;
    default:
        break;
    }
}

GameObject::ObjectType GameObject::get_type()
{
    return type;
}

int GameObject::get_x()
{
    return _x;
}

int GameObject::get_y()
{
    return _y;
}

int GameObject::get_score()
{
    return score;
}

void GameObject::set_score(int s)
{
    score = s;
}

void GameObject::set_dir(Dir d)
{
    dir = d;
}

GameObject::Dir GameObject::get_dir()
{
    return dir;
}

GameObject::Dir GameObject::get_next_dir()
{
    return next_dir;
}

void GameObject::set_next_dir(Dir d)
{
    next_dir = d;
}

GameObject::~GameObject()
{
}
