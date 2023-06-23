/*
Auth : Muhammad Nabil Akhtar Raya Amoriza | 5025221021
Problem :  The Lotto requires people to pick seven numbers from the numbers 1 to 40. Write a program to \
randomly generate and print five sets of seven numbers each (one set per line). No number is to be      \
repeated in any of the sets; that is, exactly 35 of the 40 numbers must be used. If a number ( p, say)  \
is generated that has been used already, the first unused number after p is used. (Assume that 1        \
follows 40.) For example, if 15 is generated but has been used already, 16 is tried, but if this has    \
been used, 17 is tried, and so on, until an unused number is found.
*/

#include <iostream>
#include <vector>
#include <time.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

int dist(int a, int b){
    int offset = rand() / (RAND_MAX + 1.0) * (b - a + 1);
    return a + offset;
}

vector<int> generate() {
    vector<int> lotto;
    vector<bool> used(41, false);

    for (int i = 0; i < 7; i++) {
        int number = dist(1, 40);

        while (used[number]) {
            number = (number % 40) + 1;
        }

        lotto.push_back(number);
        used[number] = true;
    }

    return lotto;
}

void print_lotto(const vector<vector<int>>& lottoSets) {
    for (const auto& lotto : lottoSets) {
        for (int number : lotto) {
            cout << number << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    const int n = 5;
    vector<vector<int>> lottoSets;

    for (int i = 0; i < n; i++) {
        vector<int> lotto = generate();
        lottoSets.push_back(lotto);
    }

    cout << "Generated Lotto Sets:" << endl;
    print_lotto(lottoSets);

    return 0;
}