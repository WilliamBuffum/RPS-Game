#include "tool.h"

//default constructor to initialize strength value
Tool::Tool(){
   strength = 1;
}

//allows user to set the beginning strength level
Tool::Tool(int i){
   strength = i;
}

//polymorphs to set strength of tool type allocated to tool ptr
void Tool::set_strength(int i){
   strength = i;
}

//assignment operator overload
void Tool::operator=(const Tool &temp){
   type = temp.type;
   strength = temp.strength;
}

//will allow selection of specific derived class
void Tool::set_type(char i){
   type = i;
}

//gets the type of tool tool represents
char Tool::get_type(){
   return type;
}

//polymorphs to get the strength of tool type allocated to tool ptr
int Tool::get_strength(){
   return strength;
}
