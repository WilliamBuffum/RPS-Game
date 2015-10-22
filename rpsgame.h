#ifndef RPSGAME_H
#define RPSGAME_H
#include "tool.h"

class RPSgame {
   private:
      int num_wins;
      int num_ties;
      int num_losses;
      int rounds;
      int best_of;
      Tool* computer;
      Tool* human;
   public:
      RPSgame();
      RPSgame(int);
      RPSgame(const RPSgame &);
      void operator=(const RPSgame &);
      void set_best_of(int);
      int get_best_of()const;
      void set_num_wins(int);
      int get_num_wins()const;
      void set_num_losses(int);
      int get_num_losses()const;
      void set_num_ties(int);
      int get_num_ties()const;
      void set_human(char);
      Tool* get_human()const;
      void set_computer(char);
      Tool* get_computer()const;
      ~RPSgame();
};

#endif
