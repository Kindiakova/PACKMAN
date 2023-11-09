#ifndef OPTIONS_H
#define OPTIONS_H


/* Changeable game options */
#define BALL_SCORE          10          // score of balls
#define POWERBALL_SCORE     30          // score of powerballs
#define GHOST_SCORE         50          // score of ghosts
#define INTERVAL            10          // move interval of pacman
#define NORMAL_INTERVAL     10          // move interval of normal ghosts
#define PANNIC_INTERVAL     15          // move interval of pannic ghosts
#define RUNNING_INTERVAL    5           // move interval of running ghosts
#define PANNIC_TIME         1000        // interval number of pannic ghosts
#define FLASH_INTERVAL      200         // flash interval
#define SAFE_INTERVAL       1000         // interval after pacman is revived when he is invulnerable
#define PACMAN_LIVES        3           // Amount of pacman lifex
const int GHOST_RELEASE_TIME[] = {0, 200, 400, 600};
const int map_height = 30, map_width = 29; // map size
const int xx = 0, yy = 50;

#endif // OPTIONS_H
