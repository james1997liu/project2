//
//  ChutesAndLaddersGame.cpp
//
#include <iostream>
#include <string>
#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// TODO: implement the constructor with all your team members
// constructor with the default value of  a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
   // TODO: implement this function properly
   //throw std::logic_error("not implemented yet");
	Player James;
	James.setName("James");
	Player Ryan;
	Ryan.setName("Ryan");
	playerList.enqueue(James);
	playerList.enqueue(Ryan);
}

// TODO: implement the destructor
// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() 
{
	while (!playerList.empty())
	{
		playerList.dequeue();
	}
   // TODO: implement this function properly
   //throw std::logic_error("not implemented yet");
}

// TO DO: implement this function properly
// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
	while (!playerList.empty())
	{
		playerList.dequeue();
	}
	Player James;
	James.setName("James");
	Player Ryan;
	Ryan.setName("Ryan");
	playerList.enqueue(James);
	playerList.enqueue(Ryan);
   // TODO: implement this function properly
   //throw std::logic_error("not implemented yet");
}

// TO DO: implement this function properly
// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {
   // TODO: implement this function properly
   //throw std::logic_error("not implemented yet");
	while (winner == "There is no winner")
	{
		Player temp = playerList.front();
		temp.setPostion(temp.rollDieAndMove());
		temp.setPostion(gameBoard.checkChutesLadders(temp.getPostion()));
		if (temp.getPostion() == WINNING_POSITION)
		{
			winner = temp.getName();
			cout << "The winner is " << winner << endl;
			resetGame();
		}
		else if (temp.getPostion() != WINNING_POSITION)
		{
			playerList.dequeue();
			playerList.enqueue(temp);
		}
	}
	
}