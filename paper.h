#ifndef PAPER_H//preprocessor guards
#define PAPER_H
#include "tool.h"

class Paper: public Tool{
   public:
      Paper();
      Paper(int);
      void operator=(const Paper &);
      void set_strength(int);
      int fight(Tool);//fight function polymorphs depending on what tool is used
};
#endif
