// main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PlayGame();
void PrintIntro(int32 Chances);
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //Global access, se crea al ejecutar el codigo, antes del main

int main()
{
    bool bPlayAgain = false;
    BCGame.SetMaxTries(5);

    do
    {
        PlayGame();
        bPlayAgain = AskToPlayAgain();
        BCGame.Reset();

    } while (bPlayAgain);

    return 0;
}



void PrintIntro(int32 Chances)
{
    constexpr int32 WORLD_LENGHT = 6;

    //Introduce the game
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the isogram i'm thinking of?\n\n";
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
        FText Guess = GetGuess();

        FBullCowCount BullCowCount =  BCGame.SubmitGuess(Guess);
        std::cout << "Bulls = " << BullCowCount.Bulls <<"\n";
        std::cout << "Cows = " << BullCowCount.Cows << "\n\n";
    }
}

FText GetGuess() 
{
    //Get a guess from the player
    std::cout << "Enter guess: ";
    FText Guess;
    getline(std::cin, Guess);
    std::cout <<"Try: " << BCGame.GetCurrentTry()<<". \n";
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n)";
    FText Response = "";
    getline(std::cin, Response);

    return (Response[0] == 'y') || (Response[0] == 'Y');

}