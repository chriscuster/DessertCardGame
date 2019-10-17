/*
Christopher Custer
Assignment #5
Description: Playing card game where the winner is decided upon based on their total points.
This game will utilize loops, if statements, and checks. It will have various statements that will
have a dealer deal players their cards. Then the dealer stop giving cards to a plyer when they get 3 cards.
The dealer will then deal his own cards to use to check the players for the purpose of cancellation.
The player with the lowest score wins and it is based on a 3-33 scale.
*/

#include <iostream>
#include <iomanip>
#include "cardDeckType.h"

using namespace std;

int main(int argc, char* argv[])
{
	//The introduction to the game 
	cout << setfill('-') << setw(44) << " " << endl;
	cout << "Welcome to the Lunch Time Dessert 333 Game" << endl;
	cout << setfill('-') << setw(44) << " " << endl;

	//Game initial settings
	cardDeckType deck;
	deck.setDeck(NORMAL);

	//integers and variables for the game
	int player1Card1 = 0;
	int player1Card2 = 0;
	int player1Card3 = 0;
	int player2Card1 = 0;
	int player2Card2 = 0;
	int player2Card3 = 0;
	int dealerCardDraws = 0;
	int dealerCard1 = 0;
	int dealerCard2 = 0;
	int dealerCard3 = 0;
	int dealerCard4 = 0;
	int dealerCard5 = 0;
	int currentCard = 0;

	//if statement for normal gameplay
	if (argc == 1)
	{
		deck.initDeck();
		deck.shuffle();
		deck.cardsRemaining();

		//do while for player cards
		do
		{
			switch (dealerCardDraws)
			{
			case 0:
				player1Card1 = deck.drawCard();
				player2Card1 = deck.drawCard();
				break;
			case 1:
				player1Card2 = deck.drawCard();
				player2Card2 = deck.drawCard();
				break;
			case 2:
				player1Card3 = deck.drawCard();
				player2Card3 = deck.drawCard();
				break;
			default:
				break;
			}
			dealerCardDraws++;
		} while (dealerCardDraws <= 2);

		//player's total card points
		int sumP1 = player1Card1 + player1Card2 + player1Card3;
		int sumP2 = player2Card1 + player2Card2 + player2Card3;

		// shows player 1 and 2's cards
		cout << "Player 1: " << player1Card1 << setfill(' ') << setw(20) << player1Card2 << left << player1Card3 << left << "Total: " << left << sumP1 << endl;
		cout << "Player 2: " << player2Card1 << setfill(' ') << setw(20) << player2Card2 << setw(2) << player2Card3 << setw(2) << "Total: " << setw(1) << sumP2 << endl;


		//reset the number drawn by the dealer
		dealerCardDraws = 0;


		// while dealer has drawn less than 6 cards and no player has 0 cards


		/* As the boolean value inside the while statement is true create a statement where there are if to check the program.
		For round 1 of the while statement where the while is true have the dealer draw a card that is saved to dealerCard1.
		Have a if statement that will check the players cards to see if there is a match
		For round 2 have the dealer draw another card that will check dealerCard1 and if it is the same discard it but if it is unique add it to dealerCard2.
		*/

		while (dealerCardDraws < 5)
		{
			deck.setDeck(NORMAL);
			deck.cardsRemaining();
			currentCard = deck.drawCard();

			// check if dealer has drawn same card
			if (dealerCard1 == 0)
			{
				dealerCard1 = currentCard;
				cout << "Round 1: " << endl;
				cout << "The table card is: " << dealerCard1 << endl;

				if (currentCard == player1Card1)
				{
					player1Card1 = 0;
				}
				if (currentCard == player1Card2)
				{
					player1Card2 = 0;
				}
				if (currentCard == player1Card3)
				{
					player1Card3 = 0;
				}
				if (currentCard == player2Card1)
				{
					player2Card1 = 0;
				}
				if (currentCard == player2Card2)
				{
					player2Card1 = 0;
				}
				if (currentCard == player2Card3)
				{
					player1Card3 = 0;
				}
				cout << "Player 1: " << player1Card1 << " " << player1Card2 << " " << player1Card3 << endl;
				cout << "Player 2: " << player2Card1 << " " << player2Card2 << " " << player2Card3 << endl;
							   				 			  
			}
			
			while (dealerCard2 == 0)
			{
				if (deck.drawCard() != dealerCard1)
				{

					dealerCard2 = currentCard;
					cout << "Round2: " << endl;
					cout << "The Table card is: " << dealerCard2 << endl;

					if (currentCard == player1Card1)
					{
						player1Card1 = 0;
					}
					if (currentCard == player1Card2)
					{
						player1Card2 = 0;
					}
					if (currentCard == player1Card3)
					{
						player1Card3 = 0;
					}
					if (currentCard == player2Card1)
					{
						player2Card1 = 0;
					}
					if (currentCard == player2Card2)
					{
						player2Card1 = 0;
					}
					if (currentCard == player2Card3)
					{
						player1Card3 = 0;
					}
					cout << "Player 1: " << player1Card1 << " " << player1Card2 << " " << player1Card3 << endl;
					cout << "Player 2: " << player2Card1 << " " << player2Card2 << " " << player2Card3 << endl;

				}
				else
				{
					currentCard = deck.drawCard();
				}

			}


			









		}








	}








	//Test code for argument 2 
	/*
	cout << "Argument Count: " << argc << endl;
	if (argc == 2)
	{
		deck.initDeck();
		deck.shuffle();
		cout << "Draw a card: " << deck.drawCard() << endl;
	}
	*/


}

