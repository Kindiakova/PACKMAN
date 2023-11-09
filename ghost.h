#ifndef GHOST_H
#define GHOST_H

#include "gameobject.h"
#include "imoveable.h"

class Ghost : public IMoveable, public GameObject
{
public:
    enum Color {Red = 0, Pink = 1, Blue = 2, Yellow = 3};
    enum Status {Normal, Panic, Running};
    const static int GhostNum = 4;
    Game *game;

    Ghost(Game*, int, int, int, int);
    void move();
    Color get_color();

    friend class Game;
    friend class Pacman;

protected:
    void moveup() override;
    void movedown() override;
    void moveleft() override;
    void moveright() override;
    bool good(int, int) override;

    void setdir_randomly();
    void go_out_cage();
    void chase_pacman();
    void dodge_pacman();
    void go_to_cage();
    virtual QPair<int, int> goal_position() = 0; // position ghost make it way to according to chasing strategy

    Color color;
    Status status;
    QVector<QPixmap> anim[4];
    QVector<QPixmap> panic_anim;
    QVector<QPixmap> running_anim;
    int anim_index;
    int release_time;           // time to get out the cage
    bool is_released;
    int panic_time;
};

class RedGhost : public Ghost{
public:
    RedGhost(Game*, int, int, int, int);
private:
    QPair<int, int> goal_position() override;
};

class PinkGhost : public Ghost{
public:
    PinkGhost(Game*, int, int, int, int);
private:
    QPair<int, int> goal_position() override;
};

class BlueGhost : public Ghost{
public:
    BlueGhost(Game*, int, int, int, int);
private:
    QPair<int, int> goal_position() override;
};

class YellowGhost : public Ghost{
public:
    YellowGhost(Game*, int, int, int, int);
private:
    QPair<int, int> goal_position() override;
};



#endif // GHOST_H
