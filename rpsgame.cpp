#include "tool.h"
#include "rock.h"
#include "paper.h"
#include "scissors.h"
#include "rpsgame.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//default constructor to intialize values upon instance of object
RPSgame::RPSgame(){
   num_wins = 0;
   num_ties = 0;
   num_losses = 0;
   rounds = 0;
   best_of = 3;
   computer = NULL;
   human = NULL;
}

//parameterized constructor
RPSgame::RPSgame(int i){
   num_wins = 0;
   num_ties = 0;
   num_losses = 0;
   rounds = 0;
   best_of = i;
   computer = NULL;
   human = NULL;
}

//copy constructor
RPSgame::RPSgame(const RPSgame &temp){
   num_wins = temp.num_wins;
   num_ties = temp.num_ties;
   num_losses = temp.num_losses;
   rounds = temp.rounds;
   best_of = temp.best_of;
   computer = temp.computer;
   human = temp.human;
}

//assignment operator overload
void RPSgame::operator=(const RPSgame &temp){
   num_wins = temp.num_wins;
   num_ties = temp.num_ties;
   num_losses = temp.num_losses;
   rounds = temp.rounds;
   best_of = temp.best_of;
   computer = temp.computer;
   human = temp.human;
}

//sets the number of rounds to be played
void RPSgame::set_best_of(int i){
   best_of = i;
}

//returns the number of rounds to be played
int RPSgame::get_best_of()const{
   return best_of;
}

//sets the current number of wins by human
void RPSgame::set_num_wins(int i){
   num_wins += i;
}

//gets the current number of wins by human
int RPSgame::get_num_wins()const{
   return num_wins;
}

//sets the number of losses by human
void RPSgame::set_num_losses(int i){
   num_losses += i;
}

//gets the number of losses by human
int RPSgame::get_num_losses()const{
   return num_losses;
}

//sets the number of ties by human
void RPSgame::set_num_ties(int i){
   num_ties += i;
}

//gets the number of ties by human
int RPSgame::get_num_ties()const{
   return num_ties;
}

//set_human function allocates the necessary memory
//for the Tool ptr to use during each round of the game.
//Once the round is over, the destructor frees the memory
//space for the next round if the user wants to play again
void RPSgame::set_human(char i){
   if(i == 'r'){
      human = new Rock;
       
      human->set_type(i);
   }
   else if(i == 'p'){
      human = new Paper;
      human->set_type(i);
   }
   else if(i == 's'){
      human = new Scissors;
      human->set_type(i);
   }
}

//gets the tool ptr once memory has been allocated
Tool* RPSgame::get_human()const{
   return human;
}

//set_computer function allocates the necessary memory
//for the Tool ptr to use during each round of the game.
//Once the round is over, the destructor frees the memory
//space for the next round if the user wants to play again
void RPSgame::set_computer(char i){
   if(i == 'r'){
      computer = new Rock;
      computer->set_type(i);
   }
   else if(i == 'p'){
      computer = new Paper;
      computer->set_type(i);
   }
   else if(i == 's'){
      computer = new Scissors;
      computer->set_type(i);
   }
}

//gets the tool ptr once memory has be allocated
Tool* RPSgame::get_computer()const{
   return computer;
}

//destructor that frees memory once instance is no longer needed
RPSgame::~RPSgame(){
   if(computer != NULL){
      delete [] computer;
      computer = NULL;
   }
   if(human != NULL){
      delete [] human;
      human = NULL;
   }
}
