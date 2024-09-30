#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

// Constants
const int max_transactions = 100; // Maximum number of transactions

// Function declarations
void inputUserName(string& user_name, int& accountNum);
void inputCountries(string countries[], int& count, const int max_countryNum);
double calculateTransferFare(const string& country);
void displayResults(const string countries[], int count, double amount_transfer, int points, string transactionCountries[], double transactionAmounts[], double transactionFares[], double transactionTotals[], int& transactionCount);
void displayTransactionHistory(string transactionCountries[], double transactionAmounts[], double transactionFares[], double transactionTotals[], int transactionCount);

int main() {
    const int max_countryNum = 10;
    string countries[max_countryNum];
    string user_name;
    srand(time(0));
    int accountNum = rand()%100'000;  // Random to create account number
    int count = 0;
    double amount_transfer;
    int points;
    int times_sent;

    // Input user information
    inputUserName(user_name, accountNum);

    // Input countries
    inputCountries(countries, count, max_countryNum);

    if (count == 0) {
        cout << "No countries selected. Exiting." << endl;
        return 0;
    }

    // Input transfer amount and previous transfer times
    cout << "How much money do you want to send? ";
    cin >> amount_transfer;

    cout << "How many times have you sent money before? ";
    cin >> times_sent;
    points = static_cast<double>(times_sent) * 2;
    cout << "You have collected " << points << " points." << endl;

    // Transaction history arrays
    string transactionCountries[max_transactions];
    double transactionAmounts[max_transactions];
    double transactionFares[max_transactions];
    double transactionTotals[max_transactions];
    int transactionCount = 0;

    // Display results and store transaction history
    displayResults(countries, count, amount_transfer, points, transactionCountries, transactionAmounts, transactionFares, transactionTotals, transactionCount);

    // Option to view transaction history
    char viewHistory;
    cout << "Would you like to view your transaction history? (y/n): ";
    cin >> viewHistory;

    if (viewHistory == 'y' || viewHistory == 'Y') {
        displayTransactionHistory(transactionCountries, transactionAmounts, transactionFares, transactionTotals, transactionCount);
    }

    return 0;
}

// Function to input the user's name and account number
void inputUserName(string& user_name, int& accountNum) {
    cout << "Enter user name, type 'new' if you are a new user: ";
    cin >> user_name;

    if (user_name == "new") {
        cout << "To create a new account, select your desired user name: ";
        cin >> user_name;
        while (user_name.length() < 4) {
            cout << "Please enter a valid user name (min 4 characters): ";
            cin >> user_name;
        }
        cout << "This is your new account: " << user_name << endl;
        cout << "Your account number is: " << accountNum << endl;
    }
}

// Function to input countries
void inputCountries(string countries[], int& count, const int max_countryNum) {
    string country;
    cout << "Select countries to see rate (enter 'done' after you finish):" << endl;

    while (count < max_countryNum) {
        getline(cin >> ws, country);
        if (country == "done") {
            break;
        }
        countries[count] = country;
        count++;
    }
}

// Function to calculate transfer fare based on the country

double calculateTransferFare(const string& country) {
    if (country == "Eritrea" || country == "Ethiopia" || country == "Sudan" || country == "Uganda") {
        return 0.05;
    }
    else if (country == "Holland" || country == "Germany" || country == "England") {
        return 0.03;
    }
    else if (country == "Australia" || country == "China") {
        return 0.025;
    }
    else {
        return -1.0; // Indicates no service available
    }
}

// Function to display results and store transaction details
void displayResults(const string countries[], int count, double amount_transfer, int points, string transactionCountries[], double transactionAmounts[], double transactionFares[], double transactionTotals[], int& transactionCount) {
    cout << setw(12) << left << "|  Country" << "   |   " << setw(12) << right << "Transfer Fare" << "   |   Total Amount" << " | " << endl;
    cout << "----------------------------------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        double transfer_fare = calculateTransferFare(countries[i]);

        if (transfer_fare < 0) {
            cout << "Sorry, we do not have the service for " << countries[i] << "." << endl;
            continue;
        }

        double total = amount_transfer + (transfer_fare * amount_transfer) - (amount_transfer * points / 1000);

        // Store transaction in history
        transactionCountries[transactionCount] = countries[i];
        transactionAmounts[transactionCount] = amount_transfer;
        transactionFares[transactionCount] = transfer_fare;
        transactionTotals[transactionCount] = total;
        transactionCount++;

        cout << setw(12) << left << countries[i]
            << "   |   " << setw(12) << right << fixed << setprecision(3) << transfer_fare
            << "   |   " << setw(12) << right << fixed << setprecision(2) << total << "| " << endl;

        //cout << "The total amount for sending to " << countries[i] << " is " << fixed << setprecision(2) << total << " $" << endl;
    }
}

// Function to display transaction history
void displayTransactionHistory(string transactionCountries[], double transactionAmounts[], double transactionFares[], double transactionTotals[], int transactionCount) {
    cout << "\nTransaction History:" << endl;
    cout << setw(12) << left << "|  Country" << "   |   " << setw(15) << right << "Amount Transferred" << "   |   Transfer Fare" << "   |   Total Amount" << " | " << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < transactionCount; i++) {
        cout << setw(12) << left << transactionCountries[i]
            << "   |   " << setw(15) << right << fixed << setprecision(2) << transactionAmounts[i]
            << "   |   " << setw(12) << right << fixed << setprecision(3) << transactionFares[i]
            << "   |   " << setw(12) << right << fixed << setprecision(2) << transactionTotals[i] << "| " << endl;
    }
}
