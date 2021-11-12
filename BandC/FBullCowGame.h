#pragma once
#include <string>


using FString = std::string;
using int32 = int;

struct FBullCowCount //Es como una clase pero siempre public
{
	int32 Bulls;
	int32 Cows;
};

enum class EWordStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Not_Same_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); //Constructor
	void Reset(); 
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength()const ;

	void SetCurrentTry();
	void SetMaxTries(int32 max);
	void SetHiddenWord();
	
	bool IsGameWon(FBullCowCount FBFBullCowCount) const;
	EWordStatus CheckGuessValidity(FString Guess) const;

	FBullCowCount SubmitValidGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};