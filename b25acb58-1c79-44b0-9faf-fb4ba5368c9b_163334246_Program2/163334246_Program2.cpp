#include <iostream>
#include <vector>
#include <string>

using namespace std;

void shuffle(vector<int>& cards) {
    unsigned int i;
    int temp, random_index;
    srand(time(0));

    for (i = 0; i < cards.size(); i++) {
        random_index = rand() % 16;
        temp = cards.at(i);
        cards.at(i) = cards.at(random_index);
        cards.at(random_index) = temp;
    }
}


int max_card(vector<int> cards) {
    unsigned int i;

    if (cards.size() > 0) {
        int max = cards.at(0);

        for (i = 0; i < cards.size(); i++) {
            if (cards.at(i) > max) {
                max = cards.at(i);
            }
        }
        return max;
    }
    else {
        return -1;
    }
}

bool contains(int card, vector<int> cards) {
    unsigned int i;
    for (i = 0; i < cards.size(); i++) {
        if (cards.at(i) == card) {
            return true;
        }
    }
    return false;
}

void sort(vector<int>& cards) {
    unsigned int i, j;
    int temp;
    for (i = 0; i < cards.size(); i++) {
        for (j = 0; j < cards.size() - i - 1; j++) {
            if (cards.at(j) > cards.at(j + 1)) {
                temp = cards.at(j);
                cards.at(j) = cards.at(j + 1);
                cards.at(j + 1) = temp;

            }
        }
    }
}
int main()
{
    int current_score = 0, next_card = 0;
    vector<int> live_cards{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    vector<int> dead_cards;
    vector<int> taken_cards;

    char choice, continue_choice = 'y';
    unsigned int i;

    string input;
    string output;

    do {
        shuffle(live_cards);
        current_score = 0;
        next_card = 0;
        dead_cards.clear();
        taken_cards.clear();

        while (dead_cards.size() != 16) {
            choice = 'l';

            sort(dead_cards);

            cout << "Current Score: " << current_score << endl;

            cout << "Dead Cards: ";
            for (i = 0; i < dead_cards.size(); i++) {
                cout << dead_cards.at(i) << " ";
            }
            cout << endl;

            cout << "Live Cards: ";
            for (i = 1; i <= live_cards.size(); i++) {
                if (!contains(i, dead_cards))
                    cout << i << " ";
            }
            cout << endl;

            cout << "Next Card: ";
            if (live_cards.at(next_card) < max_card(taken_cards)) {
                cout << live_cards.at(next_card) << " Dead" << endl;
            }
            else {
                cout << live_cards.at(next_card) << endl;
                cout << "Take it [T] or Leave it [L]? ";
                cin >> choice;
            }

            if (choice == 't' || choice == 'T') {
                taken_cards.push_back(live_cards.at(next_card));
                current_score = current_score + live_cards.at(next_card);
            }

            dead_cards.push_back(live_cards.at(next_card));

            next_card++;

            cout << endl;
        }

        cout << "Final Score: " << current_score << endl;

        cout << "Do you like to continue? (y/n) ";
        cin >> continue_choice;

        cout << endl;
    } while (continue_choice == 'y' || continue_choice == 'Y');
}