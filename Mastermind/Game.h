#ifndef GAME_H
#define GAME_H

#include <cmath>
#include <utility>
#include <ctime>
#include <iostream>
#include "Guess.h"

using namespace std;

//This is my own work - Gaj Carson

class Game
{
private:
	Guess currGuess;
	Guess secretCode;
	int blkPegs, whtPegs, numGuesses;
public:
	Game();
	void playGame();
	void generateFeedback();
	void getUserGuess();
	bool isWinner();
	bool isLoser();


};
Game::Game()
{
	blkPegs = whtPegs = 0;
	numGuesses = 10;
	secretCode.setMaster();
}
void Game::getUserGuess()
{
	cout << "Please enter 4 digits from 1 to 6" << endl;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	currGuess.setGuess(a, b, c, d);
}
bool Game::isWinner()
{
	return blkPegs == 4;
}
bool Game::isLoser()
{
	return numGuesses == 0;
}
void Game::generateFeedback()
{
	blkPegs = whtPegs = 0;

	for (int i = 0; i < 4; i++)
	{
		if(currGuess[i] == secretCode[i])
		blkPegs++;
	
	}
	cout <<  "bp:" << blkPegs << endl;
	
	int guessColor[6];
	int codeColor[6];

	for (int i = 0; i < 6; i++)
	{
		guessColor[i] = codeColor[i] = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		guessColor[currGuess[i]-1]++;
		codeColor[secretCode[i]-1]++;
	}
	int inc = 0;
	for (int i = 0; i < 6; i++)
	{
		int inc = fmin(guessColor[i], codeColor[i]);
		if (inc > 0)
		{
			whtPegs += inc;
		}

	}
	whtPegs = whtPegs - blkPegs;
	cout << "wp:" << whtPegs << endl;
}
void Game::playGame()
{
	do
	{
		getUserGuess();
		generateFeedback();
		numGuesses--;
		if (isWinner()== true)
			cout << "WINNER WINNER!!!" << endl;
		else if (isLoser() == true)
			cout << "LLLOOOSSEEERRR" << endl;
	} while (!isWinner() && !isLoser());
}







#endif