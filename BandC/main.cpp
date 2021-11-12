// main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PlayGame();
void PrintIntro(int32 Chances);
FText GetValidGuess();
void AskToPlayAgain();

FBullCowGame BCGame; //Global access, se crea al ejecutar el codigo, antes del main

int main()
{
    bool bPlayAgain = false;
    BCGame.SetMaxTries(5);

    do
    {
        PlayGame();
        AskToPlayAgain();

    } while (bPlayAgain);

    return 0;
}



void PrintIntro(int32 Chances)
{
    //Introduce the game

    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the "<< BCGame.GetHiddenWordLength()<<" isogram i'm thinking of?\n\n";
    return;
}

void PlayGame()
{

    int32 MaxTries = BCGame.GetMaxTries();
    BCGame.SetHiddenWord();

    //Loop for the number of turns
    PrintIntro(MaxTries);

    for (int32 i = 0; i < MaxTries; i++)
    {
        FText Guess = GetValidGuess();

        FBullCowCount BullCowCount =  BCGame.SubmitValidGuess(Guess);
        std::cout << "Bulls = " << BullCowCount.Bulls <<"\n";
        std::cout << "Cows = " << BullCowCount.Cows << "\n\n";
        if (BCGame.IsGameWon(BullCowCount))
        {
            std::cout << "Congrats, you won!\n\n" << std::endl;
            AskToPlayAgain();
        }
    }
    std::cout << "Gameover, that was your last chance!\n\n" << std::endl;
    AskToPlayAgain();
}

FText GetValidGuess() 
{
    //Get a guess from the player

    EWordStatus Status = EWordStatus::Invalid_Status;

    do
    {
        std::cout << "Enter guess: ";
        FText Guess;
        getline(std::cin, Guess);
        std::cout << "Try: " << BCGame.GetCurrentTry() + 1 << ". \n";

        Status = BCGame.CheckGuessValidity(Guess);

        switch (Status)
        {
        case EWordStatus::Not_Isogram:

            std::cout << "Please enter an isogram\n\n";

            break;
        case EWordStatus::Not_Same_Length:

            std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letters word\n\n";

            break;
        case EWordStatus::Not_Lowercase:

            std::cout << "Please enter a lowercase word\n\n";

            break;
        default:
            return Guess;
        }
    } while (Status != EWordStatus::OK);
    
    return "Something Failed";
}

void AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n)";
    FText Response = "";
    getline(std::cin, Response);

    if (Response[0] == 'y' || Response[0] == 'Y') {
        BCGame.Reset();
        PlayGame();
    }
    else {
        
    }

}