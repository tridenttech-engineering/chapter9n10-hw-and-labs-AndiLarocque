//Lab 9-19.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>
#include <iostream>
#include <cmath>
using namespace std;

// Function prototypes
double getPayment(double, double, int);
double totalCost(double, double, int);

int main() {
    double carPrice = 0.0;
    int term = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;

    // User input
    cout << "Enter car price: ";
    cin >> carPrice;
    cout << "Enter loan term (in years): ";
    cin >> term;
    cout << "Enter credit union interest rate (as a percentage): ";
    cin >> creditRate;
    cout << "Enter dealer interest rate (as a percentage): ";
    cin >> dealerRate;

    // Convert annual rates to decimals
    creditRate /= 100.0;
    dealerRate /= 100.0;
    
    // Calculate monthly payments
    double creditPayment = getPayment(carPrice, creditRate, term * 12);
    double dealerPayment = getPayment(carPrice, dealerRate, term * 12);

    // Output monthly payments
    if (creditPayment == -1 || dealerPayment == -1) {
        cout << "Error: Division by zero in payment calculation." << endl;  
    } 
    else {
        cout << "Monthly payment through credit union: $" << creditPayment << endl;
        cout << "Monthly payment through dealer: $" << dealerPayment << endl;

        // Calculate and output total payments
        double totalCreditCost = static_cast<int>(term * 12);
        double totalDealerCost = static_cast<int>(term * 12);

        cout << "Total cost through credit union: $" << totalCreditCost << endl;
        cout << "Total cost through dealer: $" << totalDealerCost << endl;
    }

    return 0;
}

// Function to calculate monthly payment
double getPayment(double principal, double annualRate, int months) {
    double monthlyRate = annualRate / 12.0;
    double denominator = pow(1 + monthlyRate, months) - 1;
    if (denominator == 0) {
        return -1; // Error: Division by zero
    }
    return principal * (monthlyRate * pow(1 + monthlyRate, months)) / denominator;
}

// Function to calculate total cost
double totalCost(double monthlyPayment, int months) {
    return monthlyPayment * months;
}
