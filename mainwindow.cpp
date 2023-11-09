#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("pac-man"));

    /* Initialize graphicsview and game scene */
    ui->graphicsView->setStyleSheet("QGraphicsView {border: none;}");
    ui->graphicsView->setBackgroundBrush(Qt::black);
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);


    int w = (map_width * GameObject::Width);
    int h = (map_height * GameObject::Width);
    resize(w + xx, h + yy + 20);
    ui->graphicsView->setGeometry(xx, yy, w, h);
    game = new Game(xx, yy, map_width, map_height, "C:/Users/Diashka/Documents/PACMEN/game_objects/map_objects/map.txt");
    ui->graphicsView->setScene(game);
    initLabels();
    game->start();
    game->stop();
}


/* Initialize UI */
void MainWindow::initLabels()
{
    score_title = new QLabel(this);
    score_title->setText("score");
    score_title->show();
    score_title->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    score_title->setGeometry(50, 12, 60, 26);

    score = new QLabel(this);
    score->setIndent(-80);
    score->setText("0");
    score->show();
    score->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    score->setGeometry(110, 12, 150, 26);

    win_label = new QLabel(this);
    win_label->hide();
    win_label->setText("You win!");
    win_label->setStyleSheet("QLabel {font-family: Fixedsys;color: yellow;font-size: 16px;}");
    win_label->setGeometry(300, 12, 150, 26);

    lose_label = new QLabel(this);
    lose_label->hide();
    lose_label->setText("You lose!");
    lose_label->setStyleSheet("QLabel {font-family: Fixedsys;color: red;font-size: 16px;}");
    lose_label->setGeometry(300, 12, 150, 26);

    pause_label = new QLabel(this);
    pause_label->show();
    pause_label->setText("II pause");
    pause_label->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    pause_label->setGeometry(500, 12, 150, 26);

    score_timer = new QTimer(this);
    score_timer->start(25);
    connect(score_timer, SIGNAL(timeout()), this , SLOT(update_score()));

    for (int i = 0; i < PACMAN_LIVES; ++i){
        QPixmap pix("C:/Users/Diashka/Documents/PACMEN/game_objects/pacman/a3.png");
        QLabel *label = new QLabel(this);
        label->setPixmap(pix);
        label->setGeometry(10 + i*GameObject::Width, yy + map_height*GameObject::Width, GameObject::Width, GameObject::Width);
        lives_label.append(label);
    }
    connect(game, SIGNAL(lose_life()), this, SLOT(lose_life()));
}


/* Update score UI */
void MainWindow::update_score()
{
    score->setText(QString::number(game->get_score()));
    if (game->stat == Game::Win) {
        win_label->show();
        score_timer->stop();
    } else if (game->stat == Game::Lose) {
        lose_label->show();
        score_timer->stop();
    }
}


void MainWindow::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_W:
        if (game->stat == Game::Pause) game->_continue(), pause_label->hide();
        game->pacman_next_direction(GameObject::Up);
        break;
    case Qt::Key_A:
        if (game->stat == Game::Pause) game->_continue(), pause_label->hide();
        game->pacman_next_direction(GameObject::Left);
        break;
    case Qt::Key_S:
        if (game->stat == Game::Pause) game->_continue(), pause_label->hide();
        game->pacman_next_direction(GameObject::Down);
        break;
    case Qt::Key_D:
        if (game->stat == Game::Pause) game->_continue(), pause_label->hide();
        game->pacman_next_direction(GameObject::Right);
        break;
    case Qt::Key_Escape:
        if (game->stat != Game::Win && game->stat != Game::Lose){
            game->stop();
            pause_label->show();
        }
        break;
    }
}

void MainWindow::lose_life(){
    for (int i = PACMAN_LIVES - 1; i >= 0; --i)
        if (lives_label[i]->isVisible()) {
           lives_label[i]->hide();
           break;
        }
}


MainWindow::~MainWindow()
{
    delete ui;
}

