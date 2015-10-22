#include "Tool.h"//includes the Tool functions because Paper inherits from tool
#include "Paper.h"//.h for prototypes of class functions here

//default constructor
Paper::Paper(){
   strength = 1;
   type = 'p';
}

//parameterized constructor
Paper::Paper(int i){
   strength = i;
   type = 'p';
}

//assignment operator overload
void Paper::operator=(const Paper &temp){
   strength = temp.strength;
}

//polymorphs Tool pointer to set strength here
void Paper::set_strength(int i){
   strength = i;
}

//fight function determines whether human or computer wins or if there is a tie
//strength is *2 in for both traditional wins and loses because if the user 
//changes the strength level of any tool, then it may change the outcome of the
//fight
int Paper::fight(Tool tool_name){
   if(tool_name.get_type() == 'r'){
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
   else if(tool_name.get_type() == 's'){
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
      return 2;//would be paper, in which case it's a tie
   }
}
