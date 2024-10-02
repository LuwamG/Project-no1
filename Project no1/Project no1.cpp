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
    //double rate;
    int accountNum = rand();
    int count = 0;
    double amount_transfer;
    int points;
    int times_sent;
    string new_user;

    cout << "Enter user name, type new if you are new user : ";
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
    cout << "Select country to see rate (enter done after you finish): " << endl;

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


    cout << "How much money do you want to send?" << endl;
    cin >> amount_transfer;

    cout << "How many times have you sent money before?" << endl;
    cin >> times_sent;
    points = times_sent * 2;
    cout << "You have collected " << points << " points." << endl;

    //cout << "This are the countries you entered and their rates of exchange: " << endl;
    cout << setw(12) << left << "|  country" << "   |   " << setw(12) << right << " transfer_fare" << "| " << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        double transfer_fare = calculateTransferFare(countries[i]);

        if (countries[i] == "Eritrea" || countries[i] == "Ethiopia" || countries[i] == "Sudan" || countries[i] == "Uganda") {
            transfer_fare = 0.05;


        }
        else if (countries[i] == "Holand" || countries[i] == "Germany" || countries[i] == "England") {
            transfer_fare = 0.03;


        }
        else if (countries[i] == "Australia" || countries[i] == "China") {
            transfer_fare = 0.025;

        }
        else {
            cout << "Sorry we do not have the service you require." << endl;
            continue;
        }

        total = amount_transfer + (transfer_fare * amount_transfer) - (amount_transfer * points / 1000);

    for (int i = 0; i < transactionCount; i++) {
        cout << setw(12) << left << transactionCountries[i]
            << "   |   " << setw(15) << right << fixed << setprecision(2) << transactionAmounts[i]
            << "   |   " << setw(12) << right << fixed << setprecision(3) << transactionFares[i]
            << "   |   " << setw(12) << right << fixed << setprecision(2) << transactionTotals[i] << "| " << endl;
    }
 return 0;
}
