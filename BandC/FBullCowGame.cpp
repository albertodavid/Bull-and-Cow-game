#include "FBullCowGame.h"

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

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString a)
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
