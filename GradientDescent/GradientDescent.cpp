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
        double baseValue = x * funct.coefficients.at(i);
        value += pow(baseValue, funct.exponents.at(i));
    }
    return value;
}

void randomGuess(double& x, double& y, double high, double low) {
    default_random_engine generator;
    uniform_real_distribution<double> distribution(low, high);
    x = distribution(generator);
    y = distribution(generator);
}

double gradientDescent(polynomial& funct) {
    double boundX = 5.0;
    double boundY = 5.0;
}

int main()
{

    /*int n;
    cout << "Number of operands: ";
    cin >> n;
    cout << endl << endl;
    */
    //vector< vector<double>> function(n,vector<double>(n)); //creates a 2-dimensional vector that will store coefficients and exponents respectively.
    int n = 3;





    vector< vector<double>> function(n, vector<double>(n));

    /*for (int i = 0; i < n; ++i) { //This will allow users to custom make polynomials. Test case polynomial is sufficient for now.
        cout << "Value for coefficient";
    }*/


    return 0;
}
