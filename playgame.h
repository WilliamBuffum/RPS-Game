#ifndef PLAY_GAME_H
#define PLAY_GAME_H

struct strength_level {
   int rock_level;
   int paper_level;
   int scissor_level;
};

void set_tools(strength_level, char, int &);
void modify_strength(strength_level &, char);
void play_game();
void artificial_choice(char &);

#endif
