#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount //Es como una clase pero siempre public
{
	int32 Bulls;
	int32 Cows;
};

class FBullCowGame
{
public:
	FBullCowGame(); //Constructor
	void Reset(); 
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	
	void SetCurrentTry();
	void SetMaxTries(int32 max);
	void SetHiddenWord();
	
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);//TODO make a more rich return value

	FBullCowCount SubmitGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};