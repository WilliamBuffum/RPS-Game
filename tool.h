#ifndef TOOL_H
#define TOOL_H

class Tool {
   protected:
      int strength;
      char type;
   public:
      Tool();
      Tool(int);
      void operator=(const Tool &);
      virtual void set_strength(int);
      void set_type(char);
      char get_type();
      int get_strength();
      virtual int fight(Tool){}
};

#endif
