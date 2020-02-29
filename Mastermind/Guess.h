#ifndef GUESS_H
#define GUESS_H

#include <utility>
#include <ctime>
#include <iostream>
//This is my own work
class Guess
{
private:
	int aGuess[4];
	bool isValid(int)  const ;
public:
	Guess();
	void setGuess(int,int,int,int);
	void setMaster();
	int operator[](int) const;
};
//implementations 
Guess::Guess()
{
	srand(time(NULL)); 
	aGuess[0] = aGuess[1] = aGuess[2] = aGuess[3] = -1;
}
int Guess::operator[](int index) const 
{
	return aGuess[index];
}
bool Guess::isValid(int a)const 
{
	//Making sure we make a valid array
	return a >= 1 && a <= 6;
}
void Guess::setGuess(int a, int b, int c, int d)
{
	//each variable is tested through isValid to make sure the array is built correctly
	if (isValid(a) == true) 
		aGuess[0] = a;

	if (isValid(b) == true) 
		aGuess[1] = b;
	
	if (isValid(c) == true) 
		aGuess[2] = c;
	
	if (isValid(d) == true) 
		aGuess[3] = d;
}
void Guess::setMaster()
{
	//Rand is used to make the master code and it will not be seen
	aGuess[0] = rand()%6;
	aGuess[1] = rand()%6;
	aGuess[2] = rand()%6;
	aGuess[3] = rand()%6;
}









#endif