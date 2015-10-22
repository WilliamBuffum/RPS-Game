#include "tool.h"
#include "scissors.h"

//default constructor
Scissors::Scissors(){
   strength = 1;
   type = 's';
}

//parameterized constructor
Scissors::Scissors(int i){
   strength = i;
   type = 's';
}

//assignment operator overload in case someone needed it
void Scissors::operator=(const Scissors &temp){
   strength = temp.strength;
}

//polymorphs Tool pointer to set strength here
void Scissors::set_strength(int i){
   strength = i;
}

//fight function determines whether human or computer wins or if there is a tie
//strength is *2 in for both traditional wins and loses because if the user 
//changes the strength level of any tool, then it may change the outcome of the
//fight
int Scissors::fight(Tool tool_name){
   if(tool_name.get_type() == 'p'){
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
   else if(tool_name.get_type() == 'r'){
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
