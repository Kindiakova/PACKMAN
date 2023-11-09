#ifndef PACMAN_H
#define PACMAN_H

#include "gameobject.h"
#include "imoveable.h"

class Pacman : IMoveable, public GameObject
{
public:
    Pacman(Game *, int, int, int, int);
    void move();
    Game *game;

    friend class Game;

private:
    void moveup() override;
    void movedown() override;
    void moveleft() override;
    void moveright() override;
    bool good(int, int) override;

    void eat_ball(int, int);

    QVector<QPixmap> anim[4];   // animations
    int anim_index;
    int lives;
};


#endif // PACMAN_H
