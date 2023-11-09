#ifndef GAME_H
#define GAME_H

#include<QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPair>
#include "ghost.h"
#include "pacman.h"


/* Game control class */
class Game : public QGraphicsScene
{
    Q_OBJECT

public:
    enum GameStatus {Playing, Win, Lose, Pause, Safe};
    Game(int, int, int, int, QString);
    ~Game();
    void start();
    void _continue();
    void stop();
    void pacman_next_direction(GameObject::Dir);
    int get_score();

    GameObject ***map;              // the map of pacman game
    GameObject *gate;               // pointer of the gate of cage of ghosts
    Pacman *pacman;                 // pointer of pacman
    Ghost *ghost[Ghost::GhostNum];  // pointers of ghosts
    QVector<GameObject*> powerball; // pointers of powerball
    GameStatus stat;

    friend class Pacman;
    friend class Ghost;

signals:
    void lose_life();

private slots:
    void pacman_handler();
    void flash();
    void ghost_handler(int);
    void pacman_death_handler();

private:
    int map_height, map_width;      // game map (20 x 29 in this app)
    int map_size;                   // map_width * map_height
    int ball_num, eat_num, score;
    int geo_x, geo_y;               // geometric coordinate
    bool pause;

    int safe_time;
    QTimer *ghost_timer[Ghost::GhostNum];
    QTimer *pacman_timer;
    QTimer *safe_timer, *flash_timer;
    bool flash_tick;
    bool safe_tick;

};

#endif // GAME_H
