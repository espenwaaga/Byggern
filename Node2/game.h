#ifndef GAME_H
#define GAME_H

typedef struct game_stats{
  uint8_t lives;
} game_stats;

void game_init(uint8_t lives);
void game_get_lives(void);


#endif