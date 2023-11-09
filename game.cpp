#include "game.h"
#include <QString>
#include <QFile>
#include <QRandomGenerator>
#include "options.h"

#define W (GameObject::Width)


Game::Game(int x, int y, int map_w, int map_h, QString map_src)
    : QGraphicsScene(x, y, W * map_w, W * map_h)
{
    geo_x = x;
    geo_y = y;
    stat = Playing;
    safe_time = 0;
    /* Initialize map pointers */
    map_size = map_w * map_h;
    map_width = map_w;
    map_height = map_h;
    map = new GameObject**[map_height];
    for (int i = 0; i < map_height; i++) {
        map[i] = new GameObject*[map_width];
        for (int j = 0; j < map_width; j++)
            map[i][j] = nullptr;
    }

    /* Initialize map graphics */
    ball_num = eat_num = score = 0;

    QPixmap wallpix_01("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall01.png");
    QPixmap wallpix_02("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall02.png");
    QPixmap wallpix_03("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall03.png");
    QPixmap wallpix_04("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall04.png");
    QPixmap wallpix_1("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall1.png");
    QPixmap wallpix_2("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall2.png");
    QPixmap wallpix_3("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall3.png");
    QPixmap wallpix_4("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall4.png");
    QPixmap wallpix_5("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall5.png");
    QPixmap wallpix_6("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall6.png");
    QPixmap wallpix_7("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall7.png");
    QPixmap wallpix_8("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall8.png");
    QPixmap wallpix_9("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall9.png");
    QPixmap wallpix_10("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/wall10.png");

    QPixmap ballpix("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/dot.png");
    QPixmap powerballpix("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/power_ball.png");
    QPixmap gatepix("C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/gate.png");
    QPixmap blankpix;
    QFile mapfile(map_src);
    mapfile.open(QIODevice::ReadOnly|QIODevice::Text);


    for (int i = 0; i < map_h; i++) {
        QByteArray line = mapfile.readLine();
        for (int j = 0; j < map_w; j++) {
            int tmp_x = x + (j * W);
            int tmp_y = y + (i * W);
            switch (line[j]) {
            case '0':
                map[i][j] = new GameObject(GameObject::Blank, blankpix, j, i);
                break;
            case '1':
                if (i > 0 && map[i-1][j]->type == GameObject::Wall)
                    if (j > 0 && map[i][j-1]->type == GameObject::Wall)
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_01, j, i, tmp_x, tmp_y);
                    else if (j+1 < map_w && (line[j+1] == '1' || line[j+1] == '2'))
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_04, j, i, tmp_x, tmp_y);
                    else
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_1, j, i, tmp_x, tmp_y);
                else if (j+1 < map_w && (line[j+1] == '1' || line[j+1] == '2'))
                    if (j > 0 && map[i][j-1]->type == GameObject::Wall)
                         map[i][j] = new GameObject(GameObject::Wall, wallpix_03, j, i, tmp_x, tmp_y);
                    else
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_3, j, i, tmp_x, tmp_y);
                else if (j > 0 && map[i][j-1]->type == GameObject::Wall)
                    map[i][j] = new GameObject(GameObject::Wall, wallpix_4, j, i, tmp_x, tmp_y);
                else
                    map[i][j] = new GameObject(GameObject::Wall, wallpix_9, j, i, tmp_x, tmp_y);
                addItem(map[i][j]);
                break;
            case '2':
                if (j > 0 && map[i][j-1]->type == GameObject::Wall){
                    if (j+1 < map_w && (line[j+1] == '1' || line[j+1] == '2'))
                        if (i > 0 && map[i-1][j]->type == GameObject::Wall)
                            map[i][j] = new GameObject(GameObject::Wall, wallpix_02, j, i, tmp_x, tmp_y);
                        else
                            map[i][j] = new GameObject(GameObject::Wall, wallpix_2, j, i, tmp_x, tmp_y);
                    else if (i > 0 && map[i-1][j]->type == GameObject::Wall)
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_6, j, i, tmp_x, tmp_y);
                    else
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_8, j, i, tmp_x, tmp_y);
                }
                else {
                    if (i == 0 || map[i-1][j]->type != GameObject::Wall)
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_7, j, i, tmp_x, tmp_y);
                    else if (j + 1 == map_w || (line[j+1] != '1' && line[j+1] != '2'))
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_10, j, i, tmp_x, tmp_y);
                    else
                        map[i][j] = new GameObject(GameObject::Wall, wallpix_5, j, i, tmp_x, tmp_y);
                }
                addItem(map[i][j]);
                break;
            case '3':
                gate = new GameObject(GameObject::Gate, gatepix, j, i, tmp_x, tmp_y);
                addItem(gate);
                map[i][j] = gate;
                break;
            case '4':
                map[i][j] = new GameObject(GameObject::Ball, ballpix, j, i, tmp_x, tmp_y);
                addItem(map[i][j]);
                ball_num++;
                break;
            case '5':
                map[i][j] = new GameObject(GameObject::PowerBall, powerballpix, j, i, tmp_x, tmp_y);
                addItem(map[i][j]);
                powerball.push_back(map[i][j]);
                ball_num++;
                break;            
            case 'P':
                pacman = new Pacman(this, j, i, tmp_x, tmp_y);
                addItem(pacman);
                map[i][j] = pacman;
                break;
            case 'r':
                map[i][j] = new GameObject(GameObject::Blank, blankpix, j, i);
                ghost[Ghost::Red] = new RedGhost(this, j, i, tmp_x, tmp_y);
                addItem(ghost[Ghost::Red]);
                break;
            case 'p':
                map[i][j] = new GameObject(GameObject::Blank, blankpix, j, i);
                ghost[Ghost::Pink] = new PinkGhost(this, j, i, tmp_x, tmp_y);
                addItem(ghost[Ghost::Pink]);
                break;
            case 'b':
                map[i][j] = new GameObject(GameObject::Blank, blankpix, j, i);
                ghost[Ghost::Blue] = new BlueGhost(this, j, i, tmp_x, tmp_y);
                addItem(ghost[Ghost::Blue]);
                break;
            case 'y':
                map[i][j] = new GameObject(GameObject::Blank, blankpix, j, i);
                ghost[Ghost::Yellow] = new YellowGhost(this, j, i, tmp_x, tmp_y);
                addItem(ghost[Ghost::Yellow]);
                break;
           }

        }
    }
}


