#include <iostream>
#include <random>
using namespace std;

int simulateCollection() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int capsCollected = 0;
    int countA = 0, countP = 0, countL = 0, countE = 0;

    while (true) {
        int cap = dist(gen);

        if (cap <= 40) {
            countA++;
            if (countA == 1 && countP >= 1 && countL >= 2 && countE >= 1)
                break;
        } else if (cap <= 50) {
            countP++;
            if (countA >= 1 && countP == 1 && countL >= 2 && countE >= 1)
                break;
        } else if (cap <= 60) {
            countL++;
            if (countA >= 1 && countP >= 1 && countL == 2 && countE >= 1)
                break;
        } else {
            countE++;
            if (countA >= 1 && countP >= 1 && countL >= 2 && countE == 1)
                break;
        }

        capsCollected++;
    }

    return capsCollected;
}

int main() {
    const int numSimulations = 50;
    int totalCapsCollected = 0;

    for (int i = 0; i < numSimulations; i++) {
        int capsCollected = simulateCollection();
        totalCapsCollected += capsCollected;
        cout << "Simulation " << i + 1 << ": " << capsCollected << " caps collected." << endl;
    }

    double averageCaps = static_cast<double>(totalCapsCollected) / numSimulations;
    cout << "Average number of caps per simulation: " << averageCaps << endl;

    return 0;
}
