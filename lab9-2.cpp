//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{

int carPrice= 0;
int rebate=0 ; 
double creditRate= 0.0;
double dealerRate=0;
int term=0 
double creditpayment=0.0;
double dealerpayment=0.0; 

    cout<<"Car price (after any trade in): ";
    cin>>carPrice;
    cout<< "Rebate:";
    cin>>rebate;
    cout<<"Credit union rate: ";
    cin>>creditRate;
    cout<<"Dealer rate: ";
    cin>>dealerRate;
    cout<<"Term in years: " ;
    cin>> term;

//caculate payment
    
    creditpayment= getPayemnt(carPrice - rebate,
        creditRate/12, term * 12);
    dealerPayment= getPayment(carPrice,dealerRate/ 12,
        term * 12);

    //display payment

    cout<<fixed<< setprecision(2)
    cout<<"Credit union payment:  $"
    <<creditPayment<<endl; 
    cout<<"Dealer payment; $"
        <<dealerPayment<<endl; 

    return 0;
}//end of main function    