void Game::start()
{
    stat = Playing;
    flash_timer = new QTimer(this);
    connect(flash_timer, SIGNAL(timeout()), this , SLOT(flash()));
    flash_timer->start(FLASH_INTERVAL);

    pacman_timer = new QTimer(this);
    connect(pacman_timer, SIGNAL(timeout()), this , SLOT(pacman_handler()));
    pacman_timer->start(INTERVAL);

    for (int i = 0; i < Ghost::GhostNum; i++) {
        ghost_timer[i] = new QTimer(this);
        // Managed to pass ghost id to ghost_handler.
        connect(ghost_timer[i], &QTimer::timeout, [=](){ghost_handler(i);} );
        ghost_timer[i]->start(NORMAL_INTERVAL);
    }
    safe_timer = new QTimer(this);
    safe_timer->setInterval(SAFE_INTERVAL);
    safe_timer->stop();
    connect(safe_timer, &QTimer::timeout, [=](){
        if (!pacman->isVisible()) pacman->show();
        safe_time = 0;
        safe_timer->setInterval(SAFE_INTERVAL);
        safe_timer->stop();
        stat = Playing;
    } );
}

void Game::_continue()
{
    if (safe_time == 0) stat = Playing;
    else {

        safe_timer->start(safe_time);
        safe_time = 0;
        stat = Safe;
    }
    pacman_timer->start();
    flash_timer->start();
    for (int i = 0; i < Ghost::GhostNum; i++) {
        ghost_timer[i]->start();
    }
}

void Game::stop()
{
    if (stat == Safe) {
        safe_time = safe_timer->remainingTime();
        safe_timer->stop();
        stat = Pause;
    }
    if (stat == Playing) stat = Pause;
    pacman_timer->stop();
    for (int i = 0; i < Ghost::GhostNum; i++) {
        ghost_timer[i]->stop();
    }
}


void Game::flash()
{
    if (powerball.empty()) {
        flash_timer->stop();
        return;
    }

    if (flash_tick) {
        for (int i = 0; i < powerball.size(); i++) {
            powerball.at(i)->hide();
        }
        flash_tick = 0;
    } else {
        for (int i = 0; i < powerball.size(); i++) {
            powerball.at(i)->show();
        }
        flash_tick = 1;
    }

    if (stat == Safe){
        if (safe_tick) {
            pacman->hide();
            safe_tick = 0;
        } else {
            pacman->show();
            safe_tick = 1;
        }
    }
}

void Game::pacman_handler()
{
    pacman->move();
    if (stat == Win) {
        stop();
    }
}


void Game::ghost_handler(int ghost_id)
{
    ghost[ghost_id]->move();
    if (stat == Lose) {
        stop();
    }
}

void Game::pacman_death_handler(){
    pacman->lives--;
    emit lose_life();

    if (pacman->lives == 0)
        stat = Lose;
    else {
        stat = Safe;
        safe_timer->start(SAFE_INTERVAL);
    }

}

void Game::pacman_next_direction(GameObject::Dir d)
{
    pacman->set_next_dir(d);
}

int Game::get_score()
{
    return score;
}


Game::~Game()
{
    delete pacman_timer;
    delete flash_timer;
    delete safe_timer;
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            if (map[i][j] != nullptr)
                delete map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
    for (int i = 0; i < Ghost::GhostNum; i++)
        delete ghost_timer[i];

}


