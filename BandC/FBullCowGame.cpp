#include "FBullCowGame.h"
#include <iostream>
#include <set>
#include <map>

#define TMap std::map
#define TSet std::set

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset(); //Esto se va ejecutar cada vez que llamemos a un objeto nuevo
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 0;
}

int32 FBullCowGame::GetMaxTries() const {	return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const  { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length();}

void FBullCowGame::SetCurrentTry()
{
	MyCurrentTry++;
}

void FBullCowGame::SetMaxTries(int32 max)
{
	MyMaxTries = max;
}

void FBullCowGame::SetHiddenWord()
{
	const FString HIDDEN_WORD = "plant";
	MyHiddenWord = HIDDEN_WORD;
}

bool FBullCowGame::IsGameWon(FBullCowCount FBFBullCowCount) const
{
	if (FBFBullCowCount.Bulls == MyHiddenWord.length())
	{
		return true;
	}
	else
	{
		return false;
	}
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	FString LowGuess;
	TSet <char> SetOfCharacters;

	for (int i = 0; i < Guess.length(); i++)
	{
		LowGuess.push_back(std::tolower(Guess[i]));
		SetOfCharacters.insert(Guess[i]);
	}

	if (MyHiddenWord.length() != Guess.length())
	{
		return EWordStatus::Not_Same_Length;
	}
	else if (LowGuess != Guess)
	{
		return EWordStatus::Not_Lowercase;
	}
	else if (SetOfCharacters.size() != MyHiddenWord.length())
	{
	return EWordStatus::Not_Isogram;
	}
	else
	{
		return EWordStatus::OK;
	}

}

FBullCowCount FBullCowGame::SubmitValidGuess(FString a)
{
	SetCurrentTry();

	FString Guess = a;

	FBullCowCount BullCowCount;

	BullCowCount.Bulls = 0;
	BullCowCount.Cows = 0;

	for (int32 i = 0; i < MyHiddenWord.length(); i++)
	{
		for (int32 j = 0; j < MyHiddenWord.length(); j++)
		{
			if (MyHiddenWord[i] == Guess[j] && i == j)
			{
				BullCowCount.Bulls++;
			}
			else if (MyHiddenWord[i] == Guess[j] && i != j)
			{
				BullCowCount.Cows++;
			}
		}

	}

	return BullCowCount;
}
