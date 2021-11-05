// ======================================
// filename: project1_carter_slc0070.cpp
// author: Sydney Carter
// project: Flow of Control
// sources: I used Project1_hints.pdf as my source code
//          stack overflow links from Piazza(questions 48, 55, 62)
//          Emailed with Dr.Zheng about recognizing string and char input
// compile: compiled with g++, worked on au server

// ======================================

#include <iostream>
#include <limits>
using namespace std;

int main() {
    
    // variable initialization
    double loan_amount;
    double interest_rate;
    double interest_rateC;
    double monthly_payments;
    int current_month = 0;
    double monthly_interest;
    double interest_total;

    // currency formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    using std::cout;
    using std::cin;

    // get user input
    do {
        cout << "Loan Amount: ";
        cin >> loan_amount;
        if (loan_amount <= 0 || !cin) {
            cout << "Please enter a positive amount" << endl;
            cin.clear();
            cin.ignore();
                // numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (loan_amount <= 0);

    //interest rate
    do {
        cout << "Interest Rate (% per year): ";
        cin >> interest_rate;
        if (interest_rate < 0 || !cin) {
            cout << "Please enter a positive amount" << endl;
            cin.clear();
            cin.ignore();
                // numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (interest_rate < 0);

    // calculate interest rate
    interest_rate /= 12;
    interest_rateC = interest_rate / 100;

    // monthly payments
    do {
        cout << "Monthly Payments: ";
        cin >> monthly_payments;
        if (monthly_payments <= (interest_rateC * loan_amount) || !cin) {
            cout << "Please enter sufficient monthly payment." << endl;
            cin.clear();
            cin.ignore();
                // numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (monthly_payments < (interest_rateC * loan_amount));

    
    // cout << "Monthly Payments";
    // cin >> monthly_payments;

    cout << endl;

    // Amortization table
    cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    // loop to fill in table
    while (loan_amount > 0) {
        if (current_month == 0) {
            cout << current_month++ << "\t$" << loan_amount;
                if (loan_amount < 1000) {
                cout << "\t";
                }
            cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
        }
        else {
            // calculate monthly interest rate and total interest
            monthly_interest = loan_amount * interest_rateC;
            interest_total += monthly_interest;
            
            // calculate loan
            loan_amount = (loan_amount * (1 + interest_rateC)) - monthly_payments;
            if (loan_amount < 0) {
                monthly_payments += loan_amount;
                loan_amount = 0;
            }

            // display info in table
            cout << current_month++ << "\t$" << loan_amount << "\t";
            if (loan_amount < 1000) {
                cout << "\t";
            }
            cout << "$" << monthly_payments << "\t" << interest_rate << "\t$"
                << monthly_interest << "\t\t$"
                << monthly_payments - monthly_interest << endl;
        }
    }

    // display loan info
    cout << "*****************************************************************\n";
    cout << "\nIt takes " << -- current_month <<  " months to pay off "
         << "the loan.\n"
         << "Total interest paid is: $" << interest_total;
    cout << endl << endl;
    return 0;

}
