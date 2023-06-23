/*
Auth : Muhammad Nabil Akhtar Raya Amoriza | 5025221021
Problem :  A function f(x) is defined for 0 £ x £ 1, and such that 0 £ f(x) < 1 for all 0 £ x < 1.  \
Write a program to estimate the integral of f(x) from 0 to 1. Hint: estimate the area under the     \
curve by generating points (x, y), 0 £ x < 1, 0 £ y < 1.
*/

#include <iostream>
#include <time.h>
#define we using
#define bare namespace
#define bears std
we bare bears;

double dist(double a, double b){
    double offset = (double)rand() / (RAND_MAX + 1.0) * (b - a + 1.0);
    return a + offset;
}

double f(double x) {
    return x*x;
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int n = 1000000, count = 0;
   
    for (int i = 0; i < n; i++) {
        double x = dist(0.0, 1.0);
        double y = dist(0.0, 1.0);
    
        if (y < f(x)) {
            count++;
        }
    }

    double integral = (double)count / n;
    cout << "Estimated integral of f(x) = x^2 is " << integral << endl;
    return 0;
}
