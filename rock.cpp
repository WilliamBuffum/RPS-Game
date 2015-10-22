#include "tool.h"
#include "rock.h"

//default constructor
Rock::Rock(){
   strength = 1;
   type = 'r';
}

//parameterized constructor
Rock::Rock(int i){
   strength = i;
   type = 'r';
}

//assignment operator overload in case someone needed it
void Rock::operator=(const Rock &temp){
   strength = temp.strength;
}

//polymorphs tool pointer to set strength here
void Rock::set_strength(int i){
   strength = i;
}

//fight function determines whether human or computer wins or if there is a tie
//strength is *2 in for both traditional wins and loses because if the user 
//changes the strength level of any tool, then it may change the outcome of the
//fight
int Rock::fight(Tool tool_name){
   if(tool_name.get_type() == 's'){
      if(this->strength*2 > tool_name.get_strength()){//this player wins
	 return 1;
      }
      else if(this->strength*2 == tool_name.get_strength()){//game is tie
	 return 2;
      }
      else{
	 return 0;//this player loses
      }
   }
   else if(tool_name.get_type() == 'p'){
      //must have following because players can change strength of each tool
      if(this->strength/2 > tool_name.get_strength()){//this player wins
	 return 1;
      }
      else if(this->strength/2 == tool_name.get_strength()){//game is tie
	 return 2;
      }
      else{
	 return 0;//this player loses
      }
   }
   else{
      return 2;//would be rock, in which case it's a tie
   }
}
