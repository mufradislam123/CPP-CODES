//Name: Mufrad Islam, ID: 16334246, Program 1, CS201R-0002, Creation date:2/2/22, Due date:2/6/22


#include <iostream>

using namespace std;

int main() {
    cout << "Welcome to KC Cookies\n";
    cout << "We offer 3 different packs of Cookies\n";
    cout << "4 Pack Box\t\t$13.20\n";
    cout << "6 Pack Box\t\t$19.49\n";
    cout << "Party  Box '12'\t$34.08\n";

    int choice;


    int pack = 0;
    double order = 0;
    char askAgain = 'y';
    while (askAgain == 'y' || askAgain == 'Y') {

        cout << "\n\nWhat would you like to order today\n";
        cout << "1 ==> 4-Pack Cookies\n";
        cout << "2 ==> 6-Pack Cookies\n";
        cout << "3 ==> Party Box (12-Pack Cookies)\n";
        cout << "Please enter '1 or 2 or 3' to proceed:\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "How many packs do you want?\n";
            cin >> pack;
            order += pack * 13.20;
            cout << "\nYou ordered: " << pack << " 4-Pack Cookies\n";


            break;
        case 2:
            cout << "How many packs do you want?\n";
            cin >> pack;
            order += pack * 19.49;
            cout << "\nYou ordered: " << pack << " 6-Pack Cookies\n";

            break;
        case 3:
            cout << "How many packs do you want?\n";
            cin >> pack;
            order += pack * 34.08;
            cout << "\nYou ordered: " << pack << " Party Pack Cookies\n";

            break;
        default:
            cout << "Invalid input.";
            break;
        }
        cout << "Do you want to add anything else?Y/y N/n\n";
        cin >> askAgain;
    }
    cout << "Total of your order is $" << order << endl;
    return 0;
}
