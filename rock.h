#ifndef ROCK_H
#define ROCK_H
#include "Tool.h"

class Rock: public Tool{
   public:
      Rock();
      Rock(int);
      void operator=(const Rock &);
      void set_strength(int);
      int fight(Tool);
};
#endif
