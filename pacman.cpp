#include "game.h"
#include "options.h"

#define W (GameObject::Width)

Pacman::Pacman(Game *game, int x, int y, int tmp_x, int tmp_y) : GameObject(
    GameObject::Pacman, QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a3.png"),
    x, y, tmp_x, tmp_y)
{
    this->game = game;
    _x = x;
    _y = y;
    lives = PACMAN_LIVES;
    setZValue(2);
    dir = Stop;
    next_dir = Stop;
    anim_index = 2;
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a1.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a2.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a3.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a4.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a5.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a6.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a5.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a4.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a3.png"));
    anim[Right].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a2.png"));

    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a1.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b2.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b3.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b4.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b5.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b6.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b5.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b4.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b3.png"));
    anim[Up].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/b2.png"));

    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a1.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c2.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c3.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c4.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c5.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c6.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c5.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c4.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c3.png"));
    anim[Left].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/c2.png"));

    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a1.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d2.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d3.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d4.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d5.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d6.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d5.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d4.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d3.png"));
    anim[Down].push_back(QPixmap("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/d2.png"));
}

void Pacman::moveup()
{
    anim_index++;
    if (anim_index == anim[Up].size()) {
        anim_index = 0;
    }
    setPixmap(anim[Up][anim_index]);
    if (static_cast<int>(y() - 1) == game->geo_y)
        setY(game->geo_y + (game->map_height - 1) * GameObject::Width);
    else setY(static_cast<int>(y()) - 1);
}

void Pacman::moveleft()
{
    anim_index++;
    if (anim_index == anim[Left].size()) {
        anim_index = 0;
    }
    setPixmap(anim[Left][anim_index]);
    if (static_cast<int>(x() - 1) == game->geo_x)
        setX(game->geo_x + (game->map_width - 1) * GameObject::Width);
    else setX(static_cast<int>(x()) - 1);
}

void Pacman::movedown()
{
    anim_index++;
    if (anim_index == anim[Down].size()) {
        anim_index = 0;
    }
    setPixmap(anim[Down][anim_index]);
    if (static_cast<int>(y() + 1) == game->geo_y + (game->map_height - 1) * GameObject::Width)
        setY(game->geo_y);
    else setY(static_cast<int>(y()) + 1);
}

void Pacman::moveright()
{
    anim_index++;
    if (anim_index == anim[Right].size()) {
        anim_index = 0;
    }
    setPixmap(anim[Right][anim_index]);
    if (static_cast<int>(x()) + 1 == game->geo_x + (game->map_width - 1) * GameObject::Width)
        setX(game->geo_x);
    else setX(static_cast<int>(x()) + 1);
}


void Pacman::eat_ball(int __y, int __x)
{
    GameObject *obj = game->map[__y][__x];
    switch (obj->get_type()) {
    case Ball:
        game->score += obj->get_score();
        game->ball_num--;
        break;
    case PowerBall:
        game->score += obj->get_score();
        game->ball_num--;
        for (int i = 0; i < game->powerball.size(); i++) {
            if (game->powerball.at(i) == obj) {
                game->powerball.remove(i);
                break;
            }
        }

        for (int i = 0; i < Ghost::GhostNum; i++) {
            if (game->ghost[i]->status != Ghost::Running) {
                game->ghost[i]->status = Ghost::Panic;
                game->ghost[i]->panic_time = PANNIC_TIME;
                game->ghost_timer[i]->setInterval(PANNIC_INTERVAL);
            }
        }
        break;
    default:
        return;
    }

    /* Pacman eat a ball, and
     * fill the previous block with blank. */
    QPixmap blankpix;
    game->map[_y][_x] = new GameObject(GameObject::Blank, blankpix, _x, _y);
    game->map[__y][__x] = this;
    delete obj;
}


bool Pacman::good(int ii, int jj)
{
    int i = ii, j = jj;
    qDebug() << i << " " << j;
    if (i < 0 || j < 0) {
         if (i < -1 || j < -1) return false;
         if (i < 0) i = game->map_height - 1;
         if (j < 0) j = game->map_width  - 1;
     }

     if (i >= game->map_height || j >= game->map_width) {
         if (i > game->map_height || j > game->map_width)
             return false;
         if (i == game->map_height) i = 0;
         if (j == game->map_width) j = 0;
     }
    qDebug() <<"(" << i << " " << j << ")";
    switch (game->map[i][j]->get_type()) {
    case Wall:
    case Gate:
        return false;
    default:
        return true;
    }
}

void Pacman::move()
{
    int pac_x = static_cast<int>(x());
    int pac_y = static_cast<int>(y());
    int __x = (pac_x - game->geo_x) / W;            // x coordinate in map
    int __y = (pac_y - game->geo_y) / W;            // y coordinate in map
    int x_remainder = (pac_x - game->geo_x) % W;    // remainder x pixel to fit a block
    int y_remainder = (pac_y - game->geo_y) % W;    // remainder y pixel to fit a block
    Dir next_dir = get_next_dir();


    if (x_remainder == 0) {
        if (y_remainder == 0) {
            eat_ball(__y, __x);

            // update pacman's coordinate in map
            _x = __x;
            _y = __y;

            if (game->ball_num == 0) {
                game->stat = Game::Win;
                return;
            }
        }

        switch (next_dir) {
        case Stop:
            dir = next_dir;
            break;
        case Up:        // test if it can turn upward
            if (good(_y - 1, _x)) {
                dir = next_dir;
            }
            break;
        case Down:      // test if it can turn downward
            if (good(_y + 1, _x)) {
                dir = next_dir;
            }
            break;
        case Left:      // test if it can turn left
            if (y_remainder == 0 && good(_y, _x - 1)) {
                dir = next_dir;
            }
            break;
        case Right:      // test if it can turn right
            if (y_remainder == 0 && good(_y, _x + 1)) {
                dir = next_dir;
            }
            break;
        }
    } else if (y_remainder == 0) {
        switch (next_dir) {
        case Stop:
            dir = next_dir;
            break;
        case Left:      // test if it can turn left
            if (good(_y, _x - 1)) {
                dir = next_dir;
            }
            break;
        case Right:     // test if it can turn right
            if (good(_y, _x + 1)) {
                dir = next_dir;
            }
            break;
        default:                    // decide when x_remainder = 0
            break;
        }
    }


    switch (dir) {
    case Stop:
        break;
    case Up:
        if (y_remainder == 0 && !good(_y - 1, _x)) {
            dir = Stop;
            next_dir = Stop;
        } else {
            moveup();
        }
        break;
    case Down:
        if (y_remainder == 0 && !good(_y + 1, _x)) {
            dir = Stop;
            next_dir = Stop;
        } else {
            movedown();
        }
        break;
    case Left:
        if (x_remainder == 0 && !good(_y, _x - 1)) {
            dir = Stop;
            next_dir = Stop;
        } else {
            moveleft();
        }
        break;
    case Right:
        if (x_remainder == 0 && !good(_y, _x + 1)) {
            dir = Stop;
            next_dir = Stop;
        } else {
            moveright();
        }
        break;
    }
}
