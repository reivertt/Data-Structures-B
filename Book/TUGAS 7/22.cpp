#include <iostream>
#include <random>
using namespace std;

double f(double x) {
    // Define your function f(x) here
    return x * x;  // Example: f(x) = x^2
}

double estimateIntegral(int numPoints) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);

    int pointsUnderCurve = 0;

    for (int i = 0; i < numPoints; i++) {
        double x = dist(gen);
        double y = dist(gen);

        if (y < f(x)) {
            pointsUnderCurve++;
        }
    }

    double integral = static_cast<double>(pointsUnderCurve) / numPoints;
    return integral;
}

int main() {
    const int numPoints = 1000000;
    double integral = estimateIntegral(numPoints);

    cout << "Estimated integral of f(x) from 0 to 1: " << integral << endl;

    return 0;
}
