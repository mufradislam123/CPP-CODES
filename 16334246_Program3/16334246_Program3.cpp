#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
const int SIZE = 10;

char displayMenu() {
    char choice;
    cout << endl;
    cout << "1. Print all customers data" << endl;
    cout << "2. Print names and IDs" << endl;
    cout << "3. Print accounts total" << endl;
    cout << "4. Enter q/Q to quit" << endl;
    cout << endl;
    cout << "Enter your choice, or 'q' to quit: ";
    cin >> choice;

    return choice;
}
void printCustomersData(int* id, string* first_name, string* last_name, double* checking, double* savings, int count) {
    cout << endl;
    cout << left << setw(20) << "Last" << setw(20) << "First" << setw(20) << "ID" << setw(30) << "Savings Account" << setw(30) << "Checking Account" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(20) << last_name[i] << setw(20) << first_name[i] << setw(20) << id[i] << setw(30) << savings[i] << setw(30) << checking[i] << endl;
    }
}
void printNames(string* first_name, string* last_name, int count) {
    string temp;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (first_name[j] > first_name[j + 1]) {
                temp = first_name[j];
                first_name[j] = first_name[j + 1];
                first_name[j + 1] = temp;

                temp = last_name[j];
                last_name[j] = last_name[j + 1];
                last_name[j + 1] = temp;
            }
            else if (first_name[j] == first_name[j + 1]) {
                if (last_name[j] > last_name[j + 1]) {
                    temp = first_name[j];
                    first_name[j] = first_name[j + 1];
                    first_name[j + 1] = temp;

                    temp = last_name[j];
                    last_name[j] = last_name[j + 1];
                    last_name[j + 1] = temp;
                }
            }
        }
    }
    cout << endl;
    cout << left << setw(15) << "First" << setw(15) << "Last" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(15) << first_name[i] << setw(15) << last_name[i] << endl;
    }
    string message = "Total Numbers of Customers is: " + to_string(count);
    cout << endl;
    cout << setw(message.size()) << setfill('*');
    cout << '*' << endl;
    cout << setw(message.size()) << message << endl;
    cout << setw(message.size()) << setfill('*');
    cout << '*' << endl;
    cout << setfill(' ');
}

void printBankTotal(int* id, double* savings, double* checking, int count) {
    double total = 0;
    cout << endl;
    cout << left << setw(20) << "ID" << setw(30) << "Savings Account" << setw(30) << "Checking Account" << setw(30) << "Total" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(20) << id[i] << setw(30) << savings[i] << setw(30) << checking[i] << setw(30) << savings[i] + checking[i] << endl;
        total = total + savings[i] + checking[i];
    }
    cout << endl;

    string message = "The bank total amount is $";
    cout << endl;
    cout << setw(message.size() + 7) << setfill('*');
    cout << '*' << endl;
    cout << setw(message.size()) << message << fixed << setprecision(1) << total << endl;
    cout << setw(message.size() + 7) << setfill('*');
    cout << '*' << endl;
    cout << setfill(' ');
}
int main()
{
    char choice;
    string filename{ "input.txt" }, trash, line;
    int id[SIZE];
    string first_name[SIZE], last_name[SIZE];
    double savings_account_balance[SIZE], checking_account_balance[SIZE];

    int count{ 0 };

    ifstream file;

    //Open the file
    file.open(filename);

    //Display error if file does not open
    if (file.fail())
    {
        cout << "\nCannot open file!" << endl;
        return 1;
    }
    else
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            string id_s, savings, checking, first, last;
            getline(ss, id_s, ' ');
            getline(ss, first, ' ');
            getline(ss, last, ' ');
            getline(ss, savings, ' ');
            getline(ss, checking, ' ');

            id[count] = atoi(id_s.c_str());
            first_name[count] = first;
            last_name[count] = last;
            savings_account_balance[count] = atof(savings.c_str());
            checking_account_balance[count] = atof(checking.c_str());
            count++;
        }
    }

    do {

        choice = displayMenu();
        while (!(choice == '1' or choice == '2' or choice == '3' or choice == 'q' or choice == 'Q')) {
            cout << endl;
            cout << "Wrong input. Try again..." << endl;
            cout << endl;
            choice = displayMenu();
        }

        switch (choice) {
        case '1':
            printCustomersData(id, first_name, last_name, checking_account_balance, savings_account_balance, count);
            break;
        case '2':
            printNames(first_name, last_name, count);
            break;
        case '3':
            printBankTotal(id, savings_account_balance, checking_account_balance, count);
            break;
        }
    } while (choice != 'q' and choice != 'Q');

    cout << endl;
    cout << "Thanks for using my program. Goodbye!!" << endl;
    return 0;
}
