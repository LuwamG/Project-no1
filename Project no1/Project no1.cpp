// Project 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Banking: Foreign currency exchange 

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;
int main()
{
    string user_name;
    //int account_number;
    // if new create account and use rand to generate account number
    //bool found = true;
    // int birthyear;
    //int feedback;
    const int max_countryNum = 10;
    string countries[max_countryNum];
    string country;
    srand(time(0));
    //double rate;
    int accountNum = rand();
    int count = 0;
    double transfer_fare;
    double total;
    double amount_transfer;
    int points;
    int times_sent;
    string new_user;

    cout << "Enter user name, type new if you are new user : ";
    cin >> user_name;

    if (user_name == "new") {
        cout << "To create new account. Select your desired user name: ";
        cin >> user_name;
        cout << "This is your new account: " << user_name << endl;
        cout << "Your account number is: " << accountNum << endl;
    }
    cout << "Select country to see rate (enter done after you finish): " << endl;

    while (count < max_countryNum) {
        getline(cin >> ws, country);
        if (country == "done") {
            break;
        }
        countries[count] = country;
        count++;
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

        cout << setw(12) << left << countries[i] << "   |   " << setw(12) << right << transfer_fare << "| " << endl;
        cout << "The total amount of " << countries[i] << " is " << total << " $" << endl;
    }
 return 0;
}
