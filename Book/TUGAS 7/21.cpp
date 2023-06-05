#include <iostream>
#include <random>
#include <vector>
using namespace std;

vector<int> generateLottoSet() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 40);

    vector<int> lottoSet;
    vector<bool> usedNumbers(41, false); // Index 0 is unused

    for (int i = 0; i < 7; i++) {
        int number = dist(gen);

        while (usedNumbers[number]) {
            number = (number % 40) + 1;
        }

        lottoSet.push_back(number);
        usedNumbers[number] = true;
    }

    return lottoSet;
}

void printLottoSets(const vector<vector<int>>& lottoSets) {
    for (const auto& lottoSet : lottoSets) {
        for (int number : lottoSet) {
            cout << number << " ";
        }
        cout << endl;
    }
}

int main() {
    const int numSets = 5;
    vector<vector<int>> lottoSets;

    for (int i = 0; i < numSets; i++) {
        vector<int> lottoSet = generateLottoSet();
        lottoSets.push_back(lottoSet);
    }

    cout << "Generated Lotto Sets:" << endl;
    printLottoSets(lottoSets);

    return 0;
}
