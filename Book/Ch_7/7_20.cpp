/*
Auth: Muhammad Nabil Akhtar Raya Amoriza | 5025221021
Problem : Write a program to simulate the collection of bottle caps to spell apple. In every 100 caps, \
A and E occur 40 times each, and P and L occur 10 times each. Do 50 simulations and print the average  \
number of caps per simulation.
*/

#include <iostream>
#include <time.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

int dist(int a, int b){
    int offset = rand() / (RAND_MAX + 1.0) * (b - a + 1);
    return a + offset;
}

int simulateCollection() {
    int collected = 0, count_a = 0, count_p = 0, count_l = 0, count_e = 0;

    while (true) {
        int cap = dist(1, 100);

        if (cap <= 40) {
            count_a++;
            if (count_a == 1 && count_p >= 1 && count_l >= 2 && count_e >= 1)
                break;
        } else if (cap <= 50) {
            count_p++;
            if (count_a >= 1 && count_p == 1 && count_l >= 2 && count_e >= 1)
                break;
        } else if (cap <= 60) {
            count_l++;
            if (count_a >= 1 && count_p >= 1 && count_l == 2 && count_e >= 1)
                break;
        } else {
            count_e++;
            if (count_a >= 1 && count_p >= 1 && count_l >= 2 && count_e == 1)
                break;
        }

        collected++;
    }

    return collected;
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    const int n = 50;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int collected = simulateCollection();
        ans += collected;
        cout << "Simulation " << i + 1 << ": " << collected << " caps collected." << endl;
    }

    double avg = static_cast<double>(ans) / n;
    cout << "Average number of caps per simulation: " << avg << endl;

    return 0;
}
