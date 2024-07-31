//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Prototype for the getPayment function
void getPayment(int prin, double monthRate, int months, double &monthPay);

int main() 
{
    int carPrice = 0;       
    int rebate = 0;           
    double creditRate = 0.0;   
    double dealerRate = 0.0;    
    int term = 0;              

    double creditPayment = 0.0;  
    double dealerPayment = 0.0;  


    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;
    
    // Call function to calculate payments
    
    getPayment(carPrice - rebate, creditRate / 12, term * 12, creditPayment);
    
    // Explanation: carPrice - rebate calculates the principal for the credit union.
    // creditRate / 12 converts the annual rate to a monthly rate.
    // term * 12 converts the loan term from years to months.
    // creditPayment is passed by reference to store the result.

    getPayment(carPrice, dealerRate / 12, term * 12, dealerPayment);
    // Explanation: carPrice is the principal for the dealer.
    // dealerRate / 12 converts the annual rate to a monthly rate.
    // term * 12 converts the loan term from years to months.
    // dealerPayment is passed by reference to store the result.

    // Display payments
    cout << fixed << setprecision(2) << endl;
    // Explanation: Set the floating-point number formatting to fixed with 2 decimal places.

    cout << "Credit union payment: $" << creditPayment << endl;
    // Explanation: Output the monthly payment for the credit union.

    cout << "Dealer payment: $" << dealerPayment << endl;
    // Explanation: Output the monthly payment for the dealer.

    return 0;
}

// Function definition for getPayment
void getPayment(int prin, double monthRate, int months, double &monthPay) {
    // Explanation: This function calculates the monthly payment for a loan.
    monthPay = prin * monthRate / (1 - pow(monthRate + 1, -months));
    // Explanation: Use the formula for calculating the monthly payment:
    // monthPay = principal * monthly rate / (1 - (1 + monthly rate)^(-number of months))
}
