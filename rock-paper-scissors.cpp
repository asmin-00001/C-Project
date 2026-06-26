#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to convert number to choice name
string getChoiceName(int choice)
{
    if (choice == 1) return "Rock";
    if (choice == 2) return "Paper";
    return "Scissors";
}

// Function to decide winner
void decideWinner(int player, int computer)
{
    cout << "\nYou chose: " << getChoiceName(player);
    cout << "\nComputer chose: " << getChoiceName(computer) << "\n\n";

    if (player == computer)
    {
        cout << "Result: Draw!\n";
    }
    else if (
        (player == 1 && computer == 3) || // Rock beats Scissors
        (player == 2 && computer == 1) || // Paper beats Rock
        (player == 3 && computer == 2)    // Scissors beats Paper
    )
    {
        cout << "Result: You Win!\n";
    }
    else
    {
        cout << "Result: You Lose!\n";
    }
}

int main()
{
    srand(time(0)); // seed random generator

    int playerChoice;
    char playAgain;

    do
    {
        cout << "\n===== ROCK PAPER SCISSORS =====\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Enter your choice: ";
        cin >> playerChoice;

        // input validation
        if (playerChoice < 1 || playerChoice > 3)
        {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        int computerChoice = rand() % 3 + 1;

        decideWinner(playerChoice, computerChoice);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing!\n";

    return 0;
}