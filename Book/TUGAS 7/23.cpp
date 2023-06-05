#include <iostream>
#include <random>
using namespace std;

int playGame() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dice(1, 6);
    uniform_int_distribution<> cards(1, 13);

    int dice1 = dice(gen);
    int dice2 = dice(gen);
    int sum = dice1 + dice2;

    if (sum % 2 == 0) {
        return -5;  // Even sum, lose $5
    } else {
        int card = cards(gen);

        if (card == 1 || card == 3 || card == 5 || card == 7 || card == 9) {
            return card + 5;  // Odd sum with special card, win card value + $5
        } else {
            return -5;  // Odd sum with other card, lose $5
        }
    }
}

int main() {
    const int numGames = 20;
    int totalAmountWon = 0;

    for (int i = 0; i < numGames; i++) {
        int amountWon = playGame();
        totalAmountWon += amountWon;
    }

    double averageAmountWon = static_cast<double>(totalAmountWon) / numGames;

    cout << "Average amount won per game: $" << averageAmountWon << endl;

    return 0;
}
