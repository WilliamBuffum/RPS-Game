#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "RPSgame.h"
#include "Tool.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "playgame.h"

using namespace std;

//play_game allows the user to player a certain number of rounds
void play_game(){
   struct strength_level str;//struct to hold and mods to strength levels
   RPSgame game;
   int i = 0;
   char choice;
      
   cout << "\e[2J" << "\e[K" << "\e[H";

   //sets the number of rounds in a specific game
   cout << "How many rounds would you like to play?: ";
   cin >> i;
   game.set_best_of(i);

   //lets the player modify the strength level if they so choose
   cout << "Would you like to change the strength levels of any tool (y/n): ";
   cin >> choice;
   modify_strength(str, choice);
   cout << "\e[2J" << "\e[K" << "\e[H";

   do {
      //computer AI to select tool 
      //uses random number generator (1-3) 
      //to select rock, paper or scissors
      artificial_choice(choice);
      game.set_computer(choice);
      set_tools(str, choice, i);//sets the proper strength level

      //changes the strength level of a rock, paper, or scissors
      game.get_computer()->set_strength(i);

      cout << "Rock (r), Paper (p), or Scissors (s)?: ";
      cin >> choice;
      while(choice != 'r' and choice != 'p' and choice != 's'){
	 cout << "Error: Bad Input: ";
	 cin >> choice;
      }

      //inputs users selected tool type (r, p, s)
      //allocates memory for the tool type
      //sets human pointer to that tool type
      game.set_human(choice);

      set_tools(str, choice, i);//sets the proper strength level

      //takes the strength returned in i and stores it in the strength of tool
      game.get_human()->set_strength(i);

      //fights human versus the computer
      //takes in the type of computer
      //outputs 1-winner, 2-tie, 0-loser
      game.get_human()->fight(*(game.get_computer()));

      cout << "The computer chose: " << game.get_computer()->get_type() << endl;

      //sets the counters for win, loss, or tie
      switch(game.get_human()->fight(*(game.get_computer()))){
	 case 1:
	    game.set_num_wins(1);
	    break;
	 case 2:
	    game.set_num_ties(1);
	    break;
	 default:
	    game.set_num_losses(1);
	    break;
      }

      cout << "\e[2J" << "\e[K" << "\e[H";
      //prints the number of wins, losses, and ties after each round
      cout << "\nhuman wins: " << game.get_num_wins() << endl;
      cout << "computer wins: " << game.get_num_losses() << endl;
      cout << "ties: " << game.get_num_ties() << "\n" << endl;

      //below two functions print when the player wins or loses a game
      if(game.get_num_wins() >= game.get_best_of()){
	 cout << "You won!" << endl;
      }
      else if(game.get_num_losses() >= game.get_best_of()){
	 cout << "You lost!" << endl;
      }

      //determines win or loss
   }while(game.get_num_wins() < game.get_best_of() and
	 game.get_num_losses() < game.get_best_of());
}

//function allows computer selection of r/p/s
void artificial_choice(char &choice){
   int i = 0;

   srand(time(NULL));//srand uses time as a seed for rand
   i = rand() % 3 + 1;
   if(i == 1){
      choice = 'r';
   }
   else if(i == 2){
      choice = 'p';
   }
   else{ choice = 's'; }
}
   

//this function is used when the user wants to modify a tools initial strength 
void modify_strength(strength_level &str, char choice){
   str.rock_level = 1;
   str.paper_level = 1;
   str.scissor_level = 1;
   while(choice == 'y'){
      cout << "Change the level of Rock (r), Paper (p), or Scissors (s): ";
      cin >> choice;
      if(choice == 'r'){
	 cout << "What starting whole number would you like Rock to be?: ";
	 cin >> str.rock_level;
      }
      else if(choice == 'p'){
	 cout << "What starting whole number would you like Paper to be?: ";
	 cin >> str.paper_level;
      }
      else if(choice == 's'){
	 cout << "What starting whole number would you like Scissors to be?: ";
	 cin >> str.scissor_level;
      }
      cout << "Would you like to modify another tool's strength? (y/n): ";
      cin >> choice;
   }
}

//this function sets the strength level of the tool 
void set_tools(strength_level str, char choice, int &i){
   if(choice == 'r'){
      i = str.rock_level;
   }
   else if(choice == 'p'){
      i = str.paper_level;
   }
   else{
      i = str.scissor_level;
   }
}
