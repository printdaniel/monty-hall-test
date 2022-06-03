#include <iostream>
#include <cstdlib>
using namespace std;

int getRandomNumber(int n)
{
    return (1.0 * n * std::rand()) / (1.0 + RAND_MAX);
}

int switchCard(int card1, int card2)
{
    int card3;
    if (card1 == card2)
    {
        card3 = getRandomNumber(2);
        if (card3 >= card1)
            ++card3;
    }
    else
    {
        for (card3 = 0; card3 == card1 || card3 == card2; ++card3)
        {
            // empty
        }
    }
    return card3;
}

int check(int numberOfSimulations, bool changeCard)
{
    int winCounter = 0;
    for (int simulation = 0; simulation < numberOfSimulations; ++simulation)
    {
        int const winningCard = getRandomNumber(3);
        int const originalChoice = getRandomNumber(3);
        int showCard = switchCard(originalChoice, winningCard);

        int const selectedCard = changeCard ?
            switchCard(showCard, originalChoice)
            : originalChoice;

        if (selectedCard == winningCard)
            ++winCounter;
    }

    return winCounter;
}

int main()
{
    int numberOfSimulations = 1000000;
    int stayWins = check(numberOfSimulations, false);
    int switchWins = check(numberOfSimulations, true);

    cout << "Stay wins: " << 100.0 * stayWins / numberOfSimulations << "%\n";
    cout << "Switch wins: " << 100.0 * switchWins / numberOfSimulations << "%\n";

    system("pause>nul");
}
