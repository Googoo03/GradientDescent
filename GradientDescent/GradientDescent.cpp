#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

struct polynomial {
    vector<double> coefficients;
    vector<double> exponents;
};

double functionValue(polynomial& funct, double x, double y) {
    double value = 0;
    for (int i = 0; i < funct.coefficients.size(); ++i) {
        double baseValue = pow(x, funct.exponents.at(i));
        value += baseValue * funct.coefficients.at(i);
    }
    return value;
}

double xGrad(polynomial& funct, double x, double y, double epsilon) {
    double dx = (functionValue(funct, x + epsilon, y) - functionValue(funct, x - epsilon, y)) / (2 * epsilon);
    return dx;
}

double yGrad(polynomial& funct, double x, double y, double epsilon) {
    double dy = (functionValue(funct, x, y+epsilon) - functionValue(funct, x, y-epsilon)) / (2 * epsilon);
    return dy;
}

void randomGuess(double& x, double& y, double high, double low) {
    default_random_engine generator;
    uniform_real_distribution<double> distribution(low, high);
    x = distribution(generator);
    y = distribution(generator);
}

double gradientDescent(polynomial& funct) {
    double high = 5.0;
    double low = -5.0;

    double convergenceTolerance = 0.000000001;

    double x0 = 0;
    double y0 = 0;

    randomGuess(x0, y0, high, low);

    double value = functionValue(funct, x0, y0);
    double prevValue = value;
    double dx, dy;
    double gradient;

    double coeff;
    double stepSize = 0.5;
    double epsilon = 0.0000001;
    double stepSizemultipler = 0.1;

    unsigned maxIterations = 1000;

    for (int i = 0; i < maxIterations; ++i) {
        dx = -1 * xGrad(funct, x0, y0, epsilon);
        dy = -1 * yGrad(funct, x0, y0, epsilon);

        gradient = sqrt((dx*dx) + (dy*dy));

        if (gradient == 0) return value;


        coeff = stepSize / gradient;
        x0 += (coeff * dx);
        y0 += (coeff * dy);

        prevValue = value;
        value = functionValue(funct, x0, y0);

        if (value > prevValue) {
            stepSize *= stepSizemultipler;
        }

        if (abs(prevValue - value) < convergenceTolerance) return value;

        

    }
    return value;
    //double const epsilon = 0.0000001;

    
}

int main()
{
    polynomial x2;
    x2.coefficients = { 1, 2,-1,-1 };
    x2.exponents = { 6, 3,2,1 };

    double finalValue = gradientDescent(x2);
    cout << "the best descent value for x2 is " << finalValue;

    return 0;
}
