#ifndef SCISSORS_H
#define SCISSORS_H
#include "tool.h"

class Scissors: public Tool{
   public:
      Scissors();
      Scissors(int);
      void operator=(const Scissors &);
      void set_strength(int);
      int fight(Tool);
};
#endif
