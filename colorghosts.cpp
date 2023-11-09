#include "ghost.h"
#include "pacman.h"
#include "game.h"
#include "options.h"

RedGhost::RedGhost(Game * game, int x, int y, int tmp_x, int tmp_y):
    Ghost(game, x, y, tmp_x, tmp_y)
{
    color = Ghost::Red;
    release_time = GHOST_RELEASE_TIME[Ghost::Red];
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/redright1.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/redright2.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/redup1.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/redup2.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/redleft1.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/redleft2.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/reddown1.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/reddown2.png"));
    setPixmap(anim[Right][0]);
}

PinkGhost::PinkGhost(Game * game, int x, int y, int tmp_x, int tmp_y):
    Ghost(game, x, y, tmp_x, tmp_y)
{
    color = Ghost::Pink;
    release_time = GHOST_RELEASE_TIME[Ghost::Pink];
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/pinkright1.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN//game_objects/ghosts/pinkright2.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/pinkup1.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/pinkup2.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/pinkleft1.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/pinkleft2.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/pinkdown1.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/pinkdown2.png"));
    setPixmap(anim[Right][0]);
}

BlueGhost::BlueGhost(Game * game, int x, int y, int tmp_x, int tmp_y):
    Ghost(game, x, y, tmp_x, tmp_y)
{
    color = Ghost::Blue;
    release_time = GHOST_RELEASE_TIME[Ghost::Blue];
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/blueright1.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/blueright2.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/blueup1.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/blueup2.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/blueleft1.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/blueleft2.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/bluedown1.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/bluedown2.png"));
    setPixmap(anim[Right][0]);
}

YellowGhost::YellowGhost(Game * game, int x, int y, int tmp_x, int tmp_y):
    Ghost(game, x, y, tmp_x, tmp_y)
{
    color = Ghost::Yellow;
    release_time = GHOST_RELEASE_TIME[Ghost::Yellow];
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/yellowright1.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/yellowright2.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/yellowup1.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/yellowup2.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/yellowleft1.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/yellowleft2.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/yellowdown1.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/ghosts/yellowdown2.png"));
    setPixmap(anim[Right][0]);

}

//Shadow -- chaser
QPair<int, int> RedGhost::goal_position() {
    auto *pacman = game->pacman;
    int dist_x = pacman->get_x() - get_x();
    int dist_y = pacman->get_y() - get_y();
    return QPair<int, int>(dist_x, dist_y);
}



//Speedy -- ambusher
QPair<int, int> PinkGhost::goal_position() {
    auto *pacman = game->pacman;
    int dist_x = pacman->get_x() - get_x();
    int dist_y = pacman->get_y() - get_y();
    switch(pacman->get_dir()) {
    case GameObject::Up:
        dist_y-=4;
        break;
    case GameObject::Down:
        dist_y+=4;
        break;
    case GameObject::Left:
        dist_x-=4;
        break;
    case GameObject::Right:
        dist_x+=4;
        break;
    default:
        break;
    }
    return QPair<int, int>(dist_x, dist_y);
}

//Bashful -- Fickle
QPair<int, int> BlueGhost::goal_position() {
    auto *pacman = game->pacman;
    Ghost *red_ghost = game->ghost[Ghost::Red];
    int dist_x = (pacman->get_x() - red_ghost->get_x()) * 2 - get_x();
    int dist_y = (pacman->get_y() - red_ghost->get_y()) * 2 - get_y();
    return QPair<int, int>(dist_x, dist_y);

}

//Pokey -- feigning ignorance
QPair<int, int> YellowGhost::goal_position() {
    auto *pacman = game->pacman;
    int dist_x = pacman->get_x() - get_x();
    int dist_y = pacman->get_y() - get_y();
    if (dist_x * dist_x + dist_y * dist_y < 64) {
        dist_x = 2 - get_x();
        dist_y = 2 - get_y();
    }
    return QPair<int, int>(dist_x, dist_y);
}


